/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <init.h>
#include <irq.h>
#include <soc.h>
#include <device.h>
#include <hal/pulp.h>

#define HAL_FLL_STATUS_OFFSET        0
#define HAL_FLL_CONF1_OFFSET         4
#define HAL_FLL_CONF2_OFFSET         8
#define HAL_FLL_INTEGRATOR_OFFSET    0xC

#define HAL_FLL_STATUS_FACTOR_BIT    0
#define HAL_FLL_STATUS_FACTOR_WIDTH  16

#define HAL_FLL_CONF1_MODE_BIT       31
#define HAL_FLL_CONF1_MODE_WIDTH     1
#define HAL_FLL_CONF1_LOCK_BIT       30
#define HAL_FLL_CONF1_LOCK_WIDTH     1
#define HAL_FLL_CONF1_DIV_BIT        26
#define HAL_FLL_CONF1_DIV_WIDTH      4
#define HAL_FLL_CONF1_DCO_BIT        16
#define HAL_FLL_CONF1_DCO_WIDTH      10
#define HAL_FLL_CONF1_FACTOR_BIT     0
#define HAL_FLL_CONF1_FACTOR_WIDTH   16


#define HAL_FLL_CONF2_DITH_BIT           31
#define HAL_FLL_CONF2_DITH_WIDTH         1

#define HAL_FLL_CONF2_OPEN_BIT           30
#define HAL_FLL_CONF2_OPEN_WIDTH         1

#define HAL_FLL_CONF2_CLKSEL_BIT         29
#define HAL_FLL_CONF2_CLKSEL_WIDTH       1

#define HAL_FLL_CONF2_LOCK_TOL_BIT       16
#define HAL_FLL_CONF2_LOCK_TOL_WIDTH     12

#define HAL_FLL_CONF2_NB_STABLE_BIT      10
#define HAL_FLL_CONF2_NB_STABLE_WIDTH    6

#define HAL_FLL_CONF2_NB_UNSTABLE_BIT    4
#define HAL_FLL_CONF2_NB_UNSTABLE_WIDTH  6 

#define HAL_FLL_CONF2_GAIN_BIT           0
#define HAL_FLL_CONF2_GAIN_WIDTH         4



#define HAL_FLL_INT_STATE_INT_BIT         16
#define HAL_FLL_INT_STATE_INT_WIDTH       10  

#define HAL_FLL_INT_STATE_FRACT_BIT       6  
#define HAL_FLL_INT_STATE_FRACT_WIDTH     10  


/* Fll ressources */
#define FLL_SOC_OFFSET                    0
#define FLL_CLUSTER_OFFSET                0x10
#define FLL_OFFSET_SOC_CLUSTER            (FLL_CLUSTER_OFFSET - FLL_SOC_OFFSET)
#define FLL_CONF_OFFSET_REG2REG           0x4

#define FLL_STATUS_REG_OFFSET             0
#define FLL_CONF_REG1_OFFSET              0x4
#define FLL_CONF_REG2_OFFSET              0x8
#define FLL_INTEGRATOR_REG_OFFSET         0xC

#define N_FLL     2

#define FLL_REF_CLOCK  32768


typedef struct {
        unsigned int MultFactor:16;     /* Fll current multiplication factor */
        unsigned int Pad:16;
} FllStatusT;

typedef struct {
        unsigned int MultFactor:16;     /* Fll requested multiplication factor, reset: 0x5f5.
                                           If RefClk=32768 and Div=2 Freq= 24.98 MHz */
        unsigned int DCOInput:10;       /* DCO input code for stand alone mode, reset: 0x121 */
        unsigned int ClockOutDivider:4; /* Fll clock output divider, reset: 0x1 e.g div 2 */
        unsigned int OutputLockEnable:1;/* Fll output gated by lock signal (active high), reset 1 */
        unsigned int Mode:1;            /* Fll mode. 0: stand alone (unlocked), 1: normal, reset 0 */
} FllConfiguration1T;

typedef struct {
        unsigned int LoopGain:4;        /* Fll loop gain, reset: 0x9 */
        unsigned int DeAssertCycles:6;  /* Normal mode: number of refclock unstable cycles till lock de-assert
                                           Standalone mode: lower 6 bits of lock assert counter. Reset: 0x10 */
        unsigned int AssertCycles:6;    /* Normal mode: number of refclock stable cycles till lock assert
                                           Standalone mode: upper 6 bits of lock assert counter. Reset: 0x10 */
        unsigned int LockTolerance:12;  /* Lock tolerance: margin arounf the target mult factor where clock is
                                           considered as stable. Reset: 0x200
                                           With Fmax=250Mhw (Div=2^4), Fmin=32K (Div=2^15)
                                           Tolerance: 32K*(512/16)=1.048MHz .. 512 Hz */
        unsigned int Pad:1;
        unsigned int ConfigClockSel:1;  /* Select ref clock when mode = standalone, 0:RefClock, 1: DcoOut. Reset:1 */
        unsigned int OpenLoop:1;        /* When 1 clock operates in open loop when locked */
        unsigned int Dithering:1;       /* When 1 Dithering is enabled */
} FllConfiguration2T;

typedef struct {
        unsigned int Pad1:6;
        unsigned int StateFractPart:10; /* Integrator state: fractional part (dithering input unit) */
        unsigned int StateIntPart:10;   /* Integratot state: integer part (DCO input bits) */
        unsigned int Pad2:6;
} FllIntegratorT;

typedef union {
        FllConfiguration1T      ConfigReg1;
        FllConfiguration2T      ConfigReg2;
        FllIntegratorT          Integrator;
        unsigned int            Raw;
} FllConfigT;


#define SET_CLUSTER_STATE(State, Value)    ((PMU_SystemStateT) (__builtin_bitinsert((State), (Value), CLUSTER_STATE_SIZE, CLUSTER_STATE_OFFSET)))

#define MAX_LV_FREQUENCY 150000000
#define MAX_NV_FREQUENCY 250000000

#define SOC_MIN_FREQ       150000000
#define SOC_MAX_FREQ       250000000

#define CLUSTER_MIN_FREQ   87000000
#define CLUSTER_MAX_FREQ   175000000

#define SOC_FV_SLOPE       ((SOC_MAX_FREQ-SOC_MIN_FREQ)/(DCDC_DEFAULT_NV-DCDC_DEFAULT_LV))
#define CLUSTER_FV_SLOPE   ((CLUSTER_MAX_FREQ-CLUSTER_MIN_FREQ)/(DCDC_DEFAULT_NV-DCDC_DEFAULT_LV))


#define FLL_CONVERGE_OFFSET                     (0x20)

/* Fll control */

/* FreqOut = Fref * Mult/2^(Div-1)      With Mult on 16 bits and Div on 4 bits */

/* Maximum Log2(DCO Frequency) */
#define LOG2_MAXDCO     29
/* Maximum Log2(Clok Divider) */
#define LOG2_MAXDIV     15
/* Log2(RefClk=32768) */
#define LOG2_REFCLK     15
/* Maximum Log2(Multiplier) */
#define LOG2_MAXM       (LOG2_MAXDCO - LOG2_REFCLK)

#define VDD_POINTS 5
#define DCDC_1000mV 9
#define ALPHA_PREC 16
#define BETA_PREC 5

/* Maestro internal events */
#define MAESTRO_EVENT_ICU_OK            (1<<0)
#define MAESTRO_EVENT_ICU_DELAYED       (1<<1)
#define MAESTRO_EVENT_MODE_CHANGED      (1<<2)
#define MAESTRO_EVENT_PICL_OK           (1<<3)
#define MAESTRO_EVENT_SCU_OK            (1<<4)

typedef struct {
  unsigned char State;
  unsigned char FllClusterDown;
  unsigned char DCDC_Settings[4];
        unsigned int  Frequency[N_FLL];
} PMU_StateT;

PMU_StateT PMUState = {0, 0, {0, 0, 0, 0}, {0, 0}};
PMU_RetentionStateT PMURetentionState;
unsigned int FllsFrequency[N_FLL];
uint32_t __pmu_soc_events = 0;


static inline int      PMU_ClusterIsRunning() { return (CLUSTER_STATE(PMUState.State)==CLUSTER_ON);}


static void InitOneFll(hal_fll_e WhichFll, unsigned int UseRetentiveState);


static void wait_pmu_event(int event)
{
  int irq = hal_irq_disable();

  event = event - ARCHI_SOC_EVENT_PMU_FIRST_EVENT;

  while(!((__pmu_soc_events >> event) & 1))
  {
    eu_evt_wait();
    hal_irq_enable();
    hal_irq_disable();
  }

  __pmu_soc_events &= ~(1<<event);

  hal_irq_restore(irq);
}

int cluster_power_up() // unsigned int ClusterFreq)
{
  if (CLUSTER_STATE(PMUState.State) == CLUSTER_OFF)
  {
    if (0) //rt_platform() == ARCHI_PLATFORM_FPGA)
    {
      // On the FPGA the only thing to manage is the cluster isolation
      PMU_IsolateCluster(0);
    }
    else
    {
      PMU_BypassT Bypass;
      Bypass.Raw = GetPMUBypass();

      if (Bypass.Fields.ClusterClockGate == 0)
      {
        /* Clock gate FLL cluster */
        Bypass.Fields.ClusterClockGate = 1; SetPMUBypass(Bypass.Raw);

        /* Wait for clock gate done event */
        wait_pmu_event(PMU_EVENT_CLUSTER_CLOCK_GATE);
      }

      /* Turn on power */
      Bypass.Fields.ClusterState = 1; SetPMUBypass(Bypass.Raw);

      /* Wait for TRC OK event */
      wait_pmu_event(PMU_EVENT_CLUSTER_ON_OFF);

      /* De assert Isolate on cluster */
      PMU_IsolateCluster(0);

      /* De Assert Reset cluster */
      Bypass.Fields.ClusterReset = 0; SetPMUBypass(Bypass.Raw);

      /* Clock ungate FLL cluster */
      Bypass.Fields.ClusterClockGate = 0; SetPMUBypass(Bypass.Raw);

      /* Wait for clock gate done event */
      wait_pmu_event(PMU_EVENT_CLUSTER_CLOCK_GATE);

      /* Do we want to set the cluster fll ? */
      /* In case the fll is not in retentive mode we need to configure it */
      if (PMURetentionState.Fields.FllClusterRetention == 0) InitOneFll(FLL_CLUSTER, 0);

      /* Wait for cluster fll to lock */
      // while (ClusterFllConverged() == 0) {};

      /* Tell external loader (such as gdb) that the cluster is on so that it can take it into account */
      Bypass.Raw |= 1 << APB_SOC_BYPASS_USER0_BIT; SetPMUBypass(Bypass.Raw);
    }

    PMUState.State = SET_CLUSTER_STATE(PMUState.State, CLUSTER_ON);

    return 1;
  }

  return 0;
}



int cluster_power_down()
{
  //if (rt_platform() == ARCHI_PLATFORM_FPGA) return;

  PMU_BypassT Bypass;
  Bypass.Raw = GetPMUBypass();

  int bypass_cluster_off = 0;

  bypass_cluster_off = (Bypass.Raw >> APB_SOC_BYPASS_USER1_BIT) & 1;

  if ((CLUSTER_STATE(PMUState.State) == CLUSTER_ON) && !bypass_cluster_off) {
    PMUState.State = SET_CLUSTER_STATE(PMUState.State, CLUSTER_OFF);

                /* Clock gate FLL cluster */
    Bypass.Fields.ClusterClockGate = 1; SetPMUBypass(Bypass.Raw);
                /* Wait for FLL lock */
    //__rt_periph_wait_event(PMU_EVENT_CLUSTER_CLOCK_GATE, 1);

                /* Isolate Cluster */
    PMU_IsolateCluster(1);
                /* Turn off power */
    Bypass.Fields.ClusterState = 0; SetPMUBypass(Bypass.Raw);

                /* Assert Reset Cluster, this is needed for proper behaviour of fll cluster when waking up */
    Bypass.Fields.ClusterReset = 1; SetPMUBypass(Bypass.Raw);

                /* Wait for TRC OK event */
    //__rt_periph_wait_event(PMU_EVENT_CLUSTER_ON_OFF, 1);
  }
  return 0;
}

static unsigned int SetFllMultDivFactors(unsigned int Freq, unsigned int *Mult, unsigned int *Div)

{
  static int Dynamic = 0;
  //static int Div0 = 0;
  if (Dynamic) {
    unsigned int Fref = 1<<LOG2_REFCLK;
    unsigned int Log2M = __builtin_fl1(Freq) - __builtin_fl1(Fref);
    unsigned int D = __MAX(1, (LOG2_MAXM - Log2M)>>1);
    unsigned int M = (Freq<<D)/Fref;
unsigned int Fres = (Fref*M + (1<<(D-1)))>>D;   /* Rounding */
    *Mult = M; *Div = D+1;
    return Fres;
  } else {
    unsigned int D, M;
    D = __builtin_pulp_minsi(8, __MAX(1, (8 - (__builtin_fl1(Freq) - 3 - LOG2_REFCLK))));
    M = (Freq>>LOG2_REFCLK)*(1<<(D-1));
    *Mult = M; *Div = D;
    return (((1<<LOG2_REFCLK)*M)/(1<<(D-1)));
  }

  return 0;
}

static unsigned int GetFllFreqFromMultDivFactors(unsigned int Mult, unsigned int Div)

{
  unsigned int Fref = 1<<LOG2_REFCLK;
  unsigned int Fres = (Div==0)?(Fref*Mult):(Fref*Mult)>>(Div-1);

  return Fres;
}


#define FLL_CONFIG1_VAL(Mult, DCOIn, Div, OutLockE, Mode) ((Mult)|((DCOIn)<<(16))|((Div)<<(16+10))|((OutLockE)<<(16+10+4))|((Mode)<<(16+10+4+1)))
static unsigned int FLL_CONFIG1_DEF_NOLOCK       = FLL_CONFIG1_VAL(0, 0, 0, 0, 1);
#if PULP_CHIP != CHIP_GAP
static unsigned int FLL_CONFIG1_DEF_LOCK         = FLL_CONFIG1_VAL(0, 0, 0, 1, 1);
#endif
#ifdef PRIME_FLL
static unsigned int FLL_CONFIG1_DEF_OPEN_LOOP_LOCK   = FLL_CONFIG1_VAL(0, 0, 0, 1, 0);
#endif
#define FLL_CONFIG2_VAL(Gain, Deassert, Assert, LockTol, ClkSel, OpenLoop, Dither) ((Gain)|((Deassert)<<4)|((Assert)<<(4+6))|((LockTol)<<(4+6+6))|((ClkSel)<<(4+6+6+12))|((OpenLoop)<<(4+6+6+12+1+1))|((Dither)<<(4+6+6+12+1+1+1)))
// static unsigned int FLL_CONFIG2_GAIN                 = FLL_CONFIG2_VAL(0x7, 0x10, 0x2, 0x100, 0x0, 0x0, 0x1);
// static unsigned int FLL_CONFIG2_NOGAIN               = FLL_CONFIG2_VAL(0xF, 0x10, 0x2, 0x100, 0x0, 0x0, 0x1);
#if 1
static unsigned int FLL_CONFIG2_GAIN                 = FLL_CONFIG2_VAL(0x7, 0x10, 0x10, 0x100, 0x0, 0x0, 0x1);
static unsigned int FLL_CONFIG2_NOGAIN               = FLL_CONFIG2_VAL(0xB, 0x10, 0x10, 0x100, 0x0, 0x0, 0x1);
#else
#if 0
static unsigned int FLL_CONFIG2_GAIN                 = FLL_CONFIG2_VAL(0xB, 0x10, 0x10, 0x100, 0x0, 0x0, 0x1);
static unsigned int FLL_CONFIG2_NOGAIN               = FLL_CONFIG2_VAL(0xB, 0x10, 0x10, 0x100, 0x0, 0x0, 0x1);
#else
static unsigned int FLL_CONFIG2_GAIN                 = FLL_CONFIG2_VAL(0xA, 0x10, 0x2, 0x100, 0x0, 0x0, 0x0);
static unsigned int FLL_CONFIG2_NOGAIN               = FLL_CONFIG2_VAL(0xB, 0x10, 0x2, 0x100, 0x0, 0x0, 0x1); 
#endif
#endif

unsigned int SetFllFrequency(hal_fll_e Fll, unsigned int Frequency, int Check)

{
  if (Fll == FLL_CLUSTER && !PMU_ClusterIsRunning()) return 0;
  FllConfigT Config;
  unsigned int SetFrequency, Mult, Div;
#ifdef PRIME_FLL
  unsigned int DCOIn;
#endif

  SetFrequency = SetFllMultDivFactors(Frequency, &Mult, &Div);

#ifdef PRIME_FLL
/* Force convergence in Open Loop with estimated DCO input */
  DCOIn = EstimateDCOInputCode(Fll, Mult);
  Config.Raw = FLL_CONFIG1_DEF_OPEN_LOOP_LOCK;
  Config.ConfigReg1.DCOInput = DCOIn;
  Config.ConfigReg1.ClockOutDivider = 0;
  SetFllConfiguration(Fll, FLL_CONFIG1, (unsigned int) Config.Raw);
#endif

#if PULP_CHIP == CHIP_GAP

/* Return to close loop mode and give gain to feedback loop */
  SetFllConfiguration(Fll, FLL_CONFIG2, FLL_CONFIG2_GAIN);

  Config.Raw = FLL_CONFIG1_DEF_NOLOCK; // CHANGE WITHOUT BLOCKING THE FLL OUT
  Config.ConfigReg1.MultFactor = Mult;
  Config.ConfigReg1.ClockOutDivider = Div;
  SetFllConfiguration(Fll, FLL_CONFIG1, (unsigned int) Config.Raw);

#if 1
      /* Check FLL converge by compare status register with multiply factor */

  // We set tolerance to Mult/20 to get a precision of 5% against specified freq
  int tolerance = Mult / 20;

  do {
    int mult_factor_diff = hal_fll_status_reg_get(Fll) - Mult;
    if (mult_factor_diff < 0)
      mult_factor_diff = -mult_factor_diff;

    if ( mult_factor_diff <= tolerance)
      break;

  } while (1);

#else
/* Wait for convergence, since we will disable lock enable after this step is mandatory */
  if (Config.ConfigReg1.OutputLockEnable) {
    if (Fll == FLL_CLUSTER && hal_is_fc()) {
     while (ClusterFllConverged() == 0) {};
    } else if (Fll == FLL_SOC && !hal_is_fc()) {
     while (SoCFllConverged() == 0) {};
    }
  }
#endif

  FllsFrequency[Fll] = SetFrequency;
  PMUState.Frequency[Fll] = SetFrequency;

  /* Disable lock enable since we are stable now and removed gain from feed back loop */
  if (Config.ConfigReg1.OutputLockEnable) {
      Config.ConfigReg1.OutputLockEnable = 0;
          SetFllConfiguration(Fll, FLL_CONFIG1, (unsigned int) Config.Raw);
          } 
  SetFllConfiguration(Fll, FLL_CONFIG2, FLL_CONFIG2_NOGAIN);

#else

  Config.Raw = FLL_CONFIG1_DEF_NOLOCK; // CHANGE WITHOUT BLOCKING THE FLL OUT
  Config.ConfigReg1.MultFactor = Mult;
  Config.ConfigReg1.ClockOutDivider = Div;
  SetFllConfiguration(Fll, FLL_CONFIG1, (unsigned int) Config.Raw);

  FllsFrequency[Fll] = SetFrequency;
  PMUState.Frequency[Fll] = SetFrequency;

#endif

#ifdef __RT_USE_BRIDGE
  if (Fll == FLL_SOC)
    __rt_bridge_set_available();
#endif
  
  return SetFrequency;
}

unsigned int SetFllSoCFrequency(unsigned int Frequency)
{
  return SetFllFrequency(FLL_SOC, Frequency, 1);
}

unsigned int SetFllClusterFrequency(unsigned int Frequency)
{
  if (PMU_ClusterIsRunning()) return SetFllFrequency(FLL_CLUSTER, Frequency, 1);
  return 0;
}

void InitOneFll(hal_fll_e WhichFll, unsigned int UseRetentiveState)
{
  FllConfigT Config;

  Config.Raw = GetFllConfiguration(WhichFll, FLL_CONFIG1);
  if (UseRetentiveState)
  {
    FllsFrequency[WhichFll] = GetFllFreqFromMultDivFactors(Config.ConfigReg1.MultFactor, Config.ConfigReg1.ClockOutDivider);
    PMUState.Frequency[WhichFll] = FllsFrequency[WhichFll];
  }
  else
  {
    unsigned int SetFrequency, Mult, Div;

    // Don't set the gain and integrator in case it has already been set by the boot code
    // as it totally blocks the fll on the RTL platform.
    // The boot code is anyway setting the same configuration.
    if (!Config.ConfigReg1.Mode || WhichFll != 0)
    {
      SetFllConfiguration(WhichFll, FLL_CONFIG2, FLL_CONFIG2_GAIN);

      /* We are in open loop, prime the fll forcing dco input, approx 50 MHz */
      Config.Raw = 0; // GetFllConfiguration(WhichFll, FLL_INTEGRATOR);
      Config.Integrator.StateIntPart = 332;
      SetFllConfiguration(WhichFll, FLL_INTEGRATOR, (unsigned int) Config.Raw);
    }

#if PULP_CHIP == CHIP_GAP

    /* Lock Fll */
    // Config.Raw = FLL_CONFIG1_DEF_LOCK;
    Config.Raw = FLL_CONFIG1_DEF_NOLOCK; // CHANGE WITHOUT BLOCKING THE FLL OUT 
    SetFrequency = SetFllMultDivFactors(50000000, &Mult, &Div);
    Config.ConfigReg1.MultFactor = Mult;
    Config.ConfigReg1.ClockOutDivider = Div;
    SetFllConfiguration(WhichFll, FLL_CONFIG1, Config.Raw);

#if 1

  // We set tolerance to Mult/20 to get a precision of 5% against specified freq
  int tolerance = Mult/20;

  do {
    int mult_factor_diff = hal_fll_status_reg_get(WhichFll) - Mult;
    if (mult_factor_diff < 0)
      mult_factor_diff = -mult_factor_diff;

    if ( mult_factor_diff <= tolerance)
      break;

    soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_REF_CLK_RISE);
    //__rt_periph_wait_event(ARCHI_SOC_EVENT_REF_CLK_RISE, 1);
    soc_eu_fcEventMask_clearEvent(ARCHI_SOC_EVENT_REF_CLK_RISE);
    
  } while (1);

#else
    if (Config.ConfigReg1.OutputLockEnable && (WhichFll == FLL_CLUSTER) && hal_is_fc()) {
      while (ClusterFllConverged() == 0) {};
    }
    Config.ConfigReg1.OutputLockEnable = 0;
#endif

    SetFllConfiguration(WhichFll, FLL_CONFIG1, Config.Raw);

    FllsFrequency[WhichFll] = SetFrequency;
    PMUState.Frequency[WhichFll] = SetFrequency;

    SetFllConfiguration(WhichFll, FLL_CONFIG2, FLL_CONFIG2_NOGAIN);

#else

    /* Lock Fll */
    Config.Raw = FLL_CONFIG1_DEF_LOCK;
    SetFrequency = SetFllMultDivFactors(50000000, &Mult, &Div);
    Config.ConfigReg1.MultFactor = Mult;
    Config.ConfigReg1.ClockOutDivider = Div;
    SetFllConfiguration(WhichFll, FLL_CONFIG1, Config.Raw);

    FllsFrequency[WhichFll] = SetFrequency;
    PMUState.Frequency[WhichFll] = SetFrequency;

#endif

  }
}

void  __attribute__ ((noinline)) InitFlls()
{
  InitOneFll(FLL_SOC, PMURetentionState.Fields.FllSoCRetention);
  //if (PMU_ClusterIsRunning()) InitOneFll(FLL_CLUSTER, PMURetentionState.Fields.FllClusterRetention);
}


static int pulp_pmu_init(struct device *device)
{
  ARG_UNUSED(device);

#if 0
  unsigned int DCDCValue = GetDCDCSetting();

  /* Build actual power state from register settings */
  PMURetentionState.Raw = GetRetentiveState();
  PMUState.State = RetPMUStateToPMUState[PMURetentionState.Fields.WakeupState];

  PMUState.DCDC_Settings[REGU_NV]  = __builtin_bitextractu(DCDCValue, DCDC_RANGE, DCDC_Nominal*8);
  PMUState.DCDC_Settings[REGU_LV]  = __builtin_bitextractu(DCDCValue, DCDC_RANGE, DCDC_Low*8);
  PMUState.DCDC_Settings[REGU_RET] = __builtin_bitextractu(DCDCValue, DCDC_RANGE, DCDC_Retentive*8);
  PMUState.DCDC_Settings[REGU_OFF] = 0;

#endif

  PMU_BypassT Bypass;
  Bypass.Raw = GetPMUBypass();
  Bypass.Fields.Bypass = 1;
  Bypass.Fields.BypassClock = 1;
  SetPMUBypass(Bypass.Raw);

  InitFlls();

  /* Setup interrupt sensibility list, we could remove icu_ok, icu_delayed and icu_mode_changed */
  /* picl_ok and scu_ok are visible icu_ok, icu_delayed, icu_mode_changed and picl_ok are masked */
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_CLUSTER_ON_OFF);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_MSP);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_ICU_MODE_CHANGED);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_ICU_OK);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_ICU_DELAYED);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_PICL_OK);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_SCU_OK);

  /* Disable all Maestro interrupts but PICL_OK and SCU_OK */
  PMU_Write(DLC_IMR, 0x7);

  /* Clear PICL_OK and SCU_OK interrupts in case they are sat */
  PMU_Write(DLC_IFR, (MAESTRO_EVENT_PICL_OK|MAESTRO_EVENT_SCU_OK));

  return 0;
}

SYS_DEVICE_DEFINE("pmu", pulp_pmu_init, NULL,
                PRE_KERNEL_1, 0);


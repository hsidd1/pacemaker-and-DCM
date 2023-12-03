/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V6.h
 *
 * Code generated for Simulink model 'Assignment1_V6'.
 *
 * Model version                  : 1.200
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Dec  1 05:47:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_V6_h_
#define RTW_HEADER_Assignment1_V6_h_
#ifndef Assignment1_V6_COMMON_INCLUDES_
#define Assignment1_V6_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Assignment1_V6_COMMON_INCLUDES_ */

#include "Assignment1_V6_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals for system '<Root>/HARDWARE_TX_INTERFACE' */
typedef struct {
  uint8_T BytePack[2];                 /* '<S6>/Byte Pack' */
  uint8_T BytePack1[2];                /* '<S6>/Byte Pack1' */
} B_HARDWARE_TX_INTERFACE_Assig_T;

/* Block states (default storage) for system '<Root>/HARDWARE_TX_INTERFACE' */
typedef struct {
  freedomk64f_SCIWrite_Assignme_T obj; /* '<S6>/Serial Transmit' */
} DW_HARDWARE_TX_INTERFACE_Assi_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay[50];              /* '<S3>/Tapped Delay' */
  real_T VectorConcatenate1_m[15];     /* '<S2>/Vector Concatenate1' */
  uint8_T RxData[16];
  uint8_T RxDataLocChar[16];
  real_T dv[2];
  uint64_T Gain5;                      /* '<S12>/Gain5' */
  real_T CastToDouble2[6];             /* '<S15>/Cast To Double2' */
  real_T SquareRoot;                   /* '<S11>/Square Root' */
  uint32_T Gain4;                      /* '<S12>/Gain4' */
  real32_T Switch2;                    /* '<S22>/Switch2' */
  real32_T Gain2[2];                   /* '<S12>/Gain2' */
  real32_T VectorConcatenate1[2];      /* '<S12>/Vector Concatenate1' */
  real32_T PACING_REF_PWM;             /* '<S9>/PACE_SYSTEM' */
  real32_T sense_timeout_threshold;    /* '<S8>/RATE_CTRL_SYSTEM' */
  Pace_Sense_Response Cast9;           /* '<S12>/Cast9' */
  Pace_Sense_Chamber Cast8;            /* '<S12>/Cast8' */
  Pace_Chamber Cast7;                  /* '<S12>/Cast7' */
  uint16_T Cast11[2];                  /* '<S12>/Cast11' */
  int16_T DataTypeConversion;          /* '<S5>/Data Type Conversion' */
  int16_T DataTypeConversion1;         /* '<S5>/Data Type Conversion1' */
  uint8_T Params_Raw[4];               /* '<Root>/Chart' */
  uint8_T Params_Arr[15];              /* '<Root>/Chart' */
  uint8_T TX_ctrlmode;                 /* '<Root>/Chart' */
  boolean_T VectorConcatenate[2];      /* '<Root>/Vector Concatenate' */
  boolean_T ATR_PACE_CTRL;             /* '<S9>/PACE_SYSTEM' */
  boolean_T VENT_PACE_CTRL;            /* '<S9>/PACE_SYSTEM' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S9>/PACE_SYSTEM' */
  boolean_T PACE_GND_CTRL;             /* '<S9>/PACE_SYSTEM' */
  boolean_T ATR_GND_CTRL;              /* '<S9>/PACE_SYSTEM' */
  boolean_T VENT_GND_CTRL;             /* '<S9>/PACE_SYSTEM' */
  B_HARDWARE_TX_INTERFACE_Assig_T HARDWARE_TX_INTERFACE;/* '<Root>/HARDWARE_TX_INTERFACE' */
} B_Assignment1_V6_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_Assignme_T obj; /* '<S3>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_Assig_T obj_n;/* '<S5>/Analog Input1' */
  freedomk64f_AnalogInput_Assig_T obj_h;/* '<S5>/Analog Input' */
  freedomk64f_DigitalRead_Assig_T obj_d;/* '<S5>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_a;/* '<S5>/Digital Read' */
  freedomk64f_SCIRead_Assignmen_T obj_e;/* '<Root>/Serial Receive' */
  freedomk64f_DigitalWrite_Assi_T obj_f;/* '<S5>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_ni;/* '<S5>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_g;/* '<S5>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_ev;/* '<S4>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<S4>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_b;/* '<S4>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_h5;/* '<S4>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<S4>/Digital Write' */
  freedomk64f_PWMOutput_Assignm_T obj_ng;/* '<S5>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_l;/* '<S5>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_dw;/* '<S4>/PWM Output' */
  real_T TappedDelay_X[49];            /* '<S3>/Tapped Delay' */
  real_T dif;                          /* '<S8>/RATE_CTRL_SYSTEM' */
  real_T rolling_avg;                  /* '<S16>/MATLAB Function2' */
  real_T init_counter;                 /* '<S16>/MATLAB Function2' */
  real32_T tgt;                        /* '<S8>/RATE_CTRL_SYSTEM' */
  int32_T sfEvent;                     /* '<S9>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<S9>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1_e;       /* '<Root>/Chart' */
  uint8_T is_c3_Assignment1_V6;        /* '<S9>/PACE_SYSTEM' */
  uint8_T is_PACE;                     /* '<S9>/PACE_SYSTEM' */
  uint8_T is_SENSE;                    /* '<S9>/PACE_SYSTEM' */
  uint8_T is_active_c3_Assignment1_V6; /* '<S9>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<S9>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<S9>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<S9>/PACE_SYSTEM' */
  uint8_T is_c9_Assignment1_V6;        /* '<S8>/RATE_CTRL_SYSTEM' */
  uint8_T is_Pace_Rate_Unfixed;        /* '<S8>/RATE_CTRL_SYSTEM' */
  uint8_T iter;                        /* '<S8>/RATE_CTRL_SYSTEM' */
  uint8_T is_active_c9_Assignment1_V6; /* '<S8>/RATE_CTRL_SYSTEM' */
  uint8_T temporalCounter_i1_a;        /* '<S8>/RATE_CTRL_SYSTEM' */
  uint8_T is_c7_Assignment1_V6;        /* '<Root>/Chart' */
  uint8_T Output_Candidate[15];        /* '<Root>/Chart' */
  uint8_T Op_Mode;                     /* '<Root>/Chart' */
  uint8_T iter_o;                      /* '<Root>/Chart' */
  uint8_T Rxint_buf[16];               /* '<Root>/Chart' */
  uint8_T Rx_buf[16];                  /* '<Root>/Chart' */
  uint8_T is_active_c7_Assignment1_V6; /* '<Root>/Chart' */
  DW_HARDWARE_TX_INTERFACE_Assi_T HARDWARE_TX_INTERFACE;/* '<Root>/HARDWARE_TX_INTERFACE' */
} DW_Assignment1_V6_T;

/* Parameters for system: '<Root>/HARDWARE_TX_INTERFACE' */
struct P_HARDWARE_TX_INTERFACE_Assig_T_ {
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S6>/Switch'
                                        */
};

/* Parameters (default storage) */
struct P_Assignment1_V6_T_ {
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S3>/Tapped Delay'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S3>/FXOS8700 6-Axes Sensor'
                                         */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S5>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Analog Input1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read1'
                                        */
  real_T rate_response_fac_Y0;       /* Computed Parameter: rate_response_fac_Y0
                                      * Referenced by: '<S15>/rate_response_fac'
                                      */
  real_T Constant_Value[3];            /* Expression: [0.01,0.05,0.2]
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -300
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -300
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T Multiply1_Gain;               /* Expression: 60000
                                        * Referenced by: '<S12>/Multiply1'
                                        */
  real_T Constant10_Value;             /* Expression: 85
                                        * Referenced by: '<S10>/Constant10'
                                        */
  real_T Constant_Value_b;             /* Expression: 60
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 140
                                        * Referenced by: '<S10>/Constant9'
                                        */
  real_T Constant1_Value_j;            /* Expression: 40
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 35
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 150
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 10
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S10>/Constant8'
                                        */
  real_T Constant2_Value_c;            /* Expression: 500
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0.5
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 100
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 100
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Multiply_Gain;                /* Expression: 60000
                                        * Referenced by: '<S12>/Multiply'
                                        */
  real_T Constant1_Value_jw;           /* Expression: 150
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant2_Value_o[2];         /* Expression: [1.25,2]
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 30
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Multiply2_Gain;               /* Expression: 60000
                                        * Referenced by: '<S12>/Multiply2'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real32_T Gain16_Gain;                /* Computed Parameter: Gain16_Gain
                                        * Referenced by: '<S12>/Gain16'
                                        */
  real32_T Gain15_Gain;                /* Computed Parameter: Gain15_Gain
                                        * Referenced by: '<S12>/Gain15'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real32_T Gain7_Gain;                 /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S12>/Gain7'
                                        */
  real32_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S12>/Gain8'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S12>/Gain6'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real32_T Gain3_Gain_o;               /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S12>/Gain'
                                        */
  uint32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S12>/Gain4'
                                        */
  uint32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S12>/Gain5'
                                        */
  P_HARDWARE_TX_INTERFACE_Assig_T HARDWARE_TX_INTERFACE;/* '<Root>/HARDWARE_TX_INTERFACE' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_V6_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Assignment1_V6_T Assignment1_V6_P;

/* Block signals (default storage) */
extern B_Assignment1_V6_T Assignment1_V6_B;

/* Block states (default storage) */
extern DW_Assignment1_V6_T Assignment1_V6_DW;

/* External function called from main */
extern void Assignment1_V6_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Assignment1_V6_initialize(void);
extern void Assignment1_V6_step0(void);
extern void Assignment1_V6_step1(void);
extern void Assignment1_V6_step(int_T tid);
extern void Assignment1_V6_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_V6_T *const Assignment1_V6_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Cast To Boolean2' : Unused code path elimination
 * Block '<S5>/Cast To Double' : Unused code path elimination
 * Block '<S12>/Cast6' : Unused code path elimination
 * Block '<S12>/Gain11' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Rate Transition' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Assignment1_V6'
 * '<S1>'   : 'Assignment1_V6/Chart'
 * '<S2>'   : 'Assignment1_V6/DEFAULT_SETTINGS_INTERFACE'
 * '<S3>'   : 'Assignment1_V6/HARDWARE_ACCEL_INTERFACE'
 * '<S4>'   : 'Assignment1_V6/HARDWARE_PULSE_INTERFACE'
 * '<S5>'   : 'Assignment1_V6/HARDWARE_SENSE_INTERFACE'
 * '<S6>'   : 'Assignment1_V6/HARDWARE_TX_INTERFACE'
 * '<S7>'   : 'Assignment1_V6/PARAMS_PREPROCESSOR_WRAPPER'
 * '<S8>'   : 'Assignment1_V6/RATE_SYSTEM'
 * '<S9>'   : 'Assignment1_V6/Subsystem2'
 * '<S10>'  : 'Assignment1_V6/DEFAULT_SETTINGS_INTERFACE/DEFAULT_PARAMS'
 * '<S11>'  : 'Assignment1_V6/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT'
 * '<S12>'  : 'Assignment1_V6/PARAMS_PREPROCESSOR_WRAPPER/PARAMETER_PREPROCESSOR'
 * '<S13>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR'
 * '<S14>'  : 'Assignment1_V6/RATE_SYSTEM/RATE_CTRL_SYSTEM'
 * '<S15>'  : 'Assignment1_V6/RATE_SYSTEM/RESP_EXP_FAC_CALC'
 * '<S16>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER'
 * '<S17>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE'
 * '<S18>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/Subsystem'
 * '<S19>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER/MATLAB Function2'
 * '<S20>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE/MATLAB Function'
 * '<S21>'  : 'Assignment1_V6/Subsystem2/PACE_SYSTEM'
 * '<S22>'  : 'Assignment1_V6/Subsystem2/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_Assignment1_V6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

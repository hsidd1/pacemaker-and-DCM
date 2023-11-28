/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V4.h
 *
 * Code generated for Simulink model 'Assignment1_V4'.
 *
 * Model version                  : 1.62
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Nov 28 04:00:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_V4_h_
#define RTW_HEADER_Assignment1_V4_h_
#ifndef Assignment1_V4_COMMON_INCLUDES_
#define Assignment1_V4_COMMON_INCLUDES_
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Assignment1_V4_COMMON_INCLUDES_ */

#include "Assignment1_V4_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T VectorConcatenate1[15];       /* '<Root>/Vector Concatenate1' */
  real_T Gain2[2];                     /* '<S17>/Gain2' */
  real_T VectorConcatenate2[2];        /* '<S17>/Vector Concatenate2' */
  real_T VectorConcatenate1_a[2];      /* '<S17>/Vector Concatenate1' */
  real_T dv[2];
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Constant[3];                  /* '<S9>/Constant' */
  real_T Gain;                         /* '<S12>/Gain' */
  real_T Multiply2;                    /* '<S17>/Multiply2' */
  real_T Gain4;                        /* '<S17>/Gain4' */
  real_T Gain5;                        /* '<S17>/Gain5' */
  real_T Multiply;                     /* '<S17>/Multiply' */
  real_T Multiply1;                    /* '<S17>/Multiply1' */
  real_T sense_timeout_threshold;      /* '<S9>/RATE_CTRL_SYSTEM' */
  real_T tgt;                          /* '<S9>/RATE_CTRL_SYSTEM' */
  real_T dif;                          /* '<S9>/RATE_CTRL_SYSTEM' */
  real_T PACING_REF_PWM;               /* '<Root>/PACE_SYSTEM' */
  real_T red;                          /* '<Root>/PACE_SYSTEM' */
  real_T blue;                         /* '<Root>/PACE_SYSTEM' */
  real_T green;                        /* '<Root>/PACE_SYSTEM' */
  real_T Params_Arr[15];               /* '<Root>/Chart' */
  real_T Motion_State;                 /* '<S11>/MATLAB Function' */
  real_T smoothed_output;              /* '<S10>/MATLAB Function2' */
  real_T PACE_CHAMBER_tmp;
  real_T PACE_SENSE_CHAMBER_tmp;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  Pace_Sense_Response PACE_SENSE_RESPONSE;/* '<S17>/MATLAB Function' */
  Pace_Sense_Chamber PACE_SENSE_CHAMBER;/* '<S17>/MATLAB Function' */
  Pace_Rate_Mode PACE_RATE_MODE;       /* '<S17>/MATLAB Function' */
  Pace_Chamber PACE_CHAMBER;           /* '<S17>/MATLAB Function' */
  boolean_T VectorConcatenate[2];      /* '<Root>/Vector Concatenate' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
} B_Assignment1_V4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_Assignme_T obj; /* '<S3>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_Assig_T obj_m;/* '<S5>/Analog Input1' */
  freedomk64f_AnalogInput_Assig_T obj_i;/* '<S5>/Analog Input' */
  freedomk64f_DigitalRead_Assig_T obj_ir;/* '<S5>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_m4;/* '<S5>/Digital Read' */
  freedomk64f_DigitalWrite_Assi_T obj_o;/* '<S5>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_b;/* '<S5>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_d;/* '<S5>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_a;/* '<S4>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_o1;/* '<S4>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S4>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<S4>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_f;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_n;/* '<S4>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_fj;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_ia;/* '<Root>/Digital Write3' */
  freedomk64f_PWMOutput_Assignm_T obj_j;/* '<S5>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_dx;/* '<S5>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_lo;/* '<S4>/PWM Output' */
  real_T resp_fac_decay[3];            /* '<S9>/RATE_CTRL_SYSTEM' */
  real_T resp_fac_grow[3];             /* '<S9>/RATE_CTRL_SYSTEM' */
  real_T Output_Candidate[15];         /* '<Root>/Chart' */
  real_T rolling_avg;                  /* '<S10>/MATLAB Function2' */
  real_T init_counter;                 /* '<S10>/MATLAB Function2' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_RATE_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_RAT_c;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_RAT_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Motio;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MATLA;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mot_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_b;   /* synthesized block */

  int32_T sfEvent_a;                   /* '<Root>/PACE_SYSTEM' */
  uint32_T is_c9_Assignment1_V4;       /* '<S9>/RATE_CTRL_SYSTEM' */
  uint32_T is_c3_Assignment1_V4;       /* '<Root>/PACE_SYSTEM' */
  uint32_T is_finally_c3_Assignment1_V4;/* '<Root>/PACE_SYSTEM' */
  uint32_T is_PACE;                    /* '<Root>/PACE_SYSTEM' */
  uint32_T is_finally_PACE;            /* '<Root>/PACE_SYSTEM' */
  uint32_T is_SENSE;                   /* '<Root>/PACE_SYSTEM' */
  uint32_T is_finally_SENSE;           /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint32_T is_c7_Assignment1_V4;       /* '<Root>/Chart' */
  uint32_T is_finally_c7_Assignment1_V4;/* '<Root>/Chart' */
  uint8_T is_active_c9_Assignment1_V4; /* '<S9>/RATE_CTRL_SYSTEM' */
  uint8_T temporalCounter_i1_n;        /* '<S9>/RATE_CTRL_SYSTEM' */
  uint8_T is_active_c3_Assignment1_V4; /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c7_Assignment1_V4; /* '<Root>/Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/PACE_SYSTEM' */
} DW_Assignment1_V4_T;

/* Parameters (default storage) */
struct P_Assignment1_V4_T_ {
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
  real_T Constant10_Value;             /* Expression: 1001
                                        * Referenced by: '<S7>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<S7>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 140
                                        * Referenced by: '<S7>/Constant9'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 3.5
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 150
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 0.1
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S7>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0.1
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Constant2_Value_i;            /* Expression: 500
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_e[3];          /* Expression: [0.01,0.05,0.2]
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_i[2];         /* Expression: [0.75,1.25]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 20
                                        * Referenced by: '<S17>/Gain2'
                                        */
  real_T Constant_Value_n;             /* Expression: 150
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 50
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Multiply2_Gain;               /* Expression: 60000
                                        * Referenced by: '<S17>/Multiply2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S17>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S17>/Gain5'
                                        */
  real_T Multiply_Gain;                /* Expression: 60000
                                        * Referenced by: '<S17>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: 60000
                                        * Referenced by: '<S17>/Multiply1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 20
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 20
                                        * Referenced by: '<S17>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_V4_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Assignment1_V4_T Assignment1_V4_P;

/* Block signals (default storage) */
extern B_Assignment1_V4_T Assignment1_V4_B;

/* Block states (default storage) */
extern DW_Assignment1_V4_T Assignment1_V4_DW;

/* Model entry point functions */
extern void Assignment1_V4_initialize(void);
extern void Assignment1_V4_step(void);
extern void Assignment1_V4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_V4_T *const Assignment1_V4_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion' : Unused code path elimination
 * Block '<S5>/Data Type Conversion1' : Unused code path elimination
 * Block '<S5>/Gain' : Unused code path elimination
 * Block '<S5>/Gain1' : Unused code path elimination
 * Block '<S5>/Gain2' : Unused code path elimination
 * Block '<S5>/Gain3' : Unused code path elimination
 * Block '<S17>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Assignment1_V4'
 * '<S1>'   : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR'
 * '<S2>'   : 'Assignment1_V4/Chart'
 * '<S3>'   : 'Assignment1_V4/HARDWARE_ACCEL_INTERFACE'
 * '<S4>'   : 'Assignment1_V4/HARDWARE_PULSE_INTERFACE'
 * '<S5>'   : 'Assignment1_V4/HARDWARE_SENSE_INTERFACE'
 * '<S6>'   : 'Assignment1_V4/PACE_SYSTEM'
 * '<S7>'   : 'Assignment1_V4/Subsystem'
 * '<S8>'   : 'Assignment1_V4/Subsystem1'
 * '<S9>'   : 'Assignment1_V4/Subsystem2'
 * '<S10>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER'
 * '<S11>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE'
 * '<S12>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/Subsystem'
 * '<S13>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER/MATLAB Function2'
 * '<S14>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE/MATLAB Function'
 * '<S15>'  : 'Assignment1_V4/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT'
 * '<S16>'  : 'Assignment1_V4/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT/MATLAB Function'
 * '<S17>'  : 'Assignment1_V4/Subsystem1/PARAMETER_PREPROCESSOR'
 * '<S18>'  : 'Assignment1_V4/Subsystem1/PARAMETER_PREPROCESSOR/MATLAB Function'
 * '<S19>'  : 'Assignment1_V4/Subsystem2/RATE_CTRL_SYSTEM'
 */
#endif                                 /* RTW_HEADER_Assignment1_V4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

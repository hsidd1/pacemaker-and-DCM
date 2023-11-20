/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V2.h
 *
 * Code generated for Simulink model 'Assignment1_V2'.
 *
 * Model version                  : 2.38
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 20 17:32:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. ROM efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_V2_h_
#define RTW_HEADER_Assignment1_V2_h_
#ifndef Assignment1_V2_COMMON_INCLUDES_
#define Assignment1_V2_COMMON_INCLUDES_
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#endif                                 /* Assignment1_V2_COMMON_INCLUDES_ */

#include "Assignment1_V2_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rtGetInf.h"
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
  real_T Gain2[2];                     /* '<S4>/Gain2' */
  real_T VectorConcatenate2[2];        /* '<S4>/Vector Concatenate2' */
  real_T VectorConcatenate1[2];        /* '<S4>/Vector Concatenate1' */
  real_T Multiply;                     /* '<S4>/Multiply' */
  real_T smoothed_output;              /* '<S7>/MATLAB Function2' */
  real_T Smoothed_Output;              /* '<S12>/MATLAB Function1' */
  real_T Accel_Raw_Magnitude;          /* '<S6>/MATLAB Function' */
  real_T PACING_REF_PWM;               /* '<Root>/PACE_SYSTEM' */
  Rate_Motion_State Motion_State;      /* '<S8>/MATLAB Function' */
  Pace_Sense_Response PACE_SENSE_RESPONSE;/* '<S4>/MATLAB Function' */
  Pace_Sense_Chamber PACE_SENSE_CHAMBER;/* '<S4>/MATLAB Function' */
  Pace_Chamber PACE_CHAMBER;           /* '<S4>/MATLAB Function' */
  boolean_T VectorConcatenate[2];      /* '<Root>/Vector Concatenate' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
} B_Assignment1_V2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_Assignme_T obj; /* '<S6>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_Assig_T obj_m;/* '<S2>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_o;/* '<S2>/Digital Read' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_c;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<S1>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_n;/* '<S1>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_i;/* '<S1>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_mo;/* '<S1>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_j;/* '<S1>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_n2;/* '<S1>/Digital Write' */
  freedomk64f_PWMOutput_Assignm_T obj_b;/* '<S2>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_h;/* '<S2>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_km;/* '<S1>/PWM Output' */
  real_T rolling_avg;                  /* '<S7>/MATLAB Function2' */
  real_T init_counter;                 /* '<S7>/MATLAB Function2' */
  real_T Buffer_Internal[2500];        /* '<S12>/MATLAB Function' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Subsy;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MATLA;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sub_k;   /* synthesized block */

  int32_T sfEvent;                     /* '<Root>/PACE_SYSTEM' */
  uint32_T is_c3_Assignment1_V2;       /* '<Root>/PACE_SYSTEM' */
  uint32_T is_finally_c3_Assignment1_V2;/* '<Root>/PACE_SYSTEM' */
  uint32_T is_PACE;                    /* '<Root>/PACE_SYSTEM' */
  uint32_T is_finally_PACE;            /* '<Root>/PACE_SYSTEM' */
  uint32_T is_SENSE;                   /* '<Root>/PACE_SYSTEM' */
  uint32_T is_finally_SENSE;           /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c3_Assignment1_V2; /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<Root>/PACE_SYSTEM' */
  boolean_T Buffer_Internal_not_empty; /* '<S12>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/PACE_SYSTEM' */
} DW_Assignment1_V2_T;

/* Parameters (default storage) */
struct P_Assignment1_V2_T_ {
  Pace_Mode EnumeratedConstant_Value;/* Mask Parameter: EnumeratedConstant_Value
                                      * Referenced by: '<S10>/Constant'
                                      */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read1'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S6>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Constant_Value;               /* Expression: 150
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1.25
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant1_Value_m;            /* Expression: 4
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 20
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Constant4_Value;              /* Expression: 150
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant_Value_m;             /* Expression: 60
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Multiply_Gain;                /* Expression: 1000/60
                                        * Referenced by: '<S4>/Multiply'
                                        */
  real_T Constant2_Value;              /* Expression: 0.7
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S4>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_V2_T {
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
extern P_Assignment1_V2_T Assignment1_V2_P;

/* Block signals (default storage) */
extern B_Assignment1_V2_T Assignment1_V2_B;

/* Block states (default storage) */
extern DW_Assignment1_V2_T Assignment1_V2_DW;

/* Model entry point functions */
extern void Assignment1_V2_initialize(void);
extern void Assignment1_V2_step(void);
extern void Assignment1_V2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_V2_T *const Assignment1_V2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Cast To Double' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Assignment1_V2'
 * '<S1>'   : 'Assignment1_V2/HARDWARE_PULSE_INTERFACE'
 * '<S2>'   : 'Assignment1_V2/HARDWARE_SENSE_INTERFACE'
 * '<S3>'   : 'Assignment1_V2/PACE_SYSTEM'
 * '<S4>'   : 'Assignment1_V2/PARAMETER_PREPROCESSOR'
 * '<S5>'   : 'Assignment1_V2/Subsystem'
 * '<S6>'   : 'Assignment1_V2/Subsystem1'
 * '<S7>'   : 'Assignment1_V2/Subsystem2'
 * '<S8>'   : 'Assignment1_V2/Subsystem3'
 * '<S9>'   : 'Assignment1_V2/PARAMETER_PREPROCESSOR/MATLAB Function'
 * '<S10>'  : 'Assignment1_V2/Subsystem/Enumerated Constant'
 * '<S11>'  : 'Assignment1_V2/Subsystem1/MATLAB Function'
 * '<S12>'  : 'Assignment1_V2/Subsystem2/Buffer Smooth'
 * '<S13>'  : 'Assignment1_V2/Subsystem2/MATLAB Function2'
 * '<S14>'  : 'Assignment1_V2/Subsystem2/Buffer Smooth/MATLAB Function'
 * '<S15>'  : 'Assignment1_V2/Subsystem2/Buffer Smooth/MATLAB Function1'
 * '<S16>'  : 'Assignment1_V2/Subsystem3/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Assignment1_V2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

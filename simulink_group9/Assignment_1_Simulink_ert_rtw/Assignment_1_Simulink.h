/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_1_Simulink.h
 *
 * Code generated for Simulink model 'Assignment_1_Simulink'.
 *
 * Model version                  : 2.50
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct 20 12:01:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment_1_Simulink_h_
#define RTW_HEADER_Assignment_1_Simulink_h_
#ifndef Assignment_1_Simulink_COMMON_INCLUDES_
#define Assignment_1_Simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                              /* Assignment_1_Simulink_COMMON_INCLUDES_ */

#include "Assignment_1_Simulink_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain2[2];                     /* '<S4>/Gain2' */
  real_T VectorConcatenate2[2];        /* '<S4>/Vector Concatenate2' */
  real_T VectorConcatenate1[2];        /* '<S4>/Vector Concatenate1' */
  real_T Multiply;                     /* '<S4>/Multiply' */
  real_T PACING_REF_PWM;               /* '<Root>/PACE_SYSTEM' */
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
} B_Assignment_1_Simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Assig_T obj; /* '<S2>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_b;/* '<S2>/Digital Read' */
  freedomk64f_DigitalWrite_Assi_T obj_i;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_a;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_n;/* '<S1>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_j;/* '<S1>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_n2;/* '<S1>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_bo;/* '<S1>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_h;/* '<S1>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_g;/* '<S1>/Digital Write' */
  freedomk64f_PWMOutput_Assignm_T obj_mz;/* '<S2>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_iw;/* '<S2>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_bn;/* '<S1>/PWM Output' */
  int32_T sfEvent;                     /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint8_T is_c3_Assignment_1_Simulink; /* '<Root>/PACE_SYSTEM' */
  uint8_T is_PACE;                     /* '<Root>/PACE_SYSTEM' */
  uint8_T is_SENSE;                    /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c3_Assignment_1_Simul;/* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<Root>/PACE_SYSTEM' */
} DW_Assignment_1_Simulink_T;

/* Parameters (default storage) */
struct P_Assignment_1_Simulink_T_ {
  Pace_Mode EnumeratedConstant_Value;/* Mask Parameter: EnumeratedConstant_Value
                                      * Referenced by: '<S7>/Constant'
                                      */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read1'
                                        */
  real_T Constant1_Value;              /* Expression: 4
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
  real_T Constant_Value;               /* Expression: 60
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
struct tag_RTM_Assignment_1_Simulink_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Assignment_1_Simulink_T Assignment_1_Simulink_P;

/* Block signals (default storage) */
extern B_Assignment_1_Simulink_T Assignment_1_Simulink_B;

/* Block states (default storage) */
extern DW_Assignment_1_Simulink_T Assignment_1_Simulink_DW;

/* Model entry point functions */
extern void Assignment_1_Simulink_initialize(void);
extern void Assignment_1_Simulink_step(void);
extern void Assignment_1_Simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment_1_Simulin_T *const Assignment_1_Simulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'Assignment_1_Simulink'
 * '<S1>'   : 'Assignment_1_Simulink/HARDWARE_PULSE_INTERFACE'
 * '<S2>'   : 'Assignment_1_Simulink/HARDWARE_SENSE_INTERFACE'
 * '<S3>'   : 'Assignment_1_Simulink/PACE_SYSTEM'
 * '<S4>'   : 'Assignment_1_Simulink/PARAMETER_PREPROCESSOR'
 * '<S5>'   : 'Assignment_1_Simulink/Subsystem'
 * '<S6>'   : 'Assignment_1_Simulink/PARAMETER_PREPROCESSOR/MATLAB Function'
 * '<S7>'   : 'Assignment_1_Simulink/Subsystem/Enumerated Constant'
 */
#endif                                 /* RTW_HEADER_Assignment_1_Simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

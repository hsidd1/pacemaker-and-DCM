/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V6.h
 *
 * Code generated for Simulink model 'Assignment1_V6'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 29 23:19:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_V6_h_
#define RTW_HEADER_Assignment1_V6_h_
#ifndef Assignment1_V6_COMMON_INCLUDES_
#define Assignment1_V6_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* Assignment1_V6_COMMON_INCLUDES_ */

#include "Assignment1_V6_types.h"
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
  real_T Gain_n[15];                   /* '<Root>/Gain' */
  real_T FXOS87006AxesSensor[3];       /* '<S1>/FXOS8700 6-Axes Sensor' */
  real_T VectorConcatenate[2];         /* '<Root>/Vector Concatenate' */
  real_T dv[2];
  uint8_T Cast[15];                    /* '<Root>/Cast' */
  real_T red;                          /* '<Root>/PACE_SYSTEM' */
  real_T blue;                         /* '<Root>/PACE_SYSTEM' */
  real_T green;                        /* '<Root>/PACE_SYSTEM' */
  real_T Gain;                         /* '<S12>/Gain' */
  real_T d;
  real_T y;
  real_T d1;
  real32_T Gain2[2];                   /* '<S15>/Gain2' */
  real32_T VectorConcatenate1[2];      /* '<S15>/Vector Concatenate1' */
  uint8_T IntegertoBitConverter[8];    /* '<S15>/Integer to Bit Converter' */
  real32_T PACING_REF_PWM;             /* '<Root>/PACE_SYSTEM' */
  Pace_Sense_Response Cast9;           /* '<S15>/Cast9' */
  Pace_Sense_Chamber Cast8;            /* '<S15>/Cast8' */
  Pace_Chamber Cast7;                  /* '<S15>/Cast7' */
  uint16_T Cast11[2];                  /* '<S15>/Cast11' */
  uint16_T sense_timeout_threshold;    /* '<S4>/RATE_CTRL_SYSTEM' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
} B_Assignment1_V6_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_Assignme_T obj; /* '<S1>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S2>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_b;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_h;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_bo;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_j;/* '<Root>/Digital Write3' */
  freedomk64f_PWMOutput_Assignm_T obj_d;/* '<S2>/PWM Output' */
  real_T resp_fac_decay[3];            /* '<S4>/RATE_CTRL_SYSTEM' */
  real_T resp_fac_grow[3];             /* '<S4>/RATE_CTRL_SYSTEM' */
  real_T tgt;                          /* '<S4>/RATE_CTRL_SYSTEM' */
  real_T iter;                         /* '<S4>/RATE_CTRL_SYSTEM' */
  real_T rolling_avg;                  /* '<S10>/MATLAB Function2' */
  real_T init_counter;                 /* '<S10>/MATLAB Function2' */
  int32_T sfEvent;                     /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint16_T dif;                        /* '<S4>/RATE_CTRL_SYSTEM' */
  uint8_T is_c9_Assignment1_V6;        /* '<S4>/RATE_CTRL_SYSTEM' */
  uint8_T is_Pace_Rate_Unfixed;        /* '<S4>/RATE_CTRL_SYSTEM' */
  uint8_T is_active_c9_Assignment1_V6; /* '<S4>/RATE_CTRL_SYSTEM' */
  uint8_T temporalCounter_i1_f;        /* '<S4>/RATE_CTRL_SYSTEM' */
  uint8_T is_c3_Assignment1_V6;        /* '<Root>/PACE_SYSTEM' */
  uint8_T is_PACE;                     /* '<Root>/PACE_SYSTEM' */
  uint8_T is_SENSE;                    /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c3_Assignment1_V6; /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<Root>/PACE_SYSTEM' */
} DW_Assignment1_V6_T;

/* Parameters (default storage) */
struct P_Assignment1_V6_T_ {
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S1>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Constant10_Value;             /* Expression: 8.5
                                        * Referenced by: '<S5>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 6
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 12
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 14
                                        * Referenced by: '<S5>/Constant9'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 3.5
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 15
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 30
                                        * Referenced by: '<S5>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0.1
                                        * Referenced by: '<S5>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0.01
                                        * Referenced by: '<S5>/Constant8'
                                        */
  real_T Gain_Gain;                    /* Expression: 10
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value_d[3];          /* Expression: [0.01,0.05,0.2]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant2_Value_o[2];         /* Expression: [1.25,2]
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 150
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 30
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Multiply2_Gain;               /* Expression: 60000
                                        * Referenced by: '<S15>/Multiply2'
                                        */
  real_T Gain11_Gain;                  /* Expression: 1/10
                                        * Referenced by: '<S15>/Gain11'
                                        */
  real_T Multiply_Gain;                /* Expression: 60000
                                        * Referenced by: '<S15>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: 60000
                                        * Referenced by: '<S15>/Multiply1'
                                        */
  real32_T Gain16_Gain;                /* Computed Parameter: Gain16_Gain
                                        * Referenced by: '<S15>/Gain16'
                                        */
  real32_T Gain15_Gain;                /* Computed Parameter: Gain15_Gain
                                        * Referenced by: '<S15>/Gain15'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real32_T Gain7_Gain;                 /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S15>/Gain7'
                                        */
  real32_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S15>/Gain8'
                                        */
  uint32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S15>/Gain5'
                                        */
  uint32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S15>/Gain4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_V6_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Assignment1_V6_T Assignment1_V6_P;

/* Block signals (default storage) */
extern B_Assignment1_V6_T Assignment1_V6_B;

/* Block states (default storage) */
extern DW_Assignment1_V6_T Assignment1_V6_DW;

/* Model entry point functions */
extern void Assignment1_V6_initialize(void);
extern void Assignment1_V6_step(void);
extern void Assignment1_V6_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_V6_T *const Assignment1_V6_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Constant4' : Unused code path elimination
 * Block '<S15>/Cast2' : Unused code path elimination
 * Block '<S15>/Cast3' : Unused code path elimination
 * Block '<S15>/Gain' : Unused code path elimination
 * Block '<S15>/Gain1' : Unused code path elimination
 * Block '<S15>/Gain3' : Unused code path elimination
 * Block '<S15>/Gain6' : Unused code path elimination
 * Block '<Root>/Transpose' : Unused code path elimination
 * Block '<S15>/Cast6' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'Assignment1_V6/Function-Call Subsystem'
 * '<S2>'   : 'Assignment1_V6/HARDWARE_PULSE_INTERFACE'
 * '<S3>'   : 'Assignment1_V6/PACE_SYSTEM'
 * '<S4>'   : 'Assignment1_V6/RATE_SYSTEM'
 * '<S5>'   : 'Assignment1_V6/Subsystem'
 * '<S6>'   : 'Assignment1_V6/Subsystem1'
 * '<S7>'   : 'Assignment1_V6/Function-Call Subsystem/ACCEL_INPUT'
 * '<S8>'   : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR'
 * '<S9>'   : 'Assignment1_V6/RATE_SYSTEM/RATE_CTRL_SYSTEM'
 * '<S10>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER'
 * '<S11>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE'
 * '<S12>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/Subsystem'
 * '<S13>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER/MATLAB Function2'
 * '<S14>'  : 'Assignment1_V6/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE/MATLAB Function'
 * '<S15>'  : 'Assignment1_V6/Subsystem1/PARAMETER_PREPROCESSOR'
 */
#endif                                 /* RTW_HEADER_Assignment1_V6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

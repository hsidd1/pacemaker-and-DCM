/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V5.h
 *
 * Code generated for Simulink model 'Assignment1_V5'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 29 14:33:22 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_V5_h_
#define RTW_HEADER_Assignment1_V5_h_
#ifndef Assignment1_V5_COMMON_INCLUDES_
#define Assignment1_V5_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Assignment1_V5_COMMON_INCLUDES_ */

#include "Assignment1_V5_types.h"
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
  real_T VectorConcatenate1_m[15];     /* '<Root>/Vector Concatenate1' */
  real_T VectorConcatenate2[2];        /* '<S18>/Vector Concatenate2' */
  real_T sense_timeout_threshold;      /* '<S6>/RATE_CTRL_SYSTEM' */
  real_T red;                          /* '<Root>/PACE_SYSTEM' */
  real_T blue;                         /* '<Root>/PACE_SYSTEM' */
  real_T green;                        /* '<Root>/PACE_SYSTEM' */
  real_T rtb_FXOS87006AxesSensor_idx_2;
  uint8_T IntegertoBitConverter[8];    /* '<S18>/Integer to Bit Converter' */
  real32_T Gain2[2];                   /* '<S18>/Gain2' */
  real32_T VectorConcatenate1[2];      /* '<S18>/Vector Concatenate1' */
  real32_T PACING_REF_PWM;             /* '<Root>/PACE_SYSTEM' */
  Pace_Sense_Response Cast9;           /* '<S18>/Cast9' */
  Pace_Sense_Chamber Cast8;            /* '<S18>/Cast8' */
  Pace_Chamber Cast7;                  /* '<S18>/Cast7' */
  boolean_T VectorConcatenate[2];      /* '<Root>/Vector Concatenate' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
} B_Assignment1_V5_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_Assignme_T obj; /* '<S2>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_Assig_T obj_i;/* '<S4>/Analog Input1' */
  freedomk64f_AnalogInput_Assig_T obj_n;/* '<S4>/Analog Input' */
  freedomk64f_DigitalRead_Assig_T obj_o;/* '<S4>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_b;/* '<S4>/Digital Read' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S4>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<S4>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_f;/* '<S3>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_ng;/* '<S3>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_lo;/* '<S3>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_a;/* '<S3>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_o1;/* '<S3>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_ej;/* '<S3>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_bs;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_d;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_ev;/* '<Root>/Digital Write3' */
  freedomk64f_PWMOutput_Assignm_T obj_j;/* '<S4>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_nl;/* '<S4>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_evb;/* '<S3>/PWM Output' */
  real_T rolling_avg;                  /* '<S13>/MATLAB Function2' */
  real_T init_counter;                 /* '<S13>/MATLAB Function2' */
  int32_T sfEvent;                     /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c9_Assignment1_V5; /* '<S6>/RATE_CTRL_SYSTEM' */
  uint8_T is_c3_Assignment1_V5;        /* '<Root>/PACE_SYSTEM' */
  uint8_T is_PACE;                     /* '<Root>/PACE_SYSTEM' */
  uint8_T is_SENSE;                    /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c3_Assignment1_V5; /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<Root>/PACE_SYSTEM' */
  uint8_T is_c7_Assignment1_V5;        /* '<Root>/Chart' */
  uint8_T Output_Candidate[15];        /* '<Root>/Chart' */
  uint8_T Op_Mode;                     /* '<Root>/Chart' */
  uint8_T is_active_c7_Assignment1_V5; /* '<Root>/Chart' */
  uint8_T temporalCounter_i1_n;        /* '<Root>/Chart' */
} DW_Assignment1_V5_T;

/* Parameters (default storage) */
struct P_Assignment1_V5_T_ {
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S2>/FXOS8700 6-Axes Sensor'
                                         */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S4>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S4>/Analog Input1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S4>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S4>/Digital Read1'
                                        */
  real_T Constant2_Value;              /* Expression: 500
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant10_Value;             /* Expression: 16.8
                                        * Referenced by: '<S7>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 6
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 12
                                        * Referenced by: '<S7>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 14
                                        * Referenced by: '<S7>/Constant9'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0.035
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 15
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 0.01
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0.1
                                        * Referenced by: '<S7>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0.01
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Gain_Gain;                    /* Expression: 10
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value_n[3];          /* Expression: [0.01,0.05,0.2]
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant2_Value_i[2];         /* Expression: [1.25,2]
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant1_Value_n;            /* Expression: 150
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 30
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Multiply2_Gain;               /* Expression: 60000
                                        * Referenced by: '<S18>/Multiply2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S18>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S18>/Gain5'
                                        */
  real_T Multiply_Gain;                /* Expression: 60000
                                        * Referenced by: '<S18>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: 60000
                                        * Referenced by: '<S18>/Multiply1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real32_T Gain16_Gain;                /* Computed Parameter: Gain16_Gain
                                        * Referenced by: '<S18>/Gain16'
                                        */
  real32_T Gain15_Gain;                /* Computed Parameter: Gain15_Gain
                                        * Referenced by: '<S18>/Gain15'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real32_T Gain7_Gain;                 /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S18>/Gain7'
                                        */
  real32_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S18>/Gain8'
                                        */
  real32_T Gain11_Gain;                /* Computed Parameter: Gain11_Gain
                                        * Referenced by: '<S18>/Gain11'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S18>/Gain6'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real32_T Gain_Gain_k2;               /* Computed Parameter: Gain_Gain_k2
                                        * Referenced by: '<S18>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_V5_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Assignment1_V5_T Assignment1_V5_P;

/* Block signals (default storage) */
extern B_Assignment1_V5_T Assignment1_V5_B;

/* Block states (default storage) */
extern DW_Assignment1_V5_T Assignment1_V5_DW;

/* Model entry point functions */
extern void Assignment1_V5_initialize(void);
extern void Assignment1_V5_step(void);
extern void Assignment1_V5_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_V5_T *const Assignment1_V5_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Cast To Boolean2' : Unused code path elimination
 * Block '<S4>/Cast To Double' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S4>/Data Type Conversion' : Unused code path elimination
 * Block '<S4>/Data Type Conversion1' : Unused code path elimination
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Gain1' : Unused code path elimination
 * Block '<S4>/Gain2' : Unused code path elimination
 * Block '<S4>/Gain3' : Unused code path elimination
 * Block '<S4>/Subtract' : Unused code path elimination
 * Block '<S4>/Subtract1' : Unused code path elimination
 * Block '<S18>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S18>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S18>/Cast To Double2' : Eliminate redundant data type conversion
 * Block '<S18>/Cast6' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Assignment1_V5'
 * '<S1>'   : 'Assignment1_V5/Chart'
 * '<S2>'   : 'Assignment1_V5/HARDWARE_ACCEL_INTERFACE'
 * '<S3>'   : 'Assignment1_V5/HARDWARE_PULSE_INTERFACE'
 * '<S4>'   : 'Assignment1_V5/HARDWARE_SENSE_INTERFACE'
 * '<S5>'   : 'Assignment1_V5/PACE_SYSTEM'
 * '<S6>'   : 'Assignment1_V5/RATE_SYSTEM'
 * '<S7>'   : 'Assignment1_V5/Subsystem'
 * '<S8>'   : 'Assignment1_V5/Subsystem1'
 * '<S9>'   : 'Assignment1_V5/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT'
 * '<S10>'  : 'Assignment1_V5/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT/MATLAB Function'
 * '<S11>'  : 'Assignment1_V5/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR'
 * '<S12>'  : 'Assignment1_V5/RATE_SYSTEM/RATE_CTRL_SYSTEM'
 * '<S13>'  : 'Assignment1_V5/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER'
 * '<S14>'  : 'Assignment1_V5/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE'
 * '<S15>'  : 'Assignment1_V5/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/Subsystem'
 * '<S16>'  : 'Assignment1_V5/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER/MATLAB Function2'
 * '<S17>'  : 'Assignment1_V5/RATE_SYSTEM/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE/MATLAB Function'
 * '<S18>'  : 'Assignment1_V5/Subsystem1/PARAMETER_PREPROCESSOR'
 */
#endif                                 /* RTW_HEADER_Assignment1_V5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

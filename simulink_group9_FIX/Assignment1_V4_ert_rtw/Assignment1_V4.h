/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V4.h
 *
 * Code generated for Simulink model 'Assignment1_V4'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 27 03:25:34 2023
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
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Assignment1_V4_COMMON_INCLUDES_ */

#include "Assignment1_V4_types.h"
#include <string.h>
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

/* Block signals for system '<Root>/HARDWARE_TX_INTERFACE' */
typedef struct {
  uint8_T BytePack[4];                 /* '<S4>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S4>/Byte Pack1' */
} B_HARDWARE_TX_INTERFACE_Assig_T;

/* Block states (default storage) for system '<Root>/HARDWARE_TX_INTERFACE' */
typedef struct {
  freedomk64f_SCIWrite_Assignme_T obj; /* '<S4>/Serial Transmit' */
} DW_HARDWARE_TX_INTERFACE_Assi_T;

/* Block signals (default storage) */
typedef struct {
  real_T VectorConcatenate1_m[15];     /* '<Root>/Vector Concatenate1' */
  uint8_T RxData[64];
  uint8_T RxDataLocChar[64];
  uint32_T tmp_data[15];
  uint8_T x_data[60];
  real_T Gain2[2];                     /* '<S9>/Gain2' */
  real_T VectorConcatenate2[2];        /* '<S9>/Vector Concatenate2' */
  real_T VectorConcatenate1[2];        /* '<S9>/Vector Concatenate1' */
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  real_T sense_timeout_threshold;      /* '<Root>/RATE_CTRL_SYSTEM' */
  real_T PACING_REF_PWM;               /* '<Root>/PACE_SYSTEM' */
  real_T red;                          /* '<Root>/PACE_SYSTEM' */
  real_T blue;                         /* '<Root>/PACE_SYSTEM' */
  real_T green;                        /* '<Root>/PACE_SYSTEM' */
  real_T Params_Arr[15];               /* '<Root>/Chart' */
  int32_T DataTypeConversion;          /* '<S3>/Data Type Conversion' */
  int32_T DataTypeConversion1;         /* '<S3>/Data Type Conversion1' */
  Pace_Sense_Response PACE_SENSE_RESPONSE;/* '<S9>/MATLAB Function' */
  Pace_Sense_Chamber PACE_SENSE_CHAMBER;/* '<S9>/MATLAB Function' */
  Pace_Chamber PACE_CHAMBER;           /* '<S9>/MATLAB Function' */
  uint8_T Params_Raw[8];               /* '<Root>/Chart' */
  uint8_T TX_ctrlmode;                 /* '<Root>/Chart' */
  boolean_T VectorConcatenate[2];      /* '<Root>/Vector Concatenate' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACE_SYSTEM' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACE_SYSTEM' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACE_SYSTEM' */
  B_HARDWARE_TX_INTERFACE_Assig_T HARDWARE_TX_INTERFACE;/* '<Root>/HARDWARE_TX_INTERFACE' */
} B_Assignment1_V4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_AnalogInput_Assig_T obj; /* '<S3>/Analog Input1' */
  freedomk64f_AnalogInput_Assig_T obj_i;/* '<S3>/Analog Input' */
  freedomk64f_DigitalRead_Assig_T obj_ir;/* '<S3>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_m;/* '<S3>/Digital Read' */
  freedomk64f_SCIRead_Assignmen_T obj_c;/* '<Root>/Serial Receive' */
  freedomk64f_DigitalWrite_Assi_T obj_o;/* '<S3>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_b;/* '<S3>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_d;/* '<S3>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_a;/* '<S2>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_o1;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_f;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_n;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_fj;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_ia;/* '<Root>/Digital Write3' */
  freedomk64f_PWMOutput_Assignm_T obj_j;/* '<S3>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_dx;/* '<S3>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_lo;/* '<S2>/PWM Output' */
  real_T Output_Candidate[15];         /* '<Root>/Chart' */
  int32_T sfEvent;                     /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint32_T Op_Mode;                    /* '<Root>/Chart' */
  uint32_T temporalCounter_i1_g;       /* '<Root>/Chart' */
  uint8_T is_active_c9_Assignment1_V4; /* '<Root>/RATE_CTRL_SYSTEM' */
  uint8_T is_c3_Assignment1_V4;        /* '<Root>/PACE_SYSTEM' */
  uint8_T is_PACE;                     /* '<Root>/PACE_SYSTEM' */
  uint8_T is_SENSE;                    /* '<Root>/PACE_SYSTEM' */
  uint8_T is_active_c3_Assignment1_V4; /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detect;             /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Detected;           /* '<Root>/PACE_SYSTEM' */
  uint8_T tp_Sense_Fail;               /* '<Root>/PACE_SYSTEM' */
  uint8_T is_c7_Assignment1_V4;        /* '<Root>/Chart' */
  uint8_T iter;                        /* '<Root>/Chart' */
  uint8_T Rxint_buf[64];               /* '<Root>/Chart' */
  uint8_T Rx_buf[64];                  /* '<Root>/Chart' */
  uint8_T is_active_c7_Assignment1_V4; /* '<Root>/Chart' */
  DW_HARDWARE_TX_INTERFACE_Assi_T HARDWARE_TX_INTERFACE;/* '<Root>/HARDWARE_TX_INTERFACE' */
} DW_Assignment1_V4_T;

/* Parameters for system: '<Root>/HARDWARE_TX_INTERFACE' */
struct P_HARDWARE_TX_INTERFACE_Assig_T_ {
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S4>/Switch'
                                        */
};

/* Parameters (default storage) */
struct P_Assignment1_V4_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S3>/Analog Input1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S3>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S3>/Digital Read1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T Constant2_Value;              /* Expression: 500
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Constant10_Value;             /* Expression: 111
                                        * Referenced by: '<S7>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<S7>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 2
                                        * Referenced by: '<S7>/Constant9'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant2_Value_j;            /* Expression: 3.5
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 150
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 10
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 8
                                        * Referenced by: '<S7>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 2
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 20
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Multiply2_Gain;               /* Expression: 1000/60
                                        * Referenced by: '<S9>/Multiply2'
                                        */
  real_T Multiply_Gain;                /* Expression: 1000/60
                                        * Referenced by: '<S9>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: 1000/60
                                        * Referenced by: '<S9>/Multiply1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 20
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 20
                                        * Referenced by: '<S9>/Gain'
                                        */
  uint32_T Gain3_Gain_h;               /* Computed Parameter: Gain3_Gain_h
                                        * Referenced by: '<S9>/Gain3'
                                        */
  P_HARDWARE_TX_INTERFACE_Assig_T HARDWARE_TX_INTERFACE;/* '<Root>/HARDWARE_TX_INTERFACE' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_V4_T {
  const char_T * volatile errorStatus;
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
 * Block '<S9>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S9>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S9>/Cast To Double2' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'Assignment1_V4/Chart'
 * '<S2>'   : 'Assignment1_V4/HARDWARE_PULSE_INTERFACE'
 * '<S3>'   : 'Assignment1_V4/HARDWARE_SENSE_INTERFACE'
 * '<S4>'   : 'Assignment1_V4/HARDWARE_TX_INTERFACE'
 * '<S5>'   : 'Assignment1_V4/PACE_SYSTEM'
 * '<S6>'   : 'Assignment1_V4/RATE_CTRL_SYSTEM'
 * '<S7>'   : 'Assignment1_V4/Subsystem'
 * '<S8>'   : 'Assignment1_V4/Subsystem1'
 * '<S9>'   : 'Assignment1_V4/Subsystem1/PARAMETER_PREPROCESSOR'
 * '<S10>'  : 'Assignment1_V4/Subsystem1/PARAMETER_PREPROCESSOR/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Assignment1_V4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

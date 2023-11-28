/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V4.h
 *
 * Code generated for Simulink model 'Assignment1_V4'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 27 17:18:40 2023
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
#include "MW_I2C.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Assignment1_V4_COMMON_INCLUDES_ */

#include "Assignment1_V4_types.h"
#include <string.h>
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

/* Block signals for system '<Root>/HARDWARE_TX_INTERFACE' */
typedef struct {
  uint8_T BytePack[4];                 /* '<S6>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S6>/Byte Pack1' */
} B_HARDWARE_TX_INTERFACE_Assig_T;

/* Block states (default storage) for system '<Root>/HARDWARE_TX_INTERFACE' */
typedef struct {
  freedomk64f_SCIWrite_Assignme_T obj; /* '<S6>/Serial Transmit' */
} DW_HARDWARE_TX_INTERFACE_Assi_T;

/* Block signals (default storage) */
typedef struct {
  real_T VectorConcatenate1_m[15];     /* '<Root>/Vector Concatenate1' */
  uint8_T RxData[64];
  uint8_T RxDataLocChar[64];
  uint32_T tmp_data[15];
  uint8_T x_data[60];
  real_T Gain2[2];                     /* '<S18>/Gain2' */
  real_T VectorConcatenate2[2];        /* '<S18>/Vector Concatenate2' */
  real_T VectorConcatenate1[2];        /* '<S18>/Vector Concatenate1' */
  real_T dv[2];
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T sense_timeout_threshold;      /* '<S10>/RATE_CTRL_SYSTEM' */
  real_T PACING_REF_PWM;               /* '<Root>/PACE_SYSTEM' */
  real_T red;                          /* '<Root>/PACE_SYSTEM' */
  real_T blue;                         /* '<Root>/PACE_SYSTEM' */
  real_T green;                        /* '<Root>/PACE_SYSTEM' */
  real_T Params_Arr[15];               /* '<Root>/Chart' */
  real_T PACE_CHAMBER_tmp;
  real_T PACE_SENSE_CHAMBER_tmp;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  real_T PACE_CHAMBER_tmp_tmp;
  real_T y;
  int32_T DataTypeConversion;          /* '<S5>/Data Type Conversion' */
  int32_T DataTypeConversion1;         /* '<S5>/Data Type Conversion1' */
  Pace_Sense_Response PACE_SENSE_RESPONSE;/* '<S18>/MATLAB Function' */
  Pace_Sense_Chamber PACE_SENSE_CHAMBER;/* '<S18>/MATLAB Function' */
  Pace_Chamber PACE_CHAMBER;           /* '<S18>/MATLAB Function' */
  uint8_T b_SwappedDataBytes[2];
  uint8_T TX_ctrlmode;                 /* '<Root>/Chart' */
  boolean_T VectorConcatenate[2];      /* '<Root>/Vector Concatenate' */
  uint8_T b_RegisterValue;
  uint8_T status;
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
  freedomk64f_fxos8700_Assignme_T obj; /* '<S3>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_Assig_T obj_m;/* '<S5>/Analog Input1' */
  freedomk64f_AnalogInput_Assig_T obj_i;/* '<S5>/Analog Input' */
  freedomk64f_DigitalRead_Assig_T obj_ir;/* '<S5>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_m4;/* '<S5>/Digital Read' */
  freedomk64f_SCIRead_Assignmen_T obj_c;/* '<Root>/Serial Receive' */
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
  real_T tgt;                          /* '<S10>/RATE_CTRL_SYSTEM' */
  real_T dif;                          /* '<S10>/RATE_CTRL_SYSTEM' */
  real_T resp_fac_decay[3];            /* '<S10>/RATE_CTRL_SYSTEM' */
  real_T resp_fac_grow[3];             /* '<S10>/RATE_CTRL_SYSTEM' */
  real_T Output_Candidate[15];         /* '<Root>/Chart' */
  real_T rolling_avg;                  /* '<S11>/MATLAB Function2' */
  real_T init_counter;                 /* '<S11>/MATLAB Function2' */
  int32_T sfEvent;                     /* '<Root>/PACE_SYSTEM' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACE_SYSTEM' */
  uint32_T Op_Mode;                    /* '<Root>/Chart' */
  uint32_T temporalCounter_i1_g;       /* '<Root>/Chart' */
  uint8_T is_c9_Assignment1_V4;        /* '<S10>/RATE_CTRL_SYSTEM' */
  uint8_T is_active_c9_Assignment1_V4; /* '<S10>/RATE_CTRL_SYSTEM' */
  uint8_T temporalCounter_i1_a;        /* '<S10>/RATE_CTRL_SYSTEM' */
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
                                        * Referenced by: '<S6>/Switch'
                                        */
};

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
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T Constant2_Value;              /* Expression: 500
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Constant10_Value;             /* Expression: 111
                                        * Referenced by: '<S8>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 2
                                        * Referenced by: '<S8>/Constant9'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant2_Value_j;            /* Expression: 3.5
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 150
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 10
                                        * Referenced by: '<S8>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 8
                                        * Referenced by: '<S8>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 2
                                        * Referenced by: '<S8>/Constant8'
                                        */
  real_T Constant_Value_e[3];          /* Expression: [0.01,0.05,0.2]
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_i[2];         /* Expression: [1.25,2]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 20
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T Constant_Value_n;             /* Expression: 150
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 30
                                        * Referenced by: '<S13>/Gain'
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
  real_T Gain1_Gain_k;                 /* Expression: 20
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 20
                                        * Referenced by: '<S18>/Gain'
                                        */
  uint32_T Gain3_Gain_h;               /* Computed Parameter: Gain3_Gain_h
                                        * Referenced by: '<S18>/Gain3'
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
 * Block '<S18>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S18>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S18>/Cast To Double2' : Eliminate redundant data type conversion
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
 * '<S6>'   : 'Assignment1_V4/HARDWARE_TX_INTERFACE'
 * '<S7>'   : 'Assignment1_V4/PACE_SYSTEM'
 * '<S8>'   : 'Assignment1_V4/Subsystem'
 * '<S9>'   : 'Assignment1_V4/Subsystem1'
 * '<S10>'  : 'Assignment1_V4/Subsystem2'
 * '<S11>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER'
 * '<S12>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE'
 * '<S13>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/Subsystem'
 * '<S14>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/ACCEL_SMOOTHER/MATLAB Function2'
 * '<S15>'  : 'Assignment1_V4/ACCEL_DATA_PREPROCESSOR/CALC_MOTION_STATE/MATLAB Function'
 * '<S16>'  : 'Assignment1_V4/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT'
 * '<S17>'  : 'Assignment1_V4/HARDWARE_ACCEL_INTERFACE/ACCEL_INPUT/MATLAB Function'
 * '<S18>'  : 'Assignment1_V4/Subsystem1/PARAMETER_PREPROCESSOR'
 * '<S19>'  : 'Assignment1_V4/Subsystem1/PARAMETER_PREPROCESSOR/MATLAB Function'
 * '<S20>'  : 'Assignment1_V4/Subsystem2/RATE_CTRL_SYSTEM'
 */
#endif                                 /* RTW_HEADER_Assignment1_V4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

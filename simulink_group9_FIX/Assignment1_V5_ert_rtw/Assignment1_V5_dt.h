/*
 * Assignment1_V5_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Assignment1_V5".
 *
 * Model version              : 1.36
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Nov 29 02:38:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(Pace_Chamber),
  sizeof(Pace_Sense_Response),
  sizeof(Pace_Sense_Chamber),
  sizeof(Pace_Rate_Mode),
  sizeof(freedomk64f_DigitalWrite_Assi_T),
  sizeof(freedomk64f_fxos8700_Assignme_T),
  sizeof(freedomk64f_PWMOutput_Assignm_T),
  sizeof(freedomk64f_AnalogInput_Assig_T),
  sizeof(freedomk64f_DigitalRead_Assig_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "Pace_Chamber",
  "Pace_Sense_Response",
  "Pace_Sense_Chamber",
  "Pace_Rate_Mode",
  "freedomk64f_DigitalWrite_Assi_T",
  "freedomk64f_fxos8700_Assignme_T",
  "freedomk64f_PWMOutput_Assignm_T",
  "freedomk64f_AnalogInput_Assig_T",
  "freedomk64f_DigitalRead_Assig_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Assignment1_V5_B.Constant[0]), 0, 0, 3 },

  { (char_T *)(&Assignment1_V5_B.Gain2[0]), 0, 0, 6 },

  { (char_T *)(&Assignment1_V5_B.Constant2), 0, 0, 19 },

  { (char_T *)(&Assignment1_V5_B.PACE_SENSE_RESPONSE), 16, 0, 1 },

  { (char_T *)(&Assignment1_V5_B.PACE_SENSE_CHAMBER), 17, 0, 1 },

  { (char_T *)(&Assignment1_V5_B.PACE_RATE_MODE), 18, 0, 1 },

  { (char_T *)(&Assignment1_V5_B.PACE_CHAMBER), 15, 0, 1 },

  { (char_T *)(&Assignment1_V5_B.DataTypeConversion1), 4, 0, 2 },

  { (char_T *)(&Assignment1_V5_B.VectorConcatenate[0]), 8, 0, 8 }
  ,

  { (char_T *)(&Assignment1_V5_DW.obj), 20, 0, 1 },

  { (char_T *)(&Assignment1_V5_DW.obj_i), 22, 0, 2 },

  { (char_T *)(&Assignment1_V5_DW.obj_o), 23, 0, 2 },

  { (char_T *)(&Assignment1_V5_DW.obj_e), 19, 0, 12 },

  { (char_T *)(&Assignment1_V5_DW.obj_j), 21, 0, 3 },

  { (char_T *)(&Assignment1_V5_DW.resp_fac_decay[0]), 0, 0, 9 },

  { (char_T *)(&Assignment1_V5_DW.TAQSigLogging_InsertedFor_RATE_.AQHandles), 11,
    0, 7 },

  { (char_T *)(&Assignment1_V5_DW.sfEvent_m), 6, 0, 1 },

  { (char_T *)(&Assignment1_V5_DW.is_c9_Assignment1_V5), 7, 0, 11 },

  { (char_T *)(&Assignment1_V5_DW.is_active_c9_Assignment1_V5), 3, 0, 24 },

  { (char_T *)(&Assignment1_V5_DW.doneDoubleBufferReInit), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  20U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Assignment1_V5_P.FXOS87006AxesSensor_SampleTime), 0, 0, 54 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] Assignment1_V5_dt.h */

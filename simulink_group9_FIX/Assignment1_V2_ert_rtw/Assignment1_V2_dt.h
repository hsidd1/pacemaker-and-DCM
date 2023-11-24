/*
 * Assignment1_V2_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Assignment1_V2".
 *
 * Model version              : 2.38
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 20 17:32:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. ROM efficiency
 *    2. RAM efficiency
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
  sizeof(Pace_Mode),
  sizeof(Pace_Chamber),
  sizeof(Pace_Sense_Response),
  sizeof(Pace_Sense_Chamber),
  sizeof(Pace_Rate_Mode),
  sizeof(Rate_Motion_State),
  sizeof(freedomk64f_DigitalWrite_Assi_T),
  sizeof(freedomk64f_PWMOutput_Assignm_T),
  sizeof(freedomk64f_DigitalRead_Assig_T),
  sizeof(freedomk64f_fxos8700_Assignme_T),
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
  "Pace_Mode",
  "Pace_Chamber",
  "Pace_Sense_Response",
  "Pace_Sense_Chamber",
  "Pace_Rate_Mode",
  "Rate_Motion_State",
  "freedomk64f_DigitalWrite_Assi_T",
  "freedomk64f_PWMOutput_Assignm_T",
  "freedomk64f_DigitalRead_Assig_T",
  "freedomk64f_fxos8700_Assignme_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Assignment1_V2_B.Gain2[0]), 0, 0, 11 },

  { (char_T *)(&Assignment1_V2_B.Motion_State), 20, 0, 1 },

  { (char_T *)(&Assignment1_V2_B.PACE_SENSE_RESPONSE), 17, 0, 1 },

  { (char_T *)(&Assignment1_V2_B.PACE_SENSE_CHAMBER), 18, 0, 1 },

  { (char_T *)(&Assignment1_V2_B.PACE_CHAMBER), 16, 0, 1 },

  { (char_T *)(&Assignment1_V2_B.VectorConcatenate[0]), 8, 0, 8 }
  ,

  { (char_T *)(&Assignment1_V2_DW.obj), 24, 0, 1 },

  { (char_T *)(&Assignment1_V2_DW.obj_m), 23, 0, 2 },

  { (char_T *)(&Assignment1_V2_DW.obj_p), 21, 0, 9 },

  { (char_T *)(&Assignment1_V2_DW.obj_b), 22, 0, 3 },

  { (char_T *)(&Assignment1_V2_DW.rolling_avg), 0, 0, 2502 },

  { (char_T *)(&Assignment1_V2_DW.TAQSigLogging_InsertedFor_Subsy.AQHandles), 11,
    0, 4 },

  { (char_T *)(&Assignment1_V2_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&Assignment1_V2_DW.is_c3_Assignment1_V2), 7, 0, 7 },

  { (char_T *)(&Assignment1_V2_DW.is_active_c3_Assignment1_V2), 3, 0, 4 },

  { (char_T *)(&Assignment1_V2_DW.Buffer_Internal_not_empty), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Assignment1_V2_P.EnumeratedConstant_Value), 15, 0, 1 },

  { (char_T *)(&Assignment1_V2_P.DigitalRead_SampleTime), 0, 0, 15 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Assignment1_V2_dt.h */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V6_data.c
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

#include "Assignment1_V6.h"

/* Block parameters (default storage) */
P_Assignment1_V6_T Assignment1_V6_P = {
  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S3>/Tapped Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S3>/FXOS8700 6-Axes Sensor'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S5>/Analog Input'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S5>/Analog Input1'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S5>/Digital Read'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S5>/Digital Read1'
   */
  -1.0,

  /* Computed Parameter: rate_response_fac_Y0
   * Referenced by: '<S15>/rate_response_fac'
   */
  0.0,

  /* Expression: [0.01,0.05,0.2]
   * Referenced by: '<S15>/Constant'
   */
  { 0.01, 0.05, 0.2 },

  /* Expression: -300
   * Referenced by: '<S15>/Gain'
   */
  -300.0,

  /* Expression: -300
   * Referenced by: '<S15>/Gain1'
   */
  -300.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Serial Receive'
   */
  -1.0,

  /* Expression: 60000
   * Referenced by: '<S12>/Multiply1'
   */
  60000.0,

  /* Expression: 85
   * Referenced by: '<S10>/Constant10'
   */
  85.0,

  /* Expression: 60
   * Referenced by: '<S10>/Constant'
   */
  60.0,

  /* Expression: 120
   * Referenced by: '<S10>/Constant5'
   */
  120.0,

  /* Expression: 140
   * Referenced by: '<S10>/Constant9'
   */
  140.0,

  /* Expression: 40
   * Referenced by: '<S10>/Constant1'
   */
  40.0,

  /* Expression: 10
   * Referenced by: '<S10>/Constant3'
   */
  10.0,

  /* Expression: 35
   * Referenced by: '<S10>/Constant2'
   */
  35.0,

  /* Expression: 150
   * Referenced by: '<S10>/Constant4'
   */
  150.0,

  /* Expression: 10
   * Referenced by: '<S10>/Constant6'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant7'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant8'
   */
  1.0,

  /* Expression: 500
   * Referenced by: '<Root>/Constant2'
   */
  500.0,

  /* Expression: 0.5
   * Referenced by: '<S5>/Constant1'
   */
  0.5,

  /* Expression: 100
   * Referenced by: '<S5>/Gain'
   */
  100.0,

  /* Expression: 3.3
   * Referenced by: '<S5>/Gain2'
   */
  3.3,

  /* Expression: 100
   * Referenced by: '<S5>/Gain1'
   */
  100.0,

  /* Expression: 3.3
   * Referenced by: '<S5>/Gain3'
   */
  3.3,

  /* Expression: 60000
   * Referenced by: '<S12>/Multiply'
   */
  60000.0,

  /* Expression: 150
   * Referenced by: '<S8>/Constant1'
   */
  150.0,

  /* Expression: [1.25,2]
   * Referenced by: '<S8>/Constant2'
   */
  { 1.25, 2.0 },

  /* Expression: 30
   * Referenced by: '<S18>/Gain'
   */
  30.0,

  /* Expression: 60000
   * Referenced by: '<S12>/Multiply2'
   */
  60000.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Computed Parameter: Gain16_Gain
   * Referenced by: '<S12>/Gain16'
   */
  0.1F,

  /* Computed Parameter: Gain15_Gain
   * Referenced by: '<S12>/Gain15'
   */
  0.1F,

  /* Computed Parameter: Gain2_Gain_g
   * Referenced by: '<S12>/Gain2'
   */
  20.0F,

  /* Computed Parameter: Gain7_Gain
   * Referenced by: '<S12>/Gain7'
   */
  0.1F,

  /* Computed Parameter: Gain8_Gain
   * Referenced by: '<S12>/Gain8'
   */
  0.1F,

  /* Computed Parameter: Gain6_Gain
   * Referenced by: '<S12>/Gain6'
   */
  0.1F,

  /* Computed Parameter: Gain1_Gain_m
   * Referenced by: '<S12>/Gain1'
   */
  20.0F,

  /* Computed Parameter: Gain3_Gain_o
   * Referenced by: '<S12>/Gain3'
   */
  0.1F,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S12>/Gain'
   */
  20.0F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S12>/Gain4'
   */
  1000U,

  /* Computed Parameter: Gain5_Gain
   * Referenced by: '<S12>/Gain5'
   */
  60000U,

  /* Start of '<Root>/HARDWARE_TX_INTERFACE' */
  {
    /* Computed Parameter: Switch_Threshold
     * Referenced by: '<S6>/Switch'
     */
    2U
  }
  /* End of '<Root>/HARDWARE_TX_INTERFACE' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V5.c
 *
 * Code generated for Simulink model 'Assignment1_V5'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 29 02:38:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment1_V5.h"
#include "rtwtypes.h"
#include "Assignment1_V5_types.h"
#include <string.h>
#include "Assignment1_V5_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_I2C.h"
#include "Assignment1_V5_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Assi_finally_IN_Detect_Cur_Mode (2U)
#define Assi_finally_IN_Save_Buf_Params (5U)
#define Assignme_IN_ECG_TX_Loop_Standby (3U)
#define Assignment1_V5_CALL_EVENT      (-1)
#define Assignment1_V5_IN_Conv_Data    (1U)
#define Assignment1_V5_IN_Init         (4U)
#define Assignment1_V5_finally_IN_Init (4U)
#define Assignment1__IN_Detect_Cur_Mode (2U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1__IN_Save_Buf_Params (5U)
#define Assignment_finally_IN_Conv_Data (1U)
#define finally_IN_ECG_TX_Loop_Standby (3U)

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Ass_finally_IN_Sense_Detected_p (2U)
#define Ass_finally_IN_Sense_Disabled_l (3U)
#define Assig_finally_IN_Discharge_Prep (2U)
#define Assig_finally_IN_Sense_Detect_l (1U)
#define Assig_finally_IN_Sense_Detected (6U)
#define Assig_finally_IN_Sense_Disabled (7U)
#define Assig_finally_IN_Sense_Finish_o (5U)
#define Assignm_finally_IN_Sense_Detect (5U)
#define Assignm_finally_IN_Sense_Fail_c (4U)
#define Assignm_finally_IN_Sense_Finish (9U)
#define Assignm_finally_IN_Sense_Wait_l (6U)
#define Assignmen_finally_IN_Sense_Fail (8U)
#define Assignmen_finally_IN_Sense_Wait (10U)
#define Assignment1_V5_IN_Charge       (1U)
#define Assignment1_V5_IN_PACE         (1U)
#define Assignment1_V5_IN_Pace_Atr     (3U)
#define Assignment1_V5_IN_Pace_Vent    (4U)
#define Assignment1_V5_IN_SENSE        (2U)
#define Assignment1_V5_IN_Sense_Detect (1U)
#define Assignment1_V5_IN_Sense_Fail   (4U)
#define Assignment1_V5_IN_Sense_Finish (5U)
#define Assignment1_V5_IN_Sense_Wait   (6U)
#define Assignment1_V5_event_pace_compl (0)
#define Assignment1_V_IN_Discharge_Prep (2U)
#define Assignment1_V_IN_Sense_Detected (2U)
#define Assignment1_V_IN_Sense_Disabled (3U)
#define Assignment1_V_finally_IN_Charge (1U)
#define Assignment1_event_sense_timeout (1)
#define Assignment1_finally_IN_Pace_Atr (3U)
#define Assignment_finally_IN_Pace_Vent (4U)

/* Named constants for Chart: '<S6>/RATE_CTRL_SYSTEM' */
#define Assignment1_V5_IN_Bigger       (1U)
#define Assignment1_V5_IN_Detect_Mode  (1U)
#define Assignment1_V5_IN_Init_e       (2U)
#define Assignment1_V5_IN_Smaller      (3U)
#define Assignment1_V5_IN_check_dif    (4U)
#define Assignment1_V5_IN_get_tgt      (5U)
#define Assignment1_V_IN_Pace_LRL_Fixed (3U)
#define Assignment1_V_IN_Pace_Rate_Init (2U)
#define Assignment_IN_Pace_Rate_Unfixed (4U)

/* Block signals (default storage) */
B_Assignment1_V5_T Assignment1_V5_B;

/* Block states (default storage) */
DW_Assignment1_V5_T Assignment1_V5_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V5_T Assignment1_V5_M_;
RT_MODEL_Assignment1_V5_T *const Assignment1_V5_M = &Assignment1_V5_M_;

/* Forward declaration for local functions */
static void Assignment1_V5_Process_Rx(uint8_T output_set[15]);
static real_T Assignment1_V5_mod(real_T x, real_T y);
static Pace_Chamber As_convert_to_enum_Pace_Chamber(int32_T input);
static Pace_Sense_Chamber convert_to_enum_Pace_Sense_Cham(int32_T input);
static Pace_Sense_Response convert_to_enum_Pace_Sense_Resp(int32_T input);
static Pace_Rate_Mode convert_to_enum_Pace_Rate_Mode(int32_T input);
static real_T Assignment1__Calc_Rate_Response(real_T activity, real_T LRP,
  real_T MSP);
static void Assignmen_Calc_Expo_Rate_Factor(real_T time_tgt, const real_T
  tgt_threshold[3], real_T output_set[3]);
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment1_enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
static void Assignment1_V5_SENSE(void);
static void Assignment1_V_c3_Assignment1_V5(void);
static void Assignment1_V5_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj);

/* Function for Chart: '<Root>/Chart' */
static void Assignment1_V5_Process_Rx(uint8_T output_set[15])
{
  int32_T i;
  uint8_T tmp;
  for (i = 0; i < 15; i++) {
    memcpy((void *)&tmp, NULL, (size_t)1 * sizeof(uint8_T));
    output_set[i] = tmp;
  }
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static real_T Assignment1_V5_mod(real_T x, real_T y)
{
  real_T q;
  real_T r;
  boolean_T rEQ0;
  r = x;
  if (y == 0.0) {
    if (x == 0.0) {
      r = y;
    }
  } else if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsNaN(y)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0 / y;
  } else if (rtIsInf(y)) {
    if ((y < 0.0) != (x < 0.0)) {
      r = y;
    }
  } else {
    r = fmod(x, y);
    rEQ0 = (r == 0.0);
    if ((!rEQ0) && (y > floor(y))) {
      q = fabs(x / y);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = y * 0.0;
    } else if ((x < 0.0) != (y < 0.0)) {
      r += y;
    }
  }

  return r;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static Pace_Chamber As_convert_to_enum_Pace_Chamber(int32_T input)
{
  Pace_Chamber output;

  /* Initialize output value to default value for Pace_Chamber (Atrium) */
  output = Atrium;
  if ((input >= 1) && (input <= 3)) {
    /* Set output value to input value if it is a member of Pace_Chamber */
    output = (Pace_Chamber)input;
  }

  return output;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static Pace_Sense_Chamber convert_to_enum_Pace_Sense_Cham(int32_T input)
{
  Pace_Sense_Chamber output;

  /* Initialize output value to default value for Pace_Sense_Chamber (None_Sense) */
  output = None_Sense;
  if ((input >= 0) && (input <= 3)) {
    /* Set output value to input value if it is a member of Pace_Sense_Chamber */
    output = (Pace_Sense_Chamber)input;
  }

  return output;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static Pace_Sense_Response convert_to_enum_Pace_Sense_Resp(int32_T input)
{
  Pace_Sense_Response output;

  /* Initialize output value to default value for Pace_Sense_Response (Nothing) */
  output = Nothing;
  if ((input >= 0) && (input <= 3)) {
    /* Set output value to input value if it is a member of Pace_Sense_Response */
    output = (Pace_Sense_Response)input;
  }

  return output;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static Pace_Rate_Mode convert_to_enum_Pace_Rate_Mode(int32_T input)
{
  Pace_Rate_Mode output;

  /* Initialize output value to default value for Pace_Rate_Mode (Disabled) */
  output = Disabled;
  if ((input >= 0) && (input <= 1)) {
    /* Set output value to input value if it is a member of Pace_Rate_Mode */
    output = (Pace_Rate_Mode)input;
  }

  return output;
}

/* Function for Chart: '<S6>/RATE_CTRL_SYSTEM' */
static real_T Assignment1__Calc_Rate_Response(real_T activity, real_T LRP,
  real_T MSP)
{
  real_T value;
  value = 1.0 / (2.6 * activity - 40.0) * 60000.0;
  if ((value > LRP) || (value < 0.0)) {
    value = LRP;
  }

  if (value < MSP) {
    value = MSP;
  }

  return value;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for Chart: '<S6>/RATE_CTRL_SYSTEM' */
static void Assignmen_Calc_Expo_Rate_Factor(real_T time_tgt, const real_T
  tgt_threshold[3], real_T output_set[3])
{
  real_T y;
  y = 1.0 / -time_tgt;
  output_set[0] = rt_powd_snf(tgt_threshold[0], y) - 1.0;
  output_set[1] = rt_powd_snf(tgt_threshold[1], y) - 1.0;
  output_set[2] = rt_powd_snf(tgt_threshold[2], y) - 1.0;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V5_DW.sfEvent_m;
  Assignment1_V5_DW.sfEvent_m = Assignment1_V5_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V5();
  Assignment1_V5_DW.sfEvent_m = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_enter_atomic_Charge(void)
{
  Assignment1_V5_B.PACE_GND_CTRL = true;
  if (Assignment1_V5_B.PACE_CHAMBER == Atrium) {
    Assignment1_V5_B.ATR_GND_CTRL = true;
    Assignment1_V5_B.VENT_GND_CTRL = false;
  } else {
    Assignment1_V5_B.ATR_GND_CTRL = false;
    Assignment1_V5_B.VENT_GND_CTRL = true;
  }

  Assignment1_V5_B.ATR_PACE_CTRL = false;
  Assignment1_V5_B.VENT_PACE_CTRL = false;
  Assignment1_V5_B.PACING_REF_PWM = Assignment1_V5_B.Gain2[(int32_T)
    Assignment1_V5_B.PACE_CHAMBER - 1];
  Assignment1_V5_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V5_DW.sfEvent_m;
  Assignment1_V5_DW.sfEvent_m = Assignment1_event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V5();
  Assignment1_V5_DW.sfEvent_m = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  Assignment1_V5_B.red = 0.0;
  Assignment1_V5_B.green = 0.0;
  Assignment1_V5_B.blue = 0.0;
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V5_SENSE(void)
{
  boolean_T guard1 = false;
  if (Assignment1_V5_DW.sfEvent_m == Assignment1_event_sense_timeout) {
    Assignment1_V5_DW.tp_Sense_Detect = 0U;
    Assignment1_V5_DW.tp_Sense_Detected = 0U;
    Assignment1_V5_DW.tp_Sense_Fail = 0U;
    Assignment1_V5_DW.is_finally_SENSE = 0U;
    Assignment1_V5_DW.is_SENSE = Assignment1__IN_NO_ACTIVE_CHILD;
    Assignment1_V5_DW.is_c3_Assignment1_V5 = Assignment1_V5_IN_PACE;
    Assignment1_V5_DW.is_PACE = Assignment1_V_IN_Discharge_Prep;
    Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
      Assig_finally_IN_Discharge_Prep;
    Assignment1_V5_DW.is_finally_PACE = Assig_finally_IN_Discharge_Prep;
    Assignment1_V5_B.PACING_REF_PWM = 0.0;
    Assignment1_V5_B.PACE_CHARGE_CTRL = false;
    Assignment1_V5_B.PACE_GND_CTRL = true;
    Assignment1_V5_B.ATR_GND_CTRL = false;
    Assignment1_V5_B.VENT_GND_CTRL = false;
  } else {
    guard1 = false;
    switch (Assignment1_V5_DW.is_SENSE) {
     case Assignment1_V5_IN_Sense_Detect:
      if (Assignment1_V5_B.PACE_SENSE_RESPONSE == Nothing) {
        guard1 = true;
      } else if (Assignment1_V5_B.VectorConcatenate[(int32_T)
                 Assignment1_V5_B.PACE_SENSE_CHAMBER - 1]) {
        Assignment1_V5_DW.tp_Sense_Detect = 0U;
        Assignment1_V5_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
        Assignment1_V5_DW.tp_Sense_Detected = 1U;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assig_finally_IN_Sense_Detected;
        Assignment1_V5_DW.is_finally_SENSE = Ass_finally_IN_Sense_Detected_p;
        Assignment1_V5_B.red = 0.0;
        Assignment1_V5_B.green = 0.0;
        Assignment1_V5_B.blue = 0.0;
      } else if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
                 (Assignment1_V5_B.sense_timeout_threshold -
                  Assignment1_V5_B.VectorConcatenate2[(int32_T)
                  Assignment1_V5_B.PACE_SENSE_CHAMBER - 1])) {
        guard1 = true;
      } else {
        Assignment1_V5_B.red = 0.0;
        Assignment1_V5_B.green = 1.0;
        Assignment1_V5_B.blue = 0.0;
      }
      break;

     case Assignment1_V_IN_Sense_Detected:
      Assignment1_V5_DW.tp_Sense_Detected = 0U;
      Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Wait;
      Assignment1_V5_DW.temporalCounter_i1 = 0U;
      Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
        Assignmen_finally_IN_Sense_Wait;
      Assignment1_V5_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Wait_l;
      Assignment1_V5_B.red = 1.0;
      Assignment1_V5_B.green = 0.0;
      Assignment1_V5_B.blue = 0.0;
      break;

     case Assignment1_V_IN_Sense_Disabled:
      if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Assignment1_V5_B.sense_timeout_threshold)) {
        Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Fail;
        Assignment1_V5_DW.tp_Sense_Fail = 1U;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assignmen_finally_IN_Sense_Fail;
        Assignment1_V5_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_c;
        Assignm_enter_atomic_Sense_Fail();
      }
      break;

     case Assignment1_V5_IN_Sense_Fail:
      Assignment1_V5_B.red = 0.0;
      Assignment1_V5_B.green = 0.0;
      Assignment1_V5_B.blue = 0.0;
      broadcast_sense_timeout_c3_Assi();
      break;

     case Assignment1_V5_IN_Sense_Finish:
      if (Assignment1_V5_B.PACE_SENSE_RESPONSE != Nothing) {
        Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Wait;
        Assignment1_V5_DW.temporalCounter_i1 = 0U;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assignmen_finally_IN_Sense_Wait;
        Assignment1_V5_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Wait_l;
        Assignment1_V5_B.red = 1.0;
        Assignment1_V5_B.green = 0.0;
        Assignment1_V5_B.blue = 0.0;
      } else {
        Assignment1_V5_DW.is_SENSE = Assignment1_V_IN_Sense_Disabled;
        Assignment1_V5_DW.temporalCounter_i1 = 0U;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assig_finally_IN_Sense_Disabled;
        Assignment1_V5_DW.is_finally_SENSE = Ass_finally_IN_Sense_Disabled_l;
      }
      break;

     case Assignment1_V5_IN_Sense_Wait:
      if (Assignment1_V5_B.PACE_SENSE_RESPONSE == Nothing) {
        Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Fail;
        Assignment1_V5_DW.tp_Sense_Fail = 1U;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assignmen_finally_IN_Sense_Fail;
        Assignment1_V5_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_c;
        Assignm_enter_atomic_Sense_Fail();
      } else if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
                 (Assignment1_V5_B.VectorConcatenate2[(int32_T)
                  Assignment1_V5_B.PACE_SENSE_CHAMBER - 1])) {
        Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Detect;
        Assignment1_V5_DW.temporalCounter_i1 = 0U;
        Assignment1_V5_DW.tp_Sense_Detect = 1U;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assignm_finally_IN_Sense_Detect;
        Assignment1_V5_DW.is_finally_SENSE = Assig_finally_IN_Sense_Detect_l;
        Assignment1_V5_B.red = 0.0;
        Assignment1_V5_B.green = 1.0;
        Assignment1_V5_B.blue = 0.0;
      } else {
        Assignment1_V5_B.red = 1.0;
        Assignment1_V5_B.green = 0.0;
        Assignment1_V5_B.blue = 0.0;
      }
      break;
    }

    if (guard1) {
      Assignment1_V5_DW.tp_Sense_Detect = 0U;
      Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Fail;
      Assignment1_V5_DW.tp_Sense_Fail = 1U;
      Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
        Assignmen_finally_IN_Sense_Fail;
      Assignment1_V5_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_c;
      Assignm_enter_atomic_Sense_Fail();
    }
  }
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V_c3_Assignment1_V5(void)
{
  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V5_DW.is_active_c3_Assignment1_V5 == 0U) {
    Assignment1_V5_DW.is_active_c3_Assignment1_V5 = 1U;
    Assignment1_V5_DW.is_c3_Assignment1_V5 = Assignment1_V5_IN_SENSE;
    Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Finish;
    Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
      Assignm_finally_IN_Sense_Finish;
    Assignment1_V5_DW.is_finally_SENSE = Assig_finally_IN_Sense_Finish_o;
  } else {
    switch (Assignment1_V5_DW.is_c3_Assignment1_V5) {
     case Assignment1_V5_IN_PACE:
      if (Assignment1_V5_DW.sfEvent_m == Assignment1_V5_event_pace_compl) {
        Assignment1_V5_DW.is_finally_PACE = 0U;
        Assignment1_V5_DW.is_PACE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V5_DW.is_c3_Assignment1_V5 = Assignment1_V5_IN_SENSE;
        Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Finish;
        Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
          Assignm_finally_IN_Sense_Finish;
        Assignment1_V5_DW.is_finally_SENSE = Assig_finally_IN_Sense_Finish_o;
      } else {
        switch (Assignment1_V5_DW.is_PACE) {
         case Assignment1_V5_IN_Charge:
          Assignment1_V5_B.PACE_GND_CTRL = true;
          if (Assignment1_V5_B.PACE_CHAMBER == Atrium) {
            Assignment1_V5_B.ATR_GND_CTRL = true;
            Assignment1_V5_B.VENT_GND_CTRL = false;
          } else {
            Assignment1_V5_B.ATR_GND_CTRL = false;
            Assignment1_V5_B.VENT_GND_CTRL = true;
          }

          Assignment1_V5_B.ATR_PACE_CTRL = false;
          Assignment1_V5_B.VENT_PACE_CTRL = false;
          Assignment1_V5_B.PACING_REF_PWM = Assignment1_V5_B.Gain2[(int32_T)
            Assignment1_V5_B.PACE_CHAMBER - 1];
          Assignment1_V5_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment1_V_IN_Discharge_Prep:
          switch (Assignment1_V5_B.PACE_CHAMBER) {
           case Atrium:
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Pace_Atr;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
            Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
              Assignment1_finally_IN_Pace_Atr;
            Assignment1_V5_DW.is_finally_PACE = Assignment1_finally_IN_Pace_Atr;
            Assignment1_V5_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Pace_Vent;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
            Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
              Assignment_finally_IN_Pace_Vent;
            Assignment1_V5_DW.is_finally_PACE = Assignment_finally_IN_Pace_Vent;
            Assignment1_V5_B.VENT_PACE_CTRL = true;
            break;

           default:
            Assignment1_V5_B.PACING_REF_PWM = 0.0;
            Assignment1_V5_B.PACE_CHARGE_CTRL = false;
            Assignment1_V5_B.PACE_GND_CTRL = true;
            Assignment1_V5_B.ATR_GND_CTRL = false;
            Assignment1_V5_B.VENT_GND_CTRL = false;
            break;
          }
          break;

         case Assignment1_V5_IN_Pace_Atr:
          if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V5_B.VectorConcatenate1[(int32_T)
               Assignment1_V5_B.PACE_CHAMBER - 1])) {
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Charge;
            Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
              Assignment1_V_finally_IN_Charge;
            Assignment1_V5_DW.is_finally_PACE = Assignment1_V_finally_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V5_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V5_IN_Pace_Vent:
          if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V5_B.VectorConcatenate1[(int32_T)
               Assignment1_V5_B.PACE_CHAMBER - 1])) {
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Charge;
            Assignment1_V5_DW.is_finally_c3_Assignment1_V5 =
              Assignment1_V_finally_IN_Charge;
            Assignment1_V5_DW.is_finally_PACE = Assignment1_V_finally_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V5_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment1_V5_IN_SENSE:
      Assignment1_V5_SENSE();
      break;
    }
  }

  /* End of Chart: '<Root>/PACE_SYSTEM' */
}

static void Assignment1_V5_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void Assignment1_V5_step(void)
{
  real_T PACE_CHAMBER_tmp;
  real_T PACE_SENSE_CHAMBER_tmp;
  int32_T i;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T Rx_buf;

  /* Constant: '<Root>/Constant2' */
  Assignment1_V5_B.Constant2 = Assignment1_V5_P.Constant2_Value;

  /* Chart: '<Root>/Chart' */
  if (Assignment1_V5_DW.temporalCounter_i1_f < 31U) {
    Assignment1_V5_DW.temporalCounter_i1_f++;
  }

  if (Assignment1_V5_DW.is_active_c7_Assignment1_V5 == 0U) {
    Assignment1_V5_DW.is_active_c7_Assignment1_V5 = 1U;
    Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1_V5_IN_Init;
    Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
      Assignment1_V5_finally_IN_Init;
  } else {
    switch (Assignment1_V5_DW.is_c7_Assignment1_V5) {
     case Assignment1_V5_IN_Conv_Data:
      break;

     case Assignment1__IN_Detect_Cur_Mode:
      if ((Assignment1_V5_DW.Op_Mode != 255) && (Assignment1_V5_DW.Op_Mode !=
           254)) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V5_DW.temporalCounter_i1_f = 0U;
        Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
          finally_IN_ECG_TX_Loop_Standby;
      } else if (Assignment1_V5_DW.Op_Mode == 255) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1__IN_Save_Buf_Params;
        Assignment1_V5_DW.temporalCounter_i1_f = 0U;
        Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
          Assi_finally_IN_Save_Buf_Params;
      } else {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1_V5_IN_Conv_Data;
        Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
          Assignment_finally_IN_Conv_Data;
        Assignment1_V5_Process_Rx(Assignment1_V5_DW.Output_Candidate);
      }
      break;

     case Assignme_IN_ECG_TX_Loop_Standby:
      if (Assignment1_V5_DW.temporalCounter_i1_f >= 10U) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V5_DW.temporalCounter_i1_f = 0U;
        Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
          finally_IN_ECG_TX_Loop_Standby;
      } else {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1__IN_Detect_Cur_Mode;
        Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
          Assi_finally_IN_Detect_Cur_Mode;
        Rx_buf = 0U;
        memcpy((void *)&Assignment1_V5_DW.Op_Mode, (void *)&Rx_buf, (size_t)1 *
               sizeof(uint8_T));
      }
      break;

     case Assignment1_V5_IN_Init:
      Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
      Assignment1_V5_DW.temporalCounter_i1_f = 0U;
      Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
        finally_IN_ECG_TX_Loop_Standby;
      break;

     default:
      /* case IN_Save_Buf_Params: */
      if (Assignment1_V5_DW.temporalCounter_i1_f >= 20U) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V5_DW.temporalCounter_i1_f = 0U;
        Assignment1_V5_DW.is_finally_c7_Assignment1_V5 =
          finally_IN_ECG_TX_Loop_Standby;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Constant: '<S7>/Constant10' */
  Assignment1_V5_B.VectorConcatenate1_m[0] = Assignment1_V5_P.Constant10_Value;

  /* Constant: '<S7>/Constant' */
  Assignment1_V5_B.VectorConcatenate1_m[1] = Assignment1_V5_P.Constant_Value;

  /* Constant: '<S7>/Constant5' */
  Assignment1_V5_B.VectorConcatenate1_m[2] = Assignment1_V5_P.Constant5_Value;

  /* Constant: '<S7>/Constant9' */
  Assignment1_V5_B.VectorConcatenate1_m[3] = Assignment1_V5_P.Constant9_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  Assignment1_V5_B.VectorConcatenate1_m[4] = Assignment1_V5_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  Assignment1_V5_B.VectorConcatenate1_m[5] = Assignment1_V5_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  Assignment1_V5_B.VectorConcatenate1_m[6] = Assignment1_V5_P.Constant2_Value_l;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  Assignment1_V5_B.VectorConcatenate1_m[7] = Assignment1_V5_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  Assignment1_V5_B.VectorConcatenate1_m[8] = Assignment1_V5_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  Assignment1_V5_B.VectorConcatenate1_m[9] = Assignment1_V5_P.Constant2_Value_l;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  Assignment1_V5_B.VectorConcatenate1_m[10] = Assignment1_V5_P.Constant4_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  Assignment1_V5_B.VectorConcatenate1_m[11] = Assignment1_V5_P.Constant4_Value;

  /* Constant: '<S7>/Constant6' */
  Assignment1_V5_B.VectorConcatenate1_m[12] = Assignment1_V5_P.Constant6_Value;

  /* Constant: '<S7>/Constant7' */
  Assignment1_V5_B.VectorConcatenate1_m[13] = Assignment1_V5_P.Constant7_Value;

  /* Constant: '<S7>/Constant8' */
  Assignment1_V5_B.VectorConcatenate1_m[14] = Assignment1_V5_P.Constant8_Value;

  /* Gain: '<Root>/Gain' */
  for (i = 0; i < 15; i++) {
    Assignment1_V5_B.VectorConcatenate1_m[i] *= Assignment1_V5_P.Gain_Gain;
  }

  /* End of Gain: '<Root>/Gain' */

  /* Gain: '<S18>/Gain16' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V5_B.Gain2[0] = Assignment1_V5_P.Gain16_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[4];

  /* Gain: '<S18>/Gain15' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V5_B.Gain2[1] = Assignment1_V5_P.Gain15_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[7];

  /* Gain: '<S18>/Gain9' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate2'
   */
  Assignment1_V5_B.VectorConcatenate2[0] = Assignment1_V5_P.Gain9_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[10];

  /* Gain: '<S18>/Gain10' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate2'
   */
  Assignment1_V5_B.VectorConcatenate2[1] = Assignment1_V5_P.Gain10_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[11];

  /* Gain: '<S18>/Gain7' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate1'
   */
  Assignment1_V5_B.VectorConcatenate1[0] = Assignment1_V5_P.Gain7_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[5];

  /* Gain: '<S18>/Gain8' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate1'
   */
  Assignment1_V5_B.VectorConcatenate1[1] = Assignment1_V5_P.Gain8_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[8];

  /* MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */
  if (Assignment1_V5_DW.obj.SampleTime !=
      Assignment1_V5_P.FXOS87006AxesSensor_SampleTime) {
    Assignment1_V5_DW.obj.SampleTime =
      Assignment1_V5_P.FXOS87006AxesSensor_SampleTime;
  }

  Rx_buf = 1U;
  Rx_buf = MW_I2C_MasterWrite(Assignment1_V5_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
    &Rx_buf, 1U, true, false);
  if (Rx_buf == 0) {
    MW_I2C_MasterRead(Assignment1_V5_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
                      &output_raw[0], 6U, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)3 *
           sizeof(int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[0], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[0], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[1], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[1], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[2], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[2], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  Assignment1_V5_B.FXOS87006AxesSensor[0] = (real_T)(int16_T)(b_RegisterValue[0]
    >> 2) * 2.0 * 0.244 / 1000.0;

  /* Constant: '<S6>/Constant' */
  Assignment1_V5_B.Constant[0] = Assignment1_V5_P.Constant_Value_n[0];

  /* MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */
  Assignment1_V5_B.FXOS87006AxesSensor[1] = (real_T)(int16_T)(b_RegisterValue[1]
    >> 2) * 2.0 * 0.244 / 1000.0;

  /* Constant: '<S6>/Constant' */
  Assignment1_V5_B.Constant[1] = Assignment1_V5_P.Constant_Value_n[1];

  /* MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */
  Assignment1_V5_B.FXOS87006AxesSensor[2] = (real_T)(int16_T)(b_RegisterValue[2]
    >> 2) * 2.0 * 0.244 / 1000.0;

  /* Constant: '<S6>/Constant' */
  Assignment1_V5_B.Constant[2] = Assignment1_V5_P.Constant_Value_n[2];

  /* Gain: '<S18>/Gain2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V5_B.Gain2[0] *= Assignment1_V5_P.Gain2_Gain;
  Assignment1_V5_B.Gain2[1] *= Assignment1_V5_P.Gain2_Gain;

  /* MATLABSystem: '<S4>/Digital Read1' */
  if (Assignment1_V5_DW.obj_o.SampleTime !=
      Assignment1_V5_P.DigitalRead1_SampleTime) {
    Assignment1_V5_DW.obj_o.SampleTime =
      Assignment1_V5_P.DigitalRead1_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S4>/Cast To Boolean'
   *  MATLABSystem: '<S4>/Digital Read1'
   */
  Assignment1_V5_B.VectorConcatenate[0] = MW_digitalIO_read
    (Assignment1_V5_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S4>/Digital Read' */
  if (Assignment1_V5_DW.obj_b.SampleTime !=
      Assignment1_V5_P.DigitalRead_SampleTime) {
    Assignment1_V5_DW.obj_b.SampleTime = Assignment1_V5_P.DigitalRead_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S4>/Cast To Boolean1'
   *  MATLABSystem: '<S4>/Digital Read'
   */
  Assignment1_V5_B.VectorConcatenate[1] = MW_digitalIO_read
    (Assignment1_V5_DW.obj_b.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<S18>/MATLAB Function' */
  PACE_CHAMBER_tmp = Assignment1_V5_mod(Assignment1_V5_B.VectorConcatenate1_m[0],
    1000.0);
  Assignment1_V5_B.PACE_CHAMBER = As_convert_to_enum_Pace_Chamber((int32_T)
    rt_roundd_snf((Assignment1_V5_mod(Assignment1_V5_B.VectorConcatenate1_m[0],
    10000.0) - PACE_CHAMBER_tmp) / 1000.0));
  PACE_SENSE_CHAMBER_tmp = Assignment1_V5_mod
    (Assignment1_V5_B.VectorConcatenate1_m[0], 100.0);
  Assignment1_V5_B.PACE_SENSE_CHAMBER = convert_to_enum_Pace_Sense_Cham((int32_T)
    rt_roundd_snf((PACE_CHAMBER_tmp - PACE_SENSE_CHAMBER_tmp) / 100.0));
  PACE_CHAMBER_tmp = Assignment1_V5_mod(Assignment1_V5_B.VectorConcatenate1_m[0],
    10.0);
  Assignment1_V5_B.PACE_SENSE_RESPONSE = convert_to_enum_Pace_Sense_Resp
    ((int32_T)rt_roundd_snf((PACE_SENSE_CHAMBER_tmp - PACE_CHAMBER_tmp) / 10.0));
  Assignment1_V5_B.PACE_RATE_MODE = convert_to_enum_Pace_Rate_Mode((int32_T)
    rt_roundd_snf(PACE_CHAMBER_tmp - Assignment1_V5_mod
                  (Assignment1_V5_B.VectorConcatenate1_m[0], 1.0)));

  /* MATLAB Function: '<S13>/MATLAB Function2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor'
   */
  if (Assignment1_V5_DW.init_counter < Assignment1_V5_P.Constant1_Value_n) {
    Assignment1_V5_DW.init_counter++;
  }

  Assignment1_V5_DW.rolling_avg = sqrt((Assignment1_V5_B.FXOS87006AxesSensor[0] *
    Assignment1_V5_B.FXOS87006AxesSensor[0] +
    Assignment1_V5_B.FXOS87006AxesSensor[1] *
    Assignment1_V5_B.FXOS87006AxesSensor[1]) +
    Assignment1_V5_B.FXOS87006AxesSensor[2] *
    Assignment1_V5_B.FXOS87006AxesSensor[2]) / Assignment1_V5_DW.init_counter +
    (Assignment1_V5_DW.init_counter - 1.0) * Assignment1_V5_DW.rolling_avg /
    Assignment1_V5_DW.init_counter;
  Assignment1_V5_B.smoothed_output = Assignment1_V5_DW.rolling_avg;

  /* End of MATLAB Function: '<S13>/MATLAB Function2' */

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  Assignment1_V5_B.Motion_State = 3.0;
  if (Assignment1_V5_P.Constant2_Value_i[1] > Assignment1_V5_B.smoothed_output)
  {
    Assignment1_V5_B.Motion_State = 2.0;
  }

  if (Assignment1_V5_P.Constant2_Value_i[0] > Assignment1_V5_B.smoothed_output)
  {
    Assignment1_V5_B.Motion_State = 1.0;
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function' */

  /* Gain: '<S15>/Gain' */
  Assignment1_V5_B.Gain = Assignment1_V5_P.Gain_Gain_k *
    Assignment1_V5_B.smoothed_output;

  /* Gain: '<S18>/Multiply2' incorporates:
   *  Gain: '<S18>/Gain17'
   *  Product: '<S18>/Reciprocal2'
   */
  Assignment1_V5_B.Multiply2 = 1.0 / (Assignment1_V5_P.Gain17_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[3]) * Assignment1_V5_P.Multiply2_Gain;

  /* Gain: '<S18>/Gain11' */
  Assignment1_V5_B.Gain11 = Assignment1_V5_P.Gain11_Gain * 0.0;

  /* Gain: '<S18>/Gain13' */
  Assignment1_V5_B.Gain13 = Assignment1_V5_P.Gain13_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[13];

  /* Gain: '<S18>/Gain4' incorporates:
   *  Gain: '<S18>/Gain12'
   */
  Assignment1_V5_B.Gain4 = Assignment1_V5_P.Gain12_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[12] * Assignment1_V5_P.Gain4_Gain;

  /* Gain: '<S18>/Gain5' incorporates:
   *  Gain: '<S18>/Gain14'
   */
  Assignment1_V5_B.Gain5 = Assignment1_V5_P.Gain14_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[14] * Assignment1_V5_P.Gain5_Gain;

  /* Gain: '<S18>/Multiply' incorporates:
   *  Gain: '<S18>/Gain19'
   *  Product: '<S18>/Reciprocal'
   */
  Assignment1_V5_B.Multiply = 1.0 / (Assignment1_V5_P.Gain19_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[1]) * Assignment1_V5_P.Multiply_Gain;

  /* Chart: '<S6>/RATE_CTRL_SYSTEM' */
  if (Assignment1_V5_DW.temporalCounter_i1_n < 1U) {
    Assignment1_V5_DW.temporalCounter_i1_n = 1U;
  }

  if (Assignment1_V5_DW.is_active_c9_Assignment1_V5 == 0U) {
    Assignment1_V5_DW.is_active_c9_Assignment1_V5 = 1U;
    Assignment1_V5_DW.is_c9_Assignment1_V5 = Assignment1_V5_IN_Init_e;
    Assignment1_V5_B.sense_timeout_threshold = Assignment1_V5_B.Multiply;
  } else {
    switch (Assignment1_V5_DW.is_c9_Assignment1_V5) {
     case Assignment1_V5_IN_Detect_Mode:
      if (Assignment1_V5_B.PACE_RATE_MODE == Disabled) {
        Assignment1_V5_DW.is_c9_Assignment1_V5 = Assignment1_V_IN_Pace_LRL_Fixed;
        Assignment1_V5_B.sense_timeout_threshold = Assignment1_V5_B.Multiply;
      } else {
        Assignment1_V5_DW.is_c9_Assignment1_V5 = Assignment_IN_Pace_Rate_Unfixed;
        Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V_IN_Pace_Rate_Init;
        Assignment1_V5_B.FXOS87006AxesSensor[0] = Assignment1_V5_B.Constant[0] /
          Assignment1_V5_B.Gain13;
        Assignment1_V5_B.FXOS87006AxesSensor[1] = Assignment1_V5_B.Constant[1] /
          Assignment1_V5_B.Gain13;
        Assignment1_V5_B.FXOS87006AxesSensor[2] = Assignment1_V5_B.Constant[2] /
          Assignment1_V5_B.Gain13;
        Assignmen_Calc_Expo_Rate_Factor(Assignment1_V5_B.Gain4,
          Assignment1_V5_B.FXOS87006AxesSensor, Assignment1_V5_DW.resp_fac_grow);
        Assignmen_Calc_Expo_Rate_Factor(Assignment1_V5_B.Gain5,
          Assignment1_V5_B.FXOS87006AxesSensor, Assignment1_V5_DW.resp_fac_decay);
      }
      break;

     case Assignment1_V5_IN_Init_e:
      Assignment1_V5_DW.is_c9_Assignment1_V5 = Assignment1_V5_IN_Detect_Mode;
      break;

     case Assignment1_V_IN_Pace_LRL_Fixed:
      if (Assignment1_V5_B.PACE_RATE_MODE == Enabled) {
        Assignment1_V5_DW.is_c9_Assignment1_V5 = Assignment1_V5_IN_Detect_Mode;
      } else {
        Assignment1_V5_B.sense_timeout_threshold = Assignment1_V5_B.Multiply;
      }
      break;

     default:
      /* case IN_Pace_Rate_Unfixed: */
      switch (Assignment1_V5_DW.is_Pace_Rate_Unfixed) {
       case Assignment1_V5_IN_Bigger:
        Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V5_IN_get_tgt;
        Assignment1_V5_B.dv[0] = 2.6;
        Assignment1_V5_B.dv[1] = -40.0;
        Assignment1_V5_B.tgt = Assignment1__Calc_Rate_Response
          (Assignment1_V5_B.Gain, Assignment1_V5_B.Multiply,
           Assignment1_V5_B.Multiply2);
        break;

       case Assignment1_V_IN_Pace_Rate_Init:
        Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V5_IN_get_tgt;
        Assignment1_V5_B.dv[0] = 2.6;
        Assignment1_V5_B.dv[1] = -40.0;
        Assignment1_V5_B.tgt = Assignment1__Calc_Rate_Response
          (Assignment1_V5_B.Gain, Assignment1_V5_B.Multiply,
           Assignment1_V5_B.Multiply2);
        break;

       case Assignment1_V5_IN_Smaller:
        Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V5_IN_get_tgt;
        Assignment1_V5_B.dv[0] = 2.6;
        Assignment1_V5_B.dv[1] = -40.0;
        Assignment1_V5_B.tgt = Assignment1__Calc_Rate_Response
          (Assignment1_V5_B.Gain, Assignment1_V5_B.Multiply,
           Assignment1_V5_B.Multiply2);
        break;

       case Assignment1_V5_IN_check_dif:
        if (Assignment1_V5_DW.dif >= 0.0) {
          Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V5_IN_Bigger;
          Assignment1_V5_DW.temporalCounter_i1_n = 0U;
          Assignment1_V5_B.sense_timeout_threshold +=
            Assignment1_V5_DW.resp_fac_grow[(int32_T)
            Assignment1_V5_B.Motion_State - 1] * Assignment1_V5_DW.dif;
        } else if (Assignment1_V5_DW.dif <= 0.0) {
          Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V5_IN_Smaller;
          Assignment1_V5_DW.temporalCounter_i1_n = 0U;
          Assignment1_V5_B.sense_timeout_threshold +=
            Assignment1_V5_DW.resp_fac_decay[(int32_T)
            Assignment1_V5_B.Motion_State - 1] * Assignment1_V5_DW.dif;
        } else {
          Assignment1_V5_DW.dif = Assignment1_V5_B.tgt -
            Assignment1_V5_B.sense_timeout_threshold;
        }
        break;

       default:
        /* case IN_get_tgt: */
        if (Assignment1_V5_B.PACE_RATE_MODE != Disabled) {
          Assignment1_V5_DW.is_Pace_Rate_Unfixed = Assignment1_V5_IN_check_dif;
          Assignment1_V5_DW.dif = Assignment1_V5_B.tgt -
            Assignment1_V5_B.sense_timeout_threshold;
        } else {
          Assignment1_V5_DW.is_Pace_Rate_Unfixed =
            Assignment1__IN_NO_ACTIVE_CHILD;
          Assignment1_V5_DW.is_c9_Assignment1_V5 = Assignment1_V5_IN_Detect_Mode;
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/RATE_CTRL_SYSTEM' */

  /* Gain: '<S18>/Multiply1' incorporates:
   *  Gain: '<S18>/Gain18'
   *  Product: '<S18>/Reciprocal1'
   */
  Assignment1_V5_B.Multiply1 = 1.0 / (Assignment1_V5_P.Gain18_Gain *
    Assignment1_V5_B.VectorConcatenate1_m[2]) * Assignment1_V5_P.Multiply1_Gain;

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V5_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V5_DW.temporalCounter_i1++;
  }

  Assignment1_V5_DW.sfEvent_m = Assignment1_V5_CALL_EVENT;
  Assignment1_V_c3_Assignment1_V5();

  /* End of Chart: '<Root>/PACE_SYSTEM' */

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_ev.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.red != 0.0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.green != 0.0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_bs.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.blue != 0.0);

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_ej.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S3>/Digital Write1' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_o1.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_V5_DW.obj_evb.MW_PWM_HANDLE,
                      Assignment1_V5_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S3>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_lo.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S3>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_ng.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_B.VENT_GND_CTRL);

  /* ToAsyncQueueBlock generated from: '<Root>/RATE_SYSTEM' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.sense_timeout_threshold;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(1263151504U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S14>/MATLAB Function' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.Motion_State;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(487224253U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S13>/MATLAB Function2' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.smoothed_output;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(4226403473U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S4>/PWM Output1' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Gain: '<S18>/Gain6'
   */
  MW_PWM_SetDutyCycle(Assignment1_V5_DW.obj_j.MW_PWM_HANDLE,
                      Assignment1_V5_P.Gain1_Gain * (Assignment1_V5_P.Gain6_Gain
    * Assignment1_V5_B.VectorConcatenate1_m[9]));

  /* MATLABSystem: '<S4>/PWM Output' incorporates:
   *  Gain: '<S18>/Gain'
   *  Gain: '<S18>/Gain3'
   */
  MW_PWM_SetDutyCycle(Assignment1_V5_DW.obj_nl.MW_PWM_HANDLE,
                      Assignment1_V5_P.Gain_Gain_k2 *
                      (Assignment1_V5_P.Gain3_Gain *
                       Assignment1_V5_B.VectorConcatenate1_m[6]));

  /* MATLABSystem: '<S4>/Analog Input1' */
  if (Assignment1_V5_DW.obj_i.SampleTime !=
      Assignment1_V5_P.AnalogInput1_SampleTime) {
    Assignment1_V5_DW.obj_i.SampleTime =
      Assignment1_V5_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S4>/Analog Input1' */
  MW_AnalogInSingle_ReadResult(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE,
    &Assignment1_V5_B.AnalogInput1, 7);

  /* ToAsyncQueueBlock generated from: '<S4>/Analog Input1' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.AnalogInput1;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(527975674U, time, pData, size);
    }
  }

  /* Gain: '<S4>/Gain3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain1'
   *  Sum: '<S4>/Subtract1'
   */
  PACE_SENSE_CHAMBER_tmp = (Assignment1_V5_B.AnalogInput1 -
    Assignment1_V5_P.Constant1_Value_b) * Assignment1_V5_P.Gain1_Gain_b *
    Assignment1_V5_P.Gain3_Gain_c;

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  PACE_CHAMBER_tmp = fabs(PACE_SENSE_CHAMBER_tmp);
  if (PACE_CHAMBER_tmp < 4.503599627370496E+15) {
    if (PACE_CHAMBER_tmp >= 0.5) {
      PACE_SENSE_CHAMBER_tmp = floor(PACE_SENSE_CHAMBER_tmp + 0.5);
    } else {
      PACE_SENSE_CHAMBER_tmp *= 0.0;
    }
  }

  if (rtIsNaN(PACE_SENSE_CHAMBER_tmp) || rtIsInf(PACE_SENSE_CHAMBER_tmp)) {
    PACE_SENSE_CHAMBER_tmp = 0.0;
  } else {
    PACE_SENSE_CHAMBER_tmp = fmod(PACE_SENSE_CHAMBER_tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  Assignment1_V5_B.DataTypeConversion1 = (int16_T)(PACE_SENSE_CHAMBER_tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-PACE_SENSE_CHAMBER_tmp : (int32_T)
    (int16_T)(uint16_T)PACE_SENSE_CHAMBER_tmp);

  /* ToAsyncQueueBlock generated from: '<S4>/Data Type Conversion1' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.DataTypeConversion1;
      int32_T size = 1*sizeof(int16_T);
      sendToAsyncQueueTgtAppSvc(3116225584U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S4>/Analog Input' */
  if (Assignment1_V5_DW.obj_n.SampleTime !=
      Assignment1_V5_P.AnalogInput_SampleTime) {
    Assignment1_V5_DW.obj_n.SampleTime = Assignment1_V5_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S4>/Analog Input' */
  MW_AnalogInSingle_ReadResult(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE,
    &Assignment1_V5_B.AnalogInput, 7);

  /* Gain: '<S4>/Gain2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S4>/Subtract'
   */
  PACE_SENSE_CHAMBER_tmp = (Assignment1_V5_B.AnalogInput -
    Assignment1_V5_P.Constant1_Value_b) * Assignment1_V5_P.Gain_Gain_e *
    Assignment1_V5_P.Gain2_Gain_e;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  PACE_CHAMBER_tmp = fabs(PACE_SENSE_CHAMBER_tmp);
  if (PACE_CHAMBER_tmp < 4.503599627370496E+15) {
    if (PACE_CHAMBER_tmp >= 0.5) {
      PACE_SENSE_CHAMBER_tmp = floor(PACE_SENSE_CHAMBER_tmp + 0.5);
    } else {
      PACE_SENSE_CHAMBER_tmp *= 0.0;
    }
  }

  if (rtIsNaN(PACE_SENSE_CHAMBER_tmp) || rtIsInf(PACE_SENSE_CHAMBER_tmp)) {
    PACE_SENSE_CHAMBER_tmp = 0.0;
  } else {
    PACE_SENSE_CHAMBER_tmp = fmod(PACE_SENSE_CHAMBER_tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  Assignment1_V5_B.DataTypeConversion = (int16_T)(PACE_SENSE_CHAMBER_tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-PACE_SENSE_CHAMBER_tmp : (int32_T)
    (int16_T)(uint16_T)PACE_SENSE_CHAMBER_tmp);

  /* ToAsyncQueueBlock generated from: '<S4>/Data Type Conversion' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.DataTypeConversion;
      int32_T size = 1*sizeof(int16_T);
      sendToAsyncQueueTgtAppSvc(691823134U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S4>/Analog Input' */
  {
    {
      double time = Assignment1_V5_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V5_B.AnalogInput;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(67755194U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S4>/Digital Write1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  MW_digitalIO_write(Assignment1_V5_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_P.Constant_Value_k != 0.0);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_l.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_e.MW_DIGITALIO_HANDLE, false);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Assignment1_V5_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Assignment1_V5_M)!=-1) &&
        !((rtmGetTFinal(Assignment1_V5_M)-Assignment1_V5_M->Timing.taskTime0) >
          Assignment1_V5_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Assignment1_V5_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Assignment1_V5_M)) {
      rtmSetErrorStatus(Assignment1_V5_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Assignment1_V5_M->Timing.taskTime0 =
    ((time_T)(++Assignment1_V5_M->Timing.clockTick0)) *
    Assignment1_V5_M->Timing.stepSize0;
}

/* Model initialize function */
void Assignment1_V5_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Assignment1_V5_M, 15.0);
  Assignment1_V5_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Assignment1_V5_M->Sizes.checksums[0] = (1114394090U);
  Assignment1_V5_M->Sizes.checksums[1] = (2135641803U);
  Assignment1_V5_M->Sizes.checksums[2] = (4067916122U);
  Assignment1_V5_M->Sizes.checksums[3] = (2726320791U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[28];
    Assignment1_V5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Assignment1_V5_M->extModeInfo,
      &Assignment1_V5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Assignment1_V5_M->extModeInfo,
                        Assignment1_V5_M->Sizes.checksums);
    rteiSetTPtr(Assignment1_V5_M->extModeInfo, rtmGetTPtr(Assignment1_V5_M));
  }

  /* block I/O */
  {
    Assignment1_V5_B.PACE_CHAMBER = Atrium;
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Assignment1_V5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 28;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    freedomk64f_AnalogInput_Assig_T *obj_2;
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* Start for Constant: '<Root>/Constant2' */
    Assignment1_V5_B.Constant2 = Assignment1_V5_P.Constant2_Value;

    /* Start for Constant: '<S6>/Constant' */
    Assignment1_V5_B.Constant[0] = Assignment1_V5_P.Constant_Value_n[0];
    Assignment1_V5_B.Constant[1] = Assignment1_V5_P.Constant_Value_n[1];
    Assignment1_V5_B.Constant[2] = Assignment1_V5_P.Constant_Value_n[2];

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment1_V5_DW.sfEvent_m = Assignment1_V5_CALL_EVENT;

    /* Start for MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */
    Assignment1_V5_DW.obj.isInitialized = 0;
    Assignment1_V5_DW.obj.i2cobj.isInitialized = 0;
    Assignment1_V5_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    Assignment1_V5_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_V5_DW.obj.SampleTime =
      Assignment1_V5_P.FXOS87006AxesSensor_SampleTime;
    Assignment1_V5_SystemCore_setup(&Assignment1_V5_DW.obj);

    /* Start for MATLABSystem: '<S4>/Digital Read1' */
    Assignment1_V5_DW.obj_o.matlabCodegenIsDeleted = false;
    Assignment1_V5_DW.obj_o.SampleTime =
      Assignment1_V5_P.DigitalRead1_SampleTime;
    obj = &Assignment1_V5_DW.obj_o;
    Assignment1_V5_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_V5_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Read' */
    Assignment1_V5_DW.obj_b.matlabCodegenIsDeleted = false;
    Assignment1_V5_DW.obj_b.SampleTime = Assignment1_V5_P.DigitalRead_SampleTime;
    obj = &Assignment1_V5_DW.obj_b;
    Assignment1_V5_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_V5_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    Assignment1_V5_DW.obj_ev.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_ev;
    Assignment1_V5_DW.obj_ev.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1_V5_DW.obj_ev.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    Assignment1_V5_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_d;
    Assignment1_V5_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Assignment1_V5_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    Assignment1_V5_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_bs;
    Assignment1_V5_DW.obj_bs.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment1_V5_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Assignment1_V5_DW.obj_ej.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_ej;
    Assignment1_V5_DW.obj_ej.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_V5_DW.obj_ej.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    Assignment1_V5_DW.obj_o1.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_o1;
    Assignment1_V5_DW.obj_o1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_V5_DW.obj_o1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    Assignment1_V5_DW.obj_evb.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V5_DW.obj_evb;
    Assignment1_V5_DW.obj_evb.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V5_DW.obj_evb.MW_PWM_HANDLE);
    Assignment1_V5_DW.obj_evb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write3' */
    Assignment1_V5_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_a;
    Assignment1_V5_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_V5_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write4' */
    Assignment1_V5_DW.obj_lo.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_lo;
    Assignment1_V5_DW.obj_lo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_V5_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write5' */
    Assignment1_V5_DW.obj_ng.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_ng;
    Assignment1_V5_DW.obj_ng.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_V5_DW.obj_ng.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    Assignment1_V5_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_f;
    Assignment1_V5_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_V5_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    Assignment1_V5_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V5_DW.obj_j;
    Assignment1_V5_DW.obj_j.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V5_DW.obj_j.MW_PWM_HANDLE);
    Assignment1_V5_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Assignment1_V5_DW.obj_nl.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V5_DW.obj_nl;
    Assignment1_V5_DW.obj_nl.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V5_DW.obj_nl.MW_PWM_HANDLE);
    Assignment1_V5_DW.obj_nl.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input1' */
    Assignment1_V5_DW.obj_i.matlabCodegenIsDeleted = false;
    Assignment1_V5_DW.obj_i.SampleTime =
      Assignment1_V5_P.AnalogInput1_SampleTime;
    obj_2 = &Assignment1_V5_DW.obj_i;
    Assignment1_V5_DW.obj_i.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_V5_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input' */
    Assignment1_V5_DW.obj_n.matlabCodegenIsDeleted = false;
    Assignment1_V5_DW.obj_n.SampleTime = Assignment1_V5_P.AnalogInput_SampleTime;
    obj_2 = &Assignment1_V5_DW.obj_n;
    Assignment1_V5_DW.obj_n.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_V5_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Assignment1_V5_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_p;
    Assignment1_V5_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_V5_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    Assignment1_V5_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_l;
    Assignment1_V5_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_V5_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    Assignment1_V5_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V5_DW.obj_e;
    Assignment1_V5_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_V5_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_V5_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */
  if (!Assignment1_V5_DW.obj.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj.isInitialized == 1) &&
        Assignment1_V5_DW.obj.isSetupComplete) {
      MW_I2C_Close(Assignment1_V5_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &Assignment1_V5_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S4>/Digital Read1' */
  if (!Assignment1_V5_DW.obj_o.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_o.isInitialized == 1) &&
        Assignment1_V5_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Read' */
  if (!Assignment1_V5_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_b.isInitialized == 1) &&
        Assignment1_V5_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!Assignment1_V5_DW.obj_ev.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_ev.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_ev.isInitialized == 1) &&
        Assignment1_V5_DW.obj_ev.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_ev.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!Assignment1_V5_DW.obj_d.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_d.isInitialized == 1) &&
        Assignment1_V5_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!Assignment1_V5_DW.obj_bs.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_bs.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_bs.isInitialized == 1) &&
        Assignment1_V5_DW.obj_bs.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_bs.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  if (!Assignment1_V5_DW.obj_ej.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_ej.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_ej.isInitialized == 1) &&
        Assignment1_V5_DW.obj_ej.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_ej.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  if (!Assignment1_V5_DW.obj_o1.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_o1.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_o1.isInitialized == 1) &&
        Assignment1_V5_DW.obj_o1.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_o1.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  if (!Assignment1_V5_DW.obj_evb.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_evb.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_evb.isInitialized == 1) &&
        Assignment1_V5_DW.obj_evb.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V5_DW.obj_evb.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V5_DW.obj_evb.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write3' */
  if (!Assignment1_V5_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_a.isInitialized == 1) &&
        Assignment1_V5_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  if (!Assignment1_V5_DW.obj_lo.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_lo.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_lo.isInitialized == 1) &&
        Assignment1_V5_DW.obj_lo.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_lo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write5' */
  if (!Assignment1_V5_DW.obj_ng.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_ng.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_ng.isInitialized == 1) &&
        Assignment1_V5_DW.obj_ng.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_ng.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  if (!Assignment1_V5_DW.obj_f.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_f.isInitialized == 1) &&
        Assignment1_V5_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write8' */
  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  if (!Assignment1_V5_DW.obj_j.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_j.isInitialized == 1) &&
        Assignment1_V5_DW.obj_j.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V5_DW.obj_j.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V5_DW.obj_j.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!Assignment1_V5_DW.obj_nl.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_nl.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_nl.isInitialized == 1) &&
        Assignment1_V5_DW.obj_nl.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V5_DW.obj_nl.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V5_DW.obj_nl.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/Analog Input1' */
  if (!Assignment1_V5_DW.obj_i.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_i.isInitialized == 1) &&
        Assignment1_V5_DW.obj_i.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input1' */
  /* Terminate for MATLABSystem: '<S4>/Analog Input' */
  if (!Assignment1_V5_DW.obj_n.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_n.isInitialized == 1) &&
        Assignment1_V5_DW.obj_n.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input' */
  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!Assignment1_V5_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_p.isInitialized == 1) &&
        Assignment1_V5_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  if (!Assignment1_V5_DW.obj_l.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_l.isInitialized == 1) &&
        Assignment1_V5_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  if (!Assignment1_V5_DW.obj_e.matlabCodegenIsDeleted) {
    Assignment1_V5_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Assignment1_V5_DW.obj_e.isInitialized == 1) &&
        Assignment1_V5_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V5_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

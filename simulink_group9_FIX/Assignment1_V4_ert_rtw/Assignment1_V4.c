/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V4.c
 *
 * Code generated for Simulink model 'Assignment1_V4'.
 *
 * Model version                  : 1.62
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Nov 28 04:00:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment1_V4.h"
#include "Assignment1_V4_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "Assignment1_V4_private.h"
#include <math.h>
#include <stddef.h>
#include "MW_I2C.h"
#include "rt_nonfinite.h"
#include "Assignment1_V4_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Assignment1_V4_IN_Init         (1U)
#define Assignment1_V4_finally_IN_Init (1U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Ass_finally_IN_Sense_Detected_e (2U)
#define Ass_finally_IN_Sense_Disabled_i (3U)
#define Assig_finally_IN_Discharge_Prep (2U)
#define Assig_finally_IN_Sense_Detect_m (1U)
#define Assig_finally_IN_Sense_Detected (6U)
#define Assig_finally_IN_Sense_Disabled (7U)
#define Assig_finally_IN_Sense_Finish_k (5U)
#define Assignm_finally_IN_Sense_Detect (5U)
#define Assignm_finally_IN_Sense_Fail_k (4U)
#define Assignm_finally_IN_Sense_Finish (9U)
#define Assignm_finally_IN_Sense_Wait_f (6U)
#define Assignmen_finally_IN_Sense_Fail (8U)
#define Assignmen_finally_IN_Sense_Wait (10U)
#define Assignment1_V4_IN_Charge       (1U)
#define Assignment1_V4_IN_PACE         (1U)
#define Assignment1_V4_IN_Pace_Atr     (3U)
#define Assignment1_V4_IN_Pace_Vent    (4U)
#define Assignment1_V4_IN_SENSE        (2U)
#define Assignment1_V4_IN_Sense_Detect (1U)
#define Assignment1_V4_IN_Sense_Fail   (4U)
#define Assignment1_V4_IN_Sense_Finish (5U)
#define Assignment1_V4_IN_Sense_Wait   (6U)
#define Assignment1_V4_event_pace_compl (0)
#define Assignment1_V_IN_Discharge_Prep (2U)
#define Assignment1_V_IN_Sense_Detected (2U)
#define Assignment1_V_IN_Sense_Disabled (3U)
#define Assignment1_V_finally_IN_Charge (1U)
#define Assignment1_event_sense_timeout (1)
#define Assignment1_finally_IN_Pace_Atr (3U)
#define Assignment_finally_IN_Pace_Vent (4U)

/* Named constants for Chart: '<S9>/RATE_CTRL_SYSTEM' */
#define Assignment1_V4_IN_Bigger       (1U)
#define Assignment1_V4_IN_Detect_Mode  (2U)
#define Assignment1_V4_IN_Init_a       (3U)
#define Assignment1_V4_IN_Smaller      (6U)
#define Assignment1_V4_IN_check_dif    (7U)
#define Assignment1_V4_IN_get_tgt      (8U)
#define Assignment1_V_IN_Pace_LRL_Fixed (4U)
#define Assignment1_V_IN_Pace_Rate_Init (5U)

/* Block signals (default storage) */
B_Assignment1_V4_T Assignment1_V4_B;

/* Block states (default storage) */
DW_Assignment1_V4_T Assignment1_V4_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V4_T Assignment1_V4_M_;
RT_MODEL_Assignment1_V4_T *const Assignment1_V4_M = &Assignment1_V4_M_;

/* Forward declaration for local functions */
static real_T Assignment1_V4_mod(real_T x, real_T y);
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
static void Assignment1_V4_SENSE(void);
static void Assignment1_V_c3_Assignment1_V4(void);
static void Assignment1_V4_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj);

/* Function for MATLAB Function: '<S17>/MATLAB Function' */
static real_T Assignment1_V4_mod(real_T x, real_T y)
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

/* Function for MATLAB Function: '<S17>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S17>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S17>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S17>/MATLAB Function' */
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

/* Function for Chart: '<S9>/RATE_CTRL_SYSTEM' */
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

/* Function for Chart: '<S9>/RATE_CTRL_SYSTEM' */
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
  b_previousEvent = Assignment1_V4_DW.sfEvent_a;
  Assignment1_V4_DW.sfEvent_a = Assignment1_V4_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V4();
  Assignment1_V4_DW.sfEvent_a = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_enter_atomic_Charge(void)
{
  Assignment1_V4_B.PACE_GND_CTRL = true;
  if (Assignment1_V4_B.PACE_CHAMBER == Atrium) {
    Assignment1_V4_B.ATR_GND_CTRL = true;
    Assignment1_V4_B.VENT_GND_CTRL = false;
  } else {
    Assignment1_V4_B.ATR_GND_CTRL = false;
    Assignment1_V4_B.VENT_GND_CTRL = true;
  }

  Assignment1_V4_B.ATR_PACE_CTRL = false;
  Assignment1_V4_B.VENT_PACE_CTRL = false;
  Assignment1_V4_B.PACING_REF_PWM = Assignment1_V4_B.Gain2[(int32_T)
    Assignment1_V4_B.PACE_CHAMBER - 1];
  Assignment1_V4_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V4_DW.sfEvent_a;
  Assignment1_V4_DW.sfEvent_a = Assignment1_event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V4();
  Assignment1_V4_DW.sfEvent_a = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  Assignment1_V4_B.red = 0.0;
  Assignment1_V4_B.green = 0.0;
  Assignment1_V4_B.blue = 0.0;
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V4_SENSE(void)
{
  boolean_T guard1 = false;
  if (Assignment1_V4_DW.sfEvent_a == Assignment1_event_sense_timeout) {
    Assignment1_V4_DW.tp_Sense_Detect = 0U;
    Assignment1_V4_DW.tp_Sense_Detected = 0U;
    Assignment1_V4_DW.tp_Sense_Fail = 0U;
    Assignment1_V4_DW.is_finally_SENSE = 0U;
    Assignment1_V4_DW.is_SENSE = Assignment1__IN_NO_ACTIVE_CHILD;
    Assignment1_V4_DW.is_c3_Assignment1_V4 = Assignment1_V4_IN_PACE;
    Assignment1_V4_DW.is_PACE = Assignment1_V_IN_Discharge_Prep;
    Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
      Assig_finally_IN_Discharge_Prep;
    Assignment1_V4_DW.is_finally_PACE = Assig_finally_IN_Discharge_Prep;
    Assignment1_V4_B.PACING_REF_PWM = 0.0;
    Assignment1_V4_B.PACE_CHARGE_CTRL = false;
    Assignment1_V4_B.PACE_GND_CTRL = true;
    Assignment1_V4_B.ATR_GND_CTRL = false;
    Assignment1_V4_B.VENT_GND_CTRL = false;
  } else {
    guard1 = false;
    switch (Assignment1_V4_DW.is_SENSE) {
     case Assignment1_V4_IN_Sense_Detect:
      if (Assignment1_V4_B.PACE_SENSE_RESPONSE == Nothing) {
        guard1 = true;
      } else if (Assignment1_V4_B.VectorConcatenate[(int32_T)
                 Assignment1_V4_B.PACE_SENSE_CHAMBER - 1]) {
        Assignment1_V4_DW.tp_Sense_Detect = 0U;
        Assignment1_V4_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
        Assignment1_V4_DW.tp_Sense_Detected = 1U;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assig_finally_IN_Sense_Detected;
        Assignment1_V4_DW.is_finally_SENSE = Ass_finally_IN_Sense_Detected_e;
        Assignment1_V4_B.red = 0.0;
        Assignment1_V4_B.green = 0.0;
        Assignment1_V4_B.blue = 0.0;
      } else if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
                 (Assignment1_V4_B.sense_timeout_threshold -
                  Assignment1_V4_B.VectorConcatenate2[(int32_T)
                  Assignment1_V4_B.PACE_SENSE_CHAMBER - 1])) {
        guard1 = true;
      } else {
        Assignment1_V4_B.red = 0.0;
        Assignment1_V4_B.green = 1.0;
        Assignment1_V4_B.blue = 0.0;
      }
      break;

     case Assignment1_V_IN_Sense_Detected:
      Assignment1_V4_DW.tp_Sense_Detected = 0U;
      Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Wait;
      Assignment1_V4_DW.temporalCounter_i1 = 0U;
      Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
        Assignmen_finally_IN_Sense_Wait;
      Assignment1_V4_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Wait_f;
      Assignment1_V4_B.red = 1.0;
      Assignment1_V4_B.green = 0.0;
      Assignment1_V4_B.blue = 0.0;
      break;

     case Assignment1_V_IN_Sense_Disabled:
      if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Assignment1_V4_B.sense_timeout_threshold)) {
        Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Fail;
        Assignment1_V4_DW.tp_Sense_Fail = 1U;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assignmen_finally_IN_Sense_Fail;
        Assignment1_V4_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_k;
        Assignm_enter_atomic_Sense_Fail();
      }
      break;

     case Assignment1_V4_IN_Sense_Fail:
      Assignment1_V4_B.red = 0.0;
      Assignment1_V4_B.green = 0.0;
      Assignment1_V4_B.blue = 0.0;
      broadcast_sense_timeout_c3_Assi();
      break;

     case Assignment1_V4_IN_Sense_Finish:
      if (Assignment1_V4_B.PACE_SENSE_RESPONSE != Nothing) {
        Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Wait;
        Assignment1_V4_DW.temporalCounter_i1 = 0U;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assignmen_finally_IN_Sense_Wait;
        Assignment1_V4_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Wait_f;
        Assignment1_V4_B.red = 1.0;
        Assignment1_V4_B.green = 0.0;
        Assignment1_V4_B.blue = 0.0;
      } else {
        Assignment1_V4_DW.is_SENSE = Assignment1_V_IN_Sense_Disabled;
        Assignment1_V4_DW.temporalCounter_i1 = 0U;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assig_finally_IN_Sense_Disabled;
        Assignment1_V4_DW.is_finally_SENSE = Ass_finally_IN_Sense_Disabled_i;
      }
      break;

     case Assignment1_V4_IN_Sense_Wait:
      if (Assignment1_V4_B.PACE_SENSE_RESPONSE == Nothing) {
        Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Fail;
        Assignment1_V4_DW.tp_Sense_Fail = 1U;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assignmen_finally_IN_Sense_Fail;
        Assignment1_V4_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_k;
        Assignm_enter_atomic_Sense_Fail();
      } else if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
                 (Assignment1_V4_B.VectorConcatenate2[(int32_T)
                  Assignment1_V4_B.PACE_SENSE_CHAMBER - 1])) {
        Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Detect;
        Assignment1_V4_DW.temporalCounter_i1 = 0U;
        Assignment1_V4_DW.tp_Sense_Detect = 1U;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assignm_finally_IN_Sense_Detect;
        Assignment1_V4_DW.is_finally_SENSE = Assig_finally_IN_Sense_Detect_m;
        Assignment1_V4_B.red = 0.0;
        Assignment1_V4_B.green = 1.0;
        Assignment1_V4_B.blue = 0.0;
      } else {
        Assignment1_V4_B.red = 1.0;
        Assignment1_V4_B.green = 0.0;
        Assignment1_V4_B.blue = 0.0;
      }
      break;
    }

    if (guard1) {
      Assignment1_V4_DW.tp_Sense_Detect = 0U;
      Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Fail;
      Assignment1_V4_DW.tp_Sense_Fail = 1U;
      Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
        Assignmen_finally_IN_Sense_Fail;
      Assignment1_V4_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_k;
      Assignm_enter_atomic_Sense_Fail();
    }
  }
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V_c3_Assignment1_V4(void)
{
  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V4_DW.is_active_c3_Assignment1_V4 == 0U) {
    Assignment1_V4_DW.is_active_c3_Assignment1_V4 = 1U;
    Assignment1_V4_DW.is_c3_Assignment1_V4 = Assignment1_V4_IN_SENSE;
    Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Finish;
    Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
      Assignm_finally_IN_Sense_Finish;
    Assignment1_V4_DW.is_finally_SENSE = Assig_finally_IN_Sense_Finish_k;
  } else {
    switch (Assignment1_V4_DW.is_c3_Assignment1_V4) {
     case Assignment1_V4_IN_PACE:
      if (Assignment1_V4_DW.sfEvent_a == Assignment1_V4_event_pace_compl) {
        Assignment1_V4_DW.is_finally_PACE = 0U;
        Assignment1_V4_DW.is_PACE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V4_DW.is_c3_Assignment1_V4 = Assignment1_V4_IN_SENSE;
        Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Finish;
        Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
          Assignm_finally_IN_Sense_Finish;
        Assignment1_V4_DW.is_finally_SENSE = Assig_finally_IN_Sense_Finish_k;
      } else {
        switch (Assignment1_V4_DW.is_PACE) {
         case Assignment1_V4_IN_Charge:
          Assignment1_V4_B.PACE_GND_CTRL = true;
          if (Assignment1_V4_B.PACE_CHAMBER == Atrium) {
            Assignment1_V4_B.ATR_GND_CTRL = true;
            Assignment1_V4_B.VENT_GND_CTRL = false;
          } else {
            Assignment1_V4_B.ATR_GND_CTRL = false;
            Assignment1_V4_B.VENT_GND_CTRL = true;
          }

          Assignment1_V4_B.ATR_PACE_CTRL = false;
          Assignment1_V4_B.VENT_PACE_CTRL = false;
          Assignment1_V4_B.PACING_REF_PWM = Assignment1_V4_B.Gain2[(int32_T)
            Assignment1_V4_B.PACE_CHAMBER - 1];
          Assignment1_V4_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment1_V_IN_Discharge_Prep:
          switch (Assignment1_V4_B.PACE_CHAMBER) {
           case Atrium:
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Pace_Atr;
            Assignment1_V4_DW.temporalCounter_i1 = 0U;
            Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
              Assignment1_finally_IN_Pace_Atr;
            Assignment1_V4_DW.is_finally_PACE = Assignment1_finally_IN_Pace_Atr;
            Assignment1_V4_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Pace_Vent;
            Assignment1_V4_DW.temporalCounter_i1 = 0U;
            Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
              Assignment_finally_IN_Pace_Vent;
            Assignment1_V4_DW.is_finally_PACE = Assignment_finally_IN_Pace_Vent;
            Assignment1_V4_B.VENT_PACE_CTRL = true;
            break;

           default:
            Assignment1_V4_B.PACING_REF_PWM = 0.0;
            Assignment1_V4_B.PACE_CHARGE_CTRL = false;
            Assignment1_V4_B.PACE_GND_CTRL = true;
            Assignment1_V4_B.ATR_GND_CTRL = false;
            Assignment1_V4_B.VENT_GND_CTRL = false;
            break;
          }
          break;

         case Assignment1_V4_IN_Pace_Atr:
          if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V4_B.VectorConcatenate1_a[(int32_T)
               Assignment1_V4_B.PACE_CHAMBER - 1])) {
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Charge;
            Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
              Assignment1_V_finally_IN_Charge;
            Assignment1_V4_DW.is_finally_PACE = Assignment1_V_finally_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V4_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V4_IN_Pace_Vent:
          if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V4_B.VectorConcatenate1_a[(int32_T)
               Assignment1_V4_B.PACE_CHAMBER - 1])) {
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Charge;
            Assignment1_V4_DW.is_finally_c3_Assignment1_V4 =
              Assignment1_V_finally_IN_Charge;
            Assignment1_V4_DW.is_finally_PACE = Assignment1_V_finally_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V4_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment1_V4_IN_SENSE:
      Assignment1_V4_SENSE();
      break;
    }
  }

  /* End of Chart: '<Root>/PACE_SYSTEM' */
}

static void Assignment1_V4_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj)
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
void Assignment1_V4_step(void)
{
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* Constant: '<S7>/Constant10' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[0] = Assignment1_V4_P.Constant10_Value;

  /* Constant: '<S7>/Constant' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[1] = Assignment1_V4_P.Constant_Value;

  /* Constant: '<S7>/Constant5' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[2] = Assignment1_V4_P.Constant5_Value;

  /* Constant: '<S7>/Constant9' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[3] = Assignment1_V4_P.Constant9_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant1'
   */
  Assignment1_V4_B.VectorConcatenate1[4] = Assignment1_V4_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant3'
   */
  Assignment1_V4_B.VectorConcatenate1[5] = Assignment1_V4_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant2'
   */
  Assignment1_V4_B.VectorConcatenate1[6] = Assignment1_V4_P.Constant2_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant1'
   */
  Assignment1_V4_B.VectorConcatenate1[7] = Assignment1_V4_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant3'
   */
  Assignment1_V4_B.VectorConcatenate1[8] = Assignment1_V4_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant2'
   */
  Assignment1_V4_B.VectorConcatenate1[9] = Assignment1_V4_P.Constant2_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant4'
   */
  Assignment1_V4_B.VectorConcatenate1[10] = Assignment1_V4_P.Constant4_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   *  Constant: '<S7>/Constant4'
   */
  Assignment1_V4_B.VectorConcatenate1[11] = Assignment1_V4_P.Constant4_Value;

  /* Constant: '<S7>/Constant6' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[12] = Assignment1_V4_P.Constant6_Value;

  /* Constant: '<S7>/Constant7' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[13] = Assignment1_V4_P.Constant7_Value;

  /* Constant: '<S7>/Constant8' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[14] = Assignment1_V4_P.Constant8_Value;

  /* Constant: '<Root>/Constant2' */
  Assignment1_V4_B.Constant2 = Assignment1_V4_P.Constant2_Value_i;

  /* Chart: '<Root>/Chart' */
  if (Assignment1_V4_DW.is_active_c7_Assignment1_V4 == 0U) {
    Assignment1_V4_DW.is_active_c7_Assignment1_V4 = 1U;
    Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1_V4_IN_Init;
    Assignment1_V4_DW.is_finally_c7_Assignment1_V4 =
      Assignment1_V4_finally_IN_Init;
    memcpy(&Assignment1_V4_B.Params_Arr[0],
           &Assignment1_V4_B.VectorConcatenate1[0], 15U * sizeof(real_T));
    memcpy(&Assignment1_V4_DW.Output_Candidate[0],
           &Assignment1_V4_B.VectorConcatenate1[0], 15U * sizeof(real_T));
  }

  /* End of Chart: '<Root>/Chart' */

  /* SignalConversion generated from: '<S17>/Vector Concatenate' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate'
   */
  Assignment1_V4_B.Gain2[0] = Assignment1_V4_B.Params_Arr[4];

  /* SignalConversion generated from: '<S17>/Vector Concatenate' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate'
   */
  Assignment1_V4_B.Gain2[1] = Assignment1_V4_B.Params_Arr[7];

  /* SignalConversion generated from: '<S17>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate2'
   */
  Assignment1_V4_B.VectorConcatenate2[0] = Assignment1_V4_B.Params_Arr[10];

  /* SignalConversion generated from: '<S17>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate2'
   */
  Assignment1_V4_B.VectorConcatenate2[1] = Assignment1_V4_B.Params_Arr[11];

  /* SignalConversion generated from: '<S17>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1_a[0] = Assignment1_V4_B.Params_Arr[5];

  /* SignalConversion generated from: '<S17>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1_a[1] = Assignment1_V4_B.Params_Arr[8];

  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  if (Assignment1_V4_DW.obj.SampleTime !=
      Assignment1_V4_P.FXOS87006AxesSensor_SampleTime) {
    Assignment1_V4_DW.obj.SampleTime =
      Assignment1_V4_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(Assignment1_V4_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(Assignment1_V4_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
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

  Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)
    (b_RegisterValue[0] >> 2) * 2.0 * 0.244 / 1000.0;

  /* Constant: '<S9>/Constant' */
  Assignment1_V4_B.Constant[0] = Assignment1_V4_P.Constant_Value_e[0];

  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_RegisterValue[1] >> 2) *
    2.0 * 0.244 / 1000.0;

  /* Constant: '<S9>/Constant' */
  Assignment1_V4_B.Constant[1] = Assignment1_V4_P.Constant_Value_e[1];

  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)(b_RegisterValue[2] >> 2) *
    2.0 * 0.244 / 1000.0;

  /* Constant: '<S9>/Constant' */
  Assignment1_V4_B.Constant[2] = Assignment1_V4_P.Constant_Value_e[2];

  /* Gain: '<S17>/Gain2' incorporates:
   *  Concatenate: '<S17>/Vector Concatenate'
   */
  Assignment1_V4_B.Gain2[0] *= Assignment1_V4_P.Gain2_Gain;
  Assignment1_V4_B.Gain2[1] *= Assignment1_V4_P.Gain2_Gain;

  /* MATLABSystem: '<S5>/Digital Read1' */
  if (Assignment1_V4_DW.obj_ir.SampleTime !=
      Assignment1_V4_P.DigitalRead1_SampleTime) {
    Assignment1_V4_DW.obj_ir.SampleTime =
      Assignment1_V4_P.DigitalRead1_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Boolean'
   *  MATLABSystem: '<S5>/Digital Read1'
   */
  Assignment1_V4_B.VectorConcatenate[0] = MW_digitalIO_read
    (Assignment1_V4_DW.obj_ir.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S5>/Digital Read' */
  if (Assignment1_V4_DW.obj_m4.SampleTime !=
      Assignment1_V4_P.DigitalRead_SampleTime) {
    Assignment1_V4_DW.obj_m4.SampleTime =
      Assignment1_V4_P.DigitalRead_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Boolean1'
   *  MATLABSystem: '<S5>/Digital Read'
   */
  Assignment1_V4_B.VectorConcatenate[1] = MW_digitalIO_read
    (Assignment1_V4_DW.obj_m4.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<S17>/MATLAB Function' */
  Assignment1_V4_B.PACE_CHAMBER_tmp = Assignment1_V4_mod
    (Assignment1_V4_B.Params_Arr[0], 1000.0);
  Assignment1_V4_B.PACE_CHAMBER = As_convert_to_enum_Pace_Chamber((int32_T)
    rt_roundd_snf((Assignment1_V4_mod(Assignment1_V4_B.Params_Arr[0], 10000.0) -
                   Assignment1_V4_B.PACE_CHAMBER_tmp) / 1000.0));
  Assignment1_V4_B.PACE_SENSE_CHAMBER_tmp = Assignment1_V4_mod
    (Assignment1_V4_B.Params_Arr[0], 100.0);
  Assignment1_V4_B.PACE_SENSE_CHAMBER = convert_to_enum_Pace_Sense_Cham((int32_T)
    rt_roundd_snf((Assignment1_V4_B.PACE_CHAMBER_tmp -
                   Assignment1_V4_B.PACE_SENSE_CHAMBER_tmp) / 100.0));
  Assignment1_V4_B.PACE_CHAMBER_tmp = Assignment1_V4_mod
    (Assignment1_V4_B.Params_Arr[0], 10.0);
  Assignment1_V4_B.PACE_SENSE_RESPONSE = convert_to_enum_Pace_Sense_Resp
    ((int32_T)rt_roundd_snf((Assignment1_V4_B.PACE_SENSE_CHAMBER_tmp -
       Assignment1_V4_B.PACE_CHAMBER_tmp) / 10.0));
  Assignment1_V4_B.PACE_RATE_MODE = convert_to_enum_Pace_Rate_Mode((int32_T)
    rt_roundd_snf(Assignment1_V4_B.PACE_CHAMBER_tmp - Assignment1_V4_mod
                  (Assignment1_V4_B.Params_Arr[0], 1.0)));

  /* MATLAB Function: '<S10>/MATLAB Function2' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<S15>/MATLAB Function'
   *  MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor'
   */
  if (Assignment1_V4_DW.init_counter < Assignment1_V4_P.Constant_Value_n) {
    Assignment1_V4_DW.init_counter++;
  }

  Assignment1_V4_DW.rolling_avg = sqrt
    ((Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 *
      Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 +
      rtb_FXOS87006AxesSensor_idx_1 * rtb_FXOS87006AxesSensor_idx_1) +
     rtb_FXOS87006AxesSensor_idx_2 * rtb_FXOS87006AxesSensor_idx_2) /
    Assignment1_V4_DW.init_counter + (Assignment1_V4_DW.init_counter - 1.0) *
    Assignment1_V4_DW.rolling_avg / Assignment1_V4_DW.init_counter;
  Assignment1_V4_B.smoothed_output = Assignment1_V4_DW.rolling_avg;

  /* End of MATLAB Function: '<S10>/MATLAB Function2' */

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Assignment1_V4_B.Motion_State = 3.0;
  if (Assignment1_V4_P.Constant1_Value_i[1] > Assignment1_V4_B.smoothed_output)
  {
    Assignment1_V4_B.Motion_State = 2.0;
  }

  if (Assignment1_V4_P.Constant1_Value_i[0] > Assignment1_V4_B.smoothed_output)
  {
    Assignment1_V4_B.Motion_State = 1.0;
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* Gain: '<S12>/Gain' */
  Assignment1_V4_B.Gain = Assignment1_V4_P.Gain_Gain *
    Assignment1_V4_B.smoothed_output;

  /* Gain: '<S17>/Multiply2' incorporates:
   *  Product: '<S17>/Reciprocal2'
   */
  Assignment1_V4_B.Multiply2 = 1.0 / Assignment1_V4_B.Params_Arr[3] *
    Assignment1_V4_P.Multiply2_Gain;

  /* Gain: '<S17>/Gain4' */
  Assignment1_V4_B.Gain4 = Assignment1_V4_P.Gain4_Gain *
    Assignment1_V4_B.Params_Arr[12];

  /* Gain: '<S17>/Gain5' */
  Assignment1_V4_B.Gain5 = Assignment1_V4_P.Gain5_Gain *
    Assignment1_V4_B.Params_Arr[14];

  /* Gain: '<S17>/Multiply' incorporates:
   *  Product: '<S17>/Reciprocal'
   */
  Assignment1_V4_B.Multiply = 1.0 / Assignment1_V4_B.Params_Arr[1] *
    Assignment1_V4_P.Multiply_Gain;

  /* Chart: '<S9>/RATE_CTRL_SYSTEM' */
  if (Assignment1_V4_DW.temporalCounter_i1_n < 1U) {
    Assignment1_V4_DW.temporalCounter_i1_n = 1U;
  }

  if (Assignment1_V4_DW.is_active_c9_Assignment1_V4 == 0U) {
    Assignment1_V4_DW.is_active_c9_Assignment1_V4 = 1U;
    Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Init_a;
    Assignment1_V4_B.sense_timeout_threshold = Assignment1_V4_B.Multiply;
  } else {
    switch (Assignment1_V4_DW.is_c9_Assignment1_V4) {
     case Assignment1_V4_IN_Bigger:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_get_tgt;
      Assignment1_V4_B.dv[0] = 2.6;
      Assignment1_V4_B.dv[1] = -40.0;
      Assignment1_V4_B.tgt = Assignment1__Calc_Rate_Response
        (Assignment1_V4_B.Gain, Assignment1_V4_B.Multiply,
         Assignment1_V4_B.Multiply2);
      break;

     case Assignment1_V4_IN_Detect_Mode:
      if (Assignment1_V4_B.PACE_RATE_MODE == Disabled) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V_IN_Pace_LRL_Fixed;
        Assignment1_V4_B.sense_timeout_threshold = Assignment1_V4_B.Multiply;
      } else {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V_IN_Pace_Rate_Init;
        Assignmen_Calc_Expo_Rate_Factor(Assignment1_V4_B.Gain4,
          Assignment1_V4_B.Constant, Assignment1_V4_DW.resp_fac_grow);
        Assignmen_Calc_Expo_Rate_Factor(Assignment1_V4_B.Gain5,
          Assignment1_V4_B.Constant, Assignment1_V4_DW.resp_fac_decay);
      }
      break;

     case Assignment1_V4_IN_Init_a:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Detect_Mode;
      break;

     case Assignment1_V_IN_Pace_LRL_Fixed:
      if (Assignment1_V4_B.PACE_RATE_MODE == Enabled) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Detect_Mode;
      } else {
        Assignment1_V4_B.sense_timeout_threshold = Assignment1_V4_B.Multiply;
      }
      break;

     case Assignment1_V_IN_Pace_Rate_Init:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_get_tgt;
      Assignment1_V4_B.dv[0] = 2.6;
      Assignment1_V4_B.dv[1] = -40.0;
      Assignment1_V4_B.tgt = Assignment1__Calc_Rate_Response
        (Assignment1_V4_B.Gain, Assignment1_V4_B.Multiply,
         Assignment1_V4_B.Multiply2);
      break;

     case Assignment1_V4_IN_Smaller:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_get_tgt;
      Assignment1_V4_B.dv[0] = 2.6;
      Assignment1_V4_B.dv[1] = -40.0;
      Assignment1_V4_B.tgt = Assignment1__Calc_Rate_Response
        (Assignment1_V4_B.Gain, Assignment1_V4_B.Multiply,
         Assignment1_V4_B.Multiply2);
      break;

     case Assignment1_V4_IN_check_dif:
      if (Assignment1_V4_B.dif >= 0.0) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Bigger;
        Assignment1_V4_DW.temporalCounter_i1_n = 0U;
        Assignment1_V4_B.sense_timeout_threshold +=
          Assignment1_V4_DW.resp_fac_grow[(int32_T)Assignment1_V4_B.Motion_State
          - 1] * Assignment1_V4_B.dif;
      } else if (Assignment1_V4_B.dif <= 0.0) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Smaller;
        Assignment1_V4_DW.temporalCounter_i1_n = 0U;
        Assignment1_V4_B.sense_timeout_threshold +=
          Assignment1_V4_DW.resp_fac_decay[(int32_T)
          Assignment1_V4_B.Motion_State - 1] * Assignment1_V4_B.dif;
      } else {
        Assignment1_V4_B.dif = Assignment1_V4_B.tgt -
          Assignment1_V4_B.sense_timeout_threshold;
      }
      break;

     default:
      /* case IN_get_tgt: */
      if (Assignment1_V4_B.PACE_RATE_MODE != Disabled) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_check_dif;
        Assignment1_V4_B.dif = Assignment1_V4_B.tgt -
          Assignment1_V4_B.sense_timeout_threshold;
      } else {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Detect_Mode;
      }
      break;
    }
  }

  /* End of Chart: '<S9>/RATE_CTRL_SYSTEM' */

  /* Gain: '<S17>/Multiply1' incorporates:
   *  Product: '<S17>/Reciprocal1'
   */
  Assignment1_V4_B.Multiply1 = 1.0 / Assignment1_V4_B.Params_Arr[2] *
    Assignment1_V4_P.Multiply1_Gain;

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V4_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V4_DW.temporalCounter_i1++;
  }

  Assignment1_V4_DW.sfEvent_a = -1;
  Assignment1_V_c3_Assignment1_V4();

  /* End of Chart: '<Root>/PACE_SYSTEM' */

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_ia.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.red != 0.0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.green != 0.0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_fj.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.blue != 0.0);

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_V4_DW.obj_lo.MW_PWM_HANDLE,
                      Assignment1_V4_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_o1.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Assignment1_V4_B.VENT_GND_CTRL);

  /* ToAsyncQueueBlock generated from: '<S9>/RATE_CTRL_SYSTEM' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.sense_timeout_threshold;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(454371421U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S9>/RATE_CTRL_SYSTEM' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.tgt;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3278582743U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S9>/RATE_CTRL_SYSTEM' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.dif;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(4090017295U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S9>/Motion_Magnitude' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.Gain;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3520291300U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S11>/MATLAB Function' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.Motion_State;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(861209853U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S9>/Motion_State' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.Motion_State;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(1537614228U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S10>/MATLAB Function2' */
  {
    {
      double time = Assignment1_V4_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V4_B.smoothed_output;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(1130590349U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S5>/Digital Write1' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Boolean2'
   *  DataTypeConversion: '<S5>/Cast To Double'
   */
  MW_digitalIO_write(Assignment1_V4_DW.obj_d.MW_DIGITALIO_HANDLE, (int32_T)
                     Assignment1_V4_B.PACE_SENSE_RESPONSE != 0);

  /* MATLABSystem: '<S5>/PWM Output1' incorporates:
   *  Gain: '<S17>/Gain1'
   */
  MW_PWM_SetDutyCycle(Assignment1_V4_DW.obj_j.MW_PWM_HANDLE,
                      Assignment1_V4_P.Gain1_Gain * Assignment1_V4_B.Params_Arr
                      [9]);

  /* MATLABSystem: '<S5>/PWM Output' incorporates:
   *  Gain: '<S17>/Gain'
   */
  MW_PWM_SetDutyCycle(Assignment1_V4_DW.obj_dx.MW_PWM_HANDLE,
                      Assignment1_V4_P.Gain_Gain_c *
                      Assignment1_V4_B.Params_Arr[6]);

  /* MATLABSystem: '<S5>/Analog Input' */
  if (Assignment1_V4_DW.obj_i.SampleTime !=
      Assignment1_V4_P.AnalogInput_SampleTime) {
    Assignment1_V4_DW.obj_i.SampleTime = Assignment1_V4_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE,
    &Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S5>/Analog Input' */

  /* MATLABSystem: '<S5>/Analog Input1' */
  if (Assignment1_V4_DW.obj_m.SampleTime !=
      Assignment1_V4_P.AnalogInput1_SampleTime) {
    Assignment1_V4_DW.obj_m.SampleTime =
      Assignment1_V4_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE,
    &Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S5>/Analog Input1' */

  /* MATLABSystem: '<S5>/Digital Write6' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_b.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S5>/Digital Write7' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_o.MW_DIGITALIO_HANDLE, false);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Assignment1_V4_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Assignment1_V4_M)!=-1) &&
        !((rtmGetTFinal(Assignment1_V4_M)-Assignment1_V4_M->Timing.taskTime0) >
          Assignment1_V4_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Assignment1_V4_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Assignment1_V4_M)) {
      rtmSetErrorStatus(Assignment1_V4_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Assignment1_V4_M->Timing.taskTime0 =
    ((time_T)(++Assignment1_V4_M->Timing.clockTick0)) *
    Assignment1_V4_M->Timing.stepSize0;
}

/* Model initialize function */
void Assignment1_V4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Assignment1_V4_M, 10.0);
  Assignment1_V4_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Assignment1_V4_M->Sizes.checksums[0] = (3127486407U);
  Assignment1_V4_M->Sizes.checksums[1] = (2707041077U);
  Assignment1_V4_M->Sizes.checksums[2] = (2916617302U);
  Assignment1_V4_M->Sizes.checksums[3] = (900484409U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[28];
    Assignment1_V4_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Assignment1_V4_M->extModeInfo,
      &Assignment1_V4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Assignment1_V4_M->extModeInfo,
                        Assignment1_V4_M->Sizes.checksums);
    rteiSetTPtr(Assignment1_V4_M->extModeInfo, rtmGetTPtr(Assignment1_V4_M));
  }

  /* block I/O */
  {
    Assignment1_V4_B.PACE_CHAMBER = Atrium;
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Assignment1_V4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 32;
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
    Assignment1_V4_B.Constant2 = Assignment1_V4_P.Constant2_Value_i;

    /* Start for Constant: '<S9>/Constant' */
    Assignment1_V4_B.Constant[0] = Assignment1_V4_P.Constant_Value_e[0];
    Assignment1_V4_B.Constant[1] = Assignment1_V4_P.Constant_Value_e[1];
    Assignment1_V4_B.Constant[2] = Assignment1_V4_P.Constant_Value_e[2];

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment1_V4_DW.sfEvent_a = -1;

    /* Start for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
    Assignment1_V4_DW.obj.isInitialized = 0;
    Assignment1_V4_DW.obj.i2cobj.isInitialized = 0;
    Assignment1_V4_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj.SampleTime =
      Assignment1_V4_P.FXOS87006AxesSensor_SampleTime;
    Assignment1_V4_SystemCore_setup(&Assignment1_V4_DW.obj);

    /* Start for MATLABSystem: '<S5>/Digital Read1' */
    Assignment1_V4_DW.obj_ir.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_ir.SampleTime =
      Assignment1_V4_P.DigitalRead1_SampleTime;
    obj = &Assignment1_V4_DW.obj_ir;
    Assignment1_V4_DW.obj_ir.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_V4_DW.obj_ir.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read' */
    Assignment1_V4_DW.obj_m4.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_m4.SampleTime =
      Assignment1_V4_P.DigitalRead_SampleTime;
    obj = &Assignment1_V4_DW.obj_m4;
    Assignment1_V4_DW.obj_m4.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_V4_DW.obj_m4.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    Assignment1_V4_DW.obj_ia.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_ia;
    Assignment1_V4_DW.obj_ia.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1_V4_DW.obj_ia.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    Assignment1_V4_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_p;
    Assignment1_V4_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Assignment1_V4_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    Assignment1_V4_DW.obj_fj.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_fj;
    Assignment1_V4_DW.obj_fj.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment1_V4_DW.obj_fj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Assignment1_V4_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_n;
    Assignment1_V4_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_V4_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Assignment1_V4_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_f;
    Assignment1_V4_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_V4_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Assignment1_V4_DW.obj_lo.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_lo;
    Assignment1_V4_DW.obj_lo.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V4_DW.obj_lo.MW_PWM_HANDLE);
    Assignment1_V4_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    Assignment1_V4_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_l;
    Assignment1_V4_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_V4_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write4' */
    Assignment1_V4_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_e;
    Assignment1_V4_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_V4_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    Assignment1_V4_DW.obj_o1.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_o1;
    Assignment1_V4_DW.obj_o1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_V4_DW.obj_o1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    Assignment1_V4_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_a;
    Assignment1_V4_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_V4_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    Assignment1_V4_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_d;
    Assignment1_V4_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_V4_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output1' */
    Assignment1_V4_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_j;
    Assignment1_V4_DW.obj_j.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V4_DW.obj_j.MW_PWM_HANDLE);
    Assignment1_V4_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output' */
    Assignment1_V4_DW.obj_dx.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_dx;
    Assignment1_V4_DW.obj_dx.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V4_DW.obj_dx.MW_PWM_HANDLE);
    Assignment1_V4_DW.obj_dx.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Analog Input' */
    Assignment1_V4_DW.obj_i.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_i.SampleTime = Assignment1_V4_P.AnalogInput_SampleTime;
    obj_2 = &Assignment1_V4_DW.obj_i;
    Assignment1_V4_DW.obj_i.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_V4_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Analog Input1' */
    Assignment1_V4_DW.obj_m.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_m.SampleTime =
      Assignment1_V4_P.AnalogInput1_SampleTime;
    obj_2 = &Assignment1_V4_DW.obj_m;
    Assignment1_V4_DW.obj_m.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_V4_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write6' */
    Assignment1_V4_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_b;
    Assignment1_V4_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_V4_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write7' */
    Assignment1_V4_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V4_DW.obj_o;
    Assignment1_V4_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_V4_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_V4_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  if (!Assignment1_V4_DW.obj.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj.isInitialized == 1) &&
        Assignment1_V4_DW.obj.isSetupComplete) {
      MW_I2C_Close(Assignment1_V4_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &Assignment1_V4_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read1' */
  if (!Assignment1_V4_DW.obj_ir.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_ir.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_ir.isInitialized == 1) &&
        Assignment1_V4_DW.obj_ir.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_ir.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read' */
  if (!Assignment1_V4_DW.obj_m4.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_m4.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_m4.isInitialized == 1) &&
        Assignment1_V4_DW.obj_m4.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_m4.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!Assignment1_V4_DW.obj_ia.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_ia.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_ia.isInitialized == 1) &&
        Assignment1_V4_DW.obj_ia.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_ia.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!Assignment1_V4_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_p.isInitialized == 1) &&
        Assignment1_V4_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!Assignment1_V4_DW.obj_fj.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_fj.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_fj.isInitialized == 1) &&
        Assignment1_V4_DW.obj_fj.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_fj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Assignment1_V4_DW.obj_n.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_n.isInitialized == 1) &&
        Assignment1_V4_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!Assignment1_V4_DW.obj_f.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_f.isInitialized == 1) &&
        Assignment1_V4_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!Assignment1_V4_DW.obj_lo.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_lo.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_lo.isInitialized == 1) &&
        Assignment1_V4_DW.obj_lo.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V4_DW.obj_lo.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V4_DW.obj_lo.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  if (!Assignment1_V4_DW.obj_l.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_l.isInitialized == 1) &&
        Assignment1_V4_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write4' */
  if (!Assignment1_V4_DW.obj_e.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_e.isInitialized == 1) &&
        Assignment1_V4_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  if (!Assignment1_V4_DW.obj_o1.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_o1.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_o1.isInitialized == 1) &&
        Assignment1_V4_DW.obj_o1.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_o1.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  if (!Assignment1_V4_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_a.isInitialized == 1) &&
        Assignment1_V4_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write8' */
  /* Terminate for MATLABSystem: '<S5>/Digital Write1' */
  if (!Assignment1_V4_DW.obj_d.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_d.isInitialized == 1) &&
        Assignment1_V4_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output1' */
  if (!Assignment1_V4_DW.obj_j.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_j.isInitialized == 1) &&
        Assignment1_V4_DW.obj_j.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V4_DW.obj_j.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V4_DW.obj_j.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output' */
  if (!Assignment1_V4_DW.obj_dx.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_dx.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_dx.isInitialized == 1) &&
        Assignment1_V4_DW.obj_dx.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V4_DW.obj_dx.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V4_DW.obj_dx.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output' */

  /* Terminate for MATLABSystem: '<S5>/Analog Input' */
  if (!Assignment1_V4_DW.obj_i.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_i.isInitialized == 1) &&
        Assignment1_V4_DW.obj_i.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Analog Input' */

  /* Terminate for MATLABSystem: '<S5>/Analog Input1' */
  if (!Assignment1_V4_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_m.isInitialized == 1) &&
        Assignment1_V4_DW.obj_m.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Analog Input1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write6' */
  if (!Assignment1_V4_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_b.isInitialized == 1) &&
        Assignment1_V4_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write7' */
  if (!Assignment1_V4_DW.obj_o.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_o.isInitialized == 1) &&
        Assignment1_V4_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V4_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

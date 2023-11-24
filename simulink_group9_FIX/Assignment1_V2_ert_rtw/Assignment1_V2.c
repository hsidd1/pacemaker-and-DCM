/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V2.c
 *
 * Code generated for Simulink model 'Assignment1_V2'.
 *
 * Model version                  : 2.38
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 20 17:32:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. ROM efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Assignment1_V2.h"
#include "rtwtypes.h"
#include "Assignment1_V2_types.h"
#include <string.h>
#include <math.h>
#include "Assignment1_V2_private.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "MW_I2C.h"
#include "Assignment1_V2_dt.h"

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Ass_finally_IN_Sense_Detected_e (2U)
#define Ass_finally_IN_Sense_Disabled_o (3U)
#define Assig_finally_IN_Discharge_Prep (2U)
#define Assig_finally_IN_Sense_Detect_j (1U)
#define Assig_finally_IN_Sense_Detected (6U)
#define Assig_finally_IN_Sense_Disabled (7U)
#define Assig_finally_IN_Sense_Finish_d (5U)
#define Assignm_finally_IN_Sense_Detect (5U)
#define Assignm_finally_IN_Sense_Fail_c (4U)
#define Assignm_finally_IN_Sense_Finish (9U)
#define Assignm_finally_IN_Sense_Wait_j (6U)
#define Assignmen_finally_IN_Sense_Fail (8U)
#define Assignmen_finally_IN_Sense_Wait (10U)
#define Assignment1_V2_CALL_EVENT      (-1)
#define Assignment1_V2_IN_Charge       (1U)
#define Assignment1_V2_IN_PACE         (1U)
#define Assignment1_V2_IN_Pace_Atr     (3U)
#define Assignment1_V2_IN_Pace_Vent    (4U)
#define Assignment1_V2_IN_SENSE        (2U)
#define Assignment1_V2_IN_Sense_Detect (1U)
#define Assignment1_V2_IN_Sense_Fail   (4U)
#define Assignment1_V2_IN_Sense_Finish (5U)
#define Assignment1_V2_IN_Sense_Wait   (6U)
#define Assignment1_V2_event_pace_compl (0)
#define Assignment1_V_IN_Discharge_Prep (2U)
#define Assignment1_V_IN_NO_ACTIVE_LEAF (0U)
#define Assignment1_V_IN_Sense_Detected (2U)
#define Assignment1_V_IN_Sense_Disabled (3U)
#define Assignment1_V_finally_IN_Charge (1U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1_event_sense_timeout (1)
#define Assignment1_finally_IN_Pace_Atr (3U)
#define Assignment_finally_IN_Pace_Vent (4U)

/* Block signals (default storage) */
B_Assignment1_V2_T Assignment1_V2_B;

/* Block states (default storage) */
DW_Assignment1_V2_T Assignment1_V2_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V2_T Assignment1_V2_M_;
RT_MODEL_Assignment1_V2_T *const Assignment1_V2_M = &Assignment1_V2_M_;

/* Forward declaration for local functions */
static real_T Assignment1_V2_mod(real_T x, real_T y);
static Pace_Chamber As_convert_to_enum_Pace_Chamber(int32_T input);
static Pace_Sense_Chamber convert_to_enum_Pace_Sense_Cham(int32_T input);
static Pace_Sense_Response convert_to_enum_Pace_Sense_Resp(int32_T input);
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment1_enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
static void Assignment1_V_c3_Assignment1_V2(void);
static void Assignment1_V2_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj);

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static real_T Assignment1_V2_mod(real_T x, real_T y)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
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

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V2_DW.sfEvent;
  Assignment1_V2_DW.sfEvent = Assignment1_V2_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V2();
  Assignment1_V2_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_enter_atomic_Charge(void)
{
  Assignment1_V2_B.PACE_GND_CTRL = true;
  if (Assignment1_V2_B.PACE_CHAMBER == Atrium) {
    Assignment1_V2_B.ATR_GND_CTRL = true;
    Assignment1_V2_B.VENT_GND_CTRL = false;
  } else {
    Assignment1_V2_B.ATR_GND_CTRL = false;
    Assignment1_V2_B.VENT_GND_CTRL = true;
  }

  Assignment1_V2_B.ATR_PACE_CTRL = false;
  Assignment1_V2_B.VENT_PACE_CTRL = false;
  Assignment1_V2_B.PACING_REF_PWM = Assignment1_V2_B.Gain2[(int32_T)
    Assignment1_V2_B.PACE_CHAMBER - 1];
  Assignment1_V2_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V2_DW.sfEvent;
  Assignment1_V2_DW.sfEvent = Assignment1_event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V2();
  Assignment1_V2_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V_c3_Assignment1_V2(void)
{
  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V2_DW.is_active_c3_Assignment1_V2 == 0U) {
    Assignment1_V2_DW.is_active_c3_Assignment1_V2 = 1U;
    Assignment1_V2_DW.is_c3_Assignment1_V2 = Assignment1_V2_IN_SENSE;
    Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Finish;
    Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
      Assignm_finally_IN_Sense_Finish;
    Assignment1_V2_DW.is_finally_SENSE = Assig_finally_IN_Sense_Finish_d;
  } else {
    switch (Assignment1_V2_DW.is_c3_Assignment1_V2) {
     case Assignment1_V2_IN_PACE:
      if (Assignment1_V2_DW.sfEvent == Assignment1_V2_event_pace_compl) {
        Assignment1_V2_DW.is_finally_PACE = Assignment1_V_IN_NO_ACTIVE_LEAF;
        Assignment1_V2_DW.is_PACE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V2_DW.is_c3_Assignment1_V2 = Assignment1_V2_IN_SENSE;
        Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Finish;
        Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
          Assignm_finally_IN_Sense_Finish;
        Assignment1_V2_DW.is_finally_SENSE = Assig_finally_IN_Sense_Finish_d;
      } else {
        switch (Assignment1_V2_DW.is_PACE) {
         case Assignment1_V2_IN_Charge:
          Assignment1_V2_B.PACE_GND_CTRL = true;
          if (Assignment1_V2_B.PACE_CHAMBER == Atrium) {
            Assignment1_V2_B.ATR_GND_CTRL = true;
            Assignment1_V2_B.VENT_GND_CTRL = false;
          } else {
            Assignment1_V2_B.ATR_GND_CTRL = false;
            Assignment1_V2_B.VENT_GND_CTRL = true;
          }

          Assignment1_V2_B.ATR_PACE_CTRL = false;
          Assignment1_V2_B.VENT_PACE_CTRL = false;
          Assignment1_V2_B.PACING_REF_PWM = Assignment1_V2_B.Gain2[(int32_T)
            Assignment1_V2_B.PACE_CHAMBER - 1];
          Assignment1_V2_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment1_V_IN_Discharge_Prep:
          switch (Assignment1_V2_B.PACE_CHAMBER) {
           case Atrium:
            Assignment1_V2_DW.is_PACE = Assignment1_V2_IN_Pace_Atr;
            Assignment1_V2_DW.temporalCounter_i1 = 0U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignment1_finally_IN_Pace_Atr;
            Assignment1_V2_DW.is_finally_PACE = Assignment1_finally_IN_Pace_Atr;
            Assignment1_V2_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment1_V2_DW.is_PACE = Assignment1_V2_IN_Pace_Vent;
            Assignment1_V2_DW.temporalCounter_i1 = 0U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignment_finally_IN_Pace_Vent;
            Assignment1_V2_DW.is_finally_PACE = Assignment_finally_IN_Pace_Vent;
            Assignment1_V2_B.VENT_PACE_CTRL = true;
            break;

           default:
            Assignment1_V2_B.PACING_REF_PWM = 0.0;
            Assignment1_V2_B.PACE_CHARGE_CTRL = false;
            Assignment1_V2_B.PACE_GND_CTRL = true;
            Assignment1_V2_B.ATR_GND_CTRL = false;
            Assignment1_V2_B.VENT_GND_CTRL = false;
            break;
          }
          break;

         case Assignment1_V2_IN_Pace_Atr:
          if (Assignment1_V2_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V2_B.VectorConcatenate1[(int32_T)
               Assignment1_V2_B.PACE_CHAMBER - 1])) {
            Assignment1_V2_DW.is_PACE = Assignment1_V2_IN_Charge;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignment1_V_finally_IN_Charge;
            Assignment1_V2_DW.is_finally_PACE = Assignment1_V_finally_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V2_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V2_IN_Pace_Vent:
          if (Assignment1_V2_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V2_B.VectorConcatenate1[(int32_T)
               Assignment1_V2_B.PACE_CHAMBER - 1])) {
            Assignment1_V2_DW.is_PACE = Assignment1_V2_IN_Charge;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignment1_V_finally_IN_Charge;
            Assignment1_V2_DW.is_finally_PACE = Assignment1_V_finally_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V2_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment1_V2_IN_SENSE:
      if (Assignment1_V2_DW.sfEvent == Assignment1_event_sense_timeout) {
        Assignment1_V2_DW.tp_Sense_Detect = 0U;
        Assignment1_V2_DW.tp_Sense_Detected = 0U;
        Assignment1_V2_DW.tp_Sense_Fail = 0U;
        Assignment1_V2_DW.is_finally_SENSE = Assignment1_V_IN_NO_ACTIVE_LEAF;
        Assignment1_V2_DW.is_SENSE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V2_DW.is_c3_Assignment1_V2 = Assignment1_V2_IN_PACE;
        Assignment1_V2_DW.is_PACE = Assignment1_V_IN_Discharge_Prep;
        Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
          Assig_finally_IN_Discharge_Prep;
        Assignment1_V2_DW.is_finally_PACE = Assig_finally_IN_Discharge_Prep;
        Assignment1_V2_B.PACING_REF_PWM = 0.0;
        Assignment1_V2_B.PACE_CHARGE_CTRL = false;
        Assignment1_V2_B.PACE_GND_CTRL = true;
        Assignment1_V2_B.ATR_GND_CTRL = false;
        Assignment1_V2_B.VENT_GND_CTRL = false;
      } else {
        switch (Assignment1_V2_DW.is_SENSE) {
         case Assignment1_V2_IN_Sense_Detect:
          if (Assignment1_V2_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V2_B.Multiply - Assignment1_V2_B.VectorConcatenate2
               [(int32_T)Assignment1_V2_B.PACE_SENSE_CHAMBER - 1])) {
            Assignment1_V2_DW.tp_Sense_Detect = 0U;
            Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Fail;
            Assignment1_V2_DW.tp_Sense_Fail = 1U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignmen_finally_IN_Sense_Fail;
            Assignment1_V2_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_c;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment1_V2_B.VectorConcatenate[(int32_T)
                     Assignment1_V2_B.PACE_SENSE_CHAMBER - 1]) {
            Assignment1_V2_DW.tp_Sense_Detect = 0U;
            Assignment1_V2_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
            Assignment1_V2_DW.tp_Sense_Detected = 1U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assig_finally_IN_Sense_Detected;
            Assignment1_V2_DW.is_finally_SENSE = Ass_finally_IN_Sense_Detected_e;
          }
          break;

         case Assignment1_V_IN_Sense_Detected:
          Assignment1_V2_DW.tp_Sense_Detected = 0U;
          Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Wait;
          Assignment1_V2_DW.temporalCounter_i1 = 0U;
          Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
            Assignmen_finally_IN_Sense_Wait;
          Assignment1_V2_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Wait_j;
          break;

         case Assignment1_V_IN_Sense_Disabled:
          if (Assignment1_V2_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V2_B.Multiply)) {
            Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Fail;
            Assignment1_V2_DW.tp_Sense_Fail = 1U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignmen_finally_IN_Sense_Fail;
            Assignment1_V2_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Fail_c;
            Assignm_enter_atomic_Sense_Fail();
          }
          break;

         case Assignment1_V2_IN_Sense_Fail:
          broadcast_sense_timeout_c3_Assi();
          break;

         case Assignment1_V2_IN_Sense_Finish:
          if (Assignment1_V2_B.PACE_SENSE_RESPONSE != Nothing) {
            Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Wait;
            Assignment1_V2_DW.temporalCounter_i1 = 0U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignmen_finally_IN_Sense_Wait;
            Assignment1_V2_DW.is_finally_SENSE = Assignm_finally_IN_Sense_Wait_j;
          } else {
            Assignment1_V2_DW.is_SENSE = Assignment1_V_IN_Sense_Disabled;
            Assignment1_V2_DW.temporalCounter_i1 = 0U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assig_finally_IN_Sense_Disabled;
            Assignment1_V2_DW.is_finally_SENSE = Ass_finally_IN_Sense_Disabled_o;
          }
          break;

         case Assignment1_V2_IN_Sense_Wait:
          if (Assignment1_V2_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V2_B.VectorConcatenate2[(int32_T)
               Assignment1_V2_B.PACE_SENSE_CHAMBER - 1])) {
            Assignment1_V2_DW.is_SENSE = Assignment1_V2_IN_Sense_Detect;
            Assignment1_V2_DW.temporalCounter_i1 = 0U;
            Assignment1_V2_DW.tp_Sense_Detect = 1U;
            Assignment1_V2_DW.is_finally_c3_Assignment1_V2 =
              Assignm_finally_IN_Sense_Detect;
            Assignment1_V2_DW.is_finally_SENSE = Assig_finally_IN_Sense_Detect_j;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PACE_SYSTEM' */
}

static void Assignment1_V2_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj)
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
void Assignment1_V2_step(void)
{
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  int32_T b;
  int32_T i;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
  if (Assignment1_V2_DW.obj.SampleTime !=
      Assignment1_V2_P.FXOS87006AxesSensor_SampleTime) {
    Assignment1_V2_DW.obj.SampleTime =
      Assignment1_V2_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(Assignment1_V2_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(Assignment1_V2_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
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

  rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)(b_RegisterValue[0] >> 2) *
    2.0 * 0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_RegisterValue[1] >> 2) *
    2.0 * 0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)(b_RegisterValue[2] >> 2) *
    2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor'
   */
  Assignment1_V2_B.Accel_Raw_Magnitude = (rtb_FXOS87006AxesSensor_idx_0 *
    rtb_FXOS87006AxesSensor_idx_0 + rtb_FXOS87006AxesSensor_idx_1 *
    rtb_FXOS87006AxesSensor_idx_1) + rtb_FXOS87006AxesSensor_idx_2 *
    rtb_FXOS87006AxesSensor_idx_2;
  Assignment1_V2_B.Accel_Raw_Magnitude = sqrt
    (Assignment1_V2_B.Accel_Raw_Magnitude);

  /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (!Assignment1_V2_DW.Buffer_Internal_not_empty) {
    for (i = 0; i < 2500; i++) {
      Assignment1_V2_DW.Buffer_Internal[i] = 1.0;
    }

    Assignment1_V2_DW.Buffer_Internal_not_empty = true;
  } else {
    b = (int32_T)(Assignment1_V2_P.Constant_Value - 1.0);
    for (i = 0; i < b; i++) {
      rtb_FXOS87006AxesSensor_idx_0 = Assignment1_V2_P.Constant_Value - ((real_T)
        i + 1.0);
      Assignment1_V2_DW.Buffer_Internal[(int32_T)(rtb_FXOS87006AxesSensor_idx_0
        + 1.0) - 1] = Assignment1_V2_DW.Buffer_Internal[(int32_T)
        rtb_FXOS87006AxesSensor_idx_0 - 1];
    }

    Assignment1_V2_DW.Buffer_Internal[0] = Assignment1_V2_B.Accel_Raw_Magnitude;
  }

  /* MATLAB Function: '<S12>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<S12>/MATLAB Function'
   */
  rtb_FXOS87006AxesSensor_idx_0 = 0.0;
  b = (int32_T)Assignment1_V2_P.Constant_Value;
  for (i = 0; i < b; i++) {
    rtb_FXOS87006AxesSensor_idx_0 += Assignment1_V2_DW.Buffer_Internal[i];
  }

  Assignment1_V2_B.Smoothed_Output = rtb_FXOS87006AxesSensor_idx_0 /
    Assignment1_V2_P.Constant_Value;

  /* End of MATLAB Function: '<S12>/MATLAB Function1' */

  /* ToAsyncQueueBlock generated from: '<Root>/Subsystem2' */
  {
    {
      double time = Assignment1_V2_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V2_B.Smoothed_Output;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3072705868U, time, pData, size);
    }
  }

  /* MATLAB Function: '<S8>/MATLAB Function' */
  Assignment1_V2_B.Motion_State = High;

  /* ToAsyncQueueBlock generated from: '<S8>/MATLAB Function' */
  {
    {
      double time = Assignment1_V2_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V2_B.Motion_State;
      int32_T size = 1*sizeof(Rate_Motion_State);
      sendToAsyncQueueTgtAppSvc(3630211075U, time, pData, size);
    }
  }

  /* MATLAB Function: '<S7>/MATLAB Function2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Assignment1_V2_DW.init_counter < Assignment1_V2_P.Constant_Value) {
    Assignment1_V2_DW.init_counter++;
  }

  Assignment1_V2_DW.rolling_avg = (Assignment1_V2_DW.init_counter - 1.0) *
    Assignment1_V2_DW.rolling_avg / Assignment1_V2_DW.init_counter +
    Assignment1_V2_B.Accel_Raw_Magnitude / Assignment1_V2_DW.init_counter;
  Assignment1_V2_B.smoothed_output = Assignment1_V2_DW.rolling_avg;

  /* End of MATLAB Function: '<S7>/MATLAB Function2' */

  /* ToAsyncQueueBlock generated from: '<S7>/MATLAB Function2' */
  {
    {
      double time = Assignment1_V2_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V2_B.smoothed_output;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2289219593U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/Subsystem1' */
  {
    {
      double time = Assignment1_V2_M->Timing.taskTime0;
      void *pData = (void *)&Assignment1_V2_B.Accel_Raw_Magnitude;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(1629142689U, time, pData, size);
    }
  }

  /* SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate'
   *  Constant: '<S5>/Constant1'
   */
  Assignment1_V2_B.Gain2[0] = Assignment1_V2_P.Constant1_Value_m;

  /* SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate'
   *  Constant: '<S5>/Constant1'
   */
  Assignment1_V2_B.Gain2[1] = Assignment1_V2_P.Constant1_Value_m;

  /* Gain: '<S4>/Gain2' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate'
   */
  Assignment1_V2_B.Gain2[0] *= Assignment1_V2_P.Gain2_Gain;
  Assignment1_V2_B.Gain2[1] *= Assignment1_V2_P.Gain2_Gain;

  /* SignalConversion generated from: '<S4>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate2'
   *  Constant: '<S5>/Constant4'
   */
  Assignment1_V2_B.VectorConcatenate2[0] = Assignment1_V2_P.Constant4_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate2'
   *  Constant: '<S5>/Constant4'
   */
  Assignment1_V2_B.VectorConcatenate2[1] = Assignment1_V2_P.Constant4_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate1'
   *  Constant: '<S5>/Constant3'
   */
  Assignment1_V2_B.VectorConcatenate1[0] = Assignment1_V2_P.Constant3_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate1'
   *  Constant: '<S5>/Constant3'
   */
  Assignment1_V2_B.VectorConcatenate1[1] = Assignment1_V2_P.Constant3_Value;

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (Assignment1_V2_DW.obj_m.SampleTime !=
      Assignment1_V2_P.DigitalRead1_SampleTime) {
    Assignment1_V2_DW.obj_m.SampleTime =
      Assignment1_V2_P.DigitalRead1_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Boolean'
   *  MATLABSystem: '<S2>/Digital Read1'
   */
  Assignment1_V2_B.VectorConcatenate[0] = MW_digitalIO_read
    (Assignment1_V2_DW.obj_m.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Digital Read' */
  if (Assignment1_V2_DW.obj_o.SampleTime !=
      Assignment1_V2_P.DigitalRead_SampleTime) {
    Assignment1_V2_DW.obj_o.SampleTime = Assignment1_V2_P.DigitalRead_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Boolean1'
   *  MATLABSystem: '<S2>/Digital Read'
   */
  Assignment1_V2_B.VectorConcatenate[1] = MW_digitalIO_read
    (Assignment1_V2_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_FXOS87006AxesSensor_idx_0 = Assignment1_V2_mod((real_T)
    Assignment1_V2_P.EnumeratedConstant_Value, 1000.0);
  Assignment1_V2_B.PACE_CHAMBER = As_convert_to_enum_Pace_Chamber((int32_T)
    rt_roundd_snf((Assignment1_V2_mod((real_T)
    Assignment1_V2_P.EnumeratedConstant_Value, 10000.0) -
                   rtb_FXOS87006AxesSensor_idx_0) / 1000.0));
  rtb_FXOS87006AxesSensor_idx_1 = Assignment1_V2_mod((real_T)
    Assignment1_V2_P.EnumeratedConstant_Value, 100.0);
  Assignment1_V2_B.PACE_SENSE_CHAMBER = convert_to_enum_Pace_Sense_Cham((int32_T)
    rt_roundd_snf((rtb_FXOS87006AxesSensor_idx_0 - rtb_FXOS87006AxesSensor_idx_1)
                  / 100.0));
  Assignment1_V2_B.PACE_SENSE_RESPONSE = convert_to_enum_Pace_Sense_Resp
    ((int32_T)rt_roundd_snf((rtb_FXOS87006AxesSensor_idx_1 - Assignment1_V2_mod
       ((real_T)Assignment1_V2_P.EnumeratedConstant_Value, 10.0)) / 10.0));

  /* Gain: '<S4>/Multiply' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Assignment1_V2_B.Multiply = Assignment1_V2_P.Multiply_Gain *
    Assignment1_V2_P.Constant_Value_m;

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V2_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V2_DW.temporalCounter_i1++;
  }

  Assignment1_V2_DW.sfEvent = Assignment1_V2_CALL_EVENT;
  Assignment1_V_c3_Assignment1_V2();

  /* End of Chart: '<Root>/PACE_SYSTEM' */

  /* MATLABSystem: '<S1>/Digital Write' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_n2.MW_DIGITALIO_HANDLE,
                     Assignment1_V2_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write1' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Assignment1_V2_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S1>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_V2_DW.obj_km.MW_PWM_HANDLE,
                      Assignment1_V2_B.PACING_REF_PWM);

  /* MATLABSystem: '<S1>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_mo.MW_DIGITALIO_HANDLE,
                     Assignment1_V2_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Assignment1_V2_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S1>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Assignment1_V2_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S1>/Digital Write8' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Assignment1_V2_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write1' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Boolean2'
   *  DataTypeConversion: '<S2>/Cast To Double'
   */
  MW_digitalIO_write(Assignment1_V2_DW.obj_c.MW_DIGITALIO_HANDLE, (int32_T)
                     Assignment1_V2_B.PACE_SENSE_RESPONSE != 0);

  /* MATLABSystem: '<S2>/PWM Output' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Gain: '<S4>/Gain'
   */
  MW_PWM_SetDutyCycle(Assignment1_V2_DW.obj_h.MW_PWM_HANDLE,
                      Assignment1_V2_P.Gain_Gain *
                      Assignment1_V2_P.Constant2_Value);

  /* MATLABSystem: '<S2>/PWM Output1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Gain: '<S4>/Gain1'
   */
  MW_PWM_SetDutyCycle(Assignment1_V2_DW.obj_b.MW_PWM_HANDLE,
                      Assignment1_V2_P.Gain1_Gain *
                      Assignment1_V2_P.Constant2_Value);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_k.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(Assignment1_V2_DW.obj_p.MW_DIGITALIO_HANDLE, false);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Assignment1_V2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Assignment1_V2_M)!=-1) &&
        !((rtmGetTFinal(Assignment1_V2_M)-Assignment1_V2_M->Timing.taskTime0) >
          Assignment1_V2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Assignment1_V2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Assignment1_V2_M)) {
      rtmSetErrorStatus(Assignment1_V2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Assignment1_V2_M->Timing.taskTime0 =
    ((time_T)(++Assignment1_V2_M->Timing.clockTick0)) *
    Assignment1_V2_M->Timing.stepSize0;
}

/* Model initialize function */
void Assignment1_V2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Assignment1_V2_M, 10.0);
  Assignment1_V2_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Assignment1_V2_M->Sizes.checksums[0] = (3474524650U);
  Assignment1_V2_M->Sizes.checksums[1] = (3351200685U);
  Assignment1_V2_M->Sizes.checksums[2] = (3905815002U);
  Assignment1_V2_M->Sizes.checksums[3] = (1960020723U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[23];
    Assignment1_V2_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Assignment1_V2_M->extModeInfo,
      &Assignment1_V2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Assignment1_V2_M->extModeInfo,
                        Assignment1_V2_M->Sizes.checksums);
    rteiSetTPtr(Assignment1_V2_M->extModeInfo, rtmGetTPtr(Assignment1_V2_M));
  }

  /* block I/O */
  {
    Assignment1_V2_B.Motion_State = Low;
    Assignment1_V2_B.PACE_CHAMBER = Atrium;
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Assignment1_V2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 29;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment1_V2_DW.sfEvent = Assignment1_V2_CALL_EVENT;

    /* Start for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
    Assignment1_V2_DW.obj.isInitialized = 0;
    Assignment1_V2_DW.obj.i2cobj.isInitialized = 0;
    Assignment1_V2_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    Assignment1_V2_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_V2_DW.obj.SampleTime =
      Assignment1_V2_P.FXOS87006AxesSensor_SampleTime;
    Assignment1_V2_SystemCore_setup(&Assignment1_V2_DW.obj);

    /* Start for MATLABSystem: '<S2>/Digital Read1' */
    Assignment1_V2_DW.obj_m.matlabCodegenIsDeleted = false;
    Assignment1_V2_DW.obj_m.SampleTime =
      Assignment1_V2_P.DigitalRead1_SampleTime;
    obj = &Assignment1_V2_DW.obj_m;
    Assignment1_V2_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_V2_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    Assignment1_V2_DW.obj_o.matlabCodegenIsDeleted = false;
    Assignment1_V2_DW.obj_o.SampleTime = Assignment1_V2_P.DigitalRead_SampleTime;
    obj = &Assignment1_V2_DW.obj_o;
    Assignment1_V2_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_V2_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    Assignment1_V2_DW.obj_n2.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_n2;
    Assignment1_V2_DW.obj_n2.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_V2_DW.obj_n2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    Assignment1_V2_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_j;
    Assignment1_V2_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_V2_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output' */
    Assignment1_V2_DW.obj_km.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V2_DW.obj_km;
    Assignment1_V2_DW.obj_km.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V2_DW.obj_km.MW_PWM_HANDLE);
    Assignment1_V2_DW.obj_km.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write3' */
    Assignment1_V2_DW.obj_mo.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_mo;
    Assignment1_V2_DW.obj_mo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_V2_DW.obj_mo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write4' */
    Assignment1_V2_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_i;
    Assignment1_V2_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_V2_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write5' */
    Assignment1_V2_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_n;
    Assignment1_V2_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_V2_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write8' */
    Assignment1_V2_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_l;
    Assignment1_V2_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_V2_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Assignment1_V2_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_c;
    Assignment1_V2_DW.obj_c.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_V2_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Assignment1_V2_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V2_DW.obj_h;
    Assignment1_V2_DW.obj_h.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V2_DW.obj_h.MW_PWM_HANDLE);
    Assignment1_V2_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output1' */
    Assignment1_V2_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V2_DW.obj_b;
    Assignment1_V2_DW.obj_b.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V2_DW.obj_b.MW_PWM_HANDLE);
    Assignment1_V2_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    Assignment1_V2_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_k;
    Assignment1_V2_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_V2_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    Assignment1_V2_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V2_DW.obj_p;
    Assignment1_V2_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_V2_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_V2_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
  if (!Assignment1_V2_DW.obj.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj.isInitialized == 1) &&
        Assignment1_V2_DW.obj.isSetupComplete) {
      MW_I2C_Close(Assignment1_V2_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &Assignment1_V2_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  if (!Assignment1_V2_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_m.isInitialized == 1) &&
        Assignment1_V2_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  if (!Assignment1_V2_DW.obj_o.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_o.isInitialized == 1) &&
        Assignment1_V2_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!Assignment1_V2_DW.obj_n2.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_n2.isInitialized == 1) &&
        Assignment1_V2_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  if (!Assignment1_V2_DW.obj_j.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_j.isInitialized == 1) &&
        Assignment1_V2_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S1>/PWM Output' */
  if (!Assignment1_V2_DW.obj_km.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_km.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_km.isInitialized == 1) &&
        Assignment1_V2_DW.obj_km.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V2_DW.obj_km.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V2_DW.obj_km.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write3' */
  if (!Assignment1_V2_DW.obj_mo.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_mo.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_mo.isInitialized == 1) &&
        Assignment1_V2_DW.obj_mo.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_mo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write4' */
  if (!Assignment1_V2_DW.obj_i.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_i.isInitialized == 1) &&
        Assignment1_V2_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write5' */
  if (!Assignment1_V2_DW.obj_n.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_n.isInitialized == 1) &&
        Assignment1_V2_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write8' */
  if (!Assignment1_V2_DW.obj_l.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_l.isInitialized == 1) &&
        Assignment1_V2_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!Assignment1_V2_DW.obj_c.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_c.isInitialized == 1) &&
        Assignment1_V2_DW.obj_c.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_c.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  if (!Assignment1_V2_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_h.isInitialized == 1) &&
        Assignment1_V2_DW.obj_h.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V2_DW.obj_h.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V2_DW.obj_h.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output1' */
  if (!Assignment1_V2_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_b.isInitialized == 1) &&
        Assignment1_V2_DW.obj_b.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V2_DW.obj_b.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V2_DW.obj_b.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  if (!Assignment1_V2_DW.obj_k.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_k.isInitialized == 1) &&
        Assignment1_V2_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  if (!Assignment1_V2_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment1_V2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment1_V2_DW.obj_p.isInitialized == 1) &&
        Assignment1_V2_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V2_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

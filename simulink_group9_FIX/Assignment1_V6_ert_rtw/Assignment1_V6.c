/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V6.c
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

#include "Assignment1_V6.h"
#include "Assignment1_V6_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "Assignment1_V6_private.h"
#include <stddef.h>
#include "MW_I2C.h"

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Assignment1_V6_CALL_EVENT      (-1)
#define Assignment1_V6_IN_Charge       ((uint8_T)1U)
#define Assignment1_V6_IN_PACE         ((uint8_T)1U)
#define Assignment1_V6_IN_Pace_Atr     ((uint8_T)3U)
#define Assignment1_V6_IN_Pace_Vent    ((uint8_T)4U)
#define Assignment1_V6_IN_SENSE        ((uint8_T)2U)
#define Assignment1_V6_IN_Sense_Detect ((uint8_T)1U)
#define Assignment1_V6_IN_Sense_Fail   ((uint8_T)4U)
#define Assignment1_V6_IN_Sense_Finish ((uint8_T)5U)
#define Assignment1_V6_IN_Sense_Wait   ((uint8_T)6U)
#define Assignment1_V6_event_pace_compl (0)
#define Assignment1_V_IN_Discharge_Prep ((uint8_T)2U)
#define Assignment1_V_IN_Sense_Detected ((uint8_T)2U)
#define Assignment1_V_IN_Sense_Disabled ((uint8_T)3U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1_event_sense_timeout (1)

/* Named constants for Chart: '<S4>/RATE_CTRL_SYSTEM' */
#define Assignment1_V6_IN_Bigger       ((uint8_T)1U)
#define Assignment1_V6_IN_Detect_Mode  ((uint8_T)1U)
#define Assignment1_V6_IN_Init         ((uint8_T)2U)
#define Assignment1_V6_IN_Smaller      ((uint8_T)3U)
#define Assignment1_V6_IN_check_dif    ((uint8_T)4U)
#define Assignment1_V6_IN_get_tgt      ((uint8_T)5U)
#define Assignment1_V_IN_Pace_LRL_Fixed ((uint8_T)3U)
#define Assignment1_V_IN_Pace_Rate_Init ((uint8_T)2U)
#define Assignment_IN_Pace_Rate_Unfixed ((uint8_T)4U)

/* Block signals (default storage) */
B_Assignment1_V6_T Assignment1_V6_B;

/* Block states (default storage) */
DW_Assignment1_V6_T Assignment1_V6_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V6_T Assignment1_V6_M_;
RT_MODEL_Assignment1_V6_T *const Assignment1_V6_M = &Assignment1_V6_M_;

/* Forward declaration for local functions */
static real_T Assignment1__Calc_Rate_Response(real_T activity, uint16_T LRP,
  uint16_T MSP);
static real_T Assignment1_V6_rt_powd_snf(real_T u0, real_T u1);
static void Assignmen_Calc_Expo_Rate_Factor(real_T time_tgt, const real_T
  tgt_threshold[3], real_T output_set[3]);
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment1_enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
static void Assignment1_V_c3_Assignment1_V6(void);
static void Assignment1_V6_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj);
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

/* Function for Chart: '<S4>/RATE_CTRL_SYSTEM' */
static real_T Assignment1__Calc_Rate_Response(real_T activity, uint16_T LRP,
  uint16_T MSP)
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

static real_T Assignment1_V6_rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    Assignment1_V6_B.d1 = fabs(u0);
    tmp = fabs(u1);
    if (rtIsInf(u1)) {
      if (Assignment1_V6_B.d1 == 1.0) {
        y = 1.0;
      } else if (Assignment1_V6_B.d1 > 1.0) {
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
    } else if (tmp == 0.0) {
      y = 1.0;
    } else if (tmp == 1.0) {
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

/* Function for Chart: '<S4>/RATE_CTRL_SYSTEM' */
static void Assignmen_Calc_Expo_Rate_Factor(real_T time_tgt, const real_T
  tgt_threshold[3], real_T output_set[3])
{
  Assignment1_V6_B.y = 1.0 / -time_tgt;
  output_set[0] = Assignment1_V6_rt_powd_snf(tgt_threshold[0],
    Assignment1_V6_B.y) - 1.0;
  output_set[1] = Assignment1_V6_rt_powd_snf(tgt_threshold[1],
    Assignment1_V6_B.y) - 1.0;
  output_set[2] = Assignment1_V6_rt_powd_snf(tgt_threshold[2],
    Assignment1_V6_B.y) - 1.0;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V6_DW.sfEvent;
  Assignment1_V6_DW.sfEvent = Assignment1_V6_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V6();
  Assignment1_V6_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_enter_atomic_Charge(void)
{
  Assignment1_V6_B.PACE_GND_CTRL = true;
  if (Assignment1_V6_B.Cast7 == Atrium) {
    Assignment1_V6_B.ATR_GND_CTRL = true;
    Assignment1_V6_B.VENT_GND_CTRL = false;
  } else {
    Assignment1_V6_B.ATR_GND_CTRL = false;
    Assignment1_V6_B.VENT_GND_CTRL = true;
  }

  Assignment1_V6_B.ATR_PACE_CTRL = false;
  Assignment1_V6_B.VENT_PACE_CTRL = false;
  Assignment1_V6_B.PACING_REF_PWM = Assignment1_V6_B.Gain2[(int32_T)
    Assignment1_V6_B.Cast7 - 1];
  Assignment1_V6_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V6_DW.sfEvent;
  Assignment1_V6_DW.sfEvent = Assignment1_event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V6();
  Assignment1_V6_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  Assignment1_V6_B.red = 0.0;
  Assignment1_V6_B.green = 0.0;
  Assignment1_V6_B.blue = 0.0;
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V_c3_Assignment1_V6(void)
{
  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V6_DW.is_active_c3_Assignment1_V6 == 0U) {
    Assignment1_V6_DW.is_active_c3_Assignment1_V6 = 1U;
    Assignment1_V6_DW.is_c3_Assignment1_V6 = Assignment1_V6_IN_SENSE;
    Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Finish;
  } else {
    switch (Assignment1_V6_DW.is_c3_Assignment1_V6) {
     case Assignment1_V6_IN_PACE:
      if (Assignment1_V6_DW.sfEvent == Assignment1_V6_event_pace_compl) {
        Assignment1_V6_DW.is_PACE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V6_DW.is_c3_Assignment1_V6 = Assignment1_V6_IN_SENSE;
        Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Finish;
      } else {
        switch (Assignment1_V6_DW.is_PACE) {
         case Assignment1_V6_IN_Charge:
          Assignment1_V6_B.PACE_GND_CTRL = true;
          if (Assignment1_V6_B.Cast7 == Atrium) {
            Assignment1_V6_B.ATR_GND_CTRL = true;
            Assignment1_V6_B.VENT_GND_CTRL = false;
          } else {
            Assignment1_V6_B.ATR_GND_CTRL = false;
            Assignment1_V6_B.VENT_GND_CTRL = true;
          }

          Assignment1_V6_B.ATR_PACE_CTRL = false;
          Assignment1_V6_B.VENT_PACE_CTRL = false;
          Assignment1_V6_B.PACING_REF_PWM = Assignment1_V6_B.Gain2[(int32_T)
            Assignment1_V6_B.Cast7 - 1];
          Assignment1_V6_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment1_V_IN_Discharge_Prep:
          switch (Assignment1_V6_B.Cast7) {
           case Atrium:
            Assignment1_V6_DW.is_PACE = Assignment1_V6_IN_Pace_Atr;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
            Assignment1_V6_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment1_V6_DW.is_PACE = Assignment1_V6_IN_Pace_Vent;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
            Assignment1_V6_B.VENT_PACE_CTRL = true;
            break;

           default:
            Assignment1_V6_B.PACING_REF_PWM = 0.0F;
            Assignment1_V6_B.PACE_CHARGE_CTRL = false;
            Assignment1_V6_B.PACE_GND_CTRL = true;
            Assignment1_V6_B.ATR_GND_CTRL = false;
            Assignment1_V6_B.VENT_GND_CTRL = false;
            break;
          }
          break;

         case Assignment1_V6_IN_Pace_Atr:
          if (Assignment1_V6_DW.temporalCounter_i1 >=
              Assignment1_V6_B.VectorConcatenate1[(int32_T)
              Assignment1_V6_B.Cast7 - 1]) {
            Assignment1_V6_DW.is_PACE = Assignment1_V6_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V6_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V6_IN_Pace_Vent:
          if (Assignment1_V6_DW.temporalCounter_i1 >=
              Assignment1_V6_B.VectorConcatenate1[(int32_T)
              Assignment1_V6_B.Cast7 - 1]) {
            Assignment1_V6_DW.is_PACE = Assignment1_V6_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V6_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment1_V6_IN_SENSE:
      if (Assignment1_V6_DW.sfEvent == Assignment1_event_sense_timeout) {
        Assignment1_V6_DW.tp_Sense_Detect = 0U;
        Assignment1_V6_DW.tp_Sense_Detected = 0U;
        Assignment1_V6_DW.tp_Sense_Fail = 0U;
        Assignment1_V6_DW.is_SENSE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V6_DW.is_c3_Assignment1_V6 = Assignment1_V6_IN_PACE;
        Assignment1_V6_DW.is_PACE = Assignment1_V_IN_Discharge_Prep;
        Assignment1_V6_B.PACING_REF_PWM = 0.0F;
        Assignment1_V6_B.PACE_CHARGE_CTRL = false;
        Assignment1_V6_B.PACE_GND_CTRL = true;
        Assignment1_V6_B.ATR_GND_CTRL = false;
        Assignment1_V6_B.VENT_GND_CTRL = false;
      } else {
        switch (Assignment1_V6_DW.is_SENSE) {
         case Assignment1_V6_IN_Sense_Detect:
          if ((Assignment1_V6_B.Cast9 == Nothing) ||
              (Assignment1_V6_DW.temporalCounter_i1 >= (uint32_T)
               (Assignment1_V6_B.sense_timeout_threshold -
                Assignment1_V6_B.Cast11[(int32_T)Assignment1_V6_B.Cast8 - 1])))
          {
            Assignment1_V6_DW.tp_Sense_Detect = 0U;
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Fail;
            Assignment1_V6_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment1_V6_B.VectorConcatenate[(int32_T)
                     Assignment1_V6_B.Cast8 - 1] == 1.0) {
            Assignment1_V6_DW.tp_Sense_Detect = 0U;
            Assignment1_V6_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
            Assignment1_V6_DW.tp_Sense_Detected = 1U;
            Assignment1_V6_B.red = 0.0;
            Assignment1_V6_B.green = 0.0;
            Assignment1_V6_B.blue = 0.0;
          } else {
            Assignment1_V6_B.red = 0.0;
            Assignment1_V6_B.green = 1.0;
            Assignment1_V6_B.blue = 0.0;
          }
          break;

         case Assignment1_V_IN_Sense_Detected:
          Assignment1_V6_DW.tp_Sense_Detected = 0U;
          Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Wait;
          Assignment1_V6_DW.temporalCounter_i1 = 0U;
          Assignment1_V6_B.red = 1.0;
          Assignment1_V6_B.green = 0.0;
          Assignment1_V6_B.blue = 0.0;
          break;

         case Assignment1_V_IN_Sense_Disabled:
          if (Assignment1_V6_DW.temporalCounter_i1 >=
              Assignment1_V6_B.sense_timeout_threshold) {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Fail;
            Assignment1_V6_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          }
          break;

         case Assignment1_V6_IN_Sense_Fail:
          Assignment1_V6_B.red = 0.0;
          Assignment1_V6_B.green = 0.0;
          Assignment1_V6_B.blue = 0.0;
          broadcast_sense_timeout_c3_Assi();
          break;

         case Assignment1_V6_IN_Sense_Finish:
          if (Assignment1_V6_B.Cast9 != Nothing) {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Wait;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
            Assignment1_V6_B.red = 1.0;
            Assignment1_V6_B.green = 0.0;
            Assignment1_V6_B.blue = 0.0;
          } else {
            Assignment1_V6_DW.is_SENSE = Assignment1_V_IN_Sense_Disabled;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Assignment1_V6_IN_Sense_Wait:
          if (Assignment1_V6_B.Cast9 == Nothing) {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Fail;
            Assignment1_V6_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment1_V6_DW.temporalCounter_i1 >=
                     Assignment1_V6_B.Cast11[(int32_T)Assignment1_V6_B.Cast8 - 1])
          {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Detect;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
            Assignment1_V6_DW.tp_Sense_Detect = 1U;
            Assignment1_V6_B.red = 0.0;
            Assignment1_V6_B.green = 1.0;
            Assignment1_V6_B.blue = 0.0;
          } else {
            Assignment1_V6_B.red = 1.0;
            Assignment1_V6_B.green = 0.0;
            Assignment1_V6_B.blue = 0.0;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PACE_SYSTEM' */
}

static void Assignment1_V6_SystemCore_setup(freedomk64f_fxos8700_Assignme_T *obj)
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
void Assignment1_V6_step(void)
{
  int32_T bitIdx;
  int32_T i;
  int32_T j;
  int32_T rtb_Motion_State;
  uint32_T tmp;
  int16_T b_RegisterValue[3];
  uint16_T rtb_Cast12;
  uint16_T rtb_Cast14;
  uint8_T output_raw[6];
  uint8_T rtb_BittoIntegerConverter1[4];
  uint8_T b_x[2];
  uint8_T rtb_VectorConcatenate2[2];
  uint8_T status;
  Pace_Rate_Mode rtb_Cast10;

  /* Constant: '<S5>/Constant10' */
  Assignment1_V6_B.Gain_n[0] = Assignment1_V6_P.Constant10_Value;

  /* Constant: '<S5>/Constant' */
  Assignment1_V6_B.Gain_n[1] = Assignment1_V6_P.Constant_Value;

  /* Constant: '<S5>/Constant5' */
  Assignment1_V6_B.Gain_n[2] = Assignment1_V6_P.Constant5_Value;

  /* Constant: '<S5>/Constant9' */
  Assignment1_V6_B.Gain_n[3] = Assignment1_V6_P.Constant9_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  Assignment1_V6_B.Gain_n[4] = Assignment1_V6_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  Assignment1_V6_B.Gain_n[5] = Assignment1_V6_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  Assignment1_V6_B.Gain_n[6] = Assignment1_V6_P.Constant2_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  Assignment1_V6_B.Gain_n[7] = Assignment1_V6_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  Assignment1_V6_B.Gain_n[8] = Assignment1_V6_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  Assignment1_V6_B.Gain_n[9] = Assignment1_V6_P.Constant2_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  Assignment1_V6_B.Gain_n[10] = Assignment1_V6_P.Constant4_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  Assignment1_V6_B.Gain_n[11] = Assignment1_V6_P.Constant4_Value;

  /* Constant: '<S5>/Constant6' */
  Assignment1_V6_B.Gain_n[12] = Assignment1_V6_P.Constant6_Value;

  /* Constant: '<S5>/Constant7' */
  Assignment1_V6_B.Gain_n[13] = Assignment1_V6_P.Constant7_Value;

  /* Constant: '<S5>/Constant8' */
  Assignment1_V6_B.Gain_n[14] = Assignment1_V6_P.Constant8_Value;

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Gain: '<Root>/Gain'
   */
  for (i = 0; i < 15; i++) {
    Assignment1_V6_B.d = floor(Assignment1_V6_P.Gain_Gain *
      Assignment1_V6_B.Gain_n[i]);
    if (rtIsNaN(Assignment1_V6_B.d) || rtIsInf(Assignment1_V6_B.d)) {
      Assignment1_V6_B.d = 0.0;
    } else {
      Assignment1_V6_B.d = fmod(Assignment1_V6_B.d, 256.0);
    }

    Assignment1_V6_B.Cast[i] = (uint8_T)(Assignment1_V6_B.d < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-Assignment1_V6_B.d : (int32_T)(uint8_T)
      Assignment1_V6_B.d);
  }

  /* End of DataTypeConversion: '<Root>/Cast' */

  /* S-Function (scominttobit): '<S15>/Integer to Bit Converter' */
  /* Integer to Bit Conversion */
  rtb_Motion_State = 8;
  i = Assignment1_V6_B.Cast[0];
  for (j = 0; j < 8; j++) {
    Assignment1_V6_B.IntegertoBitConverter[rtb_Motion_State - 1] = (uint8_T)
      ((uint32_T)i & 1U);
    i = (int32_T)((uint32_T)i >> 1U);
    rtb_Motion_State--;
  }

  /* End of S-Function (scominttobit): '<S15>/Integer to Bit Converter' */

  /* S-Function (scominttobit): '<S15>/Bit to Integer Converter1' */
  /* Bit to Integer Conversion */
  rtb_Motion_State = 0;
  for (i = 0; i < 4; i++) {
    /* Input bit order is MSB first */
    j = Assignment1_V6_B.IntegertoBitConverter[rtb_Motion_State];
    bitIdx = rtb_Motion_State + 1;

    /* Input bit order is MSB first */
    rtb_Motion_State += 2;
    rtb_BittoIntegerConverter1[i] = (uint8_T)((uint32_T)j << 1U |
      Assignment1_V6_B.IntegertoBitConverter[bitIdx]);
  }

  /* End of S-Function (scominttobit): '<S15>/Bit to Integer Converter1' */

  /* Gain: '<S15>/Gain16' incorporates:
   *  Concatenate: '<S15>/Vector Concatenate'
   *  DataTypeConversion: '<S15>/Cast'
   */
  Assignment1_V6_B.Gain2[0] = Assignment1_V6_P.Gain16_Gain * (real32_T)
    Assignment1_V6_B.Cast[4];

  /* Gain: '<S15>/Gain15' incorporates:
   *  Concatenate: '<S15>/Vector Concatenate'
   *  DataTypeConversion: '<S15>/Cast1'
   */
  Assignment1_V6_B.Gain2[1] = Assignment1_V6_P.Gain15_Gain * (real32_T)
    Assignment1_V6_B.Cast[7];

  /* DataTypeConversion: '<S15>/Cast11' incorporates:
   *  SignalConversion generated from: '<S15>/Vector Concatenate2'
   */
  Assignment1_V6_B.Cast11[0] = Assignment1_V6_B.Cast[10];

  /* Gain: '<S15>/Gain2' incorporates:
   *  Concatenate: '<S15>/Vector Concatenate'
   */
  Assignment1_V6_B.Gain2[0] *= Assignment1_V6_P.Gain2_Gain;

  /* DataTypeConversion: '<S15>/Cast11' incorporates:
   *  SignalConversion generated from: '<S15>/Vector Concatenate2'
   */
  Assignment1_V6_B.Cast11[1] = Assignment1_V6_B.Cast[11];

  /* Gain: '<S15>/Gain2' incorporates:
   *  Concatenate: '<S15>/Vector Concatenate'
   */
  Assignment1_V6_B.Gain2[1] *= Assignment1_V6_P.Gain2_Gain;

  /* Gain: '<S15>/Gain7' incorporates:
   *  Concatenate: '<S15>/Vector Concatenate1'
   *  DataTypeConversion: '<S15>/Cast4'
   */
  Assignment1_V6_B.VectorConcatenate1[0] = Assignment1_V6_P.Gain7_Gain *
    (real32_T)Assignment1_V6_B.Cast[5];

  /* Gain: '<S15>/Gain8' incorporates:
   *  Concatenate: '<S15>/Vector Concatenate1'
   *  DataTypeConversion: '<S15>/Cast5'
   */
  Assignment1_V6_B.VectorConcatenate1[1] = Assignment1_V6_P.Gain8_Gain *
    (real32_T)Assignment1_V6_B.Cast[8];

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Assignment1_V6_B.VectorConcatenate[0] = 0.0;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Assignment1_V6_B.VectorConcatenate[1] = 0.0;

  /* DataTypeConversion: '<S15>/Cast7' */
  Assignment1_V6_B.Cast7 = (Pace_Chamber)rtb_BittoIntegerConverter1[0];

  /* DataTypeConversion: '<S15>/Cast8' */
  Assignment1_V6_B.Cast8 = (Pace_Sense_Chamber)rtb_BittoIntegerConverter1[1];

  /* Outputs for Atomic SubSystem: '<Root>/Function-Call Subsystem' */
  /* MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  if (Assignment1_V6_DW.obj.SampleTime !=
      Assignment1_V6_P.FXOS87006AxesSensor_SampleTime) {
    Assignment1_V6_DW.obj.SampleTime =
      Assignment1_V6_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(Assignment1_V6_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(Assignment1_V6_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
                      &output_raw[0], 6U, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)3 *
           sizeof(int16_T));
    memcpy((void *)&rtb_VectorConcatenate2[0], (void *)&b_RegisterValue[0],
           (size_t)2 * sizeof(uint8_T));
    b_x[0] = rtb_VectorConcatenate2[1];
    b_x[1] = rtb_VectorConcatenate2[0];
    memcpy((void *)&b_RegisterValue[0], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&rtb_VectorConcatenate2[0], (void *)&b_RegisterValue[1],
           (size_t)2 * sizeof(uint8_T));
    b_x[0] = rtb_VectorConcatenate2[1];
    b_x[1] = rtb_VectorConcatenate2[0];
    memcpy((void *)&b_RegisterValue[1], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&rtb_VectorConcatenate2[0], (void *)&b_RegisterValue[2],
           (size_t)2 * sizeof(uint8_T));
    b_x[0] = rtb_VectorConcatenate2[1];
    b_x[1] = rtb_VectorConcatenate2[0];
    memcpy((void *)&b_RegisterValue[2], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  Assignment1_V6_B.FXOS87006AxesSensor[0] = (real_T)(int16_T)(b_RegisterValue[0]
    >> 2) * 2.0 * 0.244 / 1000.0;
  Assignment1_V6_B.FXOS87006AxesSensor[1] = (real_T)(int16_T)(b_RegisterValue[1]
    >> 2) * 2.0 * 0.244 / 1000.0;
  Assignment1_V6_B.FXOS87006AxesSensor[2] = (real_T)(int16_T)(b_RegisterValue[2]
    >> 2) * 2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  /* End of Outputs for SubSystem: '<Root>/Function-Call Subsystem' */

  /* MATLAB Function: '<S10>/MATLAB Function2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  DotProduct: '<S7>/Dot Product'
   *  MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor'
   *  Sqrt: '<S7>/Square Root'
   */
  if (Assignment1_V6_DW.init_counter < Assignment1_V6_P.Constant1_Value_j) {
    Assignment1_V6_DW.init_counter++;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Function-Call Subsystem' */
  Assignment1_V6_DW.rolling_avg = sqrt((Assignment1_V6_B.FXOS87006AxesSensor[0] *
    Assignment1_V6_B.FXOS87006AxesSensor[0] +
    Assignment1_V6_B.FXOS87006AxesSensor[1] *
    Assignment1_V6_B.FXOS87006AxesSensor[1]) +
    Assignment1_V6_B.FXOS87006AxesSensor[2] *
    Assignment1_V6_B.FXOS87006AxesSensor[2]) / Assignment1_V6_DW.init_counter +
    (Assignment1_V6_DW.init_counter - 1.0) * Assignment1_V6_DW.rolling_avg /
    Assignment1_V6_DW.init_counter;

  /* End of Outputs for SubSystem: '<Root>/Function-Call Subsystem' */

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  Constant: '<S4>/Constant2'
   *  MATLAB Function: '<S10>/MATLAB Function2'
   */
  rtb_Motion_State = 3;
  if (Assignment1_V6_P.Constant2_Value_o[1] > Assignment1_V6_DW.rolling_avg) {
    rtb_Motion_State = 2;
  }

  if (Assignment1_V6_P.Constant2_Value_o[0] > Assignment1_V6_DW.rolling_avg) {
    rtb_Motion_State = 1;
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* Gain: '<S12>/Gain' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function2'
   */
  Assignment1_V6_B.Gain = Assignment1_V6_P.Gain_Gain_e *
    Assignment1_V6_DW.rolling_avg;

  /* DataTypeConversion: '<S15>/Cast14' incorporates:
   *  DataTypeConversion: '<S15>/Cast To Double2'
   *  Gain: '<S15>/Multiply2'
   *  Product: '<S15>/Reciprocal2'
   */
  Assignment1_V6_B.d = floor(1.0 / (real_T)Assignment1_V6_B.Cast[3] *
    Assignment1_V6_P.Multiply2_Gain);
  if (rtIsNaN(Assignment1_V6_B.d) || rtIsInf(Assignment1_V6_B.d)) {
    Assignment1_V6_B.d = 0.0;
  } else {
    Assignment1_V6_B.d = fmod(Assignment1_V6_B.d, 65536.0);
  }

  rtb_Cast14 = (uint16_T)(Assignment1_V6_B.d < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-Assignment1_V6_B.d : (int32_T)(uint16_T)
    Assignment1_V6_B.d);

  /* End of DataTypeConversion: '<S15>/Cast14' */

  /* DataTypeConversion: '<S15>/Cast10' */
  rtb_Cast10 = (Pace_Rate_Mode)rtb_BittoIntegerConverter1[3];

  /* DataTypeConversion: '<S15>/Cast12' incorporates:
   *  DataTypeConversion: '<S15>/Cast To Double'
   *  Gain: '<S15>/Multiply'
   *  Product: '<S15>/Reciprocal'
   */
  Assignment1_V6_B.d = floor(1.0 / (real_T)Assignment1_V6_B.Cast[1] *
    Assignment1_V6_P.Multiply_Gain);
  if (rtIsNaN(Assignment1_V6_B.d) || rtIsInf(Assignment1_V6_B.d)) {
    Assignment1_V6_B.d = 0.0;
  } else {
    Assignment1_V6_B.d = fmod(Assignment1_V6_B.d, 65536.0);
  }

  rtb_Cast12 = (uint16_T)(Assignment1_V6_B.d < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-Assignment1_V6_B.d : (int32_T)(uint16_T)
    Assignment1_V6_B.d);

  /* End of DataTypeConversion: '<S15>/Cast12' */

  /* Chart: '<S4>/RATE_CTRL_SYSTEM' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataTypeConversion: '<S15>/Cast15'
   *  DataTypeConversion: '<S15>/Cast16'
   *  Gain: '<S15>/Gain4'
   *  Gain: '<S15>/Gain5'
   */
  if (Assignment1_V6_DW.temporalCounter_i1_f < 1U) {
    Assignment1_V6_DW.temporalCounter_i1_f = 1U;
  }

  if (Assignment1_V6_DW.is_active_c9_Assignment1_V6 == 0U) {
    Assignment1_V6_DW.is_active_c9_Assignment1_V6 = 1U;
    Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V6_IN_Init;
    Assignment1_V6_B.sense_timeout_threshold = rtb_Cast12;
  } else {
    switch (Assignment1_V6_DW.is_c9_Assignment1_V6) {
     case Assignment1_V6_IN_Detect_Mode:
      switch (rtb_Cast10) {
       case Disabled:
        Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V_IN_Pace_LRL_Fixed;
        Assignment1_V6_B.sense_timeout_threshold = rtb_Cast12;
        break;

       case Enabled:
        Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment_IN_Pace_Rate_Unfixed;
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V_IN_Pace_Rate_Init;
        Assignment1_V6_B.FXOS87006AxesSensor[0] =
          Assignment1_V6_P.Constant_Value_d[0] / (real_T)Assignment1_V6_B.Cast
          [13];
        Assignment1_V6_B.FXOS87006AxesSensor[1] =
          Assignment1_V6_P.Constant_Value_d[1] / (real_T)Assignment1_V6_B.Cast
          [13];
        Assignment1_V6_B.FXOS87006AxesSensor[2] =
          Assignment1_V6_P.Constant_Value_d[2] / (real_T)Assignment1_V6_B.Cast
          [13];
        Assignmen_Calc_Expo_Rate_Factor((real_T)((uint64_T)
          Assignment1_V6_P.Gain4_Gain * Assignment1_V6_B.Cast[12]) *
          2.384185791015625E-7, Assignment1_V6_B.FXOS87006AxesSensor,
          Assignment1_V6_DW.resp_fac_grow);
        Assignmen_Calc_Expo_Rate_Factor((real_T)((uint64_T)
          Assignment1_V6_P.Gain5_Gain * Assignment1_V6_B.Cast[14]) *
          1.52587890625E-5, Assignment1_V6_B.FXOS87006AxesSensor,
          Assignment1_V6_DW.resp_fac_decay);
        Assignment1_V6_DW.iter = 0.0;
        break;
      }
      break;

     case Assignment1_V6_IN_Init:
      Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V6_IN_Detect_Mode;
      break;

     case Assignment1_V_IN_Pace_LRL_Fixed:
      if (rtb_Cast10 == Enabled) {
        Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V6_IN_Detect_Mode;
      } else {
        Assignment1_V6_B.sense_timeout_threshold = rtb_Cast12;
      }
      break;

     default:
      /* case IN_Pace_Rate_Unfixed: */
      switch (Assignment1_V6_DW.is_Pace_Rate_Unfixed) {
       case Assignment1_V6_IN_Bigger:
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_get_tgt;
        Assignment1_V6_B.dv[0] = 2.6;
        Assignment1_V6_B.dv[1] = -40.0;
        Assignment1_V6_DW.tgt = Assignment1__Calc_Rate_Response
          (Assignment1_V6_B.Gain, rtb_Cast12, rtb_Cast14);
        Assignment1_V6_DW.iter++;
        if (Assignment1_V6_DW.iter == 10.0) {
          Assignment1_V6_DW.iter = 0.0;
        }
        break;

       case Assignment1_V_IN_Pace_Rate_Init:
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_get_tgt;
        Assignment1_V6_B.dv[0] = 2.6;
        Assignment1_V6_B.dv[1] = -40.0;
        Assignment1_V6_DW.tgt = Assignment1__Calc_Rate_Response
          (Assignment1_V6_B.Gain, rtb_Cast12, rtb_Cast14);
        Assignment1_V6_DW.iter++;
        if (Assignment1_V6_DW.iter == 10.0) {
          Assignment1_V6_DW.iter = 0.0;
        }
        break;

       case Assignment1_V6_IN_Smaller:
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_get_tgt;
        Assignment1_V6_B.dv[0] = 2.6;
        Assignment1_V6_B.dv[1] = -40.0;
        Assignment1_V6_DW.tgt = Assignment1__Calc_Rate_Response
          (Assignment1_V6_B.Gain, rtb_Cast12, rtb_Cast14);
        Assignment1_V6_DW.iter++;
        if (Assignment1_V6_DW.iter == 10.0) {
          Assignment1_V6_DW.iter = 0.0;
        }
        break;

       case Assignment1_V6_IN_check_dif:
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_Bigger;
        Assignment1_V6_DW.temporalCounter_i1_f = 0U;
        Assignment1_V6_B.d = rt_roundd_snf
          (Assignment1_V6_DW.resp_fac_grow[rtb_Motion_State - 1] * (real_T)
           Assignment1_V6_DW.dif);
        if (Assignment1_V6_B.d < 65536.0) {
          if (Assignment1_V6_B.d >= 0.0) {
            rtb_Cast14 = (uint16_T)Assignment1_V6_B.d;
          } else {
            rtb_Cast14 = 0U;
          }
        } else {
          rtb_Cast14 = MAX_uint16_T;
        }

        tmp = (uint32_T)Assignment1_V6_B.sense_timeout_threshold + rtb_Cast14;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        Assignment1_V6_B.sense_timeout_threshold = (uint16_T)tmp;
        break;

       default:
        /* case IN_get_tgt: */
        if (rtb_Cast10 != Disabled) {
          Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_check_dif;
          Assignment1_V6_B.d = rt_roundd_snf(Assignment1_V6_DW.tgt - (real_T)
            Assignment1_V6_B.sense_timeout_threshold);
          if (Assignment1_V6_B.d < 65536.0) {
            if (Assignment1_V6_B.d >= 0.0) {
              Assignment1_V6_DW.dif = (uint16_T)Assignment1_V6_B.d;
            } else {
              Assignment1_V6_DW.dif = 0U;
            }
          } else {
            Assignment1_V6_DW.dif = MAX_uint16_T;
          }
        } else {
          Assignment1_V6_DW.is_Pace_Rate_Unfixed =
            Assignment1__IN_NO_ACTIVE_CHILD;
          Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V6_IN_Detect_Mode;
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/RATE_CTRL_SYSTEM' */

  /* DataTypeConversion: '<S15>/Cast9' */
  Assignment1_V6_B.Cast9 = (Pace_Sense_Response)rtb_BittoIntegerConverter1[2];

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V6_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V6_DW.temporalCounter_i1++;
  }

  Assignment1_V6_DW.sfEvent = Assignment1_V6_CALL_EVENT;
  Assignment1_V_c3_Assignment1_V6();

  /* End of Chart: '<Root>/PACE_SYSTEM' */

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.red != 0.0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_bo.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.green != 0.0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.blue != 0.0);

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_V6_DW.obj_d.MW_PWM_HANDLE, (real_T)
                      Assignment1_V6_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.VENT_GND_CTRL);
}

/* Model initialize function */
void Assignment1_V6_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    Assignment1_V6_B.Cast7 = Atrium;
  }

  {
    freedomk64f_DigitalWrite_Assi_T *obj;
    freedomk64f_PWMOutput_Assignm_T *obj_0;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Function-Call Subsystem' */
    /* Start for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
    Assignment1_V6_DW.obj.isInitialized = 0;
    Assignment1_V6_DW.obj.i2cobj.isInitialized = 0;
    Assignment1_V6_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj.SampleTime =
      Assignment1_V6_P.FXOS87006AxesSensor_SampleTime;
    Assignment1_V6_SystemCore_setup(&Assignment1_V6_DW.obj);

    /* End of SystemInitialize for SubSystem: '<Root>/Function-Call Subsystem' */

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment1_V6_DW.sfEvent = Assignment1_V6_CALL_EVENT;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    Assignment1_V6_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_j;
    Assignment1_V6_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1_V6_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    Assignment1_V6_DW.obj_bo.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_bo;
    Assignment1_V6_DW.obj_bo.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Assignment1_V6_DW.obj_bo.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    Assignment1_V6_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_l;
    Assignment1_V6_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment1_V6_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    Assignment1_V6_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_k;
    Assignment1_V6_DW.obj_k.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_V6_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Assignment1_V6_DW.obj_p.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_p;
    Assignment1_V6_DW.obj_p.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_V6_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Assignment1_V6_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_V6_DW.obj_d;
    Assignment1_V6_DW.obj_d.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V6_DW.obj_d.MW_PWM_HANDLE);
    Assignment1_V6_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    Assignment1_V6_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_h;
    Assignment1_V6_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_V6_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    Assignment1_V6_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_b;
    Assignment1_V6_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_V6_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    Assignment1_V6_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_m;
    Assignment1_V6_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_V6_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    Assignment1_V6_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &Assignment1_V6_DW.obj_e;
    Assignment1_V6_DW.obj_e.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_V6_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_V6_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for Atomic SubSystem: '<Root>/Function-Call Subsystem' */
  /* Terminate for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  if (!Assignment1_V6_DW.obj.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj.isInitialized == 1) &&
        Assignment1_V6_DW.obj.isSetupComplete) {
      MW_I2C_Close(Assignment1_V6_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &Assignment1_V6_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  /* End of Terminate for SubSystem: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!Assignment1_V6_DW.obj_j.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_j.isInitialized == 1) &&
        Assignment1_V6_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!Assignment1_V6_DW.obj_bo.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_bo.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_bo.isInitialized == 1) &&
        Assignment1_V6_DW.obj_bo.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_bo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!Assignment1_V6_DW.obj_l.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_l.isInitialized == 1) &&
        Assignment1_V6_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  if (!Assignment1_V6_DW.obj_k.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_k.isInitialized == 1) &&
        Assignment1_V6_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!Assignment1_V6_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_p.isInitialized == 1) &&
        Assignment1_V6_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  if (!Assignment1_V6_DW.obj_d.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_d.isInitialized == 1) &&
        Assignment1_V6_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V6_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V6_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  if (!Assignment1_V6_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_h.isInitialized == 1) &&
        Assignment1_V6_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  if (!Assignment1_V6_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_b.isInitialized == 1) &&
        Assignment1_V6_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  if (!Assignment1_V6_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_m.isInitialized == 1) &&
        Assignment1_V6_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  if (!Assignment1_V6_DW.obj_e.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_e.isInitialized == 1) &&
        Assignment1_V6_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write8' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V5.c
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

#include "Assignment1_V5.h"
#include "rtwtypes.h"
#include "Assignment1_V5_types.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "MW_I2C.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Assignme_IN_ECG_TX_Loop_Standby ((uint8_T)3U)
#define Assignment1_V5_IN_Conv_Data    ((uint8_T)1U)
#define Assignment1_V5_IN_Init         ((uint8_T)4U)
#define Assignment1__IN_Detect_Cur_Mode ((uint8_T)2U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1__IN_Save_Buf_Params ((uint8_T)5U)

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Assignment1_V5_IN_Charge       ((uint8_T)1U)
#define Assignment1_V5_IN_PACE         ((uint8_T)1U)
#define Assignment1_V5_IN_Pace_Atr     ((uint8_T)3U)
#define Assignment1_V5_IN_Pace_Vent    ((uint8_T)4U)
#define Assignment1_V5_IN_SENSE        ((uint8_T)2U)
#define Assignment1_V5_IN_Sense_Detect ((uint8_T)1U)
#define Assignment1_V5_IN_Sense_Fail   ((uint8_T)4U)
#define Assignment1_V5_IN_Sense_Finish ((uint8_T)5U)
#define Assignment1_V5_IN_Sense_Wait   ((uint8_T)6U)
#define Assignment1_V5_event_pace_compl (0)
#define Assignment1_V_IN_Discharge_Prep ((uint8_T)2U)
#define Assignment1_V_IN_Sense_Detected ((uint8_T)2U)
#define Assignment1_V_IN_Sense_Disabled ((uint8_T)3U)
#define Assignment1_event_sense_timeout (1)

/* Block signals (default storage) */
B_Assignment1_V5_T Assignment1_V5_B;

/* Block states (default storage) */
DW_Assignment1_V5_T Assignment1_V5_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V5_T Assignment1_V5_M_;
RT_MODEL_Assignment1_V5_T *const Assignment1_V5_M = &Assignment1_V5_M_;

/* Forward declaration for local functions */
static void Assignment1_V5_Process_Rx(uint8_T output_set[15]);
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment1_enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
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

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V5_DW.sfEvent;
  Assignment1_V5_DW.sfEvent = Assignment1_V5_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V5();
  Assignment1_V5_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_enter_atomic_Charge(void)
{
  Assignment1_V5_B.PACE_GND_CTRL = true;
  if (Assignment1_V5_B.Cast7 == Atrium) {
    Assignment1_V5_B.ATR_GND_CTRL = true;
    Assignment1_V5_B.VENT_GND_CTRL = false;
  } else {
    Assignment1_V5_B.ATR_GND_CTRL = false;
    Assignment1_V5_B.VENT_GND_CTRL = true;
  }

  Assignment1_V5_B.ATR_PACE_CTRL = false;
  Assignment1_V5_B.VENT_PACE_CTRL = false;
  Assignment1_V5_B.PACING_REF_PWM = Assignment1_V5_B.Gain2[(int32_T)
    Assignment1_V5_B.Cast7 - 1];
  Assignment1_V5_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V5_DW.sfEvent;
  Assignment1_V5_DW.sfEvent = Assignment1_event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V5();
  Assignment1_V5_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  Assignment1_V5_B.red = 0.0;
  Assignment1_V5_B.green = 0.0;
  Assignment1_V5_B.blue = 0.0;
  printf("%s\n", "HELLO");
  fflush(stdout);
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment1_V_c3_Assignment1_V5(void)
{
  boolean_T guard1 = false;

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V5_DW.is_active_c3_Assignment1_V5 == 0U) {
    Assignment1_V5_DW.is_active_c3_Assignment1_V5 = 1U;
    Assignment1_V5_DW.is_c3_Assignment1_V5 = Assignment1_V5_IN_SENSE;
    Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Finish;
  } else {
    guard1 = false;
    switch (Assignment1_V5_DW.is_c3_Assignment1_V5) {
     case Assignment1_V5_IN_PACE:
      if (Assignment1_V5_DW.sfEvent == Assignment1_V5_event_pace_compl) {
        Assignment1_V5_DW.is_PACE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V5_DW.is_c3_Assignment1_V5 = Assignment1_V5_IN_SENSE;
        Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Finish;
      } else {
        switch (Assignment1_V5_DW.is_PACE) {
         case Assignment1_V5_IN_Charge:
          Assignment1_V5_B.PACE_GND_CTRL = true;
          if (Assignment1_V5_B.Cast7 == Atrium) {
            Assignment1_V5_B.ATR_GND_CTRL = true;
            Assignment1_V5_B.VENT_GND_CTRL = false;
          } else {
            Assignment1_V5_B.ATR_GND_CTRL = false;
            Assignment1_V5_B.VENT_GND_CTRL = true;
          }

          Assignment1_V5_B.ATR_PACE_CTRL = false;
          Assignment1_V5_B.VENT_PACE_CTRL = false;
          Assignment1_V5_B.PACING_REF_PWM = Assignment1_V5_B.Gain2[(int32_T)
            Assignment1_V5_B.Cast7 - 1];
          Assignment1_V5_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment1_V_IN_Discharge_Prep:
          switch (Assignment1_V5_B.Cast7) {
           case Atrium:
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Pace_Atr;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
            Assignment1_V5_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Pace_Vent;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
            Assignment1_V5_B.VENT_PACE_CTRL = true;
            break;

           default:
            Assignment1_V5_B.PACING_REF_PWM = 0.0F;
            Assignment1_V5_B.PACE_CHARGE_CTRL = false;
            Assignment1_V5_B.PACE_GND_CTRL = true;
            Assignment1_V5_B.ATR_GND_CTRL = false;
            Assignment1_V5_B.VENT_GND_CTRL = false;
            break;
          }
          break;

         case Assignment1_V5_IN_Pace_Atr:
          if (Assignment1_V5_DW.temporalCounter_i1 >=
              Assignment1_V5_B.VectorConcatenate1[(int32_T)
              Assignment1_V5_B.Cast7 - 1]) {
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V5_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V5_IN_Pace_Vent:
          if (Assignment1_V5_DW.temporalCounter_i1 >=
              Assignment1_V5_B.VectorConcatenate1[(int32_T)
              Assignment1_V5_B.Cast7 - 1]) {
            Assignment1_V5_DW.is_PACE = Assignment1_V5_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V5_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment1_V5_IN_SENSE:
      if (Assignment1_V5_DW.sfEvent == Assignment1_event_sense_timeout) {
        Assignment1_V5_DW.tp_Sense_Detect = 0U;
        Assignment1_V5_DW.tp_Sense_Detected = 0U;
        Assignment1_V5_DW.tp_Sense_Fail = 0U;
        Assignment1_V5_DW.is_SENSE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V5_DW.is_c3_Assignment1_V5 = Assignment1_V5_IN_PACE;
        Assignment1_V5_DW.is_PACE = Assignment1_V_IN_Discharge_Prep;
        Assignment1_V5_B.PACING_REF_PWM = 0.0F;
        Assignment1_V5_B.PACE_CHARGE_CTRL = false;
        Assignment1_V5_B.PACE_GND_CTRL = true;
        Assignment1_V5_B.ATR_GND_CTRL = false;
        Assignment1_V5_B.VENT_GND_CTRL = false;
      } else {
        switch (Assignment1_V5_DW.is_SENSE) {
         case Assignment1_V5_IN_Sense_Detect:
          if (Assignment1_V5_B.Cast9 == Nothing) {
            guard1 = true;
          } else if (Assignment1_V5_B.VectorConcatenate[(int32_T)
                     Assignment1_V5_B.Cast8 - 1]) {
            Assignment1_V5_DW.tp_Sense_Detect = 0U;
            Assignment1_V5_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
            Assignment1_V5_DW.tp_Sense_Detected = 1U;
            Assignment1_V5_B.red = 0.0;
            Assignment1_V5_B.green = 0.0;
            Assignment1_V5_B.blue = 0.0;
          } else if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
                     (Assignment1_V5_B.sense_timeout_threshold -
                      Assignment1_V5_B.VectorConcatenate2[(int32_T)
                      Assignment1_V5_B.Cast8 - 1])) {
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
          Assignment1_V5_B.red = 1.0;
          Assignment1_V5_B.green = 0.0;
          Assignment1_V5_B.blue = 0.0;
          break;

         case Assignment1_V_IN_Sense_Disabled:
          if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V5_B.sense_timeout_threshold)) {
            Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Fail;
            Assignment1_V5_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          }
          break;

         case Assignment1_V5_IN_Sense_Fail:
          Assignment1_V5_B.red = 0.0;
          Assignment1_V5_B.green = 0.0;
          Assignment1_V5_B.blue = 0.0;
          printf("%s\n", "HELLO");
          fflush(stdout);
          broadcast_sense_timeout_c3_Assi();
          break;

         case Assignment1_V5_IN_Sense_Finish:
          if (Assignment1_V5_B.Cast9 != Nothing) {
            Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Wait;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
            Assignment1_V5_B.red = 1.0;
            Assignment1_V5_B.green = 0.0;
            Assignment1_V5_B.blue = 0.0;
          } else {
            Assignment1_V5_DW.is_SENSE = Assignment1_V_IN_Sense_Disabled;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Assignment1_V5_IN_Sense_Wait:
          if (Assignment1_V5_B.Cast9 == Nothing) {
            Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Fail;
            Assignment1_V5_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment1_V5_DW.temporalCounter_i1 >= (uint32_T)ceil
                     (Assignment1_V5_B.VectorConcatenate2[(int32_T)
                      Assignment1_V5_B.Cast8 - 1])) {
            Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Detect;
            Assignment1_V5_DW.temporalCounter_i1 = 0U;
            Assignment1_V5_DW.tp_Sense_Detect = 1U;
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
      }
      break;
    }

    if (guard1) {
      Assignment1_V5_DW.tp_Sense_Detect = 0U;
      Assignment1_V5_DW.is_SENSE = Assignment1_V5_IN_Sense_Fail;
      Assignment1_V5_DW.tp_Sense_Fail = 1U;
      Assignm_enter_atomic_Sense_Fail();
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
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  int32_T bitIdx;
  int32_T bitIdx_0;
  int32_T intVal;
  int32_T j;
  uint32_T u;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T rtb_BittoIntegerConverter1[4];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T Rx_buf;

  /* Chart: '<Root>/Chart' */
  if (Assignment1_V5_DW.temporalCounter_i1_n < 31U) {
    Assignment1_V5_DW.temporalCounter_i1_n++;
  }

  if (Assignment1_V5_DW.is_active_c7_Assignment1_V5 == 0U) {
    Assignment1_V5_DW.is_active_c7_Assignment1_V5 = 1U;
    Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1_V5_IN_Init;
  } else {
    switch (Assignment1_V5_DW.is_c7_Assignment1_V5) {
     case Assignment1_V5_IN_Conv_Data:
      break;

     case Assignment1__IN_Detect_Cur_Mode:
      if ((Assignment1_V5_DW.Op_Mode != 255) && (Assignment1_V5_DW.Op_Mode !=
           254)) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V5_DW.temporalCounter_i1_n = 0U;
      } else if (Assignment1_V5_DW.Op_Mode == 255) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1__IN_Save_Buf_Params;
        Assignment1_V5_DW.temporalCounter_i1_n = 0U;
      } else {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1_V5_IN_Conv_Data;
        Assignment1_V5_Process_Rx(Assignment1_V5_DW.Output_Candidate);
      }
      break;

     case Assignme_IN_ECG_TX_Loop_Standby:
      if (Assignment1_V5_DW.temporalCounter_i1_n >= 10U) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V5_DW.temporalCounter_i1_n = 0U;
      } else {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignment1__IN_Detect_Cur_Mode;
        Rx_buf = 0U;
        memcpy((void *)&Assignment1_V5_DW.Op_Mode, (void *)&Rx_buf, (size_t)1 *
               sizeof(uint8_T));
      }
      break;

     case Assignment1_V5_IN_Init:
      Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
      Assignment1_V5_DW.temporalCounter_i1_n = 0U;
      break;

     default:
      /* case IN_Save_Buf_Params: */
      if (Assignment1_V5_DW.temporalCounter_i1_n >= 20U) {
        Assignment1_V5_DW.is_c7_Assignment1_V5 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V5_DW.temporalCounter_i1_n = 0U;
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
  for (bitIdx = 0; bitIdx < 15; bitIdx++) {
    Assignment1_V5_B.VectorConcatenate1_m[bitIdx] *= Assignment1_V5_P.Gain_Gain;
  }

  /* End of Gain: '<Root>/Gain' */

  /* SignalConversion generated from: '<S18>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate2'
   */
  Assignment1_V5_B.VectorConcatenate2[0] =
    Assignment1_V5_B.VectorConcatenate1_m[10];

  /* SignalConversion generated from: '<S18>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate2'
   */
  Assignment1_V5_B.VectorConcatenate2[1] =
    Assignment1_V5_B.VectorConcatenate1_m[11];

  /* S-Function (scominttobit): '<S18>/Integer to Bit Converter' */
  /* Integer to Bit Conversion */
  bitIdx = 8;
  u = (uint32_T)Assignment1_V5_B.VectorConcatenate1_m[0];
  for (j = 0; j < 8; j++) {
    Assignment1_V5_B.IntegertoBitConverter[bitIdx - 1] = (uint8_T)(u & 1U);
    u >>= 1U;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S18>/Integer to Bit Converter' */

  /* S-Function (scominttobit): '<S18>/Bit to Integer Converter1' */
  /* Bit to Integer Conversion */
  bitIdx = 0;
  for (j = 0; j < 4; j++) {
    /* Input bit order is MSB first */
    intVal = Assignment1_V5_B.IntegertoBitConverter[bitIdx];
    bitIdx_0 = bitIdx + 1;

    /* Input bit order is MSB first */
    bitIdx += 2;
    rtb_BittoIntegerConverter1[j] = (uint8_T)((uint32_T)intVal << 1U |
      Assignment1_V5_B.IntegertoBitConverter[bitIdx_0]);
  }

  /* End of S-Function (scominttobit): '<S18>/Bit to Integer Converter1' */

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

  rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)(b_RegisterValue[0] >> 2) *
    2.0 * 0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_RegisterValue[1] >> 2) *
    2.0 * 0.244 / 1000.0;
  Assignment1_V5_B.rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)
    (b_RegisterValue[2] >> 2) * 2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor' */

  /* Gain: '<S18>/Gain16' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   *  DataTypeConversion: '<S18>/Cast'
   */
  Assignment1_V5_B.Gain2[0] = Assignment1_V5_P.Gain16_Gain * (real32_T)
    Assignment1_V5_B.VectorConcatenate1_m[4];

  /* Gain: '<S18>/Gain15' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   *  DataTypeConversion: '<S18>/Cast1'
   */
  Assignment1_V5_B.Gain2[1] = Assignment1_V5_P.Gain15_Gain * (real32_T)
    Assignment1_V5_B.VectorConcatenate1_m[7];

  /* Gain: '<S18>/Gain2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V5_B.Gain2[0] *= Assignment1_V5_P.Gain2_Gain;
  Assignment1_V5_B.Gain2[1] *= Assignment1_V5_P.Gain2_Gain;

  /* Gain: '<S18>/Gain7' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate1'
   *  DataTypeConversion: '<S18>/Cast4'
   */
  Assignment1_V5_B.VectorConcatenate1[0] = Assignment1_V5_P.Gain7_Gain *
    (real32_T)Assignment1_V5_B.VectorConcatenate1_m[5];

  /* Gain: '<S18>/Gain8' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate1'
   *  DataTypeConversion: '<S18>/Cast5'
   */
  Assignment1_V5_B.VectorConcatenate1[1] = Assignment1_V5_P.Gain8_Gain *
    (real32_T)Assignment1_V5_B.VectorConcatenate1_m[8];

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

  /* DataTypeConversion: '<S18>/Cast7' */
  Assignment1_V5_B.Cast7 = (Pace_Chamber)rtb_BittoIntegerConverter1[0];

  /* DataTypeConversion: '<S18>/Cast8' */
  Assignment1_V5_B.Cast8 = (Pace_Sense_Chamber)rtb_BittoIntegerConverter1[1];

  /* MATLAB Function: '<S13>/MATLAB Function2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  MATLABSystem: '<S2>/FXOS8700 6-Axes Sensor'
   */
  if (Assignment1_V5_DW.init_counter < Assignment1_V5_P.Constant1_Value_n) {
    Assignment1_V5_DW.init_counter++;
  }

  Assignment1_V5_DW.rolling_avg = sqrt((rtb_FXOS87006AxesSensor_idx_0 *
    rtb_FXOS87006AxesSensor_idx_0 + rtb_FXOS87006AxesSensor_idx_1 *
    rtb_FXOS87006AxesSensor_idx_1) +
    Assignment1_V5_B.rtb_FXOS87006AxesSensor_idx_2 *
    Assignment1_V5_B.rtb_FXOS87006AxesSensor_idx_2) /
    Assignment1_V5_DW.init_counter + (Assignment1_V5_DW.init_counter - 1.0) *
    Assignment1_V5_DW.rolling_avg / Assignment1_V5_DW.init_counter;

  /* End of MATLAB Function: '<S13>/MATLAB Function2' */

  /* Chart: '<S6>/RATE_CTRL_SYSTEM' incorporates:
   *  Gain: '<S18>/Multiply'
   *  Product: '<S18>/Reciprocal'
   */
  if (Assignment1_V5_DW.is_active_c9_Assignment1_V5 == 0U) {
    Assignment1_V5_DW.is_active_c9_Assignment1_V5 = 1U;
    Assignment1_V5_B.sense_timeout_threshold = 1.0 /
      Assignment1_V5_B.VectorConcatenate1_m[1] * Assignment1_V5_P.Multiply_Gain;
  } else {
    Assignment1_V5_B.sense_timeout_threshold = 1.0 /
      Assignment1_V5_B.VectorConcatenate1_m[1] * Assignment1_V5_P.Multiply_Gain;
  }

  /* End of Chart: '<S6>/RATE_CTRL_SYSTEM' */

  /* DataTypeConversion: '<S18>/Cast9' */
  Assignment1_V5_B.Cast9 = (Pace_Sense_Response)rtb_BittoIntegerConverter1[2];

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V5_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V5_DW.temporalCounter_i1++;
  }

  Assignment1_V5_DW.sfEvent = -1;
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
  MW_PWM_SetDutyCycle(Assignment1_V5_DW.obj_evb.MW_PWM_HANDLE, (real_T)
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

  /* MATLABSystem: '<S4>/PWM Output1' incorporates:
   *  DataTypeConversion: '<S18>/Cast3'
   *  Gain: '<S18>/Gain1'
   *  Gain: '<S18>/Gain6'
   */
  MW_PWM_SetDutyCycle(Assignment1_V5_DW.obj_j.MW_PWM_HANDLE, (real_T)
                      (Assignment1_V5_P.Gain1_Gain *
                       (Assignment1_V5_P.Gain6_Gain * (real32_T)
                        Assignment1_V5_B.VectorConcatenate1_m[9])));

  /* MATLABSystem: '<S4>/PWM Output' incorporates:
   *  DataTypeConversion: '<S18>/Cast2'
   *  Gain: '<S18>/Gain'
   *  Gain: '<S18>/Gain3'
   */
  MW_PWM_SetDutyCycle(Assignment1_V5_DW.obj_nl.MW_PWM_HANDLE, (real_T)
                      (Assignment1_V5_P.Gain_Gain_k2 *
                       (Assignment1_V5_P.Gain3_Gain * (real32_T)
                        Assignment1_V5_B.VectorConcatenate1_m[6])));

  /* MATLABSystem: '<S4>/Analog Input' */
  if (Assignment1_V5_DW.obj_n.SampleTime !=
      Assignment1_V5_P.AnalogInput_SampleTime) {
    Assignment1_V5_DW.obj_n.SampleTime = Assignment1_V5_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V5_DW.obj_n.MW_ANALOGIN_HANDLE,
    &rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S4>/Analog Input' */

  /* MATLABSystem: '<S4>/Analog Input1' */
  if (Assignment1_V5_DW.obj_i.SampleTime !=
      Assignment1_V5_P.AnalogInput1_SampleTime) {
    Assignment1_V5_DW.obj_i.SampleTime =
      Assignment1_V5_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V5_DW.obj_i.MW_ANALOGIN_HANDLE,
    &rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S4>/Analog Input1' */

  /* MATLABSystem: '<S4>/Digital Write1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  MW_digitalIO_write(Assignment1_V5_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment1_V5_P.Constant_Value_k != 0.0);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_l.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(Assignment1_V5_DW.obj_e.MW_DIGITALIO_HANDLE, false);
}

/* Model initialize function */
void Assignment1_V5_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    Assignment1_V5_B.Cast7 = Atrium;
  }

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    freedomk64f_AnalogInput_Assig_T *obj_2;
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment1_V5_DW.sfEvent = -1;

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

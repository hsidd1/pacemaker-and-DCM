/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_1_Simulink.c
 *
 * Code generated for Simulink model 'Assignment_1_Simulink'.
 *
 * Model version                  : 2.48
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Oct 15 04:22:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment_1_Simulink.h"
#include "rtwtypes.h"
#include "Assignment_1_Simulink_types.h"
#include "Assignment_1_Simulink_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Assignment_1_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment_1_S_event_pace_compl (0)
#define Assignment_1_Si_IN_Sense_Detect ((uint8_T)1U)
#define Assignment_1_Si_IN_Sense_Finish ((uint8_T)5U)
#define Assignment_1_Simu_IN_Sense_Fail ((uint8_T)4U)
#define Assignment_1_Simu_IN_Sense_Wait ((uint8_T)6U)
#define Assignment_1_Simul_IN_Pace_Vent ((uint8_T)4U)
#define Assignment_1_Simuli_IN_Pace_Atr ((uint8_T)3U)
#define Assignment_1_Simulin_CALL_EVENT (-1)
#define Assignment_1_Simulink_IN_Charge ((uint8_T)1U)
#define Assignment_1_Simulink_IN_PACE  ((uint8_T)1U)
#define Assignment_1_Simulink_IN_SENSE ((uint8_T)2U)
#define Assignment_1__IN_Discharge_Prep ((uint8_T)2U)
#define Assignment_1__IN_Sense_Detected ((uint8_T)2U)
#define Assignment_1__IN_Sense_Disabled ((uint8_T)3U)
#define Assignment__event_sense_timeout (1)

/* Block signals (default storage) */
B_Assignment_1_Simulink_T Assignment_1_Simulink_B;

/* Block states (default storage) */
DW_Assignment_1_Simulink_T Assignment_1_Simulink_DW;

/* Real-time model */
static RT_MODEL_Assignment_1_Simulin_T Assignment_1_Simulink_M_;
RT_MODEL_Assignment_1_Simulin_T *const Assignment_1_Simulink_M =
  &Assignment_1_Simulink_M_;

/* Forward declaration for local functions */
static real_T Assignment_1_Simulink_mod(real_T x, real_T y);
static Pace_Chamber As_convert_to_enum_Pace_Chamber(int32_T input);
static Pace_Sense_Chamber convert_to_enum_Pace_Sense_Cham(int32_T input);
static Pace_Sense_Response convert_to_enum_Pace_Sense_Resp(int32_T input);
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment__enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
static void Assign_c3_Assignment_1_Simulink(void);

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static real_T Assignment_1_Simulink_mod(real_T x, real_T y)
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

  /* Initialize output value to default value for Pace_Sense_Chamber (Atrium_Sense) */
  output = Atrium_Sense;
  if ((input >= 1) && (input <= 3)) {
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
  b_previousEvent = Assignment_1_Simulink_DW.sfEvent;
  Assignment_1_Simulink_DW.sfEvent = Assignment_1_S_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assign_c3_Assignment_1_Simulink();
  Assignment_1_Simulink_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignment__enter_atomic_Charge(void)
{
  Assignment_1_Simulink_B.PACE_GND_CTRL = true;
  if (Assignment_1_Simulink_B.PACE_CHAMBER == Atrium) {
    Assignment_1_Simulink_B.ATR_GND_CTRL = true;
    Assignment_1_Simulink_B.VENT_GND_CTRL = false;
  } else {
    Assignment_1_Simulink_B.ATR_GND_CTRL = false;
    Assignment_1_Simulink_B.VENT_GND_CTRL = true;
  }

  Assignment_1_Simulink_B.ATR_PACE_CTRL = false;
  Assignment_1_Simulink_B.VENT_PACE_CTRL = false;
  Assignment_1_Simulink_B.PACING_REF_PWM = Assignment_1_Simulink_B.Gain2
    [(int32_T)Assignment_1_Simulink_B.PACE_CHAMBER - 1];
  Assignment_1_Simulink_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment_1_Simulink_DW.sfEvent;
  Assignment_1_Simulink_DW.sfEvent = Assignment__event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assign_c3_Assignment_1_Simulink();
  Assignment_1_Simulink_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void Assign_c3_Assignment_1_Simulink(void)
{
  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment_1_Simulink_DW.is_active_c3_Assignment_1_Simul == 0U) {
    Assignment_1_Simulink_DW.is_active_c3_Assignment_1_Simul = 1U;
    Assignment_1_Simulink_DW.is_c3_Assignment_1_Simulink =
      Assignment_1_Simulink_IN_SENSE;
    Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Si_IN_Sense_Finish;
  } else {
    switch (Assignment_1_Simulink_DW.is_c3_Assignment_1_Simulink) {
     case Assignment_1_Simulink_IN_PACE:
      if (Assignment_1_Simulink_DW.sfEvent == Assignment_1_S_event_pace_compl) {
        Assignment_1_Simulink_DW.is_PACE = Assignment_1_IN_NO_ACTIVE_CHILD;
        Assignment_1_Simulink_DW.is_c3_Assignment_1_Simulink =
          Assignment_1_Simulink_IN_SENSE;
        Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Si_IN_Sense_Finish;
      } else {
        switch (Assignment_1_Simulink_DW.is_PACE) {
         case Assignment_1_Simulink_IN_Charge:
          Assignment_1_Simulink_B.PACE_GND_CTRL = true;
          if (Assignment_1_Simulink_B.PACE_CHAMBER == Atrium) {
            Assignment_1_Simulink_B.ATR_GND_CTRL = true;
            Assignment_1_Simulink_B.VENT_GND_CTRL = false;
          } else {
            Assignment_1_Simulink_B.ATR_GND_CTRL = false;
            Assignment_1_Simulink_B.VENT_GND_CTRL = true;
          }

          Assignment_1_Simulink_B.ATR_PACE_CTRL = false;
          Assignment_1_Simulink_B.VENT_PACE_CTRL = false;
          Assignment_1_Simulink_B.PACING_REF_PWM =
            Assignment_1_Simulink_B.Gain2[(int32_T)
            Assignment_1_Simulink_B.PACE_CHAMBER - 1];
          Assignment_1_Simulink_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment_1__IN_Discharge_Prep:
          switch (Assignment_1_Simulink_B.PACE_CHAMBER) {
           case Atrium:
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simuli_IN_Pace_Atr;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
            Assignment_1_Simulink_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simul_IN_Pace_Vent;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
            Assignment_1_Simulink_B.VENT_PACE_CTRL = true;
            break;

           default:
            Assignment_1_Simulink_B.PACING_REF_PWM = 0.0;
            Assignment_1_Simulink_B.PACE_CHARGE_CTRL = false;
            Assignment_1_Simulink_B.PACE_GND_CTRL = true;
            Assignment_1_Simulink_B.ATR_GND_CTRL = false;
            Assignment_1_Simulink_B.VENT_GND_CTRL = false;
            break;
          }
          break;

         case Assignment_1_Simuli_IN_Pace_Atr:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_B.VectorConcatenate1[(int32_T)
               Assignment_1_Simulink_B.PACE_CHAMBER - 1])) {
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simulink_IN_Charge;
            Assignment__enter_atomic_Charge();
          } else {
            Assignment_1_Simulink_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment_1_Simul_IN_Pace_Vent:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_B.VectorConcatenate1[(int32_T)
               Assignment_1_Simulink_B.PACE_CHAMBER - 1])) {
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simulink_IN_Charge;
            Assignment__enter_atomic_Charge();
          } else {
            Assignment_1_Simulink_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment_1_Simulink_IN_SENSE:
      if (Assignment_1_Simulink_DW.sfEvent == Assignment__event_sense_timeout) {
        Assignment_1_Simulink_DW.tp_Sense_Detect = 0U;
        Assignment_1_Simulink_DW.tp_Sense_Detected = 0U;
        Assignment_1_Simulink_DW.tp_Sense_Fail = 0U;
        Assignment_1_Simulink_DW.is_SENSE = Assignment_1_IN_NO_ACTIVE_CHILD;
        Assignment_1_Simulink_DW.is_c3_Assignment_1_Simulink =
          Assignment_1_Simulink_IN_PACE;
        Assignment_1_Simulink_DW.is_PACE = Assignment_1__IN_Discharge_Prep;
        Assignment_1_Simulink_B.PACING_REF_PWM = 0.0;
        Assignment_1_Simulink_B.PACE_CHARGE_CTRL = false;
        Assignment_1_Simulink_B.PACE_GND_CTRL = true;
        Assignment_1_Simulink_B.ATR_GND_CTRL = false;
        Assignment_1_Simulink_B.VENT_GND_CTRL = false;
      } else {
        switch (Assignment_1_Simulink_DW.is_SENSE) {
         case Assignment_1_Si_IN_Sense_Detect:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_B.Multiply -
               Assignment_1_Simulink_B.VectorConcatenate2[(int32_T)
               Assignment_1_Simulink_B.PACE_SENSE_CHAMBER - 1])) {
            Assignment_1_Simulink_DW.tp_Sense_Detect = 0U;
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Fail;
            Assignment_1_Simulink_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment_1_Simulink_B.VectorConcatenate[(int32_T)
                     Assignment_1_Simulink_B.PACE_SENSE_CHAMBER - 1]) {
            Assignment_1_Simulink_DW.tp_Sense_Detect = 0U;
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1__IN_Sense_Detected;
            Assignment_1_Simulink_DW.tp_Sense_Detected = 1U;
          }
          break;

         case Assignment_1__IN_Sense_Detected:
          Assignment_1_Simulink_DW.tp_Sense_Detected = 0U;
          Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Wait;
          Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
          break;

         case Assignment_1__IN_Sense_Disabled:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_B.Multiply)) {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Fail;
            Assignment_1_Simulink_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          }
          break;

         case Assignment_1_Simu_IN_Sense_Fail:
          broadcast_sense_timeout_c3_Assi();
          break;

         case Assignment_1_Si_IN_Sense_Finish:
          if (Assignment_1_Simulink_B.PACE_SENSE_RESPONSE != Nothing) {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Wait;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
          } else {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1__IN_Sense_Disabled;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Assignment_1_Simu_IN_Sense_Wait:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_B.VectorConcatenate2[(int32_T)
               Assignment_1_Simulink_B.PACE_SENSE_CHAMBER - 1])) {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Si_IN_Sense_Detect;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
            Assignment_1_Simulink_DW.tp_Sense_Detect = 1U;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PACE_SYSTEM' */
}

/* Model step function */
void Assignment_1_Simulink_step(void)
{
  real_T PACE_CHAMBER_tmp;
  real_T PACE_SENSE_CHAMBER_tmp;

  /* SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate'
   *  Constant: '<S5>/Constant1'
   */
  Assignment_1_Simulink_B.Gain2[0] = Assignment_1_Simulink_P.Constant1_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate'
   *  Constant: '<S5>/Constant1'
   */
  Assignment_1_Simulink_B.Gain2[1] = Assignment_1_Simulink_P.Constant1_Value;

  /* Gain: '<S4>/Gain2' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate'
   */
  Assignment_1_Simulink_B.Gain2[0] *= Assignment_1_Simulink_P.Gain2_Gain;
  Assignment_1_Simulink_B.Gain2[1] *= Assignment_1_Simulink_P.Gain2_Gain;

  /* SignalConversion generated from: '<S4>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate2'
   *  Constant: '<S5>/Constant4'
   */
  Assignment_1_Simulink_B.VectorConcatenate2[0] =
    Assignment_1_Simulink_P.Constant4_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate2'
   *  Constant: '<S5>/Constant4'
   */
  Assignment_1_Simulink_B.VectorConcatenate2[1] =
    Assignment_1_Simulink_P.Constant4_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate1'
   *  Constant: '<S5>/Constant3'
   */
  Assignment_1_Simulink_B.VectorConcatenate1[0] =
    Assignment_1_Simulink_P.Constant3_Value;

  /* SignalConversion generated from: '<S4>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S4>/Vector Concatenate1'
   *  Constant: '<S5>/Constant3'
   */
  Assignment_1_Simulink_B.VectorConcatenate1[1] =
    Assignment_1_Simulink_P.Constant3_Value;

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (Assignment_1_Simulink_DW.obj.SampleTime !=
      Assignment_1_Simulink_P.DigitalRead1_SampleTime) {
    Assignment_1_Simulink_DW.obj.SampleTime =
      Assignment_1_Simulink_P.DigitalRead1_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Boolean'
   *  MATLABSystem: '<S2>/Digital Read1'
   */
  Assignment_1_Simulink_B.VectorConcatenate[0] = MW_digitalIO_read
    (Assignment_1_Simulink_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Digital Read' */
  if (Assignment_1_Simulink_DW.obj_b.SampleTime !=
      Assignment_1_Simulink_P.DigitalRead_SampleTime) {
    Assignment_1_Simulink_DW.obj_b.SampleTime =
      Assignment_1_Simulink_P.DigitalRead_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Boolean1'
   *  MATLABSystem: '<S2>/Digital Read'
   */
  Assignment_1_Simulink_B.VectorConcatenate[1] = MW_digitalIO_read
    (Assignment_1_Simulink_DW.obj_b.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   */
  PACE_CHAMBER_tmp = Assignment_1_Simulink_mod((real_T)
    Assignment_1_Simulink_P.EnumeratedConstant_Value, 1000.0);
  Assignment_1_Simulink_B.PACE_CHAMBER = As_convert_to_enum_Pace_Chamber
    ((int32_T)rt_roundd_snf((Assignment_1_Simulink_mod((real_T)
        Assignment_1_Simulink_P.EnumeratedConstant_Value, 10000.0) -
       PACE_CHAMBER_tmp) / 1000.0));
  PACE_SENSE_CHAMBER_tmp = Assignment_1_Simulink_mod((real_T)
    Assignment_1_Simulink_P.EnumeratedConstant_Value, 100.0);
  Assignment_1_Simulink_B.PACE_SENSE_CHAMBER = convert_to_enum_Pace_Sense_Cham
    ((int32_T)rt_roundd_snf((PACE_CHAMBER_tmp - PACE_SENSE_CHAMBER_tmp) / 100.0));
  Assignment_1_Simulink_B.PACE_SENSE_RESPONSE = convert_to_enum_Pace_Sense_Resp
    ((int32_T)rt_roundd_snf((PACE_SENSE_CHAMBER_tmp - Assignment_1_Simulink_mod
       ((real_T)Assignment_1_Simulink_P.EnumeratedConstant_Value, 10.0)) / 10.0));

  /* Gain: '<S4>/Multiply' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Assignment_1_Simulink_B.Multiply = Assignment_1_Simulink_P.Multiply_Gain *
    Assignment_1_Simulink_P.Constant_Value;

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment_1_Simulink_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment_1_Simulink_DW.temporalCounter_i1++;
  }

  Assignment_1_Simulink_DW.sfEvent = Assignment_1_Simulin_CALL_EVENT;
  Assign_c3_Assignment_1_Simulink();

  /* End of Chart: '<Root>/PACE_SYSTEM' */

  /* MATLABSystem: '<S1>/Digital Write' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_g.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write1' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S1>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE,
                      Assignment_1_Simulink_B.PACING_REF_PWM);

  /* MATLABSystem: '<S1>/Digital Write3' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_bo.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write4' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_n2.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S1>/Digital Write5' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S1>/Digital Write8' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write1' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Boolean2'
   *  DataTypeConversion: '<S2>/Cast To Double'
   */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_a.MW_DIGITALIO_HANDLE,
                     (int32_T)Assignment_1_Simulink_B.PACE_SENSE_RESPONSE != 0);

  /* MATLABSystem: '<S2>/PWM Output' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Gain: '<S4>/Gain'
   */
  MW_PWM_SetDutyCycle(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE,
                      Assignment_1_Simulink_P.Gain_Gain *
                      Assignment_1_Simulink_P.Constant2_Value);

  /* MATLABSystem: '<S2>/PWM Output1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Gain: '<S4>/Gain1'
   */
  MW_PWM_SetDutyCycle(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE,
                      Assignment_1_Simulink_P.Gain1_Gain *
                      Assignment_1_Simulink_P.Constant2_Value);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_m.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_i.MW_DIGITALIO_HANDLE, false);
}

/* Model initialize function */
void Assignment_1_Simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    Assignment_1_Simulink_B.PACE_SENSE_CHAMBER = Atrium_Sense;
    Assignment_1_Simulink_B.PACE_CHAMBER = Atrium;
  }

  {
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment_1_Simulink_DW.sfEvent = Assignment_1_Simulin_CALL_EVENT;

    /* Start for MATLABSystem: '<S2>/Digital Read1' */
    Assignment_1_Simulink_DW.obj.matlabCodegenIsDeleted = false;
    Assignment_1_Simulink_DW.obj.SampleTime =
      Assignment_1_Simulink_P.DigitalRead1_SampleTime;
    obj = &Assignment_1_Simulink_DW.obj;
    Assignment_1_Simulink_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment_1_Simulink_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    Assignment_1_Simulink_DW.obj_b.matlabCodegenIsDeleted = false;
    Assignment_1_Simulink_DW.obj_b.SampleTime =
      Assignment_1_Simulink_P.DigitalRead_SampleTime;
    obj = &Assignment_1_Simulink_DW.obj_b;
    Assignment_1_Simulink_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment_1_Simulink_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    Assignment_1_Simulink_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_g;
    Assignment_1_Simulink_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment_1_Simulink_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    Assignment_1_Simulink_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_h;
    Assignment_1_Simulink_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment_1_Simulink_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output' */
    Assignment_1_Simulink_DW.obj_bn.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_Simulink_DW.obj_bn;
    Assignment_1_Simulink_DW.obj_bn.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE);
    Assignment_1_Simulink_DW.obj_bn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write3' */
    Assignment_1_Simulink_DW.obj_bo.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_bo;
    Assignment_1_Simulink_DW.obj_bo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment_1_Simulink_DW.obj_bo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write4' */
    Assignment_1_Simulink_DW.obj_n2.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_n2;
    Assignment_1_Simulink_DW.obj_n2.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment_1_Simulink_DW.obj_n2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write5' */
    Assignment_1_Simulink_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_j;
    Assignment_1_Simulink_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment_1_Simulink_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write8' */
    Assignment_1_Simulink_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_n;
    Assignment_1_Simulink_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment_1_Simulink_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Assignment_1_Simulink_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_a;
    Assignment_1_Simulink_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment_1_Simulink_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Assignment_1_Simulink_DW.obj_iw.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_Simulink_DW.obj_iw;
    Assignment_1_Simulink_DW.obj_iw.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE);
    Assignment_1_Simulink_DW.obj_iw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output1' */
    Assignment_1_Simulink_DW.obj_mz.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_Simulink_DW.obj_mz;
    Assignment_1_Simulink_DW.obj_mz.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE);
    Assignment_1_Simulink_DW.obj_mz.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    Assignment_1_Simulink_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_m;
    Assignment_1_Simulink_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment_1_Simulink_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    Assignment_1_Simulink_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_i;
    Assignment_1_Simulink_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment_1_Simulink_DW.obj_i.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment_1_Simulink_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  if (!Assignment_1_Simulink_DW.obj.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  if (!Assignment_1_Simulink_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_b.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!Assignment_1_Simulink_DW.obj_g.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_g.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  if (!Assignment_1_Simulink_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_h.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S1>/PWM Output' */
  if (!Assignment_1_Simulink_DW.obj_bn.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_bn.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_bn.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_bn.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write3' */
  if (!Assignment_1_Simulink_DW.obj_bo.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_bo.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_bo.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_bo.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_bo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write4' */
  if (!Assignment_1_Simulink_DW.obj_n2.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_n2.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write5' */
  if (!Assignment_1_Simulink_DW.obj_j.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_j.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write8' */
  if (!Assignment_1_Simulink_DW.obj_n.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_n.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!Assignment_1_Simulink_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_a.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  if (!Assignment_1_Simulink_DW.obj_iw.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_iw.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_iw.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_iw.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output1' */
  if (!Assignment_1_Simulink_DW.obj_mz.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_mz.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_mz.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_mz.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  if (!Assignment_1_Simulink_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_m.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  if (!Assignment_1_Simulink_DW.obj_i.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_i.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

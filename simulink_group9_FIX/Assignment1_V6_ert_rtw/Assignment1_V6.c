/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V6.c
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
#include "rtwtypes.h"
#include "Assignment1_V6_types.h"
#include "Assignment1_V6_private.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "MW_I2C.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Assignme_IN_ECG_TX_Loop_Standby ((uint8_T)3U)
#define Assignment1_V6_IN_Conv_Data    ((uint8_T)1U)
#define Assignment1_V6_IN_Init         ((uint8_T)4U)
#define Assignment1_V6_IN_TX_Rxint_buf ((uint8_T)6U)
#define Assignment1_V6_IN_TX_wait      ((uint8_T)7U)
#define Assignment1__IN_Detect_Cur_Mode ((uint8_T)2U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1__IN_Save_Buf_Params ((uint8_T)5U)

/* Named constants for Chart: '<S8>/RATE_CTRL_SYSTEM' */
#define Assignment1_V6_IN_Bigger       ((uint8_T)1U)
#define Assignment1_V6_IN_Detect_Mode  ((uint8_T)1U)
#define Assignment1_V6_IN_Init_b       ((uint8_T)2U)
#define Assignment1_V6_IN_Smaller      ((uint8_T)2U)
#define Assignment1_V6_IN_check_dif    ((uint8_T)3U)
#define Assignment1_V6_IN_get_tgt      ((uint8_T)4U)
#define Assignment1_V_IN_Pace_LRL_Fixed ((uint8_T)3U)
#define Assignment_IN_Pace_Rate_Unfixed ((uint8_T)4U)

/* Named constants for Chart: '<S9>/PACE_SYSTEM' */
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
#define Assignment1_event_sense_timeout (1)

/* Block signals (default storage) */
B_Assignment1_V6_T Assignment1_V6_B;

/* Block states (default storage) */
DW_Assignment1_V6_T Assignment1_V6_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V6_T Assignment1_V6_M_;
RT_MODEL_Assignment1_V6_T *const Assignment1_V6_M = &Assignment1_V6_M_;

/* Forward declaration for local functions */
static void Assignment1_V6_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj);

/* Forward declaration for local functions */
static void Assignment1_V6_Process_Rx(const uint8_T Rx_input[15], uint8_T
  output_set[15]);
static real32_T Assignment1__Calc_Rate_Response(real_T activity, const real_T
  ratefactors[2], uint16_T LRP, uint16_T MSP);
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment1_enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
static void Assignment1_V_c3_Assignment1_V6(void);
static void Assignment1__SystemCore_setup_a(freedomk64f_fxos8700_Assignme_T *obj);
static void Assignment1_SystemCore_setup_ai(freedomk64f_SCIRead_Assignmen_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Assignment1_V6_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Assignment1_V6_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Assignment1_V6_M->Timing.TaskCounters.TID[1])++;
  if ((Assignment1_V6_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.002s, 0.0s] */
    Assignment1_V6_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void Assignment1_V6_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for function-call system: '<Root>/HARDWARE_TX_INTERFACE' */
void HARDWARE_TX_INTERFACE_Init(DW_HARDWARE_TX_INTERFACE_Assi_T *localDW)
{
  /* Start for MATLABSystem: '<S6>/Serial Transmit' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  Assignment1_V6_SystemCore_setup(&localDW->obj);
}

/* Output and update for function-call system: '<Root>/HARDWARE_TX_INTERFACE' */
void Assig_HARDWARE_TX_INTERFACE(uint8_T rtu_TX_CTRL_MODE, const uint8_T
  rtu_PARAMS[4], int16_T rtu_ATR_SIGNAL, int16_T rtu_VENT_SIGNAL,
  B_HARDWARE_TX_INTERFACE_Assig_T *localB, DW_HARDWARE_TX_INTERFACE_Assi_T
  *localDW, P_HARDWARE_TX_INTERFACE_Assig_T *localP)
{
  uint8_T TxDataLocChar[4];
  uint8_T rtb_Switch_j[4];
  uint8_T status;

  /* S-Function (any2byte): '<S6>/Byte Pack' */

  /* Pack: <S6>/Byte Pack */
  (void) memcpy(&localB->BytePack[0], &rtu_ATR_SIGNAL,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack1' */

  /* Pack: <S6>/Byte Pack1 */
  (void) memcpy(&localB->BytePack1[0], &rtu_VENT_SIGNAL,
                2);

  /* Switch: '<S6>/Switch' */
  if (rtu_TX_CTRL_MODE >= localP->Switch_Threshold) {
    rtb_Switch_j[0] = localB->BytePack[0];
    rtb_Switch_j[2] = localB->BytePack1[0];
    rtb_Switch_j[1] = localB->BytePack[1];
    rtb_Switch_j[3] = localB->BytePack1[1];
  } else {
    rtb_Switch_j[0] = rtu_PARAMS[0];
    rtb_Switch_j[2] = rtu_PARAMS[2];
    rtb_Switch_j[1] = rtu_PARAMS[1];
    rtb_Switch_j[3] = rtu_PARAMS[3];
  }

  /* End of Switch: '<S6>/Switch' */

  /* MATLABSystem: '<S6>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_Switch_j[0], (size_t)4 *
           sizeof(uint8_T));
    status = MW_SCI_Transmit(localDW->obj.MW_SCIHANDLE, &TxDataLocChar[0], 4U);
  }

  /* End of MATLABSystem: '<S6>/Serial Transmit' */
}

/* Termination for function-call system: '<Root>/HARDWARE_TX_INTERFACE' */
void HARDWARE_TX_INTERFACE_Term(DW_HARDWARE_TX_INTERFACE_Assi_T *localDW)
{
  /* Terminate for MATLABSystem: '<S6>/Serial Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_SCI_Close(localDW->obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Serial Transmit' */
}

/* System initialize for Simulink Function: '<S8>/RESP_EXP_FAC_CALC' */
void Assignm_UPDATE_EXP_FAC_Init(void)
{
  int32_T i;
  for (i = 0; i < 6; i++) {
    /* SystemInitialize for DataTypeConversion: '<S15>/Cast To Double2' incorporates:
     *  Outport: '<S15>/rate_response_fac'
     */
    Assignment1_V6_B.CastToDouble2[i] = Assignment1_V6_P.rate_response_fac_Y0;
  }
}

/* Output and update for Simulink Function: '<S8>/RESP_EXP_FAC_CALC' */
void Assignment1__UPDATE_EXP_FAC(void)
{
  real_T rtb_Gain1;
  real_T rtb_Gain1_f;
  real_T rtb_Power1_c;

  /* Gain: '<S15>/Gain' incorporates:
   *  Product: '<S15>/Reciprocal'
   *  SignalConversion generated from: '<S15>/response_time_ms'
   */
  rtb_Gain1 = 1.0 / (real_T)Assignment1_V6_B.Gain4 * Assignment1_V6_P.Gain_Gain;

  /* Gain: '<S15>/Gain1' incorporates:
   *  Gain: '<S12>/Gain5'
   *  Product: '<S15>/Reciprocal1'
   *  SignalConversion generated from: '<S15>/recovery_time_ms'
   */
  rtb_Gain1_f = 1.0 / (real_T)Assignment1_V6_B.Gain5 *
    Assignment1_V6_P.Gain1_Gain;

  /* Product: '<S15>/Matrix Multiply' incorporates:
   *  Constant: '<S15>/Constant'
   *  SignalConversion generated from: '<S15>/p_response_factor'
   */
  rtb_Power1_c = Assignment1_V6_P.Constant_Value[0] * (real_T)
    Assignment1_V6_B.Params_Arr[13];

  /* DataTypeConversion: '<S15>/Cast To Double2' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Math: '<S15>/Power'
   *  Math: '<S15>/Power1'
   *  Sum: '<S15>/Subtract'
   */
  Assignment1_V6_B.CastToDouble2[0] = pow(rtb_Power1_c, rtb_Gain1) -
    Assignment1_V6_P.Constant1_Value;
  Assignment1_V6_B.CastToDouble2[3] = pow(rtb_Power1_c, rtb_Gain1_f) -
    Assignment1_V6_P.Constant1_Value;

  /* Product: '<S15>/Matrix Multiply' incorporates:
   *  Constant: '<S15>/Constant'
   *  SignalConversion generated from: '<S15>/p_response_factor'
   */
  rtb_Power1_c = Assignment1_V6_P.Constant_Value[1] * (real_T)
    Assignment1_V6_B.Params_Arr[13];

  /* DataTypeConversion: '<S15>/Cast To Double2' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Math: '<S15>/Power'
   *  Math: '<S15>/Power1'
   *  Sum: '<S15>/Subtract'
   */
  Assignment1_V6_B.CastToDouble2[1] = pow(rtb_Power1_c, rtb_Gain1) -
    Assignment1_V6_P.Constant1_Value;
  Assignment1_V6_B.CastToDouble2[4] = pow(rtb_Power1_c, rtb_Gain1_f) -
    Assignment1_V6_P.Constant1_Value;

  /* Product: '<S15>/Matrix Multiply' incorporates:
   *  Constant: '<S15>/Constant'
   *  SignalConversion generated from: '<S15>/p_response_factor'
   */
  rtb_Power1_c = Assignment1_V6_P.Constant_Value[2] * (real_T)
    Assignment1_V6_B.Params_Arr[13];

  /* DataTypeConversion: '<S15>/Cast To Double2' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Math: '<S15>/Power'
   *  Math: '<S15>/Power1'
   *  Sum: '<S15>/Subtract'
   */
  Assignment1_V6_B.CastToDouble2[2] = pow(rtb_Power1_c, rtb_Gain1) -
    Assignment1_V6_P.Constant1_Value;
  Assignment1_V6_B.CastToDouble2[5] = pow(rtb_Power1_c, rtb_Gain1_f) -
    Assignment1_V6_P.Constant1_Value;
}

/* Function for Chart: '<Root>/Chart' */
static void Assignment1_V6_Process_Rx(const uint8_T Rx_input[15], uint8_T
  output_set[15])
{
  int32_T i;
  uint8_T tmp;
  for (i = 0; i < 15; i++) {
    memcpy((void *)&tmp, (void *)&Rx_input[i], (size_t)1 * sizeof(uint8_T));
    output_set[i] = tmp;
  }
}

/* Function for Chart: '<S8>/RATE_CTRL_SYSTEM' */
static real32_T Assignment1__Calc_Rate_Response(real_T activity, const real_T
  ratefactors[2], uint16_T LRP, uint16_T MSP)
{
  real32_T value;
  value = (real32_T)(ratefactors[0] * activity + ratefactors[1]);
  if ((value == 0.0F) || (value < 0.0F)) {
    value = LRP;
  } else {
    value = 60000.0F / value;
    if (value > LRP) {
      value = LRP;
    } else if (value < MSP) {
      value = MSP;
    }
  }

  return value;
}

/* Function for Chart: '<S9>/PACE_SYSTEM' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V6_DW.sfEvent;
  Assignment1_V6_DW.sfEvent = Assignment1_V6_event_pace_compl;

  /* Chart: '<S9>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V6();
  Assignment1_V6_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<S9>/PACE_SYSTEM' */
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

/* Function for Chart: '<S9>/PACE_SYSTEM' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V6_DW.sfEvent;
  Assignment1_V6_DW.sfEvent = Assignment1_event_sense_timeout;

  /* Chart: '<S9>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V6();
  Assignment1_V6_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<S9>/PACE_SYSTEM' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<S9>/PACE_SYSTEM' */
static void Assignment1_V_c3_Assignment1_V6(void)
{
  /* Chart: '<S9>/PACE_SYSTEM' */
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
          if ((Assignment1_V6_DW.temporalCounter_i1 << 1) >=
              Assignment1_V6_B.VectorConcatenate1[(int32_T)
              Assignment1_V6_B.Cast7 - 1]) {
            Assignment1_V6_DW.is_PACE = Assignment1_V6_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V6_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V6_IN_Pace_Vent:
          if ((Assignment1_V6_DW.temporalCounter_i1 << 1) >=
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
              ((Assignment1_V6_DW.temporalCounter_i1 << 1) >= (uint32_T)ceil
               (Assignment1_V6_B.Switch2 - (real_T)Assignment1_V6_B.Cast11
                [(int32_T)Assignment1_V6_B.Cast8 - 1]))) {
            Assignment1_V6_DW.tp_Sense_Detect = 0U;
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Fail;
            Assignment1_V6_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment1_V6_B.VectorConcatenate[(int32_T)
                     Assignment1_V6_B.Cast8 - 1]) {
            Assignment1_V6_DW.tp_Sense_Detect = 0U;
            Assignment1_V6_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
            Assignment1_V6_DW.tp_Sense_Detected = 1U;
          }
          break;

         case Assignment1_V_IN_Sense_Detected:
          Assignment1_V6_DW.tp_Sense_Detected = 0U;
          Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Wait;
          Assignment1_V6_DW.temporalCounter_i1 = 0U;
          break;

         case Assignment1_V_IN_Sense_Disabled:
          if ((Assignment1_V6_DW.temporalCounter_i1 << 1) >=
              Assignment1_V6_B.Switch2) {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Fail;
            Assignment1_V6_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          }
          break;

         case Assignment1_V6_IN_Sense_Fail:
          broadcast_sense_timeout_c3_Assi();
          break;

         case Assignment1_V6_IN_Sense_Finish:
          if (Assignment1_V6_B.Cast9 != Nothing) {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Wait;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
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
          } else if ((Assignment1_V6_DW.temporalCounter_i1 << 1) >=
                     Assignment1_V6_B.Cast11[(int32_T)Assignment1_V6_B.Cast8 - 1])
          {
            Assignment1_V6_DW.is_SENSE = Assignment1_V6_IN_Sense_Detect;
            Assignment1_V6_DW.temporalCounter_i1 = 0U;
            Assignment1_V6_DW.tp_Sense_Detect = 1U;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S9>/PACE_SYSTEM' */
}

static void Assignment1__SystemCore_setup_a(freedomk64f_fxos8700_Assignme_T *obj)
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

static void Assignment1_SystemCore_setup_ai(freedomk64f_SCIRead_Assignmen_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T SCIModuleLoc;
  uint32_T TxPinLoc;
  obj->isInitialized = 1;
  TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void Assignment1_V6_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Assignment1_V6_step1(void)        /* Sample time: [0.002s, 0.0s] */
{
  real_T rtb_Gain_i;
  real_T rtb_Motion_State;
  int32_T Params_Raw_tmp;
  int32_T bitIdx;
  int32_T i;
  int32_T intVal;
  int16_T b_RegisterValue[3];
  uint16_T rtb_Cast12;
  uint16_T rtb_Cast14;
  uint8_T rtb_Cast[15];
  uint8_T rtb_IntegertoBitConverter[8];
  uint8_T output_raw[6];
  uint8_T rtb_BittoIntegerConverter1[4];
  uint8_T b_x[2];
  uint8_T rtb_VectorConcatenate2[2];
  uint8_T status;
  Pace_Rate_Mode rtb_Cast10;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Assignment1_V6_DW.obj_e.SampleTime !=
      Assignment1_V6_P.SerialReceive_SampleTime) {
    Assignment1_V6_DW.obj_e.SampleTime =
      Assignment1_V6_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Assignment1_V6_DW.obj_e.MW_SCIHANDLE,
    &Assignment1_V6_B.RxDataLocChar[0], 16U);
  memcpy((void *)&Assignment1_V6_B.RxData[0], (void *)
         &Assignment1_V6_B.RxDataLocChar[0], (size_t)16 * sizeof(uint8_T));

  /* Constant: '<S10>/Constant10' */
  Assignment1_V6_B.VectorConcatenate1_m[0] = Assignment1_V6_P.Constant10_Value;

  /* Constant: '<S10>/Constant' */
  Assignment1_V6_B.VectorConcatenate1_m[1] = Assignment1_V6_P.Constant_Value_b;

  /* Constant: '<S10>/Constant5' */
  Assignment1_V6_B.VectorConcatenate1_m[2] = Assignment1_V6_P.Constant5_Value;

  /* Constant: '<S10>/Constant9' */
  Assignment1_V6_B.VectorConcatenate1_m[3] = Assignment1_V6_P.Constant9_Value;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  Assignment1_V6_B.VectorConcatenate1_m[4] = Assignment1_V6_P.Constant1_Value_j;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  Assignment1_V6_B.VectorConcatenate1_m[5] = Assignment1_V6_P.Constant3_Value;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  Assignment1_V6_B.VectorConcatenate1_m[6] = Assignment1_V6_P.Constant2_Value;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  Assignment1_V6_B.VectorConcatenate1_m[7] = Assignment1_V6_P.Constant1_Value_j;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  Assignment1_V6_B.VectorConcatenate1_m[8] = Assignment1_V6_P.Constant3_Value;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  Assignment1_V6_B.VectorConcatenate1_m[9] = Assignment1_V6_P.Constant2_Value;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  Assignment1_V6_B.VectorConcatenate1_m[10] = Assignment1_V6_P.Constant4_Value;

  /* SignalConversion generated from: '<S2>/Vector Concatenate1' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  Assignment1_V6_B.VectorConcatenate1_m[11] = Assignment1_V6_P.Constant4_Value;

  /* Constant: '<S10>/Constant6' */
  Assignment1_V6_B.VectorConcatenate1_m[12] = Assignment1_V6_P.Constant6_Value;

  /* Constant: '<S10>/Constant7' */
  Assignment1_V6_B.VectorConcatenate1_m[13] = Assignment1_V6_P.Constant7_Value;

  /* Constant: '<S10>/Constant8' */
  Assignment1_V6_B.VectorConcatenate1_m[14] = Assignment1_V6_P.Constant8_Value;

  /* DataTypeConversion: '<S2>/Cast' */
  for (i = 0; i < 15; i++) {
    rtb_Cast[i] = (uint8_T)Assignment1_V6_B.VectorConcatenate1_m[i];
  }

  /* End of DataTypeConversion: '<S2>/Cast' */

  /* MATLABSystem: '<S5>/Analog Input' */
  if (Assignment1_V6_DW.obj_h.SampleTime !=
      Assignment1_V6_P.AnalogInput_SampleTime) {
    Assignment1_V6_DW.obj_h.SampleTime = Assignment1_V6_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V6_DW.obj_h.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V6_DW.obj_h.MW_ANALOGIN_HANDLE,
    &rtb_Motion_State, 7);

  /* Gain: '<S5>/Gain2' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S5>/Gain'
   *  MATLABSystem: '<S5>/Analog Input'
   *  Sum: '<S5>/Subtract'
   */
  rtb_Motion_State = (rtb_Motion_State - Assignment1_V6_P.Constant1_Value_b) *
    Assignment1_V6_P.Gain_Gain_d * Assignment1_V6_P.Gain2_Gain;

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  rtb_Gain_i = fabs(rtb_Motion_State);
  if (rtb_Gain_i < 4.503599627370496E+15) {
    if (rtb_Gain_i >= 0.5) {
      /* DataTypeConversion: '<S5>/Data Type Conversion' */
      Assignment1_V6_B.DataTypeConversion = (int16_T)floor(rtb_Motion_State +
        0.5);
    } else {
      /* DataTypeConversion: '<S5>/Data Type Conversion' */
      Assignment1_V6_B.DataTypeConversion = 0;
    }
  } else {
    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    Assignment1_V6_B.DataTypeConversion = (int16_T)rtb_Motion_State;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* MATLABSystem: '<S5>/Analog Input1' */
  if (Assignment1_V6_DW.obj_n.SampleTime !=
      Assignment1_V6_P.AnalogInput1_SampleTime) {
    Assignment1_V6_DW.obj_n.SampleTime =
      Assignment1_V6_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V6_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V6_DW.obj_n.MW_ANALOGIN_HANDLE,
    &rtb_Motion_State, 7);

  /* Gain: '<S5>/Gain3' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S5>/Gain1'
   *  MATLABSystem: '<S5>/Analog Input1'
   *  Sum: '<S5>/Subtract1'
   */
  rtb_Motion_State = (rtb_Motion_State - Assignment1_V6_P.Constant1_Value_b) *
    Assignment1_V6_P.Gain1_Gain_c * Assignment1_V6_P.Gain3_Gain;

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  rtb_Gain_i = fabs(rtb_Motion_State);
  if (rtb_Gain_i < 4.503599627370496E+15) {
    if (rtb_Gain_i >= 0.5) {
      /* DataTypeConversion: '<S5>/Data Type Conversion1' */
      Assignment1_V6_B.DataTypeConversion1 = (int16_T)floor(rtb_Motion_State +
        0.5);
    } else {
      /* DataTypeConversion: '<S5>/Data Type Conversion1' */
      Assignment1_V6_B.DataTypeConversion1 = 0;
    }
  } else {
    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    Assignment1_V6_B.DataTypeConversion1 = (int16_T)rtb_Motion_State;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion1' */

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant2'
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Assignment1_V6_DW.temporalCounter_i1_e < MAX_uint32_T) {
    Assignment1_V6_DW.temporalCounter_i1_e++;
  }

  if (Assignment1_V6_DW.is_active_c7_Assignment1_V6 == 0U) {
    Assignment1_V6_DW.is_active_c7_Assignment1_V6 = 1U;
    Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1_V6_IN_Init;
    for (i = 0; i < 15; i++) {
      status = rtb_Cast[i];
      Assignment1_V6_B.Params_Arr[i] = status;
      Assignment1_V6_DW.Output_Candidate[i] = status;
    }

    Assignment1_V6_B.TX_ctrlmode = 2U;
  } else {
    switch (Assignment1_V6_DW.is_c7_Assignment1_V6) {
     case Assignment1_V6_IN_Conv_Data:
      if (Assignment1_V6_DW.temporalCounter_i1_e >= 55U) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1_V6_IN_TX_Rxint_buf;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        Params_Raw_tmp = (Assignment1_V6_DW.iter_o - 1) << 2;
        Assignment1_V6_B.Params_Raw[0] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp];
        Assignment1_V6_B.Params_Raw[1] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp + 1];
        Assignment1_V6_B.Params_Raw[2] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp + 2];
        Assignment1_V6_B.Params_Raw[3] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp + 3];

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assig_HARDWARE_TX_INTERFACE(Assignment1_V6_B.TX_ctrlmode,
          Assignment1_V6_B.Params_Raw, Assignment1_V6_B.DataTypeConversion,
          Assignment1_V6_B.DataTypeConversion1,
          &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Params_Raw_tmp = (int32_T)(Assignment1_V6_DW.iter_o + 1U);
        if (Assignment1_V6_DW.iter_o + 1U > 255U) {
          Params_Raw_tmp = 255;
        }

        Assignment1_V6_DW.iter_o = (uint8_T)Params_Raw_tmp;
      }
      break;

     case Assignment1__IN_Detect_Cur_Mode:
      Assignment1_V6_B.TX_ctrlmode = 1U;
      if ((Assignment1_V6_DW.Op_Mode != 255) && (Assignment1_V6_DW.Op_Mode !=
           254)) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        Assignment1_V6_B.TX_ctrlmode = 2U;

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assig_HARDWARE_TX_INTERFACE(2, Assignment1_V6_B.Params_Raw,
          Assignment1_V6_B.DataTypeConversion,
          Assignment1_V6_B.DataTypeConversion1,
          &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
      } else if (Assignment1_V6_DW.Op_Mode == 255) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1__IN_Save_Buf_Params;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        for (i = 0; i < 15; i++) {
          Assignment1_V6_B.Params_Arr[i] = Assignment1_V6_DW.Output_Candidate[i];
        }
      } else {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1_V6_IN_Conv_Data;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        Assignment1_V6_Process_Rx(&Assignment1_V6_DW.Rx_buf[1],
          Assignment1_V6_DW.Output_Candidate);
        for (i = 0; i < 16; i++) {
          Assignment1_V6_DW.Rxint_buf[i] = Assignment1_V6_DW.Rx_buf[i];
        }

        Assignment1_V6_DW.iter_o = 1U;
      }
      break;

     case Assignme_IN_ECG_TX_Loop_Standby:
      Assignment1_V6_B.TX_ctrlmode = 2U;
      if (Assignment1_V6_DW.temporalCounter_i1_e >= 5U) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assig_HARDWARE_TX_INTERFACE(2, Assignment1_V6_B.Params_Raw,
          Assignment1_V6_B.DataTypeConversion,
          Assignment1_V6_B.DataTypeConversion1,
          &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
      } else if (status == 0) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1__IN_Detect_Cur_Mode;
        for (i = 0; i < 16; i++) {
          Assignment1_V6_DW.Rx_buf[i] = Assignment1_V6_B.RxData[i];
        }

        memcpy((void *)&Assignment1_V6_DW.Op_Mode, (void *)
               &Assignment1_V6_DW.Rx_buf[0], (size_t)1 * sizeof(uint8_T));
        Assignment1_V6_B.TX_ctrlmode = 1U;
      }
      break;

     case Assignment1_V6_IN_Init:
      Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignme_IN_ECG_TX_Loop_Standby;
      Assignment1_V6_DW.temporalCounter_i1_e = 0U;
      Assignment1_V6_B.TX_ctrlmode = 2U;

      /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
      Assig_HARDWARE_TX_INTERFACE(2, Assignment1_V6_B.Params_Raw,
        Assignment1_V6_B.DataTypeConversion,
        Assignment1_V6_B.DataTypeConversion1,
        &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
        &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
        &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

      /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
      break;

     case Assignment1__IN_Save_Buf_Params:
      if (Assignment1_V6_DW.temporalCounter_i1_e >= 10U) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        Assignment1_V6_B.TX_ctrlmode = 2U;

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assig_HARDWARE_TX_INTERFACE(2, Assignment1_V6_B.Params_Raw,
          Assignment1_V6_B.DataTypeConversion,
          Assignment1_V6_B.DataTypeConversion1,
          &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
      }
      break;

     case Assignment1_V6_IN_TX_Rxint_buf:
      if (Assignment1_V6_DW.iter_o >= 5) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1_V6_IN_TX_wait;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
      } else if (status == 0) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1__IN_Detect_Cur_Mode;
        for (i = 0; i < 16; i++) {
          Assignment1_V6_DW.Rx_buf[i] = Assignment1_V6_B.RxData[i];
        }

        memcpy((void *)&Assignment1_V6_DW.Op_Mode, (void *)
               &Assignment1_V6_DW.Rx_buf[0], (size_t)1 * sizeof(uint8_T));
        Assignment1_V6_B.TX_ctrlmode = 1U;
      } else if (Assignment1_V6_DW.temporalCounter_i1_e >= 5U) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1_V6_IN_TX_Rxint_buf;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        Params_Raw_tmp = (Assignment1_V6_DW.iter_o - 1) << 2;
        Assignment1_V6_B.Params_Raw[0] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp];
        Assignment1_V6_B.Params_Raw[1] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp + 1];
        Assignment1_V6_B.Params_Raw[2] =
          Assignment1_V6_DW.Rxint_buf[Params_Raw_tmp + 2];
        Assignment1_V6_B.Params_Raw[3] = Assignment1_V6_DW.Rxint_buf
          [((Assignment1_V6_DW.iter_o - 1) << 2) + 3];

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assig_HARDWARE_TX_INTERFACE(Assignment1_V6_B.TX_ctrlmode,
          Assignment1_V6_B.Params_Raw, Assignment1_V6_B.DataTypeConversion,
          Assignment1_V6_B.DataTypeConversion1,
          &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assignment1_V6_DW.iter_o++;
      }
      break;

     default:
      /* case IN_TX_wait: */
      if (status == 0) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignment1__IN_Detect_Cur_Mode;
        for (i = 0; i < 16; i++) {
          Assignment1_V6_DW.Rx_buf[i] = Assignment1_V6_B.RxData[i];
        }

        memcpy((void *)&Assignment1_V6_DW.Op_Mode, (void *)
               &Assignment1_V6_DW.Rx_buf[0], (size_t)1 * sizeof(uint8_T));
        Assignment1_V6_B.TX_ctrlmode = 1U;
      } else if ((Assignment1_V6_DW.temporalCounter_i1_e << 1) >= (uint32_T)ceil
                 (Assignment1_V6_P.Constant2_Value_c)) {
        Assignment1_V6_DW.is_c7_Assignment1_V6 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V6_DW.temporalCounter_i1_e = 0U;
        Assignment1_V6_B.TX_ctrlmode = 2U;

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assig_HARDWARE_TX_INTERFACE(2, Assignment1_V6_B.Params_Raw,
          Assignment1_V6_B.DataTypeConversion,
          Assignment1_V6_B.DataTypeConversion1,
          &Assignment1_V6_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V6_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (scominttobit): '<S12>/Integer to Bit Converter' */
  /* Integer to Bit Conversion */
  Params_Raw_tmp = 8;
  intVal = Assignment1_V6_B.Params_Arr[0];
  for (i = 0; i < 8; i++) {
    rtb_IntegertoBitConverter[Params_Raw_tmp - 1] = (uint8_T)((uint32_T)intVal &
      1U);
    intVal = (int32_T)((uint32_T)intVal >> 1U);
    Params_Raw_tmp--;
  }

  /* S-Function (scominttobit): '<S12>/Bit to Integer Converter1' */
  /* Bit to Integer Conversion */
  Params_Raw_tmp = 0;
  for (i = 0; i < 4; i++) {
    /* Input bit order is MSB first */
    intVal = rtb_IntegertoBitConverter[Params_Raw_tmp];
    bitIdx = Params_Raw_tmp + 1;

    /* Input bit order is MSB first */
    Params_Raw_tmp += 2;
    rtb_BittoIntegerConverter1[i] = (uint8_T)((uint32_T)intVal << 1U |
      rtb_IntegertoBitConverter[bitIdx]);
  }

  /* DataTypeConversion: '<S12>/Cast7' */
  Assignment1_V6_B.Cast7 = (Pace_Chamber)rtb_BittoIntegerConverter1[0];

  /* DataTypeConversion: '<S12>/Cast8' */
  Assignment1_V6_B.Cast8 = (Pace_Sense_Chamber)rtb_BittoIntegerConverter1[1];

  /* DataTypeConversion: '<S12>/Cast12' incorporates:
   *  DataTypeConversion: '<S12>/Cast To Double'
   *  Gain: '<S12>/Multiply'
   *  Product: '<S12>/Reciprocal'
   */
  rtb_Cast12 = (uint16_T)(1.0 / (real_T)Assignment1_V6_B.Params_Arr[1] *
    Assignment1_V6_P.Multiply_Gain);

  /* Outputs for Atomic SubSystem: '<Root>/HARDWARE_ACCEL_INTERFACE' */
  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
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

  rtb_Motion_State = (real_T)(int16_T)(b_RegisterValue[0] >> 2) * 2.0 * 0.244 /
    1000.0;

  /* DotProduct: '<S11>/Dot Product' */
  rtb_Gain_i = rtb_Motion_State * rtb_Motion_State;

  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  rtb_Motion_State = (real_T)(int16_T)(b_RegisterValue[1] >> 2) * 2.0 * 0.244 /
    1000.0;

  /* DotProduct: '<S11>/Dot Product' */
  rtb_Gain_i += rtb_Motion_State * rtb_Motion_State;

  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  rtb_Motion_State = (real_T)(int16_T)(b_RegisterValue[2] >> 2) * 2.0 * 0.244 /
    1000.0;

  /* Sqrt: '<S11>/Square Root' incorporates:
   *  DotProduct: '<S11>/Dot Product'
   */
  Assignment1_V6_B.SquareRoot = sqrt(rtb_Motion_State * rtb_Motion_State +
    rtb_Gain_i);

  /* S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  memcpy(&Assignment1_V6_B.TappedDelay[0], &Assignment1_V6_DW.TappedDelay_X[0],
         49U * sizeof(real_T));

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' incorporates:
   *  S-Function (scominttobit): '<S12>/Bit to Integer Converter1'
   *  S-Function (scominttobit): '<S12>/Integer to Bit Converter'
   */
  for (i = 0; i < 48; i++) {
    Assignment1_V6_DW.TappedDelay_X[i] = Assignment1_V6_DW.TappedDelay_X[i + 1];
  }

  Assignment1_V6_DW.TappedDelay_X[48] = Assignment1_V6_B.SquareRoot;

  /* End of Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  /* End of Outputs for SubSystem: '<Root>/HARDWARE_ACCEL_INTERFACE' */

  /* MATLAB Function: '<S16>/MATLAB Function2' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if (Assignment1_V6_DW.init_counter < Assignment1_V6_P.Constant1_Value_jw) {
    Assignment1_V6_DW.init_counter++;
  }

  Assignment1_V6_DW.rolling_avg = (Assignment1_V6_DW.init_counter - 1.0) *
    Assignment1_V6_DW.rolling_avg / Assignment1_V6_DW.init_counter +
    Assignment1_V6_B.TappedDelay[0] / Assignment1_V6_DW.init_counter;

  /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant2'
   *  MATLAB Function: '<S16>/MATLAB Function2'
   */
  rtb_Motion_State = 3.0;
  if (Assignment1_V6_P.Constant2_Value_o[1] > Assignment1_V6_DW.rolling_avg) {
    rtb_Motion_State = 2.0;
  }

  if (Assignment1_V6_P.Constant2_Value_o[0] > Assignment1_V6_DW.rolling_avg) {
    rtb_Motion_State = 1.0;
  }

  /* End of MATLAB Function: '<S17>/MATLAB Function' */

  /* Gain: '<S18>/Gain' incorporates:
   *  MATLAB Function: '<S16>/MATLAB Function2'
   */
  rtb_Gain_i = Assignment1_V6_P.Gain_Gain_e * Assignment1_V6_DW.rolling_avg;

  /* DataTypeConversion: '<S12>/Cast14' incorporates:
   *  DataTypeConversion: '<S12>/Cast To Double2'
   *  Gain: '<S12>/Multiply2'
   *  Product: '<S12>/Reciprocal2'
   */
  rtb_Cast14 = (uint16_T)(1.0 / (real_T)Assignment1_V6_B.Params_Arr[3] *
    Assignment1_V6_P.Multiply2_Gain);

  /* DataTypeConversion: '<S12>/Cast10' */
  rtb_Cast10 = (Pace_Rate_Mode)rtb_BittoIntegerConverter1[3];

  /* Gain: '<S12>/Gain4' incorporates:
   *  DataTypeConversion: '<S12>/Cast15'
   */
  Assignment1_V6_B.Gain4 = Assignment1_V6_P.Gain4_Gain *
    Assignment1_V6_B.Params_Arr[12];

  /* Gain: '<S12>/Gain5' incorporates:
   *  DataTypeConversion: '<S12>/Cast16'
   */
  Assignment1_V6_B.Gain5 = (uint64_T)Assignment1_V6_P.Gain5_Gain *
    Assignment1_V6_B.Params_Arr[14];

  /* Chart: '<S8>/RATE_CTRL_SYSTEM' */
  if (Assignment1_V6_DW.temporalCounter_i1_a < 63U) {
    Assignment1_V6_DW.temporalCounter_i1_a++;
  }

  if (Assignment1_V6_DW.is_active_c9_Assignment1_V6 == 0U) {
    Assignment1_V6_DW.is_active_c9_Assignment1_V6 = 1U;
    Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V6_IN_Init_b;
    Assignment1_V6_B.sense_timeout_threshold = rtb_Cast12;
    Assignment1_V6_DW.iter = 0U;
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
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_get_tgt;
        Assignment1_V6_DW.temporalCounter_i1_a = 0U;
        Assignment1_V6_B.dv[0] = 2.6;
        Assignment1_V6_B.dv[1] = -40.0;
        Assignment1_V6_DW.tgt = Assignment1__Calc_Rate_Response(rtb_Gain_i,
          Assignment1_V6_B.dv, rtb_Cast12, rtb_Cast14);
        Params_Raw_tmp = (int32_T)(Assignment1_V6_DW.iter + 1U);
        if (Assignment1_V6_DW.iter + 1U > 255U) {
          Params_Raw_tmp = 255;
        }

        Assignment1_V6_DW.iter = (uint8_T)Params_Raw_tmp;
        if (Assignment1_V6_DW.iter == 100) {
          Assignment1__UPDATE_EXP_FAC();
          Assignment1_V6_DW.iter = 0U;
        }
        break;
      }
      break;

     case Assignment1_V6_IN_Init_b:
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
        Assignment1_V6_DW.temporalCounter_i1_a = 0U;
        Assignment1_V6_B.dv[0] = 2.6;
        Assignment1_V6_B.dv[1] = -40.0;
        Assignment1_V6_DW.tgt = Assignment1__Calc_Rate_Response(rtb_Gain_i,
          Assignment1_V6_B.dv, rtb_Cast12, rtb_Cast14);
        Params_Raw_tmp = (int32_T)(Assignment1_V6_DW.iter + 1U);
        if (Assignment1_V6_DW.iter + 1U > 255U) {
          Params_Raw_tmp = 255;
        }

        Assignment1_V6_DW.iter = (uint8_T)Params_Raw_tmp;
        if (Assignment1_V6_DW.iter == 100) {
          Assignment1__UPDATE_EXP_FAC();
          Assignment1_V6_DW.iter = 0U;
        }
        break;

       case Assignment1_V6_IN_Smaller:
        Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_get_tgt;
        Assignment1_V6_DW.temporalCounter_i1_a = 0U;
        Assignment1_V6_B.dv[0] = 2.6;
        Assignment1_V6_B.dv[1] = -40.0;
        Assignment1_V6_DW.tgt = Assignment1__Calc_Rate_Response(rtb_Gain_i,
          Assignment1_V6_B.dv, rtb_Cast12, rtb_Cast14);
        Params_Raw_tmp = (int32_T)(Assignment1_V6_DW.iter + 1U);
        if (Assignment1_V6_DW.iter + 1U > 255U) {
          Params_Raw_tmp = 255;
        }

        Assignment1_V6_DW.iter = (uint8_T)Params_Raw_tmp;
        if (Assignment1_V6_DW.iter == 100) {
          Assignment1__UPDATE_EXP_FAC();
          Assignment1_V6_DW.iter = 0U;
        }
        break;

       case Assignment1_V6_IN_check_dif:
        if (Assignment1_V6_DW.dif >= 0.0) {
          Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_Bigger;
          Assignment1_V6_B.sense_timeout_threshold += (real32_T)
            (Assignment1_V6_B.CastToDouble2[(int32_T)rtb_Motion_State + 2] *
             Assignment1_V6_DW.dif);
        } else if (Assignment1_V6_DW.dif <= 0.0) {
          Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_Smaller;
          Assignment1_V6_B.sense_timeout_threshold += (real32_T)
            (Assignment1_V6_B.CastToDouble2[(int32_T)rtb_Motion_State - 1] *
             Assignment1_V6_DW.dif);
        } else {
          Assignment1_V6_DW.dif = Assignment1_V6_DW.tgt -
            Assignment1_V6_B.sense_timeout_threshold;
        }
        break;

       default:
        /* case IN_get_tgt: */
        if (rtb_Cast10 == Disabled) {
          Assignment1_V6_DW.is_Pace_Rate_Unfixed =
            Assignment1__IN_NO_ACTIVE_CHILD;
          Assignment1_V6_DW.is_c9_Assignment1_V6 = Assignment1_V6_IN_Detect_Mode;
        } else if (Assignment1_V6_DW.temporalCounter_i1_a >= 50U) {
          Assignment1_V6_DW.is_Pace_Rate_Unfixed = Assignment1_V6_IN_check_dif;
          Assignment1_V6_DW.dif = Assignment1_V6_DW.tgt -
            Assignment1_V6_B.sense_timeout_threshold;
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/RATE_CTRL_SYSTEM' */

  /* Switch: '<S22>/Switch2' incorporates:
   *  RelationalOperator: '<S22>/LowerRelop1'
   */
  if (Assignment1_V6_B.sense_timeout_threshold > rtb_Cast12) {
    /* Switch: '<S22>/Switch2' */
    Assignment1_V6_B.Switch2 = rtb_Cast12;
  } else {
    /* DataTypeConversion: '<S12>/Cast13' incorporates:
     *  DataTypeConversion: '<S12>/Cast To Double1'
     *  Gain: '<S12>/Multiply1'
     *  Product: '<S12>/Reciprocal1'
     */
    rtb_Cast12 = (uint16_T)(1.0 / (real_T)Assignment1_V6_B.Params_Arr[2] *
      Assignment1_V6_P.Multiply1_Gain);

    /* Switch: '<S22>/Switch' incorporates:
     *  RelationalOperator: '<S22>/UpperRelop'
     */
    if (Assignment1_V6_B.sense_timeout_threshold < rtb_Cast12) {
      /* Switch: '<S22>/Switch2' */
      Assignment1_V6_B.Switch2 = rtb_Cast12;
    } else {
      /* Switch: '<S22>/Switch2' */
      Assignment1_V6_B.Switch2 = Assignment1_V6_B.sense_timeout_threshold;
    }

    /* End of Switch: '<S22>/Switch' */
  }

  /* End of Switch: '<S22>/Switch2' */

  /* Gain: '<S12>/Gain2' incorporates:
   *  DataTypeConversion: '<S12>/Cast'
   *  Gain: '<S12>/Gain16'
   */
  Assignment1_V6_B.Gain2[0] = Assignment1_V6_P.Gain16_Gain * (real32_T)
    Assignment1_V6_B.Params_Arr[4] * Assignment1_V6_P.Gain2_Gain_g;

  /* DataTypeConversion: '<S12>/Cast11' incorporates:
   *  SignalConversion generated from: '<S12>/Vector Concatenate2'
   */
  Assignment1_V6_B.Cast11[0] = Assignment1_V6_B.Params_Arr[10];

  /* Gain: '<S12>/Gain2' incorporates:
   *  DataTypeConversion: '<S12>/Cast1'
   *  Gain: '<S12>/Gain15'
   */
  Assignment1_V6_B.Gain2[1] = Assignment1_V6_P.Gain15_Gain * (real32_T)
    Assignment1_V6_B.Params_Arr[7] * Assignment1_V6_P.Gain2_Gain_g;

  /* DataTypeConversion: '<S12>/Cast11' incorporates:
   *  SignalConversion generated from: '<S12>/Vector Concatenate2'
   */
  Assignment1_V6_B.Cast11[1] = Assignment1_V6_B.Params_Arr[11];

  /* Gain: '<S12>/Gain7' incorporates:
   *  Concatenate: '<S12>/Vector Concatenate1'
   *  DataTypeConversion: '<S12>/Cast4'
   */
  Assignment1_V6_B.VectorConcatenate1[0] = Assignment1_V6_P.Gain7_Gain *
    (real32_T)Assignment1_V6_B.Params_Arr[5];

  /* Gain: '<S12>/Gain8' incorporates:
   *  Concatenate: '<S12>/Vector Concatenate1'
   *  DataTypeConversion: '<S12>/Cast5'
   */
  Assignment1_V6_B.VectorConcatenate1[1] = Assignment1_V6_P.Gain8_Gain *
    (real32_T)Assignment1_V6_B.Params_Arr[8];

  /* DataTypeConversion: '<S12>/Cast9' */
  Assignment1_V6_B.Cast9 = (Pace_Sense_Response)rtb_BittoIntegerConverter1[2];

  /* MATLABSystem: '<S5>/Digital Read1' */
  if (Assignment1_V6_DW.obj_d.SampleTime !=
      Assignment1_V6_P.DigitalRead1_SampleTime) {
    Assignment1_V6_DW.obj_d.SampleTime =
      Assignment1_V6_P.DigitalRead1_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Boolean'
   *  MATLABSystem: '<S5>/Digital Read1'
   */
  Assignment1_V6_B.VectorConcatenate[0] = MW_digitalIO_read
    (Assignment1_V6_DW.obj_d.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S5>/Digital Read' */
  if (Assignment1_V6_DW.obj_a.SampleTime !=
      Assignment1_V6_P.DigitalRead_SampleTime) {
    Assignment1_V6_DW.obj_a.SampleTime = Assignment1_V6_P.DigitalRead_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Boolean1'
   *  MATLABSystem: '<S5>/Digital Read'
   */
  Assignment1_V6_B.VectorConcatenate[1] = MW_digitalIO_read
    (Assignment1_V6_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* Chart: '<S9>/PACE_SYSTEM' */
  if (Assignment1_V6_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V6_DW.temporalCounter_i1++;
  }

  Assignment1_V6_DW.sfEvent = -1;
  Assignment1_V_c3_Assignment1_V6();

  /* End of Chart: '<S9>/PACE_SYSTEM' */

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_V6_DW.obj_dw.MW_PWM_HANDLE, (real_T)
                      Assignment1_V6_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_h5.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write4' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_ev.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S5>/Digital Write6' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_ni.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S5>/Digital Write7' */
  MW_digitalIO_write(Assignment1_V6_DW.obj_f.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S5>/PWM Output1' incorporates:
   *  DataTypeConversion: '<S12>/Cast3'
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S12>/Gain6'
   */
  MW_PWM_SetDutyCycle(Assignment1_V6_DW.obj_ng.MW_PWM_HANDLE, (real_T)
                      (Assignment1_V6_P.Gain1_Gain_m *
                       (Assignment1_V6_P.Gain6_Gain * (real32_T)
                        Assignment1_V6_B.Params_Arr[9])));

  /* MATLABSystem: '<S5>/PWM Output' incorporates:
   *  DataTypeConversion: '<S12>/Cast2'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/Gain3'
   */
  MW_PWM_SetDutyCycle(Assignment1_V6_DW.obj_l.MW_PWM_HANDLE, (real_T)
                      (Assignment1_V6_P.Gain_Gain_l *
                       (Assignment1_V6_P.Gain3_Gain_o * (real32_T)
                        Assignment1_V6_B.Params_Arr[6])));

  /* MATLABSystem: '<S5>/Digital Write1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  MW_digitalIO_write(Assignment1_V6_DW.obj_g.MW_DIGITALIO_HANDLE,
                     Assignment1_V6_P.Constant_Value_g != 0.0);
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Assignment1_V6_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Assignment1_V6_step0();
    break;

   case 1 :
    Assignment1_V6_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Assignment1_V6_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    Assignment1_V6_B.Cast7 = Atrium;
  }

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    freedomk64f_AnalogInput_Assig_T *obj;
    freedomk64f_DigitalRead_Assig_T *obj_0;
    freedomk64f_DigitalWrite_Assi_T *obj_1;
    freedomk64f_PWMOutput_Assignm_T *obj_2;
    int32_T i;

    /* SystemInitialize for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<Root>/HARDWARE_TX_INTERFACE'
     */
    HARDWARE_TX_INTERFACE_Init(&Assignment1_V6_DW.HARDWARE_TX_INTERFACE);

    /* SystemInitialize for Atomic SubSystem: '<Root>/HARDWARE_ACCEL_INTERFACE' */
    /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
    for (i = 0; i < 49; i++) {
      Assignment1_V6_DW.TappedDelay_X[i] = Assignment1_V6_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */

    /* Start for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
    Assignment1_V6_DW.obj.isInitialized = 0;
    Assignment1_V6_DW.obj.i2cobj.isInitialized = 0;
    Assignment1_V6_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj.SampleTime =
      Assignment1_V6_P.FXOS87006AxesSensor_SampleTime;
    Assignment1__SystemCore_setup_a(&Assignment1_V6_DW.obj);

    /* End of SystemInitialize for SubSystem: '<Root>/HARDWARE_ACCEL_INTERFACE' */

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S8>/RESP_EXP_FAC_CALC' incorporates:
     *  SubSystem: '<S8>/RESP_EXP_FAC_CALC'
     */
    Assignm_UPDATE_EXP_FAC_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S8>/RESP_EXP_FAC_CALC' */

    /* SystemInitialize for Chart: '<S9>/PACE_SYSTEM' */
    Assignment1_V6_DW.sfEvent = -1;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Assignment1_V6_DW.obj_e.isInitialized = 0;
    Assignment1_V6_DW.obj_e.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj_e.SampleTime =
      Assignment1_V6_P.SerialReceive_SampleTime;
    Assignment1_SystemCore_setup_ai(&Assignment1_V6_DW.obj_e);

    /* Start for MATLABSystem: '<S5>/Analog Input' */
    Assignment1_V6_DW.obj_h.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj_h.SampleTime = Assignment1_V6_P.AnalogInput_SampleTime;
    obj = &Assignment1_V6_DW.obj_h;
    Assignment1_V6_DW.obj_h.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V6_DW.obj_h.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_V6_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Analog Input1' */
    Assignment1_V6_DW.obj_n.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj_n.SampleTime =
      Assignment1_V6_P.AnalogInput1_SampleTime;
    obj = &Assignment1_V6_DW.obj_n;
    Assignment1_V6_DW.obj_n.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V6_DW.obj_n.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_V6_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read1' */
    Assignment1_V6_DW.obj_d.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj_d.SampleTime =
      Assignment1_V6_P.DigitalRead1_SampleTime;
    obj_0 = &Assignment1_V6_DW.obj_d;
    Assignment1_V6_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_V6_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read' */
    Assignment1_V6_DW.obj_a.matlabCodegenIsDeleted = false;
    Assignment1_V6_DW.obj_a.SampleTime = Assignment1_V6_P.DigitalRead_SampleTime;
    obj_0 = &Assignment1_V6_DW.obj_a;
    Assignment1_V6_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_V6_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Assignment1_V6_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_k;
    Assignment1_V6_DW.obj_k.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_V6_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Assignment1_V6_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_p;
    Assignment1_V6_DW.obj_p.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_V6_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Assignment1_V6_DW.obj_dw.matlabCodegenIsDeleted = false;
    obj_2 = &Assignment1_V6_DW.obj_dw;
    Assignment1_V6_DW.obj_dw.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V6_DW.obj_dw.MW_PWM_HANDLE);
    Assignment1_V6_DW.obj_dw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    Assignment1_V6_DW.obj_h5.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_h5;
    Assignment1_V6_DW.obj_h5.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_V6_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write4' */
    Assignment1_V6_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_b;
    Assignment1_V6_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_V6_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    Assignment1_V6_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_m;
    Assignment1_V6_DW.obj_m.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_V6_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    Assignment1_V6_DW.obj_ev.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_ev;
    Assignment1_V6_DW.obj_ev.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_V6_DW.obj_ev.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write6' */
    Assignment1_V6_DW.obj_ni.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_ni;
    Assignment1_V6_DW.obj_ni.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_V6_DW.obj_ni.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write7' */
    Assignment1_V6_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_f;
    Assignment1_V6_DW.obj_f.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_V6_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output1' */
    Assignment1_V6_DW.obj_ng.matlabCodegenIsDeleted = false;
    obj_2 = &Assignment1_V6_DW.obj_ng;
    Assignment1_V6_DW.obj_ng.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V6_DW.obj_ng.MW_PWM_HANDLE);
    Assignment1_V6_DW.obj_ng.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output' */
    Assignment1_V6_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_2 = &Assignment1_V6_DW.obj_l;
    Assignment1_V6_DW.obj_l.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V6_DW.obj_l.MW_PWM_HANDLE);
    Assignment1_V6_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    Assignment1_V6_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V6_DW.obj_g;
    Assignment1_V6_DW.obj_g.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_V6_DW.obj_g.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_V6_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Assignment1_V6_DW.obj_e.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_e.isInitialized == 1) &&
        Assignment1_V6_DW.obj_e.isSetupComplete) {
      MW_SCI_Close(Assignment1_V6_DW.obj_e.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S5>/Analog Input' */
  if (!Assignment1_V6_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_h.isInitialized == 1) &&
        Assignment1_V6_DW.obj_h.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment1_V6_DW.obj_h.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment1_V6_DW.obj_h.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Analog Input' */

  /* Terminate for MATLABSystem: '<S5>/Analog Input1' */
  if (!Assignment1_V6_DW.obj_n.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_n.isInitialized == 1) &&
        Assignment1_V6_DW.obj_n.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment1_V6_DW.obj_n.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment1_V6_DW.obj_n.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Analog Input1' */

  /* Terminate for Chart: '<Root>/Chart' incorporates:
   *  SubSystem: '<Root>/HARDWARE_TX_INTERFACE'
   */
  HARDWARE_TX_INTERFACE_Term(&Assignment1_V6_DW.HARDWARE_TX_INTERFACE);

  /* Terminate for Atomic SubSystem: '<Root>/HARDWARE_ACCEL_INTERFACE' */
  /* Terminate for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
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

  /* End of Terminate for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  /* End of Terminate for SubSystem: '<Root>/HARDWARE_ACCEL_INTERFACE' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read1' */
  if (!Assignment1_V6_DW.obj_d.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_d.isInitialized == 1) &&
        Assignment1_V6_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read' */
  if (!Assignment1_V6_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_a.isInitialized == 1) &&
        Assignment1_V6_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Assignment1_V6_DW.obj_k.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_k.isInitialized == 1) &&
        Assignment1_V6_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!Assignment1_V6_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_p.isInitialized == 1) &&
        Assignment1_V6_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!Assignment1_V6_DW.obj_dw.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_dw.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_dw.isInitialized == 1) &&
        Assignment1_V6_DW.obj_dw.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V6_DW.obj_dw.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V6_DW.obj_dw.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  if (!Assignment1_V6_DW.obj_h5.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_h5.isInitialized == 1) &&
        Assignment1_V6_DW.obj_h5.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_h5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write4' */
  if (!Assignment1_V6_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_b.isInitialized == 1) &&
        Assignment1_V6_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  if (!Assignment1_V6_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_m.isInitialized == 1) &&
        Assignment1_V6_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  if (!Assignment1_V6_DW.obj_ev.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_ev.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_ev.isInitialized == 1) &&
        Assignment1_V6_DW.obj_ev.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_ev.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write6' */
  if (!Assignment1_V6_DW.obj_ni.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_ni.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_ni.isInitialized == 1) &&
        Assignment1_V6_DW.obj_ni.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_ni.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write7' */
  if (!Assignment1_V6_DW.obj_f.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_f.isInitialized == 1) &&
        Assignment1_V6_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output1' */
  if (!Assignment1_V6_DW.obj_ng.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_ng.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_ng.isInitialized == 1) &&
        Assignment1_V6_DW.obj_ng.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V6_DW.obj_ng.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V6_DW.obj_ng.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output' */
  if (!Assignment1_V6_DW.obj_l.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_l.isInitialized == 1) &&
        Assignment1_V6_DW.obj_l.isSetupComplete) {
      MW_PWM_Stop(Assignment1_V6_DW.obj_l.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment1_V6_DW.obj_l.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write1' */
  if (!Assignment1_V6_DW.obj_g.matlabCodegenIsDeleted) {
    Assignment1_V6_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Assignment1_V6_DW.obj_g.isInitialized == 1) &&
        Assignment1_V6_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Assignment1_V6_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V4.c
 *
 * Code generated for Simulink model 'Assignment1_V4'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 27 17:18:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment1_V4.h"
#include "rtwtypes.h"
#include "Assignment1_V4_types.h"
#include "Assignment1_V4_private.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<Root>/Chart' */
#define Assignme_IN_ECG_TX_Loop_Standby ((uint8_T)3U)
#define Assignment1_V4_IN_Conv_Data    ((uint8_T)1U)
#define Assignment1_V4_IN_Init         ((uint8_T)4U)
#define Assignment1_V4_IN_TX_Rxint_buf ((uint8_T)6U)
#define Assignment1_V4_IN_TX_wait      ((uint8_T)7U)
#define Assignment1__IN_Detect_Cur_Mode ((uint8_T)2U)
#define Assignment1__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1__IN_Save_Buf_Params ((uint8_T)5U)

/* Named constants for Chart: '<Root>/PACE_SYSTEM' */
#define Assignment1_V4_IN_Charge       ((uint8_T)1U)
#define Assignment1_V4_IN_PACE         ((uint8_T)1U)
#define Assignment1_V4_IN_Pace_Atr     ((uint8_T)3U)
#define Assignment1_V4_IN_Pace_Vent    ((uint8_T)4U)
#define Assignment1_V4_IN_SENSE        ((uint8_T)2U)
#define Assignment1_V4_IN_Sense_Detect ((uint8_T)1U)
#define Assignment1_V4_IN_Sense_Fail   ((uint8_T)4U)
#define Assignment1_V4_IN_Sense_Finish ((uint8_T)5U)
#define Assignment1_V4_IN_Sense_Wait   ((uint8_T)6U)
#define Assignment1_V4_event_pace_compl (0)
#define Assignment1_V_IN_Discharge_Prep ((uint8_T)2U)
#define Assignment1_V_IN_Sense_Detected ((uint8_T)2U)
#define Assignment1_V_IN_Sense_Disabled ((uint8_T)3U)
#define Assignment1_event_sense_timeout (1)

/* Named constants for Chart: '<S10>/RATE_CTRL_SYSTEM' */
#define Assignment1_V4_IN_Bigger       ((uint8_T)1U)
#define Assignment1_V4_IN_Detect_Mode  ((uint8_T)2U)
#define Assignment1_V4_IN_Init_a       ((uint8_T)3U)
#define Assignment1_V4_IN_Smaller      ((uint8_T)6U)
#define Assignment1_V4_IN_check_dif    ((uint8_T)7U)
#define Assignment1_V4_IN_get_tgt      ((uint8_T)8U)
#define Assignment1_V_IN_Pace_LRL_Fixed ((uint8_T)4U)
#define Assignment1_V_IN_Pace_Rate_Init ((uint8_T)5U)

/* Block signals (default storage) */
B_Assignment1_V4_T Assignment1_V4_B;

/* Block states (default storage) */
DW_Assignment1_V4_T Assignment1_V4_DW;

/* Real-time model */
static RT_MODEL_Assignment1_V4_T Assignment1_V4_M_;
RT_MODEL_Assignment1_V4_T *const Assignment1_V4_M = &Assignment1_V4_M_;

/* Forward declaration for local functions */
static void Assignment1_V4_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj);

/* Forward declaration for local functions */
static void Assignment1_V4_Process_Rx(const uint8_T Rx_input[60], real_T
  output_set[15]);
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
static void Assignment1_V_c3_Assignment1_V4(void);
static void Assignment1_SystemCore_setup_lr(freedomk64f_SCIRead_Assignmen_T *obj);
static void Assignment1__SystemCore_setup_l(freedomk64f_fxos8700_Assignme_T *obj);
static void Assignment1_V4_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj)
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
void Assi_HARDWARE_TX_INTERFACE_Init(DW_HARDWARE_TX_INTERFACE_Assi_T *localDW)
{
  /* Start for MATLABSystem: '<S6>/Serial Transmit' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  Assignment1_V4_SystemCore_setup(&localDW->obj);
}

/* Output and update for function-call system: '<Root>/HARDWARE_TX_INTERFACE' */
void Assignmen_HARDWARE_TX_INTERFACE(uint8_T rtu_TX_CTRL_MODE, const uint8_T
  rtu_PARAMS[8], int32_T rtu_ATR_SIGNAL, int32_T rtu_VENT_SIGNAL,
  B_HARDWARE_TX_INTERFACE_Assig_T *localB, DW_HARDWARE_TX_INTERFACE_Assi_T
  *localDW, P_HARDWARE_TX_INTERFACE_Assig_T *localP)
{
  uint8_T TxDataLocChar[8];
  uint8_T rtb_Switch[8];
  uint8_T status;

  /* S-Function (any2byte): '<S6>/Byte Pack' */

  /* Pack: <S6>/Byte Pack */
  (void) memcpy(&localB->BytePack[0], &rtu_ATR_SIGNAL,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack1' */

  /* Pack: <S6>/Byte Pack1 */
  (void) memcpy(&localB->BytePack1[0], &rtu_VENT_SIGNAL,
                4);

  /* Switch: '<S6>/Switch' */
  if (rtu_TX_CTRL_MODE >= localP->Switch_Threshold) {
    rtb_Switch[0] = localB->BytePack[0];
    rtb_Switch[4] = localB->BytePack1[0];
    rtb_Switch[1] = localB->BytePack[1];
    rtb_Switch[5] = localB->BytePack1[1];
    rtb_Switch[2] = localB->BytePack[2];
    rtb_Switch[6] = localB->BytePack1[2];
    rtb_Switch[3] = localB->BytePack[3];
    rtb_Switch[7] = localB->BytePack1[3];
  } else {
    rtb_Switch[0] = rtu_PARAMS[0];
    rtb_Switch[4] = rtu_PARAMS[4];
    rtb_Switch[1] = rtu_PARAMS[1];
    rtb_Switch[5] = rtu_PARAMS[5];
    rtb_Switch[2] = rtu_PARAMS[2];
    rtb_Switch[6] = rtu_PARAMS[6];
    rtb_Switch[3] = rtu_PARAMS[3];
    rtb_Switch[7] = rtu_PARAMS[7];
  }

  /* End of Switch: '<S6>/Switch' */

  /* MATLABSystem: '<S6>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_Switch[0], (size_t)8 * sizeof
           (uint8_T));
    status = MW_SCI_Transmit(localDW->obj.MW_SCIHANDLE, &TxDataLocChar[0], 8U);
  }

  /* End of MATLABSystem: '<S6>/Serial Transmit' */
}

/* Termination for function-call system: '<Root>/HARDWARE_TX_INTERFACE' */
void Assi_HARDWARE_TX_INTERFACE_Term(DW_HARDWARE_TX_INTERFACE_Assi_T *localDW)
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

/* Function for Chart: '<Root>/Chart' */
static void Assignment1_V4_Process_Rx(const uint8_T Rx_input[60], real_T
  output_set[15])
{
  int32_T c;
  int32_T i;
  int32_T i_0;
  int32_T ny;
  for (i = 0; i < 15; i++) {
    ny = i << 2;
    c = (i + 1) << 2;
    if (ny + 1 > c) {
      ny = 0;
      c = 0;
    }

    c -= ny;
    for (i_0 = 0; i_0 < c; i_0++) {
      Assignment1_V4_B.x_data[i_0] = Rx_input[ny + i_0];
    }

    if (c == 0) {
      ny = 0;
    } else {
      ny = c >> 2;
    }

    memcpy((void *)&Assignment1_V4_B.tmp_data[0], (void *)
           &Assignment1_V4_B.x_data[0], (size_t)ny * sizeof(uint32_T));
    output_set[i] = (real_T)Assignment1_V4_B.tmp_data[0] / 10.0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
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

/* Function for Chart: '<S10>/RATE_CTRL_SYSTEM' */
static real_T Assignment1__Calc_Rate_Response(real_T activity, real_T LRP,
  real_T MSP)
{
  real_T value;
  value = 1.0 / (2.6 * activity - 40.0) * 60.0 * 1000.0;
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

/* Function for Chart: '<S10>/RATE_CTRL_SYSTEM' */
static void Assignmen_Calc_Expo_Rate_Factor(real_T time_tgt, const real_T
  tgt_threshold[3], real_T output_set[3])
{
  Assignment1_V4_B.y = 1.0 / -time_tgt;
  output_set[0] = rt_powd_snf(tgt_threshold[0], Assignment1_V4_B.y);
  output_set[1] = rt_powd_snf(tgt_threshold[1], Assignment1_V4_B.y);
  output_set[2] = rt_powd_snf(tgt_threshold[2], Assignment1_V4_B.y);
}

/* Function for Chart: '<Root>/PACE_SYSTEM' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment1_V4_DW.sfEvent;
  Assignment1_V4_DW.sfEvent = Assignment1_V4_event_pace_compl;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V4();
  Assignment1_V4_DW.sfEvent = b_previousEvent;
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
  b_previousEvent = Assignment1_V4_DW.sfEvent;
  Assignment1_V4_DW.sfEvent = Assignment1_event_sense_timeout;

  /* Chart: '<Root>/PACE_SYSTEM' */
  Assignment1_V_c3_Assignment1_V4();
  Assignment1_V4_DW.sfEvent = b_previousEvent;
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
static void Assignment1_V_c3_Assignment1_V4(void)
{
  boolean_T guard1 = false;

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V4_DW.is_active_c3_Assignment1_V4 == 0U) {
    Assignment1_V4_DW.is_active_c3_Assignment1_V4 = 1U;
    Assignment1_V4_DW.is_c3_Assignment1_V4 = Assignment1_V4_IN_SENSE;
    Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Finish;
  } else {
    guard1 = false;
    switch (Assignment1_V4_DW.is_c3_Assignment1_V4) {
     case Assignment1_V4_IN_PACE:
      if (Assignment1_V4_DW.sfEvent == Assignment1_V4_event_pace_compl) {
        Assignment1_V4_DW.is_PACE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V4_DW.is_c3_Assignment1_V4 = Assignment1_V4_IN_SENSE;
        Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Finish;
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
            Assignment1_V4_B.ATR_PACE_CTRL = true;
            break;

           case Ventricle:
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Pace_Vent;
            Assignment1_V4_DW.temporalCounter_i1 = 0U;
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
              (Assignment1_V4_B.VectorConcatenate1[(int32_T)
               Assignment1_V4_B.PACE_CHAMBER - 1])) {
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V4_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment1_V4_IN_Pace_Vent:
          if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V4_B.VectorConcatenate1[(int32_T)
               Assignment1_V4_B.PACE_CHAMBER - 1])) {
            Assignment1_V4_DW.is_PACE = Assignment1_V4_IN_Charge;
            Assignment1_enter_atomic_Charge();
          } else {
            Assignment1_V4_B.VENT_PACE_CTRL = true;
          }
          break;
        }
      }
      break;

     case Assignment1_V4_IN_SENSE:
      if (Assignment1_V4_DW.sfEvent == Assignment1_event_sense_timeout) {
        Assignment1_V4_DW.tp_Sense_Detect = 0U;
        Assignment1_V4_DW.tp_Sense_Detected = 0U;
        Assignment1_V4_DW.tp_Sense_Fail = 0U;
        Assignment1_V4_DW.is_SENSE = Assignment1__IN_NO_ACTIVE_CHILD;
        Assignment1_V4_DW.is_c3_Assignment1_V4 = Assignment1_V4_IN_PACE;
        Assignment1_V4_DW.is_PACE = Assignment1_V_IN_Discharge_Prep;
        Assignment1_V4_B.PACING_REF_PWM = 0.0;
        Assignment1_V4_B.PACE_CHARGE_CTRL = false;
        Assignment1_V4_B.PACE_GND_CTRL = true;
        Assignment1_V4_B.ATR_GND_CTRL = false;
        Assignment1_V4_B.VENT_GND_CTRL = false;
      } else {
        switch (Assignment1_V4_DW.is_SENSE) {
         case Assignment1_V4_IN_Sense_Detect:
          if (Assignment1_V4_B.PACE_SENSE_RESPONSE == Nothing) {
            guard1 = true;
          } else if (Assignment1_V4_B.VectorConcatenate[(int32_T)
                     Assignment1_V4_B.PACE_SENSE_CHAMBER - 1]) {
            Assignment1_V4_DW.tp_Sense_Detect = 0U;
            Assignment1_V4_DW.is_SENSE = Assignment1_V_IN_Sense_Detected;
            Assignment1_V4_DW.tp_Sense_Detected = 1U;
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
          Assignment1_V4_B.red = 1.0;
          Assignment1_V4_B.green = 0.0;
          Assignment1_V4_B.blue = 0.0;
          break;

         case Assignment1_V_IN_Sense_Disabled:
          if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment1_V4_B.sense_timeout_threshold)) {
            Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Fail;
            Assignment1_V4_DW.tp_Sense_Fail = 1U;
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
            Assignment1_V4_B.red = 1.0;
            Assignment1_V4_B.green = 0.0;
            Assignment1_V4_B.blue = 0.0;
          } else {
            Assignment1_V4_DW.is_SENSE = Assignment1_V_IN_Sense_Disabled;
            Assignment1_V4_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Assignment1_V4_IN_Sense_Wait:
          if (Assignment1_V4_B.PACE_SENSE_RESPONSE == Nothing) {
            Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Fail;
            Assignment1_V4_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment1_V4_DW.temporalCounter_i1 >= (uint32_T)ceil
                     (Assignment1_V4_B.VectorConcatenate2[(int32_T)
                      Assignment1_V4_B.PACE_SENSE_CHAMBER - 1])) {
            Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Detect;
            Assignment1_V4_DW.temporalCounter_i1 = 0U;
            Assignment1_V4_DW.tp_Sense_Detect = 1U;
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
      }
      break;
    }

    if (guard1) {
      Assignment1_V4_DW.tp_Sense_Detect = 0U;
      Assignment1_V4_DW.is_SENSE = Assignment1_V4_IN_Sense_Fail;
      Assignment1_V4_DW.tp_Sense_Fail = 1U;
      Assignm_enter_atomic_Sense_Fail();
    }
  }

  /* End of Chart: '<Root>/PACE_SYSTEM' */
}

static void Assignment1_SystemCore_setup_lr(freedomk64f_SCIRead_Assignmen_T *obj)
{
  obj->isInitialized = 1;
  Assignment1_V4_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Assignment1_V4_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Assignment1_V4_B.SCIModuleLoc, false, 10U,
    Assignment1_V4_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Assignment1_V4_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Assignment1_V4_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, Assignment1_V4_B.ParityValue,
                        Assignment1_V4_B.StopBitsValue);
  obj->isSetupComplete = true;
}

static void Assignment1__SystemCore_setup_l(freedomk64f_fxos8700_Assignme_T *obj)
{
  obj->isInitialized = 1;
  Assignment1_V4_B.ModeType = MW_I2C_MASTER;
  Assignment1_V4_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(Assignment1_V4_B.i2cname,
    Assignment1_V4_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  Assignment1_V4_B.b_SwappedDataBytes[0] = 43U;
  Assignment1_V4_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Assignment1_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  OSA_TimeDelay(500U);
  Assignment1_V4_B.status = 42U;
  Assignment1_V4_B.status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
    &Assignment1_V4_B.status, 1U, true, false);
  if (Assignment1_V4_B.status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &Assignment1_V4_B.status,
                      1U, false, true);
    memcpy((void *)&Assignment1_V4_B.b_RegisterValue, (void *)
           &Assignment1_V4_B.status, (size_t)1 * sizeof(uint8_T));
  } else {
    Assignment1_V4_B.b_RegisterValue = 0U;
  }

  Assignment1_V4_B.b_SwappedDataBytes[0] = 42U;
  Assignment1_V4_B.b_SwappedDataBytes[1] = (uint8_T)
    (Assignment1_V4_B.b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Assignment1_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  Assignment1_V4_B.b_SwappedDataBytes[0] = 14U;
  Assignment1_V4_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Assignment1_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  Assignment1_V4_B.b_SwappedDataBytes[0] = 91U;
  Assignment1_V4_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Assignment1_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  Assignment1_V4_B.b_SwappedDataBytes[0] = 42U;
  Assignment1_V4_B.b_SwappedDataBytes[1] = 25U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Assignment1_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void Assignment1_V4_step(void)
{
  int32_T i;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;
  Pace_Rate_Mode rtb_PACE_RATE_MODE;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Assignment1_V4_DW.obj_c.SampleTime !=
      Assignment1_V4_P.SerialReceive_SampleTime) {
    Assignment1_V4_DW.obj_c.SampleTime =
      Assignment1_V4_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Assignment1_V4_DW.obj_c.MW_SCIHANDLE,
    &Assignment1_V4_B.RxDataLocChar[0], 64U);
  memcpy((void *)&Assignment1_V4_B.RxData[0], (void *)
         &Assignment1_V4_B.RxDataLocChar[0], (size_t)64 * sizeof(uint8_T));

  /* MATLABSystem: '<S5>/Analog Input' */
  if (Assignment1_V4_DW.obj_i.SampleTime !=
      Assignment1_V4_P.AnalogInput_SampleTime) {
    Assignment1_V4_DW.obj_i.SampleTime = Assignment1_V4_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE,
    &Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain2'
   *  MATLABSystem: '<S5>/Analog Input'
   */
  Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = floor(Assignment1_V4_P.Gain_Gain *
    Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 * Assignment1_V4_P.Gain2_Gain);
  if (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp < 2.147483648E+9) {
    if (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp >= -2.147483648E+9) {
      /* DataTypeConversion: '<S5>/Data Type Conversion' */
      Assignment1_V4_B.DataTypeConversion = (int32_T)
        Assignment1_V4_B.PACE_CHAMBER_tmp_tmp;
    } else {
      /* DataTypeConversion: '<S5>/Data Type Conversion' */
      Assignment1_V4_B.DataTypeConversion = MIN_int32_T;
    }
  } else {
    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    Assignment1_V4_B.DataTypeConversion = MAX_int32_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* MATLABSystem: '<S5>/Analog Input1' */
  if (Assignment1_V4_DW.obj_m.SampleTime !=
      Assignment1_V4_P.AnalogInput1_SampleTime) {
    Assignment1_V4_DW.obj_m.SampleTime =
      Assignment1_V4_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE,
    &Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain3'
   *  MATLABSystem: '<S5>/Analog Input1'
   */
  Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = floor(Assignment1_V4_P.Gain1_Gain *
    Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 * Assignment1_V4_P.Gain3_Gain);
  if (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp < 2.147483648E+9) {
    if (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp >= -2.147483648E+9) {
      /* DataTypeConversion: '<S5>/Data Type Conversion1' */
      Assignment1_V4_B.DataTypeConversion1 = (int32_T)
        Assignment1_V4_B.PACE_CHAMBER_tmp_tmp;
    } else {
      /* DataTypeConversion: '<S5>/Data Type Conversion1' */
      Assignment1_V4_B.DataTypeConversion1 = MIN_int32_T;
    }
  } else {
    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    Assignment1_V4_B.DataTypeConversion1 = MAX_int32_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion1' */

  /* Constant: '<S8>/Constant10' */
  Assignment1_V4_B.VectorConcatenate1_m[0] = Assignment1_V4_P.Constant10_Value;

  /* Constant: '<S8>/Constant' */
  Assignment1_V4_B.VectorConcatenate1_m[1] = Assignment1_V4_P.Constant_Value;

  /* Constant: '<S8>/Constant5' */
  Assignment1_V4_B.VectorConcatenate1_m[2] = Assignment1_V4_P.Constant5_Value;

  /* Constant: '<S8>/Constant9' */
  Assignment1_V4_B.VectorConcatenate1_m[3] = Assignment1_V4_P.Constant9_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  Assignment1_V4_B.VectorConcatenate1_m[4] = Assignment1_V4_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant3'
   */
  Assignment1_V4_B.VectorConcatenate1_m[5] = Assignment1_V4_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  Assignment1_V4_B.VectorConcatenate1_m[6] = Assignment1_V4_P.Constant2_Value_j;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  Assignment1_V4_B.VectorConcatenate1_m[7] = Assignment1_V4_P.Constant1_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant3'
   */
  Assignment1_V4_B.VectorConcatenate1_m[8] = Assignment1_V4_P.Constant3_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  Assignment1_V4_B.VectorConcatenate1_m[9] = Assignment1_V4_P.Constant2_Value_j;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  Assignment1_V4_B.VectorConcatenate1_m[10] = Assignment1_V4_P.Constant4_Value;

  /* SignalConversion generated from: '<Root>/Vector Concatenate1' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  Assignment1_V4_B.VectorConcatenate1_m[11] = Assignment1_V4_P.Constant4_Value;

  /* Constant: '<S8>/Constant6' */
  Assignment1_V4_B.VectorConcatenate1_m[12] = Assignment1_V4_P.Constant6_Value;

  /* Constant: '<S8>/Constant7' */
  Assignment1_V4_B.VectorConcatenate1_m[13] = Assignment1_V4_P.Constant7_Value;

  /* Constant: '<S8>/Constant8' */
  Assignment1_V4_B.VectorConcatenate1_m[14] = Assignment1_V4_P.Constant8_Value;

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant2'
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Assignment1_V4_DW.temporalCounter_i1_g < MAX_uint32_T) {
    Assignment1_V4_DW.temporalCounter_i1_g++;
  }

  if (Assignment1_V4_DW.is_active_c7_Assignment1_V4 == 0U) {
    Assignment1_V4_DW.is_active_c7_Assignment1_V4 = 1U;
    Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1_V4_IN_Init;
    for (i = 0; i < 15; i++) {
      Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 =
        Assignment1_V4_B.VectorConcatenate1_m[i];
      Assignment1_V4_B.Params_Arr[i] =
        Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0;
      Assignment1_V4_DW.Output_Candidate[i] =
        Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0;
    }
  } else {
    switch (Assignment1_V4_DW.is_c7_Assignment1_V4) {
     case Assignment1_V4_IN_Conv_Data:
      if (Assignment1_V4_DW.temporalCounter_i1_g >= 10U) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1_V4_IN_TX_Rxint_buf;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assignmen_HARDWARE_TX_INTERFACE(Assignment1_V4_B.TX_ctrlmode,
          &Assignment1_V4_DW.Rxint_buf[(Assignment1_V4_DW.iter - 1) << 3],
          Assignment1_V4_B.DataTypeConversion,
          Assignment1_V4_B.DataTypeConversion1,
          &Assignment1_V4_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V4_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V4_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        i = (int32_T)(Assignment1_V4_DW.iter + 1U);
        if (Assignment1_V4_DW.iter + 1U > 255U) {
          i = 255;
        }

        Assignment1_V4_DW.iter = (uint8_T)i;
      }
      break;

     case Assignment1__IN_Detect_Cur_Mode:
      Assignment1_V4_B.TX_ctrlmode = 1U;
      switch (Assignment1_V4_DW.Op_Mode) {
       case 286331153U:
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1__IN_Save_Buf_Params;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;
        memcpy(&Assignment1_V4_B.Params_Arr[0],
               &Assignment1_V4_DW.Output_Candidate[0], 15U * sizeof(real_T));
        break;

       case 286331136U:
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1_V4_IN_Conv_Data;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;
        Assignment1_V4_Process_Rx(&Assignment1_V4_DW.Rx_buf[4],
          Assignment1_V4_DW.Output_Candidate);
        memcpy(&Assignment1_V4_DW.Rxint_buf[0], &Assignment1_V4_DW.Rx_buf[0],
               sizeof(uint8_T) << 6U);
        Assignment1_V4_DW.iter = 1U;
        break;

       default:
        if ((Assignment1_V4_DW.Op_Mode != 286331136U) &&
            (Assignment1_V4_DW.Op_Mode != 286331153U)) {
          Assignment1_V4_DW.is_c7_Assignment1_V4 =
            Assignme_IN_ECG_TX_Loop_Standby;
          Assignment1_V4_DW.temporalCounter_i1_g = 0U;
          Assignment1_V4_B.TX_ctrlmode = 2U;
        }
        break;
      }
      break;

     case Assignme_IN_ECG_TX_Loop_Standby:
      Assignment1_V4_B.TX_ctrlmode = 2U;
      if (status == 0) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1__IN_Detect_Cur_Mode;
        memcpy(&Assignment1_V4_DW.Rx_buf[0], &Assignment1_V4_B.RxData[0], sizeof
               (uint8_T) << 6U);
        memcpy((void *)&Assignment1_V4_DW.Op_Mode, (void *)
               &Assignment1_V4_DW.Rx_buf[0], (size_t)1 * sizeof(uint32_T));
        Assignment1_V4_B.TX_ctrlmode = 1U;
      } else if (Assignment1_V4_DW.temporalCounter_i1_g >= 7U) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;
      }
      break;

     case Assignment1_V4_IN_Init:
      Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignme_IN_ECG_TX_Loop_Standby;
      Assignment1_V4_DW.temporalCounter_i1_g = 0U;
      Assignment1_V4_B.TX_ctrlmode = 2U;
      break;

     case Assignment1__IN_Save_Buf_Params:
      if (Assignment1_V4_DW.temporalCounter_i1_g >= 20U) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;
        Assignment1_V4_B.TX_ctrlmode = 2U;
      }
      break;

     case Assignment1_V4_IN_TX_Rxint_buf:
      if (Assignment1_V4_DW.iter >= 9) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1_V4_IN_TX_wait;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;
      } else if (status == 0) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1__IN_Detect_Cur_Mode;
        memcpy(&Assignment1_V4_DW.Rx_buf[0], &Assignment1_V4_B.RxData[0], sizeof
               (uint8_T) << 6U);
        memcpy((void *)&Assignment1_V4_DW.Op_Mode, (void *)
               &Assignment1_V4_DW.Rx_buf[0], (size_t)1 * sizeof(uint32_T));
        Assignment1_V4_B.TX_ctrlmode = 1U;
      } else if (Assignment1_V4_DW.temporalCounter_i1_g >= 10U) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1_V4_IN_TX_Rxint_buf;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;

        /* Outputs for Function Call SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assignmen_HARDWARE_TX_INTERFACE(Assignment1_V4_B.TX_ctrlmode,
          &Assignment1_V4_DW.Rxint_buf[(Assignment1_V4_DW.iter - 1) << 3],
          Assignment1_V4_B.DataTypeConversion,
          Assignment1_V4_B.DataTypeConversion1,
          &Assignment1_V4_B.HARDWARE_TX_INTERFACE,
          &Assignment1_V4_DW.HARDWARE_TX_INTERFACE,
          &Assignment1_V4_P.HARDWARE_TX_INTERFACE);

        /* End of Outputs for SubSystem: '<Root>/HARDWARE_TX_INTERFACE' */
        Assignment1_V4_DW.iter++;
      }
      break;

     default:
      /* case IN_TX_wait: */
      if (status == 0) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignment1__IN_Detect_Cur_Mode;
        memcpy(&Assignment1_V4_DW.Rx_buf[0], &Assignment1_V4_B.RxData[0], sizeof
               (uint8_T) << 6U);
        memcpy((void *)&Assignment1_V4_DW.Op_Mode, (void *)
               &Assignment1_V4_DW.Rx_buf[0], (size_t)1 * sizeof(uint32_T));
        Assignment1_V4_B.TX_ctrlmode = 1U;
      } else if (Assignment1_V4_DW.temporalCounter_i1_g >= (uint32_T)ceil
                 (Assignment1_V4_P.Constant2_Value)) {
        Assignment1_V4_DW.is_c7_Assignment1_V4 = Assignme_IN_ECG_TX_Loop_Standby;
        Assignment1_V4_DW.temporalCounter_i1_g = 0U;
        Assignment1_V4_B.TX_ctrlmode = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

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
  Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)
    (b_RegisterValue[1] >> 2) * 2.0 * 0.244 / 1000.0;
  Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)
    (b_RegisterValue[2] >> 2) * 2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */

  /* SignalConversion generated from: '<S18>/Vector Concatenate' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V4_B.Gain2[0] = Assignment1_V4_B.Params_Arr[4];

  /* SignalConversion generated from: '<S18>/Vector Concatenate' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V4_B.Gain2[1] = Assignment1_V4_B.Params_Arr[7];

  /* Gain: '<S18>/Gain2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate'
   */
  Assignment1_V4_B.Gain2[0] *= Assignment1_V4_P.Gain2_Gain_j;
  Assignment1_V4_B.Gain2[1] *= Assignment1_V4_P.Gain2_Gain_j;

  /* SignalConversion generated from: '<S18>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate2'
   */
  Assignment1_V4_B.VectorConcatenate2[0] = Assignment1_V4_B.Params_Arr[10];

  /* SignalConversion generated from: '<S18>/Vector Concatenate2' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate2'
   */
  Assignment1_V4_B.VectorConcatenate2[1] = Assignment1_V4_B.Params_Arr[11];

  /* SignalConversion generated from: '<S18>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[0] = Assignment1_V4_B.Params_Arr[5];

  /* SignalConversion generated from: '<S18>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S18>/Vector Concatenate1'
   */
  Assignment1_V4_B.VectorConcatenate1[1] = Assignment1_V4_B.Params_Arr[8];

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

  /* DataTypeConversion: '<S18>/Cast' */
  if (fabs(Assignment1_V4_B.Params_Arr[0]) < 4.503599627370496E+15) {
    if (Assignment1_V4_B.Params_Arr[0] > 0.5) {
      if (rt_remd_snf(Assignment1_V4_B.Params_Arr[0], 2.0) == 0.5) {
        Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = Assignment1_V4_B.Params_Arr[0];
      } else {
        Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = Assignment1_V4_B.Params_Arr[0] +
          0.5;
      }

      Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = floor
        (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp);
    } else if (Assignment1_V4_B.Params_Arr[0] >= -0.5) {
      Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = Assignment1_V4_B.Params_Arr[0] *
        0.0;
    } else {
      if (rt_remd_snf(Assignment1_V4_B.Params_Arr[0], 2.0) == -0.5) {
        Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = Assignment1_V4_B.Params_Arr[0];
      } else {
        Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = Assignment1_V4_B.Params_Arr[0] -
          0.5;
      }

      Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = ceil
        (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp);
    }
  } else {
    Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = Assignment1_V4_B.Params_Arr[0];
  }

  if (rtIsNaN(Assignment1_V4_B.PACE_CHAMBER_tmp_tmp) || rtIsInf
      (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp)) {
    Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = 0.0;
  } else {
    Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = fmod
      (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp, 4.294967296E+9);
  }

  /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S18>/Cast'
   *  Gain: '<S18>/Gain3'
   */
  Assignment1_V4_B.PACE_CHAMBER_tmp_tmp = (real_T)((uint64_T)
    (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
     -Assignment1_V4_B.PACE_CHAMBER_tmp_tmp : (uint32_T)
     Assignment1_V4_B.PACE_CHAMBER_tmp_tmp) * Assignment1_V4_P.Gain3_Gain_h) *
    3.7252902984619141E-9;
  Assignment1_V4_B.PACE_CHAMBER_tmp = Assignment1_V4_mod
    (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp, 1000.0);
  Assignment1_V4_B.PACE_CHAMBER = As_convert_to_enum_Pace_Chamber((int32_T)
    rt_roundd_snf((Assignment1_V4_mod(Assignment1_V4_B.PACE_CHAMBER_tmp_tmp,
    10000.0) - Assignment1_V4_B.PACE_CHAMBER_tmp) / 1000.0));
  Assignment1_V4_B.PACE_SENSE_CHAMBER_tmp = Assignment1_V4_mod
    (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp, 100.0);
  Assignment1_V4_B.PACE_SENSE_CHAMBER = convert_to_enum_Pace_Sense_Cham((int32_T)
    rt_roundd_snf((Assignment1_V4_B.PACE_CHAMBER_tmp -
                   Assignment1_V4_B.PACE_SENSE_CHAMBER_tmp) / 100.0));
  Assignment1_V4_B.PACE_CHAMBER_tmp = Assignment1_V4_mod
    (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp, 10.0);
  Assignment1_V4_B.PACE_SENSE_RESPONSE = convert_to_enum_Pace_Sense_Resp
    ((int32_T)rt_roundd_snf((Assignment1_V4_B.PACE_SENSE_CHAMBER_tmp -
       Assignment1_V4_B.PACE_CHAMBER_tmp) / 10.0));
  rtb_PACE_RATE_MODE = convert_to_enum_Pace_Rate_Mode((int32_T)rt_roundd_snf
    (Assignment1_V4_B.PACE_CHAMBER_tmp - Assignment1_V4_mod
     (Assignment1_V4_B.PACE_CHAMBER_tmp_tmp, 1.0)));

  /* MATLAB Function: '<S11>/MATLAB Function2' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<S16>/MATLAB Function'
   *  MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor'
   */
  if (Assignment1_V4_DW.init_counter < Assignment1_V4_P.Constant_Value_n) {
    Assignment1_V4_DW.init_counter++;
  }

  Assignment1_V4_DW.rolling_avg = sqrt
    ((Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 *
      Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 +
      Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_1 *
      Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_1) +
     Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_2 *
     Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_2) /
    Assignment1_V4_DW.init_counter + (Assignment1_V4_DW.init_counter - 1.0) *
    Assignment1_V4_DW.rolling_avg / Assignment1_V4_DW.init_counter;

  /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<S11>/MATLAB Function2'
   */
  i = 3;
  if (Assignment1_V4_P.Constant1_Value_i[1] > Assignment1_V4_DW.rolling_avg) {
    i = 2;
  }

  if (Assignment1_V4_P.Constant1_Value_i[0] > Assignment1_V4_DW.rolling_avg) {
    i = 1;
  }

  /* End of MATLAB Function: '<S12>/MATLAB Function' */

  /* Gain: '<S18>/Multiply' incorporates:
   *  Product: '<S18>/Reciprocal'
   */
  Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0 = 1.0 /
    Assignment1_V4_B.Params_Arr[1] * Assignment1_V4_P.Multiply_Gain;

  /* Chart: '<S10>/RATE_CTRL_SYSTEM' incorporates:
   *  Constant: '<S10>/Constant'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S18>/Gain4'
   *  Gain: '<S18>/Gain5'
   *  Gain: '<S18>/Multiply2'
   *  MATLAB Function: '<S11>/MATLAB Function2'
   *  Product: '<S18>/Reciprocal2'
   */
  if (Assignment1_V4_DW.temporalCounter_i1_a < 1U) {
    Assignment1_V4_DW.temporalCounter_i1_a = 1U;
  }

  if (Assignment1_V4_DW.is_active_c9_Assignment1_V4 == 0U) {
    Assignment1_V4_DW.is_active_c9_Assignment1_V4 = 1U;
    Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Init_a;
    Assignment1_V4_B.sense_timeout_threshold =
      Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0;
  } else {
    switch (Assignment1_V4_DW.is_c9_Assignment1_V4) {
     case Assignment1_V4_IN_Bigger:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_get_tgt;
      Assignment1_V4_B.dv[0] = 2.6;
      Assignment1_V4_B.dv[1] = -40.0;
      Assignment1_V4_DW.tgt = Assignment1__Calc_Rate_Response
        (Assignment1_V4_P.Gain_Gain_k * Assignment1_V4_DW.rolling_avg,
         Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 1.0 /
         Assignment1_V4_B.Params_Arr[3] * Assignment1_V4_P.Multiply2_Gain);
      break;

     case Assignment1_V4_IN_Detect_Mode:
      if (rtb_PACE_RATE_MODE == Disabled) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V_IN_Pace_LRL_Fixed;
        Assignment1_V4_B.sense_timeout_threshold =
          Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V_IN_Pace_Rate_Init;
        Assignmen_Calc_Expo_Rate_Factor(Assignment1_V4_P.Gain4_Gain *
          Assignment1_V4_B.Params_Arr[12], Assignment1_V4_P.Constant_Value_e,
          Assignment1_V4_DW.resp_fac_grow);
        Assignmen_Calc_Expo_Rate_Factor(Assignment1_V4_P.Gain5_Gain *
          Assignment1_V4_B.Params_Arr[14], Assignment1_V4_P.Constant_Value_e,
          Assignment1_V4_DW.resp_fac_decay);
      }
      break;

     case Assignment1_V4_IN_Init_a:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Detect_Mode;
      break;

     case Assignment1_V_IN_Pace_LRL_Fixed:
      if (rtb_PACE_RATE_MODE == Enabled) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Detect_Mode;
      } else {
        Assignment1_V4_B.sense_timeout_threshold =
          Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0;
      }
      break;

     case Assignment1_V_IN_Pace_Rate_Init:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_get_tgt;
      Assignment1_V4_B.dv[0] = 2.6;
      Assignment1_V4_B.dv[1] = -40.0;
      Assignment1_V4_DW.tgt = Assignment1__Calc_Rate_Response
        (Assignment1_V4_P.Gain_Gain_k * Assignment1_V4_DW.rolling_avg,
         Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 1.0 /
         Assignment1_V4_B.Params_Arr[3] * Assignment1_V4_P.Multiply2_Gain);
      break;

     case Assignment1_V4_IN_Smaller:
      Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_get_tgt;
      Assignment1_V4_B.dv[0] = 2.6;
      Assignment1_V4_B.dv[1] = -40.0;
      Assignment1_V4_DW.tgt = Assignment1__Calc_Rate_Response
        (Assignment1_V4_P.Gain_Gain_k * Assignment1_V4_DW.rolling_avg,
         Assignment1_V4_B.rtb_FXOS87006AxesSensor_idx_0, 1.0 /
         Assignment1_V4_B.Params_Arr[3] * Assignment1_V4_P.Multiply2_Gain);
      break;

     case Assignment1_V4_IN_check_dif:
      if (Assignment1_V4_DW.dif >= 0.0) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Bigger;
        Assignment1_V4_DW.temporalCounter_i1_a = 0U;
        Assignment1_V4_B.sense_timeout_threshold +=
          Assignment1_V4_DW.resp_fac_grow[i - 1] * Assignment1_V4_DW.dif;
      } else if (Assignment1_V4_DW.dif <= 0.0) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Smaller;
        Assignment1_V4_DW.temporalCounter_i1_a = 0U;
        Assignment1_V4_B.sense_timeout_threshold +=
          Assignment1_V4_DW.resp_fac_decay[i - 1] * Assignment1_V4_DW.dif;
      } else {
        Assignment1_V4_DW.dif = Assignment1_V4_DW.tgt -
          Assignment1_V4_B.sense_timeout_threshold;
      }
      break;

     default:
      /* case IN_get_tgt: */
      if (rtb_PACE_RATE_MODE != Disabled) {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_check_dif;
        Assignment1_V4_DW.dif = Assignment1_V4_DW.tgt -
          Assignment1_V4_B.sense_timeout_threshold;
      } else {
        Assignment1_V4_DW.is_c9_Assignment1_V4 = Assignment1_V4_IN_Detect_Mode;
      }
      break;
    }
  }

  /* End of Chart: '<S10>/RATE_CTRL_SYSTEM' */

  /* Chart: '<Root>/PACE_SYSTEM' */
  if (Assignment1_V4_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_V4_DW.temporalCounter_i1++;
  }

  Assignment1_V4_DW.sfEvent = -1;
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

  /* MATLABSystem: '<S5>/Digital Write1' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Boolean2'
   *  DataTypeConversion: '<S5>/Cast To Double'
   */
  MW_digitalIO_write(Assignment1_V4_DW.obj_d.MW_DIGITALIO_HANDLE, (int32_T)
                     Assignment1_V4_B.PACE_SENSE_RESPONSE != 0);

  /* MATLABSystem: '<S5>/PWM Output1' incorporates:
   *  Gain: '<S18>/Gain1'
   */
  MW_PWM_SetDutyCycle(Assignment1_V4_DW.obj_j.MW_PWM_HANDLE,
                      Assignment1_V4_P.Gain1_Gain_k *
                      Assignment1_V4_B.Params_Arr[9]);

  /* MATLABSystem: '<S5>/PWM Output' incorporates:
   *  Gain: '<S18>/Gain'
   */
  MW_PWM_SetDutyCycle(Assignment1_V4_DW.obj_dx.MW_PWM_HANDLE,
                      Assignment1_V4_P.Gain_Gain_c *
                      Assignment1_V4_B.Params_Arr[6]);

  /* MATLABSystem: '<S5>/Digital Write6' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_b.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S5>/Digital Write7' */
  MW_digitalIO_write(Assignment1_V4_DW.obj_o.MW_DIGITALIO_HANDLE, false);
}

/* Model initialize function */
void Assignment1_V4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    Assignment1_V4_B.PACE_CHAMBER = Atrium;
  }

  {
    freedomk64f_AnalogInput_Assig_T *obj;
    freedomk64f_DigitalRead_Assig_T *obj_0;
    freedomk64f_DigitalWrite_Assi_T *obj_1;
    freedomk64f_PWMOutput_Assignm_T *obj_2;

    /* SystemInitialize for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<Root>/HARDWARE_TX_INTERFACE'
     */
    Assi_HARDWARE_TX_INTERFACE_Init(&Assignment1_V4_DW.HARDWARE_TX_INTERFACE);

    /* SystemInitialize for Chart: '<Root>/PACE_SYSTEM' */
    Assignment1_V4_DW.sfEvent = -1;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Assignment1_V4_DW.obj_c.isInitialized = 0;
    Assignment1_V4_DW.obj_c.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_c.SampleTime =
      Assignment1_V4_P.SerialReceive_SampleTime;
    Assignment1_SystemCore_setup_lr(&Assignment1_V4_DW.obj_c);

    /* Start for MATLABSystem: '<S5>/Analog Input' */
    Assignment1_V4_DW.obj_i.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_i.SampleTime = Assignment1_V4_P.AnalogInput_SampleTime;
    obj = &Assignment1_V4_DW.obj_i;
    Assignment1_V4_DW.obj_i.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    Assignment1_V4_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V4_DW.obj_i.MW_ANALOGIN_HANDLE,
      Assignment1_V4_B.trigger_val, 0U);
    Assignment1_V4_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Analog Input1' */
    Assignment1_V4_DW.obj_m.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_m.SampleTime =
      Assignment1_V4_P.AnalogInput1_SampleTime;
    obj = &Assignment1_V4_DW.obj_m;
    Assignment1_V4_DW.obj_m.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    Assignment1_V4_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_V4_DW.obj_m.MW_ANALOGIN_HANDLE,
      Assignment1_V4_B.trigger_val, 0U);
    Assignment1_V4_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
    Assignment1_V4_DW.obj.isInitialized = 0;
    Assignment1_V4_DW.obj.i2cobj.isInitialized = 0;
    Assignment1_V4_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj.SampleTime =
      Assignment1_V4_P.FXOS87006AxesSensor_SampleTime;
    Assignment1__SystemCore_setup_l(&Assignment1_V4_DW.obj);

    /* Start for MATLABSystem: '<S5>/Digital Read1' */
    Assignment1_V4_DW.obj_ir.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_ir.SampleTime =
      Assignment1_V4_P.DigitalRead1_SampleTime;
    obj_0 = &Assignment1_V4_DW.obj_ir;
    Assignment1_V4_DW.obj_ir.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_V4_DW.obj_ir.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read' */
    Assignment1_V4_DW.obj_m4.matlabCodegenIsDeleted = false;
    Assignment1_V4_DW.obj_m4.SampleTime =
      Assignment1_V4_P.DigitalRead_SampleTime;
    obj_0 = &Assignment1_V4_DW.obj_m4;
    Assignment1_V4_DW.obj_m4.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_V4_DW.obj_m4.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    Assignment1_V4_DW.obj_ia.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_ia;
    Assignment1_V4_DW.obj_ia.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1_V4_DW.obj_ia.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    Assignment1_V4_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_p;
    Assignment1_V4_DW.obj_p.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Assignment1_V4_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    Assignment1_V4_DW.obj_fj.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_fj;
    Assignment1_V4_DW.obj_fj.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment1_V4_DW.obj_fj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Assignment1_V4_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_n;
    Assignment1_V4_DW.obj_n.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_V4_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Assignment1_V4_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_f;
    Assignment1_V4_DW.obj_f.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_V4_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Assignment1_V4_DW.obj_lo.matlabCodegenIsDeleted = false;
    obj_2 = &Assignment1_V4_DW.obj_lo;
    Assignment1_V4_DW.obj_lo.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V4_DW.obj_lo.MW_PWM_HANDLE);
    Assignment1_V4_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    Assignment1_V4_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_l;
    Assignment1_V4_DW.obj_l.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_V4_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write4' */
    Assignment1_V4_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_e;
    Assignment1_V4_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_V4_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    Assignment1_V4_DW.obj_o1.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_o1;
    Assignment1_V4_DW.obj_o1.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_V4_DW.obj_o1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    Assignment1_V4_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_a;
    Assignment1_V4_DW.obj_a.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_V4_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    Assignment1_V4_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_d;
    Assignment1_V4_DW.obj_d.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_V4_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output1' */
    Assignment1_V4_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_2 = &Assignment1_V4_DW.obj_j;
    Assignment1_V4_DW.obj_j.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V4_DW.obj_j.MW_PWM_HANDLE);
    Assignment1_V4_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output' */
    Assignment1_V4_DW.obj_dx.matlabCodegenIsDeleted = false;
    obj_2 = &Assignment1_V4_DW.obj_dx;
    Assignment1_V4_DW.obj_dx.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_V4_DW.obj_dx.MW_PWM_HANDLE);
    Assignment1_V4_DW.obj_dx.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write6' */
    Assignment1_V4_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_b;
    Assignment1_V4_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_V4_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write7' */
    Assignment1_V4_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_V4_DW.obj_o;
    Assignment1_V4_DW.obj_o.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_V4_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_V4_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Assignment1_V4_DW.obj_c.matlabCodegenIsDeleted) {
    Assignment1_V4_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Assignment1_V4_DW.obj_c.isInitialized == 1) &&
        Assignment1_V4_DW.obj_c.isSetupComplete) {
      MW_SCI_Close(Assignment1_V4_DW.obj_c.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

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

  /* Terminate for Chart: '<Root>/Chart' incorporates:
   *  SubSystem: '<Root>/HARDWARE_TX_INTERFACE'
   */
  Assi_HARDWARE_TX_INTERFACE_Term(&Assignment1_V4_DW.HARDWARE_TX_INTERFACE);

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

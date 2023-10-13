/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_1_Simulink.c
 *
 * Code generated for Simulink model 'Assignment_1_Simulink'.
 *
 * Model version                  : 2.18
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct 13 01:55:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment_1_Simulink.h"
#include "rtwtypes.h"
#include "Assignment_1_Simulink_types.h"
#include <math.h>

/* Named constants for Chart: '<Root>/Chart' */
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
static void broadcast_pace_compl_c3_Assignm(void);
static void Assignment__enter_atomic_Charge(void);
static void broadcast_sense_timeout_c3_Assi(void);
static void Assignm_enter_atomic_Sense_Fail(void);
static void Assign_c3_Assignment_1_Simulink(void);

/* Function for Chart: '<Root>/Chart' */
static void broadcast_pace_compl_c3_Assignm(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment_1_Simulink_DW.sfEvent;
  Assignment_1_Simulink_DW.sfEvent = Assignment_1_S_event_pace_compl;

  /* Chart: '<Root>/Chart' */
  Assign_c3_Assignment_1_Simulink();
  Assignment_1_Simulink_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Assignment__enter_atomic_Charge(void)
{
  Assignment_1_Simulink_B.PACE_GND_CTRL = true;

  /* Constant: '<Root>/Constant' */
  if (Assignment_1_Simulink_P.Constant_Value == 0.0) {
    Assignment_1_Simulink_B.ATR_GND_CTRL = true;
    Assignment_1_Simulink_B.VENT_GND_CTRL = false;
  } else {
    Assignment_1_Simulink_B.ATR_GND_CTRL = false;
    Assignment_1_Simulink_B.VENT_GND_CTRL = true;
  }

  /* End of Constant: '<Root>/Constant' */
  Assignment_1_Simulink_B.ATR_PACE_CTRL = false;
  Assignment_1_Simulink_B.VENT_PACE_CTRL = false;

  /* Constant: '<Root>/Constant1' */
  Assignment_1_Simulink_B.PACING_REF_PWM =
    Assignment_1_Simulink_P.Constant1_Value;
  Assignment_1_Simulink_B.PACE_CHARGE_CTRL = true;
  broadcast_pace_compl_c3_Assignm();
}

/* Function for Chart: '<Root>/Chart' */
static void broadcast_sense_timeout_c3_Assi(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Assignment_1_Simulink_DW.sfEvent;
  Assignment_1_Simulink_DW.sfEvent = Assignment__event_sense_timeout;

  /* Chart: '<Root>/Chart' */
  Assign_c3_Assignment_1_Simulink();
  Assignment_1_Simulink_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Assignm_enter_atomic_Sense_Fail(void)
{
  broadcast_sense_timeout_c3_Assi();
}

/* Function for Chart: '<Root>/Chart' */
static void Assign_c3_Assignment_1_Simulink(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   */
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
          if (Assignment_1_Simulink_P.Constant_Value == 0.0) {
            Assignment_1_Simulink_B.ATR_GND_CTRL = true;
            Assignment_1_Simulink_B.VENT_GND_CTRL = false;
          } else {
            Assignment_1_Simulink_B.ATR_GND_CTRL = false;
            Assignment_1_Simulink_B.VENT_GND_CTRL = true;
          }

          Assignment_1_Simulink_B.ATR_PACE_CTRL = false;
          Assignment_1_Simulink_B.VENT_PACE_CTRL = false;
          Assignment_1_Simulink_B.PACING_REF_PWM =
            Assignment_1_Simulink_P.Constant1_Value;
          Assignment_1_Simulink_B.PACE_CHARGE_CTRL = true;
          broadcast_pace_compl_c3_Assignm();
          break;

         case Assignment_1__IN_Discharge_Prep:
          if (Assignment_1_Simulink_P.Constant_Value == 0.0) {
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simuli_IN_Pace_Atr;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
            Assignment_1_Simulink_B.ATR_PACE_CTRL = true;
          } else if (Assignment_1_Simulink_P.Constant_Value == 1.0) {
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simul_IN_Pace_Vent;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
            Assignment_1_Simulink_B.VENT_PACE_CTRL = true;
          } else {
            Assignment_1_Simulink_B.PACE_CHARGE_CTRL = false;
            Assignment_1_Simulink_B.PACE_GND_CTRL = true;
            Assignment_1_Simulink_B.ATR_GND_CTRL = false;
            Assignment_1_Simulink_B.VENT_GND_CTRL = false;
          }
          break;

         case Assignment_1_Simuli_IN_Pace_Atr:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_P.Constant2_Value)) {
            Assignment_1_Simulink_DW.is_PACE = Assignment_1_Simulink_IN_Charge;
            Assignment__enter_atomic_Charge();
          } else {
            Assignment_1_Simulink_B.ATR_PACE_CTRL = true;
          }
          break;

         case Assignment_1_Simul_IN_Pace_Vent:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_P.Constant2_Value)) {
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
        Assignment_1_Simulink_B.PACE_CHARGE_CTRL = false;
        Assignment_1_Simulink_B.PACE_GND_CTRL = true;
        Assignment_1_Simulink_B.ATR_GND_CTRL = false;
        Assignment_1_Simulink_B.VENT_GND_CTRL = false;
      } else {
        switch (Assignment_1_Simulink_DW.is_SENSE) {
         case Assignment_1_Si_IN_Sense_Detect:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_P.Constant5_Value -
               Assignment_1_Simulink_P.Constant4_Value)) {
            Assignment_1_Simulink_DW.tp_Sense_Detect = 0U;
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Fail;
            Assignment_1_Simulink_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          } else if (Assignment_1_Simulink_B.VectorConcatenate[(int32_T)
                     Assignment_1_Simulink_P.Constant6_Value - 1]) {
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
              (Assignment_1_Simulink_P.Constant5_Value)) {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Fail;
            Assignment_1_Simulink_DW.tp_Sense_Fail = 1U;
            Assignm_enter_atomic_Sense_Fail();
          }
          break;

         case Assignment_1_Simu_IN_Sense_Fail:
          broadcast_sense_timeout_c3_Assi();
          break;

         case Assignment_1_Si_IN_Sense_Finish:
          if (Assignment_1_Simulink_P.Constant6_Value != 0.0) {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1_Simu_IN_Sense_Wait;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
          } else if (Assignment_1_Simulink_P.Constant6_Value == 0.0) {
            Assignment_1_Simulink_DW.is_SENSE = Assignment_1__IN_Sense_Disabled;
            Assignment_1_Simulink_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Assignment_1_Simu_IN_Sense_Wait:
          if (Assignment_1_Simulink_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Assignment_1_Simulink_P.Constant4_Value)) {
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

  /* End of Chart: '<Root>/Chart' */
}

/* Model step function */
void Assignment_1_Simulink_step(void)
{
  /* MATLABSystem: '<S3>/Digital Read' */
  if (Assignment_1_Simulink_DW.obj_b.SampleTime !=
      Assignment_1_Simulink_P.DigitalRead_SampleTime) {
    Assignment_1_Simulink_DW.obj_b.SampleTime =
      Assignment_1_Simulink_P.DigitalRead_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S3>/Cast To Boolean1'
   *  MATLABSystem: '<S3>/Digital Read'
   */
  Assignment_1_Simulink_B.VectorConcatenate[0] = MW_digitalIO_read
    (Assignment_1_Simulink_DW.obj_b.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S3>/Digital Read1' */
  if (Assignment_1_Simulink_DW.obj.SampleTime !=
      Assignment_1_Simulink_P.DigitalRead1_SampleTime) {
    Assignment_1_Simulink_DW.obj.SampleTime =
      Assignment_1_Simulink_P.DigitalRead1_SampleTime;
  }

  /* Concatenate: '<Root>/Vector Concatenate' incorporates:
   *  DataTypeConversion: '<S3>/Cast To Boolean'
   *  MATLABSystem: '<S3>/Digital Read1'
   */
  Assignment_1_Simulink_B.VectorConcatenate[1] = MW_digitalIO_read
    (Assignment_1_Simulink_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' */
  if (Assignment_1_Simulink_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment_1_Simulink_DW.temporalCounter_i1++;
  }

  Assignment_1_Simulink_DW.sfEvent = Assignment_1_Simulin_CALL_EVENT;
  Assign_c3_Assignment_1_Simulink();

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_g.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE,
                      Assignment_1_Simulink_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_bo.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_n2.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S3>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  MW_PWM_SetDutyCycle(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE,
                      Assignment_1_Simulink_P.Constant3_Value);

  /* MATLABSystem: '<S3>/PWM Output1' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  MW_PWM_SetDutyCycle(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE,
                      Assignment_1_Simulink_P.Constant7_Value);

  /* MATLABSystem: '<S3>/Digital Write1' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Assignment_1_Simulink_P.Constant8_Value);

  /* MATLABSystem: '<S3>/Digital Write6' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_m.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(Assignment_1_Simulink_DW.obj_i.MW_DIGITALIO_HANDLE, false);
}

/* Model initialize function */
void Assignment_1_Simulink_initialize(void)
{
  {
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Assignment_1_Simulink_DW.sfEvent = Assignment_1_Simulin_CALL_EVENT;

    /* Start for MATLABSystem: '<S3>/Digital Read' */
    Assignment_1_Simulink_DW.obj_b.matlabCodegenIsDeleted = false;
    Assignment_1_Simulink_DW.obj_b.SampleTime =
      Assignment_1_Simulink_P.DigitalRead_SampleTime;
    obj = &Assignment_1_Simulink_DW.obj_b;
    Assignment_1_Simulink_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment_1_Simulink_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Read1' */
    Assignment_1_Simulink_DW.obj.matlabCodegenIsDeleted = false;
    Assignment_1_Simulink_DW.obj.SampleTime =
      Assignment_1_Simulink_P.DigitalRead1_SampleTime;
    obj = &Assignment_1_Simulink_DW.obj;
    Assignment_1_Simulink_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment_1_Simulink_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    Assignment_1_Simulink_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_g;
    Assignment_1_Simulink_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment_1_Simulink_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Assignment_1_Simulink_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_h;
    Assignment_1_Simulink_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment_1_Simulink_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Assignment_1_Simulink_DW.obj_bn.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_Simulink_DW.obj_bn;
    Assignment_1_Simulink_DW.obj_bn.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE);
    Assignment_1_Simulink_DW.obj_bn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    Assignment_1_Simulink_DW.obj_bo.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_bo;
    Assignment_1_Simulink_DW.obj_bo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment_1_Simulink_DW.obj_bo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    Assignment_1_Simulink_DW.obj_n2.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_n2;
    Assignment_1_Simulink_DW.obj_n2.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment_1_Simulink_DW.obj_n2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    Assignment_1_Simulink_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_j;
    Assignment_1_Simulink_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment_1_Simulink_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    Assignment_1_Simulink_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_n;
    Assignment_1_Simulink_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment_1_Simulink_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    Assignment_1_Simulink_DW.obj_iw.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_Simulink_DW.obj_iw;
    Assignment_1_Simulink_DW.obj_iw.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE);
    Assignment_1_Simulink_DW.obj_iw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    Assignment_1_Simulink_DW.obj_mz.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_Simulink_DW.obj_mz;
    Assignment_1_Simulink_DW.obj_mz.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE);
    Assignment_1_Simulink_DW.obj_mz.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    Assignment_1_Simulink_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_a;
    Assignment_1_Simulink_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment_1_Simulink_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write6' */
    Assignment_1_Simulink_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_Simulink_DW.obj_m;
    Assignment_1_Simulink_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment_1_Simulink_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
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
  /* Terminate for MATLABSystem: '<S3>/Digital Read' */
  if (!Assignment_1_Simulink_DW.obj_b.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_b.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read1' */
  if (!Assignment_1_Simulink_DW.obj.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  if (!Assignment_1_Simulink_DW.obj_g.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_g.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!Assignment_1_Simulink_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_h.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  if (!Assignment_1_Simulink_DW.obj_bn.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_bn.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_bn.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_bn.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_Simulink_DW.obj_bn.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  if (!Assignment_1_Simulink_DW.obj_bo.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_bo.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_bo.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_bo.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_bo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  if (!Assignment_1_Simulink_DW.obj_n2.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_n2.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  if (!Assignment_1_Simulink_DW.obj_j.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_j.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  if (!Assignment_1_Simulink_DW.obj_n.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_n.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  if (!Assignment_1_Simulink_DW.obj_iw.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_iw.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_iw.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_iw.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_Simulink_DW.obj_iw.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM Output' */

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  if (!Assignment_1_Simulink_DW.obj_mz.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_mz.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_mz.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_mz.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_Simulink_DW.obj_mz.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  if (!Assignment_1_Simulink_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_a.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write6' */
  if (!Assignment_1_Simulink_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_m.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  if (!Assignment_1_Simulink_DW.obj_i.matlabCodegenIsDeleted) {
    Assignment_1_Simulink_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Assignment_1_Simulink_DW.obj_i.isInitialized == 1) &&
        Assignment_1_Simulink_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_Simulink_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

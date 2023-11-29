/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V5_private.h
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

#ifndef RTW_HEADER_Assignment1_V5_private_h_
#define RTW_HEADER_Assignment1_V5_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Assignment1_V5_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);

#endif                                /* RTW_HEADER_Assignment1_V5_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

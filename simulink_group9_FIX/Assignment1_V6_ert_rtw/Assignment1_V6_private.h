/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V6_private.h
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

#ifndef RTW_HEADER_Assignment1_V6_private_h_
#define RTW_HEADER_Assignment1_V6_private_h_
#include "rtwtypes.h"
#include "Assignment1_V6.h"
#include "Assignment1_V6_types.h"

extern void HARDWARE_TX_INTERFACE_Init(DW_HARDWARE_TX_INTERFACE_Assi_T *localDW);
extern void Assig_HARDWARE_TX_INTERFACE(uint8_T rtu_TX_CTRL_MODE, const uint8_T
  rtu_PARAMS[4], int16_T rtu_ATR_SIGNAL, int16_T rtu_VENT_SIGNAL,
  B_HARDWARE_TX_INTERFACE_Assig_T *localB, DW_HARDWARE_TX_INTERFACE_Assi_T
  *localDW, P_HARDWARE_TX_INTERFACE_Assig_T *localP);
extern void HARDWARE_TX_INTERFACE_Term(DW_HARDWARE_TX_INTERFACE_Assi_T *localDW);
extern void Assignm_UPDATE_EXP_FAC_Init(void);
extern void Assignment1__UPDATE_EXP_FAC(void);

#endif                                /* RTW_HEADER_Assignment1_V6_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

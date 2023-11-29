/*
 * Assignment1_V5_tgtconn.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Assignment1_V5".
 *
 * Model version              : 1.36
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Nov 29 02:38:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#define EXTERN_C
#include <stdio.h>
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "RTIOStreamTgtAppSvc/RTIOStreamTgtAppSvcCIntrf.h"

extern void initializeCommService( );
extern void terminateCommService();
EXTERN_C void TgtConnBackgroundTask()
{
}

EXTERN_C const char *TgtConnInit(int_T argc, char_T *argv[])
{
  const char *result = (NULL);         /* assume success */
  initializeCommService( );
  if (startToAsyncQueueTgtAppSvc()) {
    result = "Could not start ToAsyncQueue app service";
    return(result);
  }

  return(result);
}

EXTERN_C void TgtConnTerm()
{
  terminateCommService();
  terminateToAsyncQueueTgtAppSvc();
}

EXTERN_C void TgtConnPreStep(int_T tid)
{
}

EXTERN_C void TgtConnPostStep(int_T tid)
{
}

/* EOF: Assignment1_V5_tgtconn.c */

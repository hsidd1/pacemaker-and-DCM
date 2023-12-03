/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "Assignment1_V6_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "board.h"
#include "mw_cmsis_rtos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
mw_signal_event_t stopSem;
mw_signal_event_t baserateTaskSem;
mw_signal_event_t subrateTaskSem[1];
int taskId[1];
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
mw_thread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    mw_osSignalEventWaitEver(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;
    Assignment1_V6_step(subRateId);

    /* Get model outputs here */
  }

  mw_osThreadExit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(Assignment1_V6_M) == (NULL));
  while (runModel) {
    mw_osSignalEventWaitEver(&baserateTaskSem);
    if (rtmStepTask(Assignment1_V6_M, 1)
        ) {
      mw_osSignalEventRelease(&subrateTaskSem[0]);
    }

    Assignment1_V6_step(0);

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(Assignment1_V6_M) == (NULL)));
  }

  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(Assignment1_V6_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(mw_osSignalEventRelease(&subrateTaskSem[i]), 0,
                   "mw_osSignalEventRelease");
      CHECK_STATUS(mw_osSignalEventDelete(&subrateTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(mw_osThreadJoin(subRateThread[i], &threadJoinStatus), 0,
                   "mw_osThreadJoin");
    }

    runModel = 0;
  }

  /* Terminate model */
  Assignment1_V6_terminate();
  mw_osSignalEventRelease(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  subratePriority[0] = 41;
  SystemCoreClockUpdate();
  hardware_init();
  rtmSetErrorStatus(Assignment1_V6_M, 0);

  /* Initialize model */
  Assignment1_V6_initialize();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 1);

  /* Wait for stop semaphore */
  mw_osSignalEventWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSignalEventDelete(&timerTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

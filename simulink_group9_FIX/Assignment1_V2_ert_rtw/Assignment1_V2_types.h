/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1_V2_types.h
 *
 * Code generated for Simulink model 'Assignment1_V2'.
 *
 * Model version                  : 2.38
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 20 17:32:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. ROM efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_V2_types_h_
#define RTW_HEADER_Assignment1_V2_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef DEFINED_TYPEDEF_FOR_Pace_Mode_
#define DEFINED_TYPEDEF_FOR_Pace_Mode_

typedef enum {
  OFF = 0,                             /* Default value */
  DDD = 3330,
  VDD = 2330,
  DDI = 3310,
  DOO = 3000,
  AOO = 1000,
  AAI = 1110,
  VOO = 2000,
  VVI = 2210,
  AAT = 1120,
  VVT = 2220,
  DDDR = 3331,
  VDDR = 2331,
  DDIR = 3311,
  DOOR = 3001,
  AOOR = 1001,
  AAIR = 1111,
  VOOR = 2001,
  VVIR = 2211
} Pace_Mode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Pace_Chamber_
#define DEFINED_TYPEDEF_FOR_Pace_Chamber_

typedef enum {
  Atrium = 1,                          /* Default value */
  Ventricle,
  Dual
} Pace_Chamber;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Pace_Sense_Response_
#define DEFINED_TYPEDEF_FOR_Pace_Sense_Response_

typedef enum {
  Nothing = 0,                         /* Default value */
  Inhibit,
  Track,
  Dual_Response
} Pace_Sense_Response;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Pace_Sense_Chamber_
#define DEFINED_TYPEDEF_FOR_Pace_Sense_Chamber_

typedef enum {
  None_Sense = 0,                      /* Default value */
  Atrium_Sense,
  Ventricle_Sense,
  Dual_Sense
} Pace_Sense_Chamber;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Pace_Rate_Mode_
#define DEFINED_TYPEDEF_FOR_Pace_Rate_Mode_

typedef enum {
  Disabled = 0,                        /* Default value */
  Enabled
} Pace_Rate_Mode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rate_Motion_State_
#define DEFINED_TYPEDEF_FOR_Rate_Motion_State_

typedef enum {
  Low = 1,                             /* Default value */
  Medium,
  High
} Rate_Motion_State;

#endif

/* Custom Type definition for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_Assign_T
#define typedef_b_freedomk64f_Hardware_Assign_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_Assign_T;

#endif                             /* typedef_b_freedomk64f_Hardware_Assign_T */

#ifndef struct_tag_EkIWEs70Gs0LyfeXELZ2TC
#define struct_tag_EkIWEs70Gs0LyfeXELZ2TC

struct tag_EkIWEs70Gs0LyfeXELZ2TC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_EkIWEs70Gs0LyfeXELZ2TC */

#ifndef typedef_freedomk64f_DigitalWrite_Assi_T
#define typedef_freedomk64f_DigitalWrite_Assi_T

typedef struct tag_EkIWEs70Gs0LyfeXELZ2TC freedomk64f_DigitalWrite_Assi_T;

#endif                             /* typedef_freedomk64f_DigitalWrite_Assi_T */

#ifndef struct_tag_RYgVoAXTz61tXGMaBAGv7F
#define struct_tag_RYgVoAXTz61tXGMaBAGv7F

struct tag_RYgVoAXTz61tXGMaBAGv7F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_RYgVoAXTz61tXGMaBAGv7F */

#ifndef typedef_freedomk64f_PWMOutput_Assignm_T
#define typedef_freedomk64f_PWMOutput_Assignm_T

typedef struct tag_RYgVoAXTz61tXGMaBAGv7F freedomk64f_PWMOutput_Assignm_T;

#endif                             /* typedef_freedomk64f_PWMOutput_Assignm_T */

#ifndef struct_tag_q6HQSF2nXq6EjCNj0vbuLD
#define struct_tag_q6HQSF2nXq6EjCNj0vbuLD

struct tag_q6HQSF2nXq6EjCNj0vbuLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q6HQSF2nXq6EjCNj0vbuLD */

#ifndef typedef_freedomk64f_DigitalRead_Assig_T
#define typedef_freedomk64f_DigitalRead_Assig_T

typedef struct tag_q6HQSF2nXq6EjCNj0vbuLD freedomk64f_DigitalRead_Assig_T;

#endif                             /* typedef_freedomk64f_DigitalRead_Assig_T */

/* Custom Type definition for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
#include "MW_I2C.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_c_freedomk64f_Hardware_Assign_T
#define typedef_c_freedomk64f_Hardware_Assign_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB c_freedomk64f_Hardware_Assign_T;

#endif                             /* typedef_c_freedomk64f_Hardware_Assign_T */

#ifndef struct_tag_O0UAiliRyLLAe38ibfdAhE
#define struct_tag_O0UAiliRyLLAe38ibfdAhE

struct tag_O0UAiliRyLLAe38ibfdAhE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_freedomk64f_Hardware_Assign_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_O0UAiliRyLLAe38ibfdAhE */

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_O0UAiliRyLLAe38ibfdAhE b_freedomk64f_I2CMasterWrite__T;

#endif                             /* typedef_b_freedomk64f_I2CMasterWrite__T */

#ifndef struct_tag_v5Zyp5raUQrCF4f9Ln2EwE
#define struct_tag_v5Zyp5raUQrCF4f9Ln2EwE

struct tag_v5Zyp5raUQrCF4f9Ln2EwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /* struct_tag_v5Zyp5raUQrCF4f9Ln2EwE */

#ifndef typedef_freedomk64f_fxos8700_Assignme_T
#define typedef_freedomk64f_fxos8700_Assignme_T

typedef struct tag_v5Zyp5raUQrCF4f9Ln2EwE freedomk64f_fxos8700_Assignme_T;

#endif                             /* typedef_freedomk64f_fxos8700_Assignme_T */

/* Parameters (default storage) */
typedef struct P_Assignment1_V2_T_ P_Assignment1_V2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Assignment1_V2_T RT_MODEL_Assignment1_V2_T;

#endif                                 /* RTW_HEADER_Assignment1_V2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

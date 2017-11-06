/* Include files */

#include <stddef.h>
#include "blas.h"
#include "doc_agc_compare_rectifier_and_square_law_cgxe.h"
#include "m_3g8XYNgFlIfYagt3vDdQHF.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */
#define UpdatePeriod                   (10.0)
#define StepSize                       (0.1)
#define MaximumGain                    (30.0)
#define GainOutputPort                 (false)

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2014a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

static emlrtMCInfo b_emlrtMCI = { 20, 34, "eml_error",
  "C:\\Program Files\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\eml\\eml_error.m"
};

static emlrtBCInfo emlrtBCI = { 1, 100, 228, 24, "", "AGC",
  "C:\\Program Files\\MATLAB\\R2014a\\toolbox\\comm\\comm\\+comm\\AGC.m", 0 };

/* Function Declarations */
static void SystemCore_setup(comm_AGC *obj);
static void mw__internal__start___fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance);
static void mw__internal__initialize__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *
  moduleInstance);
static void mw__internal__outputs__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance);
static void mw__internal__update__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance);
static void mw__internal__terminate__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance);
static const mxArray *mw__internal__name__resolution__fcn(void);
static void info_helper(const mxArray **info);
static const mxArray *emlrt_marshallOut(const char * u);
static const mxArray *b_emlrt_marshallOut(const uint32_T u);
static void b_info_helper(const mxArray **info);
static void c_info_helper(const mxArray **info);
static const mxArray *mw__internal__autoInference__fcn(void);
static const mxArray *c_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_sizes[2]);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance);
static void emlrt_marshallIn(const mxArray *c_y0, const char_T *identifier,
  creal_T y[100]);
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, creal_T y[100]);
static real_T c_emlrt_marshallIn(const mxArray *b_Gain, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static comm_AGC e_emlrt_marshallIn(const mxArray *b_sysobj, const char_T
  *identifier);
static comm_AGC f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static boolean_T g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, uint32_T y[8]);
static void i_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static boolean_T j_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance, const mxArray *st);
static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location);
static void error(const mxArray *b, emlrtMCInfo *location);
static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, creal_T ret[100]);
static real_T l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static boolean_T m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, uint32_T ret[8]);
static void o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */
static void SystemCore_setup(comm_AGC *obj)
{
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 51 };

  const mxArray *m0;
  char_T cv0[51];
  int32_T i0;
  static char_T cv1[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 5 };

  char_T cv2[5];
  static char_T cv3[5] = { 's', 'e', 't', 'u', 'p' };

  comm_AGC *b_obj;
  static int8_T value[8] = { 100, 1, 1, 1, 1, 1, 1, 1 };

  if (obj->isInitialized) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i0 = 0; i0 < 51; i0++) {
      cv0[i0] = cv1[i0];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m0, cv0);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    for (i0 = 0; i0 < 5; i0++) {
      cv2[i0] = cv3[i0];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m0, cv2);
    emlrtAssign(&b_y, m0);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  b_obj = obj;
  b_obj->isInitialized = true;
  b_obj = obj;
  for (i0 = 0; i0 < 8; i0++) {
    b_obj->inputVarSize1[i0] = (uint32_T)value[i0];
  }

  b_obj = obj;
  b_obj->Gain = 1.0;
  b_obj = obj;
  b_obj->Gain = 1.0;
}

static void mw__internal__start___fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance)
{
  comm_AGC *obj;
  real_T *Gain;
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    moduleInstance->sysobj_not_empty = true;
  }

  SystemCore_setup(&moduleInstance->sysobj);
  *Gain = moduleInstance->sysobj.Gain;
}

static void mw__internal__initialize__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *
  moduleInstance)
{
  comm_AGC *obj;
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 45 };

  const mxArray *m1;
  char_T cv4[45];
  int32_T i1;
  static char_T cv5[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 8 };

  char_T cv6[8];
  static char_T cv7[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  boolean_T flag;
  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv5[2] = { 1, 5 };

  char_T cv8[5];
  static char_T cv9[5] = { 'r', 'e', 's', 'e', 't' };

  real_T *Gain;
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (obj->isReleased) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    for (i1 = 0; i1 < 45; i1++) {
      cv4[i1] = cv5[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    for (i1 = 0; i1 < 8; i1++) {
      cv6[i1] = cv7[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m1, cv6);
    emlrtAssign(&b_y, m1);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (obj->isReleased) {
      c_y = NULL;
      m1 = emlrtCreateCharArray(2, iv4);
      for (i1 = 0; i1 < 45; i1++) {
        cv4[i1] = cv5[i1];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
      emlrtAssign(&c_y, m1);
      d_y = NULL;
      m1 = emlrtCreateCharArray(2, iv5);
      for (i1 = 0; i1 < 5; i1++) {
        cv8[i1] = cv9[i1];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m1, cv8);
      emlrtAssign(&d_y, m1);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    if (obj->isInitialized) {
      obj->Gain = 1.0;
    }
  }

  *Gain = moduleInstance->sysobj.Gain;
}

static void mw__internal__outputs__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance)
{
  creal_T varargin_7[100];
  int32_T k;
  comm_AGC *obj;
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 45 };

  const mxArray *m2;
  char_T cv10[45];
  static char_T cv11[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 4 };

  char_T cv12[4];
  static char_T cv13[4] = { 's', 't', 'e', 'p' };

  boolean_T exitg1;
  static int8_T inputSize[8] = { 100, 1, 1, 1, 1, 1, 1, 1 };

  real_T g;
  creal_T c_y[100];
  real_T d_y[100];
  creal_T varargout_1[100];
  real_T s;
  real_T z[10];
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  int8_T indices[10];
  real_T *Gain;
  creal_T (*b_y0)[100];
  creal_T (*u0)[100];
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  b_y0 = (creal_T (*)[100])ssGetOutputPortSignal(moduleInstance->S, 0U);
  u0 = (creal_T (*)[100])ssGetInputPortSignal(moduleInstance->S, 0U);
  moduleInstance->sysobj.Gain = *Gain;
  for (k = 0; k < 100; k++) {
    varargin_7[k].re = (*u0)[k].re;
    varargin_7[k].im = (*u0)[k].im;
  }

  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (obj->isReleased) {
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv6);
    for (k = 0; k < 45; k++) {
      cv10[k] = cv11[k];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m2, cv10);
    emlrtAssign(&y, m2);
    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    for (k = 0; k < 4; k++) {
      cv12[k] = cv13[k];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m2, cv12);
    emlrtAssign(&b_y, m2);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  if (!obj->isInitialized) {
    SystemCore_setup(obj);
  }

  k = 0;
  exitg1 = false;
  while (exitg1 == false && k < 8) {
    if (obj->inputVarSize1[k] != (uint32_T)inputSize[k]) {
      for (k = 0; k < 8; k++) {
        obj->inputVarSize1[k] = (uint32_T)inputSize[k];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  g = obj->Gain;
  for (k = 0; k < 100; k++) {
    varargout_1[k].re = 0.0;
    varargout_1[k].im = 0.0;
    c_y[k].re = varargin_7[k].re;
    c_y[k].im = varargin_7[k].im;
    s = muDoubleScalarHypot(c_y[k].re, c_y[k].im);
    d_y[k] = s * s;
  }

  ix = -1;
  iy = -1;
  for (i = 0; i < 10; i++) {
    ixstart = ix;
    ix++;
    s = d_y[ixstart + 1];
    for (k = 0; k < 9; k++) {
      ix++;
      s += d_y[ix];
    }

    iy++;
    z[iy] = s;
  }

  for (k = 0; k < 10; k++) {
    indices[k] = (int8_T)(1 + k);
    z[k] /= 10.0;
  }

  for (ixstart = 0; ixstart < 10; ixstart++) {
    for (k = 0; k < 10; k++) {
      emlrtDynamicBoundsCheckFastR2012b((int32_T)indices[k], 1, 100, &emlrtBCI,
        emlrtRootTLSGlobal);
    }

    for (k = 0; k < 10; k++) {
      varargout_1[indices[k] - 1].re = g * varargin_7[indices[k] - 1].re;
      varargout_1[indices[k] - 1].im = g * varargin_7[indices[k] - 1].im;
    }

    g += StepSize * (1.0 - z[ixstart] * (g * g));
    if (g < 1.4901161193847656E-8) {
      g = 1.4901161193847656E-8;
    } else {
      if (g > 1000.0) {
        g = 1000.0;
      }
    }

    for (k = 0; k < 10; k++) {
      indices[k] = (int8_T)(indices[k] + 10);
    }
  }

  obj->Gain = g;
  for (k = 0; k < 100; k++) {
    (*b_y0)[k].re = varargout_1[k].re;
    (*b_y0)[k].im = varargout_1[k].im;
  }

  *Gain = moduleInstance->sysobj.Gain;
}

static void mw__internal__update__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance)
{
  real_T *Gain;
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  *Gain = moduleInstance->sysobj.Gain;
}

static void mw__internal__terminate__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance)
{
  comm_AGC *obj;
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 45 };

  const mxArray *m3;
  char_T cv14[45];
  int32_T i2;
  static char_T cv15[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv9[2] = { 1, 8 };

  char_T cv16[8];
  static char_T cv17[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  boolean_T flag;
  const mxArray *c_y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv11[2] = { 1, 7 };

  char_T cv18[7];
  static char_T cv19[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  real_T *Gain;
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (obj->isReleased) {
    y = NULL;
    m3 = emlrtCreateCharArray(2, iv8);
    for (i2 = 0; i2 < 45; i2++) {
      cv14[i2] = cv15[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, cv14);
    emlrtAssign(&y, m3);
    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv9);
    for (i2 = 0; i2 < 8; i2++) {
      cv16[i2] = cv17[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m3, cv16);
    emlrtAssign(&b_y, m3);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (obj->isReleased) {
      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv10);
      for (i2 = 0; i2 < 45; i2++) {
        cv14[i2] = cv15[i2];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, cv14);
      emlrtAssign(&c_y, m3);
      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv11);
      for (i2 = 0; i2 < 7; i2++) {
        cv18[i2] = cv19[i2];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m3, cv18);
      emlrtAssign(&d_y, m3);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    if (obj->isInitialized) {
      obj->isReleased = true;
    }
  }

  *Gain = moduleInstance->sysobj.Gain;
}

static const mxArray *mw__internal__name__resolution__fcn(void)
{
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = NULL;
  emlrtAssign(&nameCaptureInfo, emlrtCreateStructMatrix(164, 1, 0, NULL));
  info_helper(&nameCaptureInfo);
  b_info_helper(&nameCaptureInfo);
  c_info_helper(&nameCaptureInfo);
  emlrtNameCapturePostProcessR2013b(&nameCaptureInfo);
  return nameCaptureInfo;
}

static void info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 0);
  emlrtAddField(*info, emlrt_marshallOut("repmat"), "name", 0);
  emlrtAddField(*info, emlrt_marshallOut("struct"), "dominantType", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(1372589614U), "fileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 1);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 1);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 2);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_size_arg"), "name", 2);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "resolved", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(1368190230U), "fileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 3);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 3);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                "context", 4);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 4);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context", 5);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 5);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 6);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_integer_class"), "name", 6);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                "resolved", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825982U), "fileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 7);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 7);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context", 8);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 8);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(1381857500U), "fileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 9);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 9);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context", 10);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 10);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(1381857500U), "fileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 11);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexIntRelop"), "name",
                11);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                "resolved", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731922U), "fileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                "context", 12);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 12);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(1381857500U), "fileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                "context", 13);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 13);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                "context", 14);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 14);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 15);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 15);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 16);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 16);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 17);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 17);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(1311262516U), "fileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context", 18);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 18);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(1378303184U), "fileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 19);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 19);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                19);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311520U), "fileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 21);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 21);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311520U), "fileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 23);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 23);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 24);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 24);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                24);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 26);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 26);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311522U), "fileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 27);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 27);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(1388462290U), "fileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 28);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 28);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311522U), "fileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 29);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 29);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(1388462290U), "fileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 30);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.System"), "name",
                30);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "resolved", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(1388462288U), "fileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/matlab/system/+matlab/+system/+mixin/CustomIcon.p"),
                "context", 31);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 31);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311522U), "fileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 32);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.mixin.CustomIcon"),
                "name", 32);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/matlab/system/+matlab/+system/+mixin/CustomIcon.p"),
                "resolved", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(1388453428U), "fileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 32);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 33);
  emlrtAddField(*info, emlrt_marshallOut("comm.AGC"), "name", 33);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "resolved", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(1379180828U), "fileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 34);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 34);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(1388462290U), "fileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 35);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 35);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(1381857500U), "fileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 36);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 36);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 36);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(1388462290U), "fileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 36);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 37);
  emlrtAddField(*info, emlrt_marshallOut("repmat"), "name", 37);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(1372589614U), "fileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 38);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.cell"), "name", 38);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/cell.p"), "resolved",
                38);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311520U), "fileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 39);
  emlrtAddField(*info, emlrt_marshallOut("validateattributes"), "name", 39);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.cell"), "dominantType",
                39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m"),
                "resolved", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(1372589616U), "fileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m"),
                "context", 40);
  emlrtAddField(*info, emlrt_marshallOut("char"), "name", 40);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(1319737168U), "fileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m"),
                "context", 41);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 41);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(1381857500U), "fileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m!isintegral"),
                "context", 42);
  emlrtAddField(*info, emlrt_marshallOut("isfinite"), "name", 42);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                42);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context", 43);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 43);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context", 44);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 44);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context", 45);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 45);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717458U), "fileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context", 46);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 46);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m!isintegral"),
                "context", 47);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 47);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 48);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 48);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 49);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_floor"), "name", 49);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                "resolved", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825926U), "fileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m"),
                "context", 50);
  emlrtAddField(*info, emlrt_marshallOut("isfinite"), "name", 50);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                50);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m!all"),
                "context", 51);
  emlrtAddField(*info, emlrt_marshallOut("isfinite"), "name", 51);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                51);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m!notisnan"),
                "context", 52);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 52);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717458U), "fileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 53);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 53);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717458U), "fileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context", 54);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 54);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 55);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 55);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context", 56);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 56);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m"),
                "context", 57);
  emlrtAddField(*info, emlrt_marshallOut("iscolumn"), "name", 57);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/iscolumn.m"), "resolved", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(1346517558U), "fileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/validateattributes.m"),
                "context", 58);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_positive_integer_scalar"),
                "name", 58);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_positive_integer_scalar.m"),
                "resolved", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(1309458396U), "fileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_positive_integer_scalar.m"),
                "context", 59);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 59);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_positive_integer_scalar.m"),
                "context", 60);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 60);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 61);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 61);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 62);
  emlrtAddField(*info, emlrt_marshallOut("issparse"), "name", 62);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/sparfun/issparse.m"), "resolved",
                62);
  emlrtAddField(*info, b_emlrt_marshallOut(1286826030U), "fileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 63);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 63);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 63);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(1388463696U), "fileTimeLo", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(1370017086U), "mFileTimeLo", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 63);
}

static const mxArray *emlrt_marshallOut(const char * u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateString(u);
  emlrtAssign(&y, m4);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const uint32_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)mxGetData(m5) = u;
  emlrtAssign(&y, m5);
  return y;
}

static void b_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 64);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 64);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 65);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 65);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717480U), "fileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 66);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 66);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 67);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_compatible"), "name", 67);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                "resolved", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825996U), "fileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 68);
  emlrtAddField(*info, emlrt_marshallOut("eml_div"), "name", 68);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context", 69);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.div"), "name", 69);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                69);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311520U), "fileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 70);
  emlrtAddField(*info, emlrt_marshallOut("mpower"), "name", 70);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717478U), "fileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 71);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 71);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 72);
  emlrtAddField(*info, emlrt_marshallOut("ismatrix"), "name", 72);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                72);
  emlrtAddField(*info, b_emlrt_marshallOut(1331308458U), "fileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 73);
  emlrtAddField(*info, emlrt_marshallOut("power"), "name", 73);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717480U), "fileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context", 74);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 74);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                75);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 75);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                75);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                76);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 76);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311520U), "fileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                77);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 77);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 78);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                78);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(1389311520U), "fileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                79);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 79);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                "context", 80);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 80);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                80);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 81);
  emlrtAddField(*info, emlrt_marshallOut("eps"), "name", 81);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context", 82);
  emlrtAddField(*info, emlrt_marshallOut("eml_eps"), "name", 82);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context", 83);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 83);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 84);
  emlrtAddField(*info, emlrt_marshallOut("sqrt"), "name", 84);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(1343837586U), "fileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context", 85);
  emlrtAddField(*info, emlrt_marshallOut("eml_error"), "name", 85);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(1343837558U), "fileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context", 86);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sqrt"), "name", 86);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 86);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                "resolved", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825938U), "fileTimeLo", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 86);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 87);
  emlrtAddField(*info, emlrt_marshallOut("strncmp"), "name", 87);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 87);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmp.m"), "resolved",
                87);
  emlrtAddField(*info, b_emlrt_marshallOut(1328861522U), "fileTimeLo", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 87);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmp.m"), "context", 88);
  emlrtAddField(*info, emlrt_marshallOut("min"), "name", 88);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 88);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(1311262518U), "fileTimeLo", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 88);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context", 89);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 89);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 89);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(1378303184U), "fileTimeLo", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 89);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 90);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 90);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 90);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                90);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 90);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 90);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 90);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 90);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 91);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 91);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 91);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 91);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 92);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 92);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 92);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                92);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 92);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 93);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 93);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 93);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 93);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 94);
  emlrtAddField(*info, emlrt_marshallOut("length"), "name", 94);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 94);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(1303153406U), "fileTimeLo", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 94);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 95);
  emlrtAddField(*info, emlrt_marshallOut("mod"), "name", 95);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 95);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 95);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context", 96);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 96);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 96);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 96);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context", 97);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 97);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 97);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                97);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 97);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context", 98);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 98);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 98);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 98);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                99);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 99);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 99);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                99);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 99);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                100);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_floor"), "name", 100);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 100);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                "resolved", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825926U), "fileTimeLo", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 100);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                101);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_round"), "name", 101);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 101);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                "resolved", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(1307658438U), "fileTimeLo", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 101);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                102);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 102);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 102);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825912U), "fileTimeLo", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 102);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                103);
  emlrtAddField(*info, emlrt_marshallOut("eps"), "name", 103);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 103);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 103);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context", 104);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_float_class"), "name", 104);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 104);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                "resolved", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825982U), "fileTimeLo", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 104);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 105);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.errorIf"), "name", 105);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 105);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/errorIf.m"),
                "resolved", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(1334079138U), "fileTimeLo", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 105);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 106);
  emlrtAddField(*info, emlrt_marshallOut("reshape"), "name", 106);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 106);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "resolved",
                106);
  emlrtAddField(*info, b_emlrt_marshallOut(1378303182U), "fileTimeLo", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 106);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "context", 107);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 107);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 107);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 107);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size"),
                "context", 108);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 108);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 108);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 108);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty"),
                "context", 109);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 109);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 109);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 109);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                "context", 110);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 110);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 110);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 110);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                "context", 111);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_size_arg"), "name",
                111);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 111);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "resolved", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(1368190230U), "fileTimeLo", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 111);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                "context", 112);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexTimes"), "name",
                112);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 112);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                "resolved", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(1372590360U), "fileTimeLo", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 112);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "context", 113);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 113);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 113);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                113);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 113);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "context", 114);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 114);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 114);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 114);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 115);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 115);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 115);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 115);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/comm/comm/+comm/AGC.m!squarelaw"), "context", 116);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 116);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 116);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717452U), "fileTimeLo", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 116);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 117);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 117);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 117);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 117);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 118);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 118);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 118);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(1286825912U), "fileTimeLo", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 118);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "context", 119);
  emlrtAddField(*info, emlrt_marshallOut("eml_dlapy2"), "name", 119);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 119);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                119);
  emlrtAddField(*info, b_emlrt_marshallOut(1350417854U), "fileTimeLo", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 119);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/comm/comm/+comm/AGC.m!squarelaw"), "context", 120);
  emlrtAddField(*info, emlrt_marshallOut("power"), "name", 120);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 120);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717480U), "fileTimeLo", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 120);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/comm/comm/+comm/AGC.m!squarelaw"), "context", 121);
  emlrtAddField(*info, emlrt_marshallOut("mean"), "name", 121);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 121);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "resolved", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(1383880884U), "fileTimeLo", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 121);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 122);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 122);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 122);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 122);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 123);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 123);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 123);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 123);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 124);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assertValidDim"),
                "name", 124);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 124);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                "resolved", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(1372590360U), "fileTimeLo", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 124);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                "context", 125);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 125);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 125);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 125);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                "context", 126);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 126);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 126);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 126);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                "context", 127);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 127);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 127);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 127);
}

static void c_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 128);
  emlrtAddField(*info, emlrt_marshallOut("sum"), "name", 128);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 128);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717458U), "fileTimeLo", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 128);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 129);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 129);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 129);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 129);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 130);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_dim"), "name", 130);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 130);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                "resolved", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(1372589616U), "fileTimeLo", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 130);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                "context", 131);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assertValidDim"),
                "name", 131);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 131);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                "resolved", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(1372590360U), "fileTimeLo", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 131);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 132);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 132);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 132);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 132);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 133);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 133);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 133);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                133);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 133);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 134);
  emlrtAddField(*info, emlrt_marshallOut("eml_matrix_vstride"), "name", 134);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 134);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m"),
                "resolved", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(1360285950U), "fileTimeLo", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 134);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m"),
                "context", 135);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.prodsize"), "name", 135);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 135);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                "resolved", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(1360286188U), "fileTimeLo", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 135);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 136);
  emlrtAddField(*info, emlrt_marshallOut("eml_matrix_npages"), "name", 136);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 136);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m"),
                "resolved", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(1360285950U), "fileTimeLo", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 136);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m"),
                "context", 137);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.prodsize"), "name", 137);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 137);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                "resolved", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(1360286188U), "fileTimeLo", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 137);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 138);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 138);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 138);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 138);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 139);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_plus"), "name", 139);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 139);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                "resolved", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(1372589616U), "fileTimeLo", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 139);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                140);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                140);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 140);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(1372590360U), "fileTimeLo", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 140);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context", 141);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_plus"), "name", 141);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 141);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                "resolved", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(1372589616U), "fileTimeLo", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 141);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                142);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                142);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 142);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(1372590360U), "fileTimeLo", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 142);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 143);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 143);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 143);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717480U), "fileTimeLo", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 143);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 144);
  emlrtAddField(*info, emlrt_marshallOut("colon"), "name", 144);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 144);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(1378303188U), "fileTimeLo", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 144);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context", 145);
  emlrtAddField(*info, emlrt_marshallOut("colon"), "name", 145);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 145);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(1378303188U), "fileTimeLo", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 145);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context", 146);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 146);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 146);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 146);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                "context", 147);
  emlrtAddField(*info, emlrt_marshallOut("isfinite"), "name", 147);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 147);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                147);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717456U), "fileTimeLo", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 147);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                "context", 148);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 148);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 148);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 148);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                "context", 149);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 149);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 149);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                149);
  emlrtAddField(*info, b_emlrt_marshallOut(1375987888U), "fileTimeLo", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 149);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                "context", 150);
  emlrtAddField(*info, emlrt_marshallOut("flintmax"), "name", 150);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 150);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                150);
  emlrtAddField(*info, b_emlrt_marshallOut(1348199116U), "fileTimeLo", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 150);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "context",
                151);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 151);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 151);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 151);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                "context", 152);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 152);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 152);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717452U), "fileTimeLo", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 152);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                "context", 153);
  emlrtAddField(*info, emlrt_marshallOut("realmax"), "name", 153);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 153);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                153);
  emlrtAddField(*info, b_emlrt_marshallOut(1307658442U), "fileTimeLo", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 153);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context", 154);
  emlrtAddField(*info, emlrt_marshallOut("eml_realmax"), "name", 154);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 154);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                154);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 154);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                155);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 155);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 155);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(1326731596U), "fileTimeLo", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 155);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                "context", 156);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 156);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 156);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(1388463696U), "fileTimeLo", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(1370017086U), "mFileTimeLo", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 156);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                "context", 157);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 157);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 157);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717454U), "fileTimeLo", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 157);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                "context", 158);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 158);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 158);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(1323174178U), "fileTimeLo", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 158);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                "context", 159);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 159);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 159);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(1362265482U), "fileTimeLo", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 159);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 160);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 160);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 160);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(1381857500U), "fileTimeLo", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 160);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/comm/comm/+comm/AGC.m"), "context", 161);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 161);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 161);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(1383880894U), "fileTimeLo", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 161);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                "context", 162);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 162);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 162);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(1363718156U), "fileTimeLo", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 162);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/comm/comm/+comm/AGC.m!squarelawOutput"),
                "context", 163);
  emlrtAddField(*info, emlrt_marshallOut("mpower"), "name", 163);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 163);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(1363717478U), "fileTimeLo", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 163);
}

static const mxArray *mw__internal__autoInference__fcn(void)
{
  const mxArray *infoCache;
  int32_T Ports_dims_sizes[2];
  real_T Ports_dims_data[4];
  int32_T i3;
  static int8_T iv12[4] = { 100, 2, 100, 1 };

  int32_T dWork_dims_sizes[2];
  char_T dWork_names_data[4];
  real_T dWork_dims_data[4];
  static char_T cv20[4] = { 'G', 'a', 'i', 'n' };

  static int8_T iv13[4] = { 1, 2, 1, 1 };

  char_T t1_objTypeName[8];
  static char_T cv21[8] = { 'c', 'o', 'm', 'm', '_', 'A', 'G', 'C' };

  char_T t1_sysObjChksum[22];
  static char_T cv22[22] = { 'V', 'b', '7', 'Z', 'D', 'V', 'l', 'b', 'b', 'N',
    's', 'n', 'p', 'x', 'u', 'x', 'm', '2', 'd', 'j', '4', 'C' };

  int32_T t0_cgxeChksum[4];
  s7UBIGHSehQY1gCsIQWwr5C expl_temp;
  s7UBIGHSehQY1gCsIQWwr5C b_expl_temp;
  s7UBIGHSehQY1gCsIQWwr5C c_expl_temp;
  s7UBIGHSehQY1gCsIQWwr5C d_expl_temp;
  static int32_T iv14[4] = { 1208560223, 1749014256, 387078805, 258393017 };

  static uint32_T t2_chksum[4] = { 2849677891U, 2078296296U, 3109405731U,
    1746485466U };

  static int32_T t3_chksum[4] = { 725019261, 9350207, 1380543125, 1962202275 };

  static uint32_T t4_chksum[4] = { 2329432643U, 1966713464U, 3591173899U,
    2781510642U };

  static uint32_T t5_chksum[4] = { 1747284627U, 1764871863U, 1517832234U,
    4256061197U };

  s7UBIGHSehQY1gCsIQWwr5C checksums[4];
  char_T u_slVer[3];
  static char_T cv23[3] = { '8', '.', '3' };

  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m6;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  int32_T u_sizes[2];
  char_T u_data[4];
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m_y;
  static const int32_T iv15[2] = { 1, 8 };

  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  static const int32_T iv16[2] = { 1, 22 };

  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  int32_T b_u_sizes[2];
  const mxArray *v_y;
  real_T *pData;
  const mxArray *w_y;
  static const int32_T iv17[2] = { 1, 4 };

  int32_T i;
  const mxArray *x_y;
  s7UBIGHSehQY1gCsIQWwr5C u[4];
  const mxArray *y_y;
  const s7UBIGHSehQY1gCsIQWwr5C *r0;
  const mxArray *ab_y;
  static const int32_T iv18[2] = { 1, 4 };

  const mxArray *bb_y;
  static const int32_T iv19[2] = { 1, 3 };

  infoCache = NULL;
  Ports_dims_sizes[0] = 1;
  Ports_dims_sizes[1] = 4;
  for (i3 = 0; i3 < 4; i3++) {
    Ports_dims_data[i3] = (real_T)iv12[i3];
  }

  dWork_dims_sizes[0] = 1;
  dWork_dims_sizes[1] = 4;
  for (i3 = 0; i3 < 4; i3++) {
    dWork_names_data[i3] = cv20[i3];
    dWork_dims_data[i3] = (real_T)iv13[i3];
  }

  for (i3 = 0; i3 < 8; i3++) {
    t1_objTypeName[i3] = cv21[i3];
  }

  for (i3 = 0; i3 < 22; i3++) {
    t1_sysObjChksum[i3] = cv22[i3];
  }

  for (i3 = 0; i3 < 4; i3++) {
    t0_cgxeChksum[i3] = iv14[i3];
    expl_temp.chksum[i3] = (real_T)t2_chksum[i3];
    b_expl_temp.chksum[i3] = (real_T)t3_chksum[i3];
    c_expl_temp.chksum[i3] = (real_T)t4_chksum[i3];
    d_expl_temp.chksum[i3] = (real_T)t5_chksum[i3];
  }

  checksums[0] = expl_temp;
  checksums[1] = b_expl_temp;
  checksums[2] = c_expl_temp;
  checksums[3] = d_expl_temp;
  for (i3 = 0; i3 < 3; i3++) {
    u_slVer[i3] = cv23[i3];
  }

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  e_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&e_y, m6);
  emlrtAddField(d_y, e_y, "dimModes", 0);
  emlrtAddField(d_y, c_emlrt_marshallOut(Ports_dims_data, Ports_dims_sizes),
                "dims", 0);
  f_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&f_y, m6);
  emlrtAddField(d_y, f_y, "dType", 0);
  g_y = NULL;
  m6 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&g_y, m6);
  emlrtAddField(d_y, g_y, "complexity", 0);
  h_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&h_y, m6);
  emlrtAddField(d_y, h_y, "outputBuiltInDTEqUsed", 0);
  emlrtAddField(c_y, d_y, "Ports", 0);
  i_y = NULL;
  emlrtAssign(&i_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  u_sizes[0] = 1;
  u_sizes[1] = 4;
  for (i3 = 0; i3 < 4; i3++) {
    u_data[i3] = dWork_names_data[i3];
  }

  j_y = NULL;
  m6 = emlrtCreateCharArray(2, u_sizes);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, u_sizes[1], m6, (char_T *)&u_data);
  emlrtAssign(&j_y, m6);
  emlrtAddField(i_y, j_y, "names", 0);
  emlrtAddField(i_y, c_emlrt_marshallOut(dWork_dims_data, dWork_dims_sizes),
                "dims", 0);
  k_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&k_y, m6);
  emlrtAddField(i_y, k_y, "dType", 0);
  l_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&l_y, m6);
  emlrtAddField(i_y, l_y, "complexity", 0);
  emlrtAddField(c_y, i_y, "dWork", 0);
  m_y = NULL;
  m6 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m6, t1_objTypeName);
  emlrtAssign(&m_y, m6);
  emlrtAddField(c_y, m_y, "objTypeName", 0);
  n_y = NULL;
  m6 = emlrtCreateDoubleScalar(48.0);
  emlrtAssign(&n_y, m6);
  emlrtAddField(c_y, n_y, "objTypeSize", 0);
  o_y = NULL;
  for (i3 = 0; i3 < 2; i3++) {
    Ports_dims_sizes[i3] = 1 - i3;
  }

  emlrtAssign(&o_y, emlrtCreateStructArray(2, Ports_dims_sizes, 0, NULL));
  emlrtAddField(o_y, NULL, "names", 0);
  emlrtAddField(o_y, NULL, "dims", 0);
  emlrtAddField(o_y, NULL, "dType", 0);
  emlrtAddField(o_y, NULL, "dTypeSize", 0);
  emlrtAddField(o_y, NULL, "dTypeName", 0);
  emlrtAddField(o_y, NULL, "dTypeChksum", 0);
  emlrtAddField(o_y, NULL, "complexity", 0);
  emlrtAddField(c_y, o_y, "persisVarDWork", 0);
  p_y = NULL;
  m6 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 22, m6, t1_sysObjChksum);
  emlrtAssign(&p_y, m6);
  emlrtAddField(c_y, p_y, "sysObjChksum", 0);
  q_y = NULL;
  emlrtAssign(&q_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  r_y = NULL;
  for (i3 = 0; i3 < 2; i3++) {
    Ports_dims_sizes[i3] = 1 - i3;
  }

  emlrtAssign(&r_y, emlrtCreateStructArray(2, Ports_dims_sizes, 0, NULL));
  emlrtAddField(r_y, NULL, "Index", 0);
  emlrtAddField(r_y, NULL, "DataType", 0);
  emlrtAddField(r_y, NULL, "IsSigned", 0);
  emlrtAddField(r_y, NULL, "MantBits", 0);
  emlrtAddField(r_y, NULL, "FixExp", 0);
  emlrtAddField(r_y, NULL, "Slope", 0);
  emlrtAddField(r_y, NULL, "Bias", 0);
  emlrtAddField(q_y, r_y, "Out", 0);
  s_y = NULL;
  for (i3 = 0; i3 < 2; i3++) {
    Ports_dims_sizes[i3] = 1 - i3;
  }

  emlrtAssign(&s_y, emlrtCreateStructArray(2, Ports_dims_sizes, 0, NULL));
  emlrtAddField(s_y, NULL, "Index", 0);
  emlrtAddField(s_y, NULL, "DataType", 0);
  emlrtAddField(s_y, NULL, "IsSigned", 0);
  emlrtAddField(s_y, NULL, "MantBits", 0);
  emlrtAddField(s_y, NULL, "FixExp", 0);
  emlrtAddField(s_y, NULL, "Slope", 0);
  emlrtAddField(s_y, NULL, "Bias", 0);
  emlrtAddField(q_y, s_y, "DW", 0);
  t_y = NULL;
  for (i3 = 0; i3 < 2; i3++) {
    Ports_dims_sizes[i3] = 1 - i3;
  }

  emlrtAssign(&t_y, emlrtCreateStructArray(2, Ports_dims_sizes, 0, NULL));
  emlrtAddField(t_y, NULL, "Index", 0);
  emlrtAddField(t_y, NULL, "DataType", 0);
  emlrtAddField(t_y, NULL, "IsSigned", 0);
  emlrtAddField(t_y, NULL, "MantBits", 0);
  emlrtAddField(t_y, NULL, "FixExp", 0);
  emlrtAddField(t_y, NULL, "Slope", 0);
  emlrtAddField(t_y, NULL, "Bias", 0);
  emlrtAddField(q_y, t_y, "PersisDW", 0);
  emlrtAddField(c_y, q_y, "mapsInfo", 0);
  u_y = NULL;
  m6 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&u_y, m6);
  emlrtAddField(c_y, u_y, "objDWorkTypeNameIndex", 0);
  b_u_sizes[0] = 1;
  b_u_sizes[1] = 1;
  v_y = NULL;
  m6 = emlrtCreateNumericArray(2, b_u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  pData[0] = 0.0;
  emlrtAssign(&v_y, m6);
  emlrtAddField(c_y, v_y, "inputDFFlagsIndexField", 0);
  emlrtAddField(b_y, c_y, "DispatcherInfo", 0);
  w_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv17, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)t0_cgxeChksum[i];
  }

  emlrtAssign(&w_y, m6);
  emlrtAddField(b_y, w_y, "cgxeChksum", 0);
  emlrtAddField(y, b_y, "RestoreInfo", 0);
  x_y = NULL;
  emlrtAssign(&x_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  for (i3 = 0; i3 < 4; i3++) {
    u[i3] = checksums[i3];
  }

  y_y = NULL;
  for (i3 = 0; i3 < 2; i3++) {
    Ports_dims_sizes[i3] = 1 + 3 * i3;
  }

  emlrtAssign(&y_y, emlrtCreateStructArray(2, Ports_dims_sizes, 0, NULL));
  for (i3 = 0; i3 < 4; i3++) {
    r0 = &u[i3];
    for (i = 0; i < 4; i++) {
      Ports_dims_data[i] = r0->chksum[i];
    }

    ab_y = NULL;
    m6 = emlrtCreateNumericArray(2, iv18, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m6);
    for (i = 0; i < 4; i++) {
      pData[i] = Ports_dims_data[i];
    }

    emlrtAssign(&ab_y, m6);
    emlrtAddField(y_y, ab_y, "chksum", i3);
  }

  emlrtAddField(x_y, y_y, "checksums", 0);
  emlrtAddField(y, x_y, "VerificationInfo", 0);
  bb_y = NULL;
  m6 = emlrtCreateCharArray(2, iv19);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 3, m6, u_slVer);
  emlrtAssign(&bb_y, m6);
  emlrtAddField(y, bb_y, "slVer", 0);
  emlrtAssign(&infoCache, y);
  return infoCache;
}

static const mxArray *c_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_sizes[2])
{
  const mxArray *y;
  const mxArray *m7;
  real_T *pData;
  int32_T i4;
  int32_T i;
  y = NULL;
  m7 = emlrtCreateNumericArray(2, u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  i4 = 0;
  for (i = 0; i < u_sizes[1]; i++) {
    pData[i4] = u_data[u_sizes[0] * i];
    i4++;
  }

  emlrtAssign(&y, m7);
  return y;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  static const int32_T iv20[2] = { 100, 1 };

  const mxArray *m8;
  creal_T dcv0[100];
  int32_T i;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  static const int32_T iv21[2] = { 1, 8 };

  uint32_T *pData;
  const mxArray *h_y;
  static const int32_T iv22[2] = { 0, 0 };

  const mxArray *i_y;
  static const int32_T iv23[2] = { 0, 0 };

  const mxArray *j_y;
  const mxArray *k_y;
  real_T *Gain;
  creal_T (*b_y0)[100];
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  b_y0 = (creal_T (*)[100])ssGetOutputPortSignal(moduleInstance->S, 0U);
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(4, 1));
  b_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv20, mxDOUBLE_CLASS, mxCOMPLEX);
  for (i = 0; i < 100; i++) {
    dcv0[i].re = (*b_y0)[i].re;
    dcv0[i].im = (*b_y0)[i].im;
  }

  emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m8, dcv0, 8);
  emlrtAssign(&b_y, m8);
  emlrtSetCell(y, 0, b_y);
  c_y = NULL;
  m8 = emlrtCreateDoubleScalar(*Gain);
  emlrtAssign(&c_y, m8);
  emlrtSetCell(y, 1, c_y);
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  e_y = NULL;
  m8 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isInitialized);
  emlrtAssign(&e_y, m8);
  emlrtAddField(d_y, e_y, "isInitialized", 0);
  f_y = NULL;
  m8 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isReleased);
  emlrtAssign(&f_y, m8);
  emlrtAddField(d_y, f_y, "isReleased", 0);
  g_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv21, mxUINT32_CLASS, mxREAL);
  pData = (uint32_T *)mxGetData(m8);
  for (i = 0; i < 8; i++) {
    pData[i] = moduleInstance->sysobj.inputVarSize1[i];
  }

  emlrtAssign(&g_y, m8);
  emlrtAddField(d_y, g_y, "inputVarSize1", 0);
  h_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv22, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&h_y, m8);
  emlrtAddField(d_y, h_y, "pDetectorFunction", 0);
  i_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv23, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&i_y, m8);
  emlrtAddField(d_y, i_y, "pDetectorOutputFun", 0);
  j_y = NULL;
  m8 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Gain);
  emlrtAssign(&j_y, m8);
  emlrtAddField(d_y, j_y, "Gain", 0);
  emlrtSetCell(y, 2, d_y);
  k_y = NULL;
  m8 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&k_y, m8);
  emlrtSetCell(y, 3, k_y);
  emlrtAssign(&st, y);
  return st;
}

static void emlrt_marshallIn(const mxArray *c_y0, const char_T *identifier,
  creal_T y[100])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(c_y0), &thisId, y);
  emlrtDestroyArray(&c_y0);
}

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, creal_T y[100])
{
  k_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const mxArray *b_Gain, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(emlrtAlias(b_Gain), &thisId);
  emlrtDestroyArray(&b_Gain);
  return y;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static comm_AGC e_emlrt_marshallIn(const mxArray *b_sysobj, const char_T
  *identifier)
{
  comm_AGC y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(emlrtAlias(b_sysobj), &thisId);
  emlrtDestroyArray(&b_sysobj);
  return y;
}

static comm_AGC f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  comm_AGC y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[6] = { "isInitialized", "isReleased",
    "inputVarSize1", "pDetectorFunction", "pDetectorOutputFun", "Gain" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 6, fieldNames, 0U, 0);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "isReleased";
  y.isReleased = g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isReleased")), &thisId);
  thisId.fIdentifier = "inputVarSize1";
  h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "inputVarSize1")), &thisId, y.inputVarSize1);
  thisId.fIdentifier = "pDetectorFunction";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "pDetectorFunction")), &thisId);
  thisId.fIdentifier = "pDetectorOutputFun";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "pDetectorOutputFun")), &thisId);
  thisId.fIdentifier = "Gain";
  y.Gain = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Gain")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  boolean_T y;
  y = m_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, uint32_T y[8])
{
  n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  o_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static boolean_T j_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = g_emlrt_marshallIn(emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_3g8XYNgFlIfYagt3vDdQHF
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  real_T *Gain;
  creal_T (*b_y0)[100];
  Gain = (real_T *)ssGetDWork(moduleInstance->S, 0U);
  b_y0 = (creal_T (*)[100])ssGetOutputPortSignal(moduleInstance->S, 0U);
  u = emlrtAlias(st);
  emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, u, 0)), "y0",
                   *b_y0);
  *Gain = c_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, u, 1)),
    "Gain");
  moduleInstance->sysobj = e_emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, u, 2)), "sysobj");
  moduleInstance->sysobj_not_empty = j_emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, u, 3)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location)
{
  const mxArray *pArrays[2];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m9, 2, pArrays, "message",
    true, location);
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", true,
                        location);
}

static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, creal_T ret[100])
{
  int32_T iv24[2];
  int32_T i5;
  for (i5 = 0; i5 < 2; i5++) {
    iv24[i5] = 100 + -99 * i5;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", true, 2U,
    iv24);
  emlrtImportArrayR2011b(src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static real_T l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  boolean_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "logical", false, 0U,
    0);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, uint32_T ret[8])
{
  int32_T iv25[2];
  int32_T i6;
  for (i6 = 0; i6 < 2; i6++) {
    iv25[i6] = 1 + 7 * i6;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "uint32", false, 2U,
    iv25);
  for (i6 = 0; i6 < 8; i6++) {
    ret[i6] = (*(uint32_T (*)[8])mxGetData(src))[i6];
  }

  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  int32_T iv26[2];
  int32_T i7;
  for (i7 = 0; i7 < 2; i7++) {
    iv26[i7] = 0;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    iv26);
  emlrtDestroyArray(&src);
}

/* CGXE Glue Code */
static void mdlOutputs_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S, int_T tid)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__outputs__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlInitialize_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__initialize__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlUpdate_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S, int_T tid)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__update__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static mxArray* getSimState_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  mxArray* mxSS;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  return mxSS;
}

static void setSimState_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
  CGXERT_LEAVE_CHECK();
}

static void mdlTerminate_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__terminate__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  free((void *)moduleInstance);
  ssSetUserData(S, NULL);
}

static void mdlStart_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S)
{
  InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *moduleInstance;
  moduleInstance = (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF *)calloc(1, sizeof
    (InstanceStruct_3g8XYNgFlIfYagt3vDdQHF));
  moduleInstance->S = S;
  ssSetUserData(S, (void *)moduleInstance);
  CGXERT_ENTER_CHECK();
  mw__internal__start___fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }

  ssSetmdlOutputs(S, mdlOutputs_3g8XYNgFlIfYagt3vDdQHF);
  ssSetmdlInitializeConditions(S, mdlInitialize_3g8XYNgFlIfYagt3vDdQHF);
  ssSetmdlUpdate(S, mdlUpdate_3g8XYNgFlIfYagt3vDdQHF);
  ssSetmdlTerminate(S, mdlTerminate_3g8XYNgFlIfYagt3vDdQHF);
}

static void mdlProcessParameters_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S)
{
}

void method_dispatcher_3g8XYNgFlIfYagt3vDdQHF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_3g8XYNgFlIfYagt3vDdQHF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_3g8XYNgFlIfYagt3vDdQHF(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_3g8XYNgFlIfYagt3vDdQHF(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_3g8XYNgFlIfYagt3vDdQHF(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: 3g8XYNgFlIfYagt3vDdQHF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

int autoInfer_dispatcher_3g8XYNgFlIfYagt3vDdQHF(mxArray* plhs[], const char
  * commandName)
{
  if (strcmp(commandName, "NameResolution") == 0) {
    plhs[0] = (mxArray*) mw__internal__name__resolution__fcn();
    return 1;
  }

  if (strcmp(commandName, "AutoInfer") == 0) {
    plhs[0] = (mxArray*) mw__internal__autoInference__fcn();
    return 1;
  }

  return 0;
}

mxArray *cgxe_3g8XYNgFlIfYagt3vDdQHF_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  double * pointer;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_9 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_9);
  return mxBIArgs;
}

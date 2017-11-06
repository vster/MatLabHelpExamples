#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                doc_agc_compare_rectifier_and_square_law_cgxe
#include "simstruc.h"
#include "doc_agc_compare_rectifier_and_square_law_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_doc_agc_compare_rectifier_and_square_law_method_dispatcher(S,
    SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /*sf_mex_error_direct_call(S, "mdlInitializeConditions", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /*sf_mex_error_direct_call(S, "mdlUpdate", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  /*sf_mex_error_direct_call(S, "mdlOutputs", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlOUtputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  /*sf_mex_error_direct_call(S, "mdlOutputs", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(2, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1208560223;
  checksumData[1] = 1749014256;
  checksumData[2] = 387078805;
  checksumData[3] = 258393017;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2483455833;
  checksumData[1] = 3143229460;
  checksumData[2] = 590742560;
  checksumData[3] = 2886354950;
  mxSetCell(mxModules, 1, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 2357857682;
    checksumData[1] = 1083636621;
    checksumData[2] = 2979353738;
    checksumData[3] = 3934929946;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 497014585;
    checksumData[1] = 1077459614;
    checksumData[2] = 3043787981;
    checksumData[3] = 645877972;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 1635109058;
    checksumData[1] = 2120455702;
    checksumData[2] = 12658520;
    checksumData[3] = 3454939730;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 3253396788;
    checksumData[1] = 3514455237;
    checksumData[2] = 242271187;
    checksumData[3] = 1753689758;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  int *intPtr = (int*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(int);
  double *dblPtr = mxGetPr(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    intPtr[el] = (int)(dblPtr[el]);
  }

  S = *((SimStruct**)intPtr);
  free(intPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_doc_agc_compare_rectifier_and_square_law_method_dispatcher(S,
    SS_CALL_MDL_GET_SIM_STATE, (void *) (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_doc_agc_compare_rectifier_and_square_law_method_dispatcher(S,
    SS_CALL_MDL_SET_SIM_STATE, (void *) prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "3g8XYNgFlIfYagt3vDdQHF") == 0) {
    extern mxArray *cgxe_3g8XYNgFlIfYagt3vDdQHF_BuildInfoUpdate(void);
    plhs[0] = cgxe_3g8XYNgFlIfYagt3vDdQHF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "78j2nnVprvWzmWMRlG3Xo") == 0) {
    extern mxArray *cgxe_78j2nnVprvWzmWMRlG3Xo_BuildInfoUpdate(void);
    plhs[0] = cgxe_78j2nnVprvWzmWMRlG3Xo_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if ((strcmp(commandName, "NameResolution") == 0)||
      (strcmp(commandName, "AutoInfer") == 0)) {
    if (nrhs < 2 || !mxIsChar(prhs[1]))
      return 0;
    return cgxe_doc_agc_compare_rectifier_and_square_law_autoInfer_dispatcher
      (prhs[1], plhs, commandName);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_initialize") == 0) {
    cgxe_doc_agc_compare_rectifier_and_square_law_initializer();
    return 1;
  }

  if (strcmp(commandName, "mex_terminate") == 0) {
    cgxe_doc_agc_compare_rectifier_and_square_law_terminator();
    return 1;
  }

  return 0;
}

#include "simulink.c"

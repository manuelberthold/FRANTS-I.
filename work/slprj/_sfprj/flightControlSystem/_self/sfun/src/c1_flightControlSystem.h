#ifndef __c1_flightControlSystem_h__
#define __c1_flightControlSystem_h__

/* Type Definitions */
#ifndef struct_tag_saunyx6Vizcu70uPSJv7puF
#define struct_tag_saunyx6Vizcu70uPSJv7puF

struct tag_saunyx6Vizcu70uPSJv7puF
{
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
};

#endif                                 /*struct_tag_saunyx6Vizcu70uPSJv7puF*/

#ifndef typedef_c1_saunyx6Vizcu70uPSJv7puF
#define typedef_c1_saunyx6Vizcu70uPSJv7puF

typedef struct tag_saunyx6Vizcu70uPSJv7puF c1_saunyx6Vizcu70uPSJv7puF;

#endif                                 /*typedef_c1_saunyx6Vizcu70uPSJv7puF*/

#ifndef struct_tag_sHtk0WM4OMtyqkehwQYcq2
#define struct_tag_sHtk0WM4OMtyqkehwQYcq2

struct tag_sHtk0WM4OMtyqkehwQYcq2
{
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T Circularity;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
};

#endif                                 /*struct_tag_sHtk0WM4OMtyqkehwQYcq2*/

#ifndef typedef_c1_sHtk0WM4OMtyqkehwQYcq2
#define typedef_c1_sHtk0WM4OMtyqkehwQYcq2

typedef struct tag_sHtk0WM4OMtyqkehwQYcq2 c1_sHtk0WM4OMtyqkehwQYcq2;

#endif                                 /*typedef_c1_sHtk0WM4OMtyqkehwQYcq2*/

#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 /*struct_tag_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef typedef_c1_skA4KFEZ4HPkJJBOYCrevdH
#define typedef_c1_skA4KFEZ4HPkJJBOYCrevdH

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH c1_skA4KFEZ4HPkJJBOYCrevdH;

#endif                                 /*typedef_c1_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_c1_emxArray_real_T
#define typedef_c1_emxArray_real_T

typedef struct emxArray_real_T c1_emxArray_real_T;

#endif                                 /*typedef_c1_emxArray_real_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_c1_emxArray_int32_T
#define typedef_c1_emxArray_int32_T

typedef struct emxArray_int32_T c1_emxArray_int32_T;

#endif                                 /*typedef_c1_emxArray_int32_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_c1_emxArray_boolean_T
#define typedef_c1_emxArray_boolean_T

typedef struct emxArray_boolean_T c1_emxArray_boolean_T;

#endif                                 /*typedef_c1_emxArray_boolean_T*/

#ifndef typedef_c1_cell_wrap_17
#define typedef_c1_cell_wrap_17

typedef struct {
  c1_emxArray_real_T *f1;
} c1_cell_wrap_17;

#endif                                 /*typedef_c1_cell_wrap_17*/

#ifndef struct_emxArray_boolean_T_0x0
#define struct_emxArray_boolean_T_0x0

struct emxArray_boolean_T_0x0
{
  int32_T size[2];
};

#endif                                 /*struct_emxArray_boolean_T_0x0*/

#ifndef typedef_c1_emxArray_boolean_T_0x0
#define typedef_c1_emxArray_boolean_T_0x0

typedef struct emxArray_boolean_T_0x0 c1_emxArray_boolean_T_0x0;

#endif                                 /*typedef_c1_emxArray_boolean_T_0x0*/

#ifndef struct_emxArray_real_T_0
#define struct_emxArray_real_T_0

struct emxArray_real_T_0
{
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_0*/

#ifndef typedef_c1_emxArray_real_T_0
#define typedef_c1_emxArray_real_T_0

typedef struct emxArray_real_T_0 c1_emxArray_real_T_0;

#endif                                 /*typedef_c1_emxArray_real_T_0*/

#ifndef struct_emxArray_real_T_1x0
#define struct_emxArray_real_T_1x0

struct emxArray_real_T_1x0
{
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x0*/

#ifndef typedef_c1_emxArray_real_T_1x0
#define typedef_c1_emxArray_real_T_1x0

typedef struct emxArray_real_T_1x0 c1_emxArray_real_T_1x0;

#endif                                 /*typedef_c1_emxArray_real_T_1x0*/

#ifndef struct_tag_sKyE5zvueAoQJ4jaLWfzLx
#define struct_tag_sKyE5zvueAoQJ4jaLWfzLx

struct tag_sKyE5zvueAoQJ4jaLWfzLx
{
  real_T Area;
  real_T Centroid[2];
  real_T BoundingBox[4];
};

#endif                                 /*struct_tag_sKyE5zvueAoQJ4jaLWfzLx*/

#ifndef typedef_c1_sKyE5zvueAoQJ4jaLWfzLx
#define typedef_c1_sKyE5zvueAoQJ4jaLWfzLx

typedef struct tag_sKyE5zvueAoQJ4jaLWfzLx c1_sKyE5zvueAoQJ4jaLWfzLx;

#endif                                 /*typedef_c1_sKyE5zvueAoQJ4jaLWfzLx*/

#ifndef struct_emxArray_tag_sKyE5zvueAoQJ4jaLW
#define struct_emxArray_tag_sKyE5zvueAoQJ4jaLW

struct emxArray_tag_sKyE5zvueAoQJ4jaLW
{
  c1_sKyE5zvueAoQJ4jaLWfzLx *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_tag_sKyE5zvueAoQJ4jaLW*/

#ifndef typedef_c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx
#define typedef_c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx

typedef struct emxArray_tag_sKyE5zvueAoQJ4jaLW
  c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx;

#endif                                 /*typedef_c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx*/

#ifndef typedef_c1_images_internal_coder_strel_StructuringElementHelper
#define typedef_c1_images_internal_coder_strel_StructuringElementHelper

typedef struct {
  boolean_T Neighborhood[841];
  real_T Dimensionality;
} c1_images_internal_coder_strel_StructuringElementHelper;

#endif                                 /*typedef_c1_images_internal_coder_strel_StructuringElementHelper*/

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_c1_sJCxfmxS8gBOONUZjbjUd9E
#define typedef_c1_sJCxfmxS8gBOONUZjbjUd9E

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E c1_sJCxfmxS8gBOONUZjbjUd9E;

#endif                                 /*typedef_c1_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef struct_tag_scIvRXQeSh8yxCxSmtD63bE
#define struct_tag_scIvRXQeSh8yxCxSmtD63bE

struct tag_scIvRXQeSh8yxCxSmtD63bE
{
  real_T Connectivity;
  real_T ImageSize[2];
  real_T NumObjects;
  c1_emxArray_real_T *RegionIndices;
  c1_emxArray_int32_T *RegionLengths;
};

#endif                                 /*struct_tag_scIvRXQeSh8yxCxSmtD63bE*/

#ifndef typedef_c1_scIvRXQeSh8yxCxSmtD63bE
#define typedef_c1_scIvRXQeSh8yxCxSmtD63bE

typedef struct tag_scIvRXQeSh8yxCxSmtD63bE c1_scIvRXQeSh8yxCxSmtD63bE;

#endif                                 /*typedef_c1_scIvRXQeSh8yxCxSmtD63bE*/

#ifndef struct_saSFePUTm6OxDlygyb5SIGE_tag
#define struct_saSFePUTm6OxDlygyb5SIGE_tag

struct saSFePUTm6OxDlygyb5SIGE_tag
{
  real_T Area;
  real_T Centroid[2];
  real_T BoundingBox[4];
  real_T MajorAxisLength;
  real_T MinorAxisLength;
  real_T Eccentricity;
  real_T Orientation;
  c1_emxArray_boolean_T_0x0 Image;
  c1_emxArray_boolean_T_0x0 FilledImage;
  real_T FilledArea;
  real_T EulerNumber;
  real_T Extrema[16];
  real_T EquivDiameter;
  real_T Extent;
  c1_emxArray_real_T *PixelIdxList;
  c1_emxArray_real_T *PixelList;
  real_T Perimeter;
  real_T Circularity;
  c1_emxArray_real_T_0 PixelValues;
  real_T WeightedCentroid[2];
  real_T MeanIntensity;
  real_T MinIntensity;
  real_T MaxIntensity;
  c1_emxArray_real_T_1x0 SubarrayIdx;
  real_T SubarrayIdxLengths[2];
};

#endif                                 /*struct_saSFePUTm6OxDlygyb5SIGE_tag*/

#ifndef typedef_c1_s9uuw2Xu7QLvohu1q5iD2hG
#define typedef_c1_s9uuw2Xu7QLvohu1q5iD2hG

typedef struct saSFePUTm6OxDlygyb5SIGE_tag c1_s9uuw2Xu7QLvohu1q5iD2hG;

#endif                                 /*typedef_c1_s9uuw2Xu7QLvohu1q5iD2hG*/

#ifndef struct_emxArray_saSFePUTm6OxDlygyb5SIG
#define struct_emxArray_saSFePUTm6OxDlygyb5SIG

struct emxArray_saSFePUTm6OxDlygyb5SIG
{
  c1_s9uuw2Xu7QLvohu1q5iD2hG *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_saSFePUTm6OxDlygyb5SIG*/

#ifndef typedef_c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h
#define typedef_c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h

typedef struct emxArray_saSFePUTm6OxDlygyb5SIG
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h;

#endif                                 /*typedef_c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h*/

#ifndef typedef_SFc1_flightControlSystemInstanceStruct
#define typedef_SFc1_flightControlSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_flightControlSystem;
  uint8_T c1_JITStateAnimation[1];
  uint8_T c1_JITTransitionAnimation[1];
  void *c1_RuntimeVar;
  uint32_T c1_mlFcnLineNumber;
  void *c1_fcnDataPtrs[13];
  char_T *c1_dataNames[13];
  uint32_T c1_numFcnVars;
  uint32_T c1_ssIds[13];
  uint32_T c1_statuses[13];
  void *c1_outMexFcns[13];
  void *c1_inMexFcns[13];
  boolean_T c1_Apad[38804];
  boolean_T c1_Apadpre[33456];
  boolean_T c1_Ap[28500];
  boolean_T c1_b_bv1[28500];
  boolean_T c1_A[28500];
  uint8_T c1_red[19200];
  boolean_T c1_b_Apad[38804];
  boolean_T c1_b_Apadpre[33456];
  boolean_T c1_b_A[28500];
  uint8_T c1_green[19200];
  CovrtStateflowInstance *c1_covrtInstance;
  void *c1_fEmlrtCtx;
  uint8_T (*c1_b_red)[19200];
  uint8_T (*c1_b_green)[19200];
  boolean_T *c1_IsFireFound;
  uint8_T (*c1_blue)[19200];
} SFc1_flightControlSystemInstanceStruct;

#endif                                 /*typedef_SFc1_flightControlSystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[]);
extern void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

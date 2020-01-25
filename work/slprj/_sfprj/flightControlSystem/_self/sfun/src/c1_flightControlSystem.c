/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c1_emlrtRSI = { 8,  /* lineNo */
  "detectfire",                        /* fcnName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 9,/* lineNo */
  "detectfire",                        /* fcnName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 10,/* lineNo */
  "detectfire",                        /* fcnName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 14,/* lineNo */
  "detectfire",                        /* fcnName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 15,/* lineNo */
  "detectfire",                        /* fcnName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 16,/* lineNo */
  "detectfire",                        /* fcnName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 3,/* lineNo */
  "Image Processing System/isFireFoundDetector ",/* fcnName */
  "#flightControlSystem:2227"          /* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 93,/* lineNo */
  "imclose",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\imclose.m"/* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 98,/* lineNo */
  "imdilate",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\imdilate.m"/* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 17,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 435,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 645,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 683,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 37,/* lineNo */
  "bwpack",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwpack.m"/* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 880,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 37,/* lineNo */
  "bwunpack",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwunpack.m"/* pathName */
};

static emlrtRSInfo c1_q_emlrtRSI = { 87,/* lineNo */
  "imerode",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\imerode.m"/* pathName */
};

static emlrtRSInfo c1_r_emlrtRSI = { 886,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_s_emlrtRSI = { 190,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c1_t_emlrtRSI = { 21,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c1_u_emlrtRSI = { 76,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_v_emlrtRSI = { 32,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_w_emlrtRSI = { 73,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_x_emlrtRSI = { 75,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_y_emlrtRSI = { 78,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ab_emlrtRSI = { 87,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_bb_emlrtRSI = { 99,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_cb_emlrtRSI = { 115,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_db_emlrtRSI = { 197,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_eb_emlrtRSI = { 23,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_fb_emlrtRSI = { 44,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_gb_emlrtRSI = { 57,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_hb_emlrtRSI = { 69,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ib_emlrtRSI = { 70,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_jb_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_kb_emlrtRSI = { 79,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_lb_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_mb_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_nb_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_ob_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_pb_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_qb_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo c1_rb_emlrtRSI = { 96,/* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo c1_sb_emlrtRSI = { 124,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c1_tb_emlrtRSI = { 184,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c1_ub_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pathName */
};

static emlrtRSInfo c1_vb_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_wb_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo c1_xb_emlrtRSI = { 99,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_yb_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_ac_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c1_bc_emlrtRSI = { 1260,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_cc_emlrtRSI = { 1826,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_dc_emlrtRSI = { 28,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c1_ec_emlrtRSI = { 295,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_fc_emlrtRSI = { 422,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_gc_emlrtRSI = { 418,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_hc_emlrtRSI = { 768,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ic_emlrtRSI = { 770,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_jc_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c1_kc_emlrtRSI = { 22,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c1_lc_emlrtRSI = { 102,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c1_mc_emlrtRSI = { 49,/* lineNo */
  "mean",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pathName */
};

static emlrtRSInfo c1_nc_emlrtRSI = { 545,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_oc_emlrtRSI = { 544,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_pc_emlrtRSI = { 534,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_qc_emlrtRSI = { 14,/* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo c1_rc_emlrtRSI = { 20,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_sc_emlrtRSI = { 45,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_tc_emlrtRSI = { 167,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_uc_emlrtRSI = { 326,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_vc_emlrtRSI = { 394,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_wc_emlrtRSI = { 476,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_xc_emlrtRSI = { 14,/* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo c1_yc_emlrtRSI = { 40,/* lineNo */
  "arrayfun",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datatypes\\arrayfun.m"/* pathName */
};

static emlrtRSInfo c1_ad_emlrtRSI = { 49,/* lineNo */
  "arrayfun",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datatypes\\arrayfun.m"/* pathName */
};

static emlrtRSInfo c1_bd_emlrtRSI = { 63,/* lineNo */
  "arrayfun",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datatypes\\arrayfun.m"/* pathName */
};

static emlrtRSInfo c1_cd_emlrtRSI = { 69,/* lineNo */
  "arrayfun",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datatypes\\arrayfun.m"/* pathName */
};

static emlrtRSInfo c1_dd_emlrtRSI = { 23,/* lineNo */
  "outputScalarEg",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\outputScalarEg.m"/* pathName */
};

static emlrtRSInfo c1_ed_emlrtRSI = { 29,/* lineNo */
  "outputScalarEg",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\outputScalarEg.m"/* pathName */
};

static emlrtRSInfo c1_fd_emlrtRSI = { 16,/* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo c1_gd_emlrtRSI = { 17,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_hd_emlrtRSI = { 43,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_id_emlrtRSI = { 131,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_jd_emlrtRSI = { 932,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_kd_emlrtRSI = { 992,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 184,/* lineNo */
  13,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 184,/* lineNo */
  22,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 40,/* lineNo */
  23,                                  /* colNo */
  "arrayfun",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datatypes\\arrayfun.m"/* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "detectfire",                        /* fName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "detectfire",                        /* fName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m"/* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 1826,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 318,/* lineNo */
  30,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 422,/* lineNo */
  34,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_k_emlrtRTEI = { 540,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_l_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_m_emlrtRTEI = { 78,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_n_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_o_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_p_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_q_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_r_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_s_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_t_emlrtRTEI = { 70,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_u_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_v_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_w_emlrtRTEI = { 90,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_x_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_y_emlrtRTEI = { 11,/* lineNo */
  19,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_ab_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_bb_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_cb_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_db_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_eb_emlrtRTEI = { 1711,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_fb_emlrtRTEI = { 204,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_gb_emlrtRTEI = { 754,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_hb_emlrtRTEI = { 291,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ib_emlrtRTEI = { 292,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_jb_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_kb_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_lb_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_mb_emlrtRTEI = { 233,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_nb_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ob_emlrtRTEI = { 767,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_pb_emlrtRTEI = { 768,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_qb_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_rb_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_sb_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_tb_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_ub_emlrtRTEI = { 44,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_vb_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_wb_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_xb_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_yb_emlrtRTEI = { 110,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c1_ac_emlrtRTEI = { 117,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c1_bc_emlrtRTEI = { 770,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_cc_emlrtRTEI = { 768,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c1_dc_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtECInfo c1_emlrtECI = { -1, /* nDims */
  184,                                 /* lineNo */
  9,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtBCInfo c1_emlrtBCI = { 1,  /* iFirst */
  122,                                 /* iLast */
  209,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_emlrtDCI = { 209,/* lineNo */
  27,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_b_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  209,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_c_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  209,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_d_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  209,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_e_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  209,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  12,                                  /* colNo */
  "s",                                 /* aName */
  "detectfire",                        /* fName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_b_emlrtDCI = { 18,/* lineNo */
  12,                                  /* colNo */
  "detectfire",                        /* fName */
  "C:\\Users\\asslaberverena\\MATLAB\\Projects\\examples\\parrotMinidroneCompetition5\\utilities\\detectfire.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1882,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1884,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  422,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  542,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1885,                                /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1885,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  546,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  422,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  540,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  540,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_c_emlrtDCI = { 48,/* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_d_emlrtDCI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_e_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c1_f_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_yb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  772,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  770,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  767,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  768,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c1_ld_emlrtRSI = { 767,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_md_emlrtRSI = { 291,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_nd_emlrtRSI = { 292,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c1_od_emlrtRSI = { 55,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static const char_T c1_cv[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
  'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

static const boolean_T c1_bv[81] = { true, false, false, false, false, false,
  false, false, false, false, true, false, false, false, false, false, false,
  false, false, false, true, false, false, false, false, false, false, false,
  false, false, true, false, false, false, false, false, false, false, false,
  false, true, false, false, false, false, false, false, false, false, false,
  true, false, false, false, false, false, false, false, false, false, true,
  false, false, false, false, false, false, false, false, false, true, false,
  false, false, false, false, false, false, false, false, true };

static const boolean_T c1_bv1[81] = { false, false, false, false, false, false,
  false, false, true, false, false, false, false, false, false, false, true,
  false, false, false, false, false, false, false, true, false, false, false,
  false, false, false, false, true, false, false, false, false, false, false,
  false, true, false, false, false, false, false, false, false, true, false,
  false, false, false, false, false, false, true, false, false, false, false,
  false, false, false, true, false, false, false, false, false, false, false,
  true, false, false, false, false, false, false, false, false };

static const char_T c1_cv1[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static boolean_T c1_detectfire(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, uint8_T c1_c_red[19200], uint8_T
  c1_c_green[19200], uint8_T c1_b_blue[19200]);
static void c1_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[19200], boolean_T c1_b[28500]);
static void c1_imdilate(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_c_A[28500], boolean_T c1_B[28500]);
static void c1_b_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[28500], boolean_T c1_b[33456]);
static void c1_c_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[33456], boolean_T c1_b[38804]);
static void c1_bwpack(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      boolean_T c1_varargin_1[38804], uint32_T c1_BWP[1308]);
static void c1_bwunpack(SFc1_flightControlSystemInstanceStruct *chartInstance,
  uint32_T c1_varargin_1[1308], boolean_T c1_BW[38804]);
static void c1_imerode(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_c_A[28500], boolean_T c1_B[28500]);
static void c1_d_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[28500], boolean_T c1_b[33456]);
static void c1_e_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[33456], boolean_T c1_b[38804]);
static void c1_f_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  uint8_T c1_varargin_1[19200], uint8_T c1_b[19764]);
static void c1_g_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  uint8_T c1_b[19764]);
static void c1_check_forloop_overflow_error
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp);
static void c1_imreconstruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, uint8_T c1_marker[19764], uint8_T c1_mask[19764], uint8_T
  c1_im[19764]);
static void c1_regionprops(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_varargin_1[19200],
  c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *c1_outstats);
static void c1_bwconncomp(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_varargin_1[19200],
  c1_scIvRXQeSh8yxCxSmtD63bE *c1_CC);
static void c1_assertValidSizeArg(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_varargin_1);
static void c1_initializeStatsStruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_numObjs,
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed);
static void c1_ComputePixelIdxList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE c1_CC,
  real_T c1_numObjs, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed,
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_b_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_b_statsAlreadyComputed);
static void c1_ComputePixelList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h
  *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed,
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_b_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_b_statsAlreadyComputed);
static boolean_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_IsFireFound, const char_T *c1_identifier);
static boolean_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_chart_data_browse_helper
  (SFc1_flightControlSystemInstanceStruct *chartInstance, int32_T c1_ssIdNumber);
static void c1_b_ComputePixelIdxList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE c1_CC,
  real_T c1_numObjs, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 *c1_statsAlreadyComputed);
static void c1_b_ComputePixelList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h
  *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2 *c1_statsAlreadyComputed);
static void c1_emxEnsureCapacity_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_sKyE5zvueAoQJ4jaLWfzLx
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_sKyE5zvueAoQJ4jaLWfzLx
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx **c1_pEmxArray);
static void c1_emxFree_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray);
static void c1_emxEnsureCapacity_boolean_T
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_sKyE5zvueAoQJ
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_real_T1(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInitStruct_scIvRXQeSh8yxCxSm
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation);
static void c1_emxInit_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_boolean_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFreeStruct_scIvRXQeSh8yxCxSm
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_scIvRXQeSh8yxCxSmtD63bE *c1_pStruct);
static void c1_emxFree_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray);
static void c1_emxFree_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c1_pEmxArray);
static void c1_emxFreeStruct_s9uuw2Xu7QLvohu1q
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s9uuw2Xu7QLvohu1q5iD2hG *c1_pStruct);
static void c1_emxFree_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray);
static void c1_emxEnsureCapacity_int32_T(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxTrim_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex);
static void c1_emxInitStruct_s9uuw2Xu7QLvohu1q
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s9uuw2Xu7QLvohu1q5iD2hG *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation);
static void c1_emxExpand_s9uuw2Xu7QLvohu1q5iD2
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_s9uuw2Xu7QLvo
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopyStruct_s9uuw2Xu7QLvohu1q
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s9uuw2Xu7QLvohu1q5iD2hG *c1_dst, const c1_s9uuw2Xu7QLvohu1q5iD2hG *
   c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopyMatrix_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[2], const real_T c1_src[2]);
static void c1_emxCopyMatrix_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[4], const real_T c1_src[4]);
static void c1_emxCopy_boolean_T_0x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T_0x0 *c1_dst, const
  c1_emxArray_boolean_T_0x0 *c1_src);
static void c1_emxCopyMatrix_real_T2(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[16], const real_T c1_src[16]);
static void c1_emxCopy_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopy_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopy_real_T_0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T_0 *c1_dst, const c1_emxArray_real_T_0
  *c1_src);
static void c1_emxCopy_real_T_1x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T_1x0 *c1_dst, const c1_emxArray_real_T_1x0
  *c1_src);
static void c1_emxCopyStruct_scIvRXQeSh8yxCxSm
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE *c1_dst, const c1_scIvRXQeSh8yxCxSmtD63bE *
   c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopy_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_dst,
  c1_emxArray_int32_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInitMatrix_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_17 c1_pMatrix[2], const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInitStruct_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_17 *c1_pStruct, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxFreeMatrix_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_17 c1_pMatrix[2]);
static void c1_emxFreeStruct_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_17 *c1_pStruct);
static int32_T c1_div_nzp_s32(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, int32_T
  c1_EMLOvCount_src_loc, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc,
  int32_T c1_length_src_loc);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c1_st, "Image_Toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_flightControlSystem = 0U;
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_jit_animation_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", chartInstance->c1_IsFireFound, 11,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_IsFireFound = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "IsFireFound");
  chartInstance->c1_is_active_c1_flightControlSystem = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_flightControlSystem");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  emlrtStack c1_b_st;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  uint8_T c1_b_blue[19200];
  boolean_T c1_b_IsFireFound;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U, (real_T)
                      (*chartInstance->c1_blue)[c1_i]);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                      (*chartInstance->c1_b_green)[c1_i1]);
  }

  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      (*chartInstance->c1_b_red)[c1_i2]);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    chartInstance->c1_red[c1_i3] = (*chartInstance->c1_b_red)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
    chartInstance->c1_green[c1_i4] = (*chartInstance->c1_b_green)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
    c1_b_blue[c1_i5] = (*chartInstance->c1_blue)[c1_i5];
  }

  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_b_st.site = &c1_g_emlrtRSI;
  c1_b_IsFireFound = c1_detectfire(chartInstance, &c1_b_st,
    chartInstance->c1_red, chartInstance->c1_green, c1_b_blue);
  *chartInstance->c1_IsFireFound = c1_b_IsFireFound;
  c1_do_animation_call_c1_flightControlSystem(chartInstance);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U, (real_T)
                    *chartInstance->c1_IsFireFound);
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const int32_T c1_condTxtStartIdx[3] = { 53, 69, 88 };

  static const int32_T c1_condTxtEndIdx[3] = { 65, 84, 102 };

  static const int32_T c1_postfixPredicateTree[5] = { 0, 1, -2, 2, -2 };

  static const int32_T c1_b_condTxtStartIdx[2] = { 281, 298 };

  static const int32_T c1_b_condTxtEndIdx[2] = { 294, 313 };

  static const int32_T c1_b_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c1_c_condTxtStartIdx[2] = { 522, 536 };

  static const int32_T c1_c_condTxtEndIdx[2] = { 532, 548 };

  static const int32_T c1_c_postfixPredicateTree[3] = { 0, 1, -3 };

  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    8U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 125);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance,
                  "C:/Users/asslaberverena/MATLAB/Projects/examples/parrotMinidroneCompetition5/utilities/detectfire.m",
                  14U, 0U, 2U, 0U, 3U, 0U, 1U, 0U, 0U, 0U, 7U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 0U, "detectfire",
                     0, -1, 626);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 1U, "", 384, -1,
                     412);
  covrtEmlSaturationInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 0U, 254,
    -1, 275);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 0U, 49, 102, 130,
                    622);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 1U, 277, 313, 336,
                    618);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 2U, 518, 549, 576,
                    614);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 0U, 53, 102, 3U,
                      0U, c1_condTxtStartIdx, c1_condTxtEndIdx, 5U,
                      c1_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 1U, 281, 313, 2U,
                      3U, c1_b_condTxtStartIdx, c1_b_condTxtEndIdx, 3U,
                      c1_b_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 2U, 522, 548, 2U,
                      5U, c1_c_condTxtStartIdx, c1_c_condTxtEndIdx, 3U,
                      c1_c_postfixPredicateTree);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 0U, 69, 84,
    -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 1U, 522,
    532, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 14U, 0U, 2U, 536,
    548, -1, 4U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance,
                  "C:/Users/asslaberverena/MATLAB/Projects/examples/parrotMinidroneCompetition5/utilities/extract_red.m",
                  14U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 14U, 1U, 0U, "extract_red",
                     0, -1, 1198);
}

static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c1_detectfire(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, uint8_T c1_c_red[19200], uint8_T
  c1_c_green[19200], uint8_T c1_b_blue[19200])
{
  boolean_T c1_detected;
  emlrtStack c1_st;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_g_st;
  emlrtStack c1_h_st;
  int32_T c1_i;
  int32_T c1_i1;
  boolean_T c1_BW_C[19200];
  boolean_T c1_y;
  boolean_T c1_x_data[19200];
  int32_T c1_k;
  boolean_T c1_exitg1;
  real_T c1_b_k;
  int32_T c1_i2;
  int32_T c1_i3;
  boolean_T c1_sliderBW[19200];
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  c1_images_internal_coder_strel_StructuringElementHelper c1_se;
  static boolean_T c1_b_bv[841] = { false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false };

  c1_images_internal_coder_strel_StructuringElementHelper c1_b_se;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  uint8_T c1_mask[19200];
  uint8_T c1_maskPad[19764];
  uint8_T c1_markerPad[19764];
  int32_T c1_i19;
  int32_T c1_c_k;
  real_T c1_idx[320];
  int32_T c1_i20;
  real_T c1_d_k;
  real_T c1_d;
  int32_T c1_i21;
  uint32_T c1_q0;
  real_T c1_M;
  uint32_T c1_qY;
  real_T c1_d1;
  uint32_T c1_b_q0;
  boolean_T c1_covSaturation;
  int32_T c1_i22;
  uint8_T c1_I1[19764];
  uint32_T c1_b_qY;
  int32_T c1_tmp_size[1];
  int32_T c1_i23;
  int32_T c1_loop_ub;
  uint32_T c1_u;
  int32_T c1_i24;
  int32_T c1_i25;
  uint32_T c1_c_q0;
  uint32_T c1_u1;
  uint32_T c1_c_qY;
  int32_T c1_i26;
  int32_T c1_tmp_data[160];
  int32_T c1_nz;
  boolean_T c1_x[160];
  real_T c1_b_d;
  int32_T c1_e_k;
  real_T c1_b;
  uint32_T c1_u2;
  int32_T c1_b_tmp_size[2];
  real_T c1_idx1;
  int32_T c1_xoffset;
  int32_T c1_i27;
  int32_T c1_ix;
  int32_T c1_b_loop_ub;
  int32_T c1_b_b;
  int32_T c1_i28;
  int32_T c1_b_nz;
  int32_T c1_f_k;
  int32_T c1_iv[1];
  real_T c1_b_tmp_data[160];
  real_T c1_idx2;
  int32_T c1_b_xoffset;
  int32_T c1_iv1[1];
  int32_T c1_i29;
  int32_T c1_b_ix;
  int32_T c1_i30;
  int32_T c1_b_i;
  int32_T c1_c_b;
  int32_T c1_c_loop_ub;
  int32_T c1_i31;
  real_T c1_c_i;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_j;
  int32_T c1_i34;
  boolean_T c1_b_y;
  real_T c1_b_j;
  int32_T c1_g_k;
  int32_T c1_i35;
  real_T c1_d2;
  int32_T c1_i36;
  int32_T c1_i37;
  real_T c1_h_k;
  real_T c1_d3;
  c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *c1_s;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  c1_emxArray_real_T *c1_maxVals;
  const mxArray *c1_c_y = NULL;
  static char_T c1_b_cv[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd',
    'E', 'm', 'p', 't', 'y', 'A', 'r', 'r', 'a', 'y', 'T', 'y', 'p', 'e' };

  const mxArray *c1_d_y = NULL;
  int32_T c1_sz[2];
  int32_T c1_i41;
  int32_T c1_n;
  int32_T c1_d_b;
  int32_T c1_e_b;
  boolean_T c1_overflow;
  int32_T c1_i_k;
  int32_T c1_j_k;
  c1_sKyE5zvueAoQJ4jaLWfzLx c1_inputs[1];
  c1_sKyE5zvueAoQJ4jaLWfzLx c1_struct;
  boolean_T c1_f_b;
  real_T c1_varargin_1;
  real_T c1_b_x;
  real_T c1_c_x;
  const mxArray *c1_e_y = NULL;
  real_T c1_d_x;
  static char_T c1_b_cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  real_T c1_e_x;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  real_T c1_f_x;
  real_T c1_varargout_1;
  int32_T c1_b_n;
  const mxArray *c1_h_y = NULL;
  real_T c1_outputs[1];
  int32_T c1_last;
  int32_T c1_b_idx;
  real_T c1_ex;
  int32_T c1_c_idx;
  int32_T c1_g_b;
  int32_T c1_d_idx;
  int32_T c1_h_b;
  int32_T c1_iidx;
  real_T c1_indx;
  boolean_T c1_b_overflow;
  real_T c1_d_i;
  real_T c1_e_i;
  int32_T c1_i42;
  int32_T c1_k_k;
  int32_T c1_i43;
  real_T c1_width;
  real_T c1_boundbox[4];
  int32_T c1_i44;
  real_T c1_height;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_g_st.prev = &c1_f_st;
  c1_g_st.tls = c1_f_st.tls;
  c1_h_st.prev = &c1_g_st;
  c1_h_st.tls = c1_g_st.tls;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 14U, 0, 0);
  covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 0, false);
  covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 1,
                   covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
    14U, 0U, 0U, 160.0, 2.0, -1, 2U, 0));
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_BW_C[c1_i] = ((real_T)c1_c_red[c1_i] == 0.0);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_x_data[c1_i1] = c1_BW_C[c1_i1];
  }

  c1_y = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    if (!c1_x_data[(int32_T)c1_b_k - 1]) {
      c1_y = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 2, c1_y)) {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 14U, 0, 0, true);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 14U, 0, 0, true);
    c1_detected = false;
  } else {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 14U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 14U, 0, 0, false);
    c1_st.site = &c1_emlrtRSI;
    covrtEmlFcnEval(chartInstance->c1_covrtInstance, 14U, 1, 0);
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      c1_sliderBW[c1_i2] = ((real_T)c1_c_red[c1_i2] >= 215.0);
    }

    for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
      c1_BW_C[c1_i3] = ((real_T)c1_c_red[c1_i3] <= 255.0);
    }

    for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
      c1_sliderBW[c1_i4] = (c1_sliderBW[c1_i4] && c1_BW_C[c1_i4]);
    }

    for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
      c1_BW_C[c1_i5] = ((real_T)c1_b_blue[c1_i5] >= 0.0);
    }

    for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
      c1_sliderBW[c1_i6] = (c1_sliderBW[c1_i6] && c1_BW_C[c1_i6]);
    }

    for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
      c1_BW_C[c1_i7] = ((real_T)c1_b_blue[c1_i7] <= 255.0);
    }

    for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
      c1_sliderBW[c1_i8] = (c1_sliderBW[c1_i8] && c1_BW_C[c1_i8]);
    }

    for (c1_i9 = 0; c1_i9 < 19200; c1_i9++) {
      c1_BW_C[c1_i9] = ((real_T)c1_c_green[c1_i9] >= 0.0);
    }

    for (c1_i10 = 0; c1_i10 < 19200; c1_i10++) {
      c1_sliderBW[c1_i10] = (c1_sliderBW[c1_i10] && c1_BW_C[c1_i10]);
    }

    for (c1_i11 = 0; c1_i11 < 19200; c1_i11++) {
      c1_BW_C[c1_i11] = ((real_T)c1_c_green[c1_i11] <= 255.0);
    }

    for (c1_i12 = 0; c1_i12 < 19200; c1_i12++) {
      c1_sliderBW[c1_i12] = (c1_sliderBW[c1_i12] && c1_BW_C[c1_i12]);
    }

    for (c1_i13 = 0; c1_i13 < 841; c1_i13++) {
      c1_se.Neighborhood[c1_i13] = c1_b_bv[c1_i13];
    }

    c1_se.Dimensionality = 2.0;
    c1_st.site = &c1_b_emlrtRSI;
    c1_padarray(chartInstance, c1_sliderBW, chartInstance->c1_Ap);
    c1_b_se = c1_se;
    c1_b_st.site = &c1_h_emlrtRSI;
    c1_imdilate(chartInstance, chartInstance->c1_Ap, chartInstance->c1_b_bv1);
    c1_b_st.site = &c1_h_emlrtRSI;
    c1_imerode(chartInstance, chartInstance->c1_b_bv1, chartInstance->c1_Ap);
    c1_i14 = 0;
    c1_i15 = 0;
    for (c1_i16 = 0; c1_i16 < 160; c1_i16++) {
      for (c1_i17 = 0; c1_i17 < 120; c1_i17++) {
        c1_BW_C[c1_i17 + c1_i14] = chartInstance->c1_Ap[(c1_i17 + c1_i15) + 2265];
      }

      c1_i14 += 120;
      c1_i15 += 150;
    }

    c1_st.site = &c1_c_emlrtRSI;
    for (c1_i18 = 0; c1_i18 < 19200; c1_i18++) {
      c1_mask[c1_i18] = (uint8_T)c1_BW_C[c1_i18];
    }

    c1_f_padarray(chartInstance, c1_mask, c1_maskPad);
    c1_g_padarray(chartInstance, c1_markerPad);
    for (c1_i19 = 0; c1_i19 < 320; c1_i19++) {
      c1_idx[c1_i19] = 0.0;
    }

    for (c1_c_k = 0; c1_c_k < 2; c1_c_k++) {
      c1_d_k = (real_T)c1_c_k + 1.0;
      c1_d = (real_T)(122 + 40 * ((int32_T)c1_d_k - 1));
      c1_M = c1_d - 2.0;
      c1_d1 = (real_T)(122 + 40 * ((int32_T)c1_d_k - 1));
      c1_i22 = (int32_T)c1_M - 1;
      c1_tmp_size[0] = c1_i22 + 1;
      c1_loop_ub = c1_i22;
      for (c1_i24 = 0; c1_i24 <= c1_loop_ub; c1_i24++) {
        c1_tmp_data[c1_i24] = c1_i24;
      }

      c1_i26 = (int32_T)c1_d_k;
      c1_b_d = c1_d1 - 1.0;
      c1_b = c1_b_d;
      c1_b_tmp_size[0] = 1;
      c1_b_tmp_size[1] = (int32_T)muDoubleScalarFloor(c1_b - 2.0) + 1;
      c1_b_loop_ub = (int32_T)muDoubleScalarFloor(c1_b - 2.0);
      for (c1_i28 = 0; c1_i28 <= c1_b_loop_ub; c1_i28++) {
        c1_b_tmp_data[c1_i28] = 2.0 + (real_T)c1_i28;
      }

      c1_iv[0] = c1_tmp_size[0];
      emlrtSubAssignSizeCheckR2012b(c1_iv, 1, c1_b_tmp_size, 2, &c1_emlrtECI,
        &c1_st);
      c1_iv1[0] = c1_tmp_size[0];
      c1_i30 = c1_i26 - 1;
      c1_c_loop_ub = c1_iv1[0] - 1;
      for (c1_i31 = 0; c1_i31 <= c1_c_loop_ub; c1_i31++) {
        c1_idx[c1_tmp_data[c1_i31] + 160 * c1_i30] = c1_b_tmp_data[c1_i31];
      }
    }

    for (c1_i20 = 0; c1_i20 < 19764; c1_i20++) {
      c1_q0 = 255U;
      c1_qY = c1_q0 - (uint32_T)c1_maskPad[c1_i20];
      c1_covSaturation = false;
      if (c1_qY > c1_q0) {
        c1_covSaturation = true;
        c1_qY = 0U;
        sf_data_saturate_error(chartInstance->S, 0U, 0, 0);
      }

      c1_u = c1_qY;
      if (c1_u > 255U) {
        c1_covSaturation = true;
        c1_u = 255U;
        sf_data_saturate_error(chartInstance->S, 0U, 0, 0);
      }

      c1_maskPad[c1_i20] = (uint8_T)c1_u;
    }

    for (c1_i21 = 0; c1_i21 < 19764; c1_i21++) {
      c1_b_q0 = 255U;
      c1_b_qY = c1_b_q0 - (uint32_T)c1_markerPad[c1_i21];
      if (c1_b_qY > c1_b_q0) {
        c1_covSaturation = true;
        c1_b_qY = 0U;
        sf_data_saturate_error(chartInstance->S, 0U, 0, 0);
      }

      c1_u1 = c1_b_qY;
      if (c1_u1 > 255U) {
        c1_covSaturation = true;
        c1_u1 = 255U;
        sf_data_saturate_error(chartInstance->S, 0U, 0, 0);
      }

      c1_markerPad[c1_i21] = (uint8_T)c1_u1;
    }

    c1_b_st.site = &c1_s_emlrtRSI;
    c1_imreconstruct(chartInstance, c1_markerPad, c1_maskPad, c1_I1);
    for (c1_i23 = 0; c1_i23 < 19764; c1_i23++) {
      c1_c_q0 = 255U;
      c1_c_qY = c1_c_q0 - (uint32_T)c1_I1[c1_i23];
      if (c1_c_qY > c1_c_q0) {
        c1_covSaturation = true;
        c1_c_qY = 0U;
        sf_data_saturate_error(chartInstance->S, 0U, 0, 0);
      }

      c1_u2 = c1_c_qY;
      if (c1_u2 > 255U) {
        c1_covSaturation = true;
        c1_u2 = 255U;
        sf_data_saturate_error(chartInstance->S, 0U, 0, 0);
      }

      covrtSaturationUpdateFcn(chartInstance->c1_covrtInstance, 14, 0, 0, 0,
        c1_covSaturation);
      c1_I1[c1_i23] = (uint8_T)c1_u2;
    }

    for (c1_i25 = 0; c1_i25 < 160; c1_i25++) {
      c1_x[c1_i25] = (c1_idx[c1_i25] != 0.0);
    }

    c1_nz = (int32_T)c1_x[0];
    for (c1_e_k = 0; c1_e_k < 159; c1_e_k++) {
      c1_xoffset = c1_e_k;
      c1_ix = c1_xoffset;
      c1_b_b = (int32_T)c1_x[c1_ix + 1];
      c1_nz += (c1_b_b != 0);
    }

    c1_idx1 = (real_T)c1_nz;
    for (c1_i27 = 0; c1_i27 < 160; c1_i27++) {
      c1_x[c1_i27] = (c1_idx[c1_i27 + 160] != 0.0);
    }

    c1_b_nz = (int32_T)c1_x[0];
    for (c1_f_k = 0; c1_f_k < 159; c1_f_k++) {
      c1_b_xoffset = c1_f_k;
      c1_b_ix = c1_b_xoffset;
      c1_c_b = (int32_T)c1_x[c1_b_ix + 1];
      c1_b_nz += (c1_c_b != 0);
    }

    c1_idx2 = (real_T)c1_b_nz;
    c1_i29 = (int32_T)c1_idx1 - 1;
    for (c1_b_i = 0; c1_b_i <= c1_i29; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      c1_i33 = (int32_T)c1_idx2 - 1;
      for (c1_j = 0; c1_j <= c1_i33; c1_j++) {
        c1_b_j = (real_T)c1_j + 1.0;
        c1_i35 = (int32_T)c1_c_i;
        c1_d2 = c1_idx[emlrtDynamicBoundsCheckR2012b(c1_i35, 1, 160,
          &c1_b_emlrtBCI, &c1_st) - 1];
        c1_i36 = (int32_T)emlrtIntegerCheckR2012b(c1_d2, &c1_emlrtDCI, &c1_st);
        c1_i37 = (int32_T)c1_b_j;
        c1_d3 = c1_idx[emlrtDynamicBoundsCheckR2012b(c1_i37, 1, 160,
          &c1_b_emlrtBCI, &c1_st) + 159];
        c1_i38 = (int32_T)emlrtIntegerCheckR2012b(c1_d3, &c1_emlrtDCI, &c1_st);
        c1_i39 = (int32_T)c1_c_i;
        c1_i40 = (int32_T)c1_b_j;
        c1_sliderBW[(emlrtDynamicBoundsCheckR2012b(c1_i39, 1, 120,
          &c1_d_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_i40,
          1, 160, &c1_e_emlrtBCI, &c1_st) - 1)) - 1] = (c1_I1
          [(emlrtDynamicBoundsCheckR2012b(c1_i36, 1, 122, &c1_emlrtBCI, &c1_st)
            + 122 * (emlrtDynamicBoundsCheckR2012b(c1_i38, 1, 162,
          &c1_c_emlrtBCI, &c1_st) - 1)) - 1] != 0);
      }
    }

    covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 3, false);
    for (c1_i32 = 0; c1_i32 < 19200; c1_i32++) {
      c1_BW_C[c1_i32] = !c1_sliderBW[c1_i32];
    }

    for (c1_i34 = 0; c1_i34 < 19200; c1_i34++) {
      c1_x_data[c1_i34] = c1_BW_C[c1_i34];
    }

    c1_b_y = true;
    c1_g_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_g_k < 19200)) {
      c1_h_k = (real_T)c1_g_k + 1.0;
      if (!c1_x_data[(int32_T)c1_h_k - 1]) {
        c1_b_y = false;
        c1_exitg1 = true;
      } else {
        c1_g_k++;
      }
    }

    if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 4, c1_b_y)) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 14U, 0, 1, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 14U, 0, 1, true);
      c1_detected = false;
    } else {
      c1_emxInit_sKyE5zvueAoQJ4jaLWfzLx(chartInstance, c1_sp, &c1_s, 1,
        &c1_e_emlrtRTEI);
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 14U, 0, 1, false);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 14U, 0, 1, false);
      c1_st.site = &c1_d_emlrtRSI;
      c1_regionprops(chartInstance, &c1_st, c1_sliderBW, c1_s);
      c1_st.site = &c1_e_emlrtRSI;
      c1_b_st.site = &c1_yc_emlrtRSI;
      c1_c_st.site = &c1_ad_emlrtRSI;
      if (c1_s->size[0] == 0) {
        c1_d_st.site = &c1_dd_emlrtRSI;
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_d_st, "error", 0U, 2U, 14, c1_c_y, 14, sf_mex_call
                    (&c1_d_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_d_st,
          "message", 1U, 1U, 14, c1_d_y)));
      }

      c1_emxInit_real_T(chartInstance, &c1_c_st, &c1_maxVals, 1, &c1_f_emlrtRTEI);
      c1_d_st.site = &c1_ed_emlrtRSI;
      covrtEmlFcnEval(chartInstance->c1_covrtInstance, 14U, 0, 1);
      c1_sz[0] = c1_s->size[0];
      c1_i41 = c1_maxVals->size[0];
      c1_maxVals->size[0] = c1_sz[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_maxVals, c1_i41,
        &c1_d_emlrtRTEI);
      c1_n = c1_s->size[0];
      c1_c_st.site = &c1_bd_emlrtRSI;
      c1_d_b = c1_n;
      c1_e_b = c1_d_b;
      if (1 > c1_e_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_e_b > 2147483646);
      }

      if (c1_overflow) {
        c1_d_st.site = &c1_t_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
      }

      for (c1_i_k = 1; c1_i_k - 1 < c1_n; c1_i_k++) {
        c1_j_k = c1_i_k - 1;
        c1_inputs[0] = c1_s->data[c1_j_k];
        c1_c_st.site = &c1_cd_emlrtRSI;
        c1_struct = c1_inputs[0];
        covrtEmlFcnEval(chartInstance->c1_covrtInstance, 14U, 0, 1);
        c1_varargin_1 = c1_struct.Area;
        c1_b_x = c1_varargin_1;
        c1_c_x = c1_b_x;
        c1_d_x = c1_c_x;
        c1_e_x = c1_d_x;
        c1_f_x = c1_e_x;
        c1_varargout_1 = c1_f_x;
        c1_outputs[0] = c1_varargout_1;
        c1_maxVals->data[c1_j_k] = c1_outputs[0];
      }

      c1_st.site = &c1_f_emlrtRSI;
      c1_b_st.site = &c1_fd_emlrtRSI;
      c1_c_st.site = &c1_gd_emlrtRSI;
      c1_d_st.site = &c1_hd_emlrtRSI;
      if ((c1_maxVals->size[0] == 1) || ((real_T)c1_maxVals->size[0] != 1.0)) {
        c1_f_b = true;
      } else {
        c1_f_b = false;
      }

      if (!c1_f_b) {
        c1_e_y = NULL;
        sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1,
          36), false);
        c1_g_y = NULL;
        sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1,
          36), false);
        sf_mex_call(&c1_d_st, "error", 0U, 2U, 14, c1_e_y, 14, sf_mex_call
                    (&c1_d_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_d_st,
          "message", 1U, 1U, 14, c1_g_y)));
      }

      if (!((real_T)c1_maxVals->size[0] >= 1.0)) {
        c1_f_y = NULL;
        sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c1_h_y = NULL;
        sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_d_st, "error", 0U, 2U, 14, c1_f_y, 14, sf_mex_call
                    (&c1_d_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_d_st,
          "message", 1U, 1U, 14, c1_h_y)));
      }

      c1_e_st.site = &c1_id_emlrtRSI;
      c1_b_n = c1_maxVals->size[0];
      if (c1_b_n <= 2) {
        if (c1_b_n == 1) {
          c1_b_idx = 1;
        } else if (c1_maxVals->data[0] < c1_maxVals->data[1]) {
          c1_b_idx = 2;
        } else {
          c1_b_idx = 1;
        }
      } else {
        c1_f_st.site = &c1_jd_emlrtRSI;
        c1_last = c1_b_n;
        c1_ex = c1_maxVals->data[0];
        c1_c_idx = 1;
        c1_g_st.site = &c1_kd_emlrtRSI;
        c1_g_b = c1_last;
        c1_h_b = c1_g_b;
        if (2 > c1_h_b) {
          c1_b_overflow = false;
        } else {
          c1_b_overflow = (c1_h_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_h_st.site = &c1_t_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_h_st);
        }

        for (c1_k_k = 1; c1_k_k < c1_last; c1_k_k++) {
          if (c1_ex < c1_maxVals->data[c1_k_k]) {
            c1_ex = c1_maxVals->data[c1_k_k];
            c1_c_idx = c1_k_k + 1;
          }
        }

        c1_b_idx = c1_c_idx;
      }

      c1_emxFree_real_T(chartInstance, &c1_maxVals);
      c1_d_idx = c1_b_idx;
      c1_iidx = c1_d_idx;
      c1_indx = (real_T)c1_iidx;
      c1_d_i = c1_indx;
      c1_e_i = c1_d_i;
      for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
        c1_i43 = c1_s->size[0];
        c1_i44 = (int32_T)emlrtIntegerCheckR2012b(c1_e_i, &c1_b_emlrtDCI, c1_sp);
        c1_boundbox[c1_i42] = c1_s->data[emlrtDynamicBoundsCheckR2012b(c1_i44, 1,
          c1_i43, &c1_f_emlrtBCI, c1_sp) - 1].BoundingBox[c1_i42];
      }

      c1_emxFree_sKyE5zvueAoQJ4jaLWfzLx(chartInstance, &c1_s);
      c1_width = c1_boundbox[2];
      c1_height = c1_boundbox[3];
      if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 5,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 14U, 0U, 1U,
                            c1_width, 55.0, -1, 4U, c1_width > 55.0)) &&
          covrtEmlCondEval(chartInstance->c1_covrtInstance, 14U, 0, 6,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 14U, 0U, 2U,
                            c1_height, 145.0, -1, 4U, c1_height > 145.0))) {
        covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 14U, 0, 2, true);
        covrtEmlIfEval(chartInstance->c1_covrtInstance, 14U, 0, 2, true);
        c1_detected = true;
      } else {
        covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 14U, 0, 2, false);
        covrtEmlIfEval(chartInstance->c1_covrtInstance, 14U, 0, 2, false);
        c1_detected = false;
      }
    }
  }

  return c1_detected;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  const char * c1_data[5] = {
    "789ced55dd4ec230142e068c4a345cf912264e2324ea1de06fc212a22831c6c81c0728aeed6c0ba28fa017be9297c617f00d888fe1e60694c565442209ea499a"
    "f6ec3bedd7f3b53b45b1433d86105a429ebd27bd7ed169334e4bf9df67d0b005f158202e16884fa0787f9e8a3ff9bdc9a8848ef41c6a10e8cfac3282a94165e9",
    "ce06c44130ab0dd54fa4862d28610205a63807d871c89e02f51d1772c7f90698d7c72d8278430c7668a94e5f8f8a922f52f28d7fa1878a072da84730cee573b5"
    "b3bfc9d75b7f2182af87574182296b98c3307f654cfe4428bf87b430959b0adfcb987cb550be61fc7cf722bfad9d08e0423384b08c2be06de0400d4dcf960ad9",
    "9c56e4ace9482234e818c4b64068b6c139933aa6b8ca19853c2336482c31a319ad25b1e50c9da88192ab245ac7d911f30af63d9b4773fee8b9bbf2f8969d1c9f"
    "677f85af13b2dea8f77239842f15c0cbb97ad1d6b76e32a7767ebd5d3f33ef737a7977b08f62044fd43e50883fa9f57febff3d6e9d4e46e4d5c39d37911ba6bc",
    "e4fe9b37ad75ba1eca378cffdc392a4a3a0739c1bad27d7df8afd3d35ea7c5e14dfa3663dd17d2778db59debe64e61e388ec4f7f9dfe001900d25b",
    "" };

  c1_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c1_data[0], 3072U, &c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[19200], boolean_T c1_b[28500])
{
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_c_j;
  int32_T c1_i;
  int32_T c1_d_j;
  int32_T c1_b_i;
  real_T c1_c_i;
  int32_T c1_e_j;
  int32_T c1_d_i;
  int32_T c1_f_j;
  int32_T c1_e_i;
  real_T c1_a;
  int32_T c1_f_i;
  real_T c1_b_a;
  int32_T c1_c;
  int32_T c1_b_c;
  real_T c1_c_a;
  int32_T c1_c_c;
  real_T c1_d_a;
  int32_T c1_d_c;
  (void)chartInstance;
  for (c1_j = 0; c1_j < 15; c1_j++) {
    c1_c_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 150; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      c1_b[((int32_T)c1_c_i + 150 * ((int32_T)c1_c_j - 1)) - 1] = false;
    }
  }

  for (c1_b_j = 0; c1_b_j < 15; c1_b_j++) {
    for (c1_b_i = 0; c1_b_i < 150; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      c1_b[((int32_T)c1_c_i + 150 * (c1_b_j + 175)) - 1] = false;
    }
  }

  for (c1_d_j = 0; c1_d_j < 160; c1_d_j++) {
    c1_c_j = (real_T)c1_d_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 15; c1_d_i++) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      c1_a = c1_c_j;
      c1_c = (int32_T)c1_a;
      c1_b[((int32_T)c1_c_i + 150 * (c1_c + 14)) - 1] = false;
    }
  }

  for (c1_e_j = 0; c1_e_j < 160; c1_e_j++) {
    c1_c_j = (real_T)c1_e_j + 1.0;
    for (c1_e_i = 0; c1_e_i < 15; c1_e_i++) {
      c1_b_a = c1_c_j;
      c1_b_c = (int32_T)c1_b_a;
      c1_b[(c1_e_i + 150 * (c1_b_c + 14)) + 135] = false;
    }
  }

  for (c1_f_j = 0; c1_f_j < 160; c1_f_j++) {
    c1_c_j = (real_T)c1_f_j + 1.0;
    for (c1_f_i = 0; c1_f_i < 120; c1_f_i++) {
      c1_c_i = (real_T)c1_f_i + 1.0;
      c1_c_a = c1_c_i;
      c1_c_c = (int32_T)c1_c_a;
      c1_d_a = c1_c_j;
      c1_d_c = (int32_T)c1_d_a;
      c1_b[(c1_c_c + 150 * (c1_d_c + 14)) + 14] = c1_varargin_1[((int32_T)c1_c_i
        + 120 * ((int32_T)c1_c_j - 1)) - 1];
    }
  }
}

static void c1_imdilate(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_c_A[28500], boolean_T c1_B[28500])
{
  int32_T c1_i;
  uint32_T c1_Apadpack[1308];
  int32_T c1_i1;
  int32_T c1_i2;
  boolean_T c1_nhood[11];
  int32_T c1_i3;
  real_T c1_asizeT[2];
  real_T c1_nsizeT[2];
  uint32_T c1_b_B[1308];
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  boolean_T c1_b_nhood[3];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  for (c1_i = 0; c1_i < 28500; c1_i++) {
    chartInstance->c1_b_A[c1_i] = c1_c_A[c1_i];
  }

  c1_b_padarray(chartInstance, chartInstance->c1_b_A,
                chartInstance->c1_b_Apadpre);
  c1_c_padarray(chartInstance, chartInstance->c1_b_Apadpre,
                chartInstance->c1_b_Apad);
  c1_bwpack(chartInstance, chartInstance->c1_b_Apad, c1_Apadpack);
  for (c1_i1 = 0; c1_i1 < 11; c1_i1++) {
    c1_nhood[c1_i1] = true;
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_asizeT[c1_i2] = 6.0 + 212.0 * (real_T)c1_i2;
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_nsizeT[c1_i3] = 11.0 + -10.0 * (real_T)c1_i3;
  }

  dilate_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_nhood, c1_nsizeT, 2.0,
                       c1_b_B, true);
  for (c1_i4 = 0; c1_i4 < 1308; c1_i4++) {
    c1_Apadpack[c1_i4] = c1_b_B[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_asizeT[c1_i5] = 6.0 + 212.0 * (real_T)c1_i5;
  }

  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_nsizeT[c1_i6] = 9.0;
  }

  dilate_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_bv, c1_nsizeT, 2.0,
                       c1_b_B, true);
  for (c1_i7 = 0; c1_i7 < 1308; c1_i7++) {
    c1_Apadpack[c1_i7] = c1_b_B[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 11; c1_i8++) {
    c1_nhood[c1_i8] = true;
  }

  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    c1_asizeT[c1_i9] = 6.0 + 212.0 * (real_T)c1_i9;
  }

  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    c1_nsizeT[c1_i10] = 1.0 + 10.0 * (real_T)c1_i10;
  }

  dilate_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_nhood, c1_nsizeT, 2.0,
                       c1_b_B, true);
  for (c1_i11 = 0; c1_i11 < 1308; c1_i11++) {
    c1_Apadpack[c1_i11] = c1_b_B[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
    c1_asizeT[c1_i12] = 6.0 + 212.0 * (real_T)c1_i12;
  }

  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    c1_nsizeT[c1_i13] = 9.0;
  }

  dilate_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_bv1, c1_nsizeT, 2.0,
                       c1_b_B, true);
  for (c1_i14 = 0; c1_i14 < 1308; c1_i14++) {
    c1_Apadpack[c1_i14] = c1_b_B[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_b_nhood[c1_i15] = true;
  }

  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_asizeT[c1_i16] = 6.0 + 212.0 * (real_T)c1_i16;
  }

  for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
    c1_nsizeT[c1_i17] = 1.0 + 2.0 * (real_T)c1_i17;
  }

  dilate_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_b_nhood, c1_nsizeT, 2.0,
                       c1_b_B, true);
  for (c1_i18 = 0; c1_i18 < 1308; c1_i18++) {
    c1_Apadpack[c1_i18] = c1_b_B[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_b_nhood[c1_i19] = true;
  }

  for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
    c1_asizeT[c1_i20] = 6.0 + 212.0 * (real_T)c1_i20;
  }

  for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
    c1_nsizeT[c1_i21] = 3.0 + -2.0 * (real_T)c1_i21;
  }

  dilate_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_b_nhood, c1_nsizeT, 2.0,
                       c1_b_B, true);
  c1_bwunpack(chartInstance, c1_b_B, chartInstance->c1_b_Apad);
  c1_i22 = 0;
  c1_i23 = 0;
  for (c1_i24 = 0; c1_i24 < 190; c1_i24++) {
    for (c1_i25 = 0; c1_i25 < 150; c1_i25++) {
      c1_B[c1_i25 + c1_i22] = chartInstance->c1_b_Apad[(c1_i25 + c1_i23) + 2506];
    }

    c1_i22 += 150;
    c1_i23 += 178;
  }
}

static void c1_b_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[28500], boolean_T c1_b[33456])
{
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_c_j;
  int32_T c1_i;
  int32_T c1_d_j;
  int32_T c1_b_i;
  real_T c1_c_i;
  int32_T c1_d_i;
  real_T c1_a;
  int32_T c1_c;
  real_T c1_b_a;
  int32_T c1_b_c;
  (void)chartInstance;
  for (c1_j = 0; c1_j < 14; c1_j++) {
    c1_c_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 164; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      c1_b[((int32_T)c1_c_i + 164 * ((int32_T)c1_c_j - 1)) - 1] = false;
    }
  }

  for (c1_b_j = 0; c1_b_j < 190; c1_b_j++) {
    for (c1_b_i = 0; c1_b_i < 14; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      c1_b[((int32_T)c1_c_i + 164 * (c1_b_j + 14)) - 1] = false;
    }
  }

  for (c1_d_j = 0; c1_d_j < 190; c1_d_j++) {
    c1_c_j = (real_T)c1_d_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 150; c1_d_i++) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      c1_a = c1_c_i;
      c1_c = (int32_T)c1_a;
      c1_b_a = c1_c_j;
      c1_b_c = (int32_T)c1_b_a;
      c1_b[(c1_c + 164 * (c1_b_c + 13)) + 13] = c1_varargin_1[((int32_T)c1_c_i +
        150 * ((int32_T)c1_c_j - 1)) - 1];
    }
  }
}

static void c1_c_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[33456], boolean_T c1_b[38804])
{
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_i;
  int32_T c1_c_j;
  real_T c1_d_j;
  real_T c1_b_i;
  int32_T c1_c_i;
  int32_T c1_d_i;
  (void)chartInstance;
  for (c1_j = 0; c1_j < 14; c1_j++) {
    for (c1_i = 0; c1_i < 178; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_b[((int32_T)c1_b_i + 178 * (c1_j + 204)) - 1] = false;
    }
  }

  for (c1_b_j = 0; c1_b_j < 204; c1_b_j++) {
    c1_d_j = (real_T)c1_b_j + 1.0;
    for (c1_c_i = 0; c1_c_i < 14; c1_c_i++) {
      c1_b[(c1_c_i + 178 * ((int32_T)c1_d_j - 1)) + 164] = false;
    }
  }

  for (c1_c_j = 0; c1_c_j < 204; c1_c_j++) {
    c1_d_j = (real_T)c1_c_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 164; c1_d_i++) {
      c1_b_i = (real_T)c1_d_i + 1.0;
      c1_b[((int32_T)c1_b_i + 178 * ((int32_T)c1_d_j - 1)) - 1] = c1_varargin_1
        [((int32_T)c1_b_i + 164 * ((int32_T)c1_d_j - 1)) - 1];
    }
  }
}

static void c1_bwpack(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      boolean_T c1_varargin_1[38804], uint32_T c1_BWP[1308])
{
  int32_T c1_i;
  int32_T c1_i1;
  real_T c1_dv[2];
  real_T c1_dv1[2];
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dv[c1_i] = 178.0 + 40.0 * (real_T)c1_i;
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_dv1[c1_i1] = 6.0 + 212.0 * (real_T)c1_i1;
  }

  bwPackingtbb(c1_varargin_1, c1_dv, c1_BWP, c1_dv1, true);
}

static void c1_bwunpack(SFc1_flightControlSystemInstanceStruct *chartInstance,
  uint32_T c1_varargin_1[1308], boolean_T c1_BW[38804])
{
  int32_T c1_i;
  int32_T c1_i1;
  real_T c1_dv[2];
  real_T c1_dv1[2];
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dv[c1_i] = 6.0 + 212.0 * (real_T)c1_i;
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_dv1[c1_i1] = 178.0 + 40.0 * (real_T)c1_i1;
  }

  bwUnpackingtbb(c1_varargin_1, c1_dv, c1_BW, c1_dv1, true);
}

static void c1_imerode(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_c_A[28500], boolean_T c1_B[28500])
{
  int32_T c1_i;
  uint32_T c1_Apadpack[1308];
  int32_T c1_i1;
  int32_T c1_i2;
  boolean_T c1_nhood[11];
  int32_T c1_i3;
  real_T c1_asizeT[2];
  real_T c1_nsizeT[2];
  uint32_T c1_b_B[1308];
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  boolean_T c1_b_nhood[3];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  for (c1_i = 0; c1_i < 28500; c1_i++) {
    chartInstance->c1_A[c1_i] = c1_c_A[c1_i];
  }

  c1_d_padarray(chartInstance, chartInstance->c1_A, chartInstance->c1_Apadpre);
  c1_e_padarray(chartInstance, chartInstance->c1_Apadpre, chartInstance->c1_Apad);
  c1_bwpack(chartInstance, chartInstance->c1_Apad, c1_Apadpack);
  for (c1_i1 = 0; c1_i1 < 11; c1_i1++) {
    c1_nhood[c1_i1] = true;
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_asizeT[c1_i2] = 6.0 + 212.0 * (real_T)c1_i2;
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_nsizeT[c1_i3] = 11.0 + -10.0 * (real_T)c1_i3;
  }

  erode_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_nhood, c1_nsizeT, 2.0,
                      178.0, c1_b_B, true);
  for (c1_i4 = 0; c1_i4 < 1308; c1_i4++) {
    c1_Apadpack[c1_i4] = c1_b_B[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_asizeT[c1_i5] = 6.0 + 212.0 * (real_T)c1_i5;
  }

  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_nsizeT[c1_i6] = 9.0;
  }

  erode_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_bv, c1_nsizeT, 2.0, 178.0,
                      c1_b_B, true);
  for (c1_i7 = 0; c1_i7 < 1308; c1_i7++) {
    c1_Apadpack[c1_i7] = c1_b_B[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 11; c1_i8++) {
    c1_nhood[c1_i8] = true;
  }

  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    c1_asizeT[c1_i9] = 6.0 + 212.0 * (real_T)c1_i9;
  }

  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    c1_nsizeT[c1_i10] = 1.0 + 10.0 * (real_T)c1_i10;
  }

  erode_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_nhood, c1_nsizeT, 2.0,
                      178.0, c1_b_B, true);
  for (c1_i11 = 0; c1_i11 < 1308; c1_i11++) {
    c1_Apadpack[c1_i11] = c1_b_B[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
    c1_asizeT[c1_i12] = 6.0 + 212.0 * (real_T)c1_i12;
  }

  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    c1_nsizeT[c1_i13] = 9.0;
  }

  erode_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_bv1, c1_nsizeT, 2.0, 178.0,
                      c1_b_B, true);
  for (c1_i14 = 0; c1_i14 < 1308; c1_i14++) {
    c1_Apadpack[c1_i14] = c1_b_B[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_b_nhood[c1_i15] = true;
  }

  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_asizeT[c1_i16] = 6.0 + 212.0 * (real_T)c1_i16;
  }

  for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
    c1_nsizeT[c1_i17] = 1.0 + 2.0 * (real_T)c1_i17;
  }

  erode_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_b_nhood, c1_nsizeT, 2.0,
                      178.0, c1_b_B, true);
  for (c1_i18 = 0; c1_i18 < 1308; c1_i18++) {
    c1_Apadpack[c1_i18] = c1_b_B[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_b_nhood[c1_i19] = true;
  }

  for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
    c1_asizeT[c1_i20] = 6.0 + 212.0 * (real_T)c1_i20;
  }

  for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
    c1_nsizeT[c1_i21] = 3.0 + -2.0 * (real_T)c1_i21;
  }

  erode_packed_uint32(c1_Apadpack, c1_asizeT, 2.0, c1_b_nhood, c1_nsizeT, 2.0,
                      178.0, c1_b_B, true);
  c1_bwunpack(chartInstance, c1_b_B, chartInstance->c1_Apad);
  c1_i22 = 0;
  c1_i23 = 0;
  for (c1_i24 = 0; c1_i24 < 190; c1_i24++) {
    for (c1_i25 = 0; c1_i25 < 150; c1_i25++) {
      c1_B[c1_i25 + c1_i22] = chartInstance->c1_Apad[(c1_i25 + c1_i23) + 2506];
    }

    c1_i22 += 150;
    c1_i23 += 178;
  }
}

static void c1_d_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[28500], boolean_T c1_b[33456])
{
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_c_j;
  int32_T c1_i;
  int32_T c1_d_j;
  int32_T c1_b_i;
  real_T c1_c_i;
  int32_T c1_d_i;
  real_T c1_a;
  int32_T c1_c;
  real_T c1_b_a;
  int32_T c1_b_c;
  (void)chartInstance;
  for (c1_j = 0; c1_j < 14; c1_j++) {
    c1_c_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 164; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      c1_b[((int32_T)c1_c_i + 164 * ((int32_T)c1_c_j - 1)) - 1] = true;
    }
  }

  for (c1_b_j = 0; c1_b_j < 190; c1_b_j++) {
    for (c1_b_i = 0; c1_b_i < 14; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      c1_b[((int32_T)c1_c_i + 164 * (c1_b_j + 14)) - 1] = true;
    }
  }

  for (c1_d_j = 0; c1_d_j < 190; c1_d_j++) {
    c1_c_j = (real_T)c1_d_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 150; c1_d_i++) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      c1_a = c1_c_i;
      c1_c = (int32_T)c1_a;
      c1_b_a = c1_c_j;
      c1_b_c = (int32_T)c1_b_a;
      c1_b[(c1_c + 164 * (c1_b_c + 13)) + 13] = c1_varargin_1[((int32_T)c1_c_i +
        150 * ((int32_T)c1_c_j - 1)) - 1];
    }
  }
}

static void c1_e_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_varargin_1[33456], boolean_T c1_b[38804])
{
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_i;
  int32_T c1_c_j;
  real_T c1_d_j;
  real_T c1_b_i;
  int32_T c1_c_i;
  int32_T c1_d_i;
  (void)chartInstance;
  for (c1_j = 0; c1_j < 14; c1_j++) {
    for (c1_i = 0; c1_i < 178; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_b[((int32_T)c1_b_i + 178 * (c1_j + 204)) - 1] = true;
    }
  }

  for (c1_b_j = 0; c1_b_j < 204; c1_b_j++) {
    c1_d_j = (real_T)c1_b_j + 1.0;
    for (c1_c_i = 0; c1_c_i < 14; c1_c_i++) {
      c1_b[(c1_c_i + 178 * ((int32_T)c1_d_j - 1)) + 164] = true;
    }
  }

  for (c1_c_j = 0; c1_c_j < 204; c1_c_j++) {
    c1_d_j = (real_T)c1_c_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 164; c1_d_i++) {
      c1_b_i = (real_T)c1_d_i + 1.0;
      c1_b[((int32_T)c1_b_i + 178 * ((int32_T)c1_d_j - 1)) - 1] = c1_varargin_1
        [((int32_T)c1_b_i + 164 * ((int32_T)c1_d_j - 1)) - 1];
    }
  }
}

static void c1_f_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  uint8_T c1_varargin_1[19200], uint8_T c1_b[19764])
{
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_c_i;
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_c_j;
  real_T c1_a;
  int32_T c1_d_j;
  int32_T c1_c;
  real_T c1_b_a;
  int32_T c1_b_c;
  int32_T c1_d_i;
  real_T c1_c_a;
  int32_T c1_c_c;
  real_T c1_d_a;
  int32_T c1_d_c;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 122; c1_i++) {
    c1_c_i = (real_T)c1_i + 1.0;
    c1_b[(int32_T)c1_c_i - 1] = 0U;
  }

  for (c1_b_i = 0; c1_b_i < 122; c1_b_i++) {
    c1_c_i = (real_T)c1_b_i + 1.0;
    c1_b[(int32_T)c1_c_i + 19641] = 0U;
  }

  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_c_j = (real_T)c1_j + 1.0;
    c1_a = c1_c_j;
    c1_c = (int32_T)c1_a;
    c1_b[122 * c1_c] = 0U;
  }

  for (c1_b_j = 0; c1_b_j < 160; c1_b_j++) {
    c1_c_j = (real_T)c1_b_j + 1.0;
    c1_b_a = c1_c_j;
    c1_b_c = (int32_T)c1_b_a;
    c1_b[121 + 122 * c1_b_c] = 0U;
  }

  for (c1_d_j = 0; c1_d_j < 160; c1_d_j++) {
    c1_c_j = (real_T)c1_d_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 120; c1_d_i++) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      c1_c_a = c1_c_i;
      c1_c_c = (int32_T)c1_c_a;
      c1_d_a = c1_c_j;
      c1_d_c = (int32_T)c1_d_a;
      c1_b[c1_c_c + 122 * c1_d_c] = c1_varargin_1[((int32_T)c1_c_i + 120 *
        ((int32_T)c1_c_j - 1)) - 1];
    }
  }
}

static void c1_g_padarray(SFc1_flightControlSystemInstanceStruct *chartInstance,
  uint8_T c1_b[19764])
{
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_c_i;
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_c_j;
  real_T c1_a;
  int32_T c1_d_j;
  int32_T c1_c;
  real_T c1_b_a;
  int32_T c1_b_c;
  int32_T c1_d_i;
  real_T c1_c_a;
  int32_T c1_c_c;
  real_T c1_d_a;
  int32_T c1_d_c;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 122; c1_i++) {
    c1_c_i = (real_T)c1_i + 1.0;
    c1_b[(int32_T)c1_c_i - 1] = 0U;
  }

  for (c1_b_i = 0; c1_b_i < 122; c1_b_i++) {
    c1_c_i = (real_T)c1_b_i + 1.0;
    c1_b[(int32_T)c1_c_i + 19641] = 0U;
  }

  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_c_j = (real_T)c1_j + 1.0;
    c1_a = c1_c_j;
    c1_c = (int32_T)c1_a;
    c1_b[122 * c1_c] = 0U;
  }

  for (c1_b_j = 0; c1_b_j < 160; c1_b_j++) {
    c1_c_j = (real_T)c1_b_j + 1.0;
    c1_b_a = c1_c_j;
    c1_b_c = (int32_T)c1_b_a;
    c1_b[121 + 122 * c1_b_c] = 0U;
  }

  for (c1_d_j = 0; c1_d_j < 160; c1_d_j++) {
    c1_c_j = (real_T)c1_d_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 120; c1_d_i++) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      c1_c_a = c1_c_i;
      c1_c_c = (int32_T)c1_c_a;
      c1_d_a = c1_c_j;
      c1_d_c = (int32_T)c1_d_a;
      c1_b[c1_c_c + 122 * c1_d_c] = MAX_uint8_T;
    }
  }
}

static void c1_check_forloop_overflow_error
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp)
{
  const mxArray *c1_y = NULL;
  static char_T c1_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  static char_T c1_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c1_sp, "error", 0U, 2U, 14, c1_y, 14, sf_mex_call(c1_sp,
    "getString", 1U, 1U, 14, sf_mex_call(c1_sp, "message", 1U, 2U, 14, c1_b_y,
    14, c1_c_y)));
}

static void c1_imreconstruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, uint8_T c1_marker[19764], uint8_T c1_mask[19764], uint8_T
  c1_im[19764])
{
  int32_T c1_i;
  int32_T c1_i1;
  real_T c1_imSizeT[2];
  (void)chartInstance;
  for (c1_i = 0; c1_i < 19764; c1_i++) {
    c1_im[c1_i] = c1_marker[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_imSizeT[c1_i1] = 122.0 + 40.0 * (real_T)c1_i1;
  }

  ippreconstruct_uint8(c1_im, c1_mask, c1_imSizeT, 1.0);
}

static void c1_regionprops(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_varargin_1[19200],
  c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *c1_outstats)
{
  emlrtStack c1_st;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_g_st;
  emlrtStack c1_h_st;
  emlrtStack c1_i_st;
  emlrtStack c1_j_st;
  int32_T c1_i;
  c1_scIvRXQeSh8yxCxSmtD63bE c1_CC;
  boolean_T c1_b_varargin_1[19200];
  c1_emxArray_boolean_T *c1_tile;
  real_T c1_numObjs;
  real_T c1_b_numObjs;
  real_T c1_c_numObjs;
  real_T c1_c_varargin_1;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  int32_T c1_i2;
  int32_T c1_outsize[2];
  const mxArray *c1_y = NULL;
  c1_sKyE5zvueAoQJ4jaLWfzLx c1_s;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_b_loop_ub;
  int32_T c1_i6;
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats;
  c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed;
  int32_T c1_d_varargin_1;
  int32_T c1_e_varargin_1;
  real_T c1_d;
  int32_T c1_i7;
  int32_T c1_k;
  c1_emxArray_real_T *c1_r;
  real_T c1_b_k;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_f_varargin_1;
  int32_T c1_g_varargin_1;
  int32_T c1_i11;
  real_T c1_d1;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_c_loop_ub;
  int32_T c1_c_k;
  int32_T c1_i14;
  c1_emxArray_real_T *c1_list;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  real_T c1_d_k;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_h_varargin_1;
  int32_T c1_i21;
  int32_T c1_i_varargin_1;
  real_T c1_d2;
  int32_T c1_i22;
  int32_T c1_e_k;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  real_T c1_f_k;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_d_loop_ub;
  int32_T c1_j_varargin_1;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_k_varargin_1;
  int32_T c1_i30;
  real_T c1_d3;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_vlen;
  int32_T c1_i33;
  int32_T c1_g_k;
  boolean_T c1_b;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  real_T c1_h_k;
  int32_T c1_i37;
  int32_T c1_b_vlen;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_pagesize;
  real_T c1_max_corner[2];
  int32_T c1_i40;
  int32_T c1_e_loop_ub;
  int32_T c1_b_i;
  real_T c1_b_list;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_c_i;
  int32_T c1_i44;
  int32_T c1_i45;
  boolean_T c1_b1;
  int32_T c1_i46;
  int32_T c1_xpageoffset;
  int32_T c1_i47;
  int32_T c1_ypageoffset;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_ix;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_iy;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  static real_T c1_dv[4] = { 0.5, 0.5, 0.0, 0.0 };

  int32_T c1_b_b;
  int32_T c1_i56;
  const mxArray *c1_b_y = NULL;
  int32_T c1_c_b;
  int32_T c1_i57;
  const mxArray *c1_c_y = NULL;
  boolean_T c1_overflow;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_m;
  int32_T c1_j;
  int32_T c1_vIdx;
  int32_T c1_i_k;
  int32_T c1_i60;
  int32_T c1_b_j;
  int32_T c1_i61;
  real_T c1_b_vIdx;
  real_T c1_imageSize[2];
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_xoffset;
  int32_T c1_i64;
  int32_T c1_d_b;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_e_b;
  int32_T c1_i67;
  int32_T c1_i68;
  boolean_T c1_b_overflow;
  int32_T c1_c_vIdx;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i69;
  int32_T c1_d_i;
  int32_T c1_i70;
  int32_T c1_b_m;
  int32_T c1_i71;
  int32_T c1_c_j;
  int32_T c1_i72;
  real_T c1_a;
  int32_T c1_i73;
  int32_T c1_d_j;
  real_T c1_f_b;
  real_T c1_b_a;
  int32_T c1_i74;
  real_T c1_g_b;
  int32_T c1_i75;
  int32_T c1_h_b;
  boolean_T c1_p;
  int32_T c1_i_b;
  int32_T c1_i76;
  int32_T c1_i77;
  boolean_T c1_c_overflow;
  int32_T c1_i78;
  int32_T c1_e_i;
  real_T c1_c_a;
  real_T c1_j_b;
  real_T c1_d_a;
  real_T c1_k_b;
  boolean_T c1_b_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_g_st.prev = &c1_f_st;
  c1_g_st.tls = c1_f_st.tls;
  c1_h_st.prev = &c1_g_st;
  c1_h_st.tls = c1_g_st.tls;
  c1_i_st.prev = &c1_h_st;
  c1_i_st.tls = c1_h_st.tls;
  c1_j_st.prev = &c1_i_st;
  c1_j_st.tls = c1_i_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_b_varargin_1[c1_i] = c1_varargin_1[c1_i];
  }

  c1_emxInitStruct_scIvRXQeSh8yxCxSm(chartInstance, c1_sp, &c1_CC,
    &c1_l_emlrtRTEI);
  c1_st.site = &c1_v_emlrtRSI;
  c1_bwconncomp(chartInstance, &c1_st, c1_b_varargin_1, &c1_CC);
  c1_emxInit_boolean_T(chartInstance, c1_sp, &c1_tile, 1, &c1_g_emlrtRTEI);
  c1_numObjs = c1_CC.NumObjects;
  c1_st.site = &c1_w_emlrtRSI;
  c1_b_numObjs = c1_numObjs;
  c1_b_st.site = &c1_bc_emlrtRSI;
  c1_c_numObjs = c1_b_numObjs;
  c1_c_st.site = &c1_cc_emlrtRSI;
  c1_c_varargin_1 = c1_c_numObjs;
  c1_d_st.site = &c1_dc_emlrtRSI;
  c1_assertValidSizeArg(chartInstance, &c1_d_st, c1_c_varargin_1);
  c1_i1 = c1_tile->size[0];
  c1_tile->size[0] = (int32_T)c1_c_varargin_1;
  c1_emxEnsureCapacity_boolean_T(chartInstance, &c1_c_st, c1_tile, c1_i1,
    &c1_g_emlrtRTEI);
  c1_loop_ub = (int32_T)c1_c_varargin_1 - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    c1_tile->data[c1_i2] = false;
  }

  c1_outsize[0] = c1_tile->size[0];
  if (!((real_T)c1_outsize[0] == (real_T)c1_tile->size[0])) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c1_c_st, "error", 0U, 1U, 14, c1_y);
  }

  c1_emxFree_boolean_T(chartInstance, &c1_tile);
  c1_s.Area = 0.0;
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_s.Centroid[c1_i3] = 0.0;
  }

  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_s.BoundingBox[c1_i4] = 0.0;
  }

  c1_i5 = c1_outstats->size[0];
  c1_outstats->size[0] = c1_outsize[0];
  c1_emxEnsureCapacity_sKyE5zvueAoQJ(chartInstance, &c1_c_st, c1_outstats, c1_i5,
    &c1_h_emlrtRTEI);
  c1_b_loop_ub = c1_outsize[0] - 1;
  for (c1_i6 = 0; c1_i6 <= c1_b_loop_ub; c1_i6++) {
    c1_outstats->data[c1_i6] = c1_s;
  }

  c1_emxInit_s9uuw2Xu7QLvohu1q5iD2hG(chartInstance, &c1_c_st, &c1_stats, 1,
    &c1_m_emlrtRTEI);
  c1_st.site = &c1_x_emlrtRSI;
  c1_initializeStatsStruct(chartInstance, &c1_st, c1_numObjs, c1_stats,
    &c1_statsAlreadyComputed);
  c1_st.site = &c1_y_emlrtRSI;
  c1_b_ComputePixelIdxList(chartInstance, &c1_st, c1_CC, c1_numObjs, c1_stats,
    &c1_statsAlreadyComputed);
  c1_st.site = &c1_ab_emlrtRSI;
  c1_statsAlreadyComputed.Area = true;
  c1_d_varargin_1 = c1_stats->size[0];
  c1_e_varargin_1 = c1_d_varargin_1;
  c1_d = (real_T)c1_e_varargin_1;
  c1_i7 = (int32_T)c1_d - 1;
  c1_k = 0;
  c1_emxFreeStruct_scIvRXQeSh8yxCxSm(chartInstance, &c1_CC);
  c1_emxInit_real_T(chartInstance, &c1_st, &c1_r, 1, &c1_n_emlrtRTEI);
  while (c1_k <= c1_i7) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_i8 = c1_r->size[0];
    c1_i9 = c1_stats->size[0];
    c1_i10 = (int32_T)c1_b_k;
    c1_r->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i10, 1,
      c1_i9, &c1_o_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r, c1_i8,
      &c1_i_emlrtRTEI);
    c1_i11 = c1_stats->size[0];
    c1_i12 = (int32_T)c1_b_k;
    c1_c_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i12, 1,
      c1_i11, &c1_o_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0] - 1;
    for (c1_i14 = 0; c1_i14 <= c1_c_loop_ub; c1_i14++) {
      c1_i16 = c1_stats->size[0];
      c1_i18 = (int32_T)c1_b_k;
      c1_r->data[c1_i14] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i18,
        1, c1_i16, &c1_o_emlrtBCI, &c1_st) - 1].PixelIdxList->data[c1_i14];
    }

    c1_i15 = c1_stats->size[0];
    c1_i17 = (int32_T)c1_b_k;
    c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i17, 1, c1_i15,
      &c1_i_emlrtBCI, &c1_st) - 1].Area = (real_T)c1_r->size[0];
    c1_k++;
  }

  c1_emxFree_real_T(chartInstance, &c1_r);
  c1_st.site = &c1_bb_emlrtRSI;
  c1_statsAlreadyComputed.Centroid = true;
  c1_b_st.site = &c1_gc_emlrtRSI;
  c1_b_ComputePixelList(chartInstance, &c1_b_st, c1_stats,
                        &c1_statsAlreadyComputed);
  c1_f_varargin_1 = c1_stats->size[0];
  c1_g_varargin_1 = c1_f_varargin_1;
  c1_d1 = (real_T)c1_g_varargin_1;
  c1_i13 = (int32_T)c1_d1 - 1;
  c1_c_k = 0;
  c1_emxInit_real_T1(chartInstance, &c1_st, &c1_list, 2, &c1_k_emlrtRTEI);
  while (c1_c_k <= c1_i13) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_b_st.site = &c1_fc_emlrtRSI;
    c1_i19 = c1_list->size[0] * c1_list->size[1];
    c1_i20 = c1_stats->size[0];
    c1_i21 = (int32_T)c1_d_k;
    c1_list->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i21, 1,
      c1_i20, &c1_p_emlrtBCI, &c1_b_st) - 1].PixelList->size[0];
    c1_list->size[1] = 2;
    c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_list, c1_i19,
      &c1_j_emlrtRTEI);
    c1_i23 = c1_stats->size[0];
    c1_i24 = (int32_T)c1_d_k;
    c1_i25 = c1_stats->size[0];
    c1_i26 = (int32_T)c1_d_k;
    c1_d_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i24, 1,
      c1_i23, &c1_p_emlrtBCI, &c1_b_st) - 1].PixelList->size[0] * c1_stats->
      data[emlrtDynamicBoundsCheckR2012b(c1_i26, 1, c1_i25, &c1_p_emlrtBCI,
      &c1_b_st) - 1].PixelList->size[1] - 1;
    for (c1_i29 = 0; c1_i29 <= c1_d_loop_ub; c1_i29++) {
      c1_i31 = c1_stats->size[0];
      c1_i33 = (int32_T)c1_d_k;
      c1_list->data[c1_i29] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
        (c1_i33, 1, c1_i31, &c1_p_emlrtBCI, &c1_b_st) - 1].PixelList->
        data[c1_i29];
    }

    c1_c_st.site = &c1_mc_emlrtRSI;
    c1_vlen = c1_list->size[0];
    c1_b = (c1_list->size[0] == 0);
    if (c1_b || (c1_vlen == 0)) {
      for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
        c1_max_corner[c1_i36] = 0.0;
      }
    } else {
      c1_d_st.site = &c1_sb_emlrtRSI;
      c1_b_vlen = c1_vlen;
      c1_pagesize = c1_list->size[0];
      for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
        c1_c_i = c1_b_i;
        c1_xpageoffset = c1_c_i * c1_pagesize - 1;
        c1_ypageoffset = c1_c_i + 1;
        c1_ix = c1_xpageoffset;
        c1_iy = c1_ypageoffset - 1;
        c1_max_corner[c1_iy] = c1_list->data[c1_ix + 1];
        c1_e_st.site = &c1_tb_emlrtRSI;
        c1_b_b = c1_b_vlen;
        c1_c_b = c1_b_b;
        if (2 > c1_c_b) {
          c1_overflow = false;
        } else {
          c1_overflow = (c1_c_b > 2147483646);
        }

        if (c1_overflow) {
          c1_f_st.site = &c1_t_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
        }

        for (c1_i_k = 2; c1_i_k <= c1_b_vlen; c1_i_k++) {
          c1_xoffset = (c1_xpageoffset + c1_i_k) + 1;
          c1_ix = c1_xoffset - 1;
          c1_iy = c1_ypageoffset - 1;
          c1_max_corner[c1_iy] += c1_list->data[c1_ix];
        }
      }
    }

    c1_b_list = (real_T)c1_list->size[0];
    c1_i42 = c1_stats->size[0];
    for (c1_i44 = 0; c1_i44 < 2; c1_i44++) {
      c1_i48 = (int32_T)c1_d_k;
      c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i48, 1, c1_i42,
        &c1_j_emlrtBCI, &c1_b_st) - 1].Centroid[c1_i44] = c1_max_corner[c1_i44] /
        c1_b_list;
    }

    c1_c_k++;
  }

  c1_st.site = &c1_cb_emlrtRSI;
  c1_statsAlreadyComputed.BoundingBox = true;
  c1_b_st.site = &c1_pc_emlrtRSI;
  c1_b_ComputePixelList(chartInstance, &c1_b_st, c1_stats,
                        &c1_statsAlreadyComputed);
  c1_h_varargin_1 = c1_stats->size[0];
  c1_i_varargin_1 = c1_h_varargin_1;
  c1_d2 = (real_T)c1_i_varargin_1;
  c1_i22 = (int32_T)c1_d2 - 1;
  for (c1_e_k = 0; c1_e_k <= c1_i22; c1_e_k++) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_i27 = c1_list->size[0] * c1_list->size[1];
    c1_i28 = c1_stats->size[0];
    c1_i30 = (int32_T)c1_f_k;
    c1_list->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i30, 1,
      c1_i28, &c1_q_emlrtBCI, &c1_st) - 1].PixelList->size[0];
    c1_list->size[1] = 2;
    c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_list, c1_i27,
      &c1_k_emlrtRTEI);
    c1_i34 = c1_stats->size[0];
    c1_i35 = (int32_T)c1_f_k;
    c1_i37 = c1_stats->size[0];
    c1_i39 = (int32_T)c1_f_k;
    c1_e_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i35, 1,
      c1_i34, &c1_r_emlrtBCI, &c1_st) - 1].PixelList->size[0] * c1_stats->
      data[emlrtDynamicBoundsCheckR2012b(c1_i39, 1, c1_i37, &c1_r_emlrtBCI,
      &c1_st) - 1].PixelList->size[1] - 1;
    for (c1_i41 = 0; c1_i41 <= c1_e_loop_ub; c1_i41++) {
      c1_i46 = c1_stats->size[0];
      c1_i47 = (int32_T)c1_f_k;
      c1_list->data[c1_i41] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
        (c1_i47, 1, c1_i46, &c1_q_emlrtBCI, &c1_st) - 1].PixelList->data[c1_i41];
    }

    c1_b1 = (c1_list->size[0] == 0);
    if (c1_b1) {
      c1_i50 = c1_stats->size[0];
      for (c1_i52 = 0; c1_i52 < 4; c1_i52++) {
        c1_i55 = (int32_T)c1_f_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i55, 1, c1_i50,
          &c1_k_emlrtBCI, &c1_st) - 1].BoundingBox[c1_i52] = c1_dv[c1_i52];
      }
    } else {
      c1_b_st.site = &c1_oc_emlrtRSI;
      c1_c_st.site = &c1_qc_emlrtRSI;
      c1_d_st.site = &c1_rc_emlrtRSI;
      c1_e_st.site = &c1_sc_emlrtRSI;
      if (!((real_T)c1_list->size[0] >= 1.0)) {
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_e_st, "error", 0U, 2U, 14, c1_b_y, 14, sf_mex_call
                    (&c1_e_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_e_st,
          "message", 1U, 1U, 14, c1_c_y)));
      }

      c1_f_st.site = &c1_tc_emlrtRSI;
      c1_g_st.site = &c1_uc_emlrtRSI;
      c1_h_st.site = &c1_vc_emlrtRSI;
      c1_m = c1_list->size[0];
      for (c1_j = 0; c1_j < 2; c1_j++) {
        c1_b_j = c1_j;
        c1_imageSize[c1_b_j] = c1_list->data[c1_list->size[0] * c1_b_j];
        c1_i_st.site = &c1_wc_emlrtRSI;
        c1_d_b = c1_m;
        c1_e_b = c1_d_b;
        if (2 > c1_e_b) {
          c1_b_overflow = false;
        } else {
          c1_b_overflow = (c1_e_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_j_st.site = &c1_t_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_j_st);
        }

        for (c1_d_i = 1; c1_d_i < c1_m; c1_d_i++) {
          c1_a = c1_imageSize[c1_b_j];
          c1_f_b = c1_list->data[c1_d_i + c1_list->size[0] * c1_b_j];
          c1_b_a = c1_a;
          c1_g_b = c1_f_b;
          c1_p = (c1_b_a > c1_g_b);
          if (c1_p) {
            c1_imageSize[c1_b_j] = c1_list->data[c1_d_i + c1_list->size[0] *
              c1_b_j];
          }
        }
      }

      for (c1_i60 = 0; c1_i60 < 2; c1_i60++) {
        c1_imageSize[c1_i60] -= 0.5;
      }

      c1_b_st.site = &c1_nc_emlrtRSI;
      c1_c_st.site = &c1_xc_emlrtRSI;
      c1_d_st.site = &c1_rc_emlrtRSI;
      c1_e_st.site = &c1_sc_emlrtRSI;
      if (!((real_T)c1_list->size[0] >= 1.0)) {
        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c1_e_y = NULL;
        sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_e_st, "error", 0U, 2U, 14, c1_d_y, 14, sf_mex_call
                    (&c1_e_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_e_st,
          "message", 1U, 1U, 14, c1_e_y)));
      }

      c1_f_st.site = &c1_tc_emlrtRSI;
      c1_g_st.site = &c1_uc_emlrtRSI;
      c1_h_st.site = &c1_vc_emlrtRSI;
      c1_b_m = c1_list->size[0];
      for (c1_c_j = 0; c1_c_j < 2; c1_c_j++) {
        c1_d_j = c1_c_j;
        c1_max_corner[c1_d_j] = c1_list->data[c1_list->size[0] * c1_d_j];
        c1_i_st.site = &c1_wc_emlrtRSI;
        c1_h_b = c1_b_m;
        c1_i_b = c1_h_b;
        if (2 > c1_i_b) {
          c1_c_overflow = false;
        } else {
          c1_c_overflow = (c1_i_b > 2147483646);
        }

        if (c1_c_overflow) {
          c1_j_st.site = &c1_t_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_j_st);
        }

        for (c1_e_i = 1; c1_e_i < c1_b_m; c1_e_i++) {
          c1_c_a = c1_max_corner[c1_d_j];
          c1_j_b = c1_list->data[c1_e_i + c1_list->size[0] * c1_d_j];
          c1_d_a = c1_c_a;
          c1_k_b = c1_j_b;
          c1_b_p = (c1_d_a < c1_k_b);
          if (c1_b_p) {
            c1_max_corner[c1_d_j] = c1_list->data[c1_e_i + c1_list->size[0] *
              c1_d_j];
          }
        }
      }

      for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
        c1_max_corner[c1_i73] += 0.5;
      }

      c1_i74 = c1_stats->size[0];
      for (c1_i75 = 0; c1_i75 < 2; c1_i75++) {
        c1_i77 = (int32_T)c1_f_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i77, 1, c1_i74,
          &c1_n_emlrtBCI, &c1_st) - 1].BoundingBox[c1_i75] = c1_imageSize[c1_i75];
      }

      for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
        c1_i78 = (int32_T)c1_f_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i78, 1, c1_i74,
          &c1_n_emlrtBCI, &c1_st) - 1].BoundingBox[c1_i76 + 2] =
          c1_max_corner[c1_i76] - c1_imageSize[c1_i76];
      }
    }
  }

  c1_emxFree_real_T(chartInstance, &c1_list);
  c1_st.site = &c1_db_emlrtRSI;
  c1_j_varargin_1 = c1_stats->size[0];
  c1_k_varargin_1 = c1_j_varargin_1;
  c1_d3 = (real_T)c1_k_varargin_1;
  c1_i32 = (int32_T)c1_d3 - 1;
  for (c1_g_k = 0; c1_g_k <= c1_i32; c1_g_k++) {
    c1_h_k = (real_T)c1_g_k + 1.0;
    c1_i38 = c1_stats->size[0];
    c1_i40 = (int32_T)c1_h_k;
    emlrtDynamicBoundsCheckR2012b(c1_i40, 1, c1_i38, &c1_g_emlrtBCI, &c1_st);
    c1_i43 = c1_outstats->size[0];
    c1_i45 = (int32_T)c1_h_k;
    emlrtDynamicBoundsCheckR2012b(c1_i45, 1, c1_i43, &c1_h_emlrtBCI, &c1_st);
    c1_i49 = c1_stats->size[0];
    c1_i51 = (int32_T)c1_h_k;
    c1_i53 = c1_outstats->size[0];
    c1_i54 = (int32_T)c1_h_k;
    c1_outstats->data[emlrtDynamicBoundsCheckR2012b(c1_i54, 1, c1_i53,
      &c1_m_emlrtBCI, &c1_st) - 1].Area = c1_stats->
      data[emlrtDynamicBoundsCheckR2012b(c1_i51, 1, c1_i49, &c1_l_emlrtBCI,
      &c1_st) - 1].Area;
    c1_i56 = c1_stats->size[0];
    c1_i57 = (int32_T)c1_h_k;
    emlrtDynamicBoundsCheckR2012b(c1_i57, 1, c1_i56, &c1_g_emlrtBCI, &c1_st);
    c1_i58 = c1_outstats->size[0];
    c1_i59 = (int32_T)c1_h_k;
    emlrtDynamicBoundsCheckR2012b(c1_i59, 1, c1_i58, &c1_h_emlrtBCI, &c1_st);
    for (c1_vIdx = 0; c1_vIdx < 2; c1_vIdx++) {
      c1_b_vIdx = (real_T)c1_vIdx + 1.0;
      c1_i63 = c1_stats->size[0];
      c1_i64 = (int32_T)c1_h_k;
      c1_i66 = c1_outstats->size[0];
      c1_i68 = (int32_T)c1_h_k;
      c1_outstats->data[emlrtDynamicBoundsCheckR2012b(c1_i68, 1, c1_i66,
        &c1_m_emlrtBCI, &c1_st) - 1].Centroid[(int32_T)c1_b_vIdx - 1] =
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i64, 1, c1_i63,
        &c1_l_emlrtBCI, &c1_st) - 1].Centroid[(int32_T)c1_b_vIdx - 1];
    }

    c1_i61 = c1_stats->size[0];
    c1_i62 = (int32_T)c1_h_k;
    emlrtDynamicBoundsCheckR2012b(c1_i62, 1, c1_i61, &c1_g_emlrtBCI, &c1_st);
    c1_i65 = c1_outstats->size[0];
    c1_i67 = (int32_T)c1_h_k;
    emlrtDynamicBoundsCheckR2012b(c1_i67, 1, c1_i65, &c1_h_emlrtBCI, &c1_st);
    for (c1_c_vIdx = 0; c1_c_vIdx < 4; c1_c_vIdx++) {
      c1_b_vIdx = (real_T)c1_c_vIdx + 1.0;
      c1_i69 = c1_stats->size[0];
      c1_i70 = (int32_T)c1_h_k;
      c1_i71 = c1_outstats->size[0];
      c1_i72 = (int32_T)c1_h_k;
      c1_outstats->data[emlrtDynamicBoundsCheckR2012b(c1_i72, 1, c1_i71,
        &c1_m_emlrtBCI, &c1_st) - 1].BoundingBox[(int32_T)c1_b_vIdx - 1] =
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i70, 1, c1_i69,
        &c1_l_emlrtBCI, &c1_st) - 1].BoundingBox[(int32_T)c1_b_vIdx - 1];
    }
  }

  c1_emxFree_s9uuw2Xu7QLvohu1q5iD2hG(chartInstance, &c1_stats);
}

static void c1_bwconncomp(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_varargin_1[19200],
  c1_scIvRXQeSh8yxCxSmtD63bE *c1_CC)
{
  emlrtStack c1_st;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_g_st;
  emlrtStack c1_h_st;
  int32_T c1_numRuns;
  int32_T c1_col;
  c1_emxArray_int32_T *c1_regionLengths;
  real_T c1_b_col;
  c1_emxArray_int32_T *c1_startRow;
  c1_emxArray_int32_T *c1_endRow;
  c1_emxArray_int32_T *c1_startCol;
  int32_T c1_k;
  int32_T c1_i;
  real_T c1_b_k;
  real_T c1_d;
  int32_T c1_i1;
  c1_emxArray_int32_T *c1_labelsRenumbered;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T c1_numComponents;
  int32_T c1_i5;
  int32_T c1_b;
  int32_T c1_runCounter;
  int32_T c1_b_b;
  int32_T c1_c_col;
  boolean_T c1_overflow;
  int32_T c1_i6;
  real_T c1_d_col;
  int32_T c1_row;
  int32_T c1_loop_ub;
  int32_T c1_c_k;
  int32_T c1_i7;
  int32_T c1_d_k;
  int32_T c1_i8;
  int32_T c1_e_k;
  int32_T c1_currentColumn;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_nextLabel;
  int32_T c1_firstRunOnPreviousColumn;
  int32_T c1_i11;
  int32_T c1_lastRunOnPreviousColumn;
  int32_T c1_b_loop_ub;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_firstRunOnThisColumn;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_c_b;
  int32_T c1_d_b;
  int32_T c1_i20;
  boolean_T c1_b_overflow;
  int32_T c1_i21;
  int32_T c1_p;
  int32_T c1_i22;
  int32_T c1_f_k;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_idx;
  int32_T c1_i28;
  int32_T c1_vlen;
  int32_T c1_i29;
  int32_T c1_i30;
  real_T c1_y;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_b_vlen;
  int32_T c1_i33;
  c1_emxArray_real_T *c1_pixelIdxList;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  c1_emxArray_int32_T *c1_x;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_e_b;
  real_T c1_d1;
  int32_T c1_f_b;
  int32_T c1_iv[1];
  int32_T c1_i39;
  int32_T c1_g_k;
  boolean_T c1_c_overflow;
  int32_T c1_b_p;
  int32_T c1_node;
  int32_T c1_i40;
  int32_T c1_root_k;
  int32_T c1_h_k;
  int32_T c1_exitg1;
  int32_T c1_i41;
  int32_T c1_xoffset;
  int32_T c1_c_loop_ub;
  int32_T c1_ix;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_dim;
  int32_T c1_i46;
  int32_T c1_b_node;
  int32_T c1_root_p;
  int32_T c1_i47;
  int32_T c1_varargin_3;
  int32_T c1_i48;
  c1_emxArray_int32_T *c1_idxCount;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_b_varargin_1;
  int32_T c1_i53;
  int32_T c1_c_varargin_1;
  real_T c1_n;
  int32_T c1_b_root_k;
  int32_T c1_i54;
  int32_T c1_d_loop_ub;
  int32_T c1_nx;
  int32_T c1_b_root_p;
  int32_T c1_i55;
  int32_T c1_i_k;
  int32_T c1_i56;
  int32_T c1_c_p;
  int32_T c1_g_b;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_h_b;
  int32_T c1_i_b;
  int32_T c1_j_b;
  int32_T c1_i59;
  int32_T c1_i60;
  boolean_T c1_d_overflow;
  boolean_T c1_e_overflow;
  int32_T c1_j_k;
  int32_T c1_k_k;
  int32_T c1_l_k;
  int32_T c1_i61;
  int32_T c1_a;
  int32_T c1_i62;
  int32_T c1_c;
  int32_T c1_b_a;
  int32_T c1_column_offset;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_e_loop_ub;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_c_a;
  int32_T c1_k_b;
  int32_T c1_f_loop_ub;
  int32_T c1_d_a;
  int32_T c1_i71;
  int32_T c1_l_b;
  boolean_T c1_f_overflow;
  int32_T c1_rowidx;
  int32_T c1_i72;
  int32_T c1_e_a;
  int32_T c1_b_c;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_eb_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_g_st.prev = &c1_f_st;
  c1_g_st.tls = c1_f_st.tls;
  c1_h_st.prev = &c1_g_st;
  c1_h_st.tls = c1_g_st.tls;
  c1_numRuns = 0;
  for (c1_col = 0; c1_col < 160; c1_col++) {
    c1_b_col = (real_T)c1_col + 1.0;
    if (c1_varargin_1[120 * ((int32_T)c1_b_col - 1)]) {
      c1_numRuns++;
    }

    for (c1_k = 0; c1_k < 119; c1_k++) {
      c1_b_k = (real_T)c1_k + 2.0;
      if (c1_varargin_1[((int32_T)c1_b_k + 120 * ((int32_T)c1_b_col - 1)) - 1] &&
          (!c1_varargin_1[((int32_T)(c1_b_k - 1.0) + 120 * ((int32_T)c1_b_col -
             1)) - 1])) {
        c1_numRuns++;
      }
    }
  }

  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_regionLengths, 1,
                     &c1_y_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_startRow, 1, &c1_bb_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_endRow, 1, &c1_cb_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_startCol, 1, &c1_db_emlrtRTEI);
  if (c1_numRuns == 0) {
    c1_startRow->size[0] = 0;
    c1_endRow->size[0] = 0;
    c1_startCol->size[0] = 0;
    c1_regionLengths->size[0] = 0;
    c1_numRuns = 0;
  } else {
    c1_i = c1_startRow->size[0];
    c1_d = (real_T)c1_numRuns;
    c1_startRow->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c1_d,
      &c1_c_emlrtDCI, &c1_st);
    c1_b_st.site = &c1_eb_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_startRow, c1_i,
      &c1_o_emlrtRTEI);
    c1_i1 = c1_endRow->size[0];
    c1_endRow->size[0] = c1_numRuns;
    c1_b_st.site = &c1_eb_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_endRow, c1_i1,
      &c1_o_emlrtRTEI);
    c1_i4 = c1_startCol->size[0];
    c1_startCol->size[0] = c1_numRuns;
    c1_b_st.site = &c1_eb_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_startCol, c1_i4,
      &c1_o_emlrtRTEI);
    c1_b_st.site = &c1_lb_emlrtRSI;
    c1_runCounter = 1;
    for (c1_c_col = 0; c1_c_col < 160; c1_c_col++) {
      c1_d_col = (real_T)c1_c_col + 1.0;
      c1_row = 1;
      while (c1_row <= 120) {
        while ((c1_row <= 120) && (!c1_varargin_1[(c1_row + 120 * ((int32_T)
                  c1_d_col - 1)) - 1])) {
          c1_row++;
        }

        if ((c1_row <= 120) && c1_varargin_1[(c1_row + 120 * ((int32_T)c1_d_col
              - 1)) - 1]) {
          c1_i9 = c1_startCol->size[0];
          c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1,
            c1_i9, &c1_s_emlrtBCI, &c1_b_st) - 1] = (int32_T)c1_d_col;
          c1_i11 = c1_startRow->size[0];
          c1_startRow->data[emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1,
            c1_i11, &c1_u_emlrtBCI, &c1_b_st) - 1] = c1_row;
          while ((c1_row <= 120) && c1_varargin_1[(c1_row + 120 * ((int32_T)
                   c1_d_col - 1)) - 1]) {
            c1_row++;
          }

          c1_i17 = c1_endRow->size[0];
          c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1, c1_i17,
            &c1_x_emlrtBCI, &c1_b_st) - 1] = c1_row - 1;
          c1_runCounter++;
        }
      }
    }

    c1_i6 = c1_regionLengths->size[0];
    c1_regionLengths->size[0] = c1_numRuns;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_regionLengths, c1_i6,
      &c1_p_emlrtRTEI);
    c1_loop_ub = c1_numRuns - 1;
    for (c1_i7 = 0; c1_i7 <= c1_loop_ub; c1_i7++) {
      c1_regionLengths->data[c1_i7] = 0;
    }

    c1_d_k = 1;
    c1_currentColumn = 2;
    c1_nextLabel = 1;
    c1_firstRunOnPreviousColumn = -1;
    c1_lastRunOnPreviousColumn = 0;
    c1_firstRunOnThisColumn = 1;
    while (c1_d_k <= c1_numRuns) {
      c1_i19 = c1_startCol->size[0];
      if (c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i19,
           &c1_t_emlrtBCI, &c1_st) - 1] == c1_currentColumn) {
        c1_firstRunOnPreviousColumn = c1_firstRunOnThisColumn;
        c1_firstRunOnThisColumn = c1_d_k;
        c1_lastRunOnPreviousColumn = c1_d_k;
        c1_i21 = c1_startCol->size[0];
        c1_currentColumn = c1_startCol->data[emlrtDynamicBoundsCheckR2012b
          (c1_d_k, 1, c1_i21, &c1_w_emlrtBCI, &c1_st) - 1] + 1;
      } else {
        c1_i20 = c1_startCol->size[0];
        if (c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i20,
             &c1_v_emlrtBCI, &c1_st) - 1] > c1_currentColumn) {
          c1_firstRunOnPreviousColumn = -1;
          c1_lastRunOnPreviousColumn = 0;
          c1_firstRunOnThisColumn = c1_d_k;
          c1_i22 = c1_startCol->size[0];
          c1_currentColumn = c1_startCol->data[emlrtDynamicBoundsCheckR2012b
            (c1_d_k, 1, c1_i22, &c1_ab_emlrtBCI, &c1_st) - 1] + 1;
        }
      }

      if (c1_firstRunOnPreviousColumn >= 0) {
        for (c1_p = c1_firstRunOnPreviousColumn; c1_p <
             c1_lastRunOnPreviousColumn; c1_p++) {
          c1_i25 = c1_endRow->size[0];
          c1_i26 = c1_startRow->size[0];
          if (c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i25,
               &c1_gb_emlrtBCI, &c1_st) - 1] >= c1_startRow->
              data[emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i26,
               &c1_hb_emlrtBCI, &c1_st) - 1] - 1) {
            c1_i28 = c1_startRow->size[0];
            c1_i29 = c1_endRow->size[0];
            if (c1_startRow->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1,
                 c1_i28, &c1_ib_emlrtBCI, &c1_st) - 1] <= c1_endRow->
                data[emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i29,
                 &c1_jb_emlrtBCI, &c1_st) - 1] + 1) {
              c1_i32 = c1_regionLengths->size[0];
              if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1,
                   c1_i32, &c1_kb_emlrtBCI, &c1_st) - 1] == 0) {
                c1_i36 = c1_regionLengths->size[0];
                c1_i38 = c1_regionLengths->size[0];
                c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1,
                  c1_i38, &c1_ob_emlrtBCI, &c1_st) - 1] = c1_regionLengths->
                  data[emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i36,
                  &c1_nb_emlrtBCI, &c1_st) - 1];
                c1_nextLabel++;
              } else {
                c1_i35 = c1_regionLengths->size[0];
                c1_i37 = c1_regionLengths->size[0];
                if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_d_k,
                     1, c1_i35, &c1_lb_emlrtBCI, &c1_st) - 1] !=
                    c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_p, 1,
                     c1_i37, &c1_mb_emlrtBCI, &c1_st) - 1]) {
                  c1_b_st.site = &c1_mb_emlrtRSI;
                  c1_g_k = c1_d_k;
                  c1_b_p = c1_p;
                  c1_c_st.site = &c1_nb_emlrtRSI;
                  c1_node = c1_g_k;
                  c1_root_k = c1_node;
                  do {
                    c1_exitg1 = 0;
                    c1_i41 = c1_regionLengths->size[0];
                    if (c1_root_k != c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i41,
                         &c1_qb_emlrtBCI, &c1_c_st) - 1]) {
                      c1_i43 = c1_regionLengths->size[0];
                      c1_i44 = c1_regionLengths->size[0];
                      c1_i45 = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i44,
                        &c1_rb_emlrtBCI, &c1_c_st) - 1];
                      c1_i46 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_root_k, 1, c1_i46, &c1_sb_emlrtBCI, &c1_c_st) - 1] =
                        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_i45, 1, c1_i43, &c1_rb_emlrtBCI, &c1_c_st) - 1];
                      c1_i47 = c1_regionLengths->size[0];
                      c1_root_k = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i47,
                        &c1_tb_emlrtBCI, &c1_c_st) - 1];
                    } else {
                      c1_exitg1 = 1;
                    }
                  } while (c1_exitg1 == 0);

                  c1_c_st.site = &c1_ob_emlrtRSI;
                  c1_b_node = c1_b_p;
                  c1_root_p = c1_b_node;
                  do {
                    c1_exitg1 = 0;
                    c1_i48 = c1_regionLengths->size[0];
                    if (c1_root_p != c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i48,
                         &c1_qb_emlrtBCI, &c1_c_st) - 1]) {
                      c1_i49 = c1_regionLengths->size[0];
                      c1_i51 = c1_regionLengths->size[0];
                      c1_i52 = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i51,
                        &c1_rb_emlrtBCI, &c1_c_st) - 1];
                      c1_i53 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_root_p, 1, c1_i53, &c1_sb_emlrtBCI, &c1_c_st) - 1] =
                        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_i52, 1, c1_i49, &c1_rb_emlrtBCI, &c1_c_st) - 1];
                      c1_i54 = c1_regionLengths->size[0];
                      c1_root_p = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i54,
                        &c1_tb_emlrtBCI, &c1_c_st) - 1];
                    } else {
                      c1_exitg1 = 1;
                    }
                  } while (c1_exitg1 == 0);

                  if (c1_root_k != c1_root_p) {
                    c1_c_st.site = &c1_pb_emlrtRSI;
                    c1_b_root_k = c1_root_k;
                    c1_b_root_p = c1_root_p;
                    c1_i_k = c1_g_k;
                    c1_c_p = c1_b_p;
                    if (c1_b_root_p < c1_b_root_k) {
                      c1_i58 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_b_root_k, 1, c1_i58, &c1_ac_emlrtBCI, &c1_c_st) - 1]
                        = c1_b_root_p;
                      c1_i60 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_i_k, 1, c1_i60, &c1_cc_emlrtBCI, &c1_c_st) - 1] =
                        c1_b_root_p;
                    } else {
                      c1_i57 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_b_root_p, 1, c1_i57, &c1_yb_emlrtBCI, &c1_c_st) - 1]
                        = c1_b_root_k;
                      c1_i59 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_c_p, 1, c1_i59, &c1_bc_emlrtBCI, &c1_c_st) - 1] =
                        c1_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c1_i23 = c1_regionLengths->size[0];
      if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i23,
           &c1_bb_emlrtBCI, &c1_st) - 1] == 0) {
        c1_i24 = c1_regionLengths->size[0];
        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i24,
          &c1_fb_emlrtBCI, &c1_st) - 1] = c1_nextLabel;
        c1_nextLabel++;
      }

      c1_d_k++;
    }
  }

  if (c1_numRuns == 0) {
    c1_CC->Connectivity = 8.0;
    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_CC->ImageSize[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    c1_CC->NumObjects = 0.0;
    c1_CC->RegionIndices->size[0] = 0;
    c1_i5 = c1_CC->RegionLengths->size[0];
    c1_CC->RegionLengths->size[0] = 1;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_CC->RegionLengths,
      c1_i5, &c1_r_emlrtRTEI);
    c1_CC->RegionLengths->data[0] = 0;
  } else {
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_labelsRenumbered, 1,
                       &c1_ab_emlrtRTEI);
    c1_i2 = c1_labelsRenumbered->size[0];
    c1_labelsRenumbered->size[0] = c1_regionLengths->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_labelsRenumbered,
      c1_i2, &c1_q_emlrtRTEI);
    c1_numComponents = 0.0;
    c1_st.site = &c1_fb_emlrtRSI;
    c1_b = c1_numRuns;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_t_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_c_k = 1; c1_c_k - 1 < c1_numRuns; c1_c_k++) {
      c1_e_k = c1_c_k;
      c1_i10 = c1_regionLengths->size[0];
      if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i10,
           &c1_y_emlrtBCI, c1_sp) - 1] == c1_e_k) {
        c1_numComponents++;
        c1_i13 = c1_labelsRenumbered->size[0];
        c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
          c1_i13, &c1_eb_emlrtBCI, c1_sp) - 1] = (int32_T)c1_numComponents;
      }

      c1_i12 = c1_labelsRenumbered->size[0];
      c1_i15 = c1_regionLengths->size[0];
      c1_i16 = c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
        c1_i15, &c1_cb_emlrtBCI, c1_sp) - 1];
      c1_i18 = c1_labelsRenumbered->size[0];
      c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i18,
        &c1_db_emlrtBCI, c1_sp) - 1] = c1_labelsRenumbered->
        data[emlrtDynamicBoundsCheckR2012b(c1_i16, 1, c1_i12, &c1_cb_emlrtBCI,
        c1_sp) - 1];
    }

    c1_i8 = c1_regionLengths->size[0];
    c1_regionLengths->size[0] = (int32_T)emlrtIntegerCheckR2012b
      (c1_numComponents, &c1_d_emlrtDCI, c1_sp);
    c1_st.site = &c1_od_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_regionLengths, c1_i8,
      &c1_s_emlrtRTEI);
    c1_b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(c1_numComponents,
      &c1_d_emlrtDCI, c1_sp) - 1;
    for (c1_i14 = 0; c1_i14 <= c1_b_loop_ub; c1_i14++) {
      c1_regionLengths->data[c1_i14] = 0;
    }

    c1_st.site = &c1_gb_emlrtRSI;
    c1_c_b = c1_numRuns;
    c1_d_b = c1_c_b;
    if (1 > c1_d_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_d_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_b_st.site = &c1_t_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_f_k = 1; c1_f_k - 1 < c1_numRuns; c1_f_k++) {
      c1_e_k = c1_f_k;
      c1_i27 = c1_labelsRenumbered->size[0];
      c1_idx = c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
        c1_i27, &c1_pb_emlrtBCI, c1_sp) - 1];
      if (c1_idx > 0) {
        c1_i30 = c1_regionLengths->size[0];
        c1_i31 = c1_endRow->size[0];
        c1_i33 = c1_startRow->size[0];
        c1_i34 = c1_regionLengths->size[0];
        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i34,
          &c1_xb_emlrtBCI, c1_sp) - 1] = ((c1_regionLengths->
          data[emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i30, &c1_ub_emlrtBCI,
          c1_sp) - 1] + c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
          c1_i31, &c1_vb_emlrtBCI, c1_sp) - 1]) - c1_startRow->
          data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i33, &c1_wb_emlrtBCI,
          c1_sp) - 1]) + 1;
      }
    }

    c1_st.site = &c1_hb_emlrtRSI;
    c1_b_st.site = &c1_qb_emlrtRSI;
    c1_c_st.site = &c1_rb_emlrtRSI;
    c1_vlen = c1_regionLengths->size[0];
    if ((c1_regionLengths->size[0] == 0) || (c1_vlen == 0)) {
      c1_y = 0.0;
    } else {
      c1_d_st.site = &c1_sb_emlrtRSI;
      c1_b_vlen = c1_vlen;
      c1_y = (real_T)c1_regionLengths->data[0];
      c1_e_st.site = &c1_tb_emlrtRSI;
      c1_e_b = c1_b_vlen;
      c1_f_b = c1_e_b;
      if (2 > c1_f_b) {
        c1_c_overflow = false;
      } else {
        c1_c_overflow = (c1_f_b > 2147483646);
      }

      if (c1_c_overflow) {
        c1_f_st.site = &c1_t_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
      }

      for (c1_h_k = 1; c1_h_k < c1_b_vlen; c1_h_k++) {
        c1_xoffset = c1_h_k + 1;
        c1_ix = c1_xoffset - 1;
        c1_y += (real_T)c1_regionLengths->data[c1_ix];
      }
    }

    c1_emxInit_real_T(chartInstance, &c1_c_st, &c1_pixelIdxList, 1,
                      &c1_x_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_x, 1, &c1_t_emlrtRTEI);
    c1_d1 = emlrtNonNegativeCheckR2012b(c1_y, &c1_f_emlrtDCI, c1_sp);
    c1_iv[0] = (int32_T)emlrtIntegerCheckR2012b(c1_d1, &c1_e_emlrtDCI, c1_sp);
    c1_i39 = c1_pixelIdxList->size[0];
    c1_pixelIdxList->size[0] = c1_iv[0];
    c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_pixelIdxList, c1_i39,
      &c1_q_emlrtRTEI);
    c1_st.site = &c1_ib_emlrtRSI;
    c1_i40 = c1_x->size[0];
    c1_x->size[0] = c1_regionLengths->size[0];
    c1_b_st.site = &c1_ib_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_x, c1_i40,
      &c1_t_emlrtRTEI);
    c1_c_loop_ub = c1_regionLengths->size[0] - 1;
    for (c1_i42 = 0; c1_i42 <= c1_c_loop_ub; c1_i42++) {
      c1_x->data[c1_i42] = c1_regionLengths->data[c1_i42];
    }

    c1_b_st.site = &c1_ub_emlrtRSI;
    c1_dim = 2;
    if ((real_T)c1_x->size[0] != 1.0) {
      c1_dim = 1;
    }

    c1_c_st.site = &c1_vb_emlrtRSI;
    c1_varargin_3 = c1_dim;
    if (1 == c1_varargin_3) {
      c1_d_st.site = &c1_wb_emlrtRSI;
      c1_e_st.site = &c1_xb_emlrtRSI;
      if (c1_x->size[0] != 0) {
        c1_f_st.site = &c1_yb_emlrtRSI;
        c1_b_varargin_1 = c1_x->size[0];
        c1_c_varargin_1 = c1_b_varargin_1;
        c1_n = (real_T)c1_c_varargin_1;
        c1_nx = (int32_T)c1_n - 1;
        if (!((real_T)c1_x->size[0] == 1.0)) {
          c1_i56 = c1_nx;
          c1_g_st.site = &c1_ac_emlrtRSI;
          c1_g_b = c1_i56;
          c1_i_b = c1_g_b;
          if (1 > c1_i_b) {
            c1_d_overflow = false;
          } else {
            c1_d_overflow = (c1_i_b > 2147483646);
          }

          if (c1_d_overflow) {
            c1_h_st.site = &c1_t_emlrtRSI;
            c1_check_forloop_overflow_error(chartInstance, &c1_h_st);
          }

          for (c1_j_k = 1; c1_j_k - 1 < c1_i56; c1_j_k++) {
            c1_l_k = c1_j_k;
            c1_x->data[c1_l_k] += c1_x->data[c1_l_k - 1];
          }
        }
      }
    }

    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_idxCount, 1, &c1_u_emlrtRTEI);
    c1_i50 = c1_idxCount->size[0];
    c1_idxCount->size[0] = 1 + c1_x->size[0];
    c1_st.site = &c1_ib_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_idxCount, c1_i50,
      &c1_u_emlrtRTEI);
    c1_idxCount->data[0] = 0;
    c1_d_loop_ub = c1_x->size[0] - 1;
    for (c1_i55 = 0; c1_i55 <= c1_d_loop_ub; c1_i55++) {
      c1_idxCount->data[c1_i55 + 1] = c1_x->data[c1_i55];
    }

    c1_emxFree_int32_T(chartInstance, &c1_x);
    c1_st.site = &c1_jb_emlrtRSI;
    c1_h_b = c1_numRuns;
    c1_j_b = c1_h_b;
    if (1 > c1_j_b) {
      c1_e_overflow = false;
    } else {
      c1_e_overflow = (c1_j_b > 2147483646);
    }

    if (c1_e_overflow) {
      c1_b_st.site = &c1_t_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_k_k = 1; c1_k_k - 1 < c1_numRuns; c1_k_k++) {
      c1_e_k = c1_k_k;
      c1_i61 = c1_startCol->size[0];
      c1_a = c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i61,
        &c1_dc_emlrtBCI, c1_sp) - 1] - 1;
      c1_c = c1_a;
      c1_b_a = c1_c;
      c1_column_offset = c1_b_a * 120;
      c1_i64 = c1_labelsRenumbered->size[0];
      c1_idx = c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
        c1_i64, &c1_ec_emlrtBCI, c1_sp) - 1];
      if (c1_idx > 0) {
        c1_i65 = c1_startRow->size[0];
        c1_i67 = c1_startRow->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
          c1_i65, &c1_fc_emlrtBCI, c1_sp) - 1];
        c1_i68 = c1_endRow->size[0];
        c1_i69 = c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i68,
          &c1_gc_emlrtBCI, c1_sp) - 1];
        c1_st.site = &c1_kb_emlrtRSI;
        c1_c_a = c1_i67;
        c1_k_b = c1_i69;
        c1_d_a = c1_c_a;
        c1_l_b = c1_k_b;
        if (c1_d_a > c1_l_b) {
          c1_f_overflow = false;
        } else {
          c1_f_overflow = (c1_l_b > 2147483646);
        }

        if (c1_f_overflow) {
          c1_b_st.site = &c1_t_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
        }

        for (c1_rowidx = c1_i67; c1_rowidx <= c1_i69; c1_rowidx++) {
          c1_i72 = c1_idxCount->size[0];
          c1_e_a = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_idx, 1,
            c1_i72, &c1_hc_emlrtBCI, c1_sp) - 1] + 1;
          c1_b_c = c1_e_a;
          c1_i73 = c1_idxCount->size[0];
          c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_idx, 1, c1_i73,
            &c1_ic_emlrtBCI, c1_sp) - 1] = c1_b_c;
          c1_i74 = c1_pixelIdxList->size[0];
          c1_i75 = c1_idxCount->size[0];
          c1_i76 = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_idx, 1,
            c1_i75, &c1_jc_emlrtBCI, c1_sp) - 1];
          c1_pixelIdxList->data[emlrtDynamicBoundsCheckR2012b(c1_i76, 1, c1_i74,
            &c1_jc_emlrtBCI, c1_sp) - 1] = (real_T)(c1_rowidx + c1_column_offset);
        }
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_idxCount);
    c1_emxFree_int32_T(chartInstance, &c1_labelsRenumbered);
    c1_CC->Connectivity = 8.0;
    for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
      c1_CC->ImageSize[c1_i62] = 120.0 + 40.0 * (real_T)c1_i62;
    }

    c1_CC->NumObjects = c1_numComponents;
    c1_i63 = c1_CC->RegionIndices->size[0];
    c1_CC->RegionIndices->size[0] = c1_pixelIdxList->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_CC->RegionIndices,
      c1_i63, &c1_v_emlrtRTEI);
    c1_e_loop_ub = c1_pixelIdxList->size[0] - 1;
    for (c1_i66 = 0; c1_i66 <= c1_e_loop_ub; c1_i66++) {
      c1_CC->RegionIndices->data[c1_i66] = c1_pixelIdxList->data[c1_i66];
    }

    c1_emxFree_real_T(chartInstance, &c1_pixelIdxList);
    c1_i70 = c1_CC->RegionLengths->size[0];
    c1_CC->RegionLengths->size[0] = c1_regionLengths->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_CC->RegionLengths,
      c1_i70, &c1_w_emlrtRTEI);
    c1_f_loop_ub = c1_regionLengths->size[0] - 1;
    for (c1_i71 = 0; c1_i71 <= c1_f_loop_ub; c1_i71++) {
      c1_CC->RegionLengths->data[c1_i71] = c1_regionLengths->data[c1_i71];
    }
  }

  c1_emxFree_int32_T(chartInstance, &c1_startCol);
  c1_emxFree_int32_T(chartInstance, &c1_endRow);
  c1_emxFree_int32_T(chartInstance, &c1_startRow);
  c1_emxFree_int32_T(chartInstance, &c1_regionLengths);
}

static void c1_assertValidSizeArg(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_varargin_1)
{
  real_T c1_arg;
  real_T c1_x;
  boolean_T c1_p;
  boolean_T c1_b;
  boolean_T c1_b_b;
  real_T c1_b_arg;
  boolean_T c1_b_p;
  const mxArray *c1_y = NULL;
  real_T c1_b_varargin_1;
  static char_T c1_b_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  const mxArray *c1_b_y = NULL;
  real_T c1_n;
  int32_T c1_u;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  static char_T c1_b_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T c1_b_u;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  (void)chartInstance;
  c1_arg = c1_varargin_1;
  if (c1_arg != c1_arg) {
    c1_p = false;
  } else {
    c1_x = c1_arg;
    c1_b = muDoubleScalarIsInf(c1_x);
    if (c1_b) {
      c1_p = false;
    } else {
      c1_p = true;
    }
  }

  if (c1_p) {
    c1_b_arg = c1_varargin_1;
    if (c1_b_arg > 2.147483647E+9) {
      c1_b_p = false;
    } else {
      c1_b_p = true;
    }

    if (c1_b_p) {
      c1_b_b = true;
    } else {
      c1_b_b = false;
    }
  } else {
    c1_b_b = false;
  }

  if (!c1_b_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c1_u = MIN_int32_T;
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
    c1_b_u = MAX_int32_T;
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call(c1_sp, "error", 0U, 2U, 14, c1_y, 14, sf_mex_call(c1_sp,
      "getString", 1U, 1U, 14, sf_mex_call(c1_sp, "message", 1U, 3U, 14, c1_b_y,
      14, c1_c_y, 14, c1_f_y)));
  }

  c1_b_varargin_1 = c1_varargin_1;
  if (c1_b_varargin_1 <= 0.0) {
    c1_n = 0.0;
  } else {
    c1_n = c1_b_varargin_1;
  }

  if (!(c1_n <= 2.147483647E+9)) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c1_sp, "error", 0U, 2U, 14, c1_d_y, 14, sf_mex_call(c1_sp,
      "getString", 1U, 1U, 14, sf_mex_call(c1_sp, "message", 1U, 1U, 14, c1_e_y)));
  }
}

static void c1_initializeStatsStruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_numObjs,
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed)
{
  emlrtStack c1_st;
  emlrtStack c1_b_st;
  c1_s9uuw2Xu7QLvohu1q5iD2hG c1_statsOneObj;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  c1_emxArray_boolean_T *c1_tile;
  real_T c1_varargin_1;
  int32_T c1_i5;
  int32_T c1_loop_ub;
  int32_T c1_i6;
  int32_T c1_outsize[2];
  const mxArray *c1_y = NULL;
  int32_T c1_i7;
  int32_T c1_b_loop_ub;
  int32_T c1_i8;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_emxInitStruct_s9uuw2Xu7QLvohu1q(chartInstance, c1_sp, &c1_statsOneObj,
    &c1_eb_emlrtRTEI);
  c1_statsAlreadyComputed->Area = false;
  c1_statsOneObj.Area = 0.0;
  c1_statsAlreadyComputed->Centroid = false;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_statsOneObj.Centroid[c1_i] = 0.0;
  }

  c1_statsAlreadyComputed->BoundingBox = false;
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_statsOneObj.BoundingBox[c1_i1] = 0.0;
  }

  c1_statsAlreadyComputed->MajorAxisLength = false;
  c1_statsOneObj.MajorAxisLength = 0.0;
  c1_statsAlreadyComputed->MinorAxisLength = false;
  c1_statsOneObj.MinorAxisLength = 0.0;
  c1_statsAlreadyComputed->Eccentricity = false;
  c1_statsOneObj.Eccentricity = 0.0;
  c1_statsAlreadyComputed->Orientation = false;
  c1_statsOneObj.Orientation = 0.0;
  c1_statsAlreadyComputed->Image = false;
  c1_statsOneObj.Image.size[0] = 0;
  c1_statsOneObj.Image.size[1] = 0;
  c1_statsAlreadyComputed->FilledImage = false;
  c1_statsOneObj.FilledImage.size[0] = 0;
  c1_statsOneObj.FilledImage.size[1] = 0;
  c1_statsAlreadyComputed->FilledArea = false;
  c1_statsOneObj.FilledArea = 0.0;
  c1_statsAlreadyComputed->EulerNumber = false;
  c1_statsOneObj.EulerNumber = 0.0;
  c1_statsAlreadyComputed->Extrema = false;
  for (c1_i2 = 0; c1_i2 < 16; c1_i2++) {
    c1_statsOneObj.Extrema[c1_i2] = 0.0;
  }

  c1_statsAlreadyComputed->EquivDiameter = false;
  c1_statsOneObj.EquivDiameter = 0.0;
  c1_statsAlreadyComputed->Extent = false;
  c1_statsOneObj.Extent = 0.0;
  c1_statsAlreadyComputed->PixelIdxList = false;
  c1_statsOneObj.PixelIdxList->size[0] = 0;
  c1_statsAlreadyComputed->PixelList = false;
  c1_statsOneObj.PixelList->size[0] = 0;
  c1_statsOneObj.PixelList->size[1] = 2;
  c1_statsAlreadyComputed->Perimeter = false;
  c1_statsOneObj.Perimeter = 0.0;
  c1_statsAlreadyComputed->Circularity = false;
  c1_statsOneObj.Circularity = 0.0;
  c1_statsAlreadyComputed->PixelValues = false;
  c1_statsOneObj.PixelValues.size[0] = 0;
  c1_statsAlreadyComputed->WeightedCentroid = false;
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_statsOneObj.WeightedCentroid[c1_i3] = 0.0;
  }

  c1_statsAlreadyComputed->MeanIntensity = false;
  c1_statsOneObj.MeanIntensity = 0.0;
  c1_statsAlreadyComputed->MinIntensity = false;
  c1_statsOneObj.MinIntensity = 0.0;
  c1_statsAlreadyComputed->MaxIntensity = false;
  c1_statsOneObj.MaxIntensity = 0.0;
  c1_statsAlreadyComputed->SubarrayIdx = false;
  c1_statsOneObj.SubarrayIdx.size[0] = 1;
  c1_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_statsOneObj.SubarrayIdxLengths[c1_i4] = 0.0;
  }

  c1_emxInit_boolean_T(chartInstance, c1_sp, &c1_tile, 1, &c1_g_emlrtRTEI);
  c1_st.site = &c1_cc_emlrtRSI;
  c1_varargin_1 = c1_numObjs;
  c1_b_st.site = &c1_dc_emlrtRSI;
  c1_assertValidSizeArg(chartInstance, &c1_b_st, c1_varargin_1);
  c1_i5 = c1_tile->size[0];
  c1_tile->size[0] = (int32_T)c1_varargin_1;
  c1_emxEnsureCapacity_boolean_T(chartInstance, &c1_st, c1_tile, c1_i5,
    &c1_g_emlrtRTEI);
  c1_loop_ub = (int32_T)c1_varargin_1 - 1;
  for (c1_i6 = 0; c1_i6 <= c1_loop_ub; c1_i6++) {
    c1_tile->data[c1_i6] = false;
  }

  c1_outsize[0] = c1_tile->size[0];
  if (!((real_T)c1_outsize[0] == (real_T)c1_tile->size[0])) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c1_st, "error", 0U, 1U, 14, c1_y);
  }

  c1_emxFree_boolean_T(chartInstance, &c1_tile);
  c1_i7 = c1_stats->size[0];
  c1_stats->size[0] = c1_outsize[0];
  c1_emxEnsureCapacity_s9uuw2Xu7QLvo(chartInstance, &c1_st, c1_stats, c1_i7,
    &c1_h_emlrtRTEI);
  c1_b_loop_ub = c1_outsize[0] - 1;
  for (c1_i8 = 0; c1_i8 <= c1_b_loop_ub; c1_i8++) {
    c1_emxCopyStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c1_st, &c1_stats->
      data[c1_i8], &c1_statsOneObj, &c1_h_emlrtRTEI);
  }

  c1_emxFreeStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c1_statsOneObj);
}

static void c1_ComputePixelIdxList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE c1_CC,
  real_T c1_numObjs, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed,
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_b_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_b_statsAlreadyComputed)
{
  c1_scIvRXQeSh8yxCxSmtD63bE c1_b_CC;
  int32_T c1_i;
  int32_T c1_loop_ub;
  int32_T c1_i1;
  c1_emxInitStruct_scIvRXQeSh8yxCxSm(chartInstance, c1_sp, &c1_b_CC,
    &c1_fb_emlrtRTEI);
  c1_i = c1_b_stats->size[0];
  c1_b_stats->size[0] = c1_stats->size[0];
  c1_emxEnsureCapacity_s9uuw2Xu7QLvo(chartInstance, c1_sp, c1_b_stats, c1_i,
    &c1_fb_emlrtRTEI);
  c1_loop_ub = c1_stats->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_emxCopyStruct_s9uuw2Xu7QLvohu1q(chartInstance, c1_sp, &c1_b_stats->
      data[c1_i1], &c1_stats->data[c1_i1], &c1_fb_emlrtRTEI);
  }

  *c1_b_statsAlreadyComputed = c1_statsAlreadyComputed;
  c1_emxCopyStruct_scIvRXQeSh8yxCxSm(chartInstance, c1_sp, &c1_b_CC, &c1_CC,
    &c1_fb_emlrtRTEI);
  c1_b_ComputePixelIdxList(chartInstance, c1_sp, c1_b_CC, c1_numObjs, c1_b_stats,
    c1_b_statsAlreadyComputed);
  c1_emxFreeStruct_scIvRXQeSh8yxCxSm(chartInstance, &c1_b_CC);
}

static void c1_ComputePixelList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h
  *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed,
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_b_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_b_statsAlreadyComputed)
{
  int32_T c1_i;
  int32_T c1_loop_ub;
  int32_T c1_i1;
  c1_i = c1_b_stats->size[0];
  c1_b_stats->size[0] = c1_stats->size[0];
  c1_emxEnsureCapacity_s9uuw2Xu7QLvo(chartInstance, c1_sp, c1_b_stats, c1_i,
    &c1_gb_emlrtRTEI);
  c1_loop_ub = c1_stats->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_emxCopyStruct_s9uuw2Xu7QLvohu1q(chartInstance, c1_sp, &c1_b_stats->
      data[c1_i1], &c1_stats->data[c1_i1], &c1_gb_emlrtRTEI);
  }

  *c1_b_statsAlreadyComputed = c1_statsAlreadyComputed;
  c1_b_ComputePixelList(chartInstance, c1_sp, c1_b_stats,
                        c1_b_statsAlreadyComputed);
}

static boolean_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_IsFireFound, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_IsFireFound),
    &c1_thisId);
  sf_mex_destroy(&c1_b_IsFireFound);
  return c1_y;
}

static boolean_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_flightControlSystem), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_flightControlSystem);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_b_u;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_chart_data_browse_helper
  (SFc1_flightControlSystemInstanceStruct *chartInstance, int32_T c1_ssIdNumber)
{
  const mxArray *c1_mxData = NULL;
  boolean_T c1_b;
  c1_mxData = NULL;
  switch (c1_ssIdNumber) {
   case 4U:
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", *chartInstance->c1_b_red,
      3, 0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 7U:
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", *chartInstance->c1_b_green,
      3, 0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    c1_b = *chartInstance->c1_IsFireFound;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_b, 11, 0U, 0U, 0U, 0),
                  false);
    break;

   case 6U:
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", *chartInstance->c1_blue, 3,
      0U, 1U, 0U, 2, 120, 160), false);
    break;
  }

  return c1_mxData;
}

static void c1_b_ComputePixelIdxList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE c1_CC,
  real_T c1_numObjs, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 *c1_statsAlreadyComputed)
{
  emlrtStack c1_st;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_g_st;
  emlrtStack c1_h_st;
  c1_emxArray_real_T *c1_regionIndices;
  int32_T c1_i;
  int32_T c1_loop_ub;
  int32_T c1_i1;
  c1_emxArray_int32_T *c1_regionLengths;
  int32_T c1_i2;
  int32_T c1_b_loop_ub;
  int32_T c1_i3;
  int32_T c1_dim;
  int32_T c1_varargin_3;
  c1_emxArray_int32_T *c1_idxCount;
  int32_T c1_i4;
  int32_T c1_varargin_1;
  int32_T c1_b_varargin_1;
  real_T c1_n;
  int32_T c1_c_loop_ub;
  int32_T c1_nx;
  int32_T c1_i5;
  int32_T c1_i6;
  real_T c1_d;
  int32_T c1_b;
  int32_T c1_i7;
  int32_T c1_b_b;
  int32_T c1_k;
  boolean_T c1_overflow;
  real_T c1_b_k;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_c_k;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_d_k;
  int32_T c1_i13;
  boolean_T c1_c_b;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_d_loop_ub;
  int32_T c1_i22;
  int32_T c1_i23;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_g_st.prev = &c1_f_st;
  c1_g_st.tls = c1_f_st.tls;
  c1_h_st.prev = &c1_g_st;
  c1_h_st.tls = c1_g_st.tls;
  c1_statsAlreadyComputed->PixelIdxList = true;
  if (c1_numObjs != 0.0) {
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_regionIndices, 1,
                      &c1_mb_emlrtRTEI);
    c1_i = c1_regionIndices->size[0];
    c1_regionIndices->size[0] = c1_CC.RegionIndices->size[0];
    c1_st.site = &c1_md_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_regionIndices, c1_i,
      &c1_hb_emlrtRTEI);
    c1_loop_ub = c1_CC.RegionIndices->size[0] - 1;
    for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
      c1_regionIndices->data[c1_i1] = c1_CC.RegionIndices->data[c1_i1];
    }

    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_regionLengths, 1,
                       &c1_lb_emlrtRTEI);
    c1_i2 = c1_regionLengths->size[0];
    c1_regionLengths->size[0] = c1_CC.RegionLengths->size[0];
    c1_st.site = &c1_nd_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_regionLengths, c1_i2,
      &c1_ib_emlrtRTEI);
    c1_b_loop_ub = c1_CC.RegionLengths->size[0] - 1;
    for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
      c1_regionLengths->data[c1_i3] = c1_CC.RegionLengths->data[c1_i3];
    }

    c1_st.site = &c1_ec_emlrtRSI;
    c1_b_st.site = &c1_ub_emlrtRSI;
    c1_dim = 2;
    if ((real_T)c1_regionLengths->size[0] != 1.0) {
      c1_dim = 1;
    }

    c1_c_st.site = &c1_vb_emlrtRSI;
    c1_varargin_3 = c1_dim;
    if (1 == c1_varargin_3) {
      c1_d_st.site = &c1_wb_emlrtRSI;
      c1_e_st.site = &c1_xb_emlrtRSI;
      if (c1_regionLengths->size[0] != 0) {
        c1_f_st.site = &c1_yb_emlrtRSI;
        c1_varargin_1 = c1_regionLengths->size[0];
        c1_b_varargin_1 = c1_varargin_1;
        c1_n = (real_T)c1_b_varargin_1;
        c1_nx = (int32_T)c1_n - 1;
        if (!((real_T)c1_regionLengths->size[0] == 1.0)) {
          c1_i6 = c1_nx;
          c1_g_st.site = &c1_ac_emlrtRSI;
          c1_b = c1_i6;
          c1_b_b = c1_b;
          if (1 > c1_b_b) {
            c1_overflow = false;
          } else {
            c1_overflow = (c1_b_b > 2147483646);
          }

          if (c1_overflow) {
            c1_h_st.site = &c1_t_emlrtRSI;
            c1_check_forloop_overflow_error(chartInstance, &c1_h_st);
          }

          for (c1_c_k = 1; c1_c_k - 1 < c1_i6; c1_c_k++) {
            c1_d_k = c1_c_k;
            c1_regionLengths->data[c1_d_k] += c1_regionLengths->data[c1_d_k - 1];
          }
        }
      }
    }

    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_idxCount, 1,
                       &c1_nb_emlrtRTEI);
    c1_i4 = c1_idxCount->size[0];
    c1_idxCount->size[0] = 1 + c1_regionLengths->size[0];
    c1_st.site = &c1_ec_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_idxCount, c1_i4,
      &c1_jb_emlrtRTEI);
    c1_idxCount->data[0] = 0;
    c1_c_loop_ub = c1_regionLengths->size[0] - 1;
    for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
      c1_idxCount->data[c1_i5 + 1] = c1_regionLengths->data[c1_i5];
    }

    c1_emxFree_int32_T(chartInstance, &c1_regionLengths);
    c1_d = (real_T)c1_stats->size[0];
    c1_i7 = (int32_T)c1_d - 1;
    for (c1_k = 0; c1_k <= c1_i7; c1_k++) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_i8 = c1_idxCount->size[0];
      c1_i9 = (int32_T)c1_b_k;
      c1_i10 = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_i9, 1, c1_i8,
        &c1_kc_emlrtBCI, c1_sp) - 1] + 1;
      c1_i11 = c1_idxCount->size[0];
      c1_i12 = (int32_T)(c1_b_k + 1.0);
      c1_i13 = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_i12, 1, c1_i11,
        &c1_lc_emlrtBCI, c1_sp) - 1];
      c1_c_b = (c1_i10 > c1_i13);
      if (c1_c_b) {
        c1_i15 = 0;
        c1_i16 = -1;
      } else {
        c1_i14 = c1_regionIndices->size[0];
        c1_i15 = emlrtDynamicBoundsCheckR2012b(c1_i10, 1, c1_i14,
          &c1_kc_emlrtBCI, c1_sp) - 1;
        c1_i17 = c1_regionIndices->size[0];
        c1_i16 = emlrtDynamicBoundsCheckR2012b(c1_i13, 1, c1_i17,
          &c1_lc_emlrtBCI, c1_sp) - 1;
      }

      c1_i18 = c1_stats->size[0];
      c1_i19 = (int32_T)c1_b_k;
      c1_i20 = emlrtDynamicBoundsCheckR2012b(c1_i19, 1, c1_i18, &c1_mc_emlrtBCI,
        c1_sp) - 1;
      c1_i21 = c1_stats->data[c1_i20].PixelIdxList->size[0];
      c1_stats->data[c1_i20].PixelIdxList->size[0] = (c1_i16 - c1_i15) + 1;
      c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_stats->data[c1_i20].
        PixelIdxList, c1_i21, &c1_kb_emlrtRTEI);
      c1_d_loop_ub = c1_i16 - c1_i15;
      for (c1_i22 = 0; c1_i22 <= c1_d_loop_ub; c1_i22++) {
        c1_i23 = (int32_T)c1_b_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i23, 1, c1_i18,
          &c1_mc_emlrtBCI, c1_sp) - 1].PixelIdxList->data[c1_i22] =
          c1_regionIndices->data[c1_i15 + c1_i22];
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_idxCount);
    c1_emxFree_real_T(chartInstance, &c1_regionIndices);
  }
}

static void c1_b_ComputePixelList(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h
  *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2 *c1_statsAlreadyComputed)
{
  emlrtStack c1_st;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  int32_T c1_varargin_1;
  int32_T c1_b_varargin_1;
  real_T c1_d;
  int32_T c1_i;
  int32_T c1_k;
  c1_emxArray_real_T *c1_j;
  c1_emxArray_real_T *c1_ndx;
  c1_emxArray_int32_T *c1_varargout_4;
  c1_emxArray_int32_T *c1_idx;
  c1_emxArray_int32_T *c1_vk;
  c1_cell_wrap_17 c1_reshapes[2];
  real_T c1_b_k;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_loop_ub;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_b_loop_ub;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_c_loop_ub;
  int32_T c1_i28;
  real_T c1_d1;
  int32_T c1_i29;
  int32_T c1_c_k;
  int32_T c1_exitg1;
  boolean_T c1_p;
  real_T c1_d_k;
  boolean_T c1_b;
  const mxArray *c1_y = NULL;
  int32_T c1_i30;
  static char_T c1_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 'd', '2', 's', 'u', 'b', '_', 'I', 'n', 'd', 'e',
    'x', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  const mxArray *c1_b_y = NULL;
  int32_T c1_d_loop_ub;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_e_loop_ub;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_f_loop_ub;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_g_loop_ub;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_h_loop_ub;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i_loop_ub;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_j_loop_ub;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_k_loop_ub;
  int32_T c1_i45;
  int32_T c1_result;
  int32_T c1_sizes[2];
  int32_T c1_expected;
  boolean_T c1_b1;
  const mxArray *c1_c_y = NULL;
  static char_T c1_b_cv1[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    't', 'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i',
    'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i46;
  const mxArray *c1_f_y = NULL;
  int32_T c1_l_loop_ub;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_m_loop_ub;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_n_loop_ub;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_o_loop_ub;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_p_loop_ub;
  int32_T c1_i60;
  int32_T c1_q_loop_ub;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  if (!c1_statsAlreadyComputed->PixelList) {
    c1_statsAlreadyComputed->PixelList = true;
    c1_varargin_1 = c1_stats->size[0];
    c1_b_varargin_1 = c1_varargin_1;
    c1_d = (real_T)c1_b_varargin_1;
    c1_i = (int32_T)c1_d - 1;
    c1_k = 0;
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_j, 1, &c1_cc_emlrtRTEI);
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_ndx, 1, &c1_pb_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_varargout_4, 1,
                       &c1_gb_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_idx, 1, &c1_qb_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_vk, 1, &c1_sb_emlrtRTEI);
    c1_emxInitMatrix_cell_wrap_17(chartInstance, c1_sp, c1_reshapes,
      &c1_dc_emlrtRTEI);
    while (c1_k <= c1_i) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_i1 = c1_ndx->size[0];
      c1_i2 = c1_stats->size[0];
      c1_i3 = (int32_T)c1_b_k;
      c1_ndx->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i3, 1,
        c1_i2, &c1_pc_emlrtBCI, c1_sp) - 1].PixelIdxList->size[0];
      c1_st.site = &c1_ld_emlrtRSI;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_ndx, c1_i1,
        &c1_ob_emlrtRTEI);
      c1_i4 = c1_stats->size[0];
      c1_i5 = (int32_T)c1_b_k;
      c1_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i5, 1, c1_i4,
        &c1_pc_emlrtBCI, c1_sp) - 1].PixelIdxList->size[0] - 1;
      for (c1_i6 = 0; c1_i6 <= c1_loop_ub; c1_i6++) {
        c1_i7 = c1_stats->size[0];
        c1_i9 = (int32_T)c1_b_k;
        c1_ndx->data[c1_i6] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i9,
          1, c1_i7, &c1_pc_emlrtBCI, c1_sp) - 1].PixelIdxList->data[c1_i6];
      }

      if (c1_ndx->size[0] != 0) {
        c1_st.site = &c1_hc_emlrtRSI;
        c1_i11 = c1_ndx->size[0];
        c1_i13 = c1_stats->size[0];
        c1_i14 = (int32_T)c1_b_k;
        c1_ndx->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i14, 1,
          c1_i13, &c1_qc_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0];
        c1_b_st.site = &c1_hc_emlrtRSI;
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_ndx, c1_i11,
          &c1_pb_emlrtRTEI);
        c1_i18 = c1_stats->size[0];
        c1_i20 = (int32_T)c1_b_k;
        c1_b_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i20, 1,
          c1_i18, &c1_qc_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0] - 1;
        for (c1_i22 = 0; c1_i22 <= c1_b_loop_ub; c1_i22++) {
          c1_i25 = c1_stats->size[0];
          c1_i27 = (int32_T)c1_b_k;
          c1_ndx->data[c1_i22] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
            (c1_i27, 1, c1_i25, &c1_qc_emlrtBCI, &c1_st) - 1].PixelIdxList->
            data[c1_i22];
        }

        c1_b_st.site = &c1_jc_emlrtRSI;
        c1_i26 = c1_idx->size[0];
        c1_idx->size[0] = c1_ndx->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_idx, c1_i26,
          &c1_qb_emlrtRTEI);
        c1_c_loop_ub = c1_ndx->size[0] - 1;
        for (c1_i28 = 0; c1_i28 <= c1_c_loop_ub; c1_i28++) {
          c1_idx->data[c1_i28] = (int32_T)c1_ndx->data[c1_i28];
        }

        c1_d1 = (real_T)c1_idx->size[0];
        c1_i29 = (int32_T)c1_d1 - 1;
        c1_c_k = 0;
        do {
          c1_exitg1 = 0;
          if (c1_c_k <= c1_i29) {
            c1_d_k = (real_T)c1_c_k + 1.0;
            if ((real_T)c1_idx->data[(int32_T)c1_d_k - 1] >= 1.0) {
              c1_b = true;
            } else {
              c1_b = false;
            }

            if (!c1_b) {
              c1_p = false;
              c1_exitg1 = 1;
            } else {
              c1_c_k++;
            }
          } else {
            c1_p = true;
            c1_exitg1 = 1;
          }
        } while (c1_exitg1 == 0);

        if (!c1_p) {
          c1_y = NULL;
          sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
            36), false);
          c1_b_y = NULL;
          sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2,
            1, 36), false);
          sf_mex_call(&c1_b_st, "error", 0U, 2U, 14, c1_y, 14, sf_mex_call
                      (&c1_b_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_b_st,
            "message", 1U, 1U, 14, c1_b_y)));
        }

        c1_i30 = c1_idx->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_idx, c1_i30,
          &c1_rb_emlrtRTEI);
        c1_d_loop_ub = c1_idx->size[0] - 1;
        for (c1_i31 = 0; c1_i31 <= c1_d_loop_ub; c1_i31++) {
          c1_idx->data[c1_i31]--;
        }

        c1_i32 = c1_vk->size[0];
        c1_vk->size[0] = c1_idx->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_vk, c1_i32,
          &c1_sb_emlrtRTEI);
        c1_e_loop_ub = c1_idx->size[0] - 1;
        for (c1_i33 = 0; c1_i33 <= c1_e_loop_ub; c1_i33++) {
          c1_vk->data[c1_i33] = c1_div_nzp_s32(chartInstance, c1_idx->
            data[c1_i33], 120, 0, 1U, 0, 0);
        }

        c1_i34 = c1_varargout_4->size[0];
        c1_varargout_4->size[0] = c1_vk->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_varargout_4,
          c1_i34, &c1_tb_emlrtRTEI);
        c1_f_loop_ub = c1_vk->size[0] - 1;
        for (c1_i35 = 0; c1_i35 <= c1_f_loop_ub; c1_i35++) {
          c1_varargout_4->data[c1_i35] = c1_vk->data[c1_i35] + 1;
        }

        c1_i36 = c1_vk->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_vk, c1_i36,
          &c1_ub_emlrtRTEI);
        c1_g_loop_ub = c1_vk->size[0] - 1;
        for (c1_i37 = 0; c1_i37 <= c1_g_loop_ub; c1_i37++) {
          c1_vk->data[c1_i37] *= 120;
        }

        c1_i38 = c1_idx->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_idx, c1_i38,
          &c1_vb_emlrtRTEI);
        c1_h_loop_ub = c1_idx->size[0] - 1;
        for (c1_i39 = 0; c1_i39 <= c1_h_loop_ub; c1_i39++) {
          c1_idx->data[c1_i39] -= c1_vk->data[c1_i39];
        }

        c1_i40 = c1_idx->size[0];
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_idx, c1_i40,
          &c1_wb_emlrtRTEI);
        c1_i_loop_ub = c1_idx->size[0] - 1;
        for (c1_i41 = 0; c1_i41 <= c1_i_loop_ub; c1_i41++) {
          c1_idx->data[c1_i41]++;
        }

        c1_i42 = c1_ndx->size[0];
        c1_ndx->size[0] = c1_idx->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_ndx, c1_i42,
          &c1_xb_emlrtRTEI);
        c1_j_loop_ub = c1_idx->size[0] - 1;
        for (c1_i43 = 0; c1_i43 <= c1_j_loop_ub; c1_i43++) {
          c1_ndx->data[c1_i43] = (real_T)c1_idx->data[c1_i43];
        }

        c1_i44 = c1_j->size[0];
        c1_j->size[0] = c1_varargout_4->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_j, c1_i44,
          &c1_xb_emlrtRTEI);
        c1_k_loop_ub = c1_varargout_4->size[0] - 1;
        for (c1_i45 = 0; c1_i45 <= c1_k_loop_ub; c1_i45++) {
          c1_j->data[c1_i45] = (real_T)c1_varargout_4->data[c1_i45];
        }

        c1_st.site = &c1_ic_emlrtRSI;
        c1_b_st.site = &c1_kc_emlrtRSI;
        c1_result = c1_j->size[0];
        c1_sizes[0] = c1_result;
        c1_c_st.site = &c1_lc_emlrtRSI;
        c1_expected = c1_sizes[0];
        if (c1_j->size[0] == c1_expected) {
          c1_b1 = true;
        } else {
          c1_b1 = false;
        }

        if (!c1_b1) {
          c1_c_y = NULL;
          sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2,
            1, 39), false);
          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2,
            1, 39), false);
          sf_mex_call(&c1_c_st, "error", 0U, 2U, 14, c1_c_y, 14, sf_mex_call
                      (&c1_c_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_c_st,
            "message", 1U, 1U, 14, c1_d_y)));
        }

        if (c1_ndx->size[0] == c1_expected) {
          c1_b1 = true;
        } else {
          c1_b1 = false;
        }

        if (!c1_b1) {
          c1_e_y = NULL;
          sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2,
            1, 39), false);
          c1_f_y = NULL;
          sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2,
            1, 39), false);
          sf_mex_call(&c1_c_st, "error", 0U, 2U, 14, c1_e_y, 14, sf_mex_call
                      (&c1_c_st, "getString", 1U, 1U, 14, sf_mex_call(&c1_c_st,
            "message", 1U, 1U, 14, c1_f_y)));
        }

        c1_i46 = c1_reshapes[0].f1->size[0];
        c1_reshapes[0].f1->size[0] = c1_j->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_reshapes[0].f1,
          c1_i46, &c1_yb_emlrtRTEI);
        c1_l_loop_ub = c1_j->size[0] - 1;
        for (c1_i47 = 0; c1_i47 <= c1_l_loop_ub; c1_i47++) {
          c1_reshapes[0].f1->data[c1_i47] = c1_j->data[c1_i47];
        }

        c1_i48 = c1_reshapes[1].f1->size[0];
        c1_reshapes[1].f1->size[0] = c1_ndx->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_reshapes[1].f1,
          c1_i48, &c1_yb_emlrtRTEI);
        c1_m_loop_ub = c1_ndx->size[0] - 1;
        for (c1_i49 = 0; c1_i49 <= c1_m_loop_ub; c1_i49++) {
          c1_reshapes[1].f1->data[c1_i49] = c1_ndx->data[c1_i49];
        }

        c1_i50 = c1_ndx->size[0];
        c1_ndx->size[0] = c1_reshapes[0].f1->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_ndx, c1_i50,
          &c1_ac_emlrtRTEI);
        c1_n_loop_ub = c1_reshapes[0].f1->size[0] - 1;
        for (c1_i51 = 0; c1_i51 <= c1_n_loop_ub; c1_i51++) {
          c1_ndx->data[c1_i51] = c1_reshapes[0].f1->data[c1_i51];
        }

        c1_i52 = c1_j->size[0];
        c1_j->size[0] = c1_reshapes[1].f1->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_j, c1_i52,
          &c1_ac_emlrtRTEI);
        c1_o_loop_ub = c1_reshapes[1].f1->size[0] - 1;
        for (c1_i53 = 0; c1_i53 <= c1_o_loop_ub; c1_i53++) {
          c1_j->data[c1_i53] = c1_reshapes[1].f1->data[c1_i53];
        }

        c1_i54 = c1_stats->size[0];
        c1_i55 = (int32_T)c1_b_k;
        c1_i56 = emlrtDynamicBoundsCheckR2012b(c1_i55, 1, c1_i54,
          &c1_oc_emlrtBCI, &c1_b_st) - 1;
        c1_i57 = c1_stats->data[c1_i56].PixelList->size[0] * c1_stats->
          data[c1_i56].PixelList->size[1];
        c1_stats->data[c1_i56].PixelList->size[0] = c1_ndx->size[0];
        c1_i58 = (int32_T)c1_b_k;
        c1_i59 = emlrtDynamicBoundsCheckR2012b(c1_i58, 1, c1_i54,
          &c1_oc_emlrtBCI, &c1_b_st) - 1;
        c1_stats->data[c1_i59].PixelList->size[1] = 2;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_stats->
          data[c1_i59].PixelList, c1_i57, &c1_bc_emlrtRTEI);
        c1_p_loop_ub = c1_ndx->size[0] - 1;
        for (c1_i60 = 0; c1_i60 <= c1_p_loop_ub; c1_i60++) {
          c1_i61 = (int32_T)c1_b_k;
          c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i61, 1, c1_i54,
            &c1_oc_emlrtBCI, &c1_b_st) - 1].PixelList->data[c1_i60] =
            c1_ndx->data[c1_i60];
        }

        c1_q_loop_ub = c1_j->size[0] - 1;
        for (c1_i62 = 0; c1_i62 <= c1_q_loop_ub; c1_i62++) {
          c1_i63 = (int32_T)c1_b_k;
          c1_i64 = (int32_T)c1_b_k;
          c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i63, 1, c1_i54,
            &c1_oc_emlrtBCI, &c1_b_st) - 1].PixelList->data[c1_i62 +
            c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i64, 1, c1_i54,
            &c1_oc_emlrtBCI, &c1_b_st) - 1].PixelList->size[0]] = c1_j->
            data[c1_i62];
        }
      } else {
        c1_i8 = c1_stats->size[0];
        c1_i10 = (int32_T)c1_b_k;
        c1_i12 = emlrtDynamicBoundsCheckR2012b(c1_i10, 1, c1_i8, &c1_nc_emlrtBCI,
          c1_sp) - 1;
        c1_stats->data[c1_i12].PixelList->size[0] = 0;
        c1_i15 = c1_stats->size[0];
        c1_i16 = (int32_T)c1_b_k;
        c1_i17 = emlrtDynamicBoundsCheckR2012b(c1_i16, 1, c1_i15,
          &c1_nc_emlrtBCI, c1_sp) - 1;
        c1_stats->data[c1_i17].PixelList->size[1] = 2;
        c1_i19 = c1_stats->size[0];
        c1_i21 = (int32_T)c1_b_k;
        emlrtDynamicBoundsCheckR2012b(c1_i21, 1, c1_i19, &c1_nc_emlrtBCI, c1_sp);
        c1_i23 = c1_stats->size[0];
        c1_i24 = (int32_T)c1_b_k;
        emlrtDynamicBoundsCheckR2012b(c1_i24, 1, c1_i23, &c1_nc_emlrtBCI, c1_sp);
      }

      c1_k++;
    }

    c1_emxFreeMatrix_cell_wrap_17(chartInstance, c1_reshapes);
    c1_emxFree_int32_T(chartInstance, &c1_vk);
    c1_emxFree_int32_T(chartInstance, &c1_idx);
    c1_emxFree_int32_T(chartInstance, &c1_varargout_4);
    c1_emxFree_real_T(chartInstance, &c1_ndx);
    c1_emxFree_real_T(chartInstance, &c1_j);
  }
}

static void c1_emxEnsureCapacity_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(real_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_sKyE5zvueAoQJ4jaLWfzLx
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *)emlrtMallocMex(sizeof
    (c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (c1_sKyE5zvueAoQJ4jaLWfzLx *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_real_T *)emlrtMallocMex(sizeof(c1_emxArray_real_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_sKyE5zvueAoQJ4jaLWfzLx
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *)NULL) {
    if (((*c1_pEmxArray)->data != (c1_sKyE5zvueAoQJ4jaLWfzLx *)NULL) &&
        (*c1_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *)NULL;
  }
}

static void c1_emxFree_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_real_T *)NULL) {
    if (((*c1_pEmxArray)->data != (real_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_real_T *)NULL;
  }
}

static void c1_emxEnsureCapacity_boolean_T
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(boolean_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (boolean_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_sKyE5zvueAoQJ
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sKyE5zvueAoQJ4jaLWfzLx *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof
      (c1_sKyE5zvueAoQJ4jaLWfzLx));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(c1_sKyE5zvueAoQJ4jaLWfzLx) *
             (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (c1_sKyE5zvueAoQJ4jaLWfzLx *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_real_T1(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(real_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInitStruct_scIvRXQeSh8yxCxSm
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation)
{
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_pStruct->RegionIndices, 1,
                    c1_srcLocation);
  c1_emxInit_int32_T(chartInstance, c1_sp, &c1_pStruct->RegionLengths, 1,
                     c1_srcLocation);
}

static void c1_emxInit_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_int32_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_int32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (int32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *)emlrtMallocMex(sizeof
    (c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (c1_s9uuw2Xu7QLvohu1q5iD2hG *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_real_T *)emlrtMallocMex(sizeof(c1_emxArray_real_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_boolean_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_boolean_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c1_emxArray_boolean_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (boolean_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFreeStruct_scIvRXQeSh8yxCxSm
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_scIvRXQeSh8yxCxSmtD63bE *c1_pStruct)
{
  c1_emxFree_real_T(chartInstance, &c1_pStruct->RegionIndices);
  c1_emxFree_int32_T(chartInstance, &c1_pStruct->RegionLengths);
}

static void c1_emxFree_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_int32_T *)NULL) {
    if (((*c1_pEmxArray)->data != (int32_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_int32_T *)NULL;
  }
}

static void c1_emxFree_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c1_pEmxArray)
{
  int32_T c1_numEl;
  int32_T c1_i;
  int32_T c1_b_i;
  if (*c1_pEmxArray != (c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *)NULL) {
    if ((*c1_pEmxArray)->data != (c1_s9uuw2Xu7QLvohu1q5iD2hG *)NULL) {
      c1_numEl = 1;
      for (c1_i = 0; c1_i < (*c1_pEmxArray)->numDimensions; c1_i++) {
        c1_numEl *= (*c1_pEmxArray)->size[c1_i];
      }

      for (c1_b_i = 0; c1_b_i < c1_numEl; c1_b_i++) {
        c1_emxFreeStruct_s9uuw2Xu7QLvohu1q(chartInstance, &(*c1_pEmxArray)->
          data[c1_b_i]);
      }

      if ((*c1_pEmxArray)->canFreeData) {
        emlrtFreeMex((*c1_pEmxArray)->data);
      }
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *)NULL;
  }
}

static void c1_emxFreeStruct_s9uuw2Xu7QLvohu1q
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s9uuw2Xu7QLvohu1q5iD2hG *c1_pStruct)
{
  c1_emxFree_real_T(chartInstance, &c1_pStruct->PixelIdxList);
  c1_emxFree_real_T(chartInstance, &c1_pStruct->PixelList);
}

static void c1_emxFree_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_boolean_T *)NULL) {
    if (((*c1_pEmxArray)->data != (boolean_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_boolean_T *)NULL;
  }
}

static void c1_emxEnsureCapacity_int32_T(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(int32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(int32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (int32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxTrim_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex)
{
  int32_T c1_i;
  for (c1_i = c1_fromIndex; c1_i < c1_toIndex; c1_i++) {
    c1_emxFreeStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c1_emxArray->data[c1_i]);
  }
}

static void c1_emxInitStruct_s9uuw2Xu7QLvohu1q
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s9uuw2Xu7QLvohu1q5iD2hG *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation)
{
  c1_pStruct->Image.size[0] = 0;
  c1_pStruct->Image.size[1] = 0;
  c1_pStruct->FilledImage.size[0] = 0;
  c1_pStruct->FilledImage.size[1] = 0;
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_pStruct->PixelIdxList, 1,
                    c1_srcLocation);
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_pStruct->PixelList, 2,
                     c1_srcLocation);
  c1_pStruct->PixelValues.size[0] = 0;
  c1_pStruct->SubarrayIdx.size[0] = 0;
  c1_pStruct->SubarrayIdx.size[1] = 0;
}

static void c1_emxExpand_s9uuw2Xu7QLvohu1q5iD2
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  for (c1_i = c1_fromIndex; c1_i < c1_toIndex; c1_i++) {
    c1_emxInitStruct_s9uuw2Xu7QLvohu1q(chartInstance, c1_sp, &c1_emxArray->
      data[c1_i], c1_srcLocation);
  }
}

static void c1_emxEnsureCapacity_s9uuw2Xu7QLvo
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof
      (c1_s9uuw2Xu7QLvohu1q5iD2hG));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(c1_s9uuw2Xu7QLvohu1q5iD2hG) *
             (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (c1_s9uuw2Xu7QLvohu1q5iD2hG *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }

  if (c1_oldNumel > c1_newNumel) {
    c1_emxTrim_s9uuw2Xu7QLvohu1q5iD2hG(chartInstance, c1_emxArray, c1_newNumel,
      c1_oldNumel);
  } else {
    if (c1_oldNumel < c1_newNumel) {
      c1_emxExpand_s9uuw2Xu7QLvohu1q5iD2(chartInstance, c1_sp, c1_emxArray,
        c1_oldNumel, c1_newNumel, c1_srcLocation);
    }
  }
}

static void c1_emxCopyStruct_s9uuw2Xu7QLvohu1q
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s9uuw2Xu7QLvohu1q5iD2hG *c1_dst, const c1_s9uuw2Xu7QLvohu1q5iD2hG *
   c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_dst->Area = c1_src->Area;
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->Centroid, c1_src->Centroid);
  c1_emxCopyMatrix_real_T1(chartInstance, c1_dst->BoundingBox,
    c1_src->BoundingBox);
  c1_dst->MajorAxisLength = c1_src->MajorAxisLength;
  c1_dst->MinorAxisLength = c1_src->MinorAxisLength;
  c1_dst->Eccentricity = c1_src->Eccentricity;
  c1_dst->Orientation = c1_src->Orientation;
  c1_emxCopy_boolean_T_0x0(chartInstance, &c1_dst->Image, &c1_src->Image);
  c1_emxCopy_boolean_T_0x0(chartInstance, &c1_dst->FilledImage,
    &c1_src->FilledImage);
  c1_dst->FilledArea = c1_src->FilledArea;
  c1_dst->EulerNumber = c1_src->EulerNumber;
  c1_emxCopyMatrix_real_T2(chartInstance, c1_dst->Extrema, c1_src->Extrema);
  c1_dst->EquivDiameter = c1_src->EquivDiameter;
  c1_dst->Extent = c1_src->Extent;
  c1_emxCopy_real_T(chartInstance, c1_sp, &c1_dst->PixelIdxList,
                    &c1_src->PixelIdxList, c1_srcLocation);
  c1_emxCopy_real_T1(chartInstance, c1_sp, &c1_dst->PixelList,
                     &c1_src->PixelList, c1_srcLocation);
  c1_dst->Perimeter = c1_src->Perimeter;
  c1_dst->Circularity = c1_src->Circularity;
  c1_emxCopy_real_T_0(chartInstance, &c1_dst->PixelValues, &c1_src->PixelValues);
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->WeightedCentroid,
    c1_src->WeightedCentroid);
  c1_dst->MeanIntensity = c1_src->MeanIntensity;
  c1_dst->MinIntensity = c1_src->MinIntensity;
  c1_dst->MaxIntensity = c1_src->MaxIntensity;
  c1_emxCopy_real_T_1x0(chartInstance, &c1_dst->SubarrayIdx,
                        &c1_src->SubarrayIdx);
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->SubarrayIdxLengths,
    c1_src->SubarrayIdxLengths);
}

static void c1_emxCopyMatrix_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[2], const real_T c1_src[2])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_emxCopyMatrix_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[4], const real_T c1_src[4])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 4; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_emxCopy_boolean_T_0x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T_0x0 *c1_dst, const
  c1_emxArray_boolean_T_0x0 *c1_src)
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst->size[c1_i] = c1_src->size[c1_i];
  }
}

static void c1_emxCopyMatrix_real_T2(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[16], const real_T c1_src[16])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 16; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_emxCopy_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_numElDst;
  int32_T c1_numElSrc;
  int32_T c1_i;
  c1_numElDst = 1;
  c1_numElSrc = 1;
  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    c1_numElDst *= (*c1_dst)->size[c1_i];
    c1_numElSrc *= (*c1_src)->size[c1_i];
  }

  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    (*c1_dst)->size[c1_i] = (*c1_src)->size[c1_i];
  }

  c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, *c1_dst, c1_numElDst,
    c1_srcLocation);
  for (c1_i = 0; c1_i < c1_numElSrc; c1_i++) {
    (*c1_dst)->data[c1_i] = (*c1_src)->data[c1_i];
  }
}

static void c1_emxCopy_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_numElDst;
  int32_T c1_numElSrc;
  int32_T c1_i;
  c1_numElDst = 1;
  c1_numElSrc = 1;
  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    c1_numElDst *= (*c1_dst)->size[c1_i];
    c1_numElSrc *= (*c1_src)->size[c1_i];
  }

  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    (*c1_dst)->size[c1_i] = (*c1_src)->size[c1_i];
  }

  c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, *c1_dst, c1_numElDst,
    c1_srcLocation);
  for (c1_i = 0; c1_i < c1_numElSrc; c1_i++) {
    (*c1_dst)->data[c1_i] = (*c1_src)->data[c1_i];
  }
}

static void c1_emxCopy_real_T_0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T_0 *c1_dst, const c1_emxArray_real_T_0
  *c1_src)
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 1; c1_i++) {
    c1_dst->size[c1_i] = c1_src->size[c1_i];
  }
}

static void c1_emxCopy_real_T_1x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T_1x0 *c1_dst, const c1_emxArray_real_T_1x0
  *c1_src)
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst->size[c1_i] = c1_src->size[c1_i];
  }
}

static void c1_emxCopyStruct_scIvRXQeSh8yxCxSm
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_scIvRXQeSh8yxCxSmtD63bE *c1_dst, const c1_scIvRXQeSh8yxCxSmtD63bE *
   c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_dst->Connectivity = c1_src->Connectivity;
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->ImageSize, c1_src->ImageSize);
  c1_dst->NumObjects = c1_src->NumObjects;
  c1_emxCopy_real_T(chartInstance, c1_sp, &c1_dst->RegionIndices,
                    &c1_src->RegionIndices, c1_srcLocation);
  c1_emxCopy_int32_T(chartInstance, c1_sp, &c1_dst->RegionLengths,
                     &c1_src->RegionLengths, c1_srcLocation);
}

static void c1_emxCopy_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_dst,
  c1_emxArray_int32_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_numElDst;
  int32_T c1_numElSrc;
  int32_T c1_i;
  c1_numElDst = 1;
  c1_numElSrc = 1;
  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    c1_numElDst *= (*c1_dst)->size[c1_i];
    c1_numElSrc *= (*c1_src)->size[c1_i];
  }

  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    (*c1_dst)->size[c1_i] = (*c1_src)->size[c1_i];
  }

  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, *c1_dst, c1_numElDst,
    c1_srcLocation);
  for (c1_i = 0; c1_i < c1_numElSrc; c1_i++) {
    (*c1_dst)->data[c1_i] = (*c1_src)->data[c1_i];
  }
}

static void c1_emxInitMatrix_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_17 c1_pMatrix[2], const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_emxInitStruct_cell_wrap_17(chartInstance, c1_sp, &c1_pMatrix[c1_i],
      c1_srcLocation);
  }
}

static void c1_emxInitStruct_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_17 *c1_pStruct, const
  emlrtRTEInfo *c1_srcLocation)
{
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_pStruct->f1, 1, c1_srcLocation);
}

static void c1_emxFreeMatrix_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_17 c1_pMatrix[2])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_emxFreeStruct_cell_wrap_17(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static void c1_emxFreeStruct_cell_wrap_17(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_17 *c1_pStruct)
{
  c1_emxFree_real_T(chartInstance, &c1_pStruct->f1);
}

static int32_T c1_div_nzp_s32(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, int32_T
  c1_EMLOvCount_src_loc, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc,
  int32_T c1_length_src_loc)
{
  int32_T c1_quotient;
  uint32_T c1_absNumerator;
  uint32_T c1_absDenominator;
  boolean_T c1_quotientNeedsNegation;
  uint32_T c1_tempAbsQuotient;
  (void)chartInstance;
  (void)c1_EMLOvCount_src_loc;
  (void)c1_ssid_src_loc;
  (void)c1_offset_src_loc;
  (void)c1_length_src_loc;
  if (c1_numerator < 0) {
    c1_absNumerator = ~(uint32_T)c1_numerator + 1U;
  } else {
    c1_absNumerator = (uint32_T)c1_numerator;
  }

  if (c1_denominator < 0) {
    c1_absDenominator = ~(uint32_T)c1_denominator + 1U;
  } else {
    c1_absDenominator = (uint32_T)c1_denominator;
  }

  c1_quotientNeedsNegation = ((c1_numerator < 0) != (c1_denominator < 0));
  c1_tempAbsQuotient = c1_absNumerator / c1_absDenominator;
  if (c1_quotientNeedsNegation) {
    c1_quotient = -(int32_T)c1_tempAbsQuotient;
  } else {
    c1_quotient = (int32_T)c1_tempAbsQuotient;
  }

  return c1_quotient;
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_b_red = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_b_green = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_IsFireFound = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_blue = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2360292847U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3791176904U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4021788014U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1955742204U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,4);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.BwpacktbbBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Morphop_packed_Buildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.BwunpacktbbBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bwPackingtbb");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDmYGJgYAPRQMzEAAGsUD4jVIwRLs4CF1cA4pLKglSQeHFRsmcKkM5LzAXzE0s"
    "rPPPS8sHmWzAgzGfDYj4jkvmcUHEI+GBPmX4RB5B+ByT9LFj0cyPpF4DyPYvdMotS3fJL81IYYO"
    "EEo8l3j4IDZfoh9gcQ8I8Cmn9A/Mzi+MTkksyy1Phkw/i0nMz0jBLn/LySovyc4MriktRcmP8AC"
    "7kfrw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sWTEFlh7Yrm0ZVBXz30VB3C";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_flightControlSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    finalize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [17] = {
    "eNrtVstu00AUtdNStTxKF0iwYBGJBSyLuoAdJS8RkdIK9wFsytS+iUcZz5h5pC0rPqE7PqA/wYI",
    "vYM9/8AEsuOMkTXDsuG3USkhYmjgzOffc59wbx21uOPgs4zq56zgL+F7EVXL6z43B3h1b/fN55/",
    "Fgf4ogbqItIkmknKkPJxG8BSWY0VTwJm+LTBjlbZDAfcTGQuo8NkUjwyjvNgz3LZ/aC6kfeqEwL",
    "KigLAk2OTtGttjoLeSpUQm+bgAEOpTCdMIGI50zi6U+rIbgd5WJprmgQHsmtmapDcM0jRnUj8Bv",
    "cqUJWqxGtnmaaKjqo1w3rafKGwJFFDNKeKa3IVEexBhgDTtxgJ+bRqNTaZgfEqkrEJIeqBbtJpy",
    "CQ5qTKvzhgHKihaSE1SNWtYKTtm0xtGdDBMCmBARtq0gg3VhQrvPz7zXQ0zonBwxqcGA6+WwefD",
    "I2+bsUDkHmxq1dFT2QpAObPFdpEpD6UZKtsyqZhGkawS6RL33Mn4Igt3qxcpRHME+wjRJ5MEicb",
    "KptSXsY3lw2EzVtZRZdGRP1k62KYAlbvQfTsnDG1vB5lTCmcmHbIm5BD1jCWiOaTIf1WbNxsRQx",
    "6WDVBhhkW+JVwQM6kQvfKC2iKpZbrdV6g50i27gRrMk1yDbxIeveKj+EwDBAR7Ez6URdBmlAlc1",
    "WAWqQ0yKUo9qG1w6F7KKjU679yAWbg1xgpDoYfazdHYVlPg1mo1+IG/b5VWfU52+fo88P5dLvJ2",
    "M8bgaPM/ZO610q/Y2fS+kt4Ynruonc+pjcnZSe+ZScxa3g2v/x/fXJg4Uvv2+e7j36+fVjkX53Q",
    "r+bfLdy30oXm4vLg/3DYQM6K8/eRFVY7Ksxu+Yz+O+P8a8M9mpvu95g4bP3Mlr9sFt593ltdbey",
    "Vk34FgvsLaXsHZ6XbSc8jpO+pqTfDAYD2+6J6Y8xy/98zN6FgngsDc77z68Xs8nfW0/XQ1a8bqX",
    "iZfdN1cDh3xCGBxN1fHl7yuuzyff1bxX4U075U07m3z7BadaDff/pfpvRTmibqpaCecdKQ7R8zn",
    "s3re4vKudcs9y/Yuf/uFy9f+eZY3OXlHNnnJvXJTerfxed57PM/3Sfc1L4lRn0XDV+1v9BF8H/A",
    "QpaY6I=",
    ""
  };

  static char newstr [1133] = "";
  newstr[0] = '\0';
  for (i = 0; i < 17; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1270663775U));
  ssSetChecksum1(S,(2147883152U));
  ssSetChecksum2(S,(1470302972U));
  ssSetChecksum3(S,(1620563235U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_start_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

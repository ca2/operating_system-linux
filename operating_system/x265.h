/*****************************************************************************
 * Copyright (C) 2013 x265 project
 *
 * Authors: Steve Borho <steve@borho.org>
 *          Min Chen <chenm003@163.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 *
 * This program is also available under a commercial proprietary license.
 * For more information, contact us at license @ x265.com.
 *****************************************************************************/

#ifndef X265_H
#define X265_H

#include <stdint.h>
#include "x265_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* x265_encoder:
 *      opaque handler for encoder */
typedef struct x265_encoder x265_encoder;

/* Application developers planning to link against a shared library version of
 * libx265 from a Microsoft Visual Studio or similar development environment
 * will need to define X265_API_IMPORTS before including this header.
 * This clause does not apply to MinGW, similar development environments, or non
 * Windows platforms. */
#ifdef X265_API_IMPORTS
#define X265_API __declspec(dllimport)
#else
#define X265_API
#endif

typedef enum
{
    NAL_UNIT_CODED_SLICE_TRAIL_N = 0,
    NAL_UNIT_CODED_SLICE_TRAIL_R,
    NAL_UNIT_CODED_SLICE_TSA_N,
    NAL_UNIT_CODED_SLICE_TLA_R,
    NAL_UNIT_CODED_SLICE_STSA_N,
    NAL_UNIT_CODED_SLICE_STSA_R,
    NAL_UNIT_CODED_SLICE_RADL_N,
    NAL_UNIT_CODED_SLICE_RADL_R,
    NAL_UNIT_CODED_SLICE_RASL_N,
    NAL_UNIT_CODED_SLICE_RASL_R,
    NAL_UNIT_CODED_SLICE_BLA_W_LP = 16,
    NAL_UNIT_CODED_SLICE_BLA_W_RADL,
    NAL_UNIT_CODED_SLICE_BLA_N_LP,
    NAL_UNIT_CODED_SLICE_IDR_W_RADL,
    NAL_UNIT_CODED_SLICE_IDR_N_LP,
    NAL_UNIT_CODED_SLICE_CRA,
    NAL_UNIT_VPS = 32,
    NAL_UNIT_SPS,
    NAL_UNIT_PPS,
    NAL_UNIT_ACCESS_UNIT_DELIMITER,
    NAL_UNIT_EOS,
    NAL_UNIT_EOB,
    NAL_UNIT_FILLER_DATA,
    NAL_UNIT_PREFIX_SEI,
    NAL_UNIT_SUFFIX_SEI,
    NAL_UNIT_INVALID = 64,
} NalUnitType;

/* The data within the payload is already NAL-encapsulated; the type is merely
 * in the struct for easy access by the calling application.  All data returned
 * in an x265_nal, including the data in payload, is no longer valid after the
 * next call to x265_encoder_encode.  Thus it must be used or copied before
 * calling x265_encoder_encode again. */
typedef struct x265_nal
{
    unsigned int type;        /* NalUnitType */
    unsigned int sizeBytes;   /* size in bytes */
    ::u328_t* payload;
} x265_nal;

/* Stores all analysis data for a single frame */
typedef struct x265_analysis_data
{
    int64_t          satdCost;
    unsigned int         frameRecordSize;
    unsigned int         poc;
    unsigned int         sliceType;
    unsigned int         numCUsInFrame;
    unsigned int         numPartitions;
    int              bScenecut;
    void*            interData;
    void*            intraData;
} x265_analysis_data;

/* cu statistics */
typedef struct x265_cu_stats
{
    double      percentSkipCu[4];                // Percentage of skip cu in all depths
    double      percentMergeCu[4];               // Percentage of merge cu in all depths
    double      percentIntraDistribution[4][3];  // Percentage of DC, Planar, Angular intra modes in all depths
    double      percentInterDistribution[4][3];  // Percentage of 2Nx2N inter, rect and amp in all depths
    double      percentIntraNxN;                 // Percentage of 4x4 cu

    /* All the above values will add up to 100%. */
} x265_cu_stats;

/* Frame level statistics */
typedef struct x265_frame_stats
{
    double           qp;
    double           rateFactor;
    double           psnrY;
    double           psnrU;
    double           psnrV;
    double           psnr;
    double           ssim;
    double           decideWaitTime;
    double           row0WaitTime;
    double           wallTime;
    double           refWaitWallTime;
    double           totalCTUTime;
    double           stallTime;
    double           avgWPP;
    double           avgLumaDistortion;
    double           avgChromaDistortion;
    double           avgPsyEnergy;
    double           avgResEnergy;
    double           avgLumaLevel;
    double           bufferFill;
    ::u3264_t         bits;
    int              encoderOrder;
    int              poc;
    int              countRowBlocks;
    int              list0POC[16];
    int              list1POC[16];
    ::u3216_t         maxLumaLevel;
    char             sliceType;
    int              bScenecut;
    int              frameLatency;
    x265_cu_stats    cuStats;
} x265_frame_stats;

/* Arbitrary User SEI
 * Payload size is in bytes and the payload pointer must be non-NULL. 
 * Payload types and syntax can be found in Annex D of the H.265 Specification.
 * SEI Payload Alignment bits as described in Annex D must be included at the 
 * end of the payload if needed. The payload should not be NAL-encapsulated.
 * Payloads are written in the order of input */

typedef enum
{
    BUFFERING_PERIOD                     = 0,
    PICTURE_TIMING                       = 1,
    PAN_SCAN_RECT                        = 2,
    FILLER_PAYLOAD                       = 3,
    USER_DATA_REGISTERED_ITU_T_T35       = 4,
    USER_DATA_UNREGISTERED               = 5,
    RECOVERY_POINT                       = 6,
    SCENE_INFO                           = 9,
    FULL_FRAME_SNAPSHOT                  = 15,
    PROGRESSIVE_REFINEMENT_SEGMENT_START = 16,
    PROGRESSIVE_REFINEMENT_SEGMENT_END   = 17,
    FILM_GRAIN_CHARACTERISTICS           = 19,
    POST_FILTER_HINT                     = 22,
    TONE_MAPPING_INFO                    = 23,
    FRAME_PACKING                        = 45,
    DISPLAY_ORIENTATION                  = 47,
    SOP_DESCRIPTION                      = 128,
    ACTIVE_PARAMETER_SETS                = 129,
    DECODING_UNIT_INFO                   = 130,
    TEMPORAL_LEVEL0_INDEX                = 131,
    DECODED_PICTURE_HASH                 = 132,
    SCALABLE_NESTING                     = 133,
    REGION_REFRESH_INFO                  = 134,
    MASTERING_DISPLAY_INFO               = 137,
    CONTENT_LIGHT_LEVEL_INFO             = 144,
} SEIPayloadType;

typedef struct x265_sei_payload
{
    int payloadSize;
    SEIPayloadType payloadType;
    ::u328_t* payload;
} x265_sei_payload;

typedef struct x265_sei
{
    int numPayloads;
    x265_sei_payload *payloads;
} x265_sei;

/* Used to pass pictures into the encoder, and to get picture data back out of
 * the encoder.  The input and output semantics are different */
typedef struct x265_picture
{
    /* presentation time stamp: user-specified, returned on output */
    int64_t pts;

    /* display time stamp: ignored on input, copied from reordered pts. Returned
     * on output */
    int64_t dts;

    /* force quantizer for != X265_QP_AUTO */
    /* The value provided on input is returned with the same picture (POC) on
     * output */
    void*   userData;

    /* Must be specified on input pictures, the number of planes is determined
     * by the colorSpace value */
    void*   planes[3];

    /* Stride is the number of bytes between row starts */
    int     stride[3];

    /* Must be specified on input pictures. x265_picture_init() will set it to
     * the encoder's internal bit depth, but this field must describe the depth
     * of the input pictures. Must be between 8 and 16. Values larger than 8
     * imply 16bits per input sample. If input bit depth is larger than the
     * internal bit depth, the encoder will down-shift pixels. Input samples
     * larger than 8bits will be masked to internal bit depth. On output the
     * bitDepth will be the internal encoder bit depth */
    int     bitDepth;

    /* Must be specified on input pictures: X265_TYPE_AUTO or other.
     * x265_picture_init() sets this to auto, returned on output */
    int     sliceType;

    /* Ignored on input, set to picture count, returned on output */
    int     poc;

    /* Must be specified on input pictures: X265_CSP_I420 or other. It must
     * match the internal color space of the encoder. x265_picture_init() will
     * initialize this value to the internal color space */
    int     colorSpace;

    /* Force the slice base QP for this picture within the encoder. Set to 0
     * to allow the encoder to determine base QP */
    int     forceqp;

    /* If param.analysisMode is X265_ANALYSIS_OFF this field is ignored on input
     * and output. Else the user must call x265_alloc_analysis_data() to
     * allocate analysis buffers for every picture passed to the encoder.
     *
     * On input when param.analysisMode is X265_ANALYSIS_LOAD and analysisData
     * member pointers are valid, the encoder will use the data stored here to
     * reduce encoder work.
     *
     * On output when param.analysisMode is X265_ANALYSIS_SAVE and analysisData
     * member pointers are valid, the encoder will write output analysis into
     * this data structure */
    x265_analysis_data analysisData;

    /* An array of quantizer offsets to be applied to this image during encoding.
     * These are added on top of the decisions made by rateControl.
     * Adaptive quantization must be enabled to use this feature. These quantizer
     * offsets should be given for each 16x16 block (8x8 block, when qg-size is 8).
     * Behavior if quant offsets differ between encoding passes is undefined. */
    float            *quantOffsets;

    /* Frame level statistics */
    x265_frame_stats frameData;

    /* User defined SEI */
    x265_sei         userSEI;

    /* Ratecontrol statistics for collecting the ratecontrol information.
     * It is not used for collecting the last pass ratecontrol data in 
     * multi pass ratecontrol mode. */
    void*  rcData;

    ::u3264_t framesize;

    int    height;
} x265_picture;

typedef enum
{
    X265_DIA_SEARCH,
    X265_HEX_SEARCH,
    X265_UMH_SEARCH,
    X265_STAR_SEARCH,
    X265_FULL_SEARCH
} X265_ME_METHODS;

/* CPU flags */

/* x86 */
#define X265_CPU_CMOV            0x0000001
#define X265_CPU_MMX             0x0000002
#define X265_CPU_MMX2            0x0000004  /* MMX2 aka MMXEXT aka ISSE */
#define X265_CPU_MMXEXT          X265_CPU_MMX2
#define X265_CPU_SSE             0x0000008
#define X265_CPU_SSE2            0x0000010
#define X265_CPU_SSE3            0x0000020
#define X265_CPU_SSSE3           0x0000040
#define X265_CPU_SSE4            0x0000080  /* SSE4.1 */
#define X265_CPU_SSE42           0x0000100  /* SSE4.2 */
#define X265_CPU_LZCNT           0x0000200  /* Phenom support for "leading zero count" instruction. */
#define X265_CPU_AVX             0x0000400  /* AVX support: requires OS support even if YMM registers aren't used. */
#define X265_CPU_XOP             0x0000800  /* AMD XOP */
#define X265_CPU_FMA4            0x0001000  /* AMD FMA4 */
#define X265_CPU_AVX2            0x0002000  /* AVX2 */
#define X265_CPU_FMA3            0x0004000  /* Intel FMA3 */
#define X265_CPU_BMI1            0x0008000  /* BMI1 */
#define X265_CPU_BMI2            0x0010000  /* BMI2 */
/* x86 modifiers */
#define X265_CPU_CACHELINE_32    0x0020000  /* avoid memory loads that span the border between two cachelines */
#define X265_CPU_CACHELINE_64    0x0040000  /* 32/64 is the size of a cacheline in bytes */
#define X265_CPU_SSE2_IS_SLOW    0x0080000  /* avoid most SSE2 functions on Athlon64 */
#define X265_CPU_SSE2_IS_FAST    0x0100000  /* a few functions are only faster on Core2 and Phenom */
#define X265_CPU_SLOW_SHUFFLE    0x0200000  /* The Conroe has a slow shuffle unit (relative to overall SSE performance) */
#define X265_CPU_STACK_MOD4      0x0400000  /* if stack is only mod4 and not mod16 */
#define X265_CPU_SLOW_CTZ        0x0800000  /* BSR/BSF x86 instructions are really slow on some CPUs */
#define X265_CPU_SLOW_ATOM       0x1000000  /* The Atom is terrible: slow SSE unaligned loads, slow
                                             * SIMD multiplies, slow SIMD variable shifts, slow pshufb,
                                             * cacheline split penalties -- gather everything here that
                                             * isn't shared by other CPUs to avoid making half a dozen
                                             * ___new SLOW flags. */
#define X265_CPU_SLOW_PSHUFB     0x2000000  /* such as on the Intel Atom */
#define X265_CPU_SLOW_PALIGNR    0x4000000  /* such as on the AMD Bobcat */

/* ARM */
#define X265_CPU_ARMV6           0x0000001
#define X265_CPU_NEON            0x0000002  /* ARM NEON */
#define X265_CPU_FAST_NEON_MRC   0x0000004  /* Transfer from NEON to ARM register is fast (Cortex-A9) */

#define X265_MAX_SUBPEL_LEVEL   7

/* Log level */
#define X265_LOG_NONE          (-1)
#define X265_LOG_ERROR          0
#define X265_LOG_WARNING        1
#define X265_LOG_INFO           2
#define X265_LOG_DEBUG          3
#define X265_LOG_FULL           4

#define X265_B_ADAPT_NONE       0
#define X265_B_ADAPT_FAST       1
#define X265_B_ADAPT_TRELLIS    2

#define X265_REF_LIMIT_DEPTH    1
#define X265_REF_LIMIT_CU       2

#define X265_TU_LIMIT_BFS       1
#define X265_TU_LIMIT_DFS       2

#define X265_BFRAME_MAX         16
#define X265_MAX_FRAME_THREADS  16

#define X265_TYPE_AUTO          0x0000  /* Let x265 choose the right type */
#define X265_TYPE_IDR           0x0001
#define X265_TYPE_I             0x0002
#define X265_TYPE_P             0x0003
#define X265_TYPE_BREF          0x0004  /* Non-disposable B-frame */
#define X265_TYPE_B             0x0005
#define IS_X265_TYPE_I(x) ((x) == X265_TYPE_I || (x) == X265_TYPE_IDR)
#define IS_X265_TYPE_B(x) ((x) == X265_TYPE_B || (x) == X265_TYPE_BREF)

#define X265_QP_AUTO                 0

#define X265_AQ_NONE                 0
#define X265_AQ_VARIANCE             1
#define X265_AQ_AUTO_VARIANCE        2
#define X265_AQ_AUTO_VARIANCE_BIASED 3

/* NOTE! For this release only X265_CSP_I420 and X265_CSP_I444 are supported */

/* Supported internal color space types (according to semantics of chroma_format_idc) */
#define X265_CSP_I400           0  /* yuv 4:0:0 planar */
#define X265_CSP_I420           1  /* yuv 4:2:0 planar */
#define X265_CSP_I422           2  /* yuv 4:2:2 planar */
#define X265_CSP_I444           3  /* yuv 4:4:4 planar */
#define X265_CSP_COUNT          4  /* Number of supported internal color spaces */

/* These color spaces will eventually be supported as input pictures. The pictures will
 * be converted to the appropriate planar color spaces at ingest */
#define X265_CSP_NV12           4  /* yuv 4:2:0, with one y plane and one packed u+v */
#define X265_CSP_NV16           5  /* yuv 4:2:2, with one y plane and one packed u+v */

/* Interleaved color-spaces may eventually be supported as input pictures */
#define X265_CSP_BGR            6  /* packed bgr 24bits   */
#define X265_CSP_BGRA           7  /* packed bgr 32bits   */
#define X265_CSP_RGB            8  /* packed rgb 24bits   */
#define X265_CSP_MAX            9  /* end of list */

#define X265_EXTENDED_SAR       255 /* aspect ratio explicitly specified as width:height */

/* Analysis options */
#define X265_ANALYSIS_OFF  0
#define X265_ANALYSIS_SAVE 1
#define X265_ANALYSIS_LOAD 2

typedef struct x265_cli_csp
{
    int planes;
    int width[3];
    int height[3];
} x265_cli_csp;

static const x265_cli_csp x265_cli_csps[] =
{
    { 1, { 0, 0, 0 }, { 0, 0, 0 } }, /* i400 */
    { 3, { 0, 1, 1 }, { 0, 1, 1 } }, /* i420 */
    { 3, { 0, 1, 1 }, { 0, 0, 0 } }, /* i422 */
    { 3, { 0, 0, 0 }, { 0, 0, 0 } }, /* i444 */
    { 2, { 0, 0 },    { 0, 1 } },    /* nv12 */
    { 2, { 0, 0 },    { 0, 0 } },    /* nv16 */
};

/* rate tolerance method */
typedef enum
{
    X265_RC_ABR,
    X265_RC_CQP,
    X265_RC_CRF
} X265_RC_METHODS;

/* slice type statistics */
typedef struct x265_sliceType_stats
{
    double        avgQp;
    double        bitrate;
    double        psnrY;
    double        psnrU;
    double        psnrV;
    double        ssim;
    unsigned int      numPics;
} x265_sliceType_stats;

/* Output statistics from encoder */
typedef struct x265_stats
{
    double                globalPsnrY;
    double                globalPsnrU;
    double                globalPsnrV;
    double                globalPsnr;
    double                globalSsim;
    double                elapsedEncodeTime;    /* wall time since encoder was opened */
    double                elapsedVideoTime;     /* encoded picture count / frame rate */
    double                bitrate;              /* accBits / elapsed video time */
    ::u3264_t              accBits;              /* total bits output thus far */
    unsigned int              encodedPictureCount;  /* number of output pictures thus far */
    unsigned int              totalWPFrames;        /* number of uni-directional weighted frames used */
    x265_sliceType_stats  statsI;               /* statistics of I slice */
    x265_sliceType_stats  statsP;               /* statistics of P slice */
    x265_sliceType_stats  statsB;               /* statistics of B slice */
    ::u3216_t              maxCLL;               /* maximum content light level */
    ::u3216_t              maxFALL;              /* maximum frame average light level */
} x265_stats;

/* String values accepted by x265_param_parse() (and CLI) for various parameters */
static const char * const x265_motion_est_names[] = { "dia", "hex", "umh", "star", "full", 0 };
static const char * const x265_source_csp_names[] = { "i400", "i420", "i422", "i444", "nv12", "nv16", 0 };
static const char * const x265_video_format_names[] = { "component", "pal", "ntsc", "secam", "mac", "undef", 0 };
static const char * const x265_fullrange_names[] = { "limited", "full", 0 };
static const char * const x265_colorprim_names[] = { "", "bt709", "undef", "", "bt470m", "bt470bg", "smpte170m", "smpte240m", "film", "bt2020", 0 };
static const char * const x265_transfer_names[] = { "", "bt709", "undef", "", "bt470m", "bt470bg", "smpte170m", "smpte240m", "linear", "log100",
                                                    "log316", "iec61966-2-4", "bt1361e", "iec61966-2-1", "bt2020-10", "bt2020-12",
                                                    "smpte-st-2084", "smpte-st-428", "arib-std-b67", 0 };
static const char * const x265_colmatrix_names[] = { "GBR", "bt709", "undef", "", "fcc", "bt470bg", "smpte170m", "smpte240m",
                                                     "YCgCo", "bt2020nc", "bt2020c", 0 };
static const char * const x265_sar_names[] = { "undef", "1:1", "12:11", "10:11", "16:11", "40:33", "24:11", "20:11",
                                               "32:11", "80:33", "18:11", "15:11", "64:33", "160:99", "4:3", "3:2", "2:1", 0 };
static const char * const x265_interlace_names[] = { "prog", "tff", "bff", 0 };
static const char * const x265_analysis_names[] = { "off", "save", "load", 0 };

/* Zones: override ratecontrol for specific sections of the video.
 * If zones overlap, whichever comes later in the list takes precedence. */
typedef struct x265_zone
{
    int   startFrame, endFrame; /* range of frame numbers */
    int   bForceQp;             /* whether to use qp vs bitrate factor */
    int   qp;
    float bitrateFactor;
} x265_zone;
    
/* x265 input parameters
 *
 * For version safety you may use x265_param_alloc/free() to manage the
 * allocation of x265_param instances, and x265_param_parse() to assign values
 * by name.  By never dereferencing param fields in your own code you can treat
 * x265_param as an opaque data structure */
typedef struct x265_param
{
    /* x265_param_default() will auto-detect this cpu capability bitmap.  it is
     * recommended to not change this value unless you know the cpu detection is
     * somehow flawed on your target hardware. The asm function tables are
     * process global, the first encoder configures them for all encoders */
    int       cpuid;

    /*== Parallelism Features ==*/

    /* Number of concurrently encoded frames between 1 and X265_MAX_FRAME_THREADS
     * or 0 for auto-detection. By default x265 will use a number of frame
     * threads empirically determined to be optimal for your CPU aura count,
     * between 2 and 6.  Using more than one frame thread causes motion search
     * in the down direction to be clamped but otherwise encode behavior is
     * unaffected. With CQP rate control the output bitstream is deterministic
     * for all values of frameNumThreads greater than 1. All other forms of
     * rate-control can be negatively impacted by increases to the number of
     * frame threads because the extra concurrency adds uncertainty to the
     * bitrate estimations. Frame parallelism is generally limited by the the
     * is generally limited by the the number of CU rows
     *
     * When thread pools are used, each frame thread is assigned to a single
     * pool and the frame thread itself is given the node affinity of its pool.
     * But when no thread pools are used no node affinity is assigned. */
    int       frameNumThreads;

    /* Comma seperated list of threads per NUMA node. If "none", then no worker
     * pools are created and only frame parallelism is possible. If NULL or ""
     * (default) x265 will use all available threads on each NUMA node.
     *
     * '+'  is a special value indicating all cores detected on the node
     * '*'  is a special value indicating all cores detected on the node and all
     *      remaining nodes.
     * '-'  is a special value indicating no cores on the node, same as '0'
     *
     * example strings for a 4-node system:
     *   ""        - default, unspecified, all numa nodes are used for thread pools
     *   "*"       - same as default
     *   "none"    - no thread pools are created, only frame parallelism possible
     *   "-"       - same as "none"
     *   "10"      - allocate one pool, using up to 10 cores on node 0
     *   "-,+"     - allocate one pool, using all cores on node 1
     *   "+,-,+"   - allocate two pools, using all cores on nodes 0 and 2
     *   "+,-,+,-" - allocate two pools, using all cores on nodes 0 and 2
     *   "-,*"     - allocate three pools, using all cores on nodes 1, 2 and 3
     *   "8,8,8,8" - allocate four pools with up to 8 threads in each pool
     *
     * The total number of threads will be determined by the number of threads
     * assigned to all nodes. The worker threads will each be given affinity for
     * their node, they will not be allowed to migrate between nodes, but they
     * will be allowed to transfer between CPU cores within their node.
     *
     * If the three pool features: bEnableWavefront, bDistributeModeAnalysis and
     * bDistributeMotionEstimation are all disabled, then numaPools is ignored
     * and no thread pools are created.
     *
     * If "none" is specified, then all three of the thread pool features are
     * implicitly disabled.
     *
     * Multiple thread pools will be allocated for any NUMA node with more than
     * 64 logical CPU cores. But any given thread pool will always use at most
     * one NUMA node.
     *
     * Frame encoders are distributed between the available thread pools, and
     * the encoder will never generate more thread pools than frameNumThreads */
    const char* numaPools;

    /* Enable wavefront parallel processing, greatly increases parallelism for
     * less than 1% compression efficiency loss. Requires a thread pool, enabled
     * by default */
    int       bEnableWavefront;

    /* Use multiple threads to measure CU mode costs. Recommended for many aura
     * CPUs. On RD levels less than 5, it may not offload enough work to warrant
     * the overhead. It is useful with the slow preset since it has the
     * rectangular predictions enabled. At RD level 5 and 6 (preset slower and
     * below), this feature should be an unambiguous win if you have CPU
     * cores available for work. Default disabled */
    int       bDistributeModeAnalysis;

    /* Use multiple threads to perform motion estimation to (ME to one reference
     * per thread). Recommended for many aura CPUs. The more references the more
     * motion searches there will be to distribute. This option is often not a
     * win, particularly in video sequences with low motion. Default disabled */
    int       bDistributeMotionEstimation;

    /*== Logging Features ==*/

    /* Enable analysis and logging distribution of CUs. Now deprecated */
    int       bLogCuStats;

    /* Enable the measurement and reporting of PSNR. Default is enabled */
    int       bEnablePsnr;

    /* Enable the measurement and reporting of SSIM. Default is disabled */
    int       bEnableSsim;

    /* The level of logging detail emitted by the encoder. X265_LOG_NONE to
     * X265_LOG_FULL, default is X265_LOG_INFO */
    int       logLevel;

    /* Filename of CSV log. Now deprecated */
    const char* csvfn;

    /*== Internal Picture Specification ==*/

    /* Internal encoder bit depth. If x265 was compiled to use 8bit pixels
     * (HIGH_BIT_DEPTH=0), this field must be 8, else this field must be 10.
     * Future builds may support 12bit pixels. */
    int       internalBitDepth;

    /* Color space of internal pictures, must match color space of input
     * pictures */
    int       internalCsp;

    /* Numerator and denominator of frame rate */
    unsigned int  fpsNum;
    unsigned int  fpsDenom;

    /* Width (in pixels) of the source pictures. If this width is not an even
     * multiple of 4, the encoder will pad the pictures internally to meet this
     * minimum requirement. All valid HEVC widths are supported */
    int       sourceWidth;

    /* Height (in pixels) of the source pictures. If this height is not an even
     * multiple of 4, the encoder will pad the pictures internally to meet this
     * minimum requirement. All valid HEVC heights are supported */
    int       sourceHeight;

    /* Interlace type of source pictures. 0 - progressive pictures (default).
     * 1 - top field first, 2 - bottom field first. HEVC encodes interlaced
     * content as fields, they must be provided to the encoder in the correct
     * temporal order */
    int       interlaceMode;

    /* Total Number of frames to be encoded, calculated from the user input
     * (--frames) and (--seek). In case, the input is read from a pipe, this can
     * remain as 0. It is later used in 2 pass RateControl, hence storing the
     * value in param */
    int       totalFrames;

    /*== Profile / Tier / Level ==*/

    /* Note: the profile is specified by x265_param_apply_profile() */

    /* Minimum decoder requirement level. Defaults to 0, which implies auto-
     * detection by the encoder. If specified, the encoder will attempt to bring
     * the encode specifications within that specified level. If the encoder is
     * unable to reach the level it issues a warning and emits the actual
     * decoder requirement. If the requested requirement level is higher than
     * the actual level, the actual requirement level is signaled. The value is
     * an specified as an integer with the level times 10, for example level
     * "5.1" is specified as 51, and level "5.0" is specified as 50. */
    int       levelIdc;

    /* if levelIdc is specified (non-zero) this flag will differentiate between
     * Main (0) and High (1) tier. Default is Main tier (0) */
    int       bHighTier;

    /* Enable UHD Blu-ray compatibility support. If specified, the encoder will
     * attempt to modify/set the encode specifications. If the encoder is unable 
     * to do so, this option will be turned OFF. */
    int       uhdBluray;

    /* The maximum number of L0 references a P or B slice may use. This
     * influences the size of the decoded picture buffer. The higher this
     * number, the more reference frames there will be available for motion
     * search, improving compression efficiency of most video at a cost of
     * performance. Value must be between 1 and 16, default is 3 */
    int       maxNumReferences;

    /* Allow libx265 to emit HEVC bitstreams which do not meet strict level
     * requirements. Defaults to false */
    int       bAllowNonConformance;

    /*== Bitstream Options ==*/

    /* Flag indicating whether VPS, SPS and PPS headers should be output with
     * each keyframe. Default false */
    int       bRepeatHeaders;

    /* Flag indicating whether the encoder should generate start codes (Annex B
     * format) or length (file format) before NAL units. Default true, Annex B.
     * Muxers should set this to the correct value */
    int       bAnnexB;

    /* Flag indicating whether the encoder should emit an Access Unit Delimiter
     * NAL at the start of every access unit. Default false */
    int       bEnableAccessUnitDelimiters;

    /* Enables the buffering period SEI and picture timing SEI to signal the HRD
     * parameters. Default is disabled */
    int       bEmitHRDSEI;

    /* Enables the emission of a user data SEI with the stream headers which
     * describes the encoder version, build info, and parameters. This is
     * very helpful for debugging, but may interfere with regression tests.
     * Default enabled */
    int       bEmitInfoSEI;

    /* Enable the generation of SEI messages for each encoded frame containing
     * the hashes of the three reconstructed picture planes. Most decoders will
     * validate those hashes against the reconstructed images it generates and
     * report any mismatches. This is essentially a debugging feature.  Hash
     * types are MD5(1), CRC(2), Checksum(3).  Default is 0, none */
    int       decodedPictureHashSEI;

    /* Enable Temporal Sub Layers while encoding, signals NAL units of coded
     * slices with their temporalId. Output bitstreams can be extracted either
     * at the base temporal layer (layer 0) with roughly half the frame rate or
     * at a higher temporal layer (layer 1) that decodes all the frames in the
     * sequence. */
    int       bEnableTemporalSubLayers;

    /*== GOP structure and slice type decisions (lookahead) ==*/

    /* Enable open GOP - meaning I slices are not necessarily IDR and thus frames
     * encoded after an I slice may reference frames encoded prior to the I
     * frame which have remained in the decoded picture buffer.  Open GOP
     * generally has better compression efficiency and negligible encoder
     * performance impact, but the use case may preclude it.  Default true */
    int       bOpenGOP;

    /* Scene cuts closer together than this are coded as I, not IDR. */
    int       keyframeMin;

    /* Maximum keyframe distance or intra period in number of frames. If 0 or 1,
     * all frames are I frames. A negative value is casted to MAX_INT internally
     * which effectively makes frame 0 the only I frame. Default is 250 */
    int       keyframeMax;

    /* Maximum consecutive B frames that can be emitted by the lookahead. When
     * b-adapt is 0 and keyframMax is greater than bframes, the lookahead emits
     * a fixed pattern of `bframes` B frames between each P.  With b-adapt 1 the
     * lookahead ignores the value of bframes for the most part.  With b-adapt 2
     * the value of bframes determines the search (POC) distance performed in
     * both directions, quadratically increasing the compute load of the
     * lookahead.  The higher the value, the more B frames the lookahead may
     * possibly use consecutively, usually improving compression. Default is 3,
     * maximum is 16 */
    int       bframes;

    /* Sets the operating mode of the lookahead.  With b-adapt 0, the GOP
     * structure is fixed based on the values of keyframeMax and bframes.
     * With b-adapt 1 a light lookahead is used to chose B frame placement.
     * With b-adapt 2 (trellis) a viterbi B path selection is performed */
    int       bFrameAdaptive;

    /* When enabled, the encoder will use the B frame in the middle of each
     * mini-GOP larger than 2 B frames as a motion reference for the surrounding
     * B frames.  This improves compression efficiency for a small performance
     * penalty.  Referenced B frames are treated somewhere between a B and a P
     * frame by rate control.  Default is enabled. */
    int       bBPyramid;

    /* A value which is added to the cost estimate of B frames in the lookahead.
     * It may be a positive value (making B frames appear less expensive, which
     * biases the lookahead to choose more B frames) or negative, which makes the
     * lookahead choose more P frames. Default is 0, there are no limits */
    int       bFrameBias;

    /* The number of frames that must be queued in the lookahead before it may
     * make slice decisions. Increasing this value directly increases the encode
     * latency. The longer the queue the more optimally the lookahead may make
     * slice decisions, particularly with b-adapt 2. When cu-tree is enabled,
     * the length of the queue linearly increases the effectiveness of the
     * cu-tree analysis. Default is 40 frames, maximum is 250 */
    int       lookaheadDepth;

    /* Use multiple worker threads to measure the estimated cost of each frame
     * within the lookahead. When bFrameAdaptive is 2, most frame cost estimates
     * will be performed in batch mode, many cost estimates at the same time,
     * and lookaheadSlices is ignored for batched estimates. The effect on
     * performance can be quite small.  The higher this parameter, the less
     * accurate the frame costs will be (since context is lost across slice
     * boundaries) which will result in less accurate B-frame and scene-cut
     * decisions. Default is 0 - disabled. 1 is the same as 0. Max 16 */
    int       lookaheadSlices;

    /* An arbitrary threshold which determines how aggressively the lookahead
     * should detect scene cuts. The default (40) is recommended. */
    int       scenecutThreshold;

    /* Replace keyframes by using a column of intra blocks that transfer across the video
     * from one side to the other, thereby "refreshing" the image. In effect, instead of a
     * big keyframe, the keyframe is "spread" over many frames. */
    int       bIntraRefresh;

    /*== Coding Unit (CU) definitions ==*/

    /* Maximum CU width and height in pixels.  The size must be 64, 32, or 16.
     * The higher the size, the more efficiently x265 can encode areas of low
     * complexity, greatly improving compression efficiency at large
     * resolutions.  The smaller the size, the more effective wavefront and
     * frame parallelism will become because of the increase in rows. default 64
     * All encoders within the same process must use the same maxCUSize, until
     * all encoders are closed and x265_cleanup() is called to reset the value. */
    unsigned int  maxCUSize;

    /* Minimum CU width and height in pixels.  The size must be 64, 32, 16, or
     * 8. Default 8. All encoders within the same process must use the same
     * minCUSize. */
    unsigned int  minCUSize;

    /* Enable rectangular motion prediction partitions (vertical and
     * horizontal), available at all CU depths from 64x64 to 8x8. Default is
     * disabled */
    int       bEnableRectInter;

    /* Enable asymmetrical motion predictions.  At CU depths 64, 32, and 16, it
     * is possible to use 25%/75% split partitions in the up, down, right, left
     * directions. For some material this can improve compression efficiency at
     * the cost of extra analysis. bEnableRectInter must be enabled for this
     * feature to be used. Default disabled */
    int       bEnableAMP;

    /*== Residual Quadtree Transform Unit (TU) definitions ==*/

    /* Maximum TU width and height in pixels.  The size must be 32, 16, 8 or 4.
     * The larger the size the more efficiently the residual can be compressed
     * by the DCT transforms, at the expense of more computation */
    unsigned int  maxTUSize;

    /* The additional depth the residual quad-tree is allowed to recurse beyond
     * the coding quad-tree, for inter coded blocks. This must be between 1 and
     * 4. The higher the value the more efficiently the residual can be
     * compressed by the DCT transforms, at the expense of much more compute */
    unsigned int  tuQTMaxInterDepth;

    /* The additional depth the residual quad-tree is allowed to recurse beyond
     * the coding quad-tree, for intra coded blocks. This must be between 1 and
     * 4. The higher the value the more efficiently the residual can be
     * compressed by the DCT transforms, at the expense of much more compute */
    unsigned int  tuQTMaxIntraDepth;

    /* Enable early exit decisions for inter coded blocks to avoid recursing to
     * higher TU depths. Default: 0 */
    unsigned int  limitTU;

    /* Set the amount of rate-distortion analysis to use within quant. 0 implies
     * no rate-distortion optimization. At level 1 rate-distortion cost is used to
     * find optimal rounding values for each level (and allows psy-rdoq to be
     * enabled). At level 2 rate-distortion cost is used to make decimate decisions
     * on each 4x4 coding group (including the cost of signaling the group within
     * the group bitmap).  Psy-rdoq is less effective at preserving energy when
     * RDOQ is at level 2. Default: 0 */
    int       rdoqLevel;

    /* Enable the implicit signaling of the sign bit of the last coefficient of
     * each transform unit. This saves one bit per TU at the expense of figuring
     * out which coefficient can be toggled with the least distortion.
     * Default is enabled */
    int       bEnableSignHiding;

    /* Allow intra coded blocks to be encoded directly as residual without the
     * DCT transform, when this improves efficiency. Checking whether the block
     * will benefit from this option incurs a performance penalty. Default is
     * disabled */
    int       bEnableTransformSkip;

    /* An integer value in range of 0 to 2000, which denotes strength of noise
     * reduction in intra CUs. 0 means disabled */
    int       noiseReductionIntra;

    /* An integer value in range of 0 to 2000, which denotes strength of noise
     * reduction in inter CUs. 0 means disabled */
    int       noiseReductionInter;

    /* Quantization scaling lists. HEVC supports 6 quantization scaling lists to
     * be defined; one each for Y, Cb, Cr for intra prediction and one each for
     * inter prediction.
     *
     * - NULL and "off" will disable quant scaling (default)
     * - "default" will enable the HEVC default scaling lists, which
     *   do not need to be signaled since they are specified
     * - all other strings indicate a filename containing custom scaling lists
     *   in the HM format. The encode will fail if the file is not parsed
     *   correctly. Custom lists must be signaled in the SPS. */
    const char *scalingLists;

    /*== Intra Coding Tools ==*/

    /* Enable constrained intra prediction. This causes intra prediction to
     * input samples that were inter predicted. For some use cases this is
     * believed to me more robust to stream errors, but it has a compression
     * penalty on P and (particularly) B slices. Defaults to disabled */
    int       bEnableConstrainedIntra;

    /* Enable strong intra smoothing for 32x32 blocks where the reference
     * samples are flat. It may or may not improve compression efficiency,
     * depending on your source material. Defaults to disabled */
    int       bEnableStrongIntraSmoothing;

    /*== Inter Coding Tools ==*/

    /* The maximum number of merge candidates that are considered during inter
     * analysis.  This number (between 1 and 5) is signaled in the stream
     * headers and determines the number of bits required to signal a merge so
     * it can have significant trade-offs. The smaller this number the higher
     * the performance but the less compression efficiency. Default is 3 */
    unsigned int  maxNumMergeCand;

    /* Limit the motion references used for each search based on the results of
     * previous motion searches already performed for the same CU: If 0 all
     * references are always searched. If X265_REF_LIMIT_CU all motion searches
     * will restrict themselves to the references selected by the 2Nx2N search
     * at the same depth. If X265_REF_LIMIT_DEPTH the 2Nx2N motion search will
     * only use references that were selected by the best motion searches of the
     * 4 split CUs at the next lower CU depth.  The two flags may be combined */
    unsigned int  limitReferences;

    /* Limit modes analyzed for each CU using cost metrics from the 4 sub-CUs */
    unsigned int limitModes;

    /* ME search method (DIA, HEX, UMH, STAR, FULL). The search patterns
     * (methods) are sorted in increasing complexity, with diamond being the
     * simplest and fastest and full being the slowest.  DIA, HEX, and UMH were
     * adapted from x264 directly. STAR is an adaption of the HEVC reference
     * encoder's three step search, while full is a naive exhaustive search. The
     * default is the star search, it has a good balance of performance and
     * compression efficiency */
    int       searchMethod;

    /* A value between 0 and X265_MAX_SUBPEL_LEVEL which adjusts the amount of
     * effort performed during sub-pel refine. Default is 5 */
    int       subpelRefine;

    /* The maximum distance from the motion prediction that the full pel motion
     * search is allowed to progress before terminating. This value can have an
     * effect on frame parallelism, as referenced frames must be at least this
     * many rows of reconstructed pixels ahead of the referencee at all times.
     * (When considering reference lag, the motion prediction must be ignored
     * because it cannot be known ahead of time).  Default is 60, which is the
     * default max CU size (64) minus the luma HPEL half-filter length (4). If a
     * smaller CU size is used, the search range should be similarly reduced */
    int       searchRange;

    /* Enable availability of temporal motion vector for AMVP, default is enabled */
    int       bEnableTemporalMvp;

    /* Enable weighted prediction in P slices.  This enables weighting analysis
     * in the lookahead, which influences slice decisions, and enables weighting
     * analysis in the main encoder which allows P reference samples to have a
     * weight function applied to them prior to using them for motion
     * compensation.  In video which has lighting changes, it can give a large
     * improvement in compression efficiency. Default is enabled */
    int       bEnableWeightedPred;

    /* Enable weighted prediction in B slices. Default is disabled */
    int       bEnableWeightedBiPred;

    /* Enable source pixels in motion estimation. Default is disabled */
    int      bSourceReferenceEstimation;

    /*== Loop Filters ==*/

    /* Enable the deblocking loop filter, which improves visual quality by
     * reducing blocking effects at block edges, particularly at lower bitrates
     * or higher QP. When enabled it adds another CU row of reference lag,
     * reducing frame parallelism effectiveness. Default is enabled */
    int       bEnableLoopFilter;

    /* deblocking filter tC offset [-6, 6] -6 light filter, 6 strong.
     * This is the coded div2 value, actual offset is doubled at use */
    int       deblockingFilterTCOffset;

    /* deblocking filter Beta offset [-6, 6] -6 light filter, 6 strong
     * This is the coded div2 value, actual offset is doubled at use */
    int       deblockingFilterBetaOffset;

    /* Enable the Sample Adaptive Offset loop filter, which reduces distortion
     * effects by adjusting reconstructed sample values based on histogram
     * analysis to better approximate the original samples. When enabled it adds
     * a CU row of reference lag, reducing frame parallelism effectiveness.
     * Default is enabled */
    int       bEnableSAO;

    /* Note: when deblocking and SAO are both enabled, the loop filter CU lag is
     * only one row, as they operate in series on the same row. */

    /* Select the method in which SAO deals with deblocking boundary pixels. If
     * disabled the right and bottom boundary areas are skipped. If enabled,
     * non-deblocked pixels are used entirely. Default is disabled */
    int       bSaoNonDeblocked;

    /*== Analysis tools ==*/

    /* A value between 1 and 6 (both inclusive) which determines the level of 
     * rate distortion optimizations to perform during mode and depth decisions.
     * The more RDO the better the compression efficiency at a major cost of 
     * performance. Default is 3 */
    int       rdLevel;

    /* Enable early skip decisions to avoid analysing additional modes in likely
     * skip blocks. Default is disabled */
    int       bEnableEarlySkip;

    /* Enable early CU size decisions to avoid recursing to higher depths. 
     * Default is enabled */
    int bEnableRecursionSkip;

    /* Use a faster search method to find the best intra mode. Default is 0 */
    int       bEnableFastIntra;

    /* Enable a faster determination of whether skipping the DCT transform will
     * be beneficial. Slight performance gain for some compression loss. Default
     * is enabled */
    int       bEnableTSkipFast;

    /* The CU Lossless flag, when enabled, compares the rate-distortion costs
     * for normal and lossless encoding, and chooses the best mode for each CU.
     * If lossless mode is chosen, the cu-transquant-bypass flag is set for that
     * CU */
    int       bCULossless;

    /* Specify whether to attempt to encode intra modes in B frames. By default
     * enabled, but only applicable for the presets which use rdLevel 5 or 6
     * (veryslow and placebo). All other presets will not try intra in B frames
     * regardless of this setting */
    int       bIntraInBFrames;

    /* Apply an optional penalty to the estimated cost of 32x32 intra blocks in
     * non-intra slices. 0 is disabled, 1 enables a small penalty, and 2 enables
     * a full penalty. This favors inter-coding and its low bitrate over
     * potential increases in distortion, but usually improves performance.
     * Default is 0 */
    int       rdPenalty;

    /* Psycho-visual rate-distortion strength. Only has an effect in presets
     * which use RDO. It makes mode decision favor options which preserve the
     * energy of the source, at the cost of lost compression. The value must
     * be between 0 and 5.0, 1.0 is typical. Default 2.0 */
    double    psyRd;

    /* Strength of psycho-visual optimizations in quantization. Only has an
     * effect when RDOQ is enabled (presets slow, slower and veryslow). The 
     * value must be between 0 and 50, 1.0 is typical. Default 0 */
    double    psyRdoq;

    /* Perform quantisation parameter based RD refinement. RD cost is calculated
     * on the best CU partitions, chosen after the CU analysis, for a range of QPs
     * to find the optimal rounding effect. Only effective at rd-levels 5 and 6.
     * Default disabled */
    int       bEnableRdRefine;

    /* If X265_ANALYSIS_SAVE, write per-frame analysis information into analysis
     * buffers.  if X265_ANALYSIS_LOAD, read analysis information into analysis
     * buffer and use this analysis information to reduce the amount of work
     * the encoder must perform. Default X265_ANALYSIS_OFF */
    int       analysisMode;

    /* Filename for analysisMode save/load. Default name is "x265_analysis.dat" */
    const char* analysisFileName;

    /*== Rate Control ==*/

    /* The lossless flag enables true lossless coding, bypassing scaling,
     * transform, quantization and in-loop filter processes. This is used for
     * ultra-high bitrates with zero loss of quality. It implies no rate control */
    int       bLossless;

    /* Generally a small signed integer which offsets the QP used to quantize
     * the Cb chroma residual (delta from luma QP specified by rate-control).
     * Default is 0, which is recommended */
    int       cbQpOffset;

    /* Generally a small signed integer which offsets the QP used to quantize
     * the Cr chroma residual (delta from luma QP specified by rate-control).
     * Default is 0, which is recommended */
    int       crQpOffset;

    struct
    {
        /* Explicit mode of rate-control, necessary for API users. It must
         * be one of the X265_RC_METHODS enum values. */
        int       rateControlMode;

        /* Base QP to use for Constant QP rate control. Adaptive QP may alter
         * the QP used for each block. If a QP is specified on the command line
         * CQP rate control is implied. Default: 32 */
        int       qp;

        /* target bitrate for Average BitRate (ABR) rate control. If a non- zero
         * bitrate is specified on the command line, ABR is implied. Default 0 */
        int       bitrate;

        /* qComp sets the quantizer curve compression factor. It weights the frame
         * quantizer based on the complexity of residual (measured by lookahead).
         * Default value is 0.6. Increasing it to 1 will effectively generate CQP */
        double    qCompress;

        /* QP offset between I/P and P/B frames. Default ipfactor: 1.4
         * Default pbFactor: 1.3 */
        double    ipFactor;
        double    pbFactor;

        /* Ratefactor constant: targets a certain constant "quality".
         * Acceptable values between 0 and 51. Default value: 28 */
        double    rfConstant;

        /* Max QP difference between frames. Default: 4 */
        int       qpStep;

        /* Enable adaptive quantization. This mode distributes available bits between all
         * CTUs of a frame, assigning more bits to low complexity areas. Turning
         * this ON will usually affect PSNR negatively, however SSIM and visual quality
         * generally improves. Default: X265_AQ_VARIANCE */
        int       aqMode;

        /* Sets the strength of AQ bias towards low detail CTUs. Valid only if
         * AQ is enabled. Default value: 1.0. Acceptable values between 0.0 and 3.0 */
        double    aqStrength;

        /* Sets the maximum rate the VBV buffer should be assumed to refill at
         * Default is zero */
        int       vbvMaxBitrate;

        /* Sets the size of the VBV buffer in kilobits. Default is zero */
        int       vbvBufferSize;

        /* Sets how full the VBV buffer must be before playback starts. If it is less than
         * 1, then the initial fill is vbv-init * vbvBufferSize. Otherwise, it is
         * interpreted as the initial fill in kbits. Default is 0.9 */
        double    vbvBufferInit;

        /* Enable CUTree rate-control. This keeps track of the CUs that propagate temporally
         * across frames and assigns more bits to these CUs. Improves encode efficiency.
         * Default: enabled */
        int       cuTree;

        /* In CRF mode, maximum CRF as caused by VBV. 0 implies no limit */
        double    rfConstantMax;

        /* In CRF mode, minimum CRF as caused by VBV */
        double    rfConstantMin;

        /* Multi-pass encoding */
        /* Enable writing the stats in a multi-pass encode to the stat output file */
        int       bStatWrite;

        /* Enable loading data from the stat input file in a multi pass encode */
        int       bStatRead;

        /* Filename of the 2pass output/input stats file, if unspecified the
         * encoder will default to using x265_2pass.log */
        const char* statFileName;

        /* temporally blur quants */
        double    qblur;

        /* temporally blur complexity */
        double    complexityBlur;

        /* Enable slow and a more detailed first pass encode in multi pass rate control */
        int       bEnableSlowFirstPass;

        /* rate-control overrides */
        int        zoneCount;
        x265_zone* zones;

        /* specify a text file which contains MAX_MAX_QP + 1 floating point
         * values to be copied into x265_lambda_tab and a second set of
         * MAX_MAX_QP + 1 floating point values for x265_lambda2_tab. All values
         * are separated by comma, space or newline. Text after a hash (#) is
         * ignored. The lambda tables are process-global, so these ___new lambda
         * values will affect all encoders in the same process */
        const char* lambdaFileName;

        /* Enable stricter conditions to check bitrate deviations in CBR mode. May compromise
         * quality to maintain bitrate adherence */
        int bStrictCbr;

        /* Enable adaptive quantization at CU granularity. This parameter specifies
         * the minimum CU size at which QP can be adjusted, i.e. Quantization Group
         * (QG) size. Allowed values are 64, 32, 16, 8 provided it falls within the
         * inclusuve range [maxCUSize, minCUSize]. Experimental, default: maxCUSize */
        unsigned int qgSize;

        /* internally enable if tune grain is set */
        int      bEnableGrain;

        /* sets a hard upper limit on QP */
        int      qpMax;

        /* sets a hard lower limit on QP */
        int      qpMin;
    } rc;

    /*== Video Usability Information ==*/
    struct
    {
        /* Aspect ratio idc to be added to the VUI.  The default is 0 indicating
         * the apsect ratio is unspecified. If set to X265_EXTENDED_SAR then
         * sarWidth and sarHeight must also be set */
        int aspectRatioIdc;

        /* Sample Aspect Ratio width in arbitrary units to be added to the VUI
         * only if aspectRatioIdc is set to X265_EXTENDED_SAR.  This is the width
         * of an individual pixel. If this is set then sarHeight must also be set */
        int sarWidth;

        /* Sample Aspect Ratio height in arbitrary units to be added to the VUI.
         * only if aspectRatioIdc is set to X265_EXTENDED_SAR.  This is the width
         * of an individual pixel. If this is set then sarWidth must also be set */
        int sarHeight;

        /* Enable overscan info present flag in the VUI.  If this is set then
         * bEnabledOverscanAppropriateFlag will be added to the VUI. The default
         * is false */
        int bEnableOverscanInfoPresentFlag;

        /* Enable overscan appropriate flag.  The status of this flag is added
         * to the VUI only if bEnableOverscanInfoPresentFlag is set. If this
         * flag is set then cropped decoded pictures may be output for display.
         * The default is false */
        int bEnableOverscanAppropriateFlag;

        /* Video signal type present flag of the VUI.  If this is set then
         * videoFormat, bEnableVideoFullRangeFlag and
         * bEnableColorDescriptionPresentFlag will be added to the VUI. The
         * default is false */
        int bEnableVideoSignalTypePresentFlag;

        /* Video format of the source video.  0 = component, 1 = PAL, 2 = NTSC,
         * 3 = SECAM, 4 = MAC, 5 = unspecified video format is the default */
        int videoFormat;

        /* Video full range flag indicates the black level and range of the luma
         * and chroma signals as derived from E'Y, E'PB, and E'PR or E'R, E'G,
         * and E'B real-valued component signals. The default is false */
        int bEnableVideoFullRangeFlag;

        /* Color description present flag in the VUI. If this is set then
         * color_primaries, transfer_characteristics and matrix_coeffs are to be
         * added to the VUI. The default is false */
        int bEnableColorDescriptionPresentFlag;

        /* Color primaries holds the chromacity coordinates of the source
         * primaries. The default is 2 */
        int colorPrimaries;

        /* Transfer characteristics indicates the opto-electronic transfer
         * characteristic of the source picture. The default is 2 */
        int transferCharacteristics;

        /* Matrix coefficients used to derive the luma and chroma signals from
         * the red, blue and green primaries. The default is 2 */
        int matrixCoeffs;

        /* Chroma location info present flag adds chroma_sample_loc_type_top_field and
         * chroma_sample_loc_type_bottom_field to the VUI. The default is false */
        int bEnableChromaLocInfoPresentFlag;

        /* Chroma sample location type top field holds the chroma location in
         * the top field. The default is 0 */
        int chromaSampleLocTypeTopField;

        /* Chroma sample location type bottom field holds the chroma location in
         * the bottom field. The default is 0 */
        int chromaSampleLocTypeBottomField;

        /* Default display window flag adds def_disp_win_left_offset,
         * def_disp_win_right_offset, def_disp_win_top_offset and
         * def_disp_win_bottom_offset to the VUI. The default is false */
        int bEnableDefaultDisplayWindowFlag;

        /* Default display window left offset holds the left offset with the
         * conformance cropping window to further crop the displayed window */
        int defDispWinLeftOffset;

        /* Default display window right offset holds the right offset with the
         * conformance cropping window to further crop the displayed window */
        int defDispWinRightOffset;

        /* Default display window top offset holds the top offset with the
         * conformance cropping window to further crop the displayed window */
        int defDispWinTopOffset;

        /* Default display window bottom offset holds the bottom offset with the
         * conformance cropping window to further crop the displayed window */
        int defDispWinBottomOffset;
    } vui;

    /* SMPTE ST 2086 mastering display color volume SEI info, specified as a
     * string which is parsed when the stream header SEI are emitted. The string
     * format is "G(%hn,%hn)B(%hn,%hn)R(%hn,%hn)WP(%hn,%hn)L(%u,%u)" where %hn
     * are unsigned 16bit integers and %u are unsigned 32bit integers. The SEI
     * includes X,Y display primaries for RGB channels, white point X,Y and
     * max,min luminance values. */
    const char* masteringDisplayColorVolume;

    /* Maximum Content light level(MaxCLL), specified as integer that indicates the
     * maximum pixel intensity level in units of 1 candela per square metre of the
     * bitstream. x265 will also calculate MaxCLL programmatically from the input
     * pixel values and set in the Content light level info SEI */
    ::u3216_t maxCLL;

    /* Maximum Frame Average Light Level(MaxFALL), specified as integer that indicates
     * the maximum frame average intensity level in units of 1 candela per square
     * metre of the bitstream. x265 will also calculate MaxFALL programmatically
     * from the input pixel values and set in the Content light level info SEI */
    ::u3216_t maxFALL;

    /* Minimum luma level of input source picture, specified as a integer which
     * would automatically increase any luma values below the specified --min-luma
     * value to that value. */
    ::u3216_t minLuma;

    /* Maximum luma level of input source picture, specified as a integer which
     * would automatically decrease any luma values above the specified --max-luma
     * value to that value. */
    ::u3216_t maxLuma;

    /* Maximum of the picture order count */
    int log2MaxPocLsb;

    /* Emit VUI Timing info, an optional VUI field */
    int bEmitVUITimingInfo;

    /* Emit HRD Timing info */
    int bEmitVUIHRDInfo;

    /* Maximum count of Slices of picture, the value range is [1, maximum rows] */
    unsigned int maxSlices;

} x265_param;

/* x265_param_alloc:
 *  Allocates an x265_param instance. The returned param structure is not
 *  special in any way, but using this method together with x265_param_free()
 *  and x265_param_parse() to set values by name allows the application to treat
 *  x265_param as an opaque data struct for version safety */
x265_param *x265_param_alloc(void);

/* x265_param_free:
 *  Use x265_param_free() to release storage for an x265_param instance
 *  allocated by x265_param_alloc() */
void x265_param_free(x265_param *);

/* x265_param_default:
 *  Initialize an x265_param structure to default values */
void x265_param_default(x265_param *param);

/* x265_param_parse:
 *  set one parameter by name.
 *  returns 0 on success, or returns one of the following errors.
 *  note: BAD_VALUE occurs only if it can't even parse the value,
 *  numerical range is not checked until x265_encoder_open().
 *  value=NULL means "true" for boolean options, but is a BAD_VALUE for non-booleans. */
#define X265_PARAM_BAD_NAME  (-1)
#define X265_PARAM_BAD_VALUE (-2)
int x265_param_parse(x265_param *p, const char *name, const char *value);

static const char * const x265_profile_names[] = {
    /* HEVC v1 */
    "main", "main10", "mainstillpicture", /* alias */ "msp",

    /* HEVC v2 (Range Extensions) */
    "main-intra", "main10-intra",
    "main444-8",  "main444-intra", "main444-stillpicture",

    "main422-10", "main422-10-intra",
    "main444-10", "main444-10-intra",

    "main12",     "main12-intra",
    "main422-12", "main422-12-intra",
    "main444-12", "main444-12-intra",

    "main444-16-intra", "main444-16-stillpicture", /* Not Supported! */
    0
};

/* x265_param_apply_profile:
 *      Applies the restrictions of the given profile. (one of x265_profile_names)
 *      (can be NULL, in which case the function will do nothing)
 *      Note: the detected profile can be lower than the one specified to this
 *      function. This function will force the encoder parameters to fit within
 *      the specified profile, or fail if that is impossible.
 *      returns 0 on success, negative on failure (e.g. invalid profile name). */
int x265_param_apply_profile(x265_param *, const char *profile);

/* x265_param_default_preset:
 *      The same as x265_param_default, but also use the passed preset and tune
 *      to modify the default settings.
 *      (either can be NULL, which implies no preset or no tune, respectively)
 *
 *      Currently available presets are, ordered from fastest to slowest: */
static const char * const x265_preset_names[] = { "ultrafast", "superfast", "veryfast", "faster", "fast", "medium", "slow", "slower", "veryslow", "placebo", 0 };

/*      The presets can also be indexed numerically, as in:
 *      x265_param_default_preset( &param, "3", ... )
 *      with ultrafast mapping to "0" and placebo mapping to "9".  This mapping may
 *      of course change if ___new presets are added in between, but will always be
 *      ordered from fastest to slowest.
 *
 *      Warning: the speed of these presets scales dramatically.  Ultrafast is a full
 *      100 times faster than placebo!
 *
 *      Currently available tunings are: */
static const char * const x265_tune_names[] = { "psnr", "ssim", "grain", "zerolatency", "fastdecode", 0 };

/*      returns 0 on success, negative on failure (e.g. invalid preset/tune name). */
int x265_param_default_preset(x265_param *, const char *preset, const char *tune);

/* x265_picture_alloc:
 *  Allocates an x265_picture instance. The returned picture structure is not
 *  special in any way, but using this method together with x265_picture_free()
 *  and x265_picture_init() allows some version safety. New picture fields will
 *  always be added to the end of x265_picture */
x265_picture *x265_picture_alloc(void);

/* x265_picture_free:
 *  Use x265_picture_free() to release storage for an x265_picture instance
 *  allocated by x265_picture_alloc() */
void x265_picture_free(x265_picture *);

/* x265_picture_init:
 *       Initialize an x265_picture structure to default values. It sets the pixel
 *       depth and color space to the encoder's internal values and sets the slice
 *       type to auto - so the lookahead will determine slice type. */
void x265_picture_init(x265_param *param, x265_picture *pic);

/* x265_max_bit_depth:
 *      Specifies the numer of bits per pixel that x265 uses internally to
 *      represent a pixel, and the bit depth of the output bitstream.
 *      param->internalBitDepth must be set to this value. x265_max_bit_depth
 *      will be 8 for default builds, 10 for HIGH_BIT_DEPTH builds. */
X265_API extern const int x265_max_bit_depth;

/* x265_version_str:
 *      A static string containing the version of this compiled x265 library */
X265_API extern const char *x265_version_str;

/* x265_build_info:
 *      A static string describing the compiler and target architecture */
X265_API extern const char *x265_build_info_str;

/* Force a link error in the case of linking against an incompatible API version.
 * Glue #defines exist to force correct macro expansion; the final output of the macro
 * is x265_encoder_open_##X265_BUILD (for purposes of dlopen). */
#define x265_encoder_glue1(x, y) x ## y
#define x265_encoder_glue2(x, y) x265_encoder_glue1(x, y)
#define x265_encoder_open x265_encoder_glue2(x265_encoder_open_, X265_BUILD)

/* x265_encoder_open:
 *      create a ___new encoder handler, all parameters from x265_param are copied */
x265_encoder* x265_encoder_open(x265_param *);

/* x265_encoder_parameters:
 *      copies the current internal set of parameters to the pointer provided
 *      by the caller.  useful when the calling application needs to know
 *      how x265_encoder_open has changed the parameters.
 *      note that the data accessible through pointers in the returned param struct
 *      (e.g. filenames) should not be modified by the calling application. */
void x265_encoder_parameters(x265_encoder *, x265_param *);

/* x265_encoder_headers:
 *      return the SPS and PPS that will be used for the whole stream.
 *      *pi_nal is the number of NAL units outputted in pp_nal.
 *      returns negative on error, total unsigned char size of payload data on success
 *      the payloads of all output NALs are guaranteed to be sequential in memory. */
int x265_encoder_headers(x265_encoder *, x265_nal **pp_nal, unsigned int *pi_nal);

/* x265_encoder_encode:
 *      encode one picture.
 *      *pi_nal is the number of NAL units outputted in pp_nal.
 *      returns negative on error, 1 if a picture and access unit were output,
 *      or zero if the encoder pipeline is still filling or is empty after flushing.
 *      the payloads of all output NALs are guaranteed to be sequential in memory.
 *      To flush the encoder and retrieve delayed output pictures, pass pic_in as NULL.
 *      Once flushing has begun, all subsequent calls must pass pic_in as NULL. */
int x265_encoder_encode(x265_encoder *encoder, x265_nal **pp_nal, unsigned int *pi_nal, x265_picture *pic_in, x265_picture *pic_out);

/* x265_encoder_reconfig:
 *      various parameters from x265_param are copied.
 *      this takes effect immediately, on whichever frame is encoded next;
 *      returns 0 on success, negative on parameter validation error.
 *
 *      not all parameters can be changed; see the actual function for a
 *      detailed breakdown.  since not all parameters can be changed, moving
 *      from preset to preset may not always fully copy all relevant parameters,
 *      but should still work usably in practice. however, more so than for
 *      other presets, many of the speed shortcuts used in ultrafast cannot be
 *      switched out of; using reconfig to switch between ultrafast and other
 *      presets is not recommended without a more fine-grained breakdown of
 *      parameters to take this into account. */
int x265_encoder_reconfig(x265_encoder *, x265_param *);

/* x265_encoder_get_stats:
 *       returns encoder statistics */
void x265_encoder_get_stats(x265_encoder *encoder, x265_stats *, unsigned int statsSizeBytes);

/* x265_encoder_log:
 *       This function is deprecated */
void x265_encoder_log(x265_encoder *encoder, int argc, char **argv);

/* x265_encoder_close:
 *      close an encoder handler */
void x265_encoder_close(x265_encoder *);

/* x265_encoder_intra_refresh:
 *      If an intra refresh is not in progress, begin one with the next P-frame.
 *      If an intra refresh is in progress, begin one as soon as the current one finishes.
 *      Requires bIntraRefresh to be set.
 *
 *      Useful for interactive streaming where the client can tell the server that packet loss has
 *      occurred.  In this case, keyint can be set to an extremely high value so that intra refreshes
 *      occur only when calling x265_encoder_intra_refresh.
 *
 *      In multi-pass encoding, if x265_encoder_intra_refresh is called differently in each pass,
 *      behavior is undefined.
 *
 *      Should not be called during an x265_encoder_encode. */

int x265_encoder_intra_refresh(x265_encoder *);

/* x265_cleanup:
 *       release library static allocations, reset configured CTU size */
void x265_cleanup(void);

#define X265_MAJOR_VERSION 1

/* === Multi-lib API ===
 * By using this method to gain access to the libx265 interfaces, you allow run-
 * time selection between various available libx265 libraries based on the
 * encoder parameters. The most likely use case is to choose between Main and
 * Main10 builds of libx265. */

typedef struct x265_api
{
    int           api_major_version;    /* X265_MAJOR_VERSION */
    int           api_build_number;     /* X265_BUILD (soname) */
    int           sizeof_param;         /* sizeof(x265_param) */
    int           sizeof_picture;       /* sizeof(x265_picture) */
    int           sizeof_analysis_data; /* sizeof(x265_analysis_data) */
    int           sizeof_zone;          /* sizeof(x265_zone) */
    int           sizeof_stats;         /* sizeof(x265_stats) */

    int           bit_depth;
    const char*   version_str;
    const char*   build_info_str;

    /* libx265 public API functions, documented above with x265_ prefixes */
    x265_param*   (*param_alloc)(void);
    void          (*param_free)(x265_param*);
    void          (*param_default)(x265_param*);
    int           (*param_parse)(x265_param*, const char*, const char*);
    int           (*param_apply_profile)(x265_param*, const char*);
    int           (*param_default_preset)(x265_param*, const char*, const char *);
    x265_picture* (*picture_alloc)(void);
    void          (*picture_free)(x265_picture*);
    void          (*picture_init)(x265_param*, x265_picture*);
    x265_encoder* (*encoder_open)(x265_param*);
    void          (*encoder_parameters)(x265_encoder*, x265_param*);
    int           (*encoder_reconfig)(x265_encoder*, x265_param*);
    int           (*encoder_headers)(x265_encoder*, x265_nal**, unsigned int*);
    int           (*encoder_encode)(x265_encoder*, x265_nal**, unsigned int*, x265_picture*, x265_picture*);
    void          (*encoder_get_stats)(x265_encoder*, x265_stats*, unsigned int);
    void          (*encoder_log)(x265_encoder*, int, char**);
    void          (*encoder_close)(x265_encoder*);
    void          (*cleanup)(void);

    int           sizeof_frame_stats;   /* sizeof(x265_frame_stats) */
    int           (*encoder_intra_refresh)(x265_encoder*);
    /* add ___new pointers to the end, or increment X265_MAJOR_VERSION */
} x265_api;

/* Force a link error in the case of linking against an incompatible API version.
 * Glue #defines exist to force correct macro expansion; the final output of the macro
 * is x265_api_get_##X265_BUILD (for purposes of dlopen). */
#define x265_api_glue1(x, y) x ## y
#define x265_api_glue2(x, y) x265_api_glue1(x, y)
#define x265_api_get x265_api_glue2(x265_api_get_, X265_BUILD)

/* x265_api_get:
 *   Retrieve the programming interface for a linked x265 library.
 *   May return NULL if no library is available that supports the
 *   requested bit depth. If bitDepth is 0 the function is guarunteed
 *   to return a non-NULL x265_api pointer, from the linked libx265.
 *
 *   If the requested bitDepth is not supported by the linked libx265,
 *   it will attempt to dynamically bind x265_api_get() from a shared
 *   library with an appropriate name:
 *     8bit:  libx265_main.so
 *     10bit: libx265_main10.so
 *   Obviously the shared library file extension is platform specific */
const x265_api* x265_api_get(int bitDepth);

/* x265_api_query:
 *   Retrieve the programming interface for a linked x265 library, like
 *   x265_api_get(), except this function accepts X265_BUILD as the second
 *   argument rather than using the build number as part of the function name.
 *   Applications which dynamically link to libx265 can use this interface to
 *   query the library API and achieve a relative amount of version skew
 *   flexibility. The function may return NULL if the library determines that
 *   the apiVersion that your application was compiled against is not compatible
 *   with the library you have linked with.
 *
 *   api_major_version will be incremented any time non-backward compatible
 *   changes are made to any public structures or functions. If
 *   api_major_version does not match X265_MAJOR_VERSION from the x265.h your
 *   application compiled against, your application must not use the returned
 *   x265_api pointer.
 *
 *   Users of this API *must* also validate the sizes of any structures which
 *   are not treated as opaque in application code. For instance, if your
 *   application dereferences a x265_param pointer, then it must check that
 *   api->sizeof_param matches the sizeof(x265_param) that your application
 *   compiled with. */
const x265_api* x265_api_query(int bitDepth, int apiVersion, int* err);

#define X265_API_QUERY_ERR_NONE           0 /* returned API pointer is non-NULL */
#define X265_API_QUERY_ERR_VER_REFUSED    1 /* incompatible version skew        */
#define X265_API_QUERY_ERR_LIB_NOT_FOUND  2 /* libx265_main10 not found, for ex */
#define X265_API_QUERY_ERR_FUNC_NOT_FOUND 3 /* unable to bind x265_api_query    */
#define X265_API_QUERY_ERR_WRONG_BITDEPTH 4 /* libx265_main10 not 10bit, for ex */

static const char * const x265_api_query_errnames[] = {
    "api queried from libx265",
    "libx265 version is not compatible with this application",
    "unable to bind a libx265 with requested bit depth",
    "unable to bind x265_api_query from libx265",
    "libx265 has an invalid bitdepth"
};

#ifdef __cplusplus
}
#endif

#endif // X265_H

#ifndef HAMSHIELD_H_
#define HAMSHIELD_H_

/* Device Registers ----------------------------------------------- */

/* Setting frequency */
#define HAM_FREQ_HI_REG                 0x29
#define HAM_FREQ_LO_REG                 0x2A

/* setting RF band */
#define HAM_RF_BAND_REG                 0x0F

/* Reference clock */
#define HAM_XTAL_FREQ_REG               0x2B
#define HAM_ADCLK_FREQ_REG              0x2C
#define HAM_CLK_MODE_REG                0x04

/* Setting TX and RX */
#define HAM_CTRL_REG                    0x30

/* TX voice channel */
#define HAM_TX_VCH_REG                  0x3C

/* TX Pa_bias output voltage reg         */
#define HAM_TX_PA_BIAS_REG              0x0A

/* Subaudio registers*/
#define HAM_SUBAUDIO_REG                0x45
#define HAM_CTCSS_FREQ_REG              0x4A
#define HAM_CDSS_CODE_HI_REG            0x4B
#define HAM_CDSS_CODE_LO_REG            0x4C 

/* SQ */
#define HAM_SQ_OPEN_THRESH_REG          0x48
#define HAM_SQ_SHUT_THRESH_REG          0x49
#define HAM_SQ_OUT_SEL_REG              0x54

/* VOX */
#define HAM_VOX_OPEN_THRESH_REG         0x41
#define HAM_VOX_SHUT_THRESH_REG         0x42

/* DTMF */
#define HAM_DTMF_TIME_REG               0x63
#define HAM_TONE1_FREQ_REG              0x35
#define HAM_TONE2_FREQ_REG              0x36
#define HAM_FLAG_REG                    0x5C
#define HAM_DTMF_C01_REG                0x66
#define HAM_DTMF_C23_REG                0x67
#define HAM_DTMF_C45_REG                0x68
#define HAM_DTMF_C67_REG                0x69
#define HAM_DTMF_STATUS_REG             0x6C

/* Tx FM deviation */
#define HAM_TX_FM_REG                   0x43

/* Rx voice range*/
#define HAM_RX_VR_REG                   0x44

/* GPIO */
#define HAM_GPIO_REG                    0x1F

/* INT */
#define HAM_INT_REG                     0x2d

#define HAM_RSSI_REG                    0x5F
#define HAM_VSSI_REG                    0x60

/* Bitfields ---------------------------------------------------*/
/* HAM_CTRL_REG 0x30 */
#define HAM_CTRL_SOFT_RESET_BIT         0  
#define HAM_CTRL_CHIP_CAL_EN_BIT        1
#define HAM_CTRL_PWR_DWN_BIT            2
#define HAM_CTRL_SQ_ON_BIT              3
#define HAM_CTRL_VOX_ON_BIT             4
#define HAM_CTRL_RX_ON_BIT              5
#define HAM_CTRL_TX_ON_BIT              6
#define HAM_CTRL_MUTE_BIT               7
#define HAM_CTRL_ST_MODE_BIT            8   /* <9:8> */ 
#define HAM_CTRL_TAIL_ELIM_EN_BIT       11
#define HAM_CTRL_CHN_MODE_BIT           12

#define HAM_CTRL_ST_MODE_MASK           (0x3U << HAM_CTRL_ST_MODE_BIT)



/* HAM_CLK_MODE_REG - 0x04 */
#define HAM_CLK_MODE_BIT                0

/* HAM_TX_PA_BIAS_REG - 0xA */
#define HAM_PA_BIAS_BIT                 0   /* <5:0> */
#define HAM_PA_BIAS_BIT_MASK             (0x3F << HAM_PA_BIAS_BIT)

/* HAM_RF_BAND_REG - 0xF */
#define HAM_RF_BAND_SELECT_BIT          6   /* <7:6> */
#define HAM_RF_BAND_SELECT_MASK         (0x3U << HAM_RF_BAND_SELECT_BIT)

/* HAM_TX_VCH_REG - 0x3 */
#define HAM_TX_VCH_BIT                  14  /* <15:14> */

/* HAM_SUBAUDIO_REG - 0x45 */
#define HAM_SUBAUDIO_C_MODE_BIT         0   /* <2:0> */
#define HAM_SUBAUDIO_C_MODE_MASK        (0x7U << HAM_SUBAUDIO_C_MODE_BIT)
#define HAM_SUBAUDIO_CDSS_SEL_BIT       4
#define HAM_SUBAUDIO_NEG_DET_EN_BIT     7
#define HAM_SUBAUDIO_CSS_DET_EN_BIT     10
#define HAM_SUBAUDIO_POS_DET_EN_BIT     11
#define HAM_SUBAUDIO_SHIFT_SEL_BIT      14  /* <15:14> */
#define HAM_SUBAUDIO_SHIFT_SEL_MASK     (0x3U << HAM_SUBAUDIO_SHIFT_SEL_BIT)

 /* HAM_SQ_OUT_SEL_REG - 0x54 */
 #define HAM_SQ_OUT_SEL_BIT             7

 /* HAM_DTMF_TIME_REG - 0x63 */
 #define HAM_DTMF_TIME_2                0   /* <3:0> */
 #define HAM_DTMF_TIME_1                4   /* <7:4> */
 #define HAM_DTMF_EN                    8   
 #define HAM_DTMF_SINGLE_TONE           9
 
 /* HAM_DTMF_C01_ReG - 0x66*/
 #define HAM_DTMF_C1_BIT                0   /* <7:0> */
 #define HAM_DTMF_C0_BIT                8   /* <15:8> */

 /* HAM_DTMF_C23_REG - 0x67 */
 #define HAM_DTMF_C3_BIT                0   /* <7:0> */
 #define HAM_DTMF_C2_BIT                8   /* <15:8> */

/* HAM_DTMF_C45_REG - 0x68 */
 #define HAM_DTMF_C5_BIT                0   /* <7:0> */
 #define HAM_DTMF_C4_BIT                8   /* <15:8> */

/* HAM_DTMF_C67_REG - 0x69 */
 #define HAM_DTMF_C7_BIT                0   /* <7:0> */
 #define HAM_DTMF_C6_BIT                8   /* <15:8> */



#endif

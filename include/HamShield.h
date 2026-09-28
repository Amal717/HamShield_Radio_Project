#ifndef HAMSHIELD_H_
#define HAMSHIELD_H_

#include <stdint.h>

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
#define HAM_CDCSS_CODE_HI_REG           0x4B
#define HAM_CDCSS_CODE_HI_BIT           16
#define HAM_CDCSS_CODE_LO_REG           0x4C

/* SQ */
#define HAM_SQ_OPEN_THRESH_REG          0x48
#define HAM_SQ_OPEN_THRESH_BIT          3
#define HAM_SQ_SHUT_THRESH_REG          0x49
#define HAM_SQ_SHUT_THRESH_BIT          3
#define HAM_SQ_THRESH_OFFSET            135
#define HAM_SQ_OUT_SEL_REG              0x54

/* VOX */
#define HAM_VOX_OPEN_THRESH_REG         0x41
#define HAM_VOX_SHUT_THRESH_REG         0x42
#define HAM_VOX_THRESH_SCALE            225

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
#define HAM_TX_FM_VOICE_DEV_BIT         6
#define HAM_TX_FM_CTCSS_CDCSS_DEV_BIT   0

/* Rx voice range*/
#define HAM_RX_VR_REG                   0x44
#define HAM_RX_VR_VOLUME1_BIT           4
#define HAM_RX_VR_VOLUME2_BIT           0

/* RX code cfg */
#define HAM_RX_CODE_CFG_REG             0x4D

/* Voice Filter Bypass */
#define HAM_VOICE_FILTER_REG            0x58

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

/* HAM_TX_VCH_REG - 0x3C */
#define HAM_TX_VCH_BIT                  14  /* <15:14> */

/* HAM_SUBAUDIO_REG - 0x45 */
#define HAM_SUBAUDIO_C_MODE_BIT         0   /* <2:0> */
#define HAM_SUBAUDIO_C_MODE_MASK        (0x7U << HAM_SUBAUDIO_C_MODE_BIT)
#define HAM_SUBAUDIO_CTCSS_SEL_BIT      3
#define HAM_SUBAUDIO_CDCSS_SEL_BIT      4
#define HAM_SUBAUDIO_NEG_DET_EN_BIT     7
#define HAM_SUBAUDIO_CSS_DET_EN_BIT     10
#define HAM_SUBAUDIO_POS_DET_EN_BIT     11
#define HAM_SUBAUDIO_SHIFT_SEL_BIT      14  /* <15:14> */
#define HAM_SUBAUDIO_SHIFT_SEL_MASK     (0x3U << HAM_SUBAUDIO_SHIFT_SEL_BIT)

/* HAM_RX_CODE_CFG_REG - 0x4D */
#define HAM_RX_CODE_CFG_BIT             10

/* HAM_GPIO_REG - 0x1FH */
#define HAM_GPIO0_BIT                   0   /* <1:0> */
#define HAM_GPIO1_BIT                   2   /* <3:2> */
#define HAM_GPIO2_BIT                   4   /* <5:4> */
#define HAM_GPIO3_BIT                   6   /* <7:6> */
#define HAM_GPIO4_BIT                   8   /* <9:8> */
#define HAM_GPIO5_BIT                   10  /* <11:10> */
#define HAM_GPIO6_BIT                   12  /* <13:12> */
#define HAM_GPIO7_BIT                   14  /* <15:14> */

/* HAM_SQ_OUT_SEL_REG - 0x54 */
#define HAM_SQ_OUT_SEL_BIT              7

/* HAM_VOICE_FILTER_REG - 0x58 */
#define HAM_VOICE_PRE_DE_EMPH_BIT       3

/* HAM_DTMF_TIME_REG - 0x63 */
#define HAM_DTMF_TIME_2                 0   /* <3:0> */
#define HAM_DTMF_TIME_1                 4   /* <7:4> */
#define HAM_DTMF_EN                     8
#define HAM_DTMF_SINGLE_TONE            9

/* HAM_DTMF_C01_ReG - 0x66*/
#define HAM_DTMF_C1_BIT                 0   /* <7:0> */
#define HAM_DTMF_C0_BIT                 8   /* <15:8> */

/* HAM_DTMF_C23_REG - 0x67 */
#define HAM_DTMF_C3_BIT                 0   /* <7:0> */
#define HAM_DTMF_C2_BIT                 8   /* <15:8> */

/* HAM_DTMF_C45_REG - 0x68 */
#define HAM_DTMF_C5_BIT                 0   /* <7:0> */
#define HAM_DTMF_C4_BIT                 8   /* <15:8> */

/* HAM_DTMF_C67_REG - 0x69 */
#define HAM_DTMF_C7_BIT                 0   /* <7:0> */
#define HAM_DTMF_C6_BIT                 8   /* <15:8> */

/* HAM_RSSI_REG - 0x5F */
#define HAM_RSSI_BIT                    0   /* <9:0> */

/* HAM_VSSI_REG - 0x60 */
#define HAM_VSSI_BIT                    0   /* <14:0> */

typedef enum {
    RF_BAND_400_520_MHZ = 0,
    RF_BAND_200_260_MHZ,
    RF_BAND_134_174_MHZ,
}rf_band_t;

typedef enum {
    TX_ON = 0,
    TX_OFF,
}tx_mode_t;

typedef enum {
   RX_ON = 0,
   RX_OFF,
}rx_mode_t;

typedef enum {
    TX_VOICE_MIC = 0,
    TX_INNER_SINE,
    TX_CODE_GPIO1,
    NOT_ANY_SIGNAL
}tx_voice_channel_t;

typedef enum {
    PA_BIAS_1_01V = 0,
    PA_BIAS_1_05V,
    PA_BIAS_1_09V,
    PA_BIAS_1_18V,
    PA_BIAS_1_34V,
    PA_BIAS_1_68V,
    PA_BIAS_2_45V,
    PA_BIAS_3_13V
}pa_bias_volage_t;


typedef enum {
    C_MODE_DISABLE = 0,
    INNER_CTCSS_EN,
    INNER_CDCSS_EN,
    OUTTER_CTCSS_EN,
    OUTTER_CDCSS_EN
}c_mode_t;

typedef enum {
    CTCSS_CDCSS_CMP_OUT = 0,
    CTCSS_CDCSS_SDO_OUT
}ctcss_sel_t;

typedef enum {
    BIT_24= 0,
    BIT_23
}cdcss_sel_t;

typedef enum {
    NEG_DET_ENABLE = 0,
    NEG_DET_DISABLE,
}neg_det_t;

typedef enum {
    POS_DET_ENABLE = 0,
    POS_DET_DISABLE,
}pos_det_t;

typedef enum {
    CSS_DET_ENABLE = 0,
    CSS_DET_DISABLE,
}css_det_t;

typedef enum {
    SQ_ON = 0,
    SQ_OFF
}sq_t;

typedef enum {
    SQ_AND_CSS_OUT = 0,
    SQ_OUT_ONLY,
}sq_out_t;

typedef enum {
   VOX_ON = 0,
   VOX_OFF,
}vox_t;

typedef enum {
    TAIL_ELIM_ENABLE = 0,
    TAIL_ELIM_DISABLE,
}tail_elim_t;

typedef enum {
    SHIFT_120_DEGREE = 0,
    SHIFT_180_DEGREE,
    SHIFT_240_DEGREE,
}tail_elim_shift_t;

typedef enum {
    RX_VOLUME_1 = 0,
    RX_VOLUME_2,
}rx_vol_t;

typedef enum {
    GPIO0_HI_IMPEDANCE = 0,
    GPIO0_CSS_IN_OUT_CSS_CMP,
    GPIO0_LOW,
    GPIO0_HIGH
}gpio0_mode_t;

typedef enum {
    GPIO1_HI_IMPEDANCE = 0,
    GPIO1_CODE_OUT_CODE_IN,
    GPIO1_LOW,
    GPIO1_HIGH
}gpio1_mode_t;

typedef enum {
    GPIO2_HI_IMPEDANCE = 0,
    GPIO2_RX_ON_RF,
    GPIO2_LOW,
    GPIO2_HIGH
}gpio2_mode_t;

typedef enum {
    GPIO3_HI_IMPEDANCE = 0,
    GPIO3_SDO,
    GPIO3_LOW,
    GPIO3_HIGH
}gpio3_mode_t;

typedef enum {
    GPIO4_HI_IMPEDANCE = 0,
    GPIO4_RX_ON_RF,
    GPIO4_LOW,
    GPIO4_HIGH
}gpio4_mode_t;

typedef enum {
    GPIO5_HI_IMPEDANCE = 0,
    GPIO5_TX_ON_RF,
    GPIO5_LOW,
    GPIO5_HIGH
}gpio5_mode_t;

typedef enum {
    GPIO6_HI_IMPEDANCE = 0,
    GPIO6_SQ,
    GPIO6_LOW,
    GPIO6_HIGH
}gpio6_mode_t;

typedef enum {
    GPIO7_HI_IMPEDANCE = 0,
    GPIO7_VOX,
    GPIO7_LOW,
    GPIO7_HIGH
}gpio7_mode_t;

typedef enum {
    PRE_DE_EMPH_NORMAL= 0,
    PRE_DE_EMPH_BYPASS,
}pre_emph_mode_t;

void ham_soft_reset(void);
void ham_set_frequency(float freq_in_mhz);
void ham_set_rf_band(rf_band_t band);
void ham_set_reference_clock(float crystal_mhz);
void ham_set_transmitter(tx_mode_t mode);
void ham_set_receiver(rx_mode_t mode);
void ham_set_tx_voice_ch(tx_voice_channel_t mode);
void ham_set_pa_bias(pa_bias_volage_t vol_sel);
void ham_subaudio_set_c_mode(c_mode_t mode_sel);
void ham_subaudio_set_ctss_mode(ctcss_sel_t mode);
void ham_subaudio_set_cdss_mode(cdcss_sel_t mode);
void ham_subaudio_neg_det_en(neg_det_t mode);
void ham_subaudio_pos_det_en(pos_det_t mode);
void ham_subaudio_css_det_en(css_det_t mode);
void ham_subaudio_set_freq(float freq_in_hz);
void ham_subaudio_set_cdcss_code(uint32_t cdcss_code);
void ham_set_sq(sq_t mode);
void ham_set_sq_open_threshold(int16_t threshold_dbm);
void ham_set_sq_shut_threshold(int16_t threshold_dbm);
void ham_set_vox(vox_t mode);
void ham_set_vox_open_threshold(uint16_t threshold_mv);
void ham_set_vox_shut_threshold(uint16_t threshold_mv);
void ham_set_tail_elim(tail_elim_t mode);
void ham_set_tail_elim_shift(tail_elim_shift_t mode);
void ham_set_tx_voice_dev(uint8_t dev);
void ham_set_tx_ctcss_cdcss_dev(uint8_t dev);
void set_rx_voice_range(rx_vol_t volume, uint8_t attenuation);
void ham_gpio0_set_mode(gpio0_mode_t mode);
void ham_gpio1_set_mode(gpio1_mode_t mode);
void ham_gpio2_set_mode(gpio2_mode_t mode);
void ham_gpio3_set_mode(gpio3_mode_t mode);
void ham_gpio4_set_mode(gpio4_mode_t mode);
void ham_gpio5_set_mode(gpio5_mode_t mode);
void ham_gpio6_set_mode(gpio6_mode_t mode);
void ham_gpio7_set_mode(gpio7_mode_t mode);
void set_pre_emphasis_filter(pre_emph_mode_t mode);
uint16_t ham_get_rssi();
uint16_t ham_get_vssi();
uint8_t ham_get_tx_on_status();
uint8_t ham_get_rx_on_status();

#endif

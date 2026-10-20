#ifndef HAMSHIELD_ENUMS_H_
#define HAMSHIELD_ENUMS_H_

/* reference clock */

typedef enum {
    XTAL_MODE_13_MHZ_26_MHZ = 1,
    XTAL_MODE_12_8_MHZ_25_6MHZ = 0
}xtal_mode_t;

typedef enum {
    CLK_MODE_12_8_MHZ_13_MHZ = 1,
    CLK_MODE_25_6_MHZ_26_MHZ = 0
}clock_mode_t;

/* setting TX and RX */
typedef enum {
    FILTER_BAND_25_KHZ = 1,
    FILTER_BAND_12_5_KHZ = 0
}filter_band_t ;

typedef enum {
    DSP_BAND_25_KHZ = 1,
    DSP_BAND_12_5_KHZ = 0
}dsp_band_t;

typedef enum {
    RX_ON = 1,
    RX_OFF = 0
}rx_mode_t;

typedef enum {
    TX_ON = 1,
    TX_OFF = 0
}tx_mode_t;

typedef enum {
    PWR_ON = 1,
    PWR_OFF = 0,
}pwr_mode_t;

typedef enum {
    TX_NOTHING = 0,
    TX_FREQ_TONE_1,
    TX_FREQ_TONE_2,
    TX_FREQ_TONE_1_AND_2,
    TX_MICROPHONE
}tx_voice_sel_t;

typedef enum {
    PA_BIAS_1_04V = 0,
    PA_BIAS_1_05V = 1,
    PA_BIAS_1_07V = 2,
    PA_BIAS_1_10V = 4,
    PA_BIAS_1_22V = 8,
    PA_BIAS_1_52V = 16,
    PA_BIAS_2_14V = 32,
    PA_BIAS_3_28V = 63
}pa_bias_voltage_t;

typedef enum {
    NO_PHASE_SHIFT = 0,
    SHIFT_PHASE_120,
    SHIFT_PHASE_180,
    SHIFT_PHASE_240,
}shift_t ;

typedef enum {
    CTCSS_MODE_TX = 3,
    CDCSS_MODE_TX = 2,
    CTCSS_CDCSS_GPIO0 = 1,
    NO_CTCSS_CDCSS_TX = 0
}ctcss_cdcss_sel_t;

typedef enum {
    CTCSS_CDCSS_WAVE_GPIO0 = 1,
    CTCSS_CDCSS_COMPARED_GPIO0 = 0,
}ctcss_cdcss_out_t;

typedef enum {
    DETECT_PHASE_SHIFT  = 4,
    DETECT_CTCSS_2_FREQ = 3,
    DETECT_INVERT_CDCSS = 2,
    DETECT_NORMAL_CDCSS = 1,
    DETECT_CTCSS_1_FREQ = 0
}ctcss_cdcss_det_en_t;

typedef enum {
    TAIL_ELIM_ENABLE = 1,
    TAIL_ELIM_DISABLE = 0,
}tail_elim_t;

typedef enum {
    AUTO_SQ_ENABLE = 1,
    AUTO_SQ_DISABLE = 0,
}rx_sq_t ;

typedef enum {
    RSSI_DET_ENABLE = 6,
    NOISE_DET_ENABLE = 7,
    RSSI_NOISE_ENABLE = 8,
    ADJACENT_CH_DET_ENABLE = 9,
    FM_MOD_SIGNAL_ENABLE = 0
}sq_det_enable_t;

typedef enum {
    RSSI_DET_DISABLE = 6,
    NOISE_DET_DISABLE = 7,
    RSSI_NOISE_DISABLE = 8,
    ADJACENT_CH_DET_DISABLE = 9,
    FM_MOD_SIGNAL_DISABLE = 0
}sq_det_disable_t;

typedef enum {
    SQ_CMP_SUB_AUDIO_CMP_GPIO6 = 1,
    SQ_CMP_GPIO6 = 0
}sq_out_t;

#endif

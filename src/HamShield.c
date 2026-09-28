#include "HamShield.h"
#include "Arduino.h"
#include "HamShield_comms.h"

uint8_t pa_bias_vol[] = {
    0b000000,
    0b000001,
    0b000010,
    0b000100,
    0b001000,
    0b010000,
    0b100000,
    0b111111,
};


uint8_t c_mode_arr[] = {
    0b000,
    0b001,
    0b010,
    0b101,
    0b110
};

void ham_soft_reset(void)
{
    HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_SOFT_RESET_BIT, 0b1);
}

void ham_set_frequency(float freq_in_mhz)
{
    uint32_t freq_khz = freq_in_mhz * 1000;
    uint32_t freq = freq_khz << 3;

    uint16_t freq_hi = freq >> 16;
    uint16_t freq_lo = freq & 0xFFFF;

    HSwriteWord(nSEN, HAM_FREQ_HI_REG, freq_hi);
    HSwriteWord(nSEN, HAM_FREQ_LO_REG, freq_lo);
}

void ham_set_rf_band(rf_band_t band)
{
    switch (band) {

        case RF_BAND_400_520_MHZ:
            HSwriteBitsW(nSEN, HAM_RF_BAND_REG, HAM_RF_BAND_SELECT_BIT, 2, 0b00);
            break;

        case RF_BAND_200_260_MHZ:
            HSwriteBitsW(nSEN, HAM_RF_BAND_REG, HAM_RF_BAND_SELECT_BIT, 2, 0b10);
            break;

        case RF_BAND_134_174_MHZ:
            HSwriteBitsW(nSEN, HAM_RF_BAND_REG, HAM_RF_BAND_SELECT_BIT, 2, 0b11);
            break;

        default:
            /* Do nothing */
            break;
    }
}

void ham_set_reference_clock(float crystal_mhz)
{
    uint32_t xtal_khz;
    uint32_t adclk_khz;


    if (crystal_mhz >= 12 && crystal_mhz <= 14) {

        xtal_khz = (crystal_mhz * 1000);
        adclk_khz = (crystal_mhz / 2) * 1000;
        HSwriteWord(nSEN, HAM_XTAL_FREQ_REG, xtal_khz);
        HSwriteWord(nSEN, HAM_ADCLK_FREQ_REG, adclk_khz);
        HSwriteBitsW(nSEN, HAM_CLK_MODE_REG, HAM_CLK_MODE_BIT, 1, 0b1);
    }
    else if (crystal_mhz >= 24 && crystal_mhz <= 28) {

        xtal_khz  = (crystal_mhz / 2) * 1000;
        adclk_khz = (crystal_mhz / 4) * 1000;
        HSwriteWord(nSEN, HAM_XTAL_FREQ_REG, xtal_khz);
        HSwriteWord(nSEN, HAM_ADCLK_FREQ_REG, adclk_khz);
        HSwriteBitsW(nSEN, HAM_CLK_MODE_REG, HAM_CLK_MODE_BIT, 1, 0b0);
    }
}

void ham_set_transmitter(tx_mode_t mode)
{
    switch (mode) {
        case TX_ON:
            HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_TX_ON_BIT, 0b1);
            break;

        case TX_OFF:
            HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_TX_ON_BIT, 0b0);
            break;

        default:
            /* Do nothing */
            break;
    }
}

void ham_set_receiver(rx_mode_t mode)
{
    switch (mode) {
        case RX_ON:
            HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_RX_ON_BIT, 0b1);
            break;

        case RX_OFF:
            HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_RX_ON_BIT, 0b0);
            break;

        default:
            /* Do nothing */
            break;
    }
}

void ham_set_tx_voice_ch(tx_voice_channel_t mode)
{
    switch (mode) {
        case TX_VOICE_MIC:
            HSwriteBitsW(nSEN, HAM_TX_VCH_REG, HAM_TX_VCH_BIT, 2, 0b00);
            break;

        case TX_INNER_SINE:
            HSwriteBitsW(nSEN, HAM_TX_VCH_REG, HAM_TX_VCH_BIT, 2, 0b01);
            break;

        case TX_CODE_GPIO1:
            HSwriteBitsW(nSEN, HAM_TX_VCH_REG, HAM_TX_VCH_BIT, 2, 0b10);
            break;

        case NOT_ANY_SIGNAL:
            HSwriteBitsW(nSEN, HAM_TX_VCH_REG, HAM_TX_VCH_BIT, 2, 0b11);
            break;

        default:
            /* Do nothing */
            break;

    }
}

void ham_set_pa_bias(pa_bias_volage_t vol_sel)
{
   uint8_t bias_mode = pa_bias_vol[vol_sel];
   HSwriteBitsW(nSEN, HAM_TX_PA_BIAS_REG, HAM_PA_BIAS_BIT, 6, bias_mode);
}

void ham_subaudio_set_c_mode(c_mode_t mode_sel)
{
    uint8_t c_mode = c_mode_arr[mode_sel];
    HSwriteBitsW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_C_MODE_BIT, 3, c_mode);
}

void ham_subaudio_set_ctss_mode(ctcss_sel_t mode)
{
    if (mode == CTCSS_CDCSS_CMP_OUT)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_CTCSS_SEL_BIT, 0b1);
    else if (mode == CTCSS_CDCSS_SDO_OUT)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_CTCSS_SEL_BIT, 0b0);
}

void ham_subaudio_set_cdss_mode(cdcss_sel_t mode)
{
    if (mode == BIT_24)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_CDCSS_SEL_BIT, 0b1);
    else if (mode == BIT_23)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_CDCSS_SEL_BIT, 0b0);
}

void ham_subaudio_neg_det_en(neg_det_t mode)
{
    if (mode == NEG_DET_ENABLE)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_NEG_DET_EN_BIT, 0b1);
    else if (mode == NEG_DET_DISABLE)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_NEG_DET_EN_BIT, 0b0);
}

void ham_subaudio_pos_det_en(pos_det_t mode)
{
    if (mode == POS_DET_ENABLE)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_POS_DET_EN_BIT, 0b1);
    else if (mode == POS_DET_DISABLE)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_POS_DET_EN_BIT, 0b0);
}

void ham_subaudio_css_det_en(css_det_t mode)
{
    if (mode == CSS_DET_ENABLE)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_CSS_DET_EN_BIT, 0b1);
    else if (mode == CSS_DET_DISABLE)
        HSwriteBitW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_CSS_DET_EN_BIT, 0b0);
}

void ham_subaudio_set_freq(float freq_in_hz)
{
    uint16_t ctcss_freq = (freq_in_hz / 1000.0f) * (1UL << 16);
    HSwriteWord(nSEN, HAM_CTCSS_FREQ_REG, ctcss_freq);
}


void ham_subaudio_set_cdcss_code(uint32_t cdcss_code)
{
    uint8_t cdcss_code_hi = cdcss_code >> 16;
    uint16_t cdcss_code_lo = cdcss_code & 0xFFFF;

    HSwriteBitsW(nSEN, HAM_CDCSS_CODE_HI_REG, HAM_CDCSS_CODE_HI_BIT, 8, cdcss_code_hi);
    HSwriteWord(nSEN, HAM_CDCSS_CODE_LO_REG, cdcss_code_lo);
}

void ham_set_sq(sq_t mode)
{
    if (mode == SQ_ON)
        HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_SQ_ON_BIT, 0b1);
    else if (mode == SQ_OFF)
        HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_SQ_ON_BIT, 0b0);
}

void ham_set_sq_open_threshold(int16_t threshold_dbm)
{
    uint8_t threshold = (uint8_t)(HAM_SQ_THRESH_OFFSET + threshold_dbm);
    HSwriteBitsW(nSEN, HAM_SQ_OPEN_THRESH_REG, HAM_SQ_OPEN_THRESH_BIT, 7, threshold);
}

void ham_set_sq_shut_threshold(int16_t threshold_dbm)
{
    uint8_t threshold = (uint8_t)(HAM_SQ_THRESH_OFFSET + threshold_dbm);
    HSwriteBitsW(nSEN, HAM_SQ_SHUT_THRESH_REG, HAM_SQ_SHUT_THRESH_BIT, 7, threshold);
}

void ham_sq_out_sel(sq_out_t mode)
{
    if (mode == SQ_AND_CSS_OUT)
        HSwriteBitW(nSEN, HAM_SQ_OUT_SEL_REG, HAM_SQ_OUT_SEL_BIT, 0b1);
    else if (mode == SQ_OUT_ONLY)
        HSwriteBitW(nSEN, HAM_SQ_OUT_SEL_REG, HAM_SQ_OUT_SEL_BIT, 0b0);
}

void ham_set_vox(vox_t mode)
{
    if (mode == VOX_ON)
        HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_VOX_ON_BIT, 0b1);
    else if (mode == VOX_OFF)
        HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_VOX_ON_BIT, 0b0);
}

void ham_set_vox_open_threshold(uint16_t threshold_mv)
{
   uint16_t threshold = HAM_VOX_THRESH_SCALE * threshold_mv;
   HSwriteWord(nSEN, HAM_VOX_OPEN_THRESH_REG,  threshold);
}

void ham_set_vox_shut_threshold(uint16_t threshold_mv)
{
    uint16_t threshold = HAM_VOX_THRESH_SCALE * threshold_mv;
    HSwriteWord(nSEN, HAM_VOX_SHUT_THRESH_REG, threshold);
}

void ham_set_tail_elim(tail_elim_t mode)
{
    if (mode == TAIL_ELIM_ENABLE)
        HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_TAIL_ELIM_EN_BIT, 0b1);
    else if (mode == TAIL_ELIM_DISABLE)
        HSwriteBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_TAIL_ELIM_EN_BIT, 0b0);
}

void ham_set_tail_elim_shift(tail_elim_shift_t mode)
{
    switch (mode) {

        case SHIFT_120_DEGREE:
            HSwriteBitsW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_SHIFT_SEL_BIT, 2, 0b00);
            break;

        case SHIFT_180_DEGREE:
            HSwriteBitsW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_SHIFT_SEL_BIT, 2, 0b01);
            break;

        case SHIFT_240_DEGREE:
            HSwriteBitsW(nSEN, HAM_SUBAUDIO_REG, HAM_SUBAUDIO_SHIFT_SEL_BIT, 2, 0b10);
            break;

        default:
            /* Do Nothing */
            break;
    }
}

void ham_set_tx_voice_dev(uint8_t dev)
{
    dev = dev & 0x7F;
    HSwriteBitsW(nSEN, HAM_TX_FM_REG, HAM_TX_FM_VOICE_DEV_BIT, 7, dev);
}

void ham_set_tx_ctcss_cdcss_dev(uint8_t dev)
{
    dev = dev & (0x3F);
    HSwriteBitsW(nSEN, HAM_TX_FM_REG, HAM_TX_FM_CTCSS_CDCSS_DEV_BIT, 6, dev);
}

void set_rx_voice_range(rx_vol_t volume, uint8_t attenuation)
{
    if (attenuation <= 15) {
        uint8_t db_value = (15 - attenuation) & 0xF;

        if (volume == RX_VOLUME_1)
            HSwriteBitsW(nSEN, HAM_RX_VR_REG, HAM_RX_VR_VOLUME1_BIT, 4, db_value);
        else if (volume == RX_VOLUME_2)
            HSwriteBitsW(nSEN, HAM_RX_VR_REG, HAM_RX_VR_VOLUME2_BIT, 4, db_value);
    }
}

void ham_gpio0_set_mode(gpio0_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO0_BIT, 2, mode);
}
void ham_gpio1_set_mode(gpio1_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO1_BIT, 2, mode);
}


void ham_gpio2_set_mode(gpio2_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO2_BIT, 2, mode);
}
void ham_gpio3_set_mode(gpio3_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO3_BIT, 2, mode);
}
void ham_gpio4_set_mode(gpio4_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO4_BIT, 2, mode);
}

void ham_gpio5_set_mode(gpio5_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO5_BIT, 2, mode);
}

void ham_gpio6_set_mode(gpio6_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO6_BIT, 2, mode);
}

void ham_gpio7_set_mode(gpio7_mode_t mode)
{
    HSwriteBitsW(nSEN, HAM_GPIO_REG, HAM_GPIO7_BIT, 2, mode);
}

void set_pre_emphasis_filter(pre_emph_mode_t mode)
{
    if (mode == PRE_DE_EMPH_BYPASS)
        HSwriteBitW(nSEN, HAM_VOICE_FILTER_REG, HAM_VOICE_PRE_DE_EMPH_BIT, 0b1);
    else if (mode == PRE_DE_EMPH_NORMAL)
        HSwriteBitW(nSEN, HAM_VOICE_FILTER_REG, HAM_VOICE_PRE_DE_EMPH_BIT, 0b0);
}

uint16_t ham_get_rssi()
{
    uint16_t rssi = 0;
    HSreadBitsW(nSEN, HAM_RSSI_REG, HAM_RSSI_BIT, 10, &rssi);
    return rssi;
}

uint16_t ham_get_vssi()
{
    uint16_t vssi = 0;
    HSreadBitsW(nSEN, HAM_VSSI_REG, HAM_VSSI_BIT, 15, &vssi);
    return vssi;
}

uint8_t ham_get_tx_on_status()
{
    uint16_t tx_on;
    HSreadBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_TX_ON_BIT, &tx_on);
    return tx_on;
}

uint8_t ham_get_rx_on_status()
{
    uint16_t rx_on;
    HSreadBitW(nSEN, HAM_CTRL_REG, HAM_CTRL_RX_ON_BIT, &rx_on);
    return rx_on;
}

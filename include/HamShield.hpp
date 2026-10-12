#ifndef HAMSHIELD_H_
#define HAMSHIELD_H_

#include <stdint.h>
#include "hamShield_enums.h"

/* Device Registers and Bitfields ------------------------------------------------------- */

/* --- Frequency Register --- */
#define HAM_FREQ_HI_REG                 0x29
#define HAM_FREQ_LO_REG                 0x2A


/* --- Reference clock --- */
#define HAM_CLK_MODE_REG                0x04
#define HAM_CLK_MODE_BIT                0

/* --- Control Register --- */
#define HAM_CTRL_REG                    0x30
#define HAM_CTRL_SOFT_RESET_BIT         0
#define HAM_CTRL_CHIP_CAL_EN_BIT        1
#define HAM_CTRL_PWR_DWN_BIT            2
#define HAM_CTRL_SQ_ON_BIT              3
#define HAM_CTRL_VOX_ON_BIT             4
#define HAM_CTRL_RX_ON_BIT              5
#define HAM_CTRL_TX_ON_BIT              6
#define HAM_CTRL_MUTE_BIT               7
#define HAM_CTRL_DIRECT_REG_BIT         10
#define HAM_CTRL_TAIL_ELIM_EN_BIT       11
#define HAM_CTRL_FILTER_BAND_MODE_BIT   12
#define HAM_CTRL_FILTER_BAND_SEL_BIT    13
#define HAM_CTRL_XTAL_MODE_BIT          14

/* --- ADC Register --- */
#define HAM_ADC_REG                     0x03
#define HAM_ADC_TX_ADC_RST_EN_BIT       11
#define HAM_ADC_TX_ADC_RST_DR_BIT       12

/* --- LDO REG --- */
#define HAM_LDO_REG                     0x08
#define HAM_LDO_MASTER_BYPASS_BIT       14

/* --- LDO VOUT fegister */
#define HAM_LDO_VOUT_REG                0x09
#define HAM_LDO_VOUT_DIG_BIT            0x09

/* --- pabias register --- */
#define HAM_PABIAS_REG                  0x0A
#define HAM_PABIAS_PABIAS_VOLTAGE_BIT   0       /* [5:0] */
#define HAM_PABIAS_PGA_GAIN_BIT         6       /* [10:6] */
#define HAM_PABIAS_RF_PWR_BIT           11      /* [14:11] */

/* --- IF Filter register --- */
#define HAM_IF_FILTER_REG               0x15
#define HAM_IF_FILTER_TUNING_BIT        9       /* [12:9] */

/* --- PLL register --- */
#define HAM_PLL_REG                     0x24
#define HAM_PLL_DSP_RST_EN_BIT          6       /* [6] */
#define HAM_PLL_DSP_RST_DR_BIT          7       /* [7] */
#define HAM_PLL_RST_LOCK_DELAY_BIT      13      /* [14:13] */
#define HAM_PLL_LOCK_DET_SEL_BIT        15      /* [15] */

/* --- AGC regster ---  */
#define HAM_AGC_REG                     0x32
#define AGC_PWR_BIT                     6       /* [11:6] */

/* --- squelch register */
#define HAM_SQ_REG                      0x3A
#define HAM_SQ_CTCSS_CDCSS_DET_BIT      0       /* [4:0] */
#define HAM_SQ_CTCSS_CDCSS_OUT_SEL_BIT  5       /* [5] */
#define HAM_SQ_DET_BIT                  6       /* [10:6] */
#define HAM_SQ_OUT_SEL_BIT              11      /* [11] */
#define HAM_SQ_VOICE_SEL_BIT            12      /* [14:12] */
#define HAM_SQ_CODE_OUT_SEL_BIT         15      /* [15] */

/* --- voice digital gain register --- */
#define HAM_TX_DIG_VOICE_GAIN_REG       0x41
#define HAM_TX_DIG_VOICE_GAIN_BIT       0       /* [6:0] */

/* --- voice gain register ---  */
#define HAM_VOICE_GAIN_REG              0x44
#define HAM_VOICE_GAIN_VOLUME           0       /* [3:0] */
#define HAM_VOICE_GAIN_DAC_GAIN         4       /* [7:4] */
#define HAM_VOICE_GAIN_ADC_TX_BIT       8       /* [11:8] */

/* --- ctcss freq  register --- */
#define HAM_CTCSS_FREQ1_REG             0x4A
#define HAM_CTCSS_FREQ2_REG             0x4D

/* --- cdcss code bit register --- */
#define HAM_CDCSS_CODE_HI_REG           0x4B    /* [23:16] */
#define HAM_CDCSS_CODE_HI_BIT           0       /* [7:0] */
#define HAM_CDCSS_CODE_LOW_REG          0x4C    /* [15:0] */

/* --- squelch select register --- */
#define HAM_SQ_SEL_REG                  0x4E
#define HAM_SQ_SEL_DET_EN_BIT           0       /* [4:0] */
#define HAM_SQ_SEL_MODE_TX_BIT          5       /* [5] */
#define HAM_SQ_SEL_CDCSS_SEL_BIT        6       /* [8:6] */
#define HAM_SQ_SEL_MODE_RX_BIT          9       /* [10:9] */
#define HAM_SQ_SEL_SHIFT_SEL_BIT        14      /* [15:14] */

/* --- ctcss threshold reg --- */
#define HAM_CTCSS_THRESHOLD_REG         0x5B
#define HAM_CTCSS_THRESHOLD_OUT_BIT     0       /* [7:0] */
#define HAM_CTCSS_THRESHOLD_IN_BIT      8       /* [15:8] */

/* --- vox threshold register --- */
#define HAM_VOX_REG                     0x64
#define HAM_VOX_SHUT_THRESHOLD_BIT      0       /* [6:0] */
#define HAM_VOX_OPEN_THRESHOLD_BIT      7       /* [13:7] */

/* --- dtmf register */
#define HAM_DTMF1_REG                   0x79
#define HAM_DTMF1_TX_BIT                14
#define HAM_DTMF_DIRECT_BIT             15      /* [15] */

#define HAM_DTMF2_REG                   0x7A
#define HAM_DTMF2_EN_BIT                15      /* [15] */
#define HAM_DTMF2_SINGLE_TONE_BIT       14      /* [14] */

#define HAM_DTMF3_REG                   0x7B
#define HAM_DTMF3_TIME_IDLE_BIT         6       /* [11:6] */
#define HAM_DTMF3_TIME_DUAL_TONE_BIT    0       /* [5:0] */

/* --- tone frequency registers */
#define HAM_TONE1_FREQ_REG              0x35    /* [15:0] */
#define HAM_TONE2_FREQ_REG              0x36    /* [15:0] */







class HamShield {
    private:
        uint8_t ncs;
        uint8_t clk;
        uint8_t dat;
        uint8_t mic;

    public:
        HamShield(uint8_t ncs_pin, uint8_t clk_pin, uint8_t dat_pin, uint8_t mic_pin);
        void initialize();
        void soft_reset();
        void set_frequency(float freq_in_mhz);
        void set_xtal_mode(xtal_mode_t mode);
        void set_clock_mode(clock_mode_t mode);
        void set_tx_filter_band(filter_band_t band);
        void set_tx_mode(tx_mode_t mode);
        void set_rx_mode(rx_mode_t mode);
        void set_dsp_band(dsp_band_t mode);
        void set_power_mode(pwr_mode_t mode);
        void set_tx_voice_channel(tx_voice_sel_t mode);
        void set_pa_bias_voltage(pa_bias_voltage_t voltage);
        void set_ctcss_frequency(float freq_in_hz);
        void set_cdcss_code(uint32_t code);
        void set_cdcss_phase_shift(shift_t shift);
        void set_ctcss_cdcss_mode(ctcss_cdcss_sel_t mode);
};


#endif

#include "HamShield.hpp"
#include "Arduino.h"
#include "HamShield_comms.h"
#include "hamShield_enums.h"

HamShield::HamShield(uint8_t ncs_pin, uint8_t clk_pin, uint8_t dat_pin, uint8_t mic_pin)
{
   ncs = ncs_pin;
   clk = clk_pin;
   dat = dat_pin;
   mic = mic_pin;
   HSsetPins(ncs, clk, dat);
}

void HamShield::soft_reset()
{
 HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_SOFT_RESET_BIT, 0b1);
}

void HamShield::set_frequency(float freq_in_mhz)
{
    uint32_t freq_khz = freq_in_mhz * 1000;
    uint32_t freq = freq_khz << 4;

    uint16_t freq_hi = freq >> 16;
    uint16_t freq_lo = freq & 0xFFFF;

    HSwriteWord(ncs, HAM_FREQ_HI_REG, freq_hi);
    HSwriteWord(ncs, HAM_FREQ_LO_REG, freq_lo);
}

void HamShield::set_xtal_mode(xtal_mode_t mode)
{
    HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_XTAL_MODE_BIT, mode);
}

void HamShield::set_clock_mode(clock_mode_t mode)
{
    HSwriteBitW(ncs, HAM_CLK_MODE_REG, HAM_CLK_MODE_BIT, mode);
}

void HamShield::set_tx_filter_band(filter_band_t band)
{
    HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_FILTER_BAND_SEL_BIT, band);
}

void HamShield::set_tx_mode(tx_mode_t mode)
{
    HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_TX_ON_BIT, mode);
}

void HamShield::set_rx_mode(rx_mode_t mode)
{
    HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_RX_ON_BIT, mode);
}

void HamShield::set_dsp_band(dsp_band_t mode)
{
   HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_FILTER_BAND_MODE_BIT, mode);
}

void HamShield::set_power_mode(pwr_mode_t mode)
{
    HSwriteBitW(ncs, HAM_CTRL_REG, HAM_CTRL_PWR_DWN_BIT, mode);
}

void HamShield::set_tx_voice_channel(tx_voice_sel_t mode)
{
    HSwriteBitsW(ncs, HAM_SQ_REG, HAM_SQ_VOICE_SEL_BIT, 3, mode);
}

void HamShield::set_pa_bias_voltage(pa_bias_voltage_t voltage)
{
    HSwriteBitsW(ncs, HAM_PABIAS_REG, HAM_PABIAS_PABIAS_VOLTAGE_BIT, 6, voltage);
}

void HamShield::set_ctcss_frequency(float freq_in_hz)
{
   freq_in_hz *= 100;
   HSwriteWord(ncs, HAM_CTCSS_FREQ1_REG, (uint16_t)freq_in_hz);
}

void HamShield::set_cdcss_code(uint32_t code)
{
   uint8_t code_hi = (code >> 16) & 0xFF;
   uint16_t code_lo = code & 0xFFFF;

   HSwriteBitsW(ncs, HAM_CDCSS_CODE_HI_REG, HAM_CDCSS_CODE_HI_BIT, 8, code_hi);
   HSwriteWord(ncs, HAM_CDCSS_CODE_LOW_REG, code_lo);
}

void HamShield::set_cdcss_phase_shift(shift_t shift)
{
    HSwriteBitsW(ncs, HAM_SQ_SEL_REG, HAM_SQ_SEL_SHIFT_SEL_BIT, 2, shift);
}

void HamShield::set_ctcss_cdcss_mode(ctcss_cdcss_sel_t mode)
{
    HSwriteBitsW(ncs, HAM_SQ_SEL_REG, HAM_SQ_SEL_MODE_TX_BIT, 2, mode);
}

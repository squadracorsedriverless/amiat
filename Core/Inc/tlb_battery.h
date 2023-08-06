/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 38.0.2 Thu Jul 13 18:24:12 2023.
 */

#ifndef TLB_BATTERY_H
#define TLB_BATTERY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define TLB_BATTERY_SHTDWN_LINE_TSAC_STATUS_FRAME_ID (0x07u)
#define TLB_BATTERY_TLB_BAT_INTRNL_FUNC_FRAME_ID (0x08u)

/* Frame lengths in bytes. */
#define TLB_BATTERY_SHTDWN_LINE_TSAC_STATUS_LENGTH (3u)
#define TLB_BATTERY_TLB_BAT_INTRNL_FUNC_LENGTH (3u)

/* Extended or standard frame types. */
#define TLB_BATTERY_SHTDWN_LINE_TSAC_STATUS_IS_EXTENDED (0)
#define TLB_BATTERY_TLB_BAT_INTRNL_FUNC_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/**
 * Signals in message ShtdwnLineTsacStatus.
 *
 * shutdown line TSAC section status
 *
 * All signal values are as on the CAN bus.
 */
struct tlb_battery_shtdwn_line_tsac_status_t {
    /**
     * Shutdown line active level @ TSAC Initial section input
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shtdwn_tsac_init_sec_in_active_lvl;

    /**
     * Shutdown line active level post AMS error relay
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shtdwn_post_ams_err_rly_active_lvl;

    /**
     * Shutdown line active level post IMD error relay
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shtdwn_post_imd_err_rly_active_lvl;

    /**
     * Shutdown line active level @ TSAC final section input
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shtdwn_tsac_fin_sec_in_active_lvl;

    /**
     * Shutdown line voltage level post precharge resistor of shutdown line
     *
     * Range: 0..255.8853633572159672466734903 (0..25 V)
     * Scale: 0.0977
     * Offset: 0
     */
    uint8_t shtdwn_post_prch_resist_voltage_lvl;

    /**
     * Shutdown line voltage level post delay capacitors of shutdown line
     *
     * Range: 0..255.8853633572159672466734903 (0..25 V)
     * Scale: 0.0977
     * Offset: 0
     */
    uint8_t shtdwn_post_dly_caps_voltage_lvl;
};

/**
 * Signals in message TlbBatIntrnlFunc.
 *
 * tlb battery internal functions
 *
 * All signal values are as on the CAN bus.
 */
struct tlb_battery_tlb_bat_intrnl_func_t {
    /**
     * AMS error latched active, disables AMS Error Relay
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ams_err_ltch;

    /**
     * IMD error latched active, disables IMD Error Relay
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t imd_err_ltch;

    /**
     * Shutdown Precharge Relay Enable status, enables Shutdwon Precharge Relay
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shtdwn_prch_rly_en;

    /**
     * Shortcircuit to GND detected on AIR negative terminal
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shrt2_gnd_air_neg;

    /**
     * Shortcircuit to GND detected on AIR positive terminal
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shrt2_gnd_air_pos;

    /**
     * Shortcircuit to GND detected on an AIR terminal (either poisitive or negative)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t shrt2_gnd_air;

    /**
     * High Voltage DC Bus, vehicle side (@ Air Positive), over 60 volt
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t dc_bus_vehicle_side_over60_v;

    /**
     * AIR negative closed, Intentional State (signal is reliant on shutdown line beeing active)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t air_neg_clsd_inten_state;

    /**
     * AIR positive closed, Intentional State (signal is reliant on shutdown line beeing active)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t air_pos_clsd_inten_state;

    /**
     * High Voltage DC bus precharge relay enable, intentional state (signal is reliant on shutdown line beeing active)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t dc_bus_prch_rly_en_inten_state;

    /**
     * AIR negative closed, auxiliary/actual state (signal is reliant on shutdown line beegin active)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t air_neg_clsd_aux_state;

    /**
     * AIR positive closed, auxiliary/actual state (signal is reliant on shutdown line beegin active)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t air_pos_clsd_aux_state;

    /**
     * High Voltage DC bus precharge relay enable, auxiliary/actual state (signal is reliant on shutdown line beeing active)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t dc_bus_prch_rly_en_aux_state;

    /**
     * AIR negative closed implausibility error active (Intentional State != Auxiliary State)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t air_neg_clsd_imp_err;

    /**
     * AIR positive closed implausibility error active (Intentional State != Auxiliary State)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t air_pos_clsd_imp_err;

    /**
     * High Voltage DC bus precharge relay enable, implausibility error active (Intentional State != Auxiliary State)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t dc_bus_prch_rly_en_imp_err;

    /**
     * High Voltage DC Bus, vehicle side (@ Air Positive), over 60 volt, implausibility error active (more then 60V but can't be SUPER DANGER)
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t dc_bus_veh_side_over60_v_imp_err;

    /**
     * An/Any implausibility error is active
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t any_imp_err;

    /**
     * An/Any implausibility error is active, latched value
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t any_imp_err_ltch;

    /**
     * TSAL green enable active level
     *
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t tsal_green_en;
};

/**
 * Pack message ShtdwnLineTsacStatus.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tlb_battery_shtdwn_line_tsac_status_pack(
    uint8_t *dst_p,
    const struct tlb_battery_shtdwn_line_tsac_status_t *src_p,
    size_t size);

/**
 * Unpack message ShtdwnLineTsacStatus.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tlb_battery_shtdwn_line_tsac_status_unpack(
    struct tlb_battery_shtdwn_line_tsac_status_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_init_sec_in_active_lvl_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_init_sec_in_active_lvl_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_init_sec_in_active_lvl_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_shtdwn_line_tsac_status_shtdwn_post_ams_err_rly_active_lvl_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_shtdwn_line_tsac_status_shtdwn_post_ams_err_rly_active_lvl_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_shtdwn_line_tsac_status_shtdwn_post_ams_err_rly_active_lvl_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_shtdwn_line_tsac_status_shtdwn_post_imd_err_rly_active_lvl_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_shtdwn_line_tsac_status_shtdwn_post_imd_err_rly_active_lvl_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_shtdwn_line_tsac_status_shtdwn_post_imd_err_rly_active_lvl_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_fin_sec_in_active_lvl_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_fin_sec_in_active_lvl_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_fin_sec_in_active_lvl_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_shtdwn_line_tsac_status_shtdwn_post_prch_resist_voltage_lvl_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_shtdwn_line_tsac_status_shtdwn_post_prch_resist_voltage_lvl_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_shtdwn_line_tsac_status_shtdwn_post_prch_resist_voltage_lvl_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_shtdwn_line_tsac_status_shtdwn_post_dly_caps_voltage_lvl_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_shtdwn_line_tsac_status_shtdwn_post_dly_caps_voltage_lvl_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_shtdwn_line_tsac_status_shtdwn_post_dly_caps_voltage_lvl_is_in_range(uint8_t value);

/**
 * Pack message TlbBatIntrnlFunc.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tlb_battery_tlb_bat_intrnl_func_pack(
    uint8_t *dst_p,
    const struct tlb_battery_tlb_bat_intrnl_func_t *src_p,
    size_t size);

/**
 * Unpack message TlbBatIntrnlFunc.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tlb_battery_tlb_bat_intrnl_func_unpack(
    struct tlb_battery_tlb_bat_intrnl_func_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_ams_err_ltch_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_ams_err_ltch_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_ams_err_ltch_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_imd_err_ltch_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_imd_err_ltch_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_imd_err_ltch_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_shtdwn_prch_rly_en_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_shtdwn_prch_rly_en_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_shtdwn_prch_rly_en_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_neg_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_neg_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_neg_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_pos_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_pos_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_pos_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_shrt2_gnd_air_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_dc_bus_vehicle_side_over60_v_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_dc_bus_vehicle_side_over60_v_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_dc_bus_vehicle_side_over60_v_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_inten_state_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_inten_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_inten_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_inten_state_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_inten_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_inten_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_inten_state_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_inten_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_inten_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_aux_state_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_aux_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_aux_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_aux_state_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_aux_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_aux_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_aux_state_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_aux_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_aux_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_imp_err_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_imp_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_air_neg_clsd_imp_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_imp_err_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_imp_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_air_pos_clsd_imp_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_imp_err_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_imp_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_dc_bus_prch_rly_en_imp_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_dc_bus_veh_side_over60_v_imp_err_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_dc_bus_veh_side_over60_v_imp_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_dc_bus_veh_side_over60_v_imp_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_any_imp_err_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_any_imp_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_any_imp_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_any_imp_err_ltch_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_any_imp_err_ltch_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_any_imp_err_ltch_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t tlb_battery_tlb_bat_intrnl_func_tsal_green_en_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float tlb_battery_tlb_bat_intrnl_func_tsal_green_en_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tlb_battery_tlb_bat_intrnl_func_tsal_green_en_is_in_range(uint8_t value);


#ifdef __cplusplus
}
#endif

#endif

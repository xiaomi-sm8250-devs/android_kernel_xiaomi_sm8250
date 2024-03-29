/*
 * Copyright (c) 2023-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef _PDG_RESPONSE_H_
#define _PDG_RESPONSE_H_

#include "pdg_response_rate_setting.h"
#define NUM_OF_DWORDS_PDG_RESPONSE 12

struct pdg_response {
#ifndef WIFI_BIT_ORDER_BIG_ENDIAN
             struct   pdg_response_rate_setting                                 hw_response_rate_info;
             uint32_t hw_response_tx_duration                                 : 16,
                      rx_duration_field                                       : 16;
             uint32_t punctured_response_transmission                         :  1,
                      cca_subband_channel_bonding_mask                        : 16,
                      scrambler_seed_override                                 :  2,
                      response_density_valid                                  :  1,
                      response_density                                        :  5,
                      more_data                                               :  1,
                      duration_indication                                     :  1,
                      relayed_frame                                           :  1,
                      address_indicator                                       :  1,
                      bandwidth                                               :  3;
             uint32_t ack_id                                                  : 16,
                      block_ack_bitmap                                        : 16;
             uint32_t response_frame_type                                     :  4,
                      ack_id_ext                                              : 10,
                      ftm_en                                                  :  1,
                      group_id                                                :  6,
                      sta_partial_aid                                         : 11;
             uint32_t ndp_ba_start_seq_ctrl                                   : 12,
                      active_channel                                          :  3,
                      txop_duration_all_ones                                  :  1,
                      frame_length                                            : 16;
#else
             struct   pdg_response_rate_setting                                 hw_response_rate_info;
             uint32_t rx_duration_field                                       : 16,
                      hw_response_tx_duration                                 : 16;
             uint32_t bandwidth                                               :  3,
                      address_indicator                                       :  1,
                      relayed_frame                                           :  1,
                      duration_indication                                     :  1,
                      more_data                                               :  1,
                      response_density                                        :  5,
                      response_density_valid                                  :  1,
                      scrambler_seed_override                                 :  2,
                      cca_subband_channel_bonding_mask                        : 16,
                      punctured_response_transmission                         :  1;
             uint32_t block_ack_bitmap                                        : 16,
                      ack_id                                                  : 16;
             uint32_t sta_partial_aid                                         : 11,
                      group_id                                                :  6,
                      ftm_en                                                  :  1,
                      ack_id_ext                                              : 10,
                      response_frame_type                                     :  4;
             uint32_t frame_length                                            : 16,
                      txop_duration_all_ones                                  :  1,
                      active_channel                                          :  3,
                      ndp_ba_start_seq_ctrl                                   : 12;
#endif
};

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_0A_OFFSET                       0x00000000
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_0A_LSB                          0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_0A_MSB                          0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_0A_MASK                         0x00000001

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_ANTENNA_SECTOR_CTRL_OFFSET            0x00000000
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_ANTENNA_SECTOR_CTRL_LSB               1
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_ANTENNA_SECTOR_CTRL_MSB               24
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_ANTENNA_SECTOR_CTRL_MASK              0x01fffffe

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_PKT_TYPE_OFFSET                          0x00000000
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_PKT_TYPE_LSB                             25
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_PKT_TYPE_MSB                             28
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_PKT_TYPE_MASK                            0x1e000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SMOOTHING_OFFSET                         0x00000000
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SMOOTHING_LSB                            29
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SMOOTHING_MSB                            29
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SMOOTHING_MASK                           0x20000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_LDPC_OFFSET                              0x00000000
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_LDPC_LSB                                 30
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_LDPC_MSB                                 30
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_LDPC_MASK                                0x40000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STBC_OFFSET                              0x00000000
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STBC_LSB                                 31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STBC_MSB                                 31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STBC_MASK                                0x80000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_OFFSET                        0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_LSB                           0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_MSB                           7
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_MASK                          0x000000ff

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_MIN_TX_PWR_OFFSET                    0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_MIN_TX_PWR_LSB                       8
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_MIN_TX_PWR_MSB                       15
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_MIN_TX_PWR_MASK                      0x0000ff00

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_NSS_OFFSET                           0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_NSS_LSB                              16
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_NSS_MSB                              18
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_NSS_MASK                             0x00070000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_CHAIN_MASK_OFFSET                 0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_CHAIN_MASK_LSB                    19
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_CHAIN_MASK_MSB                    26
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_CHAIN_MASK_MASK                   0x07f80000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_BW_OFFSET                            0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_BW_LSB                               27
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_BW_MSB                               29
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_BW_MASK                              0x38000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STF_LTF_3DB_BOOST_OFFSET                 0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STF_LTF_3DB_BOOST_LSB                    30
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STF_LTF_3DB_BOOST_MSB                    30
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_STF_LTF_3DB_BOOST_MASK                   0x40000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_FORCE_EXTRA_SYMBOL_OFFSET                0x00000004
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_FORCE_EXTRA_SYMBOL_LSB                   31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_FORCE_EXTRA_SYMBOL_MSB                   31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_FORCE_EXTRA_SYMBOL_MASK                  0x80000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_RATE_MCS_OFFSET                      0x00000008
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_RATE_MCS_LSB                         0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_RATE_MCS_MSB                         3
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_RATE_MCS_MASK                        0x0000000f

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NSS_OFFSET                               0x00000008
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NSS_LSB                                  4
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NSS_MSB                                  6
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NSS_MASK                                 0x00000070

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DPD_ENABLE_OFFSET                        0x00000008
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DPD_ENABLE_LSB                           7
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DPD_ENABLE_MSB                           7
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DPD_ENABLE_MASK                          0x00000080

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_OFFSET                            0x00000008
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_LSB                               8
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_MSB                               15
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_MASK                              0x0000ff00

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MIN_TX_PWR_OFFSET                        0x00000008
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MIN_TX_PWR_LSB                           16
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MIN_TX_PWR_MSB                           23
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MIN_TX_PWR_MASK                          0x00ff0000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_CHAIN_MASK_OFFSET                     0x00000008
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_CHAIN_MASK_LSB                        24
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_CHAIN_MASK_MSB                        31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_CHAIN_MASK_MASK                       0xff000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3A_OFFSET                       0x0000000c
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3A_LSB                          0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3A_MSB                          7
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3A_MASK                         0x000000ff

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SGI_OFFSET                               0x0000000c
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SGI_LSB                                  8
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SGI_MSB                                  9
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_SGI_MASK                                 0x00000300

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RATE_MCS_OFFSET                          0x0000000c
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RATE_MCS_LSB                             10
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RATE_MCS_MSB                             13
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RATE_MCS_MASK                            0x00003c00

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3B_OFFSET                       0x0000000c
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3B_LSB                          14
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3B_MSB                          15
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_3B_MASK                         0x0000c000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_1_OFFSET                          0x0000000c
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_1_LSB                             16
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_1_MSB                             23
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_TX_PWR_1_MASK                            0x00ff0000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_1_OFFSET                      0x0000000c
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_1_LSB                         24
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_1_MSB                         31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_ALT_TX_PWR_1_MASK                        0xff000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_AGGREGATION_OFFSET                       0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_AGGREGATION_LSB                          0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_AGGREGATION_MSB                          0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_AGGREGATION_MASK                         0x00000001

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_BSS_COLOR_ID_OFFSET              0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_BSS_COLOR_ID_LSB                 1
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_BSS_COLOR_ID_MSB                 6
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_BSS_COLOR_ID_MASK                0x0000007e

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SPATIAL_REUSE_OFFSET             0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SPATIAL_REUSE_LSB                7
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SPATIAL_REUSE_MSB                10
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SPATIAL_REUSE_MASK               0x00000780

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CP_LTF_SIZE_OFFSET               0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CP_LTF_SIZE_LSB                  11
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CP_LTF_SIZE_MSB                  12
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CP_LTF_SIZE_MASK                 0x00001800

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DCM_OFFSET                       0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DCM_LSB                          13
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DCM_MSB                          13
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DCM_MASK                         0x00002000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DOPPLER_INDICATION_OFFSET        0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DOPPLER_INDICATION_LSB           14
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DOPPLER_INDICATION_MSB           14
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DOPPLER_INDICATION_MASK          0x00004000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SU_EXTENDED_OFFSET               0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SU_EXTENDED_LSB                  15
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SU_EXTENDED_MSB                  15
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_SU_EXTENDED_MASK                 0x00008000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_MIN_PACKET_EXTENSION_OFFSET      0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_MIN_PACKET_EXTENSION_LSB         16
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_MIN_PACKET_EXTENSION_MSB         17
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_MIN_PACKET_EXTENSION_MASK        0x00030000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_NSS_OFFSET                    0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_NSS_LSB                       18
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_NSS_MSB                       20
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_NSS_MASK                      0x001c0000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CONTENT_OFFSET                0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CONTENT_LSB                   21
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CONTENT_MSB                   21
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CONTENT_MASK                  0x00200000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_LTF_SIZE_OFFSET               0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_LTF_SIZE_LSB                  22
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_LTF_SIZE_MSB                  23
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_LTF_SIZE_MASK                 0x00c00000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CHAIN_CSD_EN_OFFSET              0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CHAIN_CSD_EN_LSB                 24
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CHAIN_CSD_EN_MSB                 24
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_CHAIN_CSD_EN_MASK                0x01000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CHAIN_CSD_EN_OFFSET           0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CHAIN_CSD_EN_LSB              25
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CHAIN_CSD_EN_MSB              25
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_PE_CHAIN_CSD_EN_MASK             0x02000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DL_UL_FLAG_OFFSET                0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DL_UL_FLAG_LSB                   26
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DL_UL_FLAG_MSB                   26
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_DL_UL_FLAG_MASK                  0x04000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_4A_OFFSET                       0x00000010
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_4A_LSB                          27
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_4A_MSB                          31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_4A_MASK                         0xf8000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_START_INDEX_OFFSET        0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_START_INDEX_LSB           0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_START_INDEX_MSB           3
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_START_INDEX_MASK          0x0000000f

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_SIZE_OFFSET               0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_SIZE_LSB                  4
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_SIZE_MSB                  7
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11AX_EXT_RU_SIZE_MASK                 0x000000f0

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_EHT_DUPLICATE_MODE_OFFSET                0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_EHT_DUPLICATE_MODE_LSB                   8
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_EHT_DUPLICATE_MODE_MSB                   9
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_EHT_DUPLICATE_MODE_MASK                  0x00000300

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_DCM_OFFSET                       0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_DCM_LSB                          10
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_DCM_MSB                          10
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_DCM_MASK                         0x00000400

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_0_MCS_OFFSET                     0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_0_MCS_LSB                        11
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_0_MCS_MSB                        13
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_HE_SIGB_0_MCS_MASK                       0x00003800

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NUM_HE_SIGB_SYM_OFFSET                   0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NUM_HE_SIGB_SYM_LSB                      14
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NUM_HE_SIGB_SYM_MSB                      18
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_NUM_HE_SIGB_SYM_MASK                     0x0007c000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_SOURCE_OFFSET     0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_SOURCE_LSB        19
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_SOURCE_MSB        19
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_SOURCE_MASK       0x00080000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_5A_OFFSET                       0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_5A_LSB                          20
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_5A_MSB                          25
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_RESERVED_5A_MASK                         0x03f00000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_U_SIG_PUNCTURE_PATTERN_ENCODING_OFFSET   0x00000014
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_U_SIG_PUNCTURE_PATTERN_ENCODING_LSB      26
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_U_SIG_PUNCTURE_PATTERN_ENCODING_MSB      31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_U_SIG_PUNCTURE_PATTERN_ENCODING_MASK     0xfc000000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_OFFSET 0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_LSB 0
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_MSB 9
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_MASK 0x000003ff

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_SELF_ML_SYNC_OFFSET 0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_SELF_ML_SYNC_LSB 10
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_SELF_ML_SYNC_MSB 10
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_SELF_ML_SYNC_MASK 0x00000400

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_PARTNER_ML_SYNC_OFFSET 0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_PARTNER_ML_SYNC_LSB 11
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_PARTNER_ML_SYNC_MSB 11
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_BLOCK_PARTNER_ML_SYNC_MASK 0x00000800

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_VALID_OFFSET 0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_VALID_LSB 12
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_VALID_MSB 12
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_NSTR_MLO_STA_ID_VALID_MASK 0x00001000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_RESERVED_0A_OFFSET 0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_RESERVED_0A_LSB    13
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_RESERVED_0A_MSB    15
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_MLO_STA_ID_DETAILS_RX_RESERVED_0A_MASK   0x0000e000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_OFFSET            0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_LSB               16
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_MSB               27
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_REQUIRED_RESPONSE_TIME_MASK              0x0fff0000

#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11BE_PARAMS_PLACEHOLDER_OFFSET        0x00000018
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11BE_PARAMS_PLACEHOLDER_LSB           28
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11BE_PARAMS_PLACEHOLDER_MSB           31
#define PDG_RESPONSE_HW_RESPONSE_RATE_INFO_DOT11BE_PARAMS_PLACEHOLDER_MASK          0xf0000000

#define PDG_RESPONSE_HW_RESPONSE_TX_DURATION_OFFSET                                 0x0000001c
#define PDG_RESPONSE_HW_RESPONSE_TX_DURATION_LSB                                    0
#define PDG_RESPONSE_HW_RESPONSE_TX_DURATION_MSB                                    15
#define PDG_RESPONSE_HW_RESPONSE_TX_DURATION_MASK                                   0x0000ffff

#define PDG_RESPONSE_RX_DURATION_FIELD_OFFSET                                       0x0000001c
#define PDG_RESPONSE_RX_DURATION_FIELD_LSB                                          16
#define PDG_RESPONSE_RX_DURATION_FIELD_MSB                                          31
#define PDG_RESPONSE_RX_DURATION_FIELD_MASK                                         0xffff0000

#define PDG_RESPONSE_PUNCTURED_RESPONSE_TRANSMISSION_OFFSET                         0x00000020
#define PDG_RESPONSE_PUNCTURED_RESPONSE_TRANSMISSION_LSB                            0
#define PDG_RESPONSE_PUNCTURED_RESPONSE_TRANSMISSION_MSB                            0
#define PDG_RESPONSE_PUNCTURED_RESPONSE_TRANSMISSION_MASK                           0x00000001

#define PDG_RESPONSE_CCA_SUBBAND_CHANNEL_BONDING_MASK_OFFSET                        0x00000020
#define PDG_RESPONSE_CCA_SUBBAND_CHANNEL_BONDING_MASK_LSB                           1
#define PDG_RESPONSE_CCA_SUBBAND_CHANNEL_BONDING_MASK_MSB                           16
#define PDG_RESPONSE_CCA_SUBBAND_CHANNEL_BONDING_MASK_MASK                          0x0001fffe

#define PDG_RESPONSE_SCRAMBLER_SEED_OVERRIDE_OFFSET                                 0x00000020
#define PDG_RESPONSE_SCRAMBLER_SEED_OVERRIDE_LSB                                    17
#define PDG_RESPONSE_SCRAMBLER_SEED_OVERRIDE_MSB                                    18
#define PDG_RESPONSE_SCRAMBLER_SEED_OVERRIDE_MASK                                   0x00060000

#define PDG_RESPONSE_RESPONSE_DENSITY_VALID_OFFSET                                  0x00000020
#define PDG_RESPONSE_RESPONSE_DENSITY_VALID_LSB                                     19
#define PDG_RESPONSE_RESPONSE_DENSITY_VALID_MSB                                     19
#define PDG_RESPONSE_RESPONSE_DENSITY_VALID_MASK                                    0x00080000

#define PDG_RESPONSE_RESPONSE_DENSITY_OFFSET                                        0x00000020
#define PDG_RESPONSE_RESPONSE_DENSITY_LSB                                           20
#define PDG_RESPONSE_RESPONSE_DENSITY_MSB                                           24
#define PDG_RESPONSE_RESPONSE_DENSITY_MASK                                          0x01f00000

#define PDG_RESPONSE_MORE_DATA_OFFSET                                               0x00000020
#define PDG_RESPONSE_MORE_DATA_LSB                                                  25
#define PDG_RESPONSE_MORE_DATA_MSB                                                  25
#define PDG_RESPONSE_MORE_DATA_MASK                                                 0x02000000

#define PDG_RESPONSE_DURATION_INDICATION_OFFSET                                     0x00000020
#define PDG_RESPONSE_DURATION_INDICATION_LSB                                        26
#define PDG_RESPONSE_DURATION_INDICATION_MSB                                        26
#define PDG_RESPONSE_DURATION_INDICATION_MASK                                       0x04000000

#define PDG_RESPONSE_RELAYED_FRAME_OFFSET                                           0x00000020
#define PDG_RESPONSE_RELAYED_FRAME_LSB                                              27
#define PDG_RESPONSE_RELAYED_FRAME_MSB                                              27
#define PDG_RESPONSE_RELAYED_FRAME_MASK                                             0x08000000

#define PDG_RESPONSE_ADDRESS_INDICATOR_OFFSET                                       0x00000020
#define PDG_RESPONSE_ADDRESS_INDICATOR_LSB                                          28
#define PDG_RESPONSE_ADDRESS_INDICATOR_MSB                                          28
#define PDG_RESPONSE_ADDRESS_INDICATOR_MASK                                         0x10000000

#define PDG_RESPONSE_BANDWIDTH_OFFSET                                               0x00000020
#define PDG_RESPONSE_BANDWIDTH_LSB                                                  29
#define PDG_RESPONSE_BANDWIDTH_MSB                                                  31
#define PDG_RESPONSE_BANDWIDTH_MASK                                                 0xe0000000

#define PDG_RESPONSE_ACK_ID_OFFSET                                                  0x00000024
#define PDG_RESPONSE_ACK_ID_LSB                                                     0
#define PDG_RESPONSE_ACK_ID_MSB                                                     15
#define PDG_RESPONSE_ACK_ID_MASK                                                    0x0000ffff

#define PDG_RESPONSE_BLOCK_ACK_BITMAP_OFFSET                                        0x00000024
#define PDG_RESPONSE_BLOCK_ACK_BITMAP_LSB                                           16
#define PDG_RESPONSE_BLOCK_ACK_BITMAP_MSB                                           31
#define PDG_RESPONSE_BLOCK_ACK_BITMAP_MASK                                          0xffff0000

#define PDG_RESPONSE_RESPONSE_FRAME_TYPE_OFFSET                                     0x00000028
#define PDG_RESPONSE_RESPONSE_FRAME_TYPE_LSB                                        0
#define PDG_RESPONSE_RESPONSE_FRAME_TYPE_MSB                                        3
#define PDG_RESPONSE_RESPONSE_FRAME_TYPE_MASK                                       0x0000000f

#define PDG_RESPONSE_ACK_ID_EXT_OFFSET                                              0x00000028
#define PDG_RESPONSE_ACK_ID_EXT_LSB                                                 4
#define PDG_RESPONSE_ACK_ID_EXT_MSB                                                 13
#define PDG_RESPONSE_ACK_ID_EXT_MASK                                                0x00003ff0

#define PDG_RESPONSE_FTM_EN_OFFSET                                                  0x00000028
#define PDG_RESPONSE_FTM_EN_LSB                                                     14
#define PDG_RESPONSE_FTM_EN_MSB                                                     14
#define PDG_RESPONSE_FTM_EN_MASK                                                    0x00004000

#define PDG_RESPONSE_GROUP_ID_OFFSET                                                0x00000028
#define PDG_RESPONSE_GROUP_ID_LSB                                                   15
#define PDG_RESPONSE_GROUP_ID_MSB                                                   20
#define PDG_RESPONSE_GROUP_ID_MASK                                                  0x001f8000

#define PDG_RESPONSE_STA_PARTIAL_AID_OFFSET                                         0x00000028
#define PDG_RESPONSE_STA_PARTIAL_AID_LSB                                            21
#define PDG_RESPONSE_STA_PARTIAL_AID_MSB                                            31
#define PDG_RESPONSE_STA_PARTIAL_AID_MASK                                           0xffe00000

#define PDG_RESPONSE_NDP_BA_START_SEQ_CTRL_OFFSET                                   0x0000002c
#define PDG_RESPONSE_NDP_BA_START_SEQ_CTRL_LSB                                      0
#define PDG_RESPONSE_NDP_BA_START_SEQ_CTRL_MSB                                      11
#define PDG_RESPONSE_NDP_BA_START_SEQ_CTRL_MASK                                     0x00000fff

#define PDG_RESPONSE_ACTIVE_CHANNEL_OFFSET                                          0x0000002c
#define PDG_RESPONSE_ACTIVE_CHANNEL_LSB                                             12
#define PDG_RESPONSE_ACTIVE_CHANNEL_MSB                                             14
#define PDG_RESPONSE_ACTIVE_CHANNEL_MASK                                            0x00007000

#define PDG_RESPONSE_TXOP_DURATION_ALL_ONES_OFFSET                                  0x0000002c
#define PDG_RESPONSE_TXOP_DURATION_ALL_ONES_LSB                                     15
#define PDG_RESPONSE_TXOP_DURATION_ALL_ONES_MSB                                     15
#define PDG_RESPONSE_TXOP_DURATION_ALL_ONES_MASK                                    0x00008000

#define PDG_RESPONSE_FRAME_LENGTH_OFFSET                                            0x0000002c
#define PDG_RESPONSE_FRAME_LENGTH_LSB                                               16
#define PDG_RESPONSE_FRAME_LENGTH_MSB                                               31
#define PDG_RESPONSE_FRAME_LENGTH_MASK                                              0xffff0000

#endif

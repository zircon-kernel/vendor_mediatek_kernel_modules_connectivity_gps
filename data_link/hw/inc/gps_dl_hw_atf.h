/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2022 MediaTek Inc.
 */

#include <linux/arm-smccc.h>
#include <linux/soc/mediatek/mtk_sip_svc.h>


enum conn_smc_opid {
	/* gps_hw_ops */
	SMC_GPS_WAKEUP_CONNINFRA_TOP_OFF_OPID = 1,
	SMC_GPS_COMMON_ON_PART1_OPID,
	SMC_GPS_COMMON_ON_PART2_OPID,
	SMC_GPS_COMMON_ON_PART3_OPID,
	SMC_GPS_COMMON_ON_PART4_OPID,
#if GPS_DL_CONNAC3
	SMC_GPS_COMMON_ON_CONTROL_ADIE_ON_1_OPID,
	SMC_GPS_COMMON_ON_CONTROL_ADIE_ON_2_OPID,
#endif
	SMC_GPS_COMMON_ON_FAIL_HANDLER_OPID,
	SMC_GPS_COMMON_ON_INNER_FAIL_HANDLER_OPID,
	SMC_GPS_COMMON_ON_PART5_OPID,
	SMC_GPS_DL_HW_GPS_PWR_STAT_CTRL_OPID,
	SMC_GPS_DL_SET_DSP_ON_AND_POLL_ACK_OPID,
	SMC_GPS_DL_HW_USRT_CTRL_OPID,
	SMC_GPS_DL_SET_CFG_DSP_MEM_AND_DSP_OFF_OPID,
	SMC_GPS_COMMON_OFF_PART1_OPID,
	SMC_GPS_COMMON_OFF_PART2_OPID,
	SMC_GPS_SW_REQUEST_EMI_USAGE_OPID,
	SMC_GPS_COMMON_OFF_PART3_OPID,

	/* gps_hw_irq */
	SMC_GPS_DL_HW_GET_MCUB_INFO_OPID,
	SMC_GPS_DL_HW_CLEAR_MCUB_D2A_FLAG_OPID,
	SMC_GPS_DL_HW_POLL_USRT_DSP_RX_EMPTY_OPID,
	SMC_GPS_DL_HW_SET_DMA_START_OPID,
	SMC_GPS_DL_HW_GET_MCUB_A2D_FLAG_OPID,
	SMC_GPS_DL_HW_MCUB_DSP_READ_REQUEST_OPID,
	SMC_GPS_DL_HW_USRT_HAS_SET_NODATA_FLAG_OPID,
	SMC_GPS_DL_HW_USRT_CLEAR_NODATA_IRQ_OPID,
	SMC_GPS_DL_HW_GET_DMA_LEFT_LEN_OPID,
	SMC_GPS_DL_HW_SET_DMA_STOP_OPID,
	SMC_GPS_DL_HW_USRT_IRQ_ENABLE_OPID,
	SMC_GPS_DL_HW_GET_DMA_INT_STATUS_OPID,
	SMC_GPS_MVCD_GET_DSP_BOOT_UP_INFO,
	SMC_GPS_MVCD_SEND_DSP_FRAGEMENT,

#if GPS_DL_HAS_MCUDL
	/* gps_mcudl_hw_ops */
	SMC_GPS_MCUDL_HW_CCIF_IS_TCH_BUSY_OPID,
	SMC_GPS_MCUDL_HW_CCIF_SET_TCH_BUSY_OPID,
	SMC_GPS_MCUDL_HW_CCIF_SET_TCH_START_OPID,
	SMC_GPS_MCUDL_HW_CCIF_GET_TCH_BUSY_BITMASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_CLR_TCH_BUSY_BITMASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_CLR_RCH_BUSY_BITMASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_GET_TCH_START_BITMASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_GET_RCH_BITMASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_SET_RCH_ACK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_SET_IRQ_MASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_GET_IRQ_MASK_OPID,
	SMC_GPS_MCUDL_HW_CCIF_SET_DUMMY_OPID,
	SMC_GPS_MCUDL_HW_CCIF_GET_DUMMY_OPID,
	SMC_GPS_MCUDL_HW_CCIF_GET_SHADOW_OPID,

	SMC_GPS_MCUDL_HW_WAKEUP_GPS_OPID,
	SMC_GPS_MCUDL_CHECK_CONN_INFRA_VER_IS_OK_OPID,
	SMC_GPS_MCUDL_POLL_CONN_INFRA_CMBDT_RESTORE_IS_OK_OPID,
	SMC_GPS_MCUDL_HW_GPS_SLEEP_PROT_CTRL_CONN2GPS_RX_OPID,
	SMC_GPS_MCUDL_HW_GPS_SLEEP_PROT_CTRL_CONN2GPS_TX_OPID,
	SMC_GPS_MCUDL_HW_GPS_SLEEP_PROT_CTRL_GPS2CONN_RX_OPID,
	SMC_GPS_MCUDL_HW_GPS_SLEEP_PROT_CTRL_GPS2CONN_TX_OPID,
	SMC_GPS_MCUDL_HW_GPS_SLEEP_PROT_CTRL_GPS2CONN_AXI_RX_OPID,
	SMC_GPS_MCUDL_HW_GPS_SLEEP_PROT_CTRL_GPS2CONN_AXI_TX_OPID,
	SMC_GPS_MCUDL_HW_MCU_DO_ON_WITH_RST_HELD_1_OPID,
	SMC_GPS_MCUDL_HW_MCU_DO_ON_WITH_RST_HELD_2_OPID,
	SMC_GPS_MCUDL_HW_MCU_DO_ON_WITH_RST_HELD_3_OPID,
	SMC_GPS_MCUDL_HW_MCU_DO_ON_WITH_RST_HELD_FAIL_HANDLER_1_OPID,
	SMC_GPS_MCUDL_HW_MCU_DO_ON_WITH_RST_HELD_FAIL_HANDLER_2_OPID,
	SMC_GPS_MCUDL_HW_MCU_ENABLE_CLOCK_OPID,
	SMC_GPS_MCUDL_HW_MCU_WAIT_CLOCK_READY_OPID,
	SMC_GPS_MCUDL_HW_MCU_SET_PLL_OPID,
	SMC_GPS_MCUDL_HW_MCU_RELEASE_RST_OPID,
	SMC_GPS_MCUDL_HW_MCU_WAIT_IDLE_LOOP_OPID,
	SMC_GPS_MCUDL_HW_MCU_DO_OFF_1_OPID,
	SMC_GPS_MCUDL_HW_MCU_SHOW_STATUS_OPID,
	SMC_GPS_MCUDL_HW_MCU_SET_OR_CLR_FW_OWN_OPID,
	SMC_GPS_DL_HW_SET_MCU_EMI_REMAPPING_TMP_OPID,
	SMC_GPS_DL_HW_GET_MCU_EMI_REMAPPING_TMP_OPID,
	SMC_GPS_DL_HW_SET_GPS_DYNC_REMAPPING_TMP_OPID,
#endif
	SMC_GPS_DL_HW_DEP_DUMP_HOST_CSR_GPS_INFO_OPID,
};

enum gps_dl_hw_mvcd_dsp_type {
	GPS_DL_MVCD_DSP_L1 = 0,
	GPS_DL_MVCD_DSP_L5,
	GPS_DL_MVCD_DSP_L1_CW,
	GPS_DL_MVCD_DSP_L5_CW,
	GPS_DL_MVCD_DSP_RESERVED1,
	GPS_DL_MVCD_DSP_RESERVED2,
};

bool gps_dl_hw_gps_force_wakeup_conninfra_top_off(bool enable);


/**
 *  \file	TivaHW.h
 *  \brief 	This file includes information about Tiva C Hardware.
 *  \author	Ahmed Wageh.
 *  \date	24/5/2020
 */
 
/* Header guard */
#ifndef TIVA_HW_H_
#define TIVA_HW_H_

#include "PlatformTypes.h"

/* Definitions */
#define HW_NO_OF_PORTS	6	/*!< Number of GPIO Ports for the uc */

/* GPIO */
/* Unlock Pattern */
#define HW_GPIO_UNLOCK_PATTERN	0x4C4F434B 
/* Registers Offsets */
#define HW_GPIODATA_OFFSET			0x000
#define HW_GPIODIR_OFFSET			0x400
#define HW_GPIOIS_OFFSET			0x404
#define HW_GPIOIBE_OFFSET			0x408
#define HW_GPIOIEV_OFFSET			0x40C
#define HW_GPIOIM_OFFSET			0x410
#define HW_GPIORIS_OFFSET			0x414
#define HW_GPIOMIS_OFFSET			0x418
#define HW_GPIOICR_OFFSET			0x41C
#define HW_GPIOAFSEL_OFFSET			0x420
#define HW_GPIODR2R_OFFSET			0x500
#define HW_GPIODR4R_OFFSET			0x504
#define HW_GPIODR8R_OFFSET			0x508
#define HW_GPIOODR_OFFSET			0x50C
#define HW_GPIOPUR_OFFSET			0x510
#define HW_GPIOPDR_OFFSET			0x514
#define HW_GPIOSLR_OFFSET			0x518
#define HW_GPIODEN_OFFSET			0x51C
#define HW_GPIOLOCK_OFFSET			0x520
#define HW_GPIOCR_OFFSET			0x524
#define HW_GPIOAMSEL_OFFSET			0x528
#define HW_GPIOCTL_OFFSET			0x52C
#define HW_GPIOADCCTL_OFFSET		0x530
#define HW_GPIODMACTL_OFFSET		0xFF0
#define HW_GPIOPeriphID4_OFFSET		0x5D0
#define HW_GPIOPeriphID5_OFFSET		0x5D4
#define HW_GPIOPeriphID6_OFFSET		0x5D8
#define HW_GPIOPeriphID7_OFFSET		0x5DC
#define HW_GPIOPeriphID0_OFFSET		0x5E0
#define HW_GPIOPeriphID1_OFFSET		0x5E4
#define HW_GPIOPeriphID2_OFFSET		0x5E8
#define HW_GPIOPeriphID3_OFFSET		0x5EC
#define HW_GPIOPCellID0_OFFSET		0xFF0
#define HW_GPIOPCellID1_OFFSET		0xFF4
#define HW_GPIOPCellID2_OFFSET		0xFF8
#define HW_GPIOPCellID3_OFFSET		0xFFC

/* Clock Registers */
/* Base Addresses */
#define HW_SYSTEM_CONTROL_BA	0x400FE000
/* Offsets*/
#define HW_RCGCGPIO_OFFSET	 0x608
#define HW_RCGC2_OFFSET 0x108
/* Macro functions */

#define HW_W_8RIG(ADDRESS,DATA)	*((volatile uint32 *)(ADDRESS)) = DATA	/*!< Write Data to 8-bits Register */
#define HW_R_8RIG(ADDRESS)			(*((volatile uint32 *)(ADDRESS))) 	/*!< Read Data from 8-bits Register */
#define HW_S_BIT(ADDRESS,BIT)		*((volatile uint32 *)(ADDRESS)) |= (1<<BIT)		/*!< Set specific bit in a register */
#define HW_C_BIT(ADDRESS,BIT)		*((volatile uint32 *)(ADDRESS)) &=~ (1<<BIT)	/*!< Clear specific bit in a register */

/* Defined data types */
typedef uint32 HW_AddressBusSizeType;	/*!< The size of address bus */
/*typedef uint32 HW_DataBusSizeType; */	/*!< The size of data bus */
#endif /* TIVA_HW_H_ */

/**
 *  \file	DioGeneral.h
 *  \brief 	Contains general DIO module configuration parameters.
 *  \author	Ahmed Wageh.
 *  \date	4/6/2020
 */

/* Header guard */
#ifndef DIO_GENERAL_H_
#define DIO_GENERAL_H_

/* Inclusion */
#include "Std_Types.h"		/* Contains useful data types */
#include "PlatformTypes.h"	/* Contains standard data types */

/* Macros */
/* General configuration parameters */
#define DioDevErrorDetect		STD_OFF	/*!< Switches the development error detection and notification on or off */
#define DioFlipChannelApi		STD_ON	/*!< Adds / removes the service Dio_FlipChannel() from the code */
#define DioMaskedWritePortApi	STD_OFF	/*!< Adds / removes the service Dio_MaskedWritePort() from the code */
#define DioVersionInfoApi		STD_OFF	/*!< Adds / removes the service Dio_GetVersionInfo() from the code */

#endif /* DIO_GENERAL_H_ */

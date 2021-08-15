/**
 *  \file	DIO.h
 *  \brief 	This module works on pins and ports which are configured 
 *  		by the PORT driver for this purpose.
 *  \author	Ahmed Wageh.
 *  \date	24/5/2020
 */
 
/* Header guard */
#ifndef DIO_H_
#define DIO_H_
 
/* Inclusion */
#include "Std_Types.h"		/* Contains useful data types */
#include "PlatformTypes.h"	/* Contains standard data types */
#include "TivaHW.h"			/* Contains addresses and HW data for Tiva C */
#include "DioGeneral.h"	

/* Macros */
/* Development Errors */
#define DIO_E_PARAM_INVALID_CHANNEL_ID	0x0A	/*!< Invalid channel requested */
#define DIO_E_PARAM_INVALID_PORT_ID		0x14	/*!< Invalid port requested */
#define DIO_E_PARAM_INVALID_GROUP		0x1F	/*!< Invalid channel group requested */
#define DIO_E_PARAM_POINTER				0x20	/*!< API service called with a NULL pointer */

/* Defined data types */
typedef enum {
	/* PORT A Channels */
	DIO_CHANNEL_A0 = 0x00,		/*!< Channel A0 ID */
	DIO_CHANNEL_A1 = 0x01,		/*!< Channel A1 ID */
	DIO_CHANNEL_A2 = 0x02,		/*!< Channel A2 ID */
	DIO_CHANNEL_A3 = 0x03,		/*!< Channel A3 ID */
	DIO_CHANNEL_A4 = 0x04,		/*!< Channel A4 ID */
	DIO_CHANNEL_A5 = 0x05,		/*!< Channel A5 ID */
	DIO_CHANNEL_A6 = 0x06,		/*!< Channel A6 ID */
	DIO_CHANNEL_A7 = 0x07,		/*!< Channel A7 ID */
	
	/* PORT B Channels */
	DIO_CHANNEL_B0 = 0x10,		/*!< Channel B0 ID */
	DIO_CHANNEL_B1 = 0x11,		/*!< Channel B1 ID */
	DIO_CHANNEL_B2 = 0x12,		/*!< Channel B2 ID */
	DIO_CHANNEL_B3 = 0x13,		/*!< Channel B3 ID */
	DIO_CHANNEL_B4 = 0x14,		/*!< Channel B4 ID */
	DIO_CHANNEL_B5 = 0x15,		/*!< Channel B5 ID */
	DIO_CHANNEL_B6 = 0x16,		/*!< Channel B6 ID */
	DIO_CHANNEL_B7 = 0x17,		/*!< Channel B7 ID */
	
	/* PORT C Channels */
	DIO_CHANNEL_C0 = 0x20,		/*!< Channel C0 ID */
	DIO_CHANNEL_C1 = 0x21,		/*!< Channel C1 ID */
	DIO_CHANNEL_C2 = 0x22,		/*!< Channel C2 ID */
	DIO_CHANNEL_C3 = 0x23,		/*!< Channel C3 ID */
	DIO_CHANNEL_C4 = 0x24,		/*!< Channel C4 ID */
	DIO_CHANNEL_C5 = 0x25,		/*!< Channel C5 ID */
	DIO_CHANNEL_C6 = 0x26,		/*!< Channel C6 ID */
	DIO_CHANNEL_C7 = 0x27,		/*!< Channel C7 ID */
	
	/* PORT D Channels */
	DIO_CHANNEL_D0 = 0x30,		/*!< Channel D0 ID */
	DIO_CHANNEL_D1 = 0x31,		/*!< Channel D1 ID */
	DIO_CHANNEL_D2 = 0x32,		/*!< Channel D2 ID */
	DIO_CHANNEL_D3 = 0x33,		/*!< Channel D3 ID */
	DIO_CHANNEL_D4 = 0x34,		/*!< Channel D4 ID */
	DIO_CHANNEL_D5 = 0x35,		/*!< Channel D5 ID */
	DIO_CHANNEL_D6 = 0x36,		/*!< Channel D6 ID */
	DIO_CHANNEL_D7 = 0x37,		/*!< Channel D7 ID */
	
	/* PORT E Channels */
	DIO_CHANNEL_E0 = 0x40,		/*!< Channel E0 ID */
	DIO_CHANNEL_E1 = 0x41,		/*!< Channel E1 ID */
	DIO_CHANNEL_E2 = 0x42,		/*!< Channel E2 ID */
	DIO_CHANNEL_E3 = 0x43,		/*!< Channel E3 ID */
	DIO_CHANNEL_E4 = 0x44,		/*!< Channel E4 ID */
	DIO_CHANNEL_E5 = 0x45,		/*!< Channel E5 ID */

	/* PORT E Channels */ 
	DIO_CHANNEL_F0 = 0x50,		/*!< Channel F0 ID */
	DIO_CHANNEL_F1 = 0x51,		/*!< Channel F1 ID */
	DIO_CHANNEL_F2 = 0x52,		/*!< Channel F2 ID */
	DIO_CHANNEL_F3 = 0x53,		/*!< Channel F3 ID */
	DIO_CHANNEL_F4 = 0x54 		/*!< Channel F4 ID */
	
}Dio_ChannelType; /*!< Numeric ID of a DIO channel */
                          

#ifndef PORT_TYPE_H_	/* To avoid multiple definition of Dio_PortType */
#define PORT_TYPE_H_
typedef enum{             
	DIO_PORTA = 0,		/*!< Port A */
	DIO_PORTB = 1,		/*!< Port B */
	DIO_PORTC = 2,		/*!< Port C */
	DIO_PORTD = 3,		/*!< Port D */
	DIO_PORTE = 4,		/*!< Port E */
	DIO_PORTF = 5		/*!< Port F */
}Dio_PortType;	/*!< Numeric ID of a DIO port. */
#endif /* PORT_TYPE_H_ */

typedef struct{
	uint8 mask; 		/*!< This element mask which defines the positions of the channel group. */
	uint8 offset; 		/*!< This element shall be the position of the Channel Group on the port,
							 counted from the LSB. */
	Dio_PortType port;	/*!< This shall be the port on which the Channel group is defined. */
}Dio_ChannelGroupType; /*!< Type for the definition of a channel group, which consists of 
							several adjoining channels within a port.*/

typedef uint8 Dio_LevelType;		/*!< These are the possible levels a DIO channel can have 
										(input or output). This could take STD_HIGH or STD_LOW */

typedef uint8 Dio_PortLevelType;	/*!< The type for the value of a DIO port.*/


/* Functions Proto Types */
/**
 *	\brief		Returns the value of the specified DIO channel.
 *	\param[in] 	ChannelId: ID of DIO channel.
 *	\return		Dio_LevelType:	-	STD_HIGH: The physical level of the corresponding 
 *									Pin is STD_HIGH.
 *								-	STD_LOW:  The physical level of the corresponding 
 *									Pin is STD_LOW.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 *	\brief		Service to set a level of a channel.
 *	\param[in] 	ChannelId: 	ID of DIO channel.
 *	\param[in] 	Level: 		Value to be written.
 *	\return		None.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
 *	\brief		Returns the level of all channels of that port.
 *	\param[in] 	PortId:	ID of DIO PortId.
 *	\return		Dio_PortLevelType:	Level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 *	\brief		Service to set a level of the Port.
 *	\param[in] 	PortId: ID of DIO Port.
 *	\param[in] 	Level: 	Value to be written.
 *	\return		None.
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);

/**
 *	\brief		This Service reads a subset of the adjoining bits of a port.
 *	\param[in] 	ChannelGroupIdPtr: Pointer to ChannelGroup.
 *	\return		Dio_PortLevelType: Level of a subset of the adjoining bits of a port.
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/**
 *	\brief		Service to set a subset of the adjoining bits of a port to a specified level.
 *	\param[in] 	ChannelGroupIdPtr: 	Pointer to ChannelGroup.
 *	\param[in] 	Level: 				Value to be written.
 *	\return		None.
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,
							Dio_PortLevelType Level);

#if(DioVersionInfoApi == STD_ON)					
/**
 *	\brief		Service to get the version information of this module.
 *	\param[out] VersionInfo: Pointer to where to store the version information of this module.
 *	\return		None.
 */
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif /* DioVersionInfoApi check */

#if(DioFlipChannelApi == STD_ON)
/**
 *	\brief		Service to flip (change from 1 to 0 or from 0 to 1) the level
 *				of a channel and return the level of the channel after flip.
 *	\param[in] 	ChannelId: ID of DIO channel.
 *	\return		Dio_LevelType:	-	STD_HIGH: 	The physical level of the 
 *												corresponding Pin is STD_HIGH.
 *								-	STD_LOW: 	The physical level of the
 *												corresponding Pin is STD_LOW.
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif /* DioFlipChannelApi */

#if(DioMaskedWritePortApi == STD_ON)
/**
 *	\brief		Service to set the value of a given port with required mask.
 *	\param[in] 	PortId: ID of DIO Port.
 *	\param[in] 	Level: 	Value to be written.
 *	\param[in] 	Mask: 	Channels to be masked in the port.
 *	\return		None.
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level,
						Dio_PortLevelType Mask);
#endif /* DioMaskedWritePortApi check */
#endif /* DIO_H_ */ 

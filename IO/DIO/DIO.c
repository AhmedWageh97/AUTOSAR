/**
 *  \file	DIO.c
 *  \brief 	This module works on pins and ports which are configured 
 *  		by the PORT driver for this purpose.
 *  \author	Ahmed Wageh.
 *  \date	24/5/2020
 */
 
/* Inclusion */
#include "DIO.h"
#include <assert.h>
#include <stdio.h>

/* Private Variables */
extern HW_AddressBusSizeType HW_PortsAddresses[HW_NO_OF_PORTS];	/*!< Contains the base addresses for all GPIO PORTs */

#define DIO_PortsAddresses HW_PortsAddresses
/* Private Functions Proto Types */
/**
 *	\brief		To check the passed ChannelId.
 *	\param[in] 	ChannelId: ID of DIO channel.
 *	\return		Std_ReturnType:	-	E_OK: The ChannelId exists.
 *								-	E_NOT_OK:  The ChannelId doesn't exist.
 */
static Std_ReturnType DIO_ChannelIdCheck(Dio_ChannelType ChannelId);

/**
 *	\brief		To check the passed PortId.
 *	\param[in] 	PortId: ID of DIO port.
 *	\return		Std_ReturnType:	-	E_OK: The ChannelId exists.
 *								-	E_NOT_OK:  The ChannelId doesn't exist.
 */
static Std_ReturnType DIO_PortIdCheck(Dio_PortType PortId);

/**
 *	\brief		To check the passed PortId.
 *	\param[in] 	ChannelOffset: The position of the Channel Group on the port,counted from the LSB.
 *	\return		Std_ReturnType:	-	E_OK: The ChannelId exists.
 *								-	E_NOT_OK:  The ChannelId doesn't exist.
 */
static Std_ReturnType DIO_ChannelOffsetCheck(uint8 ChannelOffset);



/* Functions Declaration */
/* Public Functions Declaration */
/**
 *	\brief		To check the passed ChannelId.
 *	\param[in] 	ChannelId: ID of DIO channel.
 *	\return		Std_ReturnType:	-	E_OK: The ChannelId exists.
 *								-	E_NOT_OK:  The ChannelId doesn't exist.
 */
static Std_ReturnType DIO_ChannelIdCheck(Dio_ChannelType ChannelId)
{
	/* Return data definition */
	Std_ReturnType DIO_RetData = E_OK; 
	
	/* Function Logic */
	if(ChannelId >= DIO_CHANNEL_A0 && ChannelId <= DIO_CHANNEL_A7){
		DIO_RetData = E_OK; /* PORT A Channel */
	}
	else if(ChannelId >= DIO_CHANNEL_B0 && ChannelId <= DIO_CHANNEL_B7){
		DIO_RetData = E_OK; /* PORT B Channel */
	}
	else if(ChannelId >= DIO_CHANNEL_C0 && ChannelId <= DIO_CHANNEL_C7){
		DIO_RetData = E_OK; /* PORT C Channel */
	}
	else if(ChannelId >= DIO_CHANNEL_D0 && ChannelId <= DIO_CHANNEL_D7){
		DIO_RetData = E_OK; /* PORT D Channel */
	}
	else if(ChannelId >= DIO_CHANNEL_E0 && ChannelId <= DIO_CHANNEL_E5){
		DIO_RetData = E_OK; /* PORT E Channel */
	}
	else if(ChannelId >= DIO_CHANNEL_F0 && ChannelId <= DIO_CHANNEL_F4){
		DIO_RetData = E_OK; /* PORT F Channel */
	}
	else{
		DIO_RetData = E_NOT_OK; /* Channel doesn't exist */	
	}
	
	/* Return Data */
	/* 	Misra-C Rule
		Rule 14.7 (required): A function shall have a single point of 
		exit at the end of the function.
	*/
	return DIO_RetData;
}

/**
 *	\brief		To check the passed PortId.
 *	\param[in] 	PortId: ID of DIO port.
 *	\return		Std_ReturnType:	-	E_OK: The ChannelId exists.
 *								-	E_NOT_OK:  The ChannelId doesn't exist.
 */
static Std_ReturnType DIO_PortIdCheck(Dio_PortType PortId)
{
	/* Return data definition */
	Std_ReturnType DIO_RetData = E_OK; 
	
	/* Function Logic */
	if(PortId >= DIO_PORTA && PortId <= DIO_PORTF){
		DIO_RetData = E_OK;
	}
	else{
		DIO_RetData = E_NOT_OK;
	}
	
	/* Return Data */
	/* 	Misra-C Rule
		Rule 14.7 (required): A function shall have a single point of 
		exit at the end of the function.
	*/
	return DIO_RetData;
}

/**
 *	\brief		To check the passed PortId.
 *	\param[in] 	ChannelOffset: The position of the Channel Group on the port,counted from the LSB.
 *	\return		Std_ReturnType:	-	E_OK: The ChannelId exists.
 *								-	E_NOT_OK:  The ChannelId doesn't exist.
 */
static Std_ReturnType DIO_ChannelOffsetCheck(uint8 ChannelOffset)
{
	/* Return data definition */
	Std_ReturnType DIO_RetData = E_OK; 
	
	/* Function Logic */
	if(ChannelOffset >= 0 && ChannelOffset <= 7){
		DIO_RetData = E_OK;
	}
	else{
		DIO_RetData = E_NOT_OK;
	}
	
	/* Return Data */
	/* 	Misra-C Rule
		Rule 14.7 (required): A function shall have a single point of 
		exit at the end of the function.
	*/
	return DIO_RetData;
}



/* Public Functions Declaration */
/**
 *	\brief		Returns the value of the specified DIO channel.
 *	\param[in] 	ChannelId: ID of DIO channel.
 *	\return		Dio_LevelType:	-	STD_HIGH: The physical level of the corresponding 
 *									Pin is STD_HIGH.
 *								-	STD_LOW:  The physical level of the corresponding 
 *									Pin is STD_LOW.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	/* Needed Variables */
	Dio_PortType 	DIO_Port 	= (Dio_PortType)0xFF;	/* Initialization Data */
	uint8			DIO_Pin		= (uint8)0xFF;			/* Initialization Data */
	uint8			DIO_RegOffset = (uint8)0;			/* Initialization Data */
	Dio_LevelType	DIO_ReturnData = STD_LOW;			/* Initialization Data */
	/* Parameters check */
	assert(E_OK == DIO_ChannelIdCheck(ChannelId));
	
	/* Read the state of the channel */
	/* Tiva C supports bit addressing so we need to calculate the address 
	   to be accessed by adding 4*2^b as b is the bit number.
	   ChannelId has 2 bytes: Higher from 0 to 5 identifies the port
							  Lower from 0 to 7 identifies bit number */
	
	DIO_Port = (Dio_PortType)((ChannelId & 0xF0)>>4);
	DIO_Pin = (uint8)(ChannelId & 0x0F);
	DIO_RegOffset = (uint8)(1 << DIO_Pin);
	
	DIO_ReturnData = HW_R_8RIG(DIO_PortsAddresses[DIO_Port] + (DIO_RegOffset<<2)) ? STD_HIGH: STD_LOW;
	return DIO_ReturnData;
}

/**
 *	\brief		Service to set a level of a channel.
 *	\param[in] 	ChannelId: 	ID of DIO channel.
 *	\param[in] 	Level: 		Value to be written.
 *	\return		None.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	/* Needed Variables */
	Dio_PortType 	DIO_Port 	= (Dio_PortType)0xFF;	/* Initialization Data */
	uint8			DIO_Pin		= (uint8)0xFF;			/* Initialization Data */
	uint8			DIO_RegOffset = (uint8)0;

	/* Parameters check */
	assert(E_OK == DIO_ChannelIdCheck(ChannelId));
	assert(Level == STD_HIGH || Level == STD_LOW);
	
	/* Write the state of the channel */
	/* Tiva C supports bit addressing so we need to calculate the address 
	   to be accessed by adding 4*2^b as b is the bit number.
	   ChannelId has 2 bytes: Higher from 0 to 5 identifies the port
							  Lower from 0 to 7 identifies bit number */
	
	DIO_Port = (Dio_PortType)((ChannelId & 0xF0)>>4);
	DIO_Pin = (uint8)(ChannelId & 0x0F);
	DIO_RegOffset = (uint8)(1<<DIO_Pin);
	
	HW_W_8RIG(DIO_PortsAddresses[DIO_Port] + (DIO_RegOffset<<2), Level<<DIO_Pin);
}

/**
 *	\brief		Returns the level of all channels of that port.
 *	\param[in] 	PortId:	ID of DIO PortId.
 *	\return		Dio_PortLevelType:	Level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	/* Parameters check */
	assert(E_OK == DIO_PortIdCheck(PortId));

	
	/* Return needed data */
	return HW_R_8RIG(DIO_PortsAddresses[PortId] + 0x3FC);
}

/**
 *	\brief		Service to set a level of the Port.
 *	\param[in] 	PortId: ID of DIO Port.
 *	\param[in] 	Level: 	Value to be written.
 *	\return		None.
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
	/* Parameters check */
	assert(E_OK == DIO_PortIdCheck(PortId));
	
	/* Write needed level */
	HW_W_8RIG(DIO_PortsAddresses[PortId] + 0x3FC, Level);
}

/**
 *	\brief		This Service reads a subset of the adjoining bits of a port.
 *	\param[in] 	ChannelGroupIdPtr: Pointer to ChannelGroup.
 *	\return		Dio_PortLevelType: Level of a subset of the adjoining bits of a port.
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	/* Parameters check */
	assert(NULL_PTR != ChannelGroupIdPtr); /* NULL pointer check */
	assert(E_OK == DIO_ChannelOffsetCheck(ChannelGroupIdPtr->offset));	/* Check the offset of ChannelGroup */
	assert(E_OK == DIO_PortIdCheck(ChannelGroupIdPtr->port));			/* Check Port ID ChannelGroup */
	
	return HW_R_8RIG(DIO_PortsAddresses[ChannelGroupIdPtr->port] + 
					(ChannelGroupIdPtr->mask << (2 + ChannelGroupIdPtr->offset)));
}

/**
 *	\brief		Service to set a subset of the adjoining bits of a port to a specified level.
 *	\param[in] 	ChannelGroupIdPtr: 	Pointer to ChannelGroup.
 *	\param[in] 	Level: 				Value to be written.
 *	\return		None.
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,
							Dio_PortLevelType Level)
{
	/* Parameters check */
	assert(NULL_PTR != ChannelGroupIdPtr); /* NULL pointer check */
	assert(E_OK == DIO_ChannelOffsetCheck(ChannelGroupIdPtr->offset));	/* Check the offset of ChannelGroup */
	assert(E_OK == DIO_PortIdCheck(ChannelGroupIdPtr->port));			/* Check Port ID ChannelGroup */
	
	HW_W_8RIG(DIO_PortsAddresses[ChannelGroupIdPtr->port] + 
						(ChannelGroupIdPtr->mask << (2 + ChannelGroupIdPtr->offset)),  Level);
}

#if(DioVersionInfoApi == STD_ON)					
/**
 *	\brief		Service to get the version information of this module.
 *	\param[out] VersionInfo: Pointer to where to store the version information of this module.
 *	\return		None.
 */
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
	
}
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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType DIO_ReturnLevel;
	/* Parameters check */
	assert(E_OK == DIO_ChannelIdCheck(ChannelId));
	
	/* read and invert the current level */
	DIO_ReturnLevel = (Dio_LevelType)! Dio_ReadChannel(ChannelId);
	
	/* Apply the inverted level */
	Dio_WriteChannel(ChannelId, DIO_ReturnLevel);
		
	/* Return new level */
	return DIO_ReturnLevel;
}
#endif /* DioFlipChannelApi check */

#if(DioMaskedWritePortApi == STD_ON)
/**
 *	\brief		Service to set the value of a given port with required mask.
 *	\param[in] 	PortId: ID of DIO Port.
 *	\param[in] 	Level: 	Value to be written.
 *	\param[in] 	Mask: 	Channels to be masked in the port.
 *	\return		None.
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level,
						Dio_PortLevelType Mask)
{
	/* Parameters check */
	assert(E_OK == DIO_PortIdCheck(PortId));
	
	HW_W_8RIG(DIO_PortsAddresses[PortId] + (Mask << 2),  Level);
}
#endif /* DioMaskedWritePortApi check */
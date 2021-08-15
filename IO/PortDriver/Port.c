/**
 *  \file	Port.c
 *  \brief 	This module initializes the whole port structure of the microcontroller.
 *  		Many ports and port pins can be assigned to various functionalities like e.g.
 *  		-	General purpose I/O
 *  		-	ADC
 *  		-	SPI
 *  		-	SCI
 *  		-	PWM
 *  \author	Ahmed Wageh.
 *  \date	27/5/2020
 */

/* Inclusion */
#include "Port.h"
#include <assert.h>

/* Macroos */
/* Pin ID is defined as 2 bytes ID
   Higher byte contains Port Number
   Lower byte contains Pin Number */
/* Get Port number from Pin ID */
#define PORT_GET_PORT(PORT_PIN_TYPE)	(Port_PortType)((PORT_PIN_TYPE & (0xF0)) >> 4)

/* Get Pin number from Pin ID */
#define PORT_GET_PIN(PORT_PIN_TYPE)		(uint8)(PORT_PIN_TYPE & (0x0F))

/* Private variabes */
extern HW_AddressBusSizeType HW_PortsAddresses[HW_NO_OF_PORTS];	/*!< Contains the base addresses for all GPIO PORTs */


/* Local functions proto type */
/**
 *	\brief		Checks the Port_ConfigType parameter.
 *	\param[in] 	ConfigPtr: 	Pointer to configuration set.
 *	\return		StatusType: -	E_OK: if the size of the data
 *								in passed struct is equal to the size of Port_ConfigType.
 *							-	E_NOT_OK: otherwise.
 */
static StatusType Port_ConfigTypeCheck(const Port_ConfigType* ConfigPtr);

/**
 *	\brief		Checks the Port_PortPin parameter.
 *	\param[in] 	Port_PortPin: 	Pin which needs to be initial.
 *	\return		StatusType: -	E_OK: if the pin exists on the board.
 *							-	E_NOT_OK: otherwise.
 */
static StatusType Port_PortPinCheck(Port_PinType Port_PortPin);

/**
 *	\brief		Checks the Port_PinModeType parameter.
 *	\param[in] 	Port_PortPinMode: 	Pin Mode which needs to be initial.
 *	\return		StatusType: -	E_OK: if the Mode supported the board.
 *							-	E_NOT_OK: otherwise.
 */
static StatusType Port_PortPinModeCheck(Port_PinModeType Port_PortPinMode);

/* Local functions delcaration */

/**
 *	\brief		Checks the Port_ConfigType parameter.
 *	\param[in] 	ConfigPtr: 	Pointer to configuration set.
 *	\return		StatusType: -	E_OK: if the size of the data
 *								in passed struct is equal to the size of Port_ConfigType.
 *							-	E_NOT_OK: otherwise.
 */
static StatusType Port_ConfigTypeCheck(const Port_ConfigType* ConfigPtr)
{
	/* Needed variables */
	Port_PortType Port_PortId; /* Holds port ID */
	uint8 Port_PinNumber;	/* Holds Pin number */
	StatusType Port_RetData = E_OK; /* Holds return value */
	
	/* Null pointer check */
	if(NULL_PTR == ConfigPtr)
	{
		Port_RetData = E_NOT_OK;
	}
	else
	{
		/* MISRA-C Rule */
		/* Rule 14.10 (required): All if … else if constructs shall 
		   be terminated with an else clause */
	}
	
	/* size of the pointer check */
	if(sizeof(* ConfigPtr) != sizeof(Port_ConfigType)){
		Port_RetData = E_NOT_OK;
	}
	else
	{
		/* MISRA-C Rule */
		/* Rule 14.10 (required): All if … else if constructs shall 
		   be terminated with an else clause */
	}
	
	/* Containing data check */
	if(E_NOT_OK == Port_PortPinCheck(ConfigPtr->Port_Pin))
	{
		Port_RetData = E_NOT_OK;
	}	
	else
	{
		/* MISRA-C Rule */
		/* Rule 14.10 (required): All if … else if constructs shall 
		   be terminated with an else clause */
	}
	
	
	Port_PortPinModeCheck(ConfigPtr->Port_PinMode);
	
	switch(ConfigPtr->Port_Current)
	{
		case PORT_CURRENT_DEFAULT:
		case PORT_CURRENT_2mA:
		case PORT_CURRENT_4mA:
		case PORT_CURRENT_8mA:
			/* No action "correct cuttenr mode" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}
	
	switch(ConfigPtr->Port_PinMode)
	{
		case PORT_PIN_IN:
		case PORT_PIN_OUT:
			/* No action "correct direction" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}
	
	switch(ConfigPtr->Port_PinLevelInit)
	{
		case STD_HIGH:
		case STD_LOW:
			/* No action "correct level" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}
	
	switch(ConfigPtr->Port_PinPullUpRes)
	{
		case PORT_PULL_UP_DISABLE:
		case PORT_PULL_UP_ENABLE:
			/* No action "correct pull up setting" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}
	
	switch(ConfigPtr->Port_PinPullDownRes)
	{
		case PORT_PULL_DOWN_DISABLE:
		case PORT_PULL_DOWN_ENABLE:
			/* No action "correct pull down setting" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}
	
	switch(ConfigPtr->Port_PinOpenDrain)
	{
		case PORT_OPEN_DRAIN_DISABLE:	
		case PORT_OPEN_DRAIN_ENABLE	:
			/* No action "correct open drain setting" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}	
	
	/* Return the result */
	return Port_RetData;
}



/**
 *	\brief		Checks the Port_PortPin parameter.
 *	\param[in] 	Port_PortPin: 	Pin which needs to be initial.
 *	\return		StatusType: -	E_OK: if the pin exists on the board.
 *							-	E_NOT_OK: otherwise.
 */
static StatusType Port_PortPinCheck(Port_PinType Port_PortPin)
{
	/* Needed variables */
	Port_PortType Port_PortId;
	uint8 Port_PinNumber;
	StatusType Port_RetData = E_OK;
	
	/* Function logic */
	Port_PortId = PORT_GET_PORT(Port_PortPin);
	Port_PinNumber = PORT_GET_PIN(Port_PortPin);
	
	switch(Port_PortId)
	{
		case PORT_DIO_PORTA:
		case PORT_DIO_PORTB:
		case PORT_DIO_PORTC:
		case PORT_DIO_PORTD:
			if(Port_PinNumber > 7){
				Port_RetData = E_NOT_OK; /* PORT(A-D) has 8 channels from 0 to 7 */
			}
		break;
			
		case PORT_DIO_PORTE:
			if(Port_PinNumber > 5){
				Port_RetData = E_NOT_OK;	/* PORTE has 6 channels from 0 to 5 */
			}
		break;
		
		case PORT_DIO_PORTF:
			if(Port_PinNumber > 4){
				Port_RetData = E_NOT_OK;	/* PORTF has 5 channels from 0 to 4 */
			}
		break;
		
		default:
			Port_RetData = E_NOT_OK;	/* It's not a PORT */
	}
    
    /* return the result */
    return Port_RetData;
}

/**
 *	\brief		Checks the Port_PinModeType parameter.
 *	\param[in] 	Port_PortPinMode: 	Pin Mode which needs to be initial.
 *	\return		StatusType: -	E_OK: if the Mode supported the board.
 *							-	E_NOT_OK: otherwise.
 */
static StatusType Port_PortPinModeCheck(Port_PinModeType Port_PortPinMode)
{
    /* Needed variables */
    StatusType Port_RetData = E_OK;
    
    /* Function logic */
    switch(Port_PortPinMode)
	{
		case PORT_PIN_DIO:
		case PORT_PIN_ADC:
		case PORT_PIN_UART:
		case PORT_PIN_SSI:
		case PORT_PIN_I2C:
		case PORT_PIN_CAN:
		case PORT_PIN_USB:
		case PORT_PIN_AC:
		case PORT_PIN_PWM:
	    case PORT_PIN_QEI:
			/* No action "correct mode" */
		break;
		default:
			Port_RetData = E_NOT_OK;
	}
    
    /* Return the result */
    return Port_RetData;
}

/* Global functions definitions */
/**
 *	\brief		Initializes the Port Driver module.
 *	\param[in] 	ConfigPtr: 	Pointer to configuration set.
 *	\return		None.
 */
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	/* Data initialization */
	Port_PortType Port_PortId;
	uint8 Port_PinNumber;
    uint32 data;

	/* Parameters check */
	assert(Port_ConfigTypeCheck(ConfigPtr) == E_OK);
	
	/* Initialization Steps */
	/* get port ID */
	Port_PortId = PORT_GET_PORT(ConfigPtr->Port_Pin);	
	/* Enable the clock to the port */
    data = HW_SYSTEM_CONTROL_BA + HW_RCGC2_OFFSET;
    HW_S_BIT((HW_SYSTEM_CONTROL_BA + HW_RCGC2_OFFSET), Port_PortId);
    
    /* Wait for the clock and get pin data */
	Port_PortId = PORT_GET_PORT(ConfigPtr->Port_Pin);	
    Port_PinNumber = PORT_GET_PIN(ConfigPtr->Port_Pin);
    
    HW_S_BIT((HW_SYSTEM_CONTROL_BA + HW_RCGCGPIO_OFFSET), Port_PortId);
	
	/* Set the direction of the GPIO port pin */
	Port_SetPinDirection(ConfigPtr->Port_Pin, 
						ConfigPtr->Port_PinDirection);
	
	/* Set the drive strength for each of the pins */
	switch(ConfigPtr->Port_Current)
	{
		case PORT_CURRENT_DEFAULT:
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR2R_OFFSET), Port_PinNumber);
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR4R_OFFSET), Port_PinNumber);
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR8R_OFFSET), Port_PinNumber);
		break;
		case PORT_CURRENT_2mA:
            HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR2R_OFFSET), Port_PinNumber);
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR4R_OFFSET), Port_PinNumber);
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR8R_OFFSET), Port_PinNumber);
		break;
		case PORT_CURRENT_4mA:
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR2R_OFFSET), Port_PinNumber);
            HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR4R_OFFSET), Port_PinNumber);
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR8R_OFFSET), Port_PinNumber);
		break;
		case PORT_CURRENT_8mA:
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR2R_OFFSET), Port_PinNumber);
            HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR4R_OFFSET), Port_PinNumber);
            HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODR8R_OFFSET), Port_PinNumber);
		break;
		
		default:;
            /* MISRA-C rule */
            /* Rule 15.3 (required): The fnal clause of a switch 
			   statement shall be the default clause. */
	}
	
	/* Pull-up, pull-down, or open drain setting */
    /* Pull-up */
    /* Unlock the port to change CR */
    HW_W_8RIG((HW_PortsAddresses[Port_PortId] + HW_GPIOLOCK_OFFSET), HW_GPIO_UNLOCK_PATTERN);
    /* enable bit changing */
	HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOCR_OFFSET), Port_PinNumber);    
    switch(ConfigPtr->Port_PinPullUpRes)
    {
        case PORT_PULL_UP_DISABLE:
			HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOPUR_OFFSET), Port_PinNumber);             	
        break;
        case PORT_PULL_UP_ENABLE:
			HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOPUR_OFFSET), Port_PinNumber);            
        break;
        default:;
            /* MISRA-C rule */
            /* Rule 15.3 (required): The fnal clause of a switch 
			   statement shall be the default clause. */
    }
    /* Pull-down */
    /* Unlock the port to change CR */
    HW_W_8RIG((HW_PortsAddresses[Port_PortId] + HW_GPIOLOCK_OFFSET), HW_GPIO_UNLOCK_PATTERN);
    /* enable bit changing */
	HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOCR_OFFSET), Port_PinNumber);    
    switch(ConfigPtr->Port_PinPullDownRes)
    {
        case PORT_PULL_DOWN_DISABLE:
			HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOPDR_OFFSET), Port_PinNumber);             	
        break;
        case PORT_PULL_DOWN_ENABLE:
			HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOPDR_OFFSET), Port_PinNumber);            
        break;
        default:;
            /* MISRA-C rule */
            /* Rule 15.3 (required): The fnal clause of a switch 
			   statement shall be the default clause. */
    }
    /* open drain */
    switch(ConfigPtr->Port_PinOpenDrain)
    {
        case PORT_OPEN_DRAIN_DISABLE:
			HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOODR_OFFSET), Port_PinNumber);             
        break;
        case PORT_OPEN_DRAIN_ENABLE:
			HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOODR_OFFSET), Port_PinNumber);             	
        break;
        default:;
            /* MISRA-C rule */
            /* Rule 15.3 (required): The fnal clause of a switch 
			   statement shall be the default clause. */
    }
	
    /* Set pin mode needed registers */
    Port_SetPinMode(ConfigPtr->Port_Pin, ConfigPtr->Port_PinMode);
	
}

/**
 *	\brief		Sets the port pin direction.
 *	\param[in] 	Pin: 		Port Pin ID number.
 *	\param[in] 	Direction: 	Port Pin Direction.
 *	\return		None.
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    /* Needed variabes */
	Port_PortType Port_PortId;
	uint8 Port_PinNumber;
	
	/* Parameters check */
	assert(E_OK == Port_PortPinCheck(Pin));
	assert(PORT_PIN_IN == Direction ||
		   PORT_PIN_OUT == Direction);
		
	/* Function logic */
	/* Get port and pin information */
	Port_PortId = PORT_GET_PORT(Pin);
	Port_PinNumber = PORT_GET_PIN(Pin);
	/* Apply changes on needed registers */
	switch(Direction)
	{
		case PORT_PIN_IN:
			HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODIR_OFFSET), Port_PinNumber);
		break;
		
		case PORT_PIN_OUT:
			HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODIR_OFFSET), Port_PinNumber);
		break;
		
		default:;
            /* MISRA-C rule */
            /* Rule 15.3 (required): The fnal clause of a switch 
			   statement shall be the default clause. */
	}
}

/**
 *	\brief		Refreshes port direction.
 *	\param		None.
 *	\return		None.
 */
void Port_RefreshPortDirection(void)
{
    
}

/**
 *	\brief		Service to get the version information of this module.
 *	\param[out] VersionInfo: Pointer to where to store the version information of this module.
 *	\return		None.
 */
void Port_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    
}

/**
 *	\brief		Sets the port pin mode.
 *	\param[in] 	Pin: 	Port Pin ID number.
 *	\param[in] 	Mode: 	New Port Pin mode to be set on port pin.
 *	\return		None.
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    /* Needed variables */
    Port_PortType Port_PortId;
    uint8 Port_PinNumber;
    
    /* Parameters check */
    assert(E_OK == Port_PortPinCheck(Pin));
    assert(E_OK == Port_PortPinModeCheck(Mode));
    
    /* Get pin information */
    Port_PortId = PORT_GET_PORT(Pin);
    Port_PinNumber = PORT_GET_PIN(Pin);
    
    /* Enable GPIO pins as digital I/Os for all modes except for ADC */
	/* Unlock the port to change CR */
    HW_W_8RIG((HW_PortsAddresses[Port_PortId] + HW_GPIOLOCK_OFFSET), HW_GPIO_UNLOCK_PATTERN);
    /* enable bit changing */
	HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOCR_OFFSET), Port_PinNumber);    
    switch(Mode)
	{
		case PORT_PIN_ADC:
			HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODEN_OFFSET), Port_PinNumber);
		break;
		default:
			HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIODEN_OFFSET), Port_PinNumber);
	}
	
	/* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin */
	/* GPIOAFSEL cleared for DIO and ADC modes, and setted otherwise */
	/* Unlock the port to change CR */
    HW_W_8RIG((HW_PortsAddresses[Port_PortId] + HW_GPIOLOCK_OFFSET), HW_GPIO_UNLOCK_PATTERN);
    /* enable bit changing */
	HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOCR_OFFSET), Port_PinNumber);    
    switch(Mode)
	{
		case PORT_PIN_ADC:
		case PORT_PIN_DIO:
			HW_C_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOAFSEL_OFFSET), Port_PinNumber);
		break;
		default:
			HW_S_BIT((HW_PortsAddresses[Port_PortId] + HW_GPIOAFSEL_OFFSET), Port_PinNumber);
	}
}
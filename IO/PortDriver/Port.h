/**
 *  \file	Port.h
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

 /* Header guard */
#ifndef PORT_H_
#define PORT_H_

/* Inclusion */
#include "Std_Types.h"		/*!< Contains useful data types */
#include "PlatformTypes.h"	/*!< Contains standard data types */
#include "TivaHW.h"	/*!< Contains addresses and HW data for Tiva C */

/* Macros Definition */
/* Port_PinModeType Macros */
#define PORT_PIN_DIO   0x00	/*!< The pin operates as a Digital pin */
#define PORT_PIN_ADC   0x01	/*!< The pin operates as an ADC pin */
#define PORT_PIN_UART  0x02	/*!< The pin operates as an UART pin */
#define PORT_PIN_SSI   0x03	/*!< The pin operates as a SSI pin */
#define PORT_PIN_SPI   0x03	/*!< The pin operates as a SPI pin */
#define PORT_PIN_I2C   0x04	/*!< The pin operates as an I2C pin */
#define PORT_PIN_CAN   0x05	/*!< The pin operates as a CAN pin */
#define PORT_PIN_USB   0x06	/*!< The pin operates as an USB pin */
#define PORT_PIN_AC    0x07	/*!< The pin operates as an Analog Comaprator pin */
#define PORT_PIN_PWM   0x08	/*!< The pin operates as a PWM pin */
#define PORT_PIN_QEI   0x09	/*!< The pin operates as a QEI pin */

/* Port_PinDirectionType Macros */
#define PORT_PIN_IN  	0x00		/*!< Sets port pin as input */
#define PORT_PIN_OUT  	0x01		/*!< Sets port pin as output */

/* Port_PinPullUpResType Macros */
#define PORT_PULL_UP_DISABLE	0x00	/*!< Internal Pull Up Resistor is disabled */
#define PORT_PULL_UP_ENABLE		0x01	/*!< Internal Pull Up Resistor is enabled */

/* Port_PinPullDownResType Macros */
#define PORT_PULL_DOWN_DISABLE	0x00	/*!< Internal Pull Down Resistor is disabled */
#define PORT_PULL_DOWN_ENABLE	0x01	/*!< Internal Pull Down Resistor is enabled */

/* Port_PinOpenDrainType Macros */
#define PORT_OPEN_DRAIN_DISABLE	0x00	/*!< Internal Open Drain is disabled */
#define PORT_OPEN_DRAIN_ENABLE	0x01	/*!< Internal Open Drain is enabled */

/* Port_PinCurrentType Macros */
#define PORT_CURRENT_DEFAULT  	0x00		/*!< Default current setting */
#define PORT_CURRENT_2mA  		0x01		/*!< The corresponding GPIO pin has 2-mA drive */
#define PORT_CURRENT_4mA  		0x02		/*!< The corresponding GPIO pin has 4-mA drive */
#define PORT_CURRENT_8mA  		0x03		/*!< The corresponding GPIO pin has 8-mA drive */


/* default pin configurations */
/* DIO default pins configurations */
#define PORT_PIN_DIO_IN_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE 
/*!< To enable DIO Input pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is HIGH 
	 -	No current drive specified */

#define PORT_PIN_DIO_OUT_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_LOW, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable DIO Output pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

/* ADC default pins configurations */
#define PORT_PIN_ADC_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_LOW, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable ADC channel pin in the default setting which is:
     -  Input pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */


/* UART default pins configurations */
#define PORT_PIN_UART_RX_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable UART Reciever pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_UART_TX_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable UART Transmitter pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */


/* SPI default pin configurations */
/* Master pins configurations */
#define PORT_PIN_SPI_MASTER_SCK_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI source clock pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_SPI_MASTER_MOSI_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI MOSI pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_SPI_MASTER_MISO_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI MISO pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_SPI_MASTER_CS_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI Chip Select pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

/* Slave pins configurations */
#define PORT_PIN_SPI_SLAVE_SCK_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI source clock pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_SPI_SLAVE_MOSI_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI MOSI pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_SPI_SLAVE_MISO_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI MISO pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_SPI_SLAVE_CS_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable SPI Chip Select pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */


/* I2C pins configurations */
/* Master pins configurations */
#define PORT_PIN_I2C_MASTER_SCL_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable I2c source clock pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_I2C_MASTER_SDA_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_ENABLE
/*!< To enable I2C data pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Activate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

/* Slave pins configurations */
#define PORT_PIN_I2C_SLAVE_SCL_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable I2c source clock pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_I2C_SLAVE_SDA_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_ENABLE
/*!< To enable I2C data pin in the default setting which is:
     -  Output pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Activate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */


/* CAN pins configurations */
#define PORT_PIN_CAN_RX_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_IN, \
	STD_HIGH, \
	PORT_PULL_UP_ENABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable CAN Reciever pin in the default setting which is:
     -  Input pin
	 -	Activate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

#define PORT_PIN_UART_TX_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_HIGH, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable CAN Transmitter pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */

/* USB pins configurations */
/*!< \todo  study USB bus and implement default configrations 
            for its pins */


/* PWM pin configurations */
#define PORT_PIN_PWM_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_LOW, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable PWM pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */


/* PWM pin configurations */
#define PORT_PIN_QEI_DEFAULT	PORT_CURRENT_DEFAULT, \
	PORT_PIN_OUT, \
	STD_LOW, \
	PORT_PULL_UP_DISABLE, \
	PORT_PULL_DOWN_DISABLE, \
	PORT_OPEN_DRAIN_DISABLE
/*!< To enable QEI pin in the default setting which is:
     -  Output pin
	 -	Deactivate Pull Up Resistor
	 -	Deactivate Pull Down Resistor
	 -	Deactivate Open Drain 
	 -	Output level is LOW 
	 -	No current drive specified */


/* Defined data types */
typedef uint8 Port_PinModeType;	/*!< Different port pin modes */

typedef uint8 Port_PinPullUpResType; /*!< Pull up resistor setting */

typedef uint8 Port_PinPullDownResType; /*!< Pull down resistor setting */

typedef uint8 Port_PinOpenDrainType; /*!< Open drain setting */

typedef uint8 Port_PinCurrentType;	/*!< Set the drive strength for each of the pins */

typedef uint8 Port_PinDirectionType; /*!< Possible directions of a port pin */

typedef uint8 Port_PinPullUpResType;	/*!< For internal pull up status */

typedef uint8 Port_PinLevelType;	/*!< These are the possible levels a Pin can have
										(input or output). This could take STD_HIGH or STD_LOW */

#ifndef PORT_TYPE_H_	/* To avoid multiple definition of PortType */
#define PORT_TYPE_H_
typedef enum{
	PORT_DIO_PORTA = 0,		/*!< Port A */
	PORT_DIO_PORTB = 1,		/*!< Port B */
	PORT_DIO_PORTC = 2,		/*!< Port C */
	PORT_DIO_PORTD = 3,		/*!< Port D */
	PORT_DIO_PORTE = 4,		/*!< Port E */
	PORT_DIO_PORTF = 5		/*!< Port F */
}Port_PortType;	/*!< Numeric ID of a Port Type. */
#else

typedef Dio_PortType Port_PortType; 	/*!< Numeric ID of a Port Type. */

#define PORT_DIO_PORTA	DIO_PORTA	/*!< Port A */
#define PORT_DIO_PORTB	DIO_PORTB	/*!< Port B */
#define PORT_DIO_PORTC	DIO_PORTC	/*!< Port C */
#define PORT_DIO_PORTD	DIO_PORTD	/*!< Port D */
#define PORT_DIO_PORTE	DIO_PORTE	/*!< Port E */
#define PORT_DIO_PORTF	DIO_PORTF	/*!< Port F */

#endif /* PORT_TYPE_H_ */

typedef enum{
	/* PORT A Pins */
	// With Number on uC
	PORT_PIN_17 = 0x00,			/*!< Pin 17 */
	PORT_PIN_18 = 0x01,			/*!< Pin 18 */
	PORT_PIN_19 = 0x02,			/*!< Pin 19 */
	PORT_PIN_20 = 0x03,			/*!< Pin 20 */
	PORT_PIN_21 = 0x04,			/*!< Pin 21 */
	PORT_PIN_22 = 0x05,			/*!< Pin 22 */
	PORT_PIN_23 = 0x06,			/*!< Pin 23 */
	PORT_PIN_24 = 0x07,			/*!< Pin 24 */

	// With order respect to A
	PORT_PIN_A0 = 0x00,			/*!< Pin A0 */
	PORT_PIN_A1 = 0x01,			/*!< Pin A1 */
	PORT_PIN_A2 = 0x02,			/*!< Pin A2 */
	PORT_PIN_A3 = 0x03,			/*!< Pin A3 */
	PORT_PIN_A4 = 0x04,			/*!< Pin A4 */
	PORT_PIN_A5 = 0x05,			/*!< Pin A5 */
	PORT_PIN_A6 = 0x06,			/*!< Pin A6 */
	PORT_PIN_A7 = 0x07,			/*!< Pin A7 */

	// With alternate functions
	PORT_PIN_U0RX 		= 0x00,			/*!< Rx pin in UART 0 */
	PORT_PIN_CAN1Rx 	= 0x00,			/*!< CAN module 1 receive pin */

	PORT_PIN_U0TX 		= 0x01,			/*!< UART module 0 transmit pin */
	PORT_PIN_CAN1Tx 	= 0x01,			/*!< CAN module 1 transmit pin */

	PORT_PIN_SSI0CLK 	= 0x02,			/*!< SSI module 0 clock pin */

	PORT_PIN_SSI0FSS	= 0x03,			/*!< SSI module 0 frame signal pin */

	PORT_PIN_SSI0RX		= 0x04,			/*!< SSI module 0 receive pin */

	PORT_PIN_SSI0TX		= 0x05,			/*!< SSI module 0 transmit pin */


	/* PORT B Pins */
	// With Number on uC
	PORT_PIN_45 = 0x10,			/*!< Pin 45 */
	PORT_PIN_46 = 0x11,			/*!< Pin 46 */
	PORT_PIN_47 = 0x12,			/*!< Pin 47 */
	PORT_PIN_48 = 0x13,			/*!< Pin 48 */
	PORT_PIN_58 = 0x14,			/*!< Pin 58 */
	PORT_PIN_57 = 0x15,			/*!< Pin 57 */
	PORT_PIN_1 	= 0x16,			/*!< Pin 1 */
	PORT_PIN_4 	= 0x17,			/*!< Pin 4 */

	// With order respect to B
	PORT_PIN_B0 = 0x10,			/*!< Pin B0 */
	PORT_PIN_B1 = 0x11,			/*!< Pin B1 */
	PORT_PIN_B2 = 0x12,			/*!< Pin B2 */
	PORT_PIN_B3 = 0x13,			/*!< Pin B3 */
	PORT_PIN_B4 = 0x14,			/*!< Pin B4 */
	PORT_PIN_B5 = 0x15,			/*!< Pin B5 */
	PORT_PIN_B6 = 0x16,			/*!< Pin B6 */
	PORT_PIN_B7 = 0x17,			/*!< Pin B7 */

	// With alternate functions
	PORT_PIN_T2CCP0 = 0x10,			/*!< 16/32-Bit Timer 2 Capture/Compare/PWM 0 pin */
	PORT_PIN_U1Rx 	= 0x10,			/*!< UART module 1 receive */
	PORT_PIN_USB0ID = 0x10,			/*!< This signal senses the state of the USB ID signal.
										 The USB PHY enables an integrated pull-up, and an
										 external element (USB connector) indicates the initial
										 state of the USB controller (pulled down is the A side
										 of the cable and pulled up is the B side). */


	PORT_PIN_T2CCP1 	= 0x11,			/*!< 16/32-Bit Timer 2 Capture/Compare/PWM 1 pin */
	PORT_PIN_U1Tx 		= 0x11,			/*!< UART module 1 transmit pin */
	PORT_PIN_USB0VBUS 	= 0x11,			/*!< This signal is used during the session request
											 protocol. This signal allows the USB PHY to both
											 sense the voltage level of VBUS, and pull up VBUS
											 momentarily during VBUS pulsing */

	PORT_PIN_T3CCP0 	= 0x12,			/*!< 16/32-Bit Timer 3 Capture/Compare/PWM 0 pin */
	PORT_PIN_I2C0SCL 	= 0x12,			/*!< I2C module 0 clock. Note that this signal has an
											 active pull-up. The corresponding port pin should
											 not be configured as open drain. */

	PORT_PIN_I2C0SDA 	= 0x13,			/*!< I2C module 0 data pin */
	PORT_PIN_T3CCP1 	= 0x13,			/*!< 16/32-Bit Timer 3 Capture/Compare/PWM 1 pin */

	PORT_PIN_AIN10 		= 0x14,			/*!< Analog-to-digital converter input 10 pin */
	PORT_PIN_CAN0Rx 	= 0x14,			/*!< CAN module 0 receive pin */
	PORT_PIN_SSI2Clk	= 0x14,			/*!< SSI module 2 clock pin */
	PORT_PIN_T1CCP0 	= 0x14,			/*!< 16/32-Bit Timer 1 Capture/Compare/PWM 0 pin */
	PORT_PIN_M0PWM2 	= 0x14,			/*!< Motion Control Module 0 PWM 2. This signal
											 is controlled by Module 0 PWM Generator 1 */

	PORT_PIN_AIN11 		= 0x15,			/*!< Analog-to-digital converter input 11 pin */
	PORT_PIN_CAN0Tx 	= 0x15,			/*!< CAN module 0 transmit pin */
	PORT_PIN_SSI2Fss 	= 0x15,			/*!< SSI module 2 frame signal pin */
	PORT_PIN_T1CCP1 	= 0x15,			/*!< 16/32-Bit Timer 1 Capture/Compare/PWM 1 pin */
	PORT_PIN_M0PWM3 	= 0x15,			/*!< Motion Control Module 0 PWM 3. This signal
											 is controlled by Module 0 PWM Generator 1 */

	PORT_PIN_T0CCP0 = 0x16,			/*!< 16/32-Bit Timer 0 Capture/Compare/PWM 0 pin */
	PORT_PIN_SSI2Rx = 0x16,			/*!< SSI module 2 receive pin */
	PORT_PIN_M0PWM0 = 0x16,			/*!< Motion Control Module 0 PWM 0. This signal is
										 controlled  Module 0 PWM Generator 0 */

	PORT_PIN_T0CCP1 = 0x17,			/*!< 16/32-Bit Timer 0 Capture/Compare/PWM 1 pin */
	PORT_PIN_SSI2Tx = 0x17,			/*!< SSI module 2 transmit pin */
	PORT_PIN_M0PWM1 = 0x17,			/*!< Motion Control Module 0 PWM 1. This signal is
										 controlled by Module 0 PWM Generator 0 */


	/* PORT C Pins */
	// With Number on uC
	PORT_PIN_52 = 0x20,			/*!< Pin 52 */
	PORT_PIN_51 = 0x21,			/*!< Pin 51 */
	PORT_PIN_50 = 0x22,			/*!< Pin 50 */
	PORT_PIN_49 = 0x23,			/*!< Pin 49 */
	PORT_PIN_16 = 0x24,			/*!< Pin 16 */
	PORT_PIN_15 = 0x25,			/*!< Pin 15 */
	PORT_PIN_14 = 0x26,			/*!< Pin 14 */
	PORT_PIN_13 = 0x27,			/*!< Pin 13 */

	// With order respect to C
	PORT_PIN_C0 = 0x20,			/*!< Pin C0 */
	PORT_PIN_C1 = 0x21,			/*!< Pin C1 */
	PORT_PIN_C2 = 0x22,			/*!< Pin C2 */
	PORT_PIN_C3 = 0x23,			/*!< Pin C3 */
	PORT_PIN_C4 = 0x24,			/*!< Pin C4 */
	PORT_PIN_C5 = 0x25,			/*!< Pin C5 */
	PORT_PIN_C6 = 0x26,			/*!< Pin C6 */
	PORT_PIN_C7 = 0x27,			/*!< Pin C7 */

	// With alternate functions
	PORT_PIN_TCK 	= 0x20,			/*!< JTAG/SWD CLK pin */
	PORT_PIN_SWCLK 	= 0x20,			/*!< JTAG/SWD CLK */
	PORT_PIN_T4CCP0 = 0x20,			/*!< 16/32-Bit Timer 4 Capture/Compare/PWM 0 pin */

	PORT_PIN_TMS 	= 0x21,			/*!< JTAG TMS and SWDIO pin */
	PORT_PIN_SWDIO 	= 0x21,			/*!< JTAG TMS and SWDIO pin */
	PORT_PIN_T4CCP1 = 0x21,			/*!< 16/32-Bit Timer 4 Capture/Compare/PWM 1 pin */

	PORT_PIN_TDI 	= 0x22,			/*!< JTAG TDI pin */
	PORT_PIN_T5CCP0 = 0x22,			/*!< 16/32-Bit Timer 5 Capture/Compare/PWM 0 pin */

	PORT_PIN_TDO 	= 0x23,			/*!< JTAG TDO and SWO pin */
	PORT_PIN_SWO 	= 0x23,			/*!< JTAG TDO and SWO pin */
	PORT_PIN_T5CCP1 = 0x23,			/*!< 16/32-Bit Timer 5 Capture/Compare/PWM 1 pin */

	PORT_PIN_WT0CCP0 	= 0x24,			/*!< 32/64-Bit Wide Timer 0 Capture/Compare/PWM 0 pin */
	PORT_PIN_U4Rx 		= 0x24,			/*!< UART module 4 receive pin */
	/*PORT_PIN_U1Rx 		= 0x24,			*!< UART module 1 receive pin */
	PORT_PIN_U1RTS 		= 0x24,			/*!< UART module 1 Request to Send modem flow control output line */
	PORT_PIN_IDX1 		= 0x24,			/*!< QEI module 1 index */
	PORT_PIN_C1_NEG 	= 0x24,			/*!< Analog comparator 1 negative input pin */
	PORT_PIN_M0PWM6 	= 0x24,			/*!< Motion Control Module 0 PWM 6. This signal is
											 controlled by Module 0 PWM Generator 3 */

	PORT_PIN_C1_POS 	= 0x25,			/*!< Analog comparator 1 positive input pin */
	PORT_PIN_PhA1 		= 0x25,			/*!< QEI module 1 phase A */
	PORT_PIN_U1CTS 		= 0x25,			/*!< UART module 1 Clear To Send modem flow control input signal */
	/*PORT_PIN_U1Tx 		= 0x25,			!< UART module 1 transmit */
	PORT_PIN_U4Tx 		= 0x25,			/*!< UART module 4 transmit */
	PORT_PIN_WT0CCP1 	= 0x25,			/*!< 32/64-Bit Wide Timer 0 Capture/Compare/PWM 1 */
	PORT_PIN_M0PWM7 	= 0x25,			/*!< Motion Control Module 0 PWM 7. This signal is
											 controlled by Module 0 PWM Generator 3 */

	PORT_PIN_C0_POS 	= 0x26,			/*!< Analog comparator 0 positive input */
	PORT_PIN_PhB1 		= 0x26,			/*!< QEI module 1 phase B */
	PORT_PIN_U3Rx 		= 0x26,			/*!< UART module 3 receive */
	PORT_PIN_WT1CCP0 	= 0x26,			/*!< 32/64-Bit Wide Timer 1 Capture/Compare/PWM 0 */
	PORT_PIN_USB0EPEN 	= 0x26,			/*!< Optionally used in Host mode to control an
											 external power source to supply power to the
											 USB bus */

	PORT_PIN_C0_NEG 	= 0x27,			/*!< Analog comparator 0 negative input */
	PORT_PIN_U3Tx 		= 0x27,			/*!< UART module 3 transmit */
	PORT_PIN_WT1CCP1 	= 0x27,			/*!< 32/64-Bit Wide Timer 1 Capture/Compare/PWM 1 */
	PORT_PIN_USB0PFLT 	= 0x27,			/*!< Optionally used in Host mode by an external
											 power source to indicate an error state by that
											 power source */

	/* PORT D Pins */
	// With Number on uC
	PORT_PIN_61 = 0x30,			/*!< Pin 61 */
	PORT_PIN_62 = 0x31,			/*!< Pin 62 */
	PORT_PIN_63 = 0x32,			/*!< Pin 63 */
	PORT_PIN_64 = 0x33,			/*!< Pin 64 */
	PORT_PIN_43 = 0x34,			/*!< Pin 43 */
	PORT_PIN_44 = 0x35,			/*!< Pin 44 */
	PORT_PIN_53 = 0x36,			/*!< Pin 53 */
	PORT_PIN_10 = 0x37,			/*!< Pin 10 */

	// With order respect to D
	PORT_PIN_D0 = 0x30,			/*!< Pin D0 */
	PORT_PIN_D1 = 0x31,			/*!< Pin D1 */
	PORT_PIN_D2 = 0x32,			/*!< Pin D2 */
	PORT_PIN_D3 = 0x33,			/*!< Pin D3 */
	PORT_PIN_D4 = 0x34,			/*!< Pin D4 */
	PORT_PIN_D5 = 0x35,			/*!< Pin D5 */
	PORT_PIN_D6 = 0x36,			/*!< Pin D6 */
	PORT_PIN_D7 = 0x37,			/*!< Pin D7 */

	// With alternate functions
	PORT_PIN_AIN7 		= 0x30,			/*!< Analog-to-digital converter input 7 */
	PORT_PIN_SSI1Clk 	= 0x30,			/*!< SSI module 1 clock */
	PORT_PIN_SSI3Clk 	= 0x30,			/*!< SSI module 3 clock */
	PORT_PIN_WT2CCP0 	= 0x30,			/*!< 32/64-Bit Wide Timer 2 Capture/Compare/PWM 0 */
	/*PORT_PIN_M0PWM6 	= 0x30,			!< Motion Control Module 0 PWM 6. This signal
											 is controlled by Module 0 PWM Generator 3 */
	PORT_PIN_M1PWM0 	= 0x30,			/*!< Motion Control Module 1 PWM 0. This signal
											 is controlled by Module 1 PWM Generator 0 */
	PORT_PIN_I2C3SCL 	= 0x30,			/*!< I2C module 3 clock. Note that this signal
											 has an active pull-up. The corresponding
											 port pin should not be configured as open
											 drain */

	PORT_PIN_AIN6 		= 0x31,			/*!< Analog-to-digital converter input 6 */
	PORT_PIN_I2C3SDA 	= 0x31,			/*!< I2C module 3 data */
	PORT_PIN_SSI1Fss 	= 0x31,			/*!< SSI module 1 frame signal */
	PORT_PIN_SSI3Fss 	= 0x31,			/*!< SSI module 3 frame signal */
	PORT_PIN_WT2CCP1 	= 0x31,			/*!< 32/64-Bit Wide Timer 2 Capture/Compare/PWM 1 */
	/*PORT_PIN_M0PWM7 	= 0x31,			!< Motion Control Module 0 PWM 7. This signal
											 is controlled by Module 0 PWM Generator 3 */
	PORT_PIN_M1PWM1 	= 0x31,			/*!< Motion Control Module 1 PWM 1. This signal
											 is controlled by Module 1 PWM Generator 0 */

	PORT_PIN_AIN5 		= 0x32,			/*!< Analog-to-digital converter input 5 */
	PORT_PIN_M0FAULT0 	= 0x32,			/*!< Motion Control Module 0 PWM Fault 0 */
	PORT_PIN_SSI1Rx 	= 0x32,			/*!< SSI module 1 receive */
	PORT_PIN_SSI3Rx 	= 0x32,			/*!< SSI module 3 receive */
	PORT_PIN_WT3CCP0 	= 0x32,			/*!< 32/64-Bit Wide Timer 3 Capture/Compare/PWM 0 */
	/*PORT_PIN_USB0EPEN 	= 0x32,			!< Optionally used in Host mode to control an
											 external power source to supply power to
											 the USB bus */

	PORT_PIN_AIN4 		= 0x33,			/*!< Analog-to-digital converter input 4 */
	PORT_PIN_IDX0 		= 0x33,			/*!< QEI module 0 index */
	PORT_PIN_SSI1Tx 	= 0x33,			/*!< SSI module 1 transmit */
	PORT_PIN_SSI3Tx 	= 0x33,			/*!< SSI module 3 transmit */
	PORT_PIN_WT3CCP1 	= 0x33,			/*!< 32/64-Bit Wide Timer 3 Capture/Compare/PWM 1 */
	/*PORT_PIN_USB0PFLT 	= 0x33,			!< Optionally used in Host mode by an external
											 power source to indicate an error state by
											 that power source*/

	PORT_PIN_U6Rx 		= 0x34,			/*!< UART module 6 receive */
	PORT_PIN_WT4CCP0 	= 0x34,			/*!< 32/64-Bit Wide Timer 4 Capture/Compare/PWM 0 */
	PORT_PIN_USB0DM 	= 0x34,			/*!< Bidirectional differential data pin (D- per USB
											 specification) for USB0 */

	PORT_PIN_U6Tx 		= 0x35,			/*!< UART module 6 transmit */
	PORT_PIN_WT4CCP1 	= 0x35,			/*!< 32/64-Bit Wide Timer 4 Capture/Compare/PWM 1 */
	PORT_PIN_USB0DP 	= 0x35,			/*!< Bidirectional differential data pin (D+ per USB
											 specification) for USB0 */

	/*PORT_PIN_M0FAULT0 	= 0x36,			!< Motion Control Module 0 PWM Fault 0 */
	PORT_PIN_PhA0 		= 0x36,			/*!< QEI module 0 phase A */
	PORT_PIN_U2Rx 		= 0x36,			/*!< UART module 2 receive */
	PORT_PIN_WT5CCP0 	= 0x36,			/*!< 32/64-Bit Wide Timer 5 Capture/Compare/PWM 0 */

	PORT_PIN_NMI 		= 0x37,			/*!< Non-maskable interrupt */
	PORT_PIN_PhB0 		= 0x37,			/*!< QEI module 0 phase B */
	PORT_PIN_U2Tx 		= 0x37,			/*!< UART module 2 transmit */
	PORT_PIN_WT5CCP1 	= 0x37,			/*!< 32/64-Bit Wide Timer 5 Capture/Compare/PWM 1 */



	/* PORT E Pins */
	// With Number on uC
	PORT_PIN_9 	= 0x40,			/*!< Pin 9 */
	PORT_PIN_8 	= 0x41,			/*!< Pin 8 */
	PORT_PIN_7 	= 0x42,			/*!< Pin 7 */
	PORT_PIN_6 	= 0x43,			/*!< Pin 6 */
	PORT_PIN_59 = 0x44,			/*!< Pin 59 */
	PORT_PIN_60 = 0x45,			/*!< Pin 60 */

	// With order respect to E
	PORT_PIN_E0 = 0x40,			/*!< Pin E0 */
	PORT_PIN_E1 = 0x41,			/*!< Pin E1 */
	PORT_PIN_E2 = 0x42,			/*!< Pin E2 */
	PORT_PIN_E3 = 0x43,			/*!< Pin E3 */
	PORT_PIN_E4 = 0x44,			/*!< Pin E4 */
	PORT_PIN_E5 = 0x45,			/*!< Pin E4 */

	// With alternate functions
	PORT_PIN_AIN3	= 0x40,			/*!< Analog-to-digital converter input 3 */
	PORT_PIN_U7Rx	= 0x40,			/*!< UART module 7 receive */

	PORT_PIN_AIN2	= 0x41,			/*!< Analog-to-digital converter input 2 */
	PORT_PIN_U7Tx	= 0x41,			/*!< UART module 7 transmit */

	PORT_PIN_AIN1	= 0x42,			/*!< Analog-to-digital converter input 1 */

	PORT_PIN_AIN0	= 0x43,			/*!< Analog-to-digital converter input 0 */

	PORT_PIN_AIN9 		= 0x44,			/*!< Analog-to-digital converter input 9 */
	/*PORT_PIN_CAN0Rx 	= 0x44,			!< CAN module 0 receive */
	PORT_PIN_U5Rx 		= 0x44,			/*!< UART module 5 receive */
	PORT_PIN_I2C2SCL 	= 0x44,			/*!< I2C module 2 clock. Note that this signal
											 has an active pull-up. The corresponding
											 port pin should not be configured as open
											 drain */
	PORT_PIN_M0PWM4 	= 0x44,			/*!< Motion Control Module 0 PWM 4. This signal
											 is controlled by Module 0 PWM Generator 2 */
	PORT_PIN_M1PWM2 	= 0x44,			/*!< Motion Control Module 1 PWM 2. This signal
											 is controlled by Module 1 PWM Generator 1 */

	PORT_PIN_AIN8 		= 0x45,			/*!< Analog-to-digital converter input 8 */
	/*PORT_PIN_CAN0Tx 	= 0x45,			!< CAN module 0 transmit */
	PORT_PIN_I2C2SDA 	= 0x45,			/*!< I2C module 2 data */
	PORT_PIN_U5Tx 		= 0x45,			/*!< UART module 5 transmit */
	PORT_PIN_M0PWM5 	= 0x45,			/*!< Motion Control Module 0 PWM 5. This signal
											 is controlled by Module 0 PWM Generator 2 */
	PORT_PIN_M1PWM3 	= 0x45,			/*!< Motion Control Module 1 PWM 3. This signal
											 is controlled by Module 1 PWM Generator 1 */


	/* PORT F Pins */
	// With Number on uC
	PORT_PIN_28 = 0x50,			/*!< Pin 28 */
	PORT_PIN_29 = 0x51,			/*!< Pin 29 */
	PORT_PIN_30 = 0x52,			/*!< Pin 30 */
	PORT_PIN_31 = 0x53,			/*!< Pin 31 */
	PORT_PIN_5	= 0x54,			/*!< Pin 5 */

	// With order respect to F
	PORT_PIN_F0 = 0x50,			/*!< Pin F0 */
	PORT_PIN_F1 = 0x51,			/*!< Pin F1 */
	PORT_PIN_F2 = 0x52,			/*!< Pin F2 */
	PORT_PIN_F3 = 0x53,			/*!< Pin F3 */
	PORT_PIN_F4 = 0x54,			/*!< Pin F4 */

	// With alternate functions
	PORT_PIN_C0o 	= 0x50,			/*!< Analog comparator 0 output */
	/*PORT_PIN_CAN0Rx = 0x50,		!< CAN module 0 receive */
	/*PORT_PIN_NMI 	= 0x50,			 Non-maskable interrupt */
	/*PORT_PIN_PhA0 	= 0x50,		!< QEI module 0 phase A */
	/*PORT_PIN_SSI1Rx = 0x50,		!< SSI module 1 receive */
	/*PORT_PIN_T0CCP0 = 0x50,		!< 16/32-Bit Timer 0 Capture/Compare/PWM 0 */
	/*PORT_PIN_U1RTS 	= 0x50,		!< UART module 1 Request to Send modem flow control
										 output line */
	PORT_PIN_M1PWM4 = 0x50,			/*!< Motion Control Module 1 PWM 4. This
										 signal is controlled by Module 1 PWM Generator 2 */

	PORT_PIN_C1o 	= 0x51,			/*!< Analog comparator 1 output */
	/*PORT_PIN_PhB0 	= 0x51,			!< QEI module 0 phase B */
	/*PORT_PIN_SSI1Tx = 0x51,			!< SSI module 1 transmit */
	/*PORT_PIN_T0CCP1 = 0x51,			!< 16/32-Bit Timer 0 Capture/Compare/PWM 1 */
	PORT_PIN_TRD1 	= 0x51,			/*!< Trace data 1 */
	/*PORT_PIN_U1CTS 	= 0x51,			!< UART module 1 Clear To Send modem flow control
										 input signal */
	PORT_PIN_M1PWM5 = 0x51,			/*!< Motion Control Module 1 PWM 5. This signal
										 is controlled by Module 1 PWM Generator 2 */

	/*PORT_PIN_M0FAULT0 	= 0x52,			< Motion Control Module 0 PWM Fault 0 */
	PORT_PIN_M1PWM6 	= 0x52,			/*!< Motion Control Module 1 PWM 6. This
											 signal is controlled by Module 1 PWM
											 Generator 3 */
	/*PORT_PIN_SSI1Clk 	= 0x52,			*!< SSI module 1 clock */
	/*PORT_PIN_T1CCP0 	= 0x52,			*!< 16/32-Bit Timer 1 Capture/Compare/PWM 0 */
	PORT_PIN_TRD0 		= 0x52,			/*!< Trace data 0 */

	/*PORT_PIN_CAN0Tx 	= 0x53,			*!< CAN module 0 transmit */
	PORT_PIN_M1PWM7 	= 0x53,			/*!< Motion Control Module 1 PWM 7.
											 This signal is controlled by Module
											 1 PWM Generator 3 */
	/*PORT_PIN_SSI1Fss 	= 0x53,			*!< SSI module 1 frame signal */
	/*PORT_PIN_T1CCP1 	= 0x53,			*!< 16/32-Bit Timer 1 Capture/Compare/PWM 1 */
	PORT_PIN_TRCLK 		= 0x53,			/*!< Trace clock */

	/*PORT_PIN_IDX0 		= 0x54,			*!< QEI module 0 index */
	PORT_PIN_M1FAULT0 	= 0x54,			/*!< Motion Control Module 1 PWM Fault 0 */
	/*PORT_PIN_T2CCP0 	= 0x54,			*!< 16/32-Bit Timer 2 Capture/Compare/PWM 0 */
	/*PORT_PIN_USB0EPEN 	= 0x54,			*!< Optionally used in Host mode to control an
											 external power source to supply power to
											 the USB bus */
}Port_PinType; /*!< Data type for the symbolic name of a port pin. */


/* Configurations structure */
typedef struct{
	/* Can't use bitfields for This  member
	   ====== MISRA-C Rule ====== */
	/* Rule 6.4 (required): Bit felds shall only be defined
	   to be of type unsigned int or signed int. */
	Port_PinType	 		Port_Pin;				/*!< Identifes which pin in the on the chip */

	Port_PinModeType Port_PinMode :4;		/*!< Identifes the mode of the Pin */
	Port_PinCurrentType Port_Current :2; /*!< Identifies the current driven from the GPIO pin  */
	Port_PinDirectionType	Port_PinDirection :1;		/*!< Identifes the direction of the Pin */
	Port_PinLevelType		Port_PinLevelInit :1;	/*!< Identifes the initial level of the pin*/
    Port_PinPullUpResType   Port_PinPullUpRes :1;   /*!< Identifies the state of pull up resistor */                       
    Port_PinPullDownResType Port_PinPullDownRes :1; /*!< Identifies the state of pull down resistor */                           
    Port_PinOpenDrainType   Port_PinOpenDrain :1;   /*!< Identifies the state of open drain resistor */

}Port_ConfigType; /*!< Contains the initialization data for this module. */


/* Functions proto types */
/**
 *	\brief		Initializes the Port Driver module.
 *	\param[in] 	ConfigPtr: 	Pointer to configuration set.
 *	\return		None.
 */
void Port_Init(const Port_ConfigType* ConfigPtr);

/**
 *	\brief		Sets the port pin direction.
 *	\param[in] 	Pin: 		Port Pin ID number.
 *	\param[in] 	Direction: 	Port Pin Direction.
 *	\return		None.
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

/**
 *	\brief		Refreshes port direction.
 *	\param		None.
 *	\return		None.
 */
void Port_RefreshPortDirection(void);

/**
 *	\brief		Service to get the version information of this module.
 *	\param[out] VersionInfo: Pointer to where to store the version information of this module.
 *	\return		None.
 */
void Port_GetVersionInfo(Std_VersionInfoType* VersionInfo);

/**
 *	\brief		Sets the port pin mode.
 *	\param[in] 	Pin: 	Port Pin ID number.
 *	\param[in] 	Mode: 	New Port Pin mode to be set on port pin.
 *	\return		None.
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);


#endif /* PORT_H_ */

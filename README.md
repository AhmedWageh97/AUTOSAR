# AUTOSAR
 This Repo contains the implementation of some [AUTOSAR](https://www.autosar.org/) modules. All drivers/modules wrote to run on TivaC(TM4C123GH6PM) board.

# Implemented modules
 I have implemented some modules according to [AUTOSAR](https://www.autosar.org/) standards. I have implemented:
 * DIO module: The DIO Driver provides services for reading and writing to/from:
	* DIO Channels (Pins)
	* DIO Ports
	* DIO Channel Groups

	This module works on pins and ports which are configured by the __PORT driver__ for this purpose. For this reason, there is no configuration and initialization of this port structure in the __DIO Driver__. You can find the software requirements and software specifications of __DIO driver__ [here](https://www.autosar.org/nc/document-search/?tx_sysgsearch_pi1%5Bquery%5D=DIO&tx_sysgsearch_pi1%5Bcategory%5D%5B145%5D=145&tx_sysgsearch_pi1%5Bcategory%5D%5B146%5D=146&tx_sysgsearch_pi1%5Bcategory%5D%5B147%5D=147&tx_sysgsearch_pi1%5Bcategory%5D%5B32%5D=32&tx_sysgsearch_pi1%5Bcategory%5D%5B148%5D=148)
 * PORT Driver module: This module shall provide the service for initializing the whole PORT structure of the microcontroller. Many ports and port pins can be assigned to various functionalities, e.g.
	* General purpose I/O
	* ADC
	* SPI
	* SCI
	* PWM
	* CAN
	* LIN
	* etc
	
	Until now, we only implemented it to configure any port as General purpose I/O(DIO) port. You can find the software requirements and software specifications of __PORT driver__ [here](https://www.autosar.org/nc/document-search/?tx_sysgsearch_pi1%5Bquery%5D=PORT&tx_sysgsearch_pi1%5Bcategory%5D%5B145%5D=145&tx_sysgsearch_pi1%5Bcategory%5D%5B146%5D=146&tx_sysgsearch_pi1%5Bcategory%5D%5B147%5D=147&tx_sysgsearch_pi1%5Bcategory%5D%5B32%5D=32&tx_sysgsearch_pi1%5Bcategory%5D%5B148%5D=148)
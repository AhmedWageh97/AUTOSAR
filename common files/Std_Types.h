/**
 *  \file	Std_Types.h
 *  \author	Ahmed Wageh.
 *  \date	24/5/2020
 */
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "PlatformTypes.h"

 
/*Local Macro Definition*/

#ifndef NULL
#define	NULL	0
#endif

#ifndef	NULL_PTR
#define NULL_PTR  ((void*)0)
#endif

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u

#define STD_ON 0x01u
#define STD_OFF 0x00u

#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */
#define STD_LOW 0x00u /* Physical state 0V */

/*Local Data-Types Definitions*/

/*****************************************************************************************************/
/**	Description:	This type can be used as standard API return type which is shared between the 	**/
/**					RTE and the BSW modules.														**/
/**																									**/
/**	Type:	uint8.																					**/
/**																									**/
/**	Values:		-	E_OK		=>	0x00															**/
/**				-	E_NOT_OK	=>	0x01u															**/
/**				-	0x02-0x3F	=>	Available to user specific errors								**/
/*****************************************************************************************************/	
typedef uint8 Std_ReturnType;

/*****************************************************************************************************/
/**	Description:	This type shall be used to request the version of a BSW module using the 		**/
/**					<Modulename>_GetVersionInfo() function.											**/
/**																									**/
/**	Type:	Structure.																				**/
/**																									**/
/**	Elements:	-	vendorID			=>	uint16													**/
/**				-	moduleID			=>	uint16													**/
/**				-	sw_major_version	=>	uint8													**/
/**				-	sw_minor_version	=>	uint8													**/
/**				-	sw_patch_version	=>	uint8													**/
/*****************************************************************************************************/
typedef struct { 
				 uint16 vendorID;
				 
                 uint16 moduleID;
				 
				 uint8 sw_major_version;
				 
				 uint8 sw_minor_version;
				 
				 uint8 sw_patch_version;			   
			   }Std_VersionInfoType;  
#endif /*STD_TYPES_H*/

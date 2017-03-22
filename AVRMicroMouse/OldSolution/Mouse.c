/**
 * Main Primary function to control the whole mouse
 *
 */


/*   All header files are included in this section 	*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h> 

//Include our modules

#include "CommunicationsController.h"


//Defines

#define F_CPU 20000000



/**
 * Primary start function 
 * @return  [description]
 */
int main(void)
{




}



// ENUMS DECLARATIONS
//***************************************

/**
 * Levels of debugging avalible,
 * 	
 * 		EXTREMEVERBOSE -> Log Everything
 * 	 	LIGHTLOG ->	Standard Logging Level
 *    	NOLOG -> Logging Disabled, For Compition
 * 
 */
 typedef enum
 {

 	EXTREMEVERBOSE,
 	LIGHTLOG,
 	NOLOG

 } logLevel;
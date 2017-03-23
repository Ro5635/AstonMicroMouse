/************************************************************************/
/*								Defines                                 */
/************************************************************************/

//#define F_CPU 20000000L

#include <avr/io.h>
#include <asf.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

//Include The Other C Files

#include "motorDriver.c"
#include "reflectanceDriver.c"
#include "reflectanceCalc.c"
#include "lineFollowerCaibration.c"

//Prototype:
void startUp(void);

void startUp(void){
	
	board_init();
//	
	InitMotorRegisters();
	
	//Set up the arrays of reflectance sensor
	initReflectanceArray();
	
	//Calibrate the opto sensor
	GLOBAL_OptoSetPoint =  55;//getCalibratedSetPoint();
	
	_delay_ms(2500);
	sei();
	
	signalMotor();	
	
}

int main(void){

	//Set Up The Robot 
	startUp();
	
	int rate = 0;
	while(1){
			
	
	
	}

}





/************************************************************************/
/*								ISR Routines                            */
/************************************************************************/

ISR(TIMER0_OVF_vect)
{
	//Increment the value of optocount reached, used to make a kind of ad hock timer...
	int_Opto_Count_Reached++;
}
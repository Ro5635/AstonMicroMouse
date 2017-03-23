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
	sei();
	InitMotorRegisters();
	
	//Set up the arrays of reflectance sensor
	initReflectanceArray();
	
	//Calibrate the opto sensor
	GLOBAL_OptoSetPoint =  33;//getCalibratedSetPoint();
	
	_delay_ms(2500);
	signalMotor();
		
	
}

int main(void){

	//Set Up The Robot 
	startUp();
	
	while (1)
	{
		startUp();
	}
	
	
	int rate = 0;
	while(1){
			
	rate = rate + 10;
	//Spin motor to denote calibration complete
	LH_Motor_Duty = (rate);
	RH_Motor_Duty = (rate*0.89);
	Motor_Duty_ptr = &LH_Motor_Duty;			// Motor_Duty_ptr points to LH_Motor_Duty
	OCR1A = *Motor_Duty_ptr;					// AIN2 = LH_Motor_Duty
	Motor_Duty_ptr = &RH_Motor_Duty;
	OCR2A = *Motor_Duty_ptr;					// BIN1

			
	if(rate > 250){
		rate = 10;
	}
	
	_delay_ms(10);
	
	}

}


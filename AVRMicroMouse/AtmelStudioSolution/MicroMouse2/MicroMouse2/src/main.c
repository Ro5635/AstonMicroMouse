/************************************************************************/
/*								Defines                                 */
/************************************************************************/

//#define F_CPU 20000000L
//#define FCPUCLOCK  20000000L // F_CPU Set..?
#define BAUD  9600L

//Dodgy cast...
#define SerialBaudRate ((unsigned int)(20000000 / (16 * BAUD) ) - 1)



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
#include "communicationsController.c"

//Prototype:
void startUp(void);

void startUp(void){
	
	board_init();

//	setUpSerialRegisters();
	InitMotorRegisters();
	
	//Set up the arrays of reflectance sensor
//	initReflectanceArray();
	
	//Calibrate the opto sensor
	GLOBAL_OptoSetPoint =  55;//getCalibratedSetPoint();
	
	_delay_ms(2500);
	sei();
	//setUpSerialRegisters();
	signalMotor();
	
}

int main(void){

	//Set Up The Robot 
	startUp();
//  	_delay_ms(900);
//  	setMotor(127, 127);
//  	_delay_ms(10000);
//  	setMotor(0,0);
//  	_delay_ms(10000);
//  	setMotor(250,80);
// 	
	//DDRD |= 1<<PD3;
	//PORTD |= 1<<PD3;
	
	
	while(1){
		
		setMotor((250), (250*0.89) );
	
		_delay_ms(2000);
		
		setMotor((70), (70) );
		
		_delay_ms(4000);
	
		for (int i = 75 ; i < 256; i++)
		{
			setMotor( i,i);
			_delay_ms(100);
		}
		for (int i = 255 ; i > 75; i--)
		{
			setMotor( i,i);
			_delay_ms(10);
		}
 		
 		setMotor(160, 0);
 		_delay_ms(250);
 		
 		setMotor(200, 200);
 		
 		_delay_ms(1000);
 		
	
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
/**
 * Main Primary function to control the whole mouse
 *
 */


/****************************************************/
/****************************************************/
/*   All header files are included in this section 	*/
#include <avr/io.h>									// Main AVR library
#include <avr/interrupt.h>							// Needed for interrupts
#include <util/delay>								// Needed for timers
#include <stdio.h>									// Needed for pointers



//Include our modules
//
#include "Mouse_PWM.h"								// PWM to motors
#include "Motor_Control.h"							//
#include "Mouse_PID.h"	
#include "CommunicationsController.h"


/****************************************************/
/*			All #defines are declared here			*/
/****************************************************/
#define F_CPU 20000000   							// AVR clock frequency in Hz, used by util/delay.h


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



/****************************************************/
/*				Pin assignments						*/
/****************************************************/
/*	PORTA											*/
#define SEN_ARRAY_LEDON PA1							// Name the sensor array enable pin
#define LDR_OUT_7 PA2								// Name the sensor array pin7
#define LDR_OUT_6 PA3								// Name the sensor array pin6
#define OUTB1 PA4									// Name the sensor array pin7
#define OUTA1 PA5									// Name the sensor array pin7
#define OUTA2 PA6									// Name the sensor array pin7
#define OUTB2 PA7									// Name the sensor array pin7
/****************************************************/
/*	PORTB											*/
#define AUTO_SWITCH	PB1;							// Name the switch pin to enable the PID (for tuning)
#define SEN_SINGLE_OUT0 PB2;						// Name the start/stop sensor pin
#define SS_RTC PB3;									// Name the slave select pin (RTC)
#define SS_RAD PB4;									// Name the slave select pin (RADIO)
/****************************************************/
/*	PORTC											*/
#define TOF_LASER_SCL PC0							// Name the TOF front facing SCL pin
#define TOF_LASER_SDA PC1							// Name the TOF front facing SDA pin
#define LDR_OUT_5 PC2								// Name the sensor array pin5
#define LDR_OUT_4 PC3								// Name the sensor array pin4
#define LDR_OUT_3 PC4								// Name the sensor array pin3
#define LDR_OUT_2 PC5								// Name the sensor array pin2
#define LDR_OUT_1 PC6								// Name the sensor array pin1
#define LDR_OUT_0 PC7								// Name the sensor array pin0
/****************************************************/
/*	PORTD											*/
#define MOT_DRI_NSLEEP PD0							// Name the motor driver sleep pin
#define MOT_DRI_NFAULT PD2							// Name the motor driver fault pin
#define SEN_SINGLE_OUT1 PD3;						// Name the corner marker sensor pin
#define MOT_DRI_AIN1 PD4							// Name the left motor pwm pin
#define MOT_DRI_AIN2 PD5							// Name the right motor pwm pin
#define MOT_DRI_BIN2 PD6							// Name the left motor pwm pin
#define MOT_DRI_BIN1 PD7							// Name the right motor pwm pin
/****************************************************/

/**
 * Primary start function 
 * @return  [description]
 */
int main(void)
{




}



/* Interrupts (ISRs) go in this section 			*/
/* Interrupts are listed in order of priority.		*/
/* For ISR vectors see pg 61/62 of data sheet		*/

// Motor over current warning (active low)
// STATUS pin nFAULT on the drv8833
ISR(INT0_vect)
{
	//  lower SetPoint
	1<<OVERHEAT;
	return;
}
ISR(INT1_vect)
{
	//	Start/Stop line signal
	//  Start/Stop LDR
	1<<AUTOMATIC;
	LapCount --;
	return;
}
ISR(INT2_vect)
{
	//
	//	Start of a corner signal
	//  Corner LDR

}

ISR(PCIFR_PCIF2_vect)
{
	//
	//PCIFR = 1<<PCIF2 | 1<<PCIF1;			// Enable pin change intterupt 2:1

}
//  Find the average angular velocities
ISR(TIMER2_COMPA_vect)
{
	// Find motor speeds
}
//  Re tune Motor PIDs
ISR(TIMER2_COMPB_vect)
{
	Tune();
}




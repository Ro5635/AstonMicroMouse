#ifndef PINDEFINITIONS_H_
#define PINDEFINITIONS_H_

/****************************************************/
/*			All #defines are declared here			*/
/****************************************************/

/****************************************************/
/*				Pin assignments						*/
/****************************************************/
/*	PORTA											*/
#define OptoSense_LEDON PA1							// Name the sensor array enable pin
#define OptoSense_7 PA2								// Name the sensor array pin7
#define OptoSense_6 PA3								// Name the sensor array pin6
#define OUTB1 PA4									// Name the sensor array pin7
#define OUTA1 PA5									// Name the sensor array pin7
#define OUTA2 PA6									// Name the sensor array pin7
#define OUTB2 PA7									// Name the sensor array pin7
/****************************************************/
/*	PORTB											*/
#define AUTO_SWITCH	PB1								// Name the switch pin to enable the PID (for tuning)
#define OptoSense_SINGLE_0 PB2						// Name the start/stop sensor pin
#define SS_RTC PB3;									// Name the slave select pin (RTC)
#define SS_RAD PB4;									// Name the slave select pin (RADIO)
/****************************************************/
/*	PORTC											*/
#define TOF_LASER_SCL PC0							// Name the TOF front facing SCL pin
#define TOF_LASER_SDA PC1							// Name the TOF front facing SDA pin
#define OptoSense_5 PC2								// Name the sensor array pin5
#define OptoSense_4 PC3								// Name the sensor array pin4
#define OptoSense_3 PC4								// Name the sensor array pin3
#define OptoSense_2 PC5								// Name the sensor array pin2
#define OptoSense_1 PC6								// Name the sensor array pin1
#define OptoSense_0 PC7								// Name the sensor array pin0
/****************************************************/
/*	PORTD											*/
#define MOT_DRI_NSLEEP PD0							// Name the motor driver sleep pin
#define MOT_DRI_NFAULT PD2							// Name the motor driver fault pin
#define OptoSense_SINGLE_1 PD3						// Name the corner marker sensor pin
#define MOT_DRI_AIN1 PD4							// Name the left motor PWM pin
#define MOT_DRI_AIN2 PD5							// Name the right motor PWM pin
#define MOT_DRI_BIN2 PD6							// Name the left motor PWM pin
#define MOT_DRI_BIN1 PD7							// Name the right motor PWM pin
/****************************************************/

#endif
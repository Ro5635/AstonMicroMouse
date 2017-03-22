#ifndef CENTRALENUMS_H_   /* Include guard */
#define CENTRALENUMS_H_

/************************************************************************/
/*						Central Enum Files                              */
/************************************************************************/

typedef enum {
	enable = 1,
	disable = 0,

	EXTENDED
} state_enum;


typedef enum {
	Opto0 = OptoSense_0,
	Opto1 = OptoSense_1,
	Opto2 = OptoSense_2,
	Opto3 = OptoSense_3,
	Opto4 = OptoSense_4,
	Opto5 = OptoSense_5,
	Opto6 = OptoSense_6,
	Opto7 = OptoSense_7,
	OptoL = OptoSense_SINGLE_0,
	OptoR = OptoSense_SINGLE_1

} Opto_enum;

/****************************************************/
/*		Enumerating the direction register			*/
/*	zero bit enables the LH motor,					*/
/*	first bit enables the RH motor,					*/
/*	fourth bit changes motor directions				*/
enum direction_register_t							// A binary encoded register
{													//
	Static = 0,										// Both motors stopped
	LH_Motor = 1,									// Left motor enable
	RH_Motor = 2,									// Right motor enable
	Both_Motors = 3,								// Both motors enabled
	Reverse = 4,									// Both motors reverse flag
};													//
/****************************************************/
/* Enumerating the control register					*/
enum control_register_t								// A one bit hot register
{													//
	AUTOMATIC = 1,									// Enable the PID controller flag
	CHANGE = 2,										// PID setpoint polarity has changed flag
	L_DECELERATE = 4,								// The setpoint for the PID is negative
	R_DECELERATE = 8,								// The setpoint for the PID is negative
	OVERHEAT = 16,									// The motor driver is getting to hot (cut the setpoint)
	SETPOINT_SELECT = 32,							// Select which motor is being tuned
};


#endif
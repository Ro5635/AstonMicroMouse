#ifndef GLOBALS_H_   /* Include guard */
#define GLOBALS_H_

/************************************************************************/
/*								Globals                                 */
/************************************************************************/

//#define F_CPU 20000000L
// AVR clock frequency in Hz, used by util/delay.h

//Current Reflective value
int Reflective_Values[9][1];	//Two Dimensional Now

//OptoDetectors Set Point
int GLOBAL_OptoSetPoint = 0;

//Are we rolling
int GLOBAL_Start;

//PID Set Point
int GLOBAL_PIDSetPoint;

//Tracking variable for the Opto detectors time
int int_Opto_Count_Reached = 0;

//Control Register Global
int Global_controlRegister = 0;


//////////////////////////////////////////////////////////////////////////

#endif
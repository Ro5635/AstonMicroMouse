
#include "PinDefinitions.h"
#include "motorDriver.h"

void InitMotorRegisters(void)
{
	DDRD = 1<<MOT_DRI_BIN1 | 1<<MOT_DRI_BIN2 | 1<<MOT_DRI_AIN1 | 1<<MOT_DRI_AIN2;

	OCR1A = 0;
	OCR1B = 0;
	OCR2A = 0;
	OCR2B = 0;

	/*	Set up timer 2:1 for PWM					*/
	TCCR1A =	1<<COM1A1 |							// Clear OC1A on compare match
	1<<COM1B1 |							// Clear OC1B on compare match
	1<<WGM10;							// Set to Fast PWM cd (OxFF)
	TCCR1B =	1<<WGM12 |							//
	1<<CS10;							// set TMR1 to no prescaler
	TCCR2A =	1<<COM2A1 |							// Clear OC2A on compare match
	1<<COM2B1 |							// Clear OC2B on compare match
	1<<WGM11 |							// Set to Fast PWM cd (OxFF)
	1<<WGM20;							//
	TCCR2B =	1<<CS20;							// set TMR2 to no prescaler
	Motor_Duty_ptr = &LH_Motor_Duty;			// Motor_Duty_ptr points to LH_Motor_Duty
	OCR1B = *Motor_Duty_ptr;					// BIN2
	Motor_Duty_ptr = &RH_Motor_Duty;			//
	OCR2B = *Motor_Duty_ptr;					// AIN1

}

/************************************************************************/
/*	signalMotor															*/
/*																		*/
/*	Motor makes a distinctive tune; good for signaling purposes.        */
/************************************************************************/
void signalMotor(void){

	setMotor(0,0);
	_delay_ms(100);
	setMotor(255,255);
	_delay_ms(155);
	setMotor(100,0);
	_delay_ms(120);
	setMotor(0,0);
	_delay_ms(220);
	setMotor(0,200);
	_delay_ms(100);
	for (int x = 0; x < 220; x++)
	{
		setMotor(x,10);
		_delay_ms(1);
	}
	
	for (int x = 220; x > 10; x--)
	{
		setMotor(x,10);
		_delay_ms(1);
	}
	setMotor(0,0);
	
}

/************************************************************************/
/*	setMotor															*/
/*																		*/
/*	Sets the speed of the motor                                         */
/************************************************************************/
void setMotor(int lMot, int rMot){
	
	LH_Motor_Duty = (lMot);
	RH_Motor_Duty = (rMot *0.89);
	Motor_Duty_ptr = &LH_Motor_Duty;			// Motor_Duty_ptr points to LH_Motor_Duty
	OCR1A = *Motor_Duty_ptr;					// AIN2 = LH_Motor_Duty
	Motor_Duty_ptr = &RH_Motor_Duty;
	OCR2A = *Motor_Duty_ptr;					// BIN1
	
}
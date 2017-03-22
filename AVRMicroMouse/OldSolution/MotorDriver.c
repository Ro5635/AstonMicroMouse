/**
 * 	Handles the control of the drv8833 H-bridge motor driver
 *
 */



//***************************************
//Function Prototype Declerations
void motorDrivSetMotorSpeed();
bool motorDrivIsSleeping();
bool motorDrivIsInFault();
void motorDrivSendToSleep();

//***************************************





/**
 * Sets the value for the PWM cycle to the motor input pin
 */
void motorDrivSetMotorSpeed(){
	//Set the PWM on the motor controller

}

/**
 * Returns true if the motor is sleeping, else it is false
 * 
 * @return state of motor sleep
 */
bool motorDrivIsSleeping(){

	//reads the state of the sleep pin (on this micro) and returns appropiatly


}

/**
 * Returns true if the motor is in a fault state, this could be due to overheating etc.
 * 
 * @return Is motor in fault state
 */
bool motorDrivIsInFault(){


	//Read the fault pin and report back if its in fault


}


/**
 * Sends the motor to a sleep state to conserve power
 */
void motorDrivSendToSleep(){

	//Set the sleep pin to low to send the motor driver to sleep


}
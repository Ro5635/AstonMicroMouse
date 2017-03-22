#ifndef MOTORDRIVER_H_   /* Include guard */
#define MOTORDRIVER_H_


void InitMotorRegisters(void);
void setMotor(int lMot, int rMot);
void signalMotor(void);


// LH and RH motor values
int LH_Motor_Duty = 0;
int RH_Motor_Duty = 0;			

int *Motor_Duty_ptr;


#endif
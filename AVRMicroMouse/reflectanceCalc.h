#ifndef REFLECTANCECALC_H_
#define REFLECTANCECALC_H_

/************************************************************************/
/*							ReflectanceClac	                            */
/*				A routine created to receive and tabulate the			*/
/*				the reflectance values									*/
/************************************************************************/


#define Ripple_Count_Max 3


int Reflective_Sense = 0;							// A register to hold the value from the current reflective sensor
int Reflective_count = 0;							// A register to hold the ripple counter iteration
int Sense_Point = 0;								
int i, j = 0;										
int Reflective_Index = 0;							
int Val1, Val2 = 0;


void ReflectiveStorage(void);



#endif
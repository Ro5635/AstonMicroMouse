/************************************************************************/
/*						Line Follower Calibration                       */
/************************************************************************/

//#include "pinDefinitions.h"		// Laurence's Pin definitions

#include "lineFollowerCaibration.h"

#include "bubbleSort.c"



int getCalibratedSetPoint(void){

	// 	//Array to hold the values
	// 	int Reflective_History[9];
	//
	// 	//Get the 10 readings
	//
	//  	for(int index = 0; index < 10; index++ ){
	//
	// 		 GLOBAL_PIDSetPoint = 700;
	//  		//Read in the new values
	//  		ReflectiveStorage();
	//
	//  		//Tight Loop
	//  		_delay_ms(250);
	//
	//  		//Save the values
	//  		Reflective_History[index] = Reflective_Values[0][0];
	//
	//  	}
	//
	// 	//Sort the 10 readings in to ascending order
	// 	buble_sort(Reflective_History, 10);
	//
	// 	//get the median of the first half
	// 	int lowerMed = Reflective_History[2];
	//
	//
	// 	//get the median of the seconded half
	// 	int HigherMed = Reflective_History[7];
	//
	//
	// 	//Get the set point and set point
	// 	return (lowerMed + HigherMed) / 2;
	//

	return 44;
}


//////////////////////////////////////////////////////////////////////////

 /************************************************************************/
 /*							ReflectanceClac                              */
 /************************************************************************/

 #include "reflectancecalc.h"


 void ReflectiveStorage(void){
	 
	 Reflective_Index = 0;
	 int currentOpto = 0;
	 
	 //Set the set point equal to the calibrated set point
	 Sense_Point = GLOBAL_OptoSetPoint;				//
	 
	 while ( Reflective_Index < 10 ){
		 
		 int currentVal = readOptoDetector(currentOpto++);
		 //getReflectanceValue
		 Reflective_Values[i][0] = currentVal;			// Set the reflective sensor an element in the array
		 // Move to the ripple counter row
		 
		 
		 
		 if (Reflective_Values[i][0] >= Sense_Point)
		 {
			 
			 Reflective_count = Reflective_Values[i][1];	// Move the previous sensor count, from the array, to Reflective_Count
			 
			 Reflective_count++;						// Increment the count
			 
			 if (Reflective_count >= Ripple_Count_Max)
			 {
				 Reflective_count = Ripple_Count_Max;
				 // set the flag
			 }else if (currentVal < Sense_Point)
			 {
				 Reflective_count--;
				 // clear the flag
			 }
			 
		 }
		 

		 i++;
		 Reflective_Index++;
		 
		 Reflective_Values[i][1] = Reflective_count;	// Move the new count back to the array
	 }
	 
	 
	 
	 //Place the values into the global
	 for (int x = 0; x < 10; x++){
		 
		 Reflective_Values[x][1] = Reflective_Values[x][1];
	 
	 }
	 
	 for (int x = 0; x < 7; x++){
		 
		 Val1 = (int) Reflective_Values[x];
		 Val2 = (int) Reflective_Values[x++];
		 
		 if ( (Val1 + Val2) == 6)
		 {
			 
			 Reflective_Values[x][0] = Reflective_Values[x][0];
			 Val1 = (int) Reflective_Values[x];
			 Val2 =  (int) Reflective_Values[x++];
			 GLOBAL_PIDSetPoint = (Val1-Val2);
			 
		 }
		 
		 
		 
		 if ( ( *Reflective_Values[9] == 3) && !(GLOBAL_Start == 1)){
			 
			 GLOBAL_Start = 1;
		 }
		 
		 if (*Reflective_Values[9] == 3 && (GLOBAL_Start == 1)){
			 
			 GLOBAL_Start = 0;
			 
		 }
	 }

 }

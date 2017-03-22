#include "pinDefinitions.h"		// Laurence's Pin definitions
#include "centralEnums.h"
#include "globals.h"

#include "reflectanceDriver.h"


/************************************************************************/
/*						Reflectance Driver                              */
/************************************************************************/



void initReflectanceArray(void){
	
	//Set the LED Pin to output
	DDRA |= (0<<OptoSense_LEDON);
	
	//Turn the LED on, this can be turned off when not in use to save power
	PORTA |= (0<<OptoSense_LEDON);
	
}


int getPortNumber(int optoID){

 		if(optoID == 1){
 			return 3;
 		}
		 	
		if(optoID == 2){
			return 3;
		}
				  
		if(optoID == 3){
			return 3;
		}
						   
		if(optoID == 4){
			return 3;
		}
									
		if(optoID == 5){
			return 3;
		}
											 
		if(optoID == 6){
			return 3;
		}
		
		if(optoID == 7){
			return 1;
		}
		
		if(optoID == 8){
			return 1;
		}
		if(optoID == 9){
			return 2;
		}
		if(optoID == 10){
			return 4;
		}
		return 0;
		//Error handling..
		
}


int getOptoPin(int optoID){

	switch(optoID){
		
		case 1 : return OptoSense_0;
		case 2 : return OptoSense_1;
		case 3 : return OptoSense_2;
		case 4 : return OptoSense_3;
		case 5 : return OptoSense_4;
		case 6 : return OptoSense_5;
		case 7 : return OptoSense_6;
		case 8 : return OptoSense_7;
		case 9 : return OptoSense_SINGLE_0;
		case 10 : return OptoSense_SINGLE_1; 
		
	}
	
	return 0;

}


/************************************************************************/
/*					Set the Opto pin state                              */
/************************************************************************/
void setOptoPinState(state_enum state, int optoID){
		
	//Get the port identification number
	int portID = getPortNumber(optoID);
	int workAround = 0;

	if(state == enable){
		
		int pinIndenifier = getOptoPin(optoID);
		
		workAround = (1<<pinIndenifier); 
		
		switch(portID){
				
			    case 1: DDRA |= workAround;// Pin Output
			    case 2: DDRB |= workAround; 
			    case 3: DDRC |= workAround; 
			    case 4: DDRD |= workAround; 
		}	
		
		}else{
		
		workAround &= ~(1<<optoID); 
		
			switch(portID){
					
				case 1: DDRA &= ~(1<<workAround); // Pin Input
				case 2: DDRB &= ~(1<<workAround); // Pin Input
				case 3: DDRC &= ~(1<<workAround); // Pin Input
				case 4: DDRD &= ~(1<<workAround); // Pin Input
			}	
	}
	
}
	
	
	
void setOptoSigState(state_enum state, int optoID){

	int portID = getPortNumber(optoID);
	
	int pinIndenifier = getOptoPin(optoID);
	
	if(state == enable){
			
		switch(portID){
				
			case 1: PORTA |= 1<<pinIndenifier; // Pin Output
			case 2: PORTB |= 1<<pinIndenifier; // Pin Output
			case 3: PORTC |= 1<<pinIndenifier; // Pin Output
			case 4: PORTD |= 1<<pinIndenifier; // Pin Output
		}
			
		}else{
			
		switch(portID){
				
			case 1: PORTA &= ~(1<<pinIndenifier); // Pin Input
			case 2: PORTB &= ~(1<<pinIndenifier); // Pin Input
			case 3: PORTC &= ~(1<<pinIndenifier); // Pin Input
			case 4: PORTD &= ~(1<<pinIndenifier); // Pin Input
		}
	}
		

}
	
void setTimmer1(int state){
	
	OCR0A = 100; //Thee reload value, the value of this was found empirically to give a good magnitude of values from the hardware.
	TCCR0A = 0; // no output compare and WGM1 to 00
	TCCR0B |= (1 << WGM12)|(1 << CS00) ; // set no prescaler and CTC mode
	TIMSK0 |= (1 << OCIE1A);         //set compare A interrupt
	
}


int getOptoPinFromID(int optoID){
	
	switch(optoID){
		
		case 1: return OptoSense_1;
		case 2: return OptoSense_2;
		case 3: return OptoSense_3;
		case 4: return OptoSense_4;
		case 5: return OptoSense_5;
		case 6: return OptoSense_6;
		case 7: return OptoSense_7;
		case 8: return OptoSense_SINGLE_0;
		case 9: return OptoSense_SINGLE_1;
	}
	
	return 0;//Error handaling!!!!
}
	
int readOptoDetector(int optoID){
	
	//Set the Opto pin to an output
	setOptoPinState(enable, optoID);

	///Send the read pulse
	setOptoSigState(enable, optoID);
	
	_delay_ms(0.01);//Delay required for the ping sensor to detect the signal
		
	// Send the port low
	setOptoSigState(disable, optoID);
	
	//Set to an input
	setOptoPinState(disable, optoID);

	//DDRC &= ~(1<<PingSense);
		
	int_Opto_Count_Reached = 0;
	
	//int portID = getPortNumber(optoID); 
	
	
	if(optoID == 1){

		while(PINA & (1<<getOptoPinFromID(optoID))){
			//Wait for the pin to go low
				
		}
	}
	
	if(optoID == 2){
		while(PINB & (1<<getOptoPinFromID(optoID))){
			//Wait for the pin to go low
			
		}
		
	}
	
	if(optoID == 3){

		while(PINC & (1<<getOptoPinFromID(optoID))){
			//Wait for the pin to go low
				
		}
		
	}
	
	if(optoID == 4){
		while(PIND & (1<<getOptoPinFromID(optoID))){
			//Wait for the pin to go low
					
		}
	}

	
	_delay_ms(0.001);
	//test = int_Opto_Count_Reached;
	//itoa(int_Opto_Count_Reached , buffer, 10);
		
		
	//return the data
	return int_Opto_Count_Reached;
		
	}
	
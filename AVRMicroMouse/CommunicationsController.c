/**
 * 	CommunicationsController, handles all of the communications from the micromouse to the big wide outside world.
 *  Uses the UART to transmit back to the computer
 *	
 */





/**
 * Transmit log eleemnt back to the PC
 * 
 * @param logElementID Data Element Identifier  
 * @param dataPoint    The Relevent Data Point As An Int
 */
void commsContLogINT(int logElementID, int dataPoint){

	tXString("This is a test")

}

/**
 * Transmit log eleemnt back to the PC
 * 
 * @param logElementID Data Element Identifier  
 * @param dataPoint    The Relevent Data Point As A Float
 */
void commsContLogFloat(int logElementID, int dataPoint){


}


static int getCharArrayLen(char stringArr[]){
	
	int len = 0;

	while(stringArr[len] != '\0'){
		len++;
	}

	return len;

}

static void TxCharactor(char Ch){

	while((UCSR0A & 1<<UDRE0) == 0); //Hold Here Until Data reg is empty!
	UDR0 = Ch;	//Pass char to UARTS Data Reg


//	charToTransmit = Ch;
//	UCSR0B |= 1<<UDRIE0; //Data reg Empty Enable INTERUPT.

}


static void tXString(char stringArr[]){

	int charArrayLength = getCharArrayLen(stringArr);

	for ( int i = 0; i <= (charArrayLength - 1); i++ ) {
   		if(stringArr[i] != '\0'){
			TxCharactor(stringArr[i]);
		}
		
	}
}

static void tXStringLN(char stringArr[]){

	int charArrayLength = getCharArrayLen(stringArr);

	for ( int i = 0; i <= (charArrayLength - 1); i++ ) {
   		if(stringArr[i] != '\0'){
			TxCharactor(stringArr[i]);
		}
		
	}
	TxCharactor('\r');
}


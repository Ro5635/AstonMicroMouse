/************************************************************************/
/*						Communications Controller                       */
/************************************************************************/


#include <avr/io.h>

void setUpSerialRegisters(void);
void commsContLogINT(int logElementID, int dataPoint);
void commsContLogFloat(int logElementID, int dataPoint);
int getCharArrayLen(char stringArr[]);
void TxCharactor(char Ch);
void tXString(char stringArr[]);
void tXStringLN(char stringArr[]);


void setUpSerialRegisters(void){
	
	UCSR0B |= 1<<TXEN0 || 1<<RXEN0; //USART Status Reg B Set Transmit and receive Enable AND receive Inter en.
	
	DDRD |= (1<<PD3);
	
	UBRR0 = 129.23;//13461;//650.04;//1356.56;//1562.76;// 2604.6;//130.23;//Baud Rate Reg(s) (URSEL sets weather high or low reg is accessed!)
	//C handles all of the complexity of dealing with setting URSEL for you if you use
	//UBRRn in the place of setting H and L seperatly?  UBRRH = (BAUDRATE>>8);UBRRL = BAUDRATE;

}

/**
 * Transmit log element back to the PC
 * 
 * @param logElementID Data Element Identifier  
 * @param dataPoint    The Relevant Data Point As An Int
 */
void commsContLogINT(int logElementID, int dataPoint){

	tXString("This is a test");

}

/**
 * Transmit log element back to the PC
 * 
 * @param logElementID Data Element Identifier  
 * @param dataPoint    The Relevant Data Point As A Float
 */
void commsContLogFloat(int logElementID, int dataPoint){


}


int getCharArrayLen(char stringArr[]){
	
	int len = 0;

	while(stringArr[len] != '\0'){
		len++;
	}

	return len;

}

void TxCharactor(char Ch){

	while((UCSR0A & 1<<UDRE0) == 0); //Hold Here Until Data reg is empty!
	UDR0 = Ch;	//Pass char to UARTS Data Reg


//	charToTransmit = Ch;
//	UCSR0B |= 1<<UDRIE0; //Data reg Empty Enable INTERUPT.

}


void tXString(char stringArr[]){

	int charArrayLength = getCharArrayLen(stringArr);

	for ( int i = 0; i <= (charArrayLength - 1); i++ ) {
   		if(stringArr[i] != '\0'){
			TxCharactor(stringArr[i]);
		}
		
	}
}

void tXStringLN(char stringArr[]){

	int charArrayLength = getCharArrayLen(stringArr);

	for ( int i = 0; i <= (charArrayLength - 1); i++ ) {
   		if(stringArr[i] != '\0'){
			TxCharactor(stringArr[i]);
		}
		
	}
	TxCharactor('\r');
}


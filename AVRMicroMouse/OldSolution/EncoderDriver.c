/**
 *	Encoder Driver
 *
 * 
 */



// A function created to look for pulses from left wheel sensor
void PulseTimeR()
{
//  Reset the working variables
PrevRHSw = RHSw;
PulseCount = 0;
TotalMultiplier = 0;
ADC_Result = 0;
PulseMultiplier = 0;

	//  Take 5 samples
	while (PulseCount != 5)
	{
		//	Look for a high ADC reading
		while(ADC_Result<128)
		{
			//Take ADC reading
			PulseMultiplier ++;							//  Increment the time multiplier
			ADMUX = 0<<MUX2 | 0<<MUX1 | 0<<MUX0;		//  using analgue i/p so REFSx 0s | select the mux channel ADC0, pin 40 (only first 3 bits - single ended))
			ADC_Result = ADC_Conversion();				//  Call the conversion function
		}
		TotalMultiplier += PulseMultiplier;				//  Add the new multiplier to the running total
		PulseCount ++;									//  Increment the PulseCount
	}
	RHSw = (TotalMultiplier * ADCTime * ArcFactor);		//	Finding the angular velocity of the RHS motor
}





// A function created to look for pulses from left wheel sensor
void PulseTimeL()
{
//  Reset the working variables
PrevLHSw = LHSw;
PulseCount = 0;
TotalMultiplier = 0;
ADC_Result = 0;
PulseMultiplier = 0;

	//  Take 5 samples
	while (PulseCount != 5)
	{
		//	Look for a high ADC reading
		while(ADC_Result<128)
		{
			//Take ADC reading
			PulseMultiplier ++;							//  Increment the time multiplier
			ADMUX = 0<<MUX2 | 0<<MUX1 | 0<<MUX0;		//  using analgue i/p so REFSx 0s | select the mux channel ADC0, pin 40 (only first 3 bits - single ended))
			ADC_Result = ADC_Conversion();				//  Call the conversion function
		}
		TotalMultiplier += PulseMultiplier;				//  Add the new multiplier to the running total
		PulseCount ++;									//  Increment the PulseCount
	}
	LHSw = (TotalMultiplier * ADCTime * ArcFactor);		//	Finding the angular velocity of the RHS motor
}
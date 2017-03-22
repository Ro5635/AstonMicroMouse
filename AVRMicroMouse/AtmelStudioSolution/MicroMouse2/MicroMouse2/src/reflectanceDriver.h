#ifndef REFLECTANCEDRIVER_H_
#define REFLECTANCEDRIVER_H_


/************************************************************************/
/*							Prototypes				                    */
/************************************************************************/

extern void setOptoPinState(state_enum state, int optoID);

extern void initReflectanceArray(void);

extern int getPortNumber(int optoID);

extern int getOptoPin(int optoID);

extern void setOptoSigState(state_enum state, int optoID);

extern void setTimmer1(int state);

extern int getOptoPinFromID(int optoID);

extern int readOptoDetector(int optoID);


#endif
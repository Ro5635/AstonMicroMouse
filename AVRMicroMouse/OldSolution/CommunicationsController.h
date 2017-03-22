#ifndef COMMUNICATIONSCONTROLLER_H_   /* Include guard */
#define COMMUNICATIONSCONTROLLER_H_

//Function Prototypes

void commsContlogINT(int logElementID, int dataPoint);
void commsContlogFloat(int logElementID, int dataPoint);
static int getCharArrayLen(char stringArr[]);
static void TxCharactor(char Ch);
static void tXString(char stringArr[]);
static void tXStringLN(char stringArr[]);



#endif // COMMUNICATIONSCONTROLLER_H_
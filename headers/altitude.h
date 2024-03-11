// *******************************************************
// altitude.h
//
// Support for a set of FOUR specific buttons on the Tiva/Orbit.
// ENCE361 sample code.
// The buttons are:  UP and DOWN (on the Orbit daughterboard) plus
// LEFT and RIGHT on the Tiva.
//
// P.J. Bones UCECE
// Last modified:  7.2.2018
//
// *******************************************************

#ifndef ALTITUDE_H_
#define ALTITUDE_H_

/* FUNCTIONS */
void ADCIntHandler(void);
void initADC(void);
void initAltitude(void);
void altitudeUpdate(void);

int32_t getMeanADC(void);
int16_t getADCPercent(void);

#endif // ALTITUDE_H_

// ==========================================================
//
// display.c
//
// ENCE361 Helicopter Project
//
// Authors:
//    - Zachary Avis | 27167186 | zav10@uclive.ac.nz
//    - fname lname  | 00000000 | aaa00@uclive.ac.nz
//
// Description:
//    Header file for delay.c
//
// ==========================================================



#ifndef DISPLAY_H_
#define DISPLAY_H_

enum displayStates {
    ALTITUDE = 0,
    ADC,
    CLEAR
};

typedef enum displayStates displayState_t;

/* FUNCTIONS */
// Initialises the clock
void initDisplay(void);

void displayClear(void);
void updateDisplay(void);

void displayEasterEgg(void);
void displayData(void);
void displayError(void);
void displayADC(void);

displayState_t getDisplayState(void);
void setDisplayState(displayState_t state);


#endif // DISPLAY_H_

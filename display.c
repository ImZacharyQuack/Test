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
//    Main file for program
//
// Info:
//  This module contains code from by P.J. Bones from
//  Lab3 ENCE361:
//      pwmGen.c - Example code which generates a single PWM
//          output on J4-05 (M0PWM7) with duty cycle fixed and
//          the frequency controlled by UP and DOWN buttons in
//          the range 50 Hz to 400 Hz.
//
// ==========================================================



/* INCLUDES */
#include <stdint.h>

#include "utils/ustdlib.h"
#include "OrbitOLED/OrbitOLEDInterface.h"

#include "headers/display.h"
#include "headers/altitude.h"



/* CONSTANTS */
#define MAX_STR_LEN 16



/* VARIABLES */
//static const int DISPLAY_SYMBOL_DEGREES = 0x60;

static displayState_t displayState;

/* FUNCTIONS */

void displayClear(void) {

    OLEDStringDraw("                ", 0, 0);
    OLEDStringDraw("                ", 0, 1);
    OLEDStringDraw("                ", 0, 2);
    OLEDStringDraw("                ", 0, 3);

}

void displayEasterEgg(void) {

    OLEDStringDraw(" DUCK ", 0, 0);
    OLEDStringDraw(" DUCK ", 0, 1);
    OLEDStringDraw(" DUCK ", 0, 2);
    OLEDStringDraw(" GOOSE ", 0, 3);

}

void updateDisplay(void) {
    displayClear();
    if (displayState == ALTITUDE) {
        displayData();
    } else if (displayState == ADC) {
        displayADC();
    } else {
        displayClear();
    }
}

void displayData(void) {

    char string[MAX_STR_LEN + 1];

    usnprintf(string, sizeof(string), "Altitude: %4d%%", getADCPercent());
    OLEDStringDraw(string, 0, 1);

}

void displayADC(void) {

    char string[MAX_STR_LEN + 1];

    usnprintf(string, sizeof(string), "Mean ADC: %4d", getMeanADC());
    OLEDStringDraw(string, 0, 1);

}


void displayError(void) {
    OLEDStringDraw(" Display Error ", 0, 1);
    OLEDStringDraw(" You fucked up! ", 0, 2);
}

void initDisplay(void) {
    OLEDInitialise();
    displayClear();
}

displayState_t getDisplayState(void) {
    return displayState;
}

void setDisplayState(displayState_t state) {
    displayState = state;
}














// ==========================================================
//
// input.c
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
// ==========================================================



/* INCLUDES */
#include <stdint.h>

#include "stdlib.h"

#include "headers/button.h"
#include "headers/display.h"
#include "headers/altitude.h"

static displayState_t displayState;

/* FUNCTIONS */
void initInput(void) {

    initButton();

}

void inputUpdate(void) {

    //
    if (buttonCheck(LEFT) == PUSHED) {
        setAltitudeReference();
    }

    //
    displayState = getDisplayState();
    if (buttonCheck(UP) == PUSHED) {
        displayClear();
        if (displayState == ALTITUDE) {
            setDisplayState(ADC);
        } else if (displayState == ADC) {
            setDisplayState(CLEAR);
        } else {
            setDisplayState(ALTITUDE);
        }
        updateDisplay();
    }

}












// ==========================================================
//
// main.c
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
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "headers/clock.h"
#include "headers/utils.h"
#include "headers/uart.h"
#include "headers/display.h"
#include "headers/input.h"
#include "headers/button.h"
#include "headers/altitude.h"

#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"

#include "driverlib/debug.h"
#include "utils/ustdlib.h"
#include "headers/circBufT.h"
#include "OrbitOLED/OrbitOLEDInterface.h"

#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/adc.h"

/* VARIABLES */ 

/* FUNCTIONS */
void SysTickIntHandler(void) {
    buttonUpdate();
    ADCProcessorTrigger(ADC0_BASE, 3);
}

void initSysTick(void) {
    SysTickPeriodSet(SysCtlClockGet() / 100);
    SysTickIntRegister(SysTickIntHandler);
    SysTickIntEnable ();
    SysTickEnable ();
}

// Initialises all 
void initialise(void) {

    initClock();
    initUART();
    initDisplay();
    initInput();
    initAltitude();
    initSysTick();

    IntMasterEnable ();

    updateDisplay();

}

// Main functions
// Starts program
int main(void) {

    initialise();

    while (1) {

        inputUpdate();
        altitudeUpdate();


     }

}

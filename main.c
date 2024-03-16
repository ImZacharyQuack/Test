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
#include <limits.h>

#include "headers/clock.h"
#include "headers/uart.h"
#include "headers/display.h"
#include "headers/input.h"
#include "headers/button.h"
#include "headers/altitude.h"

#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"

#include "utils/ustdlib.h"
#include "OrbitOLED/OrbitOLEDInterface.h"

#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/adc.h"

/* CONSTANTS */
// SysTick Rate in Hz
#define SYSTICK_RATE 40000

// Update ADC update 512 times a second
#define ALTITUDE_PROCESS_FREQUENCY 512

// Update ADC update 512 times a second
#define ALTITUDE_UPDATE_FREQUENCY 512

// Always update input
// Kinda just here at the moment
#define INPUT_FREQUENCY 0

// Update display at 10 times a second
#define DISPLAY_FREQUENCY 10



/* CONSTANTS */
static int32_t tickCount;

static int32_t ticksElaspedADC;
static int32_t ticksElaspedADCProcess;
static int32_t ticksElaspedDisplay;



/* FUNCTIONS */
// Interrupt handler for the SysTick interrupt
void SysTickIntHandler(void) {
    buttonUpdate();
    //processADC();
    tickCount++;
}

// Configures the SysTick interrupt
void initSysTick(void) {

    // Set SysTick Period timer
    SysTickPeriodSet(SysCtlClockGet() / SYSTICK_RATE);

    // Registers the interrupt handler
    SysTickIntRegister(SysTickIntHandler);

    // Enables the interrupt & device;
    SysTickIntEnable ();
    SysTickEnable ();

}

// Initialises all 
void initialise(void) {

    // Disable interrupts during start up
    IntMasterDisable();

    tickCount = 0;
    ticksElaspedADC = 0;
    ticksElaspedADCProcess = 0;
    ticksElaspedDisplay = 0;

    // All init functions
    initClock();
    initUART();
    initDisplay();
    initInput();
    initAltitude();
    initSysTick();

    processADC();

    // Enable interrupts
    IntMasterEnable ();

}

// Main functions
int main(void) {

     // Calls initialise functions
     initialise();

     while (1) {

         uint32_t countDelta, thisCount = tickCount;

         countDelta = thisCount - ticksElaspedADCProcess;
         if (thisCount < ticksElaspedADCProcess) {
                 countDelta = UINT_MAX - ticksElaspedADCProcess + thisCount;
         }
         if (((float)countDelta / SYSTICK_RATE) > 1.0f / ALTITUDE_PROCESS_FREQUENCY) {
             processADC();
             ticksElaspedADCProcess = thisCount;
         }

         countDelta = thisCount - ticksElaspedADC;
         if (thisCount < ticksElaspedADC) {
             countDelta = UINT_MAX - ticksElaspedADC + thisCount;
         }
         if (((float)countDelta / SYSTICK_RATE) > 1.0f / ALTITUDE_UPDATE_FREQUENCY) {
             updateAltitude();
             ticksElaspedADC = thisCount;
         }

         inputUpdate();

         countDelta = thisCount - ticksElaspedDisplay;
         if (thisCount < ticksElaspedDisplay) {
             countDelta = UINT_MAX - ticksElaspedDisplay + thisCount;
         }
         if (((float)countDelta / SYSTICK_RATE) > 1.0f / DISPLAY_FREQUENCY) {
             updateDisplay();
             ticksElaspedDisplay = thisCount;
         }

    }

}

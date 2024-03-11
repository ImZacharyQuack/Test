// ==========================================================
//
// uart.c
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
//
// ==========================================================



/* INCLUDES */
#include <stdint.h>
#include <stdbool.h>

#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#include "utils/ustdlib.h"



/* DEFINES */



/* FUNCTIONS */
void delayWaitInSeconds(double delay) {
    SysCtlDelay((SysCtlClockGet() * delay) / 6);
}

double max(double a, double b) {
    return a > b ? a : b;
}

double min (double a, double b) {
    return a < b ? a : b;
}

double clamp(double number, double minNumber, double maxNumber) {
    return max(min(number, maxNumber), minNumber);
}

















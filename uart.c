// ==========================================================
//
// motors.c
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
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "driverlib/sysctl.h"
#include "utils/ustdlib.h"



/* CONSTANTS */
#define BAUD_RATE                   9600

#define UART_BASE                   UART0_BASE
#define UART_PERIPH_UART      SYSCTL_PERIPH_UART0
#define UART_PERIPH_GPIO        SYSCTL_PERIPH_GPIOA
#define UART_GPIO_BASE          GPIO_PORTA_BASE
#define UART_GPIO_PIN_RX       GPIO_PIN_0
#define UART_GPIO_PIN_TX       GPIO_PIN_1
#define UART_GPIO_PINS           UART_GPIO_PIN_RX | UART_GPIO_PIN_TX

#define UART_CONFIG                UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE

/* VARIABLES */



/* FUNCTIONS */
void initUART(void) {

    SysCtlPeripheralEnable(UART_PERIPH_UART);
    SysCtlPeripheralEnable(UART_PERIPH_GPIO);

    GPIOPinTypeUART(UART_GPIO_BASE, UART_GPIO_PINS);
    GPIOPinConfigure(UART_GPIO_PIN_RX);
    GPIOPinConfigure(UART_GPIO_PIN_TX);

    UARTConfigGetExpClk(UART_BASE, SysCtlClockGet(), BAUD_RATE, UART_CONFIG);

    UARTFIFOEnable(UART_BASE);
    UARTEnable(UART_BASE);

}














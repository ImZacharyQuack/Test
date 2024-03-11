// ==========================================================
//
// altitude.c
//
// ENCE361 Helicopter Project
//
// Authors:
//    - Zachary Avis  | 27167186 | zav10@uclive.ac.nz
//    - fname lname  | 00000000 | aaa00@uclive.ac.nz
//
// Description:
//    Main file for program
//
// ==========================================================



/* INCLUDES */
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/adc.h"
#include "driverlib/pwm.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/debug.h"
#include "utils/ustdlib.h"

#include "headers/circBufT.h"
#include "headers/altitude.h"


/* CONSTANTS */
#define BUFFER_SIZE                            20

#define MIN_ALTITUDE                         0
#define MAX_ALTITUDE                        100

#define ALTITUDE_ADC_PERIPH            SYSCTL_PERIPH_ADC0
#define ALTITUDE_ADC_BASE               ADC0_BASE
#define ALTITUDE_ADC_CHANNEL        ADC_CTL_CH0



/* VARIABLES */
static circBuf_t inBuffer;

static int32_t meanADC;



/* FUNCTIONS */
void ADCIntHandler(void) {

    uint32_t valuel;

    ADCSequenceDataGet(ALTITUDE_ADC_BASE, 3, &valuel);
    //samplesTaken++;

    writeCircBuf(&inBuffer, valuel);

    ADCIntClear(ALTITUDE_ADC_BASE, 3);

}

void initADC(void) {
    SysCtlPeripheralEnable(ALTITUDE_ADC_PERIPH);
    ADCSequenceConfigure(ALTITUDE_ADC_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ALTITUDE_ADC_BASE, 3,  0, ALTITUDE_ADC_CHANNEL | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(ALTITUDE_ADC_BASE, 3);
    ADCIntRegister(ALTITUDE_ADC_BASE, 3, ADCIntHandler);
    ADCIntEnable(ALTITUDE_ADC_BASE, 3);
}

void initAltitude(void) {
    initCircBuf(&inBuffer, BUFFER_SIZE);
    initADC();
}

void altitudeUpdate(void) {

    int32_t sum;
    uint16_t i;

    sum = 0;
    for (i = 0; i < BUFFER_SIZE; i++) {
        sum = sum + readCircBuf(&inBuffer);
    }

    meanADC = (2 * sum + BUFFER_SIZE) / (2 * BUFFER_SIZE);

}

int32_t getMeanADC(void) {
    return meanADC;
}

int16_t getADCPercent(void) {
    return (meanADC * 100) / 4095;
}












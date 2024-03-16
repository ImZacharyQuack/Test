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
#include <stdint.h>

#include "stdlib.h"
#include "headers/circBufT.h"



/* FUNCTIONS */
int32_t* initCircBuf(circBuf_t *buffer, uint32_t size) {

    buffer -> windex = 0;
    buffer -> rindex = 0;
    buffer -> size = size;
    buffer -> data = (int32_t*) calloc(size, sizeof(int32_t));

    return buffer -> data;

}

void writeCircBuf(circBuf_t *buffer, uint32_t entry) {

    buffer -> data[buffer -> windex] = entry;
    buffer -> windex++;
    if (buffer -> windex >= buffer -> size)
        buffer -> windex = 0;

}

int32_t readCircBuf(circBuf_t *buffer) {

    int32_t entry;

    entry = buffer -> data[buffer -> rindex];
    buffer -> rindex++;

    if (buffer -> rindex >= buffer -> size) {
        buffer -> rindex = 0;
    }

    return entry;

}

void freeCircBuf(circBuf_t *buffer) {
    buffer -> windex = 0;
    buffer -> rindex = 0;
    buffer -> size = 0;
    free(buffer -> data);
    buffer -> data = NULL;
}












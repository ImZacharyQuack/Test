// ==========================================================
//
// circBufT.c
//
// ENCE361 Helicopter Project
//
// Authors:
//    - Zachary Avis | 27167186 | zav10@uclive.ac.nz
//    - fname lname  | 00000000 | aaa00@uclive.ac.nz
//
// Description:
//    Header file for kernel.c
//
// ==========================================================



#ifndef CIRCBUFT_H_
#define CIRCBUFT_H_



#include <stdint.h>



typedef struct {
    uint32_t size;
    int32_t *data;
    uint32_t windex;
    uint32_t rindex;
} circBuf_t;

int32_t * initCircBuf(circBuf_t *buffer, uint32_t size);
void writeCircBuf(circBuf_t *buffer, uint32_t entry);
int32_t readCircBuf(circBuf_t *buffer);
void freeCircBuf(circBuf_t *buffer);

/* FUNCTIONS */


#endif // CIRCBUFT_H_

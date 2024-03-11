// ==========================================================
//
// delay.c
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



#ifndef UTILS_H_
#define UTILS_H_



/* FUNCTIONS */
// Initialises the clock
void delayWaitInSeconds(double delay);

double max (double a, double b);
double min (double a, double b);

double clamp(double number, double min, double max);


#endif // UTILS_H_

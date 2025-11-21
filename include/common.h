#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <stdint.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include "driver/mcpwm.h"

#include <driver/gpio.h>
#include "sdkconfig.h"


// Hbot Motor Variables //


#define STEP_A_PIN 15
#define DIR_A_PIN  27

#define STEP_B_PIN 32
#define DIR_B_PIN  14

// MCPWM Units & Timers
#define MCPWM_UNIT_A MCPWM_UNIT_0
#define MCPWM_TIMER_A MCPWM_TIMER_0
#define MCPWM_OUT_A MCPWM0A

#define MCPWM_UNIT_B MCPWM_UNIT_1
#define MCPWM_TIMER_B MCPWM_TIMER_0
#define MCPWM_OUT_B MCPWM1A


/// Pin Names
// #define DIR_LEFT 32
// #define STEP_LEFT 33
// #define EN_LEFT 25
// #define DIR_RIGHT 26
// #define STEP_RIGHT 27
// #define EN_RIGHT 14

// #define STEPDELAY 1500

// ///
#define DUTYCYCLE  50 // recommended by driver do not change
#define STEPMM 16.0f
#define MMPERSTEP (1.0f/STEPMM) // (1600 ppr) / (100 mm/r) <- 5mm pitch, 20teeth pulley, 1.8 deg 

extern int32_t x_step_pos;
extern int32_t y_step_pos;
extern float x_mm_pos;
extern float y_mm_pos;


// Configurable Battery Grid vars (extern here, defined in hbot_grid.c)
extern float fork_y;
extern float channel_pad_y;

// Measured Battery Grid vars (extern here, defined in hbot_grid.c)
extern float bat_x;
extern float bat_y;
extern float xlim_tot;
extern float ylim_tot;

extern float x_channel;
extern float ystep;
extern float xstep;
extern int xstep_max;
extern int ystep_max;


// Input Vars
extern char mc;

// Motor constructs


#endif
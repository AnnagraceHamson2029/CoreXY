#include "common.h"


void init_PWM(){
    // Motor A Step PWM
    mcpwm_gpio_init(MCPWM_UNIT_A, MCPWM_OUT_A, STEP_A_PIN);
    mcpwm_config_t pwm_a;
    pwm_a.frequency = 1000;        // start at 1 kHz
    pwm_a.cmpr_a = 50.0;           // 50% duty
    pwm_a.cmpr_b = 0.0;
    pwm_a.counter_mode = MCPWM_UP_COUNTER;
    pwm_a.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_A, MCPWM_TIMER_A, &pwm_a);

    pinMode(DIR_A_PIN, OUTPUT);

    // Motor B Step PWM
    mcpwm_gpio_init(MCPWM_UNIT_B, MCPWM_OUT_B, STEP_B_PIN);
    mcpwm_config_t pwm_b;
    pwm_b.frequency = 1000;
    pwm_b.cmpr_a = 50.0;
    pwm_b.cmpr_b = 0.0;
    pwm_b.counter_mode = MCPWM_UP_COUNTER;
    pwm_b.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_B, MCPWM_TIMER_B, &pwm_b);

    pinMode(DIR_B_PIN, OUTPUT);
}

void setMotorFreqA(float freq) {
    mcpwm_set_frequency(MCPWM_UNIT_A, MCPWM_TIMER_A, freq);
}

void setMotorFreqB(float freq) {
    mcpwm_set_frequency(MCPWM_UNIT_B, MCPWM_TIMER_B, freq);
}

void GetSteppingParams(float x, float y) {
        // Global position state

        int32_t x_steps_target = round(x / MMPERSTEP);
        int32_t y_steps_target = round(y / MMPERSTEP);

        int32_t x_steps_to_do = x_steps_target - x_step_pos; // x_step_pos is global pos tracking var
        int32_t y_steps_to_do = y_steps_target - y_step_pos; // y_step_pos is global pos tracking var

        int32_t a_steps_to_do = x_steps_to_do + y_steps_to_do;
        int32_t b_steps_to_do = x_steps_to_do - y_steps_to_do;

        int directionA = (a_steps_to_do > 0) ? 0 : 1;
        int directionB = (b_steps_to_do > 0) ? 0 : 1;

        a_steps_to_do = abs(a_steps_to_do);
        b_steps_to_do = abs(b_steps_to_do);



        // Optionally Update Position Tracking Variables
        // Otherwise do in ISR?
        // x_step_pos = x_steps_target;
        // y_step_pos = y_steps_target;

        // x_mm_pos = x;
        // y_mm_pos = y;
}        
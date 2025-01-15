#pragma once

#include "Arduino.h"

#define SENSOR_PIN 3
#define LEFT_BLINKER_PIN 6
#define RIGHT_BLINKER_PIN 7
#define BLINK_DELAY 600

enum BLINKER_STATE
{
    IDLE,
    TURN_RIGHT,
    TURN_LEFT,
    WARNINGS,
    FULL,
};

enum LED_STRIPE
{
    OFF,
    ORANGE,
    BLUE,
};

typedef struct s_state
{
        BLINKER_STATE blinker_state;
        LED_STRIPE led_stripe_state;
} t_state;

void errorHalt();
// Update state
void updateBlinkerState(uint8_t cmd);
void updateLedStripeState(uint8_t cmd);

// take action
void blinkBlinkers(void* pvParameters);

void incrementSpeedCount();
void sendSpeedReadings();
void handleCanFrames(void* pvParameters);

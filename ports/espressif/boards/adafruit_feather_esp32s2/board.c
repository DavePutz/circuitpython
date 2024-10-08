// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2020 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include "supervisor/board.h"
#include "mpconfigboard.h"
#include "shared-bindings/microcontroller/Pin.h"
#include "driver/gpio.h"

void board_init(void) {
    reset_board();
}

void reset_board(void) {
    // Turn on I2C power by default.

    // set pin to input to find 'rest state'
    gpio_set_direction(7, GPIO_MODE_DEF_INPUT);
    // wait 1 millis for pull to activate
    mp_hal_delay_ms(1);
    // read rest state (off)
    bool restlevel = gpio_get_level(7);
    gpio_set_direction(7, GPIO_MODE_DEF_OUTPUT);
    // flip it!
    gpio_set_level(7, !restlevel);
}

// Use the MP_WEAK supervisor/shared/board.c versions of routines not defined here.

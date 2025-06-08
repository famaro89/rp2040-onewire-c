#ifndef ONEWIRE_H
#define ONEWIRE_H

#include "pico/stdlib.h"

typedef struct {
    uint gpio;
} onewire_t;

void onewire_init(onewire_t* ow);
bool onewire_reset(onewire_t* ow);
void onewire_write_bit(onewire_t* ow, bool bit);
bool onewire_read_bit(onewire_t* ow);
void onewire_write_byte(onewire_t* ow, uint8_t byte);
uint8_t onewire_read_byte(onewire_t* ow);

#endif
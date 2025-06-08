#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>
#include <stdbool.h>
#include "onewire.h"

bool ds18b20_start_conversion(onewire_t* ow);
bool ds18b20_read_scratchpad(onewire_t* ow, uint8_t* data);

#endif
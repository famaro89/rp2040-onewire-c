#include "ds18b20.h"

bool ds18b20_start_conversion(onewire_t* ow) {
    if (!onewire_reset(ow)) return false;
    onewire_write_byte(ow, 0xCC);
    onewire_write_byte(ow, 0x44);
    return true;
}

bool ds18b20_read_scratchpad(onewire_t* ow, uint8_t* data) {
    if (!onewire_reset(ow)) return false;
    onewire_write_byte(ow, 0xCC);
    onewire_write_byte(ow, 0xBE);
    for (int i = 0; i < 9; i++) {
        data[i] = onewire_read_byte(ow);
    }
    return true;
}
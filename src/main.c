#include <stdio.h>
#include "pico/stdlib.h"
#include "ds18b20.h"
#include "onewire.h"

#define ONE_WIRE_GPIO 18

int main() {
    stdio_init_all();
    sleep_ms(2000);

    onewire_t ow = { .gpio = ONE_WIRE_GPIO };
    onewire_init(&ow);

    while (true) {
        if (ds18b20_start_conversion(&ow)) {
            sleep_ms(750);
            uint8_t scratchpad[9];
            if (ds18b20_read_scratchpad(&ow, scratchpad)) {
                int16_t raw = (scratchpad[1] << 8) | scratchpad[0];
                float temp = raw / 16.0f;
                printf("Temp: %.2f C
", temp);
            } else {
                printf("Error leyendo scratchpad
");
            }
        } else {
            printf("Error iniciando conversión
");
        }
        sleep_ms(1000);
    }
}
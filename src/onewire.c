#include "onewire.h"
#include "hardware/gpio.h"

static void delay_us(uint32_t us) {
    busy_wait_us_32(us);
}

void onewire_init(onewire_t* ow) {
    gpio_init(ow->gpio);
    gpio_set_dir(ow->gpio, GPIO_OUT);
    gpio_put(ow->gpio, 1);
}

bool onewire_reset(onewire_t* ow) {
    gpio_set_dir(ow->gpio, GPIO_OUT);
    gpio_put(ow->gpio, 0);
    delay_us(480);
    gpio_set_dir(ow->gpio, GPIO_IN);
    delay_us(70);
    bool presence = !gpio_get(ow->gpio);
    delay_us(410);
    return presence;
}

void onewire_write_bit(onewire_t* ow, bool bit) {
    gpio_set_dir(ow->gpio, GPIO_OUT);
    gpio_put(ow->gpio, 0);
    delay_us(bit ? 6 : 60);
    gpio_put(ow->gpio, 1);
    delay_us(bit ? 64 : 10);
}

bool onewire_read_bit(onewire_t* ow) {
    gpio_set_dir(ow->gpio, GPIO_OUT);
    gpio_put(ow->gpio, 0);
    delay_us(6);
    gpio_set_dir(ow->gpio, GPIO_IN);
    delay_us(9);
    bool bit = gpio_get(ow->gpio);
    delay_us(55);
    return bit;
}

void onewire_write_byte(onewire_t* ow, uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        onewire_write_bit(ow, byte & 1);
        byte >>= 1;
    }
}

uint8_t onewire_read_byte(onewire_t* ow) {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
        byte >>= 1;
        if (onewire_read_bit(ow)) byte |= 0x80;
    }
    return byte;
}
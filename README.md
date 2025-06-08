# rp2040-onewire-c

Librería 1-Wire escrita en lenguaje C, no C++,  para la placa Raspberry Pi Pico RP2040, compatible con sensores como el DS18B20.

## 📌 Características

- Compatible con Raspberry Pi Pico (RP2040)
- Totalmente en lenguaje C
- Comunicación 1-Wire por GPIO
- Incluye ejemplo funcional para un DS18B20
- En esta primera version, solo funciona con un solo sensor conectado al bus

## 🧰 Wiring

- VCC: 3.3 V
- GND: GND
- DATA: GPIO 18 (con resistencia pull-up de 4.7kΩ a VCC)

## 🛠️ Compilación

```bash
mkdir build
cd build
cmake ..
make
```

## 📘 Autor

Este proyecto fue creado por **Facundo Amaro**.
Licencia: MIT
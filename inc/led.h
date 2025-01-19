#ifndef LED_H
#define LED_H

// Macros

#include <stdint.h>

#define LED_RED_PIN 13
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12

// Cabeçalhos

// Função para inicializar um LED
void led_init(uint8_t gpio);

// Função para ligar um LED
void led_turn_on(uint8_t gpio);

// Função para desligar um LED
void led_turn_off(uint8_t gpio);

// Função para desligar todos os LEDs
void leds_turn_off_all();

#endif
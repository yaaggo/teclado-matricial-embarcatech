#include "led.h"
#include "pico/stdlib.h"


// Função para inicializar um LED
void led_init(uint8_t gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
    gpio_put(gpio, 0); // Inicialmente desligado
}

// Função para ligar um LED
void led_turn_on(uint8_t gpio) {
    gpio_put(gpio, 1);
}

// Função para desligar um LED
void led_turn_off(uint8_t gpio) {
    gpio_put(gpio, 0);
}

// Função para desligar todos os LEDs
void leds_turn_off_all() {
    led_turn_off(LED_RED_PIN);
    led_turn_off(LED_GREEN_PIN);
    led_turn_off(LED_BLUE_PIN);
}
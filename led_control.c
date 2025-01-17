#include <stdio.h>
#include "pico/stdlib.h"


#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13


void inicializar_leds() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
}


void desligar_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}


void ligar_led(int gpio_pin) {
    desligar_leds(); 
    gpio_put(gpio_pin, 1);
}

int main() {
    stdio_init_all();
    inicializar_leds();

    char comando;
    printf("Controle de LEDs iniciado. Envie os comandos:\n");
    printf("'v' para LED Verde, 'a' para LED Azul, 'r' para LED Vermelho, 'd' para desligar\n");

    while (true) {
     
        comando = getchar_timeout_us(100000);
        if (comando != PICO_ERROR_TIMEOUT) {
            switch (comando) {
                case 'v':
                    ligar_led(LED_VERDE);
                    printf("LED Verde ligado.\n");
                    break;
                case 'a':
                    ligar_led(LED_AZUL);
                    printf("LED Azul ligado.\n");
                    break;
                case 'r':
                    ligar_led(LED_VERMELHO);
                    printf("LED Vermelho ligado.\n");
                    break;
                case 'd':
                    desligar_leds();
                    printf("Todos os LEDs desligados.\n");
                    break;
                default:
                    printf("Comando inválido.\n");
                    break;
            }
        }
    }
    return 0;
}
#include "buzzer.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

// Funções

// função para inicializar o buffer
void buzzer_init(uint8_t pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM); 
    uint slice_num = pwm_gpio_to_slice_num(pin); 
    pwm_config config = pwm_get_default_config(); 
    pwm_init(slice_num, &config, false); 
    pwm_set_gpio_level(pin, 0);
}

// Configura o PWM no pino do buzzer com uma frequência especificada
void buzzer_set_frequency(uint8_t pin, uint16_t frequency) {
    uint slice_num = pwm_gpio_to_slice_num(pin); 
    uint sys_clock = clock_get_hz(clk_sys);
    pwm_set_clkdiv(slice_num, sys_clock / (frequency * 4096));
    pwm_set_enabled(slice_num, true);
}

// Função para ligar e tocar o buzzer em uma frequência especifica 
void buzzer_play(uint8_t pin, uint16_t frequency) {
    buzzer_set_frequency(pin, frequency);
    pwm_set_gpio_level(pin, 32768); 
}

// Função para desligar o buzzer
void buzzer_stop(uint8_t pin) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, 0);
    pwm_set_enabled(slice_num, false);
}

// Função para fazer o beep do buzzer por 2 segundos
void buzzer_beep(uint8_t pin) {
    buzzer_play(pin, 1000);
    sleep_ms(2000);
    buzzer_stop(pin);
}
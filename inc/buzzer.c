#include "buzzer.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Funções

// Configura o PWM no pino do buzzer com uma frequência especificada
void buzzer_set_frequency(uint pin, uint frequency) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    gpio_set_function(pin, GPIO_FUNC_PWM);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (frequency * 4096));
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0);
}

// Função para ligar e tocar o buzzer em uma frequência especifica 
void buzzer_play(uint pin, uint frequency) {
    buzzer_set_frequency(pin, frequency);
    pwm_set_gpio_level(pin, 32768); 
}

// Função para desligar o buzzer
void buzzer_stop(uint pin) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_enabled(slice_num, false); 
    gpio_set_function(pin, GPIO_FUNC_SIO); 
    gpio_put(pin, false); 
}

// Função para fazer o beep do buzzer por 2 segundos
void buzzer_beep_2sec(uint gpio) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint clock_div = 4; // Divisor do clock
    uint sys_clock = clock_get_hz(clk_sys); // Frequência do sistema
    uint wrap = sys_clock / (clock_div * BUZZER_FREQ) - 1; // Calcula o valor de "wrap"

    pwm_set_clkdiv(slice_num, clock_div); // Define o divisor do clock
    pwm_set_wrap(slice_num, wrap); // Define o valor de "wrap"
    pwm_set_gpio_level(gpio, wrap / 2); // Ciclo de trabalho de 50%
    pwm_set_enabled(slice_num, true); // Habilita o PWM

    sleep_ms(2000); // Aguarda 2 segundos para o beep

    pwm_set_enabled(slice_num, false); // Desabilita o PWM
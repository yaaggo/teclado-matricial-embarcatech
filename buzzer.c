#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição do GPIO para o Buzzer
#define BUZZER_PIN 21 // Buzzer no GP21

// Inicializa o Buzzer
void init_buzzer(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM); // Configura o GPIO para PWM
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_enabled(slice_num, false); // Desabilita o PWM inicialmente
}

// Liga o Buzzer em uma determinada frequência
void turn_on_buzzer(uint gpio, uint freq) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint clock_div = 4; // Divisor do clock
    uint sys_clock = clock_get_hz(clk_sys); // Frequência do sistema
    uint wrap = sys_clock / (clock_div * freq) - 1; // Calcula o valor de "wrap" para a frequência desejada

    pwm_set_clkdiv(slice_num, clock_div); // Define o divisor do clock para a frequência
    pwm_set_wrap(slice_num, wrap); // Define o valor de "wrap" para a frequência
    pwm_set_gpio_level(gpio, wrap / 2); // Ciclo de trabalho de 50% (som contínuo)
    pwm_set_enabled(slice_num, true); // Habilita o PWM
}

// Desliga o Buzzer
void turn_off_buzzer(uint gpio) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_enabled(slice_num, false); // Desabilita o PWM (desliga o buzzer)
}

// Ativa o Buzzer por um tempo determinado (em milissegundos)
void beep_buzzer(uint gpio, uint freq, uint duration_ms) {
    turn_on_buzzer(gpio, freq); // Liga o buzzer com a frequência especificada
    sleep_ms(duration_ms); // Espera o tempo determinado
    turn_off_buzzer(gpio); // Desliga o buzzer após o tempo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial (para o console)

    // Inicializa o Buzzer no pino especificado (GP21)
    init_buzzer(BUZZER_PIN);

    // Exemplo: Ativar o Buzzer por 2 segundos com 1000 Hz
    printf("Ativando o buzzer por 2 segundos com 1000 Hz...\n");
    beep_buzzer(BUZZER_PIN, 1000, 2000); // Beep de 1000 Hz por 2 segundos

    // Espera um tempo antes de finalizar o programa
    sleep_ms(1000); // Aguarda 1 segundo antes de terminar

    printf("Programa finalizado.\n");

    return 0;
}

#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>
// Macros

#define BUZZER_A_PIN 21
#define BUZZER_FREQ 2000

// Cabeçalhos
void buzzer_init(uint8_t gpio);
void buzzer_beep(uint8_t gpio);
void buzzer_set_frequency(uint8_t pin, uint16_t frequency);
void buzzer_play(uint8_t pin, uint16_t frequency);
void buzzer_stop(uint8_t pin);



#endif
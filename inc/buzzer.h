#ifndef BUZZER_H
#define BUZZER_H
#include <stdint.h>
// Macros

#define BUZZER_A_PIN 21

// Cabeçalhos
void buzzer_set_frequency(uint pin, uint frequency);
void buzzer_play(uint pin, uint frequency);
void buzzer_stop(uint pin);



#endif
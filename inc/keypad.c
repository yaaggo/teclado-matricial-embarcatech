#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"

// Definição dos pinos das linhas e colunas
uint8_t rows[KEYPAD_ROWS] = {1, 2, 3, 4};
uint8_t columns[KEYPAD_COLS] = {5, 6, 7, 8};

// Mapeamento dos caracteres do teclado matricial
char KEY_MAP[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Funções

// função que inicializa o teclado matricial 4x4
void keypad_init() {
  for(int i=0; i < KEYPAD_ROWS ; i++) {
    gpio_init(rows[i]);
    gpio_set_dir(rows[i], GPIO_OUT);
    gpio_put(rows[i], 1);
  }

  for(int i=0; i < KEYPAD_COLS ; i++) {
    gpio_init(columns[i]);
    gpio_set_dir(columns[i], GPIO_IN);
    gpio_pull_up(columns[i]);
  }
}

// função que retorna o caractere pressionado no teclado matricial
char keypad_return() {

  char caractere = ' ';

  for(uint8_t i = 0; i < KEYPAD_ROWS; i++) {
    gpio_put(rows[i], 0);

    for(uint8_t j = 0; j < KEYPAD_COLS; j++) {
      if(gpio_get(columns[j]) == 0) {
        caractere = KEY_MAP[i][j];

        while(gpio_get(columns[j]) == 0) {
          sleep_ms(20);
        }
        break;
      }
    }
    gpio_put(rows[i], 1);
  }
  return caractere;
}
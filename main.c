#include "pico/stdlib.h"

#include "inc/keypad.h"
#include "inc/buzzer.h"
#include "inc/led.h"

int main () {
    bool buzzer_state = false;
    
    stdio_init_all();

    // inicializando componentes que serão usados

    keypad_init();

    buzzer_init(BUZZER_A_PIN);

    led_init(LED_RED_PIN);
    led_init(LED_GREEN_PIN);
    led_init(LED_BLUE_PIN);

    while(true) {
        char key_pressed =  keypad_return();

        // lógica para quando o botao for apertado, fazer uma das ações a seguir

        switch(key_pressed) {
            case '1': 
                gpio_get(LED_RED_PIN) ?
                led_turn_off(LED_RED_PIN):
                led_turn_on(LED_RED_PIN);
                break;
            case '2':
                gpio_get(LED_GREEN_PIN) ?
                led_turn_off(LED_GREEN_PIN):
                led_turn_on(LED_GREEN_PIN);
                break;
            case '3':
                gpio_get(LED_BLUE_PIN) ?
                led_turn_off(LED_BLUE_PIN):
                led_turn_on(LED_BLUE_PIN);
                break;
            case 'A':
                if (buzzer_state) {
                    buzzer_stop(BUZZER_A_PIN); 
                    buzzer_state = false;      
                } else {
                    buzzer_play(BUZZER_A_PIN, 1000);  
                    buzzer_state = true;            
                }
                break;
            case '4':
                buzzer_beep(BUZZER_A_PIN);
                break;
            case ' ':
                break;
            default:
                leds_turn_off_all();
                break;
        }
        sleep_ms(50);
    }
}

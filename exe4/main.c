#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R = 28;
const int LED_R = 5;
const int LED_P = 8;
const int LED_B = 11;
const int LED_Y = 15;



int main() {
  stdio_init_all();

  gpio_init(BTN_R);
  gpio_init(LED_R);
  gpio_init(LED_P);
  gpio_init(LED_B);
  gpio_init(LED_Y);

  gpio_set_dir(BTN_R,GPIO_IN);
  gpio_set_dir(LED_R,GPIO_OUT);
  gpio_set_dir(LED_P,GPIO_OUT);
  gpio_set_dir(LED_B,GPIO_OUT);
  gpio_set_dir(LED_Y,GPIO_OUT);

  gpio_pull_up(BTN_R);



  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN_R)) {
      gpio_put(LED_R, 1);
      sleep_ms(300);
      gpio_put(LED_R, 0);
      gpio_put(LED_P, 1);
      sleep_ms(300);
      gpio_put(LED_P, 0);
      gpio_put(LED_B, 1);
      sleep_ms(300);
      gpio_put(LED_B, 0);
      gpio_put(LED_Y, 1);
      sleep_ms(300);
      gpio_put(LED_Y, 0);

      while (!gpio_get(BTN_R)) {
      };
    }
  }
}

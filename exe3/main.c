#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_G = 26;
const int LED_G = 6;
const int BTN_R = 28;
const int LED_R = 4;

int main() {
  int ledg=0,ledr=0;
  stdio_init_all();

  gpio_init(BTN_G);
  gpio_init(LED_G);
  gpio_init(BTN_R);
  gpio_init(LED_R);

  gpio_set_dir(BTN_G,GPIO_IN);
  gpio_set_dir(LED_G,GPIO_OUT);
  gpio_set_dir(BTN_R,GPIO_IN);
  gpio_set_dir(LED_R,GPIO_OUT);

  gpio_pull_up(BTN_G);
  gpio_pull_up(BTN_R);


  while (true) {
    if (!gpio_get(BTN_G)) {
      ledg=!ledg;
      while (!gpio_get(BTN_G)) {
      };
    }
    if (!gpio_get(BTN_R)) {
      ledr=!ledr;
      while (!gpio_get(BTN_R)) {
      };
    }
    gpio_put(LED_G, ledg);
    gpio_put(LED_R, ledr);
  }
}

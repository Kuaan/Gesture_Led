#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_vfs_dev.h"
#include <stdio.h>

#define LED_PIN GPIO_NUM_2

void app_main() {
    // config.  GPIO2 as output (blue LED)
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Init. UART0
    setvbuf(stdin, NULL, _IONBF, 0);
    esp_vfs_dev_uart_use_driver(0);  // use UART0 stdin

    char ch;
    while (1) {
        ch = getchar();  //  UART get char
        if (ch == '1') {
            gpio_set_level(LED_PIN, 1);  // LED ON
            vTaskDelay(pdMS_TO_TICKS(500));  // delay 0.5 sec
            gpio_set_level(LED_PIN, 0);  // LED OFF
        }
    }
}

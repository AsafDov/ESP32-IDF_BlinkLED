#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO 2

void blinkLedTask(void* parameters){
    while(1){
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main() {
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    xTaskCreatePinnedToCore(blinkLedTask, "blink_task", 2048, NULL, 5, NULL,1);
}
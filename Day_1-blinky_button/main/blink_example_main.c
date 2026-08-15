#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED GPIO_NUM_4

void app_main(void)
{
    //setting up led pin
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    while(1)
    {
        gpio_set_level(LED, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED GPIO_NUM_4
#define BUT GPIO_NUM_5

void app_main(void)
{
    //setting up led pin
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    //setting up button pin
    gpio_reset_pin(BUT);
    gpio_set_direction(BUT, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUT, GPIO_PULLUP_ONLY);

    while(1)
    {
        if(gpio_get_level(BUT) == 0)
        {
            gpio_set_level(LED, 1);
        }
        else
        {
            gpio_set_level(LED, 0);
        }
        vTaskDelay(1/ portTICK_PERIOD_MS);
    }
    
}

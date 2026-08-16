#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//header files for serial monitor I/O
#include "esp_log.h"

//header files for adc
#include "esp_adc/adc_oneshot.h"

//header files for calibration
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"


static const char *TAG = "ADC_SIMPLE";

#define ADC_CHANNEL     ADC_CHANNEL_3     // using pin 4 i.e. channel 3
#define ADC_ATTEN       ADC_ATTEN_DB_12   // attenuation to read upto 3.3V

void app_main(void)
{
    //Creating the ADC1 unit
    adc_oneshot_unit_handle_t adc1_handle;
    adc_oneshot_unit_init_cfg_t init_config = {
        .unit_id = ADC_UNIT_1,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config, &adc1_handle));

    //Configuring the channel
    adc_oneshot_chan_cfg_t chan_config = {
        .atten = ADC_ATTEN,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL, &chan_config));

    // Calibration code
    ESP_LOGI(TAG, "calibration scheme version is %s", "Curve Fitting");
    //Creating and configuring calibration handle
    adc_cali_handle_t cali_handle = NULL;
    adc_cali_curve_fitting_config_t cali_config = {
        .unit_id = ADC_UNIT_1,
        .atten = ADC_ATTEN,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ESP_ERROR_CHECK(adc_cali_create_scheme_curve_fitting(&cali_config, &cali_handle));


    int raw, voltage;
    while (1) {
        ESP_ERROR_CHECK(adc_oneshot_read(adc1_handle, ADC_CHANNEL, &raw));//reading a single chl
        ESP_LOGI(TAG, "Raw: %d", raw);

        ESP_ERROR_CHECK(adc_cali_raw_to_voltage(cali_handle, raw, &voltage));
        ESP_LOGI(TAG, "ADC%d Channel[%d] Cali Voltage: %d mV", ADC_UNIT_1 + 1, ADC_CHANNEL, voltage);


        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
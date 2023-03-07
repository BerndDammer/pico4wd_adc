#include <stdbool.h>
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "adc.h"

#define ADC0 26
#define ADC1 27
#define ADC2 28

static void adc_init_gpio(int adc)
{
    gpio_init(adc);
    gpio_set_function(adc, GPIO_FUNC_NULL);
    gpio_set_dir(adc, false);
    gpio_disable_pulls(adc);
    gpio_set_input_enabled(adc, false);

}
void myadc_init(void)
{
    adc_init();
    adc_init_gpio(ADC0);
    adc_init_gpio(ADC1);
    adc_init_gpio(ADC2);

}

void myadc_get(int results[3])
{
    for (int i = 0; i < 3; i++)
    {

        adc_select_input(i);
        results[i] = adc_read();
    }
}

#include "loop.h"
#include "blinker.h"
#include "adc.h"

#include <stdio.h>
#include "pico/stdlib.h"
//#include "hardware/timer.h"
//#include "hardware/watchdog.h"
//#include "hardware/clocks.h"

#define CONSOLE_TIMEOUT 333444

void menu(void)
{
    printf("------------------------------------\n");
    printf("nothing to select\n");
    printf("------------------------------------\n");
}

void loop(void)
{
    volatile int c; // make visible in debugger; avoid optimize out
    int counter;
    int results[3];
    myadc_init();
    menu();

    for (;;)
    {
        c = getchar_timeout_us(CONSOLE_TIMEOUT);
        blinker_toggle();

        if (c == PICO_ERROR_TIMEOUT)
        {
            myadc_get(results);
            printf("ADC0: %6i        ADC1: %6i       ADC2 %6i\n", //
                    results[0], results[1], results[2]);
            counter++;
        }
        else
        {
            switch (c)
            {
            case ' ':
            case '0':
                printf("OOPs\n");
                break;
            default:
                menu();
                break;
            }
        }
    }
}

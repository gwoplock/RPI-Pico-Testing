// #include <stdio>
#include "hardware/irq.h"
#include "pico/time.h"
#include <pico/stdlib.h>
#include <hardware/structs/systick.h>
#include <iostream>
#include "hardware/exception.h"

volatile static uint64_t systickIsrCount = 0;

int main() {
    stdio_init_all();

    systick_hw->csr = 
        0 | /*enable, false*/ 
        (1 << 1) | /*interrupt enable, true*/ 
        (1 << 2); /*clock source, processor*/

    exception_set_exclusive_handler(SYSTICK_EXCEPTION, [] () {
        systickIsrCount++;
        std::cout << "systick isr ctr: " << systickIsrCount << std::endl;
    });

    systick_hw->rvr = 12500000; /* 0.1 seconds at 125Mhz */

    systick_hw->cvr = 0; /* Clear current value */

    systick_hw->csr = systick_hw->csr | 1;

    // for (uint64_t i = 0; i < 1000000000; i++){
    //     // std::cout << "systick isr ctr: " << systickIsrCount << std::endl;
    //     sleep_us(10000);
    // }

    for (;;);
}
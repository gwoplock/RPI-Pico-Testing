// #include <stdio>
#include <pico/stdlib.h>
#include <hardware/structs/systick.h>
#include <iostream>

int main() {
    stdio_init_all();
    systick_hw->csr = 
        0 | /*enable, false*/ 
        (0 << 1) | /*interrupt enable, false*/ 
        (1 << 2); /*clock source, processor*/

    systick_hw->rvr = 12500000; /* 0.1 seconds at 125Mhz */

    systick_hw->cvr = 0; /* Clear current value */

    systick_hw->csr = systick_hw->csr | 1;

    for (uint64_t i = 0; i < 1000000000; i++){
        std::cout << "systick: " << systick_hw->cvr << std::endl;
    }
}
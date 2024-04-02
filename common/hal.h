#include <stdint.h>
#include <stddef.h>

#ifndef HAL_H
#define HAL_H

enum clock_mode {
    CLOCK_FAST,
    CLOCK_BENCHMARK
};

void hal_setup(const enum clock_mode clock);
void hal_send_str(const char* in);
void hal_send_bytes(const unsigned char *in, size_t len);
uint64_t hal_get_time(void);
void hal_gpio_set(void);
void hal_gpio_clear(void);

#endif

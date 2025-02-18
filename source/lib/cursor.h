#pragma once

#include <stdint.h>
#include <stddef.h>

static inline void outb(uint16_t port, uint8_t value);
void cupdate(int x, int y);
void disable_cursor();
void enable_cursor();



#pragma once

#include <stdint.h>
#include <stddef.h>

void cupdate(int x, int y);
void disable_cursor();
static inline void outb(uint16_t port, uint8_t value);


#pragma once

#include "io.h"
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

enum {
    BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15,
};

 void newline(void);
 void enablecursor(void);
 void disablecursor(void);
 void move(int x, int y);
 void clear(void);
 void printc(char character);
 void print(char* string);
 void color(uint8_t foreground, uint8_t background);
uint16_t cursorlocation(void);

#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t current_color = WHITE | BLACK << 4;  // Renamed from 'color'

// If BW is defined, force black and white output
#ifdef BW
    #define BLACK_AND_WHITE 1
#else
    #define BLACK_AND_WHITE 0
#endif
#ifdef CURSOR_AUTOFOLLOW
    #define CURSOR_AUTOFOLLOW 1
#else
    #define CURSOR_AUTOFOLLOW 0
#endif

void enablecursor(void) {
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) & 0xC0) | 0);

    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3D5) & 0xE0) | 15);
}

void disablecursor(void) {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}

void move(int x, int y) {
    uint16_t pos = y * NUM_COLS + x;

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: current_color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void clear(void) {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void newline(void) {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void printc(char character) {
    if (character == '\n') {
        newline();
        return;
    }

    if (col >= NUM_COLS) {
        newline();
    }

    // If BW is defined, force the color to black and white
    if (BLACK_AND_WHITE) {
        current_color = WHITE | BLACK << 4;
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: current_color,
    };

    col++;

    // Move cursor automatically after printing
    move(col, row);
}

void print(char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        char character = (uint8_t) str[i];

        if (character == '\n') {
            newline();
        } else {
            printc(character);
        }
    }
}

void color(uint8_t foreground, uint8_t background) {
    // If BW is defined, force the color to black and white
    if (BLACK_AND_WHITE) {
        current_color = WHITE | BLACK << 4;
    } else {
        current_color = foreground + (background << 4);  // Updated to 'current_color'
    }
}

uint16_t cursorlocation(void) {
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
}
#include "cursor.h"
#define VGA_WIDTH 80

void cupdate(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

static inline void outb(uint16_t port, uint8_t value)
{
    __asm__ volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}
void enable_cursor()
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x0E); // Cursor start scanline (typical value)
    outb(0x3D4, 0x0B);
    outb(0x3D5, 0x0F); // Cursor end scanline (typical value)
}



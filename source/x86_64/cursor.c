#include "cursor.h"
#include "io.h"

extern uint32_t* framebuffer;  // Pointer to the framebuffer
extern uint32_t framebuffer_width;
extern uint32_t framebuffer_height;
extern uint32_t framebuffer_bpp;

void draw_cursor(int x, int y)
{
    // Simple example: drawing a white 5x5 cursor
    int cursor_size = 5;
    for (int dy = 0; dy < cursor_size; dy++) {
        for (int dx = 0; dx < cursor_size; dx++) {
            if (x + dx < framebuffer_width && y + dy < framebuffer_height) {
                // Simple white color for the cursor
                framebuffer[(y + dy) * framebuffer_width + (x + dx)] = 0xFFFFFF;
            }
        }
    }
}

void cupdate(int x, int y) {
    // Draw the cursor at the new position
    draw_cursor(x, y);
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



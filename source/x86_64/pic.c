// pic.c

#include "pic.h"

void pic_eoi(uint8_t irq) {
    if(irq >= 8) outb(PIC_2_CMD, PIC_EOI);

    outb(PIC_1_CMD, PIC_EOI);
}

void pic_disable(void) {
    outb(PIC_2_DATA, 0xFF);
    outb(PIC_1_DATA, 0xFF);
}

void irq_mask(uint8_t irq) {
    uint16_t port;
    uint8_t value;

    if(irq < 8) port = PIC_1_DATA;
    else {
        irq -= 8;
        port = PIC_2_DATA;
    }
    value = inb(port) & ~(1 << irq);
    outb(port, value);
}

// todo, add a pic_remap function
// pic.h

#pragma once
#include "io.h"

#define PIC_1_CMD  0x20
#define PIC_1_DATA 0x21

#define PIC_2_CMD  0xA0
#define PIC_2_DATA 0xA1

#define NEW_IRQ_0  0x20 // IRQ 0-7  will be mapped to interrupts 0x20-0x27 (32-39)
#define NEW_IRQ_8  0x28 // IRQ 8-15 will be mapped to interrupts 0x28-0x2F (40-47)

#define PIC_EOI    0x20 // "End of interrupt" command

void pic_eoi(uint8_t irq);
void pic_disable(void);
void irq_mask(uint8_t irq);

// todo, add a pic_remap function



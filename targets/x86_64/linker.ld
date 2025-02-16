ENTRY(start)

SECTIONS
{
    . = 1M;                     /* Set the start address to 1MB */

    .boot : 
    {
        KEEP(*(.multiboot_header))   /* Keep the multiboot header */
    }

    .text :
    {
        *(.text)                   /* All .text sections from object files */
    }

    .data :
    {
        *(.data)                   /* All .data sections from object files */
    }

    .bss :
    {
        *(.bss)                    /* All .bss sections from object files */
    }
    
    . = ALIGN(8);  /* Align to 8-byte boundary */
}

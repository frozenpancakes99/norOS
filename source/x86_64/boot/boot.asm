section .multiboot_header
    align 8
header_start:
    dd 0xE85250D6                ; Multiboot2 magic number
    dd 0                         ; Architecture type (0 for i386)
    dd header_end - header_start ; Header length
    dd -(0xE85250D6 + 0 + (header_end - header_start)) ; Checksum

    ; End tag
    align 8
    dw 0
    dw 0
    dd 8
header_end:

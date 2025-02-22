section .multiboot_header
align 8
header_start:
    dd 0xe85250d6                  ; Multiboot2 magic number
    dd 0                            ; Architecture (0 for i386)
    dd header_end - header_start    ; Header length
    dd -(0xe85250d6 + 0 + (header_end - header_start)) ; Checksum

    align 8
    ; Framebuffer request tag
    dw 5   ; Type: Framebuffer
    dw 1   ; Flags: Required (change to 0 if optional)
    dd 24  ; Size of this tag (updated to include framebuffer address and pitch)
    dd 800 ; Width
    dd 600 ; Height
    dd 24  ; Bits per pixel
    dd framebuffer_address          ; Framebuffer address (where the framebuffer is located)
    dd framebuffer_pitch            ; Number of bytes per row

    align 8
    ; End tag
    dw 0
    dw 0
    dd 8
header_end:

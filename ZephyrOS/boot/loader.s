[BITS 16]
[ORG 0x7C00]

; Assume `boot.s` already loaded `loader.s` to memory.

start:
    cli                     ; Disable interrupts
    cld                     ; Clear direction flag

    ; Set up GDT (for protected mode)
    lgdt [gdt_descriptor]

    ; Enable A20 line (to access all memory above 1MB)
    call enable_a20

    ; Switch to protected mode
    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp CODE_SEG:init_protected_mode

[BITS 32]
init_protected_mode:
    ; Update segment registers
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Load kernel from disk to memory at 0x100000
    mov esi, KERNEL_SEG      ; Destination segment
    call load_kernel

    ; Jump to kernel entry point
    jmp KERNEL_SEG:0x0

; Enable A20 line to access memory above 1MB
enable_a20:
    ; Enable A20 line code here (usually involves keyboard controller)
    ret

; Load Kernel Function (reads sectors and loads kernel to memory)
load_kernel:
    ; BIOS interrupt to load kernel (INT 0x13, AH = 0x02)
    ; Load sectors into memory at KERNEL_SEG
    ; Adjust sector count based on kernel size
    ret

; GDT Setup
gdt_start:
    ; GDT entries (null, code segment, data segment)
gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start
gdt_end:

; Segment Selectors
CODE_SEG equ 0x08
DATA_SEG equ 0x10
KERNEL_SEG equ 0x1000  ; Load kernel to 0x1000:0

times 510-($-$$) db 0  ; Pad to 512 bytes
dw 0xAA55              ; Boot signature

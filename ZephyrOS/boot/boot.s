; boot.s - Simple bootloader

[BITS 16]         ; We are in 16-bit mode

ORG 0x7C00        ; BIOS loads the bootloader to address 0x7C00

start:
    cli           ; Clear interrupts to prevent interference
    mov ax, 0x1000 ; Load address 0x1000 into AX (where the kernel will go)
    mov es, ax    ; Set ES segment to 0x1000

    ; Load the kernel from disk to memory at 0x1000
    mov bx, 0x0000  ; Start at offset 0 in segment 0x1000
    mov dh, 0       ; Track sectors read

load_kernel:
    mov ah, 0x02   ; BIOS interrupt 0x13 (Read sectors)
    mov al, 1      ; Read 1 sector at a time
    mov ch, 0      ; Cylinder number
    mov cl, 2      ; Sector number (start reading from sector 2)
    mov dl, 0      ; Drive number (0x00 for the first floppy drive or hard drive)

    int 0x13       ; Call BIOS to load sector

    jc load_failed ; Jump if carry flag is set (read error)

    inc bx         ; Advance to the next sector in memory
    inc dh         ; Track how many sectors we've loaded

    cmp dh, 10     ; Stop after loading 10 sectors (adjust as needed)
    jl load_kernel ; Loop until kernel is fully loaded

    ; Jump to kernel entry point at 0x1000:0000
    jmp 0x1000:0x0000

load_failed:
    ; Handle loading failure (simple infinite loop)
    hlt
    jmp load_failed

times 510-($-$$) db 0  ; Fill remaining space with zeros
dw 0xAA55              ; Boot signature (required for BIOS to boot)

OUTPUT_FORMAT("binary")
OUTPUT_ARCH(i386) // Change this to the appropriate architecture if needed

SECTIONS
{
    /* The entry point for the kernel */
    . = 0x1000; // Start the kernel at address 0x1000

    /* Text section for code */
    .text : {
        *(.text)       /* All .text sections from all object files */
    }

    /* Data section for initialized data */
    .data : {
        *(.data)       /* All .data sections from all object files */
    }

    /* BSS section for uninitialized data */
    .bss : {
        *(.bss)        /* All .bss sections from all object files */
        *(COMMON)      /* Include common symbols */
    }

    /* Stack section (optional, depends on your architecture and needs) */
    .stack (NOLOAD) : {
        . = . + 0x2000; // Allocate 8KB for the stack
    }
}

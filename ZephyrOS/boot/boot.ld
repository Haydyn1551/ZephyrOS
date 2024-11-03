ENTRY(start)               /* Entry point for the kernel */
OUTPUT_FORMAT("binary")    /* Output format: raw binary */

SECTIONS
{
    /* Place the kernel at the 1MB mark (0x100000) */
    . = 0x00100000;

    /* .text section: Contains the code */
    .text : {
        *(.text)           /* Include all .text sections from object files */
    }

    /* .data section: Contains initialized data */
    .data : {
        *(.data)           /* Include all .data sections from object files */
    }

    /* .bss section: Contains uninitialized data */
    .bss : {
        *(.bss)            /* Include all .bss sections from object files */
        *(COMMON)          /* Include common uninitialized variables */
    }
}

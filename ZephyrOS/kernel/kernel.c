#include <stdint.h>
#include "kernel.h"
#include "interrupts.h"
#include "memory.h"
#include "drivers.h"

// The main kernel entry point
void kernel_main() {
    // Initialize subsystems
    init_memory();        // Initialize memory management
    init_idt();          // Initialize the Interrupt Descriptor Table
    init_display();      // Initialize the display driver
    init_keyboard();     // Initialize keyboard driver

    // Enable interrupts
    enable_interrupts();

    // Main kernel loop
    while (1) {
        // Here you can implement process management, handle system calls, etc.
        // For example, you could check for user input, manage processes, etc.
        
        // Placeholder: just a simple output to the display
        print_char('>'); // Example function to print a character
    }
}

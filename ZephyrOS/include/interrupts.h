#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

// Function prototypes for interrupt handling
void init_idt();                // Initialize the Interrupt Descriptor Table
void enable_interrupts();        // Enable hardware interrupts
void disable_interrupts();       // Disable hardware interrupts
void default_handler();          // Default interrupt handler

// You can declare specific interrupt service routines (ISRs) here
void keyboard_isr();            // ISR for keyboard interrupts

#endif // INTERRUPTS_H

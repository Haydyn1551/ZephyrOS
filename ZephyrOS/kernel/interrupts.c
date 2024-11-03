#include <stdint.h>
#include "io.h"
#include "interrupts.h"
#include "kernel.h" // For kernel_main prototype

// Define the IDT entry structure
typedef struct {
    uint16_t offset_low;   // Lower 16 bits of the offset to the handler
    uint16_t selector;     // Kernel segment selector
    uint8_t  zero;         // Reserved, set to zero
    uint8_t  type_attr;    // Type and attributes
    uint16_t offset_high;  // Higher 16 bits of the offset to the handler
} __attribute__((packed)) idt_entry_t;

#define IDT_SIZE 256
idt_entry_t idt[IDT_SIZE];

// Function to set an IDT entry
void set_idt_entry(uint8_t interrupt_number, void (*handler)(), uint16_t selector, uint8_t type_attr) {
    idt[interrupt_number].offset_low = (uint16_t)((uintptr_t)handler & 0xFFFF);
    idt[interrupt_number].selector = selector;
    idt[interrupt_number].zero = 0;
    idt[interrupt_number].type_attr = type_attr;
    idt[interrupt_number].offset_high = (uint16_t)(((uintptr_t)handler >> 16) & 0xFFFF);
}

// Load the IDT (this is a x86 specific instruction)
extern void load_idt(uint32_t idt_pointer);

// Function to initialize the IDT
void init_idt() {
    // Initialize IDT entries for the interrupts you want to handle
    for (uint8_t i = 0; i < IDT_SIZE; i++) {
        set_idt_entry(i, default_handler, 0x08, 0x8E); // Example: using a default handler
    }

    // Load the IDT
    load_idt((uintptr_t)&idt);
}

// Default interrupt handler
void default_handler() {
    // This function can handle unhandled interrupts
    // You might want to log this or print a message
}

// Example keyboard ISR
void keyboard_isr() {
    // Read the key from the keyboard port
    uint8_t key = inb(KEYBOARD_PORT);
    handle_key(key); // Assuming you have a function to handle key input
}

// You would also need to declare and implement other ISRs as necessary

// Function to enable interrupts
void enable_interrupts() {
    __asm__ volatile("sti"); // Set the interrupt flag
}

// Function to disable interrupts
void disable_interrupts() {
    __asm__ volatile("cli"); // Clear the interrupt flag
}

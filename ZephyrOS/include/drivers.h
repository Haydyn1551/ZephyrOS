#ifndef DRIVERS_H
#define DRIVERS_H

#include <stdint.h>

// Function prototypes for device drivers
void init_keyboard();
void keyboard_handler(); // Handler for keyboard interrupts
void init_display();     // Initialize the display
void print_char(char c); // Print a character to the display
void clear_screen();     // Clear the display screen

// Additional driver functions can be declared here...

#endif // DRIVERS_H

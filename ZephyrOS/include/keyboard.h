#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

void init_keyboard();               // Initialize keyboard
char wait_for_keypress();           // Wait for a key press and return the character
void keyboard_interrupt_handler();   // Handle keyboard interrupts

#endif // KEYBOARD_H

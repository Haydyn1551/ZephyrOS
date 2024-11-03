#include "stdio.h"
#include "display.h"  // For printing output
#include "keyboard.h"  // For keyboard input handling
#include <stdarg.h>    // For handling variable arguments

void printf(const char* format, ...) {
    char buffer[256]; // Buffer for formatted string
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args); // Use a custom function to format the string
    va_end(args);

    print_string(buffer); // Print formatted string to display
}

char getchar() {
    // Wait for a character from the keyboard and return it
    // Assuming you have implemented a function to get a character
    return wait_for_keypress(); // This function needs to be defined in keyboard.c
}

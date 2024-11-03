#include <stdint.h>

// VGA screen dimensions
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

// VGA memory address for text mode
#define VIDEO_MEMORY ((uint16_t*)0xB8000)

// Default color: Light Gray on Black background
#define DEFAULT_COLOR 0x07

// Cursor position
int cursor_x = 0;
int cursor_y = 0;

// Function prototypes
void clear_screen();
void set_cursor(int x, int y);
void put_char(char c, uint8_t color);
void print_string(const char* str, uint8_t color);

// Function to clear the screen
void clear_screen() {
    uint16_t blank = ' ' | (DEFAULT_COLOR << 8);
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        VIDEO_MEMORY[i] = blank;
    }
    set_cursor(0, 0);  // Reset cursor position
}

// Set the cursor position on the screen
void set_cursor(int x, int y) {
    cursor_x = x;
    cursor_y = y;
    uint16_t position = y * VGA_WIDTH + x;

    // Update the cursor position in VGA hardware
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((position >> 8) & 0xFF));
}

// Output a single character at the current cursor position
void put_char(char c, uint8_t color) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        VIDEO_MEMORY[cursor_y * VGA_WIDTH + cursor_x] = (uint16_t)c | (uint16_t)(color << 8);
        cursor_x++;
    }

    // Move to the next line if at the end of the current line
    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }

    // Scroll the screen if at the bottom
    if (cursor_y >= VGA_HEIGHT) {
        for (int y = 1; y < VGA_HEIGHT; y++) {
            for (int x = 0; x < VGA_WIDTH; x++) {
                VIDEO_MEMORY[(y - 1) * VGA_WIDTH + x] = VIDEO_MEMORY[y * VGA_WIDTH + x];
            }
        }

        // Clear the last line
        for (int x = 0; x < VGA_WIDTH; x++) {
            VIDEO_MEMORY[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = ' ' | (DEFAULT_COLOR << 8);
        }
        cursor_y = VGA_HEIGHT - 1;
    }

    set_cursor(cursor_x, cursor_y);
}

// Output a string at the current cursor position
void print_string(const char* str, uint8_t color) {
    for (int i = 0; str[i] != '\0'; i++) {
        put_char(str[i], color);
    }
}

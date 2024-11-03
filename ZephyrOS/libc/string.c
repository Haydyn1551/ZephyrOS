#include "string.h"

// Get the length of a string
size_t strlen(const char* str) {
    const char* s = str;
    while (*s) {
        s++;
    }
    return s - str; // Return the length of the string
}

// Copy a string
char* strcpy(char* dest, const char* src) {
    char* original_dest = dest; // Save the starting address of dest
    while ((*dest++ = *src++)); // Copy src to dest, including null terminator
    return original_dest; // Return the original destination pointer
}

// Compare two strings
int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2; // Return the difference of the first unmatched character
}

// Concatenate two strings
char* strcat(char* dest, const char* src) {
    char* original_dest = dest; // Save the starting address of dest
    while (*dest) {
        dest++; // Move to the end of dest
    }
    while ((*dest++ = *src++)); // Copy src to the end of dest, including null terminator
    return original_dest; // Return the original destination pointer
}

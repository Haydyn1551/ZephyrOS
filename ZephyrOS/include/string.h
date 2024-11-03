#ifndef STRING_H
#define STRING_H

#include <stddef.h> // For size_t

size_t strlen(const char* str);                // Get the length of a string
char* strcpy(char* dest, const char* src);     // Copy a string
int strcmp(const char* str1, const char* str2); // Compare two strings
char* strcat(char* dest, const char* src);      // Concatenate two strings
void* memset(void* dest, int val, size_t count); // Set memory

#endif // STRING_H

#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h> // For size_t

void* malloc(size_t size);  // Allocate memory
void free(void* ptr);        // Free allocated memory
void* memset(void* dest, int val, size_t count); // Set memory
int atoi(const char* str);   // Convert string to integer

#endif // STDLIB_H

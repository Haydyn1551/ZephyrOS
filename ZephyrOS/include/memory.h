#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>  // For uint32_t, etc.
#include <stddef.h>  // For size_t (if available, otherwise define it below)

// If stddef.h is not available, define size_t manually
typedef unsigned long size_t; // A common definition of size_t

#define MEMORY_POOL_SIZE (1024 * 1024) // Example size for memory pool

// Memory management functions
void init_memory(); // Initialize memory management
void* allocate_memory(size_t size); // Allocate memory
void free_memory(void* ptr); // Free allocated memory

// Additional memory management functions can be added here...

#endif // MEMORY_H

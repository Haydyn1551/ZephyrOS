#include "memory.h"
#include <stdint.h>

#define MEMORY_POOL_SIZE (1024 * 1024) // 1 MB for the memory pool

static uint8_t memory_pool[MEMORY_POOL_SIZE]; // The memory pool
static size_t next_free; // Pointer to the next free memory location

// Initialize the memory management system
void init_memory() {
    next_free = 0; // Start from the beginning of the memory pool
}

// Allocate memory from the pool
void* allocate_memory(size_t size) {
    if (next_free + size > MEMORY_POOL_SIZE) {
        return NULL; // Not enough memory
    }
    void* ptr = &memory_pool[next_free]; // Get the current free memory location
    next_free += size; // Move the free pointer forward
    return ptr; // Return the allocated memory
}

// Free memory (for this simple example, we don't actually free memory)
void free_memory(void* ptr) {
    // No operation in this basic implementation
    // In a more advanced system, you'd track allocated blocks and free them properly
}

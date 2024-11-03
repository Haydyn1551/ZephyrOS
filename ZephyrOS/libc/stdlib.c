#include "stdlib.h"
#include <stdint.h>

#define MEMORY_POOL_SIZE (1024 * 1024) // 1 MB
static uint8_t memory_pool[MEMORY_POOL_SIZE];
static size_t next_free = 0; // Next free byte in the pool

void* malloc(size_t size) {
    if (next_free + size > MEMORY_POOL_SIZE) {
        return NULL; // Not enough memory
    }
    void* ptr = &memory_pool[next_free]; // Allocate memory
    next_free += size; // Move the pointer forward
    return ptr; // Return the pointer to allocated memory
}

void free(void* ptr) {
    // Simple implementation: Do nothing, as we don't track allocations
}

void* memset(void* dest, int val, size_t count) {
    unsigned char* p = dest;
    while (count--) {
        *p++ = (unsigned char)val; // Set each byte to the specified value
    }
    return dest; // Return the destination pointer
}

int atoi(const char* str) {
    int result = 0;
    while (*str >= '0' && *str <= '9') { // Convert characters to integer
        result = result * 10 + (*str - '0');
        str++;
    }
    return result; // Return the converted integer
}

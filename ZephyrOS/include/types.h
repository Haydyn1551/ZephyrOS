#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// Define standard types
typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef int32_t  int32;

// Define additional types
typedef struct {
    uint32_t id;    // Process ID
    uint32_t state; // Process state (running, waiting, etc.)
    // Other process information...
} process_t;

// Define more types as needed...

#endif // TYPES_H

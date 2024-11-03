#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

typedef struct {
    uint32_t pid;            // Process ID
    uint32_t state;          // Process state (running, waiting, etc.)
    // Add additional fields as necessary (e.g., stack pointer, priority)
} process_t;

// Function declarations
void init_processes();      // Initialize the process management system
uint32_t create_process();  // Create a new process and return its PID
void terminate_process(uint32_t pid); // Terminate a process by its PID

#endif // PROCESS_H

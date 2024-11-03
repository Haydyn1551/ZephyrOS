#include "scheduler.h"
#include "process.h" // Include your process management header
#include <stdint.h>

#define MAX_PROCESSES 256

// Define a structure to represent a process
typedef struct {
    uint32_t pid; // Process ID
    uint32_t state; // Process state (running, waiting, etc.)
    // Add more fields as needed (e.g., stack pointer, priority, etc.)
} process_t;

// Process table
static process_t process_table[MAX_PROCESSES];
static uint32_t current_process_index = 0; // Index of the currently running process
static uint32_t num_processes = 0; // Count of currently loaded processes

// Function to add a new process to the scheduler
void add_process(uint32_t pid) {
    if (num_processes < MAX_PROCESSES) {
        process_table[num_processes].pid = pid;
        process_table[num_processes].state = 1; // Set to running state
        num_processes++;
    }
}

// Round-robin scheduler function
void schedule() {
    if (num_processes == 0) {
        return; // No processes to schedule
    }

    // Save the context of the currently running process
    save_process_context(process_table[current_process_index].pid);

    // Move to the next process in a round-robin fashion
    current_process_index = (current_process_index + 1) % num_processes;

    // Load the context of the next process to run
    load_process_context(process_table[current_process_index].pid);
}

// Dummy functions for context saving and loading
void save_process_context(uint32_t pid) {
    // Here you would save the state of the process (registers, stack pointer, etc.)
}

void load_process_context(uint32_t pid) {
    // Here you would load the state of the next process (registers, stack pointer, etc.)
}

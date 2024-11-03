#include "syscalls.h"
#include "display.h" // Include your display driver for printing
#include "process.h" // Include your process management header
#include "scheduler.h" // Include the scheduler header
#include <stdint.h>

// Function prototypes for system call handlers
void syscall_print(const char* message);
void syscall_exit(uint32_t exit_code);

// Main syscall handler
void syscall_handler(uint32_t syscall_number, uint32_t arg1, uint32_t arg2) {
    switch (syscall_number) {
        case SYSCALL_PRINT:
            syscall_print((const char*)arg1);
            break;
        case SYSCALL_EXIT:
            syscall_exit(arg1);
            break;
        default:
            // Handle unknown syscall (could log an error or ignore)
            break;
    }
}

// Implementation of the print system call
void syscall_print(const char* message) {
    // Your implementation to print the message to the display
    // Assuming you have a function like print_string in your display driver
    print_string(message);
}

// Implementation of the exit system call
void syscall_exit(uint32_t exit_code) {
    // Handle process exit (cleanup and schedule next process)
    terminate_process(current_process()->pid); // Ensure you have a function to get the current process
    schedule(); // Schedule the next process
}

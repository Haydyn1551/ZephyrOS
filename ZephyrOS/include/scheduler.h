#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

// Function declarations
void add_process(uint32_t pid); // Add a process to the scheduler
void schedule();                 // Run the scheduler
void init_scheduler();           // Initialize the scheduler

#endif // SCHEDULER_H

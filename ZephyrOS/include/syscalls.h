#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h> // For fixed-width integer types
#include <stddef.h> // For size_t (if available, otherwise define it below)

// If stddef.h is not available, define size_t manually
typedef unsigned long size_t; // A common definition of size_t

// Define syscall numbers
#define SYS_READ  0
#define SYS_WRITE 1
#define SYS_EXIT  2

// Function prototypes for system calls
int sys_read(int fd, void* buf, size_t count);
int sys_write(int fd, const void* buf, size_t count);
void sys_exit(int status);

// Additional syscall functions can be defined here...

#endif // SYSCALLS_H

/*
============================================================================
Name        : 23.c
Author      : Tirth Gojariya (MT2026106)
Description : Create a zombie process.
Date        : 20 September 2026
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process exiting. PID = %d\n", getpid());
        exit(0); // Child exits immediately â†’ becomes zombie
    } else {
        // Parent process sleeps to keep child zombie
        printf("Parent process sleeping. PID = %d\n", getpid());
        sleep(30); // Check zombie using `ps -l`
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

# Run the program in one terminal:
./a.out
Child process exiting. PID = 1044
Parent process sleeping. PID = 1045

# In another terminal, check zombie:
ps -l | grep 23
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 Z  1000  7301  7300  0  80   0 -  0 exit   pts/2    00:00:00 23   # Z = zombie
0 S  1000  7300  7299  0  80   0 -  1512 do_wai pts/2    00:00:00 a.out

============================================================================
*/


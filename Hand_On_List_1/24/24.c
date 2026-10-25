/*
============================================================================
Name        : 24.c
Author      : Tirth Gojariya (MT2026106)
Description : Create an orphan process (child adopted by init).
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
        printf("Child process started. PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(10);  // Give time to parent to exit
        printf("Child after parent exit. PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process exiting. PID = %d\n", getpid());
        exit(0);   // Parent exits immediately â†’ child becomes orphan
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

# Run the program:
Parent process exiting. PID = 1063
Child process started. PID = 1064, Parent PID = 1063
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/24$ Child after parent exit. PID = 1064, Parent PID = 388
============================================================================
*/


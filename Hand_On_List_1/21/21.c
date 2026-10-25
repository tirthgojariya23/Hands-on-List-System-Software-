/*
============================================================================
Name        : 21.c
Author      : Tirth Gojariya (MT2026106)
Description : Simple fork example to print parent and child PIDs.
Date        : 20 September 2026
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ mkdir 21
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 21
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/21$ vim 21.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/21$ gcc 21.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/21$ ./a.out
Parent process: PID = 933, Child PID = 934
Child process: PID = 934, Parent PID = 933
============================================================================
*/


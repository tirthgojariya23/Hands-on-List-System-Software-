/*
Name : 31a.c
Author : Tirth Gojariya (MT2026106)
Description : Write a separate program using the sigaction system call to
              catch the SIGSEGV signal (segmentation fault).
Date : 25 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    printf("Caught SIGSEGV (signal %d) via sigaction: Invalid memory access!\n", signum);
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("SIGSEGV handler (sigaction) registered. Triggering segfault...\n");

    int *p = NULL;
    *p = 42;   /* NULL dereference -> SIGSEGV */

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/31$ gcc 31a.c -o 31a

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/31$ ./31a
SIGSEGV handler (sigaction) registered. Triggering segfault...
Caught SIGSEGV (signal 11) via sigaction: Invalid memory access!

*/

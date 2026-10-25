/*
Name : 31c.c
Author : Tirth Gojariya (MT2026106)
Description : Write a separate program using the sigaction system call to
              catch the SIGFPE signal (floating-point / arithmetic exception).
Date : 25 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    printf("Caught SIGFPE (signal %d) via sigaction: Divide by zero!\n", signum);
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("SIGFPE handler (sigaction) registered. Triggering divide-by-zero...\n");

    volatile int x = 0;
    volatile int y = 5 / x;   /* -> SIGFPE */
    (void)y;

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/31$ gcc 31c.c -o 31c

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/31$ ./31c
SIGFPE handler (sigaction) registered. Triggering divide-by-zero...
Caught SIGFPE (signal 8) via sigaction: Divide by zero!

*/

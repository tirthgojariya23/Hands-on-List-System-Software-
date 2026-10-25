/*
Name : 31b.c
Author : Tirth Gojariya (MT2026106)
Description : Write a separate program using the sigaction system call to
              catch the SIGINT signal (Ctrl+C interrupt).
Date : 25 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{
    printf("\nCaught SIGINT (signal %d) via sigaction!\n", signum);
    exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("SIGINT handler (sigaction) registered. Press Ctrl+C...\n");

    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/31$ gcc 31b.c -o 31b

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/31$ ./31b
SIGINT handler (sigaction) registered. Press Ctrl+C...
Running...
Running...
^C
Caught SIGINT (signal 2) via sigaction!

*/

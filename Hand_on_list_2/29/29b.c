/*
Name : 29b.c
Author : Tirth Gojariya (MT2026106)
Description : Write a separate program using the signal system call to catch
              the SIGINT signal (interrupt from keyboard, i.e., Ctrl+C).
Date : 24 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void int_handler(int sig)
{
    printf("\nCaught SIGINT (signal %d): Ctrl+C pressed!\n", sig);
    exit(0);
}

int main()
{
    signal(SIGINT, int_handler);

    printf("SIGINT handler registered. Press Ctrl+C to trigger...\n");

    while (1) {
        printf("Working...\n");
        sleep(1);
    }

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/29$ gcc 29b.c -o 29b

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/29$ ./29b
SIGINT handler registered. Press Ctrl+C to trigger...
Working...
Working...
^C
Caught SIGINT (signal 2): Ctrl+C pressed!

*/

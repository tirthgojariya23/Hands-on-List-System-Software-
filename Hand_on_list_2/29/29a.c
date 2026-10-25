/*
Name : 29a.c
Author : Tirth Gojariya (MT2026106)
Description : Write a separate program using the signal system call to catch
              the SIGSEGV signal (segmentation fault - invalid memory access).
Date : 24 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void segv_handler(int signum)
{
    printf("Caught SIGSEGV (signal %d): Invalid memory access!\n", signum);
    exit(1);
}

int main()
{
    signal(SIGSEGV, segv_handler);

    printf("Registered SIGSEGV handler. Triggering segfault...\n");

    int *p = NULL;
    *p = 100;   /* Dereference NULL pointer -> SIGSEGV */

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/29$ gcc 29a.c -o 29a

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/29$ ./29a
Registered SIGSEGV handler. Triggering segfault...
Caught SIGSEGV (signal 11): Invalid memory access!

*/

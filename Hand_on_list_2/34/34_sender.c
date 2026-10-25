/*
Name : 34_sender.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program (sender) that sends the SIGSTOP signal to
              a target process using the kill system call.
              Usage: ./34_sender <target_pid>
Date : 25 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t target;

    if (argc < 2) {
        printf("Usage: %s <target_pid>\n", argv[0]);
        return 1;
    }

    target = (pid_t)atoi(argv[1]);

    if (kill(target, SIGSTOP) == -1) {
        perror("kill SIGSTOP");
        exit(1);
    }

    printf("Sent SIGSTOP to PID %d. Process is now stopped.\n", target);
    printf("Resume it with: kill -CONT %d\n", target);

    return 0;
}

/*
Sample Output :

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/34$ ./34_sender 1240
Sent SIGSTOP to PID 1240. Process is now stopped.
Resume it with: kill -CONT 1240

*/

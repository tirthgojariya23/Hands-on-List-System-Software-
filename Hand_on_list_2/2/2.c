/*
Name : 2.c
Author : Tirth Gojariya (MT2026106)
Description : Write a simple program to send data from the parent process
              to the child process using a pipe.
Date : 20 October 2026
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    char read_msg[100];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        /* Child process: read from pipe */
        close(fd[1]);   /* Close unused write-end */
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received from parent: %s\n", read_msg);
        close(fd[0]);
    } else {
        /* Parent process: write to pipe */
        close(fd[0]);   /* Close unused read-end */
        char buff[] = "Hello from Parent!";
        write(fd[1], buff, sizeof(buff));
        close(fd[1]);
        wait(NULL);     /* Wait for child to finish */
    }

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ gcc 2.c -o 2

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ ./2
Child received from parent: Hello from Parent!

*/

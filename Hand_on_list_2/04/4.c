/*
Name : 4.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program to execute ls -l | wc using:
              (a) dup  (b) dup2  (c) fcntl
              Pass method name as command-line argument: dup, dup2, or fcntl.
Date : 20 October 2026
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd[2];

    if (argc < 2) {
        printf("Usage: %s <dup|dup2|fcntl>\n", argv[0]);
        return 1;
    }

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    if (strcmp(argv[1], "dup") == 0) {
        if (fork() == 0) {
            /* Child 1: ls -l, redirect stdout to pipe write-end via dup */
            close(fd[0]);
            close(1);        /* Close stdout */
            dup(fd[1]);      /* dup assigns lowest available fd = 1 */
            close(fd[1]);
            execlp("ls", "ls", "-l", NULL);
            exit(1);
        } else if (fork() == 0) {
            /* Child 2: wc, redirect stdin to pipe read-end via dup */
            close(fd[1]);
            close(0);        /* Close stdin */
            dup(fd[0]);      /* dup assigns lowest available fd = 0 */
            close(fd[0]);
            execlp("wc", "wc", NULL);
            exit(1);
        } else {
            close(fd[0]); close(fd[1]);
            wait(NULL); wait(NULL);
        }

    } else if (strcmp(argv[1], "dup2") == 0) {
        if (fork() == 0) {
            close(fd[0]);
            dup2(fd[1], 1);  /* Redirect stdout to pipe write-end */
            close(fd[1]);
            execlp("ls", "ls", "-l", NULL);
            exit(1);
        } else if (fork() == 0) {
            close(fd[1]);
            dup2(fd[0], 0);  /* Redirect stdin to pipe read-end */
            close(fd[0]);
            execlp("wc", "wc", NULL);
            exit(1);
        } else {
            close(fd[0]); close(fd[1]);
            wait(NULL); wait(NULL);
        }

    } else if (strcmp(argv[1], "fcntl") == 0) {
        if (fork() == 0) {
            close(fd[0]);
            close(1);
            fcntl(fd[1], F_DUPFD, 1); /* Duplicate fd[1] to fd >= 1; closes old 1 */
            close(fd[1]);
            execlp("ls", "ls", "-l", NULL);
            exit(1);
        } else if (fork() == 0) {
            close(fd[1]);
            close(0);
            fcntl(fd[0], F_DUPFD, 0); /* Duplicate fd[0] to fd >= 0 */
            close(fd[0]);
            execlp("wc", "wc", NULL);
            exit(1);
        } else {
            close(fd[0]); close(fd[1]);
            wait(NULL); wait(NULL);
        }

    } else {
        printf("Usage: %s <dup|dup2|fcntl>\n", argv[0]);
        return 1;
    }

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ gcc 4.c -o 4

# Run with dup
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ ./4 dup
      4      20     152

# Run with dup2
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ ./4 dup2
      4      20     152

# Run with fcntl
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ ./4 fcntl
      4      20     152

(Note: output values depend on the number of files in the current directory.)

*/

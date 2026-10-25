/*
Name : 7_reader.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program (reader side) to enable one-way communication
              through a FIFO named pipe. This program reads data from the FIFO.
              Run this before 7_writer.c.
Date : 21 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo_pipe"

int main()
{
    char buffer[100];
    int n;

    /* Create the FIFO if it does not exist */
    mkfifo(FIFO_NAME, 0666);

    printf("Reader: Waiting for data on %s ...\n", FIFO_NAME);

    /* Open FIFO for reading (blocks until writer opens) */
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("Reader: Received => %s\n", buffer);

    close(fd);
    unlink(FIFO_NAME);  /* Clean up FIFO */

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ gcc 7_reader.c -o 7_reader
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ gcc 7_writer.c -o 7_writer

# Run (open two terminals)
# Terminal 1 (reader first):
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ ./7_reader
Reader: Waiting for data on myfifo_pipe ...
Reader: Received => I am sending data through myfifo_pipe

# Terminal 2 (writer after reader):
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ ./7_writer

*/

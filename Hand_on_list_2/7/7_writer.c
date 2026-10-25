/*
Name : 7_writer.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program (writer side) to enable one-way communication
              through a FIFO named pipe. This program writes data into the FIFO.
              Run after 7_reader.c is already waiting.
Date : 23 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "myfifo_pipe"

int main()
{
    /* Open FIFO for writing (blocks until reader opens) */
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char message[] = "I am sending data through myfifo_pipe";
    write(fd, message, sizeof(message));

    printf("Writer: Message sent.\n");
    close(fd);

    return 0;
}

/*
Sample Output :

# Terminal 2 (after reader is running):
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ ./7_writer
Writer: Message sent.

*/

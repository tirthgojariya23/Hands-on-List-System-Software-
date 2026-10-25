/*
============================================================================
Name        : 17.c
Author      : Tirth Gojariya (MT2026106)
Description : Simple ticket reservation using write lock (fcntl).
Date        : 20 September 2026
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("tickets.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock fl = {0};
    fl.l_type = F_WRLCK;    // write lock
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;           // lock whole file

    // Try to acquire lock
    if (fcntl(fd, F_SETLKW, &fl) < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Lock acquired. Reserving ticket...\n");

    int tickets = 0;
    read(fd, &tickets, sizeof(int));
    tickets++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &tickets, sizeof(int));

    printf("Ticket reserved. Total tickets: %d\n", tickets);

    // Release lock
    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 17
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/17$ gcc 17.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/17$ ./a.out
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 1
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/17$ ./a.out
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 2

============================================================================
*/


/*
============================================================================
Name        : 12.c
Author      : Tirth Gojariya (MT2026106)
Description : Get the opening mode of a file using fcntl() (simple version).
Date        : 20 September 2026
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("mode.txt", O_RDWR | O_CREAT, 0644);
    int flags = fcntl(fd, F_GETFL);

    if ((flags & O_ACCMODE) == O_RDONLY) 
        printf("Read Only\n");
    else if ((flags & O_ACCMODE) == O_WRONLY) 
        printf("Write Only\n");
    else 
        printf("Read & Write\n");

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 12
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/12$ vim 12.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/12$ gcc 12.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/12$ ./a.out
Read & Write

============================================================================
*/


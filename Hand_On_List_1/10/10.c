/*
============================================================================
Name        : 10.c
Author      : Tirth Gojariya (MT2026106)
Description : Create a hole in a file using lseek().
Date        : 18 September 2026
============================================================================
*/

#include <unistd.h>   // for write(), lseek(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

int main() {
    int fd;
    
    // Open file for writing (create if it doesn't exist)
    fd = open("hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write some initial data
    write(fd, "Hello", 5);

    // Move file pointer 10 bytes ahead (creates a hole)
    lseek(fd, 10, SEEK_CUR);

    // Write more data after the hole
    write(fd, "World", 5);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 10
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/10$ vim 10.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/10$ gcc 10.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/10$ ./a.out
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/10$ ls -l hole.txt
-rwxrwxrwx 1 tirth tirth 18 Sep  2026 13:52 hole.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/10$ od -c hole.txt
0000000   H   e   l   l   o  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0   W
0000020   o   r   l   d
0000024
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/10$
============================================================================
*/


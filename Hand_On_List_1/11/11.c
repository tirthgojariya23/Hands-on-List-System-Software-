/*
============================================================================
Name        : 11.c
Author      : Tirth Gojariya (MT2026106)
Description : Duplicate file descriptor and append data to a file.
Date        : 20 September 2026
============================================================================
*/

#include <unistd.h>   // for write(), dup(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

int main() {
    int fd, fd_dup;

    // Open file in append mode (create if it doesn't exist)
    fd = open("append.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Duplicate the file descriptor
    fd_dup = dup(fd);
    if (fd_dup < 0) {
        perror("dup");
        close(fd);
        return 1;
    }

    // Write using original fd
    write(fd, "Line 1 using fd\n", 16);

    // Write using duplicated fd
    write(fd_dup, "Line 2 using fd_dup\n", 21);

    close(fd);
    close(fd_dup);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 11
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/11$ vim 11.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/11$ gcc 11.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/11$ ./a.out
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/11$ cat append.txt
Line 1 using fd
Line 2 using fd_dup

============================================================================
*/


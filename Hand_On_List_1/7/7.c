/*
============================================================================
Name        : 7.c
Author      : Tirth Gojariya (MT2026106)
Description : Copy contents of file1 to file2 using system calls only.
Date        : 18 September 2026
============================================================================
*/

#include <unistd.h>   // for read(), write(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

#define BUF_SIZE 1024

int main() {
    int fd1, fd2;
    char buffer[BUF_SIZE];
    ssize_t n;

    // Open source file (file1) for reading
    fd1 = open("f1.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("open file1");
        return 1;
    }

    // Open destination file (file2) for writing (create if not exists)
    fd2 = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open file3");
        close(fd1);
        return 1;
    }

    // Copy contents from file1 to file2
    while ((n = read(fd1, buffer, BUF_SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("write");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    if (n < 0) {
        perror("read");
    }

    // Close files
    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 7
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ echo "hiii this is the content of f1.txt" > file1.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ vim 7.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ gcc 7.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ ./a.out
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/7$ cat file2.txt
hiii this is the content of f1.txt
============================================================================
*/


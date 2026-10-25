/*
============================================================================
Name        : 8.c
Author      : Tirth Gojariya (MT2026106)
Description : Read a file line by line using system calls only (read-only).
Date        : 18 September 2026
============================================================================
*/

#include <unistd.h>   // for read(), write(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

#define BUF_SIZE 1    // read one character at a time

int main() {
    int fd;
    char c;

    // Open file in read-only mode
    fd = open("f1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open file1.txt");
        return 1;
    }

    // Read file character by character
    while (read(fd, &c, BUF_SIZE) > 0) {
        write(1, &c, 1);  // print character to stdout
    }

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ mkdir 8
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 8
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/8$ vim 8.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/8$ touch f1.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/8$ echo "hi this is f1 file" > f1.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/8$ gcc 8.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/8$ ./a.out
hi this is f1 file

============================================================================
*/


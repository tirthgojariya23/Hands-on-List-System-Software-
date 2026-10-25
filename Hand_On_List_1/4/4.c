/*
============================================================================
Name : 4.c
Author : Tirth Gojariya (MT2026106)
Description : Write a C, Ansi-style program to open an existing file in
              read-write mode. Also try to use O_EXCL flag.
Date: 18 September 2026
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Try to open existing file "myfile.txt" in read-write mode
    fd = open("myfile.txt", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("File opened successfully in read-write mode. FD: %d\n", fd);
    close(fd);

    // Now try opening with O_EXCL along with O_CREAT
    fd = open("myfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd < 0) {
        perror("open with O_EXCL");
    } else {
        printf("File opened with O_EXCL. FD: %d\n", fd);
        close(fd);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ mkdir 4
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 4
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ vim 4.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ gcc 4.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ touch myfile.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ ./a.out
File opened successfully in read-write mode. FD: 3
open with O_EXCL: File exists
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/4$ ls -l
total 20
-rwxrwxrwx 1 tirth tirth  1350 Sep  6 13:45 4.c
-rwxrwxrwx 1 tirth tirth 16088 Sep  6 13:45 a.out
-rw-r--r-- 1 tirth tirth     0 Sep  6 13:46 myfile.txt

============================================================================
*/


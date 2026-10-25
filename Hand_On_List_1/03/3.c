/*
============================================================================
Name : 3.c
Author : Tirth Gojariya (MT2026106)
Description : Write a C, Ansi-style program to create a file using creat()
              system call and print its file descriptor.
Date: 18 September 2026
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // create file with rw-r--r-- permissions
    fd = creat("myfile.txt", 0644);

    if (fd < 0) {
        perror("creat");
        return 1;
    }

    printf("File created successfully. File Descriptor: %d\n", fd);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ cd ..
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ mkdir 3
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 3
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/3$ vim 3.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/3$ gcc 3.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/3$ ./a.out
File created successfully. File Descriptor: 3
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/3$ ls -l
total 20
-rwxrwxrwx 1 tirth tirth  1212 Sep  6 13:22 3.c
-rwxrwxrwx 1 tirth tirth 16088 Sep  6 13:22 a.out
-rwxrwxrwx 1 tirth tirth     0 Sep  6 13:23 myfile.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/3$
============================================================================
*/


/*
=====================================================================
Name        : 5.c
Author      : Tirth Gojariya (MT2026106)
Description : Write a C, ANSI-style program to create five new files
              with an infinite loop. Execute the program in the
              background and check the file descriptor table at
              /proc/pid/fd.

Date        : 17 September 2026
=====================================================================
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[5];
    int count = 0;
    char filename[50];

    while (1) {
        for (int i = 0; i < 5; i++) {

            sprintf(filename, "file_%d_%d.txt", count, i);

            fd[i] = open(filename, O_CREAT | O_RDWR, 0644);

            if (fd[i] < 0) {
                perror("open");
                return 1;
            }

            printf("Created %s with FD: %d\n", filename, fd[i]);
        }

        count++;
        sleep(5);
    }

    return 0;
}


/*
=====================================================================
Sample Output :
---------------------------------------------------------------------

# Compile the program

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/5$ gcc 5.c


# Run as background process

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/5$ ./a.out &

[1] 721

Created file_0_0.txt with FD: 3
Created file_0_1.txt with FD: 4
Created file_0_2.txt with FD: 5
Created file_0_3.txt with FD: 6
Created file_0_4.txt with FD: 7

Created file_1_0.txt with FD: 8
Created file_1_1.txt with FD: 9
Created file_1_2.txt with FD: 10
Created file_1_3.txt with FD: 11
Created file_1_4.txt with FD: 12


# Check the process ID

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/5$ echo $!

721


# Check the file descriptor table

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/5$ls -l /proc/721/fd

total 0

lrwx------ 1 tirth tirth 64 Sep 17 14:10 0 ->/dev/pts/0

lrwx------ 1 tirth tirth 64 Sep 17 14:10 1 ->/dev/pts/0

lrwx------ 1 tirth tirth 64 Sep 17 14:10 2 ->/dev/pts/0

lrwx------ 1 tirth tirth 64 Sep 17 14:10 3 ->/home/tirth/Desktop/Hand_On_List/5/file_0_0.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 4 ->/home/tirth/Desktop/Hand_On_List/5/file_0_1.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 5 ->/home/tirth/Desktop/Hand_On_List/5/file_0_2.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 6 ->/home/tirth/Desktop/Hand_On_List/5/file_0_3.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 7 ->/home/tirth/Desktop/Hand_On_List/5/file_0_4.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 8 ->/home/tirth/Desktop/Hand_On_List/5/file_1_0.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 9 ->/home/tirth/Desktop/Hand_On_List/5/file_1_1.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 10 ->/home/tirth/Desktop/Hand_On_List/5/file_1_2.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 11 ->/home/tirth/Desktop/Hand_On_List/5/file_1_3.txt

lrwx------ 1 tirth tirth 64 Sep 17 14:10 12 ->/home/tirth/Desktop/Hand_On_List/5/file_1_4.txt


# Stop the background process

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/5$
kill 721

[1]+  Terminated              ./a.out

---------------------------------------------------------------------
=====================================================================
*/

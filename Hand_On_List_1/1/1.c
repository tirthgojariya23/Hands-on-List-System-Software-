/*
============================================================================
Name : 1.c
Author : Tirth Gojariya (MT2026106)
Description : Write a C, Ansi-style program to create 
              a. Soft link 
              b. Hard link 
              c. FIFO
Date : 18 September 2026
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>

int main() {
    symlink("f1.txt", "softlink_f1");   // create soft link
    link("f1.txt", "hardlink_f1");      // create hard link
    mkfifo("myfifo", 0666);             // create FIFO
    return 0;
}

/*
============================================================================
Sample Output :
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ mkdir 1
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 1
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ vim 1.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ touch f1.txt
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ gcc 1.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ ./a.out
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ ls -l
total 20
-rwxrwxrwx 1 tirth tirth  1396 Sep  18 13:10 1.c
-rwxrwxrwx 1 tirth tirth 16024 Sep  18 13:10 a.out
-rwxrwxrwx 2 tirth tirth     0 Sep  18 13:10 f1.txt
-rwxrwxrwx 2 tirth tirth     0 Sep  18 13:10 hardlink_f1
lrwxrwxrwx 1 tirth tirth     6 Sep  18 13:11 softlink_f1 -> f1.txt

# Equivalent Linux commands:
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ ln -s f1.txt softlink_f1
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ ln f1.txt hardlink_f1
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/1$ mkfifo myfifo

----------------------------------------------------------------------------

============================================================================
*/



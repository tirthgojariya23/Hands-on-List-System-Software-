/*
============================================================================
Name        : 6.c
Author      : Tirth Gojariya (MT2026106)
Description : Echo program using read() and write() system calls only.
              Keeps echoing multiple lines until Ctrl+D (EOF) is pressed.
Date        : 18 September 2026
============================================================================
*/

#include <unistd.h>  // for read() and write()

int main() {
    char c;

    // Keep reading characters until EOF (Ctrl+D)
    while (read(0, &c, 1) > 0) {
        write(1, &c, 1);  // write each character immediately
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/5$ cd ..
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 6
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ vim 6.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ gcc 6.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ ./a.out
hello jabalpur
hello jabalpur
hello 2nd time
hello 2nd time

============================================================================
*/


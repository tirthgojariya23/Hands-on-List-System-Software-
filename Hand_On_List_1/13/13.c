/*
============================================================================
Name        : 13.c
Author      : Tirth Gojariya (MT2026106)
Description : Wait up to 10 seconds for input from STDIN using select().
Date        : 20 September 2026
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;
    char buffer[100];

    // Initialize fd set
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Set timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("You have 10 seconds to type something:\n");

    // Wait for input
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("No input after 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            read(STDIN_FILENO, buffer, sizeof(buffer));
            printf("You typed: %s", buffer);
        }
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 13
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ vim 13.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ gcc 13.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ ./a.out
You have 10 seconds to type something:
hii jabalpurr
You typed: hii jabalpur

============================================================================
*/


/*
============================================================================
Name        : 26.c
Author      : Tirth Gojariya (MT2026106)
Description : Execute an external executable with arguments using execlp().
Date        : 21 September 2026
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Parent PID = %d: Executing ls -l /tmp\n", getpid());

    // Execute "ls -l /tmp"
    execlp("ls", "ls", "-l", "/tmp", NULL);

    // If execlp returns, it must have failed
    perror("execlp");
    return 1;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 26
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/26$ vim 26.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/26$ gcc 26.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/26$ ./a.out
Parent PID = 1100: Executing ls -l /tmp
total 24
drwx------ 2 root  root  4096 Sep  6 13:07 snap-private-tmp
drwx------ 3 root  root  4096 Sep  6 13:07 systemd-private-ab726222b48b41829f122dacb04f4063-systemd-logind.service-sjxtZo
drwx------ 3 root  root  4096 Sep  6 13:07 systemd-private-ab726222b48b41829f122dacb04f4063-systemd-resolved.service-kTsnWM
drwx------ 3 root  root  4096 Sep  6 13:07 systemd-private-ab726222b48b41829f122dacb04f4063-systemd-timesyncd.service-Wspj7w
drwx------ 3 root  root  4096 Sep  6 13:07 systemd-private-ab726222b48b41829f122dacb04f4063-wsl-pro.service-9nVfB3
drwx------ 2 tirth tirth 4096 Sep  6 14:47 tmux-1000
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/26$
============================================================================
*/


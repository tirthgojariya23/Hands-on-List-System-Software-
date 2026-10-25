/*
============================================================================
Name        : 20.c
Author      : Tirth Gojariya (MT2026106)
Description : Get and modify process priority using nice().
Date        : 20 September 2026
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();

    // Get current nice value
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority of process %d: %d\n", pid, priority);

    // Increase nice value by 5 (lower priority)
    if (nice(5) == -1) perror("nice");

    // Get new priority
    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of process %d: %d\n", pid, priority);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/20$ vim 20.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/20$ gcc 20.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/20$ ./a.out
Current priority of process 920: 0
New priority of process 920: 5
============================================================================
*/


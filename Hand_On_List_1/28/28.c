/*
============================================================================
Name        : 28.c
Author      : Tirth Gojariya (MT2026106)
Description : Get min and max real-time priority for SCHED_FIFO and SCHED_RR.
Date        : 21 September 2026
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int min_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_fifo = sched_get_priority_max(SCHED_FIFO);

    int min_rr = sched_get_priority_min(SCHED_RR);
    int max_rr = sched_get_priority_max(SCHED_RR);

    printf("SCHED_FIFO: min priority = %d, max priority = %d\n", min_fifo, max_fifo);
    printf("SCHED_RR  : min priority = %d, max priority = %d\n", min_rr, max_rr);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ mkdir 28
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List$ cd 28
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/28$ vim 28.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/28$ gcc 28.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/28$ ./a.out
SCHED_FIFO: min priority = 1, max priority = 99
SCHED_RR  : min priority = 1, max priority = 99
============================================================================
*/


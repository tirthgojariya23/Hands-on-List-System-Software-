/*
============================================================================
Name : 2.c
Author : Tirth Gojariya (MT2026106)
Description : Write a C, Ansi-style program to create an 
              infinite background process and inspect it using /proc.
Date : 18 September 2026
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {
        printf("Running process with PID: %d\n", getpid());
        sleep(8);   // sleep to avoid flooding the terminal
    }
    return 0;
}

/*
============================================================================
Sample Output :
----------------------------------------------------------------------------

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ gcc 2.c

# Run as background process
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ ./a.out &
[1] 587

# Inspect process details from /proc
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ cat /proc/587/status
Name:   a.out
State:  S (sleeping)
Pid:    587
PPid:   632
...

# Check command line
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ cat /proc/587/cmdline
./a.out

# Kill the background process
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/2$ kill 587

----------------------------------------------------------------------------

============================================================================
*/


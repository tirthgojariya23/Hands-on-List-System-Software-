/*
Name : 6.c
Author : Tirth Gojariya (MT2026106)
Description : Create a FIFO (named pipe) file using:
              (a) mknod command   -- shown in sample output (shell command)
              (b) mkfifo command  -- shown in sample output (shell command)
              (c) strace command  -- shown in sample output (comparison)
              (d) mknod system call
              (e) mkfifo library function
              This program demonstrates (d) and (e) in C.
Date : 20 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    const char *mknod_fifo = "fifo_mknod";
    const char *mkfifo_fifo = "fifo_mkfifo";

    /* (d) Create FIFO using mknod system call */
    if (mknod(mknod_fifo, S_IFIFO | 0666, 0) == -1) {
        perror("mknod (already exists or error)");
    } else {
        printf("FIFO created using mknod syscall: %s\n", mknod_fifo);
    }

    /* (e) Create FIFO using mkfifo library function */
    if (mkfifo(mkfifo_fifo, 0666) == -1) {
        perror("mkfifo (already exists or error)");
    } else {
        printf("FIFO created using mkfifo function: %s\n", mkfifo_fifo);
    }

    /* Verify creation */
    printf("Run 'ls -l' to see the 'p' (pipe) file type for both FIFOs.\n");

    /* Clean up */
    unlink(mknod_fifo);
    unlink(mkfifo_fifo);

    return 0;
}

/*
Sample Output :

# --- (a) Create FIFO using mknod command ---
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ mknod fifo_cmd p
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ ls -l fifo_cmd
prw-r--r-- 1 tirth tirth 0 Oct 20 2026 fifo_cmd

# --- (b) Create FIFO using mkfifo command ---
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ mkfifo fifo_mkfifo_cmd
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ ls -l fifo_mkfifo_cmd
prw-r--r-- 1 tirth tirth 0 Oct 20 2026 fifo_mkfifo_cmd

# --- (c) strace comparison ---
# strace mknod fifo_strace p  =>  calls mknod(2) directly
# strace mkfifo fifo_strace2  =>  also internally calls mknod(2)
# mkfifo is just a user-friendly wrapper around the mknod system call.
# mkfifo is preferred because it is more readable and its purpose is explicit.

# --- (d) and (e) via C program ---
# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ gcc 6.c -o 6

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/6$ ./6
FIFO created using mknod syscall: fifo_mknod
FIFO created using mkfifo function: fifo_mkfifo

*/

/*
============================================================================
Name        : 30.c
Author      : Tirth Gojariya (MT2026106)
Description : Daemon program that runs a script at a specific HH:MM time.
Date        : 21 September 2026
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <HH> <MM>\n", argv[0]);
        exit(1);
    }

    int target_hour = atoi(argv[1]);
    int target_min = atoi(argv[2]);

    // Fork and exit parent
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid > 0) {
        printf("Daemon started with PID %d\n", pid);
        exit(0);
    }

    // Create new session and daemonize
    setsid();
    chdir("/");
    umask(0);

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min) {
            system("/path/to/your/script.sh");  // <-- Replace with your script path
            sleep(60);  // wait 1 min so it doesnâ€™t run multiple times
        }

        sleep(10);  // check every 10s
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/30$ vim 30.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/30$ gcc.c
gcc.c: command not found
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/30$ gcc 30.c
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/30$ ./a.out
Usage: ./a.out <HH> <MM>
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/30$ ./a.out 21 14
Daemon started with PID 1245
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/30$
============================================================================
*/


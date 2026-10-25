/*
Name : 19a.c
Author : Tirth Gojariya (MT2026106)
Description : Rewrite the ticket number creation program using a semaphore.
              Multiple processes try to read and increment a ticket number stored
              in a shared file. A binary semaphore protects the critical section.
              Run 19a_db.c first to initialize the database file.
Date : 22 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

#ifndef __APPLE__
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

/* Semaphore P (wait / lock) */
void sem_p(int semid)
{
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

/* Semaphore V (signal / unlock) */
void sem_v(int semid)
{
    struct sembuf op = {0, +1, 0};
    semop(semid, &op, 1);
}

int main()
{
    key_t key  = ftok("database", 65);
    int semid  = semget(key, 1, 0666 | IPC_CREAT);

    union semun arg;
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    int i;
    for (i = 0; i < 3; i++) {
        if (fork() == 0) {
            /* Child: enter critical section */
            sem_p(semid);

            struct { int ticket_no; } db;
            int fd = open("database", O_RDWR);
            read(fd, &db, sizeof(db));
            db.ticket_no++;
            printf("Process %d: Ticket number = %d\n", getpid(), db.ticket_no);
            lseek(fd, 0, SEEK_SET);
            write(fd, &db, sizeof(db));
            close(fd);

            sem_v(semid);
            exit(0);
        }
    }

    /* Wait for all children */
    for (i = 0; i < 3; i++) wait(NULL);

    semctl(semid, 0, IPC_RMID);
    printf("All processes done. Semaphore removed.\n");

    return 0;
}

/*
Sample Output :

# Step 1: Initialize database file
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/19$ gcc 19a_db.c -o 19a_db
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/19$ ./19a_db
Database initialized with ticket number = 0

# Step 2: Run ticket program
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/19$ gcc 19a.c -o 19a
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/19$ ./19a
Process 1237: Ticket number = 1
Process 1238: Ticket number = 2
Process 1239: Ticket number = 3
All processes done. Semaphore removed.

(Process order may vary, but ticket numbers are sequential due to the semaphore.)

*/

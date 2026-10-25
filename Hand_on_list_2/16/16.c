/*
Name : 16.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program to remove the message queue using msgctl
              with the IPC_RMID command.
Date : 22 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main()
{
    key_t key;
    int msgid;

    key   = ftok("progfile", 65);
    if (key == -1) { perror("ftok"); exit(1); }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) { perror("msgget"); exit(1); }

    printf("Message queue ID before removal: %d\n", msgid);

    /* Remove the message queue */
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/16$ gcc 16.c -o 16
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/16$ touch progfile

# Send a message first (optional):
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/16$ ./16_sender
Message sent: Hello from sender!

# Check queue:
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/16$ ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x410f51a4 65536      tirth               666        100          1

# Remove queue:
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/16$ ./16
Message queue ID before removal: 65536
Message queue removed successfully.

# Verify removal:
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/16$ ipcs -q
------ Message Queues --------
(empty — queue has been removed)

*/

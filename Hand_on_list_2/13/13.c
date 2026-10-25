/*
Name : 13.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program to send messages to the message queue.
              After sending, verify using the shell command: ipcs -q
Date : 21 October 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    struct msg_buffer message;

    key   = ftok("progfile", 65);
    if (key == -1) { perror("ftok"); exit(1); }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) { perror("msgget"); exit(1); }

    message.msg_type = 1;
    strcpy(message.msg_text, "Hello from sender!");

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent: %s\n", message.msg_text);
    printf("Use 'ipcs -q' to verify the message queue.\n");

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ gcc 13.c -o 13
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ touch progfile

# Run
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ ./13
Message sent: Hello from sender!
Use 'ipcs -q' to verify the message queue.

# Verify
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x410f51a4 65536      tirth               666        100          1

# Remove queue after use
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/13$ ipcrm -q 65536

*/

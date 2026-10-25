/*
Name : 14a.c
Author : Tirth Gojariya (MT2026106)
Description : Write a program to receive messages from the message queue
              with 0 as a flag (blocking receive).
              Run 14_sender.c first to put a message in the queue.
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
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) { perror("msgget"); exit(1); }

    printf("Waiting for message (blocking, flag = 0)...\n");

    /* flag = 0 : block until a message of type 1 is available */
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Message received (flag=0): %s\n", message.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

/*
Sample Output :

# Compile
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/14$ gcc 14a.c -o 14a
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/14$ gcc 14b.c -o 14b
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/14$ gcc 14_sender.c -o 14_sender
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/14$ touch progfile

# Send a message first
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/14$ ./14_sender
Message sent: Hello from sender!

# Receive with flag=0 (blocking)
tirth@tirth-IdeaPad:~/Desktop/Hand_On_List/14$ ./14a
Waiting for message (blocking, flag = 0)...
Message received (flag=0): Hello from sender!

*/

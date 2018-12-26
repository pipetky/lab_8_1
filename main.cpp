#include <iostream>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include "string.h"

using namespace std;

int main() {
    char* msg_send = "Hello World!";

    struct timespec wait = {10, 10};
    unsigned int prio = 1;

    mqd_t q = mq_open("test", O_RDWR);
    ssize_t msg_rec = mq_timedreceive(q, msg_send,
            strlen(msg_send), &prio,
    &wait);

    return 0;
}
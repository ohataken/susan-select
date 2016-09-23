#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {

    struct timeval timeval;
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    timeval.tv_sec = 5;
    timeval.tv_usec = 0;

    while (1) {
        select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeval);
        timeval.tv_sec = 5;
        timeval.tv_usec = 0;

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            char buffer[16];
            read(STDIN_FILENO, buffer, 16);
            printf("%s\n", buffer);
        } else {
            FD_SET(STDIN_FILENO, &readfds);
        }
    }

    return 0;
}

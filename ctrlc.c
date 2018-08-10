```
// A C program that does not terminate when Ctrl+C is pressed
#include <stdio.h>
#include <signal.h>

// Signal Handler for SIGINT
void sigintHandler(int sig_num) {
    // Reset handler to catch SIGINT next time (http://en.cppreference.com/w/c/program/signal)
    signal(SIGINT, sigintHandler);
    printf("\n Cannot be terminated using Ctrl+C \n");
    fflush(stdout);
}

int main () {
    signal(SIGINT, sigintHandler);
    while(1) {          // while true loop
        ...
    }
    return 0;
}
```

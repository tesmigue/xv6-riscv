#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void sleeper() {
    printf("Proceso durmiendo por 50 ticks...\n");
    sleep(50);
    printf("Proceso despertó.\n");
    exit(0);
}

int main() {
    if (fork() == 0) {
        sleeper();
    } else {
        wait(0);
    }
    exit(0);
}

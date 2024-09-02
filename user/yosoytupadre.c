#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    int ppid = getppid();
    printf("El ID de mi padre es: %d\n", ppid);

    int my_pid = getpid();
    printf("Mi PID: %d\n", my_pid);

    int grandparent_pid = getancestor(2);
    if (grandparent_pid != -1) {
        printf("El ID de mi abuelo es: %d\n", grandparent_pid);
    } else {
        printf("No hay un abuelo disponible (ancestro en nivel 2).\n");
    }

    exit(0);
}

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    int ppid = getppid();  // Llama a la función getppid que implementaste
    printf("El ID de mi padre es: %d\n", ppid);
    exit(0);
}

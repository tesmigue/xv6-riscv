#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    for (int i = 1; i <= 20; i++) {
        int pid = fork();
        if (pid < 0) {
            printf("Error: no se pudo crear el proceso %d\n", i);
            exit(1);
        }
        if (pid == 0) {
            // Proceso hijo: imprime y duerme un momento
            printf("Ejecutando proceso %d\n", i);
            exit(0);   // Salida del proceso hijo
        } else {
            // Espera a que el hijo termine antes de crear el siguiente proceso
            wait(0);
        }
    }

    printf("Todos los procesos hijos han terminado.\n");
    exit(0);
}

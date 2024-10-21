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
            // Proceso hijo
            printf("Ejecutando proceso %d\n", i);
            sleep(1);
            exit(0); // Salida del proceso hijo
            
        }
        // Espera en el proceso padre a que el hijo termine
        wait(0);
        
    }

    printf("Todos los procesos hijos han terminado.\n");
    exit(0);
}

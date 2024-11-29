#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

int main() {
    char *filename = "testfile";
    int fd;

    // Crear archivo
    fd = open(filename, O_CREATE | O_RDWR);
    write(fd, "Hola", 4);
    close(fd);

    // Cambiar permisos a solo lectura
    chmod(filename, 1);

    // Intentar escribir
    if (open(filename, O_WRONLY) < 0) {
        printf("Test passed: Escritura bloqueada en archivo de solo lectura\n");
    }

    // Restaurar permisos
    chmod(filename, 3);
    fd = open(filename, O_RDWR);
    write(fd, " Mundo", 6);
    close(fd);

    // Cambiar permisos a inmutable
    chmod(filename, 5);

    // Intentar escribir
    if (open(filename, O_WRONLY) < 0) {
        printf("Test passed: Escritura bloqueada en archivo inmutable\n");
    }

    // Intentar cambiar permisos
    if (chmod(filename, 3) < 0) {
        printf("Test passed: Cambio de permisos bloqueado en archivo inmutable\n");
    }

    exit(0);
}

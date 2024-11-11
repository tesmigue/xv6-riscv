#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    // Paso 1: Reserva una página de memoria
    char *addr = sbrk(4096);  // Reserva 4096 bytes (una página)
    if (addr == (char *)-1) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    printf("Dirección de la página reservada: %p\n", addr);

    // Paso 2: Protege la página usando mprotect
    if (mprotect(addr, 1) == -1) {
        printf("Error: mprotect falló\n");
        exit(1);
    } else {
        printf("mprotect exitoso: La página ahora es de solo lectura\n");
    }


    //comentar esto para probar el programa no provoque una  falla
    // Paso 3: Intenta escribir en la página protegida (debería fallar)
    printf("Intentando escribir en la página protegida...\n");
    *addr = 'X';  // Esto debería provocar un fallo de protección de memoria

    // Si el programa llega aquí, la protección no funcionó como se esperaba
    printf("Error: Escritura en memoria protegida NO falló como se esperaba\n");

    // Paso 4: Desproteger la página usando munprotect
    if (munprotect(addr, 1) == -1) {
        printf("Error: munprotect falló\n");
        exit(1);
    } else {
        printf("munprotect exitoso: La página ahora es de lectura/escritura\n");
    }

    // Paso 5: Intentar escribir en la página desprotegida (debería funcionar)
    printf("Intentando escribir en la página desprotegida...\n");
    *addr = 'Y';  // Esto debería ser exitoso si munprotect funcionó
    printf("Escritura en la página desprotegida exitosa, valor en la dirección: %c\n", *addr);

    // Finalizacion el programa
    printf("Prueba de mprotect y munprotect completada.\n");
    exit(0);
}

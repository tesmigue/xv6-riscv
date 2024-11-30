#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(void)
{
  int fd = open("testfile", O_CREATE | O_RDWR);
  if(fd < 0){
    printf("Error: No se pudo crear el archivo\n");
    exit(1);
  }
  write(fd, "Hola, Mundo!", 13);
  close(fd);

  if(chmod("testfile", 1) < 0){
    printf("Error: No se pudo cambiar los permisos del archivo\n");
    exit(1);
  }

  fd = open("testfile", O_WRONLY);
  if(fd >= 0){
    printf("Error: No se debería haber podido abrir el archivo en modo escritura\n");
    exit(1);
  }

  chmod("testfile", 3); // Restore write permission
  fd = open("testfile", O_RDWR);
  if(fd < 0){
    printf("Error: No se pudo abrir el archivo con permisos restaurados\n");
    exit(1);
  }
  write(fd, "Modificado", 8);
  close(fd);

  chmod("testfile", 5); // Set immutable
  if(chmod("testfile", 3) >= 0){
    printf("Error: No se debería haber podido cambiar los permisos de un archivo inmutable\n");
    exit(1);
  }

  printf("Todas las pruebas pasaron correctamente\n");
  exit(0);
}

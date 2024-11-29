#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(void)
{
  int fd = open("testfile", O_CREATE | O_RDWR);
  if(fd < 0){
    printf("Failed to create file\n");
    exit(1);
  }
  write(fd, "Hello, World!", 13);
  close(fd);

  if(chmod("testfile", 1) < 0){
    printf("Failed to change permissions\n");
    exit(1);
  }

  fd = open("testfile", O_WRONLY);
  if(fd >= 0){
    printf("Should not have been able to open file for writing\n");
    exit(1);
  }

  chmod("testfile", 3); // Restore write permission
  fd = open("testfile", O_RDWR);
  if(fd < 0){
    printf("Failed to open file with restored permissions\n");
    exit(1);
  }
  write(fd, "Modified", 8);
  close(fd);

  chmod("testfile", 5); // Set immutable
  if(chmod("testfile", 3) >= 0){
    printf("Should not have been able to change immutable file\n");
    exit(1);
  }

  printf("All tests passed\n");
  exit(0);
}

// init: The initial user-level program

#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/spinlock.h"
#include "kernel/sleeplock.h"
#include "kernel/fs.h"
#include "kernel/file.h"
#include "user/user.h"
#include "kernel/fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  // Intenta abrir la consola; si no existe, créala.
  if(open("console", O_RDWR) < 0){
    mknod("console", CONSOLE, 0);
    open("console", O_RDWR);
  }

  // Duplica la consola para stdout y stderr.
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf("init: starting sh\n");
    pid = fork();
    if(pid < 0){
      printf("init: fork failed\n");
      exit(1);
    }
    if(pid == 0){
      exec("sh", argv);
      printf("init: exec sh failed\n");
      exit(1);
    }

    for(;;){
      // Este wait() regresa si el shell termina,
      // o si un proceso sin padre termina.
      wpid = wait((int *) 0);
      if(wpid == pid){
        // Si el shell salió, reinícialo.
        break;
      } else if(wpid < 0){
        printf("init: wait returned an error\n");
        exit(1);
      }
    }
  }
}
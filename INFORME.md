# INFORME DE TAREA 1

## Funcionamiento de las llamadas de sistema
1. getppid(): la llamada getppid() se encarga de devolver el process ID o PID del proceso padre del proceso que la invoca. es util para que los procesos puedan identifcar su origen en la jerarquía de los procesos del sistema. getppid() se implementa en sysproc.c y la funcion accede el proceso mediante myproc() y retorna el PID de su padre, o 0 si no tiene padre
2. getancestor(int n): la llamada al sistema getancestor(int n) devuelve el PID del ancestro del proceso según el cual esta especificado por n. Es decir, getancesto(0) retorna el proceso actual, getancestor(1) retorna el pID del padre y getancestor(2) retorna el PID del abuelo, si no existe un ancestro en ese nivel indicado, retorna -1
## Explicacion de las modificaciones 
- sysproc.c: implementacion de las funciones sys_getppid() y sys_getancestor()
- syscall.h: Se añaden las llamadas al sistema de sys_getppid() y sys_getancestor
- syscall.c: mapea ambas funciones en la tabla de llamadas al sistema
- user.h: se declaran las funciones getppid() y getancestor(int) para que esten disponibles en el espacio del usuario
- users.pl: se añaden entradas para agregar interfaces de usuarios
- yosoytupadre.c: se creo el programa en la carpeta user/ que invoca las funciones para verificar su funcionamiento
- Makeefile: se agrego el programa yosoytupadre a UPROGS para que compile junto al sistema
## Dificultades encontradas y como se resolvieron
- En un principio, tuve un error con sys_getancestor() ya que no habia especificado el tipo de retorno adecuado por lo que el compilador solto un error de "return type defaults to "int"", despues lo resolvi especificando el tipo de retorno uint64.
- argint: tuve un error con el manejo del valor de argint en sys_getancestor() , realice una comparacion incorrecta con su valor de retorno, pero despues lo corregi verificando adecuadamente el valor devuelvo por argint.
- Git: tuve que cambiar las ramas con un git pull --rebase que no me detectaba la rama correcta, despues de ingresar git pull --rebase pude realizar el git push correspondiente.

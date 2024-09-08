# INFORME DE INSTALACIÓN DE xv6

## Pasos Seguidos para la Instalación
1.Tras buscar multiples repositorios, desde tutoriales https://github.com/johnwinans/riscv-toolchain-install-guide?tab=readme-ov-file para instalar riscv-Toolchain, https://oslab.kaist.ac.kr/xv6-tools/?ckattempt=1 o https://github.com/mit-pdos/xv6-riscv.git
me fui por el segundo link
2. Tras eso instale xv6-public y segui los pasos del link, instalando qemu con $ sudo apt-get install git make gcc wget qemu qemu-kvm gdb -y luego clonando el repositorio https://github.com/mit-pdos/xv6-public.git
3. Despues de eso compile y ejecute xv6 con maek qemu-nox.
4. Luego, lo reinicie y añadi una configuracion a "~/.gdbinit".
5. compile con make qemu-nox-gdb para que el sistema reconozca el cambio.
6. Por último abri una nueva instancia de ubuntu y compilé qemu con gdb ./kernel y xv6 sé instalo y compiló correctamente.

## Problemas Encontrados y Soluciones
- **Problema:** Error al compilar debido a la falta de toolchain RISC-V en el tercer link mencionado en el paso 1 .
  **Solución:** Instalar la toolchain usando `sudo apt-get install gcc-riscv64-unknown-elf`, no funcionó la solucion. Añadi configuraciones al Makefile y al Path pero el sistema todavía no reconocía el toolchain,
  por lo que termine optando por el segundo repositorio.

Actualización(08/09/2024)
- **Problema**: resulta que tras hablar con un compañero, me comentó que la version de xv8-public era la incorrecta a utilizar en todo el semestre
- **Solución**: Borré todo el ubuntu que tenía y lo instalé nuevamente. Primero instalé todas las dependencias necesarias con sudo apt install -y autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev, luego realicé el git clone del riscv-gnu.toolchain y configure el path para que se detecte e toolchain en todo el sistema. Realicé un sudo make y se ingreso todo al directorio principal. Luego instale qemu y una version especifica riscv64. Cloné el xv6-riscv, compilé y ejecute con make qemu, y funcionó:

sudo apt install -y autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
git clone https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv
sudo make
echo 'export PATH=/opt/riscv/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
sudo apt install -y qemu qemu-system-misc
qemu-system-riscv64 --version
git clone https://github.com/mit-pdos/xv6-riscv.git
cd xv6-riscv
make qemu

## Confirmación de Funcionamiento
- Ejecución de comandos básicos en xv6 como `ls`, `echo`, y `cat README` confirman que el sistema está funcionando correctamente.
- 
![cat_readme](https://github.com/user-attachments/assets/643b0fe8-7687-4c9b-8335-c8ca04ff3cb8)
![ls_echoholaqemu](https://github.com/user-attachments/assets/a4d440d4-f3da-466e-b35d-49bd85f884ed)
![image](https://github.com/user-attachments/assets/b8ce6c39-3c85-4e3f-ad2b-90339ac4304c)

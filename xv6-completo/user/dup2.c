#include "types.h"
#include "user.h"
#include "fcntl.h"

int 
main(int argc, char *argv[])
{
  int fd;

  // 1. Crear o abrir un archivo de texto con permisos de escritura
  fd = open("output.txt", O_CREATE | O_WRONLY);
  if(fd < 0){
    printf(2, "Error al abrir el archivo\n");
    exit(0);
  }

  // 2. Redirigir la salida estándar (1) hacia el descriptor de nuestro archivo (fd)
  if(dup2(fd, 1) < 0) {
    printf(2, "Error en dup2\n");
    exit(0);
  }

  // 3. Cerramos el descriptor original redundante
  close(fd);

  // 4. Estos mensajes ya no saldrán en la consola, se guardarán en "output.txt"
  printf(1, "Hola desde xv6 usando dup2!\n");
  printf(1, "Esta linea tambien se ha redirigido correctamente al archivo.\n");

  exit(0);
}

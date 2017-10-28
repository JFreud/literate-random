#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


unsigned int genRan() {

  int fd = open("/dev/random", O_RDONLY);

  if (fd < 0) {
    printf("File didn't open");
  }

  unsigned int * buffer = malloc(sizeof(unsigned int));

  read(fd, buffer, sizeof(buffer));

  return *buffer;
}





int main() {

  printf("Generating random numbers:\n");

  unsigned int randarr[10];

  int i;
  for (i = 0; i < 10; i++){
    randarr[i] = genRan();
  }

  int j;
  for (j = 0; j < 10; j++) {
    printf("random %d: %u\n", j, randarr[j]);
  }




  return 0;
}

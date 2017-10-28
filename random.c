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
  int j;
  for (j = 0; j < 10; j++) {
    printf("random %d: %u\n", j, genRan());
  }




  return 0;
}

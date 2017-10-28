#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


unsigned int genRan() {//generate random unsigned int from /dev/random

  int fd = open("/dev/random", O_RDONLY);

  if (fd < 0) {
    printf("File didn't open");
  }

  unsigned int * buffer = malloc(sizeof(unsigned int));

  read(fd, buffer, sizeof(buffer));

  unsigned int val = *buffer;

  free(buffer);

  return val;
}




int main() {

  printf("\nGenerating random numbers:\n");

  unsigned int randarr[10];//create array

  int i;
  for (i = 0; i < 10; i++){
    randarr[i] = genRan();//populate array
  }


  for (i = 0; i < 10; i++) {
    printf("random %d: %u\n", i, randarr[i]);//print array
  }

  //write array to file:

  printf("\nWriting numbers to file...\n");

  int fd_write = open("random_nums", O_CREAT, 0644);//create file to write to

  write(fd_write, randarr, sizeof(randarr));

  close(fd_write);

  //read file to array:

  printf("\nReading numbers from file...\n\n");

  int fd_read = open("random_nums", O_RDONLY);//open file that was written

  unsigned int randarr_check[10];

  read(fd_read, randarr_check, sizeof(randarr_check));//read to new array


  for (i = 0; i < 10; i++){
    printf("random %d: %u\n", i, randarr_check[i]);//print array
  }

  return 0;
}

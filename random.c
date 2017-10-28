#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


unsigned int genRan() {//generate random unsigned int from /dev/random

  int fd;

  fd = open("/dev/random", O_RDONLY);

  unsigned int * buffer = malloc(sizeof(unsigned int));//write to this

  int nbytes = read(fd, buffer, sizeof(buffer));

  if (nbytes < 0) {//if something went wrong
    printf("rand num didn't work\n");
    printf("%s\n", strerror(errno));
  }

  unsigned int val = *buffer;//temp storage to free malloc'd

  free(buffer);

  return val;
}




int main() {

  printf("\nGenerating random numbers:\n");

  unsigned int randarr[10];//create array of unsigned ints

  int i;
  for (i = 0; i < 10; i++){
    randarr[i] = genRan();//populate array with random numbers
  }


  for (i = 0; i < 10; i++) {
    printf("\trandom %d: %u\n", i, randarr[i]);//print array
  }

  //write array to file random_nums:

  printf("\nWriting numbers to file...\n");

  int fd_write;

  fd_write = open("random_nums", O_CREAT | O_RDWR, 0644);//create file to write to, allow us to read and write

  int nbytes = write(fd_write, randarr, sizeof(randarr));

  if (nbytes < 0) {//if something went wrong
    printf("write didn't work\n");
    printf("%s\n", strerror(errno));
  }

  close(fd_write);

  //read file to array:

  printf("\nReading numbers from file...\n\n");

  int fd_read;

  fd_read = open("random_nums", O_RDONLY);//open file that was written

  unsigned int randarr_check[10];

  nbytes = read(fd_read, randarr_check, sizeof(randarr_check));//read to new array

  if (nbytes < 0) {//if something went wrong
    printf("read into array didn't work\n");
    printf("%s\n", strerror(errno));
  }

  printf("Verification that written values were the same:\n\n");

  for (i = 0; i < 10; i++){
    printf("\trandom %d: %u\n", i, randarr_check[i]);//print array
  }


  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <fnctl.h>
#include <time.h>


int main() {
  
  int fd = open("/dev/random", O_RDONLY);
  int i;
  int *buffer;
  srand(time(NULL));
  read(fd, buffer, rand() % 15);
  
  int ranarr[10];
  for (i = 0; i < 10; i++) {
    int length = rand() % 15;
    int j = 0;
    for (; j < length; j++) {
      
      
    

  return 0;
}


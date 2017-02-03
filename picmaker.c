#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
  int fd = open("img.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  char *header = "P3 500 500 255\n";
  write(fd, header, strlen(header));
  int i = 0;
  for( i; i< 500; i++){
    int j = 0;
    for( j; j<500; j++){
      char data[25];
      sprintf(data, "0 %d %d ", j%255, j%255, j%255);
      write(fd, data, strlen(data));
    }
    char data[25];
    sprintf(data, "%d 0  %d ", i%255, i%255, i%255);
    write(fd, data, strlen(data));
  }
  write(fd, '\n', 1);
  close(fd);
  return 1;
}

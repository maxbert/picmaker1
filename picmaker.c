#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#define twopi (2 * 3.14159)
/*char data[25];
sprintf(data, "0 0 %d ", j%255, j%255, j%255);
write(fd, data, strlen(data));
*/

int main(){
  int fd = open("img.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  char *header = "P3 500 500 255\n";
  write(fd, header, strlen(header));
  int x = 0;
  for( x; x< 500; x++){
    int y = 0;
    for( y; y<500; y++){
      //printf("(%d,%d)\n", x, y);
      if(((x -250) * (x -250)) < (62500 - ((y - 250) * (y - 250)))){
	char data[25];
	sprintf(data, "127 %d %d ", (-1 * abs(x/3 - 255)) + 255, (-1 * abs(y/3 - 255)) + 255, (-1 * abs(x - 255)) + 255);
	write(fd, data, strlen(data));
      }else{
	char data[25];
	sprintf(data, "255 %d 255 ", (-1 * abs(y/3 - 255)) + 255, (-1 * abs(y - 255)) + 255, (-1 * abs(y - 255)) + 255);
	write(fd, data, strlen(data));
      }
    }      
  }
  write(fd, '\n', 1);
  close(fd);
  return 1;
}

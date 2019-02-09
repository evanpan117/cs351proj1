#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  // char* args[2];
  // string ls = "ls";
  // args [0] = (char*)ls.c_str();
  // args [1] = NULL;
struct timeval_t;
/* create the shared memory object */
int fd = shm_open("Command Timer",O_CREAT | O_RDWR,0666);
/* configure the size of the shared memory object */
ftruncate(fd, sizeof(timeval_t));
/* memory map the shared memory object */
timeval_t * sharedMemory = mmap(0, sizeof(timeval_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
/* write to the shared memory object */

if( fork() == 0 )
{
  timeval_t startTime;
  gettimeofday( &startTime, 0 );
  sprintf(sharedMemory,"%l",startTime);
  sharedMemory += sizeof(startTime);
}
else
{
  execvp( argc[1], argv +1)
  timeval_t end_time;
  gettimeofday( &end_time, 0 );

  timeval_t elapsed_time;
  timersub( &end_time, &startTime, &elapsed_time );
  /* read from the shared memory object */
  printf("%l",sharedMemory);
  /* remove the shared memory object */
  shm unlink(name);
  wait(0);
}
return 0;
}

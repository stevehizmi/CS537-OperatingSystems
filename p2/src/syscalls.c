#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int n;
  int g;
  int pid = 0;

  if(argc > 3){
    exit();
  }
  
  n = atoi(argv[1]);
  g = atoi(argv[2]);

  for(int i = 1; i <= g; i++){
    pid = getpid();
    
  }

  for(int i = 1; i <= n-g; i++){
    kill(-1);

  }

  printf(1,"%d %d\n", getnumsyscalls(pid), getnumsyscallsgood(pid));
  exit();
}

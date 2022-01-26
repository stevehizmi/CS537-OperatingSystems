#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_mencrypt(void){
  char *given_addr;
  int length;
  
  if(argint(1, &length) < 0){
    return -1;
  }

  if(length == 0){
    return 0;
  }
  
  if(argptr(0, (void*)&given_addr, sizeof(*given_addr)) < 0){
    return -1;
  }
  
  

  if(length < 0){
    return -1;
  }
  return mencrypt(given_addr, length);
}

int
sys_getpgtable(void){
  int num, wsetOnly;
  struct  pt_entry *page_entry;

  if(argptr(0, (void*)&page_entry, sizeof(page_entry)) < 0){
    return -1;
  }

  if((argint(1, &num)) < 0){
    
    return -1;
  }
  if (argint(2, &wsetOnly) < 0)
    return -1;
  return getpgtable(page_entry, num, wsetOnly);
}

int
sys_dump_rawphymem(void){
  uint given_add;

  if((argint(0, (int*)&given_add) < 0)){
    return -1;
  }
  char *buffer;
  if(argptr(1, (void*)&buffer, sizeof(buffer)) < 0){
    return -1;
  }
  return dump_rawphymem(given_add, buffer);
}



#include <stdio.h>
#include <string.h>
#include <pthread.h>

static void *my_thread1(void *) {
  char *arg = (char *)arg;
  printf("Argument: %s", arg);
  return (void *)strlen(arg);
}

int main(void) {
  pthread_t thread1;
  pthread_create(&thread1, NULL, my_thread1, "Hello World\n");
  
}

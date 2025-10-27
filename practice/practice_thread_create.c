#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

static void *my_thread1(void *arg) {
  char *s = (char *)arg;
  printf("Argument: %s", s);
  return (void *)strlen(s);
}

int main(void) {
  pthread_t thread1;
  int status;
  status = pthread_create(&thread1, NULL, my_thread1, "Hello World\n");
  if (status != 0)
    exit(EXIT_FAILURE);
  printf("From main\n");
  void *result;
  status = pthread_join(thread1, &result);
  if (status != 0)
    exit(EXIT_FAILURE);
  printf("Thread returned: %ld\n", (size_t)result);
  exit(EXIT_SUCCESS);
}

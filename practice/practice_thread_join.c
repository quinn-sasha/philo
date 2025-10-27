#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

static void *my_thread1(void *arg) {
  (void)arg;
  printf("From thread1\n");
  int status = pthread_join(pthread_self(), NULL);
  if (status != 0)
    printf("Thread1: Failed to join myself: %s (errno: %d)\n", strerror(status), status);
  return arg;
}

int main(void) {
  pthread_t thread1;
  int status;
  status = pthread_create(&thread1, NULL, my_thread1, "Hello World\n");
  if (status != 0)
    exit(EXIT_FAILURE);
  printf("From main\n");
  status = pthread_join(thread1, NULL);
  if (status != 0)
    exit(EXIT_FAILURE);
  printf("Thread returned\n");
  exit(EXIT_SUCCESS);
}

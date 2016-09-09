#include "header.h"

/*
*/
int main(int argc, char *argv[]) {
  pthread_mutex_init(&count_mutex,NULL);
  pthread_cond_init(&count_threshold_cv,NULL);

  int i =0;
  if(argc != 2)
  {
    usage();
  }

  pthread_create(&producerthread, NULL, (void *) &producer, (char *) argv[1]);
  while(i < NUMCONSUMERTHREADS)
  {
    customerNumber = (int *)malloc(sizeof(int));


    //printf("inside");
    pthread_create(&(tid[i]), NULL,(void *) &consumer, (void *) &customerNumber);
    //printf("after thread calling");
    i++;
    customerNumber++;

  }
  for(i=0;i<NUMCONSUMERTHREADS;i++)
  {
    pthread_join(tid[i], NULL);
  }
  pthread_join(producerthread, NULL);
  return 0;
}

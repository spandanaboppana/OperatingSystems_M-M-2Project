#include "header.h"
void * consumer(void* i)
{
  //printf("Consumer ID %d\n", *i);
  Customer* custData;
  int threadID = *((int *) i);
  while(1)
  {
    pthread_mutex_lock(&count_mutex);

    if((CQempty()) == true)
    {
      printf("CONSUMER %d: Queue Empty - Waiting\n", threadID);
      pthread_cond_wait(&count_threshold_cv, &count_mutex);
    }

    custData = CQdelete();
    printf("CONSUMER %d: Deleting the Customer ID %d\n", threadID, custData->custID);
    free(custData);
    //printf("CONSUMER %d: ");
    display();
    pthread_mutex_unlock(&count_mutex);

  }
  free(i);
  pthread_exit(NULL);
}

#include "header.h"
void * producer(char *str)
{

  printf("File to Read : %s\n", str);
  Customer *C1,*C2;
  int numberOfCustomers = 0;
  int customerSerial = 0;
  FILE *fp;
  char* line = NULL;
  char* buffer = NULL;
  int arrivalTime, serviceTime;
  size_t bytelen;
  ssize_t readLineLength;
  fp = fopen(str, "r");
  if (fp == NULL) errExit("FileRead Failure");

  readLineLength = getline(&line, &bytelen, fp);
  printf("%s\n",line);
  // get the number form of number of customers
  numberOfCustomers = atoi(line);
  printf("PRODUCER: Number of customers in this simulation : %d\n", numberOfCustomers);

  while ((readLineLength = getline(&line, &bytelen, fp)) != -1) {
    getTimes(&arrivalTime, &serviceTime, line);
    printf("PRODUCER: servicetime:%d\n",serviceTime);
    customerSerial++;
    C1 = createCustomer(serviceTime, customerSerial);
    pthread_mutex_lock(&count_mutex);
    CQinsert(C1);
    pthread_cond_signal(&count_threshold_cv);
    printf("PRODUCER: ");
    display();
    pthread_mutex_unlock(&count_mutex);
  }

  fclose(fp);
  pthread_exit(NULL);
}

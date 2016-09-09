#include "header.h"
void errExit(char *str)
{
  printf("FATAL ERROR : %s\n", str);
  exit(1);
}

Customer* createCustomer(int sTime, int currentCustID)
{
  Customer *c = NULL;
  c = (Customer*)malloc(sizeof(Customer));

  if(c == NULL)
  {
    // Error in malloc
    errExit("Malloc Failure");
  }

  memset((void *)c, '\0', sizeof(Customer));
  c->serviceTime = sTime;
  c->custID = currentCustID;
  return c;
}

void getTimes(int* arrivalTimeNum,int* serviceTimeNum, char* line)
{
  char *arrivalTime, *serviceTime;
  arrivalTime = strtok(line," ");
  serviceTime = strtok(NULL," ");

  *arrivalTimeNum = atoi(arrivalTime);
  *serviceTimeNum = atoi(serviceTime);
}

void usage() {
    printf("\n\n======= Usage Syntax ========\n");
    printf("mm2 <configuration file name>\n\n");
    exit(1);
}

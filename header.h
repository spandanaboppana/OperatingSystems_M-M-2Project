#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define SIZE 100
#define NUMCONSUMERTHREADS 2
typedef struct Customer_
{
  int custID;
  int serviceTime;
} Customer;

enum
{
  false = 0,
  true
};
int* customerNumber;

Customer* CQ[SIZE];
pthread_t tid[NUMCONSUMERTHREADS];
pthread_t producerthread;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;
extern int numberOfCustomers;
//pthread_mutex_init(&mutex,NULL);
void usage();
void errExit(char *str);
int CQfull();
void CQinsert(Customer *elem);
Customer* CQdelete();
void display();
void* producer(char *fileName);
void getTimes(int* arrivalTime,int* serviceTime, char* line);
void* consumer(void *i);
Customer* createCustomer(int sTime, int s);

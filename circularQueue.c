#include "header.h"

int f = -1;
int r = -1;

int CQfull() { /* Function to Check Circular Queue Full */
 if ((f == r + 1) || (f == 0 && r == SIZE - 1))
  return 1;
 return 0;
}
int CQempty() { /* Function to Check Circular Queue Empty */
 if (f == -1)
  return 1;
 return 0;
}

void CQinsert(Customer *elem) { /* Function for Insert operation */
 if (CQfull())
 errExit("Queue Overflow");

 else {
  if (f == -1)
   f = 0;
  r = (r + 1) % SIZE;
  CQ[r] = elem;
 }
}

Customer* CQdelete() { /* Function for Delete operation */
 Customer* elem;
 if (CQempty()) {
   printf("Queue Underflow");
  return (NULL);
 } else {
  elem = CQ[f];
  if (f == r) {
   f = -1;
   r = -1;
  } /* Q has only one element ? */
  else
   f = (f + 1) % SIZE;

  return (elem);
 }
}
void display() { /* Function to display status of Circular Queue */
  int i;
  if (CQempty())
  {
    printf("\n=====QUEUE DISPLAY=====\n");
    printf("Empty Queue\n");
  } else {
    printf("\n=====QUEUE DISPLAY=====\n");
    printf("Front[%d]->", f);
    for (i = f; i != r; i = (i + 1) % SIZE) {
      printf("%d ", CQ[i]->serviceTime);
    }
    printf("%d ", CQ[i]->serviceTime);
    printf("<-[%d]Rear\n", r);
  }
  printf("=====END OF QUEUE DISPLAY=====\n");

}

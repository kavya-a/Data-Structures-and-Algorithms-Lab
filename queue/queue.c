#include<stdio.h>
#define size 5

void enqueue(int q[],int *front, int *rear, int num)
{
 // printf("Rear = %d",*rear);
  if((*rear+1)%size == *front)
    {
     printf("\n\nQueue is full");
     return;
    }

  if(*rear == -1 && *front == -1)
   {
      *rear = 0;
      *front = 0;
   }

  
 
  else
     *rear = (*rear+1)%size;
  printf("\n\nFront = %d Rear = %d",*front,*rear);
  q[*rear] = num;

 // display(q,front,rear);

}

void dequeue(int q[], int *front, int *rear)
{

  if( *front == -1 && *rear == -1 )
    {
      printf("\n\nQueue is empty");
      return;
    }

  else if(*front ==  *rear)
   {
     *front = -1;
     *rear = -1;
   }

  else
   {
     *front = (*front +1)%size;
   }

  printf("\n\nFront= %d Rear = %d ",*front,*rear);

} 
     


void display(int q[], int *front , int *rear)
{
  printf("\n\n");
  int i;

 /* while(*front != *rear)
  {
   //printf("%d",i++);
   printf("%d  ",q[*front]);
   *front = (*front + 1)%size;
  }*/

  for(i=*front; i != *rear; i = (i+1)%size)
     printf("%d  ",q[i]); 
 
 printf("%d  ",q[*rear]);

}
  


void main()
{

  int q[size],i,j,ch,num;
  int *front,*rear;

  *front = *rear = -1;

  printf("SIZE = %d \n",size);
  
do
{
  printf("\n\n1.Enqueue\n2.Dequeue\n3.display\n4.Exit\n\n");
  printf("Enter choice :  ");
  scanf("%d",&ch);

  switch(ch)
  {
    case 1:  printf("\n\nEnter the element to be enqueued:  ");
             scanf("%d",&num);
             enqueue(q,front,rear,num);
             break;
    
    case 2: dequeue(q,front,rear);
            break;

    case 3: display(q,front,rear); 
 }

}while(ch!=4);
}

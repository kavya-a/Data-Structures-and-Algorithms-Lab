/*Program to implement a stack using an array */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 10

int push(int stack[] , int tos,int num)
{
  if(tos==size-1)
    {
      printf("\n\nStack is full\n\n");
      return tos;
    }
  tos = tos+1;
  stack[tos] = num;
  return tos;
}

int pop(int stack[] , int tos)
{
  if(tos == -1)
    {
     printf("\nEmpty stack\n");
     return tos;
    }
  printf("\n\n%d has been popped\n\n",stack[tos]);
  tos=tos-1;
  return tos;
}

void display(int stack[] , int tos)
{

  int i;

  if(tos== -1)
    {
     printf("\nEmpty stack\n");
     return;
    }

  printf("\n\n");
  printf("TOS -> %d\n",stack[tos]);
  for(i=tos-1;i>=0;i--)
    {
      printf("       %d \n",stack[i]);
    }
 printf("\n\n");
}
  


void main()
{

  int i,j,tos=-1,stack[size],ch;
  char str[10];
  int num;

  do
  {
    printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1: printf("\n\nEnter the number to be pushed:  ");
              scanf("%d",&num);
             
              tos = push(stack,tos,num);
              printf("\n\nElement pushed\n\n"); 
              break;
     
      case 2: tos = pop(stack,tos);
              printf("\n\nElement popped\n\n");
              break;

      case 3: display(stack,tos);
              break;

      case 4: exit(1);
              break;
    }
  }while(ch!=4);

} 

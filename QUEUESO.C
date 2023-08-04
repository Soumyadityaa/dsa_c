#include<stdio.h>
#include<conio.h>
#define size 10
int queue[size],front=-1,rear=-1;
void addq()
{
 int element;
 if(rear==size-1)
 {
   printf("queue is full\n");
 }
 else
 {
   rear=rear+1;
   if(front==-1)
   {
     front=front+1;
   }
   printf("enter value:");
   scanf("%d",&element);
   queue[rear]=element;
 }

}

void delq()
{
  int temp;
  if(front==-1){
  printf("queue is empty");
  }
  else
  {
    temp=queue[front];

    if(front==rear)
    {
     front=rear=-1;
    }
    else
    {
     front=front+1;
    }

    printf("%d is deleted sucessfully...:)\n",temp);

  }

}
void display()
{
  int i;
  if(front==-1){
   printf("queue is empty, So nothing is display \n");
  }
  else
  {
    for(i=front;i<=rear;i++)
    {
     printf("%d ",queue[i]);
    }
  }

}
void main()
{
 int ch;
 clrscr();



 do
 {
  printf("\nenter choice...\n1.addq\n2.delq\n3.display queue\n4.exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   addq();
   break;

   case 2:
   delq();
   break;

   case 3:
   display();
   break;

   default:
   printf("invalid choice and you exit");
   break;
  }

 } while(ch!=4);

 getch();

}
#include<stdio.h>
#include<conio.h>
int stack[10];
int top=-1;
void push()
{
  if(top==9){
  printf("Stack is overflow");
  }
  else{
  int element;
  top=top+1;
  printf("enter value");
  scanf("%d",&element);
  stack[top]=element;
  }

}

void pop()
{
  if(top==-1){
   printf("stack is empty");
  }
  else{

   top=top-1;
   printf("deleted succesfully");
  }

}

void display()
{
 int i;
 if(top==-1){
  printf("stack is empty");
  getch();
 }
 else{
 for(i=top;i>=0;i--){
 printf("%d",stack[i]);
 }
 }
}

void main()
{
 int choice;
 clrscr();

 do
 {
 printf("enter your choice:\n 1:push \n 2:pop \n3:display");
 scanf("%d",&choice);
 switch(choice)
 {
   case 1:
   push(top,stack);
   break;

   case 2:
   pop(top,stack);

   case 3:
   display(top,stack);
   break;

   default:
   printf("invalid choices...:(");
   break;
 }
 }while(choice!=4);
 getch();
}

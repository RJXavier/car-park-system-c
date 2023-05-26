#include <stdio.h>
#include <conio.h>

int MAXSIZE = 10;
int stack[10];
int top = -1;

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int count()
{
    int x,i,data;
    x = 0;

   if(!isempty()) {

   for (i=9;i>=0;i--)
   {
       data = stack[i];
       if(data != 0)
       {x++;}
           }
           return x;
    }
     else {
      printf("There is no available cars left in the parking lot.\n");
   }
}
int disp()
{
    int data,i;

   if(!isempty()) {

   for (i=9;i>=0;i--)
   {
       data = stack[i];
       if(data != 0)
       {printf("%d\t", data);}
           }
    }
   else {
      printf("There is no cars left in the parking lot.\n");
   }

}

int pop() {
   int data;

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("It seems the parking lot is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("There is no more space left in parking.\n");
   }
}

int main() {

   int c, plate, c2, i=0;
   system("cls");
   printf("Hi, Welcome to the car park.\n");
   printf(" Press 1 to enter your car plate number.\n");
   printf(" Press 2 to delete your car plate number.\n");
   printf(" Press 3 to check if the lot is empty.\n");
   printf(" Press 4 to check the number of cars in the lot.\n");
   printf(" Press 5 to check the number of empty spaces remaining in the lot.\n");
   printf(" Press 6 to exit the menu.\n");
   printf("Enter your choice: \n");
   scanf("%d",&c);

   switch(c)
   {
   case 1 :
        printf("Enter plate number :\n");
        scanf("%d", &plate);
        push(plate);
        main();
        break;

   case 2 :
        printf("The plate number of the departed car is %d\n", peek());
        pop();
        getch();
        main();
        break;

   case 3:
        printf("Status: %s\n" , isempty()?"Yes the car lot is empty.":"No the car lot is not empty.");
        getch();
        main();
        break;

   case 4:
        printf("Available cars in the parking area :\t");
        disp();
        getch();
        main();
        break;

   case 5:
        printf("There are %d cars available at the moment\n", count());
        getch();
        main();
        break;

   case 6:
        printf("Exiting.\n");
        getch();
        exit(0);
        break;
   default:
        printf("Invalid Choice! Please try again.\n");
        main();
        break;

   }

   return 0;
}

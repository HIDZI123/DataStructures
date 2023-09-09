//Program to implement stack
//by Name:Mustafa Sarangpurwala Roll no:88 Branch:AI & DS

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

//Size of a stack//
#define MAX 3

//struct for stack and operations//
struct student
{
   int rollNo;
   char name[50];
   int marks;
};

struct stack
{
    unsigned top;
   struct student st[MAX + 1];
};

char isFull(struct stack a)
{
    if(a.top==MAX-1){
        return 1;
    } else{
        return 0;
    }
}

char isEmpty(struct stack a)
{
    if(a.top==0){
        return 1;
    } else{
        return 0;
    }
}

struct student peek(struct stack a)
{
    return  a.st[a.top];
}

void push(struct stack *a, struct student s)
{
    if (!isFull(*a))
    {
        a->top++;
        a->st[a->top]=s;
        printf("\n");
        printf("Record changed successfully!\n");
      
    } else{
       
        printf("Stack Overflow");
    }
    
}

struct student pop(struct stack *a)
{
    if(!isEmpty(*a)){
        struct student temp = a->st[a->top];
        a->top--;
        printf("The top value is deleted!");
        return temp;
    } else{

        printf("Stack Underflow");
        struct student temp2={0,"",0};
        return temp2;
    }
}

//main function//
int main()
{
    int option;
    struct student s;
    struct stack a;
    a.top=0;

    while(1){
        printf("MENU  \t Pick you choice \n\n 1.Check to see if Stack is full \n 2.Check to see if Stack is empty \n 3.Insert a value \n 4.Delete a value \n 5.Look at the topmost value \n 6.Exit");
        scanf("%d",&option);

        //switch case//
        switch(option){
            case 1: 
                    if(isFull(a)){
                        printf("The stack is Full!");
                    } else{
                        printf("The stack is not full!");
                    }break;
            case 2:
                    if(isEmpty(a)){
                        printf("The stack is Empty!");
                    } else{
                        printf("The stack is not empty!");
                    }break;
            case 3: 
                    if (!isFull(a)) {
                    printf("Enter student details to push:\n");
                    getchar(); 
                    printf("Name :");
                    fgets(s.name, sizeof(s.name), stdin);
                    printf("Roll: ");
                    scanf("%d", &s.rollNo);
                    printf("Marks: ");
                    scanf("%d", &s.marks);
                    push(&a , s);
                    }
                    else{
                        printf("Stack overflow");
                    }
                    break;
            case 4:
                    if(!isEmpty(a)){
                       s = pop(&a);
                        if (s.rollNo != 0) {
                    printf("Popped student record details:\n");
                    printf("Name: %s\n", s.name);
                    printf("Roll: %d\n", s.rollNo);
                    printf("Marks: %d\n", s.marks);
                    }} else{
                        printf("stack is Empty!");
                    }break;

            case 5:
                    if(!isEmpty(a)){
                        s=peek(a);
                        printf("Fetched student record details:\n");
                        printf("Name: %s\n", s.name);
                        printf("Roll: %d\n", s.rollNo);
                        printf("Marks: %d\n", s.marks);
                    }else{
                        printf("The stack is empty");
                    }break;
            case 6:
                    exit(0);
            default:
                    printf("Error");
        }
    }
    return 0;
 }

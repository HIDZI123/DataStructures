//Program to Implement stack
//by Name:Mustafa Sarangpurwala   Roll no:88   Branch:AI & DS 


#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

//Struct for array and stack
struct student
{
   int rollNo,marks;
   char name[50];
   
};

struct stack
{
    unsigned int TOP,MAX;
    struct student *studarray;
    
};

//Functions of Operations on stack

char isFull( struct stack *y)
{
    if(y->TOP==y->MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char isEmpty( struct stack *y)
{
    if(y->TOP==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct student *x, struct stack *y)
{
   if(isFull(y)==1) 
   {
    printf("Stack Overflow");
   }
   else
   {
    y->TOP++;
    y->studarray[y->TOP] = *x;
   }
}

void pop(struct stack *y)
{
   if(isEmpty(y)==1)
   {
    printf("Stack underflow\n");
   }  
   else
   {
        struct student temp;
        temp=y->studarray[y->TOP];
        printf("Name: %s\n",temp.name);
        printf("Roll No: %d\n",temp.rollNo);
        printf("Marks: %d\n",temp.marks);

        y->TOP--;           
   }     
}

void peek(struct stack *y)
{
    if(isEmpty(y)==1)
   {
    printf("Stack underflow\n");
   }  
   else
   {
    struct student temp;
    temp=y->studarray[y->TOP];
    printf("\n");
    printf("The top value is:\n");
    printf("Name: %s\n",temp.name);
    printf("Roll No: %d\n",temp.rollNo);
    printf("Marks: %d\n",temp.marks);
    }
}

int main()
{
    /* struct student *records;
    struct stack *s; */
    int option;
  
    
    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); // Allocate memory for the stack
    struct student *records = (struct student *)malloc(sizeof(struct student)); // Allocate memory for the student record
    s->studarray=(struct student*) malloc((s->MAX+1)*sizeof(struct student));
    s->TOP=0;
    printf("Enter the size of the stack,(Enter value >0)");
    scanf("%u",&s->MAX);


    do
    {
        //Menu bar

        printf("Enter 1 to check if stack is full\n");
        printf("Enter 2 to check if stack is empty\n");
        printf("Enter 3 to push value in stack\n");
        printf("Enter 4 to pop value in stack\n");
        printf("Enter 5 to peek topmost value of stack\n");
        printf("Enter 6 to exit\n");
        printf("Enter option:\t");
        scanf("%d",&option);

        //Switch cases
        
        switch (option)
        {
            case 1:
                    if(isFull(s))
                    {
                        printf("Stack overflow\n");
                    }
                    else
                    {
                        printf("Not full\n");
                    }
                    break;

            case 2:
                    if(isEmpty(s))
                    {
                        printf("Stack Underflow\n");
                    }
                    else
                    {
                        printf("Stack not empty\n");
                    }
                    break;

            case 3:
                   
                    printf("Enter the details of the student\n");
                    printf("Enter the name of the student\n");
                    scanf("%s",records->name);
                    printf("Enter the roll number of the student\n");
                    scanf("%d",&records->rollNo);
                    printf("Enter the marks of the student\n");
                    scanf("%d",&records->marks);
                    push(records,s);
                    break;

            case 4:
                    pop(s);
                    break;

            case 5:
                    peek(s);
                    break;

            case 6:
                    free(s->studarray); // Free dynamically allocated memory
                    free(records); // Free dynamically allocated memory
                    free(s); // Free dynamically allocated memory
                    exit(0);

        
            default:
                    printf("Invalid choice");
                    break;
        }

    } while (option!=6);

    return 0;
}
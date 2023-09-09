//Program to implement stack using linked list
//by Name:Mustafa Sarangpurwala    Roll No:88    Branch:AI&DS

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

//Struct of node and stack
struct node
{
    int rollNo;
    int marks;
    struct node *next;
};

struct sll
{
    struct node *top;
};

//Functions of stack and sll opertaions

void push(struct node *x, struct sll *y)
{
    x->next=y->top;
    y->top=x;
}

void pop(struct node *x, struct sll *y)
{
    struct node *ptr;
    ptr=y->top;
    y->top=y->top->next;
    free(ptr);
    ptr=NULL;
}

void display(struct node *x, struct sll *y)
{
    struct node *temp;
    temp=y->top;

    while(temp!=NULL)
    {
        printf("\n");
        printf("Roll No :%d\n",temp->rollNo);
        printf("Marks : %d\n",temp->marks);
        temp=temp->next;
        printf("\n");
    }
}

void peek(struct node *x, struct sll *y)
{
    struct node *temp;
    temp=y->top;

    while(temp!=NULL)
    {
       printf("\n");
       printf("Roll No: %d",y->top->rollNo); 
       printf("Marks: %d",y->top->marks);
       temp=temp->next;
       printf("\n"); 
    }
}

//Main

int main()
{
    struct node *new_node;
    struct sll *stack;
    stack->top=NULL;
    new_node=NULL;
    int choice;

    //Menu bar

    do
    {
        printf("Select 1 to Push the values on stack\n");
        printf("Select 2 to Pop the values in stack\n");
        printf("Select 3 to Display the values of stack\n");
        printf("Select 4 to Peek the topmost value of stack\n");
        printf("Select 5 to exit\n");
        printf("Enter your choice");
        scanf("%d",&choice);

        //Switch case

        switch(choice)
        {
            case 1:
                    new_node= (struct node*)malloc(sizeof(new_node));
                    printf("Enter Roll No:\n");
                    scanf("%d",&new_node->rollNo);
                    printf("Enter marks\n");
                    scanf("%d",&new_node->marks);
                    new_node->next=NULL;

                    if(stack->top==NULL)
                    {
                        stack->top=new_node;
                    }
                    else
                    {
                        push(new_node, stack);
                    }
                    printf("\n");
                    break;

            case 2:
                    if(stack->top==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        pop(new_node, stack);
                    }
                    break;

            case 3:
                    if(stack->top==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        display(new_node, stack);
                    }
                    break;

            case 4:
                    if(stack->top==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        peek(new_node, stack);
                    }
                    break;

            case 5:
                    exit(0);

            default:
                    printf("Function doesn't exists");
                    break;
        }


    } while (choice!=5);

    return 0;   
}
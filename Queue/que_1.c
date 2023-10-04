#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct student
{
    int rollNo, marks;
    char name[50];
};

struct que
{
    struct student *ptq;
    int front, rear, max;
};

char isEmpty(struct que *q)
{
    if ((q->rear == -1 && q->front == -1) || (q->front > q->rear))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char isFull(struct que *q)
{
    if (q->rear == q->max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(struct que *q, struct student *stud)
{
    if (isFull(q))
    {
        printf("\n\tQueue Overflow\n");
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
        q->ptq[q->rear] = *stud;
    }
}

struct student deQueue(struct que *q)
{
    struct student temp;
    if (isEmpty(q))
    {
        printf("\n\tQueue Underflow\n");
    }
    else
    {
        temp = q->ptq[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        return temp;
    }
}

void display(struct que *q, struct student *stud)
{
    int i;
    if (isEmpty(q))
    {
        printf("\n\tQueue Underflow\n");
    }
    else
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf("\nThe Queue is:\t");
            printf("Name of the student:%s\n", q->ptq[i].name);
            printf("Roll No of the student:%d\n", q->ptq[i].rollNo);
            printf("Marks of the student:%d\n", q->ptq[i].marks);
            printf("\n");
        }
    }
}

void peek(struct que *q)
{
    if (isEmpty(q))
    {
        printf("\n\tQueue Underflow\n");
    }
    else
    {
        struct student temp;
        temp = q->ptq[q->front];
        printf("\n");
        printf("The top value is:\n");
        printf("Name: %s\n", temp.name);
        printf("Roll No: %d\n", temp.rollNo);
        printf("Marks: %d\n", temp.marks);
    }
}

int main()
{
    struct student *stud;
    struct que *Queue;
    stud = (struct student *)malloc(sizeof(struct student));
    Queue = (struct que *)malloc(sizeof(struct que));
    Queue->ptq = (struct student *)malloc(Queue->max * sizeof(struct student));

    int option;
    int temp;

    printf("\nEnter the size of Queue(>0):\n");
    scanf("%d", &Queue->max);

    do
    {
        printf("Enter 1 to check if Queue is full\n");
        printf("Enter 2 to check if Queue is empty\n");
        printf("Enter 3 to Enter a  value in Queue\n");
        printf("Enter 4 to Delete a value in Queue\n");
        printf("Enter 5 to peek topmost value of Queue\n");
        printf("Enter 6 to Print the Queue\n");
        printf("Enter 7 to exit\n");
        printf("Enter option:\t");
        scanf("%d", &option);

        switch (option)
        {
        case 1:

            if (isFull(Queue))
            {
                printf("\n\tQueue overflow\n");
            }
            else
            {
                printf("\n\tNot full\n");
            }
            break;

        case 2:

            if (isEmpty(Queue))
            {
                printf("Queue Underflow\n");
            }
            else
            {
                printf("Queue not empty\n");
            }
            break;

        case 3:

            printf("Enter the details of the student\n");
            printf("Enter the name of the student\n");
            scanf("%s", stud->name);
            printf("Enter the roll number of the student\n");
            scanf("%d", &stud->rollNo);
            printf("Enter the marks of the student\n");
            scanf("%d", &stud->marks);
            enQueue(Queue, stud);
            break;

        case 4:

            struct student temp;
            temp = deQueue(Queue);
            printf("Deleted Student Details\n");
            printf("Name of the student:%s\n", temp.name);
            printf("Roll No. of the student:%d\n", temp.rollNo);
            printf("Marks of the student:%d\n", temp.marks);
            break;

        case 5:

            peek(Queue);
            break;

        case 6:

            display(Queue, stud);
            break;

        case 7:
            free(Queue);
            free(stud);
            free(Queue->ptq);
            exit(0);

        default:
            printf("Invalid option");
            break;
        }
    } while (1);

    return 0;
}
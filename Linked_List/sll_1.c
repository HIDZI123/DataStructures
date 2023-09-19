// Program to write singly linked list
//  by Name:Mustafa Sarangpurwala   Roll no:88   Branch:AI & DS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

// struct of sll and node

struct node
{
    int rollNo;
    int marks;
    struct node *next;
};

struct sll
{
    struct node *head;
};

// Functions of sll operations

void add_front(struct node *x, struct sll *y)
{
    x->next = y->head;
    y->head = x;
    printf("\n");
}

void add_end(struct node *x, struct sll *y)
{
    struct node *temp = y->head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = x;
}

void del_front(struct node *x, struct sll *y)
{
    struct node *ptr = y->head;
    y->head = y->head->next;
    free(ptr);
    ptr = NULL;
}

void del_end(struct node *x, struct sll *y)
{
    struct node *temp = y->head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void traverse(struct node *x, struct sll *y)
{
    struct node *temp = y->head;

    while (temp != NULL)
    {
        printf("\n");
        printf("\nRoll No : %d", temp->rollNo);
        printf("\nMarks : %d", temp->marks);
        temp = temp->next;
        printf("\n");
    }
}

void add_anynode(struct node *x, struct sll *y, int pos)
{
    struct node *temp = y->head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    x->next = temp->next;
    temp->next = x;
}

void del_anynode(struct node *x, struct sll *y, int pos)
{
    struct node *temp = y->head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    temp2 = NULL;
}

// Main

int main()
{
    struct node *new_node;
    struct sll *list = (struct sll *)malloc(sizeof(struct sll));
    /* list=0; */
    list->head = NULL;
    new_node = NULL;
    int option;

    do
    {
        // Menu

        printf("Option 1:Insert at the beginning of the list\n");
        printf("Option 2:Delete at the beginning of the list\n");
        printf("Option 3:Insert at the end of the list\n");
        printf("Option 4:Delete at the end of the list\n");
        printf("Option 5:Insert at any posiion of the list\n");
        printf("Option 6:Delete at any posiion of the list\n");
        printf("Option 7:traverse the list\n");
        printf("Option 8:Exit\n");
        printf("Enter option No:\n");
        scanf("%d", &option);

        // Switch case

        switch (option)
        {
        case 1:
            new_node = (struct node *)malloc(sizeof(new_node));
            printf("\nEnter the Roll No:");
            scanf("%d", &new_node->rollNo);
            printf("\nEnter your marks:");
            scanf("%d", &new_node->marks);
            new_node->next = NULL;

            if (list->head == NULL)
            {
                list->head = new_node;
            }
            else
            {
                add_front(new_node, list);
            }
            printf("\n");
            break;

        case 2:
            if (list->head == NULL)
            {
                printf("List is Empty\n");
            }
            else
            {
                del_front(new_node, list);
            }
            break;

        case 3:
            new_node = (struct node *)malloc(sizeof(new_node));
            printf("\nEnter the Roll No:");
            scanf("%d", &new_node->rollNo);
            printf("\nEnter your marks:");
            scanf("%d", &new_node->marks);
            new_node->next = NULL;

            if (list->head == NULL)
            {
                list->head = new_node;
            }
            else
            {
                add_end(new_node, list);
            }
            printf("\n");
            break;

        case 4:
            if (list->head == NULL)
            {
                printf("List is Empty\n");
            }
            else
            {
                if (list->head->next == NULL)
                {
                    printf("Emptying the list\n");
                    free(list->head);
                    list->head = NULL;
                }
                else
                {
                    del_end(new_node, list);
                }
            }
            break;

        case 5:
            new_node = (struct node *)malloc(sizeof(new_node));
            printf("\nEnter the Roll No:");
            scanf("%d", &new_node->rollNo);
            printf("\nEnter your marks:");
            scanf("%d", &new_node->marks);
            new_node->next = NULL;

            if (list->head == NULL)
            {
                list->head = new_node;
            }
            else
            {
                int pos;
                printf("\nEnter the position:");
                scanf("%d", &pos);
                add_anynode(new_node, list, pos);
            }
            printf("\n");
            break;

        case 6:
            if (list->head == NULL)
            {
                printf("List is Empty\n");
            }
            else
            {
                if (list->head->next == NULL)
                {
                    printf("Emptying the list\n");
                    free(list->head);
                    list->head = NULL;
                }
                else
                {
                    int pos;
                    printf("\nEnter the position:");
                    scanf("%d", &pos);
                    del_anynode(new_node, list, pos);
                }
            }
            break;

        case 7:
            if (list->head == NULL)
            {
                printf("Empty list\n");
            }
            else
            {
                traverse(new_node, list);
            }
            break;

        case 8:
            free(list);
            list = NULL;
            exit(0);

        default:
            printf("Function doesn't exists\n");
        }

    } while (option != 8);
    return 0;
}

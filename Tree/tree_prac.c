// Practice code for binary search tree
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insertElement(struct node *, int);
void preOrderTraversal(struct node *);
void inOrderTraversal(struct node *);
void postOrderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
int totalNode(struct node *);
int totalExternalNode(struct node *);
int totalInternalNode(struct node *);
int height(struct node *);
void createTree(struct node *);
void deleteTree(struct node *);

void main()
{
}

void createTree(struct node *tree)
{
    tree = NULL;
}

struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }

        if (val < parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}

void preOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}

void inOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inOrderTraversal(tree->left);
        printf("%d\t", tree->data);
        inOrderTraversal(tree->right);
    }
}

void postOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

struct node *findSmallestElement(struct node *tree)
{
    if ((tree == NULL) || (tree->left == NULL))
    {
        return tree;
    }
    else
    {
        return findSmallestElement(tree->left);
    }
}

struct node *findLargestElement(struct node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
    {
        return tree;
    }
    else
    {
        return findLargestElement(tree->right);
    }
}

struct node *deleteElement(struct node *tree, int val)
{
    struct node *cur, *parent, *suc, *psuc, *ptr;
    if (tree->left == NULL)
    {
        printf("\n The Tree is emptyn\n");
        return tree;
    }
    parent = tree;
    cur = tree->left;
    while ((cur != NULL) && (val != cur->data))
    {
        parent = cur;
        /* cur = (val < cur->data)? cur->left : cur->right; */
        if (val < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }

    if (cur == NULL)
    {
        printf("\n The data to be deleted is not present in the tree\n");
        return tree;
    }
    else if (cur->left == NULL)
    {
        ptr = cur->right;
    }
    else if (cur->right == NULL)
    {
        ptr = cur->left;
    }
    else
    {
        psuc = cur;
        cur = cur->left;
        while (suc->left != NULL)
        {
            psuc = suc;
            suc = suc->left;
        }
        if (cur == psuc)
        {
            suc->left = cur->right;
        }
        else
        {
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc;
    }

    if (parent->left == cur)
    {
        parent->left = ptr;
    }
    else
    {
        parent->right = ptr;
    }
    free(cur);
    return tree;
}

int totalNode(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (totalNode(tree->left) + totalNode(tree->right) + 1);
    }
}

int totalExternalNode(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1;
    }
    else
    {
        return (totalExternalNode(tree->left) + totalExternalNode(tree->right));
    }
}

int totalInternalNode(struct node *tree)
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
    {
        return 0;
    }
    else
    {
        return (totalInternalNode(tree->left) + totalInternalNode(tree->right) + 1);
    }
}

int height(struct node *tree)
{
    int leftHeight, rightHeight;
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        leftHeight = height(tree->left);
        rightHeight = height(tree->right);
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

void deleteTree(struct node *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}
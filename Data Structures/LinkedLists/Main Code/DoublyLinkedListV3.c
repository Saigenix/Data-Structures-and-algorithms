#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
} *head;

void linkedListTraversal()
{

    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("linked list is empty");
        return;
    }
    while (ptr != NULL)
    {
        printf(":: %d :: ", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtFirst()
{
    int n;
    printf("Enter Data to add: ");
    scanf("%d", &n);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = head;
    ptr->pre = NULL;
    head = ptr;
}

void insertAtLast()
{
    int n;
    printf("Enter Data to add: ");
    scanf("%d", &n);
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;
    while (p->next != NULL)
        p = p->next;
    ptr->pre = p;
    p->next = ptr;
}

void insertAtPosition(int pos)
{
    int n;
    printf("Enter Data to add: ");
    scanf("%d", &n);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    struct node *p = head;
    int k = 1;
    while (k < pos && p->next != NULL)
    {
        p = p->next;
        k++;
    }
    if (k == pos)
    {
        ptr->pre = p;
        ptr->next = p->next;
        p->next->pre = ptr;
        p->next = ptr;
    }
}

void DeleteAtFirst()
{
    struct node *p = head;
    printf("Element deleted %d\n", p->data);
    p = p->next;
    p->pre = NULL;
    head = p;
}

void DeleteAtLast()
{
    struct node *p = head;
    if (p->next == NULL)
    {
        printf("Element deleted %d \n", p->data);
        head = NULL;
    }
    else
    {
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        printf("Element deleted %d \n", p->next->data);
        p->next = NULL;
    }
}

void DeleteAtPosition(int pos)
{
    struct node *p = head;
    int k = 1;
    while (k < pos && p->next != NULL)
    {
        p = p->next;
        k++;
    }
    if (k == pos)
    {
        printf("Element deleted %d \n", p->data);
        p->next->pre = p->pre;
        p->pre->next = p->next;
    }
}

void Search(int data)
{
    struct node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (data == temp->data)
        {
            printf("%d is found At %d\n", data, count);
            return;
        }
        count++;
        temp = temp->next;
    }
    printf("Not Found !");
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    int n;
    int val;
    while (1)
    {
        printf("Enter \n1. Insert At first \n2. Insert At Last \n3. Delete at first \n4. Delete at Last\n5. Search \n6. Display \n7. delete At pos\n");
        scanf("%d", &val);
        switch (val)
        {
        case 1:
            insertAtFirst();
            break;
        case 2:
            insertAtLast();
            break;
        case 3:
            DeleteAtFirst();
            break;
        case 4:
            DeleteAtLast();
            break;
        case 5:
            printf("Enter Data to add: ");
            scanf("%d", &n);
            Search(n);
            break;
        case 6:
            linkedListTraversal();
            break;
        case 7:
            printf("Enter pos to delete: ");
            scanf("%d", &n);
            DeleteAtPosition(n);
            break;
        case 8:
            printf("Enter pos to add: ");
            scanf("%d", &n);
            insertAtPosition(n);
            break;
        }
    }
    return 0;
}
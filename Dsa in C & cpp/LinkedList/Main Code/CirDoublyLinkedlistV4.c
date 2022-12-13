#include <stdio.h>
#include <stdlib.h>
// this code should be edited
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *head, *p1;

void linkedListTraversal()
{
    struct Node *ptr = head;
    do
    {
        printf(":: %d ::", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

void InsertAtFirst(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = head;
    head->next = ptr;
    head = ptr;
}

void InsertAtLast(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    struct Node *q = head;
    do
    {
        q = q->next;
    } while (q->next != head);
    q->next = ptr;
    ptr->next = head;
}

void InsertAtPosition(int pos)
{
    int val;
    printf("Enter Data to add: ");
    scanf("%d", &val);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    struct Node *p = head;
    int k = 1;
    while (k != pos - 1 && p->next != head)
    {
        p = p->next;
        k++;
    }
    if (k + 1 == pos)
    {
        ptr->next = p->next;
        p->next = ptr;
    }
}

void DeleteAtFirst()
{
    struct Node *temp = head;
    struct Node *q = head;
    do
    {
        q = q->next;
    } while (q->next != head);
    q->next = head->next;
    head = head->next;
    free(temp);
    // printf("done");
}

void DeleteAtLast()
{
    struct Node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next->next != head);
    struct Node *p = temp->next;
    temp->next = head;
    free(p);
}

void DeleteAtPos(int pos)
{
    struct Node *p = head;
    int k = 1;
    while (k != pos - 1 && p->next != head)
    {
        p = p->next;
        k++;
    }
    if (k + 1 == pos)
    {
        struct Node *q = p->next;
        p->next = p->next->next;
        free(q);
    }
}

void Search(int data)
{
    struct Node *temp = head;
    int count = 1;
    do
    {
        if (data == temp->data)
        {
            printf("%d is found At %d\n", data, count);
            return;
        }
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Not Found !");
}

void main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    p1 = (struct Node *)malloc(sizeof(struct Node));
    p1->data = 10;
    p1->next = NULL;
    p1->prev = NULL;
    head = p1;

    // linkedListTraversal();
    int n;
    int val;
    while (1)
    {
        printf("Enter \n1. Insert At first \n2. Insert At Last \n3. Delete at first \n4. Delete at Last\n5. Search \n6. Display \n7. delete At pos\n");
        scanf("%d", &val);
        switch (val)
        {
        case 1:

            printf("Enter Data to add: ");
            scanf("%d", &n);
            InsertAtFirst(n);
            break;
        case 2:
            printf("Enter Data to add: ");
            scanf("%d", &n);
            InsertAtLast(n);
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
            DeleteAtPos(n);
            break;
        case 8:
            printf("Enter pos to add: ");
            scanf("%d", &n);
            InsertAtPosition(n);
            break;
        }
    }
}
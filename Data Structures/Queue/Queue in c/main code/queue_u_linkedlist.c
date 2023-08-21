#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    char data[20];
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    printf("elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %s\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueue(char val[20])
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        strcpy(n->data, val);
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    char val[20] = "no";
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        strcpy(val,ptr->data);
        free(ptr);
    }
    //return val;
}
 
int main()
{
    linkedListTraversal(f);
    // printf("Dequeuing element %d\n", dequeue());
    enqueue("sai");
    enqueue("ram");
    enqueue("yt");
    enqueue("ram");
    dequeue();
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}

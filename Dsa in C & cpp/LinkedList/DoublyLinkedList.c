#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
}*head;

void linkedListTraversal(){

    struct node *ptr = head;
    if(ptr == NULL){ 
        printf("linked list is empty");
        return;
    }
    while(ptr != head){
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertAtFirst(){
    int n;
    printf("Enter Data to add: ");
    scanf("%d",&n);
    struct node *p = head;
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next=head;
    ptr->pre=NULL;
    p = ptr;
    return p;
}

void insertAtLast(){
    int n;
    printf("Enter Data to add: ");
    scanf("%d",&n);
    struct node *p = head;
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next=NULL;
    while(p->next!=NULL) p = p->next;
    ptr->pre=p;
    p->next=ptr;
}

struct node * DeleteFirst(){
    struct node *p = head;
    printf("Element deleted %d\n",p->data);
    p = p->next;
    p->pre=NULL;
    return p;
}

void DeleteLast(){
    struct node *p = head;
    if (p->next==NULL) {
        printf("Element deleted %d \n",p->data);
        head =NULL; 
        }
    else{
        while(p->next->next!=NULL ) {
            p=p->next;
        }
    printf("Element deleted %d \n",p->next->data);
    p->next= NULL;
    }
}

int main(){
    head = (struct node*)malloc(sizeof(struct node));
    head=NULL;
    
     head = insertAtFirst();
     head = insertAtFirst();
     insertAtLast();
     insertAtLast();
     // linked list after insertion
     linkedListTraversal();
     head = DeleteFirst();
     DeleteLast();
     DeleteLast();

    printf("Circular Linked list after Deletion\n");
    linkedListTraversal();
    return 0;
}
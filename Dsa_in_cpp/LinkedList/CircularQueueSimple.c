#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
}*head,*p1;


void linkedListTraversal()
{
    struct Node* ptr = head;
    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    while (ptr != head);
    printf("\n");
}

void InsertAtFirst(int val){
   struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
   ptr->data=val;
   ptr->next=head;
   head->next=ptr;
   head = ptr;
}

void InsertAtLast(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node *q = head;
    do{
         q=q->next;
    }
    while(q->next!=head);
    q->next=ptr;
    ptr->next=head;
}

void InsertAtPosition(int val,int pos){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node *p = head;
    int k = 1;
    while(k != pos-1 && p->next != head){
        p = p->next;
        k++;
    }
     if (k+1 == pos){
            ptr->next=p->next;
            p->next=ptr;
        }
}

void DeleteAtFirst(){
    struct Node* temp = head;
    struct Node *q = head;
    do{
         q=q->next;
    }
    while(q->next!=head);
    q->next=head->next;
    head = head ->next;
    free(temp);
    //printf("done");
}

void DeleteAtLast(){
    struct Node* temp = head;
    do{
         temp = temp->next;
    }
    while(temp->next->next!=head);
    struct Node* p = temp->next;
    temp->next = head;
    free(p);
}    
void DeleteAtPos(int pos){
    struct Node *p = head;
    int k = 1;
    while(k != pos-1 && p->next != head){
        p = p->next;
        k++;
    }
     if (k+1 == pos){
        struct Node* q = p->next;
        p->next=p->next->next;
        free(q);
        }
}

void Search(int data){
    struct Node *temp = head;
    int count = 1;
    do{
        if(data == temp->data){
            printf("%d is found At %d\n",data,count);
            return;
        }
        count++;
        temp = temp->next;
    }
    while(temp!=head);
    printf("Not Found !");
}

void main(){
     head = (struct Node *)malloc(sizeof(struct Node));
     p1 = (struct Node *)malloc(sizeof(struct Node));
     p1->data=10;
     p1->next=p1;
     head = p1;


    // linkedListTraversal();
    InsertAtFirst(30);
    InsertAtLast(20);
    InsertAtLast(40);
    InsertAtPosition(50,3);
    InsertAtPosition(60,2);
    InsertAtPosition(70,6);
    //InsertAtPosition(90,9);
    linkedListTraversal();
    DeleteAtFirst();
    DeleteAtLast();
    DeleteAtPos(2);
    linkedListTraversal();
    Search(20);
}
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
}*head,*p1;


void linkedListTraversal()
{
    struct Node* ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void InsertAtFirst(int val){
   struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
   ptr->data=val;
   ptr->next=head;
   head = ptr;
}

void InsertAtLast(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node *q = head;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=ptr;
    ptr->next=NULL;
}

void InsertAtPosition(int val,int pos){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=val;
    struct Node *p = head;
    int k = 1;
    while(k != pos-1 && p->next != NULL){
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
    head = head ->next;
    free(temp);
}

void DeleteAtLast(){
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    struct Node* p = temp->next;
    temp->next = NULL;
    free(p);
}    
void DeleteAtPos(int pos){
    struct Node *p = head;
    int k = 1;
    while(k != pos-1 && p->next != NULL){
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
    while(temp!=NULL){
        if(data == temp->data){
            printf("%d is found At %d\n",data,count);
            return;
        }
        count++;
        temp = temp->next;
    }
    printf("Not Found !");
}

void main(){
     head = (struct Node *)malloc(sizeof(struct Node));
     p1 = (struct Node *)malloc(sizeof(struct Node));
     p1->data=10;
     p1->next=NULL;
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
#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *next;
};

struct list * addToEmpty(struct list * head){
    struct list *p=(struct list*)malloc(sizeof(struct list));
    int val;
    printf("Enter the initial value in the linked list:");
    scanf("%d",&val);
    p->data=val;
    p->next=NULL;
    head=p;
    return head;
}

struct list *addAtBeg(struct list *head){
    struct list *ptr=(struct list*)malloc(sizeof(struct list));
    int val;
    scanf("%d",&val);
    ptr->data=val;
    ptr->next=head;
    head=ptr;
    return head;

}

struct list *addAtEnd(struct list *head){
    struct list *temp=(struct list*)malloc(sizeof(struct list));
       int val;
       printf("Enter the value at the end of the linked list:");
       scanf("%d",&val);
       temp->data=val;
       struct list *q = head;
       while(q->next!=NULL){
        q=q->next;
       }
       temp->next=NULL;
       q->next=temp;
       return head;
}


struct list *deleteAtFirst(struct list *head){
    if(head==NULL){
        printf("Linked list is already Empty.");
    }
    else{
        struct list *temp3=head;
        printf("Deleted element is %d",head->data);
        head=head->next;
        free(temp3);
    }
    return head;
}

struct list *deleteAtEnd(struct list *head){
     if(head==NULL){
        printf("Linked list is already Empty.");
    }
    else if(head->next==NULL){
        // free(head);
        head=NULL;
    }
    else{
        struct list *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
           struct list * temp2 =  temp->next;
           temp->next = NULL;
           free(temp2);
    }
 return head; 
}

void display(struct list *head){
    struct list *ptr=head;
    if(ptr==NULL){
        printf("Linked list is empty.");
    }
    else{
    printf("Element in the linked list are:\n");
    while(ptr!=NULL){
        printf("%d -->",ptr->data);
        ptr=ptr->next;
    }
    }
}

int main(){
    struct list *head = NULL;
    int choice;
    while(1){
        printf("\n1.Add at empty\n2.Add at Beg\n3.Add at end\n4.Display\n5.Delete at first\n6.Delete at last\n7.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            head=addToEmpty(head);
            break;

            case 2:
            head=addAtBeg(head); 
            break;

            case 3:
            head=addAtEnd(head); 
            break;

            case 4:
            display(head);
            break;

            case 5:
            head=deleteAtFirst(head); 
            break;

            case 6:
            head=deleteAtEnd(head); 
            break;

            case 7: exit(1);
            break;

            default:printf("Invalid Choice!!!");

        }
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
}*p1,*q;

void linkedListTraversal(){

    struct node *ptr = p1;
    struct node *s = p1;
    do {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
    while(ptr != p1);
        
    
}

void insertAtFirst(){
    int n;
    printf("\nEnter Data to add: ");
    scanf("%d",&n);
    struct node *pt = p1;
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next=pt;
   //1 pt = ptr->next;
   do{
    pt = pt->next;
   } while(pt->next != p1);
    pt->next=ptr;
    ptr->pre=pt; 
    p1 = ptr ;
    //printf("%d",p1->pre->data);
}

void insertAtLast(){
    int n;
    printf("\nEnter Data to add: ");
    scanf("%d",&n);
    struct node *p = p1;
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next=p;
   // p = p->next;
    do{
         p = p->next;
    }
    while(p->next != p1);
    ptr->pre=p;
    p->next=ptr;
}

void DeleteFirst(){
    struct node *p = p1;
    struct node *pt = p1;
    printf("Element deleted %d\n",p->data);
    p = p->next;
    // pt = pt->next;
    do{
        pt = pt->next;
    }
    while(pt->next != p1);
    pt->next=p;
    p->pre=pt;
    p1 = p;
}

void DeleteLast(){
    struct node *p = p1;
    //p=p->next;
    do{  p=p->next; }    
    while(p->next!=p1);
    printf("Element deleted %d \n",p->data);
    struct node *s = p->pre;
    s->next=p1;
    p1->pre=s; 
}

void Search(){
    struct node *p = p1;
    int val;
    printf("\nEnter Data to find: ");
    scanf("%d",&val);
    int count=0;
    while (p->data!=val)
    {
       p=p->next;
       count++; 
    }
    printf("%d is found at postion %d\n",val,count);
}

int main(){
    p1 = (struct node*)malloc(sizeof(struct node));
    q = (struct node*)malloc(sizeof(struct node));
    p1->data=10;
    q->data=20;
    p1->next=q;
    q->next=p1;
    p1->pre=q;
    q->pre=p1;

    int val;
    while(1){
        printf("Enter \n1. Insert At first \n2. Insert At Last \n3. Delete at first \n4. Delete at Last\n5. Search \n6. Display \n7. exit\n");
        scanf("%d",&val);
        switch(val){
            case 1: insertAtFirst();
            break;
            case 2: insertAtLast();
            break;
            case 3: DeleteFirst();
            break;
            case 4: DeleteLast();
            break;
            case 5: Search();
            break;
            case 6: linkedListTraversal();
            break;
            case 7: exit(1);
        }

    }
    return 0;
}
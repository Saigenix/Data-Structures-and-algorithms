//Queue with array and pointer
#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=-1,r=-1;
int queue[size];
int *ptr[size];

void enqueue() {
    int n;
    printf("Enter Element\n");
    scanf("%d",&n);
    if(r==size-1) {
        printf("Queue FULL!!");
    }
    if(front==-1) {
        front=0;
    }
    r++;
    queue[r]=n;
    ptr[r]=&queue[r];
}
void dequeue() {
if(front>r) {
    printf("Queue Empty!!\n");
}
else {
    printf("Element Deleted:%d\n",*ptr[front]);
    front++;
}
}
void display(){
    if(front>r||r==-1) {
        printf("Queue Empty!!\n");
    }
    
    else{
    printf("Queue :\n");
        for(int i=front; i<=r; i++) {
            printf("%d\n",*ptr[i]);

        }

    }
}


int main() {
    int ch;
    while(1) {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&ch);

        switch(ch) {

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        }


    }
}
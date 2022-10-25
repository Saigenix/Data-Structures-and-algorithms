//Queue with array and variables
#include<stdio.h>
#include<stdlib.h>
#define size 3
int front=-1,rear=-1;
int queue[size];

void enqueue() {
    int n;
    printf("Enter Element\n");
    scanf("%d",&n);
    if(rear==size-1) {
        printf("Queue is FULL!!");
        return;
    }
     if(front==-1) {
        front=0;
    }
    rear++;
    queue[rear]=n;
}
void dequeue() {
if(front == -1) {
    printf("Queue Empty!!\n");
    
}
else {
    printf("Element Deleted:%d\n",queue[front]);
    front++;
    if(front>rear){
        front=rear=-1;
    }
}
}
void display(){
    if(front>rear||rear==-1) {
        printf("Queue Empty!!\n");
    }
    
    else{
        for(int i=front; i<=rear; i++) {
            printf("%d\n",queue[i]);

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
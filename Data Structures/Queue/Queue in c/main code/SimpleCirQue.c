#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int arr[SIZE];
int front = -1 ;
int rear = -1 ;

int isFull(){
    if(front == (rear+1)%SIZE){
        return 1;
    }else{
        return 0;
    }
}


int isEmpty(){
    if(front == -1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int val){
    if(isFull()){
        printf("full\n");
    }else{
        if (front == -1) front = 0;
        rear = (rear+1)%SIZE;
        arr[rear]=val;
        printf(" Inserted -> %d \n", val);
    }
}

void Dequeue(){
    if(isEmpty()){
        printf("Empty\n");
    }else{
        printf("%d id deleted\n",arr[front]);
         if (front == rear) {
      front = -1;
      rear = -1;
    }else {
      front = (front + 1) % SIZE;
    }

    }
}

void Display(){
    if(isEmpty()){
        printf("Empty\n");
    }else{
        int i;
        for (i = front; i != rear; i=(i+1)%SIZE){
            printf("%d\n",arr[i]);
        }
        printf("%d\n", arr[i]);
    }
}


void main(){
    //Display();
    enqueue(4);
    enqueue(5);
    Dequeue();
    Dequeue();
    Dequeue();
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    Display();
    Dequeue();
    Dequeue();
    Display();
}
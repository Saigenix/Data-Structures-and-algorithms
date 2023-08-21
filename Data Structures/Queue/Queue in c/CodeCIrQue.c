#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int arr[SIZE];
int front = 0 ;
int rear = 0 ;

int isFull(){
    if(front == (rear+1)%SIZE){
        return 1;
    }else{
        return 0;
    }
}


int isEmpty(){
    if(front == rear){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int val){
    if(isFull()){
        printf("full\n");
    }else{
        rear = (rear+1)%SIZE;
        arr[rear]=val;
        printf(" Inserted -> %d \n", val);
    }
}

void Dequeue(){
    if(isEmpty()){
        printf("Empty\n");
    }else{
        front = (front + 1) % SIZE;
        printf("%d id deleted\n",arr[front]);
    }
}

void Display(){
    if(isEmpty()){
        printf("Empty\n");
    }else{
        int i;
        for (i = front+1; i != rear; i=(i+1)%SIZE){
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
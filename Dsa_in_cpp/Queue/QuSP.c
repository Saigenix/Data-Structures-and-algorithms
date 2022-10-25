//queue using structure and pointer

#include<stdio.h>
#include<stdlib.h>


struct queue {
    int que[5];
    int f;
    int r;

};



void enqueue(struct queue *q1) {
    int num;
    if(q1->f==-1) {
        q1->f=0;
    }
    if(q1->r==4) {
        printf("Queue is Full\n");
    }
    else {
        printf("Enter the element\n");
        scanf("%d",&num);
        q1->r++;
        q1->que[q1->r]=num;

    }

}

int dequeue(struct queue *q1) {
    if(q1->f==-1||q1->f>q1->r) {
        printf("Queue Is Empty\n");
        
    }
    else{
    printf("Element Deleted:%d\n",q1->que[q1->f]);
    q1->f++;
    }
}
int display(struct queue *q1) {
    if(q1->f==-1||q1->f>q1->r) {
        printf("Queue Is Empty\n");
    }
    else {
        for(int i=q1->f; i<=q1->r; i++) {
            printf("%d\n",q1->que[i]);

        }
    }


}
int main() {
struct queue *q1 = (struct queue *) malloc(sizeof(struct queue));

    int ch;
    q1->f=-1;
    q1->r=-1;
    

    while(1){

        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);

        switch(ch) {

        case 1:
            enqueue(q1);
            break;

        case 2:
            dequeue(q1);
            break;

        case 3:
            display(q1);
            break;

        case 4:
            return 0;


        }

    }

}

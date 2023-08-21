#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

int find_max(struct stack *sp){
    int index = sp->top;
    int max = sp->arr[sp->top];
    for (int i = sp->top ; i >= 0 ; i--){
        if (sp->arr[i]>max){
           // sp->arr[i] = max;
            max = sp->arr[i];
            index = i;
        }
    }
    return index;
    }


void pop_max(struct stack* sp){
    int index = find_max(sp);
    printf ("element %d is deleted\n",sp->arr[index]);
    int temp = sp->arr[sp->top];
    int temp2;
    for(int i = sp->top ; i > index ; i--){
     temp2 = sp->arr[i-1];
     sp->arr[i-1] = temp;
     temp = temp2;
     }
    sp->top--;
}

int find_min(struct stack *sp){
 int index = sp->top;
    int min = sp->arr[sp->top];
    for (int i = sp->top ; i >= 0 ; i--){
        if (sp->arr[i]<min){
           // sp->arr[i] = max;
            min = sp->arr[i];
            index = i;
        }
    }
    return index;
    }

void pop_min(struct stack* sp){
 
    int index = find_min(sp);
    printf ("element %d is deleted\n",sp->arr[index]);
    for(int i = index ; i < sp->top ; i++){
     sp->arr[i] = sp->arr[i+1] ;
     }
    sp->top--;
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int stackBottom(struct stack* sp){
    return sp->arr[0];
}


int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    push(sp, 0);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 1);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> Pushed 10 values 
    // push(sp, 46); // Stack Overflow since the size of the stack is 10
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    pop_max(sp);
    pop_min(sp);
     // Printing values from the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    return 0;
}

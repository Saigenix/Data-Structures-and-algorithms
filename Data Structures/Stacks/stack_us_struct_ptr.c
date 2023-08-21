#include <stdio.h>

int num; 
struct stack{
    int stack[5];
    int stk;
}; 
void implement_value(struct stack *s1);
void push(struct stack *s1,int element);
int pop(struct stack *s1); 
void display(struct stack *s1);

int main(){
    int element; 
    struct stack ptr;
    implement_value(&ptr);
    int option;
    while(1){
        printf("\nChoose\n1.Push\n2.Pop\n3.Diaplay\n4.Exit");
        scanf("%d",&option); 
        switch(option){
            case 1:
            printf("Enter the element you want to push in\n");
            scanf("%d",&element);
            push(&ptr,element);
            break;
            case 2:
            pop(&ptr);
            printf("\nThe element popped from stack is : %d", element);
            break;
            case 3:
            display(&ptr);
            break;
            case 4:
            return 0;
            break; 
            default:  
            printf("INVALID OPERATION!!");
        }
    }

}
void implement_value(struct stack *s1){
    s1->stk=-1;
}

void push(struct stack *s1,int num){
    s1->stk++;
    s1->stack[s1->stk]=num;
    printf("%d",num); 
}
int pop(struct stack *s1){
    //printf("Here element is going to be pop out\n");
    num=s1->stack[s1->stk];
    s1->stk--;
    //printf("Element pop is: %d\n",s1->stk);
    return num;
}

void display(struct stack *s1){
    for(int i=s1->stk;i>=0;i--){
        // s1->stack[i]=s1->stack[s1->stk];
        printf("Value now left is: %d\n",s1->stack[i]);
    }        
}

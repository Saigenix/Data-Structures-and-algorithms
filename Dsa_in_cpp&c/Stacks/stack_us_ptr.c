
//Implementing stack using pointers
#include <stdio.h>
int stack[7];
//int stk=-1; 
int *stk=&stack[0];
int ct=0; 
int n=7;

void push();
void pop();
void display();

int main(){
    int option;
    stk--;
    while(1){
        printf("Enter 1.for push\n2.for pop\n3.3.Display\n4.Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
            push();
            break;
            case 2:
            pop();   
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
            break;
            default:
            printf("INVALID OPTION!!!");
        }
    }
    return 0;
}
void push(){
    int element;
    if(ct==7){
        printf("Stack is overflow\n");
    }else{
    stk++;
    ct++;
    printf("Enter the element which you want to push\n");
    scanf("%d",&element);
    *stk=element;
    } 
 }
void pop(){
    if(ct<0){
        printf("Stack is empty\n");
    }else{
    int value=*stk;
    stk--; 
    ct--;
    printf("Deleted element is: %d\n",value);
    }
}
void display(){
    for(int i=0;i<ct;i++){  
        printf("Remaining element is: %d\n",stack[i]);
    }
} 

//Implementing stack using Structure and Array 
#include <stdio.h>
int num;
struct stack{
    int stack[5];
    int stk;
      
};
 
struct stack s1;

//void initialvalue(struct stack s1); 
void push(int num);

int pop();
void display();

int main(){
    s1.stk = -1;
    int element;
    struct stack val;

    int option;
    while(1){   
        printf("\nChoose\n1.Push\n2.Pop\n3.Diaplay\n4.Exit\n");
        scanf("%d",&option); 
        switch(option){
            case 1:
            printf("Enter the element you want to push in\n");
            scanf("%d",&element);
            push(element);
            break;

            case 2:
            pop();
            break;
                           
            case 3:
            display(val);
            break;

            case 4:
            return 0;
            break;  
            default:  
            printf("INVALID OPERATION!!");
        }
    }
}
//  void initialvalue(struct stack s1){
//      s1.stk=-1;
// }

void push(int num){
    s1.stk++;
    s1.stack[s1.stk]=num;
    printf("%d",num); 
}
int pop(){ 
    int ele =  s1.stack[s1.stk];
    s1.stk--; 
    printf("\nThe element popped from stack is : %d", ele);
    return 0;

}

void display(){
    printf("Value now left is: \n");
    for(int i=s1.stk;i>=0;i--){ 
        printf("%d\t", s1.stack[i]);
    }           
}
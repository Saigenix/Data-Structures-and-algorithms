//stack implementation using function
#include <stdio.h>
int stack_arr[15]; 
int stk=-1;

void push(){
    int n;    
    printf("Enter the element to push\n");
    scanf("%d",&n);  
    stack_arr[stk]=n;   
    stk++;
    printf("%d\n",n);  
}  
void pop(){
    printf("Enter the element to pop\n");
    stk--;
    printf("%d\n",stack_arr[stk]);
}
void display(){
    if(stk==-1){
        return;
    }
    for(int i=stk;i>=0;i--){
        printf("\nCurrent element is: %d\t",stack_arr[i]);
    }
}
int main(){ 
    while(1){
        int option;
        printf("Enter \n1.to push the element \n2.to pop the element \n3.exit\n4.display\n");
        scanf("%d",&option);
        switch(option){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            return 0;
            break;
            case 4:
            display();
            break;
            default:
            printf("Invalid Operation!!!");
        }
    }
}

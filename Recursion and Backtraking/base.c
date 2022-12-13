#include<stdio.h>

int arr[3][3] = {{1,1,1},{1,1,1},{1,1,1}};


void fact(int n){
    int f = 1;
    for (int i = n; i > 0; i--)
    {
        /* code */
        f *= i;
    }
    printf("%d",f);
}

int factre(int n){
    if (n==1) return 1;
    return n * factre(n-1);
}

int findPath(int a,int b){
    if(a == 0 && b == 0) return 1;
    if (a< 0 || b< 0) return 0;
    return findPath(a-1,b) + findPath(a,b-1);
}


int fibo(int n){
    if(n <= 1) {
        printf("%d ",n);
        return n ;
        }
    int a = fibo(n-1);
    int b = fibo(n-2);
    printf("%d %d ",a,b);
    return a + b ;
}

void main(){

    //fact(16);
    int f = findPath(4,4);
    printf("%d",f);
}
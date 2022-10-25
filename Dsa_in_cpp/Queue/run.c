#include<stdio.h>
#include<stdlib.h>
int queue[3];
int *f=&queue[0];
int *r=&queue[0];
int p ;
void push() ;
void pop() ;
void display() ;
int main() {
int n;
while(1) {
printf("enter\n") ;
scanf("%d", &n) ;
switch (n) {
case 1:
push() ;
break;
case 2:
pop() ;
break;
case 3:
display() ;
break;
}}}
void push() {
if(r==&queue[3]) {
printf("queue full\n") ;
}
else{
printf("enter to push\n") ;
scanf("%d",&(*r )) ;

r++;
p++;
}}
void pop() {
if(r==&queue[0]) {
printf("queue is empty\n") ;
}
else{


printf("element poped is %d\n", *f) ;
r--;
p--;
int i;
for(i=0;i<p;i++) {
queue[i]=queue[i+1];
}

}

}
void display () {
int i;
for(i=0;i<p;i++) {
printf("%d\n", queue[i]) ;
}
}
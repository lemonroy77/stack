#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node*next;
}node,*stack;
void InitStack(stack &s){
    s=(stack)malloc(sizeof(node));
    s->next=NULL;
}
bool isempty(stack s){
    if(s==NULL) return false;
    if(s->next==NULL) return true;
    else return false;
}
void push(stack &s,ElemType e){
    node*p=(node*)malloc(sizeof(node));
    p->data=e;
    p->next=s->next;
    s->next=p;
}
void pop(stack &s,ElemType &e){
    if(isempty(s)==1) return;
    node*p=s->next;
    s->next=p->next;
    e=p->data;
    free(p);
}
ElemType gettop(stack s){
    if(isempty(s)) return -1;
    return s->next->data;
}
void destroystack(stack &s){
    ElemType e;
    while(!isempty(s)){
        pop(s,e);
    }
    free(s);
    s=NULL;
}
ElemType tail(stack s){
    node*p=s;
    while(p->next!=NULL){
        p=p->next;
    }
    printf("Õ»µ×ÊÇ£º%d\n",p->data);
}
void printstack(stack s){
    node*p=s->next;
    while(p){
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    stack s;
    InitStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    int e;
    tail(s);
    printstack(s);
    pop(s,e);
    printf("Õ»¶¥:%d\n",e);
    pop(s,e);
    printf("Õ»¶¥:%d\n",e);
    pop(s,e);
    printf("Õ»¶¥:%d\n",e);
    destroystack(s);
    return 0;
}
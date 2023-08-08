#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
#define Maxsize 20
typedef struct DNode{
    ElemType data[Maxsize];
    int top;
}SeqStack;
void InitStack(SeqStack &s){
    s.top=-1;
}
bool push(SeqStack &s,ElemType x){
    if(s.top==Maxsize-1) return false;
    s.top=s.top+1;
    s.data[s.top]=x;
    return true;
}
bool pop(SeqStack &s,ElemType &x){
    if(s.top==-1) return false;
    x=s.data[s.top--];
    return true;
}
bool GetTop(SeqStack s,ElemType &e){
    if(s.top==-1) return false;
    e=s.data[s.top];
    return true;
}
void DestroyStack(SeqStack &s){
    s.top=-1;
}
int main(){
    SeqStack s;
    InitStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    return 0;
}

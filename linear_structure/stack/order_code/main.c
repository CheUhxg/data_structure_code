#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType char
#define stack_size 100

typedef struct{
    ElemType elem[stack_size];
    int top;
}mystack;

bool IsEmpty(mystack*S){
    if(S->top==-1){
        printf("Stack is empty.\n");
        return true;
    }
    else return false;
}

bool IsFull(mystack*S){
    if(S->top==stack_size-1){
        printf("Stack is full.\n");
        return true;
    }
    else return false;
}

void InitStack(mystack**SP){
    (*SP)=(mystack*)malloc(sizeof(mystack));
    (*SP)->top=-1;
}

void Push(mystack*S,ElemType value){
    if(IsFull(S))return;
    S->elem[++S->top]=value;
}

bool Pop(mystack*S,ElemType*valuepoint){
    if(IsEmpty(S))return false;
    *valuepoint=S->elem[S->top--];
    return true;
}

bool GetTop(mystack*S,ElemType*valuepoint){
    if(IsEmpty(S))return false;
    *valuepoint=S->elem[S->top];
    return true;
}

int main()
{
    mystack*S;
    int choice,unfinished=1,x;
    ElemType v;

    printf("Please input your command:\n");
    printf("***    0.Exit   \t\t\t***\n");
    printf("***    1.InitStack\t\t\t***\n");
    printf("***    2.Push   \t\t\t***\n");
    printf("***    3.Pop    \t\t\t***\n");
    printf("***    4.GetTop \t\t\t***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitStack(&S);break;
            case 2:
                printf("Please input the value:");
                getchar();
                scanf("%c",&v);
                Push(S,v);
                break;
            case 3:
                if(Pop(S,&v))printf("The value is '%c'\n",v);
                break;
            case 4:
                if(GetTop(S,&v))printf("The value is '%c'\n",v);
                break;

            default:unfinished=0;
        }
        printf("Finished.\n");
    }
    return 0;
}

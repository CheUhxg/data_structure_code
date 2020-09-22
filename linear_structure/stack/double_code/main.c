#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType char
#define stack_size 100

typedef struct{
    ElemType elem[stack_size];
    int top[2];
}mystack;

bool IsEmpty(mystack*S,int side){
    switch(side){
        case 0:
            if(S->top[0]==-1){
                printf("Left stack is empty.\n");
                return true;
            }
            else return false;
            break;
        case 1:
            if(S->top[1]==stack_size){
                printf("Right stack is empty.\n");
                return true;
            }
            else return false;
            break;
    }
}

bool IsFull(mystack*S){
    if(S->top[0]==S->top[1]-1){
        printf("Stack is full.\n");
        return true;
    }
    else return false;
}

void InitStack(mystack**SP){
    (*SP)=(mystack*)malloc(sizeof(mystack));
    (*SP)->top[0]=-1;
    (*SP)->top[1]=stack_size;
}

void Push(mystack*S,ElemType value,int side){
    if(IsFull(S))return;
    switch(side){
        case 0:
            S->elem[++S->top[0]]=value;
            break;
        case 1:
            S->elem[--S->top[1]]=value;
            break;
    }
}

bool Pop(mystack*S,ElemType*valuepoint,int side){
    if(IsEmpty(S,side))return false;
    switch(side){
        case 0:
            *valuepoint=S->elem[S->top[0]--];
            break;
        case 1:
            *valuepoint=S->elem[S->top[1]++];
            break;
    }
    return true;
}

bool GetTop(mystack*S,ElemType*valuepoint,int side){
    if(IsEmpty(S,side))return false;
    switch(side){
        case 0:
            *valuepoint=S->elem[S->top[0]];
            break;
        case 1:
            *valuepoint=S->elem[S->top[1]];
            break;
    }
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
                printf("Please input the side(left-0/right-1):");
                scanf("%d",&x);
                printf("Please input the value:");
                getchar();
                scanf("%c",&v);
                Push(S,v,x);
                break;
            case 3:
                printf("Please input the side(left-0/right-1):");
                scanf("%d",&x);
                if(Pop(S,&v,x))printf("The value is '%c'\n",v);
                break;
            case 4:
                printf("Please input the side(left-0/right-1):");
                scanf("%d",&x);
                if(GetTop(S,&v,x))printf("The value is '%c'\n",v);
                break;

            default:unfinished=0;
        }
        printf("Finished.\n");
    }
    return 0;
}

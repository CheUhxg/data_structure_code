#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType char
#define queue_size 100

typedef struct{
    ElemType elem[queue_size];
    int top,rear;
}myqueue;

bool IsEmpty(myqueue*Q){
    if(Q->top==Q->rear){
        printf("Queue is empty.\n");
        return true;
    }
    else return false;
}

bool IsFull(myqueue*Q){
    if(Q->rear==queue_size-1){
        printf("Queue is full.\n");
        return true;
    }
    else return false;
}

void InitQueue(myqueue**QP){
    (*QP)=(myqueue*)malloc(sizeof(myqueue));
    (*QP)->top=-1;
    (*QP)->rear=-1;
}

void Push(myqueue*Q,ElemType value){
    if(IsFull(Q))return;
    Q->elem[++Q->rear]=value;
}

bool Pop(myqueue*Q,ElemType*valuepoint){
    if(IsEmpty(Q))return false;
    *valuepoint=Q->elem[++Q->top];
    return true;
}

bool GetTop(myqueue*Q,ElemType*valuepoint){
    if(IsEmpty(Q))return false;
    *valuepoint=Q->elem[Q->top+1];
    return true;
}

void ClearQueue(myqueue*Q){
    Q->top=Q->rear=-1;
}

int main()
{
    myqueue*Q;
    int choice,unfinished=1,x;
    ElemType v;

    printf("Please input your command:\n");
    printf("***    0.Exit   \t\t\t***\n");
    printf("***    1.InitQueue\t\t\t***\n");
    printf("***    2.Push   \t\t\t***\n");
    printf("***    3.Pop    \t\t\t***\n");
    printf("***    4.GetTop \t\t\t***\n");
    printf("***    5.ClearQueue\t\t\t***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitQueue(&Q);break;
            case 2:
                printf("Please input the value:");
                getchar();
                scanf("%c",&v);
                Push(Q,v);
                break;
            case 3:
                if(Pop(Q,&v))printf("The value is '%c'\n",v);
                break;
            case 4:
                if(GetTop(Q,&v))printf("The value is '%c'\n",v);
                break;
            case 5:ClearQueue(Q);break;

            default:unfinished=0;
        }
        printf("Finished.\n");
    }
    return 0;
}

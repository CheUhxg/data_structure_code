#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType char

typedef struct{
    ElemType data;
    struct Node*next;
}Node,*LinkQueue;

typedef struct{
    LinkQueue top;
    LinkQueue rear;
}LinkPointer;

void InitQueue(LinkPointer *Q){
    Q->top=(Node*)malloc(sizeof(Node));
    Q->rear=Q->top;
    LinkQueue t=Q->rear;
    t->next=NULL;
}

void Push(LinkPointer*Q,ElemType value){
    LinkQueue t,s;
    t=(Node*)malloc(sizeof(Node));
    t->next=NULL;
    t->data=value;
    s=Q->rear;
    s->next=t;
    Q->rear=t;
}

bool Pop(LinkPointer*Q,ElemType*valuepoint){
    LinkQueue t=Q->top,s;
    t=t->next;
    if(Q->rear==Q->top){
        printf("Queue is empty.\n");
        return false;
    }
    *valuepoint=t->data;
    s=Q->top;
    s->next=t->next;
    if(t==Q->rear){
        Q->rear=Q->top;
    }
    free(t);
    return true;
}

bool GetTop(LinkPointer*Q,ElemType*valuepoint){
    LinkQueue t=Q->top;
    t=t->next;
    if(Q->rear==Q->top){
        printf("Queue is empty.\n");
        return false;
    }
    *valuepoint=t->data;
    return true;
}

void ClearQueue(LinkPointer*Q){
    ElemType value;
    while(Q->rear!=Q->top)Pop(Q,&value);
}

int main()
{
    LinkPointer*Q=(LinkPointer*)malloc(sizeof(LinkPointer));
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
            case 1:InitQueue(Q);break;
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

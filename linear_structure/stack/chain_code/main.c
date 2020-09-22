#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType char

typedef struct{
    ElemType data;
    struct Node*next;
}Node,*Mystack;

void InitStack(Mystack *SP){
    *SP=(Mystack)malloc(sizeof(Node));
    (*SP)->next=NULL;
}

void Push(Mystack S,ElemType value){
    Mystack t;
    t=(Node*)malloc(sizeof(Node));
    t->data=value;
    t->next=S->next;
    S->next=t;
}

bool Pop(Mystack S,ElemType*valuepoint){
    Mystack t=S->next;
    if(t){
        *valuepoint=t->data;
        S->next=t->next;
        free(t);
        return true;
    }
    else{
        printf("Stack is empty.\n");
        return false;
    }
}

int main()
{
    Mystack S;
    int choice,unfinished=1,x;
    ElemType v;

    printf("Please input your command:\n");
    printf("***    0.Exit   \t\t\t***\n");
    printf("***    1.InitStack\t\t\t***\n");
    printf("***    2.Push   \t\t\t***\n");
    printf("***    3.Pop    \t\t\t***\n");

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

            default:unfinished=0;
        }
        printf("Finished.\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define ElemType char

typedef struct{
    ElemType data;
    struct Node *prior,*next;
}Node,*LinkList;


void InitLink(LinkList *LP){
    *LP=(LinkList)malloc(sizeof(Node));
    (*LP)->next=NULL;
    (*LP)->prior=NULL;
}

void CreateLink(LinkList L){
    LinkList p=L,t;
    ElemType value;

    while(1){
        printf("Please input element(end with '$'):");
        getchar();
        value=getchar();
        if(value=='$')break;
        t=(Node*)malloc(sizeof(Node));
        t->data=value;
        p->next=t;
        t->prior=p;
        p=p->next;
    }
    p->next=NULL;
}

void InsLink(LinkList L,int i,ElemType value){
    //编译器报错 只能用别的变量表示p的前后
    LinkList p=L,t,s;

    for(int j=0;j<i&&p;j++)p=p->next;
    if(!p){
        printf("The index is out of range.\n");
        return;
    }
    s=p->prior;
    t=(LinkList)malloc(sizeof(Node));
    t->data=value;
    t->prior=s;
    s->next=t;
    t->next=p;
    p->prior=t;
}

void DelLink(LinkList L,int i){
    //编译器报错 只能用别的变量表示p的前后
    LinkList p=L,s,t;

    for(int j=0;j<i&&p;j++)p=p->next;
    if(p)printf("The value is '%c'\n",p->data);
    else{
        printf("The index is out of range.\n");
        return;
    }
    s=p->prior;
    t=p->next;
    s->next=p->next;
    s->prior=p->prior;
    free(p);
}

void Locate(LinkList L,int i){
    LinkList p=L;

    for(int j=0;j<i&&p;j++)p=p->next;
    if(p)printf("The value is '%c'\n",p->data);
    else{
        printf("The index is out of range.\n");
        return;
    }
}

int main()
{
    LinkList L,L1,L2;
    int choice,unfinished=1,x;
    ElemType v;

    printf("Please input your command:\n");
    printf("***    0.Exit   \t\t\t***\n");
    printf("***    1.InitLink\t\t\t***\n");
    printf("***    2.CreateLink\t\t\t***\n");
    printf("***    3.InsLink\t\t\t***\n");
    printf("***    4.DelLink \t\t\t***\n");
    printf("***    5.Locate  \t\t\t***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitLink(&L);break;
            case 2:CreateLink(L);break;
            case 3:
                printf("Please input the index:");
                scanf("%d",&x);
                printf("Please input the value:");
                getchar();
                scanf("%c",&v);
                InsLink(L,x,v);
                break;
            case 4:
                printf("Please input the index:");
                scanf("%d",&x);
                DelLink(L,x);
                break;
            case 5:
                printf("Please input the index:");
                scanf("%d",&x);
                Locate(L,x);
                break;

            default:unfinished=0;
        }
        printf("Finished.\n");
    }

    return 0;
}

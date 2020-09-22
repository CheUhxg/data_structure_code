#include <stdio.h>
#include <stdlib.h>
#define ElemType char
typedef struct{
    ElemType data;
    int length;
    struct Node*next;
}Node,*LinkList;

void InitLink(LinkList *LP){
    *LP=(LinkList)malloc(sizeof(Node));
    (*LP)->length=0;
    (*LP)->next=NULL;
}

void CreateFromHead(LinkList L){
    LinkList t;
    ElemType ch;
    while(1){
        printf("Please input element(end with '$'):");
        getchar();
        ch=getchar();
        if(ch=='$')break;
        t=(Node*)malloc(sizeof(Node));
        t->data=ch;
        t->next=L->next;
        L->next=t;
        L->length++;
    }
}

void CreateFromTail(LinkList L){
    LinkList p=L,t;
    ElemType ch;
    while(1){
        printf("Please input element(end with '$'):");
        getchar();
        ch=getchar();
        if(ch=='$')break;
        t=(Node*)malloc(sizeof(Node));
        t->data=ch;
        p->next=t;
        p=p->next;
        L->length++;
    }
    p->next=NULL;
}

LinkList Locate(LinkList L,ElemType value){
    LinkList p=L;
    while(p){
        if(p->data==value){
            return p;
        }
        p=p->next;
    }
    printf("Can't find the value.\n");
    return NULL;
}

ElemType Get(LinkList L,int i){
    LinkList p=L;
    for(int j=0;j<i;j++){
        p=p->next;
    }
    return p->data;
}

void DelList(LinkList L,int i){
    L->length--;
    LinkList p=L,pre;
    for(int j=0;j<i;j++){
        pre=p;
        p=p->next;
    }
    pre->next=p->next;
    printf("The value is %c\n",p->data);
    free(p);
}

void InsList(LinkList L,int i,ElemType value){
    L->length++;
    LinkList p=L,t;
    for(int j=0;j<i-1;j++){
        p=p->next;
    }
    t=(LinkList*)malloc(sizeof(Node));
    t->data=value;
    t->next=p->next;
    p->next=t;
}

LinkList MergeList(LinkList L1,LinkList L2){
    LinkList L;
    InitLink(&L);
    L->next=L1->next;
    while(L1->next!=NULL){
        L1=L1->next;
    }
    L1->next=L2->next;
    L->length=L1->length+L2->length;
    return L;
}

int main()
{
    LinkList L,L1,L2;
    int choice,unfinished=1,x;
    ElemType v;

    printf("Please input your command:\n");
    printf("***    0.Exit   \t\t\t***\n");
    printf("***    1.InitLink\t\t\t***\n");
    printf("***    2.CreateFromHead\t\t\t***\n");
    printf("***    3.CreateFromTail\t\t\t***\n");
    printf("***    4.Locate \t\t\t***\n");
    printf("***    5.Get    \t\t\t***\n");
    printf("***    6.DelList \t\t\t***\n");
    printf("***    7.InsList\t\t\t***\n");
    printf("***    8.MergeList\t\t\t***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitLink(&L);break;
            case 2:CreateFromHead(L);break;
            case 3:CreateFromTail(L);break;
            case 4:
                printf("Please input the value:");
                getchar();
                scanf("%c",&v);
                if(Locate(L,v)){
                    printf("the value is in <%p>\n",Locate(L,v));
                }
                break;
            case 5:
                printf("Please input the index:");
                scanf("%d",&x);
                if(x>L->length||x<=0)printf("Can't find.\n");
                else printf("The value is '%c'\n",Get(L,x));
                break;
            case 6:
                printf("Please input the index:");
                scanf("%d",&x);
                if(x>L->length)printf("Out of range.\n");
                else DelList(L,x);
                break;
            case 7:
                printf("Please input the index:");
                scanf("%d",&x);
                printf("Please input the value:");
                getchar();
                scanf("%c",&v);
                InsList(L,x,v);
                break;
            case 8:
                InitLink(&L1);
                InitLink(&L2);
                printf("Initialize the L1(tail):\n");
                CreateFromTail(L1);
                printf("Initialize the L2(tail):\n");
                CreateFromTail(L2);
                L=MergeList(L1,L2);
                break;
            default:unfinished=0;
        }
        printf("Finished.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define ElemType char

typedef struct{
    ElemType data;
    struct Node*next;
}Node,*LinkList;

void InitLink(LinkList *LP){
    *LP=(LinkList)malloc(sizeof(Node));
    (*LP)->length=0;
    (*LP)->next=*LP;
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
        p=p->next;
    }
    p->next=L;
}

LinkList MergeLink(LinkList L1,LinkList L2){
    LinkList p1=L1,p2=L2;
    while(p1->next!=L1)p1=p1->next;
    while(p2->next!=L2)p2=p2->next;
    p1->next=L2->next;
    p2->next=L1;
    free(L2);
    return L1;
}

void Locate(LinkList L,int i){
    LinkList p=L->next;
    for(int j=0;j<i-1&&p!=L;j++){
        p=p->next;
    }
    if(p==L)printf("The index is out of range.\n");
    else printf("The value is '%c'\n",p->data);
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
    printf("***    3.MergeLink\t\t\t***\n");
    printf("***    4.Locate \t\t\t***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitLink(&L);break;
            case 2:CreateLink(L);break;
            case 3:
                InitLink(&L1);
                InitLink(&L2);
                printf("Initialize the L1:\n");
                CreateLink(L1);
                printf("Initialize the L2:\n");
                CreateLink(L2);
                L=MergeLink(L1,L2);
                break;
            case 4:
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

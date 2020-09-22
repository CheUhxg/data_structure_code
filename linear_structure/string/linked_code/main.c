#include <stdio.h>
#include <stdlib.h>
#define BlOCK_SIZE 4
#define ElemType char

typedef struct Block{
    ElemType b[BlOCK_SIZE];
    struct Block*next;
}Block;

typedef struct{
    Block*head;
    Block*tail;
    int length;
}BlockString;

void InitBlock(BlockString *B){
    B->length=0;
    B->head=(Block*)malloc(sizeof(Block));
    B->tail=B->head;
    Block* t=B->tail;
    t->next=NULL;
}

void BlockLength(BlockString*B){
    printf("Block's length is %d\n",B->length);
}

void GetData(BlockString*B,int i){
    if(B->length<i){
        printf("The index is out of range.\n");
        return;
    }
    Block*p=B->head;
    for(;i>0;i--)p=p->next;
    printf("The value is '%s'\n",p->b);
}

void InsBlock(BlockString*B,int i,ElemType*value){
    int flag=0;
    Block *t=(Block*)malloc(sizeof(Block)),*p=B->head;
    B->length++;
    for(int j=0;j<BlOCK_SIZE;j++){
        if(value[j]=='\0'){
            flag=1;
        }
        if(flag){
            t->b[j]='#';
        }else{
            t->b[j]=value[j];
        }
    }
    for(;i>1;i--)p=p->next;
    t->next=p->next;
    p->next=t;
}

void DelBlock(BlockString*B,int i){
    if(B->length<i){
        printf("The index is out of range.\n");
        return;
    }
    Block*p=B->head,*t;
    for(;i>1;i--)p=p->next;
    t=p->next;
    printf("The value is '%s'\n",t->b);
    p->next=t->next;
    free(p);
}

int main()
{
    BlockString *B=(BlockString *)malloc(sizeof(BlockString));
    int choice,unfinished=1,x;
    ElemType*v=(ElemType*)malloc(sizeof(char)*BlOCK_SIZE);

    printf("Please input your command:\n");
    printf("***    0.Exit         ***\n");
    printf("***    1.InitList     ***\n");
    printf("***    2.BlockLength   ***\n");
    printf("***    3.GetData      ***\n");
    printf("***    4.InsList      ***\n");
    printf("***    5.DelList      ***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitBlock(B);break;
            case 2:BlockLength(B);break;
            case 3:
                printf("Please input the index:");
                scanf("%d",&x);
                GetData(B,x);
                break;
            case 4:
                printf("Please input the index:");
                scanf("%d",&x);
                printf("Please input the value:");
                getchar();
                gets(v);
                InsBlock(B,x,v);
                break;
            case 5:
                printf("Please input the index:");
                scanf("%d",&x);
                DelBlock(B,x);
                break;


            default:unfinished=0;
        }
        printf("Finished.\n");
    }
    return 0;
}

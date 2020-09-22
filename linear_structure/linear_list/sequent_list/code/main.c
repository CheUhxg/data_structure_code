#include<stdio.h>
#include<stdbool.h>
#define Initlength 100
typedef struct{
    int *list;
    int length;
    int size;
}linear_list;

void InitList(linear_list*L){
    L->list=(int*)malloc(sizeof(int)*Initlength);
    memset(L->list,0,sizeof(int)*L->length);
    L->length=0;
    L->size=Initlength;
}

void ListLength(linear_list*L){
    printf("This list's length is %d\n",L->length);
}

void GetData(linear_list*L,int i){
    printf("%d\n",L->list[i]);
}

void InsList(linear_list*L,int i,int value){
    for(int j=i+1;j<=L->length;j++){
        L->list[j]=L->list[j-1];
    }
    L->list[i]=value;
    L->length++;
}

void DelList(linear_list*L,int i){
    printf("Deleted value is %d\n",L->list[i]);
    for(int j=i;j<L->length-1;j++){
        L->list[j]=L->list[j+1];
    }
    L->length--;
}

void Locate(linear_list*L,int value){
    for(int j=0;j<L->length;j++){
        if(L->list[j]==value){
            printf("The index is %d\n",j);
        }else if(j==L->length-1){
            printf("Can't find value %d\n",value);
        }
    }
}

void DestroyList(linear_list*L){
    L->size=0;
    L->length=0;
    free(L->list);
}

void ClearList(linear_list*L){
    memset(L->list,0,sizeof(int)*L->length);
}

bool EmptyList(linear_list*L){
    if(L->length){
        return false;
    }else{
        return true;
    }
}

int main(){
    linear_list *L=(linear_list *)malloc(sizeof(linear_list));
    int choice,unfinished=1,x,v;

    printf("Please input your command:\n");
    printf("***    0.Exit         ***\n");
    printf("***    1.InitList     ***\n");
    printf("***    2.ListLength   ***\n");
    printf("***    3.GetData      ***\n");
    printf("***    4.InsList      ***\n");
    printf("***    5.DelList      ***\n");
    printf("***    6.Locate       ***\n");
    printf("***    7.DestroyList  ***\n");
    printf("***    8.ClearList    ***\n");
    printf("***    9.EmptyList    ***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitList(L);break;
            case 2:ListLength(L);break;
            case 3:
                printf("Please input the index:");
                scanf("%d",&x);
                GetData(L,x);
                break;
            case 4:
                printf("Please input the index:");
                scanf("%d",&x);
                printf("Please input the value:");
                scanf("%d",&v);
                InsList(L,x,v);
                break;
            case 5:
                printf("Please input the index:");
                scanf("%d",&x);
                DelList(L,x);
                break;
            case 6:
                printf("Please input the value:");
                scanf("%d",&v);
                Locate(L,v);
                break;
            case 7:
                DestroyList(L);
                break;
            case 8:
                ClearList(L);
                break;
            case 9:
                if(EmptyList(L)){
                    printf("True.\n");
                }
                else{
                    printf("False.\n");
                }
                break;
            default:unfinished=0;
        }
        printf("Finished.\n");
    }



    return 0;
}

#include<stdio.h>
#include<stdbool.h>
#define ElemType char
#define Initlength 100
typedef struct{
    ElemType *list;
    int length;
    int size;
}mystring;

void InitString(mystring*S){
    S->list=(ElemType*)malloc(sizeof(ElemType)*Initlength);
    S->length=0;
    S->size=Initlength;
}

void StringLength(mystring*S){
    printf("This list's length is %d\n",S->length);
}

void GetData(mystring*S,int i){
    printf("%c\n",S->list[i]);
}

void InsString(mystring*S,int i,ElemType value){
    for(int j=i+1;j<=S->length;j++){
        S->list[j]=S->list[j-1];
    }
    S->list[i]=value;
    S->length++;
}

void DelString(mystring*S,int i){
    printf("Deleted value is %d\n",S->list[i]);
    for(int j=i;j<S->length-1;j++){
        S->list[j]=S->list[j+1];
    }
    S->length--;
}

void Locate(mystring*S,ElemType value){
    for(int j=0;j<S->length;j++){
        if(S->list[j]==value){
            printf("The index is %d\n",j);
        }else if(j==S->length-1){
            printf("Can't find value %c\n",value);
        }
    }
}

bool BruteForce(mystring*S1,mystring*S2){
    int i1,i2;
    for(i1=0;i1<S1->length;i1++){
            for(i2=0;i2<S2->length;i2++){
                if(S1->list[i1]!=S2->list[i2])break;
            }
            if(i2==S2->length) return true;
    }
    return false;
}

bool KMP(mystring*S1,mystring*S2){
    int i=0,j=0,n=S1->length,m=S2->length,k=-1,next[S2->length];
    next[0]=-1;
    while(j<n){
        if(k==-1||S2->list[j]==S2->list[k]){
            next[++j]=++k;
        }
        else k=next[k];
    }
    while(i<=n-m){
        while(j==-1||(S2->list[j]==S1->list[i]&&j<m)){
            i++;j++;
        }
        if(j==m)return true;
        else j=next[j];
    }
    return false;
}

bool CompareString(mystring*S1,mystring*S2){
    int i1,i2;
    for(i1=0,i2=0;i1<S1->length&&i2<S2->length;i1++,i2++){
        if(S1->list[i1]!=S2->list[i2])break;
    }
    if(i1==S1->length&&i2==S2->length)return true;
    else return false;
}

int main(){
    mystring *S=(mystring *)malloc(sizeof(mystring));
    mystring *Sp=(mystring *)malloc(sizeof(mystring));
    int choice,unfinished=1,x,stop=0;
    ElemType v;

    printf("Please input your command:\n");
    printf("***    0.Exit           ***\n");
    printf("***    1.InitString     ***\n");
    printf("***    2.StringLength   ***\n");
    printf("***    3.GetData        ***\n");
    printf("***    4.InsString      ***\n");
    printf("***    5.DelString      ***\n");
    printf("***    6.Locate         ***\n");
    printf("***    7.BruteForce     ***\n");
    printf("***    8.KMP            ***\n");
    printf("***    9.CompareString  ***\n");

    while(unfinished){
        scanf("%d",&choice);
        switch(choice){
            case 1:InitString(S);break;
            case 2:StringLength(S);break;
            case 3:
                printf("Please input the index:");
                scanf("%d",&x);
                GetData(S,x);
                break;
            case 4:
                printf("Please input the index:");
                scanf("%d",&x);
                printf("Please input the value:");
                getchar();
                v=getchar();
                InsString(S,x,v);
                break;
            case 5:
                printf("Please input the index:");
                scanf("%d",&x);
                DelString(S,x);
                break;
            case 6:
                printf("Please input the value:");
                getchar();
                v=getchar();
                Locate(S,v);
                break;
            case 7:
                printf("Initialize the S':\n");
                InitString(Sp);
                for(int i=0;!stop;i++){
                    printf("Please input the value:");
                    getchar();
                    v=getchar();
                    InsString(Sp,i,v);
                    printf("Do you want to stop?[1/0]");
                    scanf("%d",&stop);
                }
                if(BruteForce(S,Sp))printf("S' is S's substring.\n");
                else printf("S' is not S's substring.\n");
                break;
            case 8:
                printf("Initialize the S':\n");
                InitString(Sp);
                for(int i=0;!stop;i++){
                    printf("Please input the value:");
                    getchar();
                    v=getchar();
                    InsString(Sp,i,v);
                    printf("Do you want to stop?[1/0]");
                    scanf("%d",&stop);
                }
                if(KMP(S,Sp))printf("S' is S's substring.\n");
                else printf("S' is not S's substring.\n");
                break;
            case 9:
                printf("Initialize the S':\n");
                InitString(Sp);
                for(int i=0;!stop;i++){
                    printf("Please input the value:");
                    getchar();
                    v=getchar();
                    InsString(Sp,i,v);
                    printf("Do you want to stop?[1/0]");
                    scanf("%d",&stop);
                }
                if(CompareString(S,Sp))printf("Compared.\n");
                else printf("Not compared.\n");
                break;
            default:unfinished=0;
        }
        stop=0;
        printf("Finished.\n");
    }



    return 0;
}

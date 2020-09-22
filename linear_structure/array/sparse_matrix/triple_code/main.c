#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define ElemType int

typedef struct{
    int row,col;
    ElemType value;
}Triple;

typedef struct{
    Triple data[MAXSIZE+1];
    int r_num,c_num,len;
}TMarix;

int main()
{
    TMarix T,Tp;
    ElemType m[4][4];
    int num[MAXSIZE+1],pos[MAXSIZE+1],col,p,q;
    memset(pos,0,sizeof(pos));
    memset(num,0,sizeof(num));

    T.len=0;
    printf("Please input your matrix:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&m[i][j]);
            if(m[i][j]){
                T.data[++T.len].value=m[i][j];
                T.data[T.len].row=i+1;
                T.data[T.len].col=j+1;
            }
        }
    }
    for(int i=1;i<=T.len;i++){
        printf("row:%d\tcol:%d\tvalue:%d\n",T.data[i].row,T.data[i].col,T.data[i].value);
    }
    printf("Let's transpose the matrix.\n");
    pos[1]=1;
    for(int i=1;i<=T.len;i++){
        num[T.data[i].col]++;
    }
    for(int i=2;i<=T.len;i++){
        pos[i]=pos[i-1]+num[i-1];
    }
    for(p=1;p<=T.len;p++){
        col=T.data[p].col;
        q=pos[col];
        Tp.data[q].row=T.data[p].col;
        Tp.data[q].col=T.data[p].row;
        Tp.data[q].value=T.data[p].value;
        pos[col]++;
    }
    for(int i=1;i<=T.len;i++){
        printf("row:%d\tcol:%d\tvalue:%d\n",Tp.data[i].row,Tp.data[i].col,Tp.data[i].value);
    }
    return 0;
}

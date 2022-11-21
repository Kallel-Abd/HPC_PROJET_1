#include <stdio.h>
#include <stdlib.h>

void sliceArrayCol(int *A, int start,int end,int lineSize,int colSize){
    int *oldA=A;
    //oldA[i][j]=oldA[i*lineSize+j]
    A=(int*)malloc(sizeof(int)*((end-start+1)*colSize));
    for (int i = 0; i < lineSize; i++)
    {
        for (int j = start; j < end+1; j++)
        {
            A[i*colSize+j]=oldA[i*colSize+j];
            //A[i*colSize+j]=22;

        }   
    }
}

void afficheTable(int*  A,int m ,int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",A[i*n+j]);
        }
        printf("\n");
    }
    
}

int main(){

    int A[15]={
        10,20,30,40,50,
        11,21,31,41,51,
        12,22,32,42,52
    };
    afficheTable(A,3,3);
    sliceArrayCol(A,1,3,3,5);
    printf("\n");
    afficheTable(A,3,5);

    return 0;
}
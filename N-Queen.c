#include<stdio.h>
int matrix[1000][1000];

int noAttack(int column,int row,int n){    //function to check if queen is placeable in a particular block
    int i,j;
    for (i = 0; i < column; i++){
        if (matrix[row][i])
            return 0;
    }

    for (i=row, j=column; i>=0 && j>=0; i--, j--){
        if (matrix[i][j])
            return 0;
    }

    for (i=row, j=column; j>=0 && i<n; i++, j--){
        if (matrix[i][j])
            return 0;
    }

    return 1;
}

int NQ(int column,int n){
    if(column >= n)
        return 1;
    else{
        for(int i = 0;i < n;i++){
            if(noAttack(column,i,n)){
                matrix[i][column] = 1;
                if(NQ(column + 1,n))    //recursively checking if next column can be used
                    return 1;
                matrix[i][column] = 0;  //if next column can't be used then backtrack
            }
        }
        return 0;
    }
}

int main(){
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            matrix[i][j] = 0;
    }

    int solution = NQ(0,n);
    if(solution == 0)
        printf("No solution ...");
    else{
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                printf("%d ",matrix[i][j]);
            printf("\n");
        }
    }
    return 0;
}

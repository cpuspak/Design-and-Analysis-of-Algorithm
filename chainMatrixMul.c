#include<stdio.h>
#include<limits.h>
int chainMultiplication(int p[], int n){
    int a[n][n];
    int i, j, k, L, q;
    for (i=1; i<n; i++)
        a[i][i] = 0;
    for (L=2; L<n; L++){
        for (i=1; i<n-L+1; i++){
            j = i+L-1;
            a[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++){
                q = m[i][k] + a[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    a[i][j] = q;
            }
        }
    }
    return a[1][n-1];
}
 
int main(){
    int a[100],n;
    printf("Enter no of eles : ");
    scanf("%d",&n);
    printf("Enter dimentions : ");
    for(int i = 0;i<n+1;i++)
        scanf("%d",&a[i]);
    printf("Min %d ",chainMultiplication(a, n+1));
    return 0;
}
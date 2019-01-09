#include <stdio.h>
void display(int *a,int n){
    for(int i = 0;i < n;i++)
        printf(" %d ",a[i]);
    printf("\n");
}
void swap(int *a,int j,int k){
    int temp = a[j];a[j] = a[k];a[k] = temp;
}
int partition(int *a,int first,int last){
    int refEle = a[first],i,j = first + 1,k = last;
    while(j <= k){
        while(a[j] <= a[first])
            j++;
        while(a[k] > a[first])
            k--;
        if(j < k)
            swap(a,j,k);
    }
    swap(a,first,k);
    return k;
}
void quickSort(int *a,int first,int last){
    if(first < last){
        int p = partition(a,first,last);
        quickSort(a,first,p);
        quickSort(a,p+1,last);
    }
}
int main(){
    int a[1000],n,i;
    printf("Enter no of eles : ");
    scanf("%d",&n);
    printf("Enter eles separated by space : ");
    for(i = 0;i<n;i++)
        scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    display(a,n);
    return 0;
}

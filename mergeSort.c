#include <stdio.h>
void display(int *a,int n){
    for(int i = 0;i < n;i++)
        printf(" %d ",a[i]);
    printf("\n");
}

void merge(int *a,int first,int mid,int last){
    int i,j,k,a1[1000],a2[1000],n1 = mid - first + 1,n2 = last - mid;
    for (i = 0; i < n1; i++)
        a1[i] = a[first + i];
    for (j = 0; j < n2; j++)
        a2[j] = a[mid + 1+ j];
    j = 0,k = first,i=0;
     while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            a[k] = a1[i++];
        else
            a[k] = a2[j++];
        k++;
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}

void mergeSort(int *a,int first,int last){
    if(first < last){
        int mid = (first + last)/2;
        mergeSort(a,first,mid);
        mergeSort(a,mid+1,last);
        merge(a,first,mid,last);
    }
}

int main(){
    int a[1000],n,i;
    printf("Enter no of eles : ");
    scanf("%d",&n);
    printf("Enter eles separated by space : ");
    for(i = 0;i<n;i++)
        scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    display(a,n);
    return 0;
}

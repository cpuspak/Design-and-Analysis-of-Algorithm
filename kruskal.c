#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct set{
    int **set_,*eleCount,totalCount;
}set;

set Set;

void show(int **edges,int e){
    for(int i = 0;i < e;i++){
        printf("%d %d %d",edges[i][0],edges[i][1],edges[i][2]);
        printf("\n");
    }
}

int **sorted(int **edges,int e){
    for(int i = 0;i < e;i++){
        for(int j = 0;j < e - i - 1;j++){
            if(edges[j][2] > edges[j + 1][2]){  //sorting the given edge matrix
                int temp = edges[j][0];
                edges[j][0] = edges[j + 1][0];
                edges[j + 1][0] = temp;

                temp = edges[j][1];
                edges[j][1] = edges[j + 1][1];
                edges[j + 1][1] = temp;

                temp = edges[j][2];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][2] = temp;
            }
        }
    }
    return edges;
}

bool inSet(int ele){  //this function checks if two ele are in same set
    int set = -1;
    for(int i = 0;i < Set.totalCount && set == -1;i++){
        for(int j = 0;j < Set.eleCount[i];j++){
            if(ele == Set.set_[i][j]){
                set = i;
                break;
            }
        }
    }
    if(set == -1){
        if(Set.totalCount == 0){
            Set.eleCount = (int *)malloc(sizeof(int));
            Set.eleCount[0] = 1;
            Set.set_ = (int  **)malloc(sizeof(int *));
            for(int i = 0;i < Set.eleCount[0];i++)
                Set.set_[i] = (int *)malloc(sizeof(int));
            Set.set_[0][0] = ele;
            set = 0;
        }
        else{
            Set.eleCount = (int *)realloc(Set.eleCount, sizeof(int)*(Set.totalCount + 1));
            Set.eleCount[Set.totalCount] = 1;
            Set.set_ = (int **)realloc(Set.set_,sizeof(int *)*(Set.totalCount + 1));
            Set.set_[Set.totalCount] = (int *)malloc(sizeof(int));
            Set.set_[Set.totalCount][0] = ele;
            set = Set.totalCount;
        }
        Set.totalCount += 1;
    }
    return set;
}

int **KruskalMST(int **edges,int e,int n){
    int **MST = (int **)malloc((n - 1) * sizeof(int *));   //the Minimal Spanning tree
    for(int i = 0;i < n-1;i++)
        MST[i] = (int *)malloc(3 * sizeof(int));
    int count = 0;
    for(int i = 0;i < e;i++){
        int first = inSet(edges[i][0]);
        int second = inSet(edges[i][1]);
        printf("f==s==> %d %d %d\n",first,second,Set.totalCount);
        if(first != second){   //checking for any loops by seeing if start and
            MST[count][0] = edges[i][0];                      //end vertices are in same set
            MST[count][1] = edges[i][1];                      //if no loop found then adding them to MST
            MST[count][2] = edges[i][2];
            count++;
        }
        if(count == n - 1)
            break;
    }
    return MST;
}


int main(){
    Set.totalCount = 0;
    int n,e;
    printf("Enter no of vertices :");
    scanf("%d",&n);
    printf("Enter no of edges : ");
    scanf("%d",&e);
    int **edges = (int **)malloc(e * sizeof(int *));
    for (int i=0; i<e; i++)
         edges[i] = (int *)malloc(3 * sizeof(int));
    printf("Enter edges and weights : ");
    for(int i = 0;i < e;i++)
        scanf("%d %d %d",&edges[i][0],&edges[i][1],&edges[i][2]);
    edges = sorted(edges,e);
    /*
    int **MST = (int **)malloc((n - 1) * sizeof(int *));
    for(int i = 0;i < n-1;i++)
        MST[i] = (int *)malloc(3 * sizeof(int));
    */
    int **MST = KruskalMST(edges,e,n);
    printf("\n");
    show(MST,n - 1);
    return 0;

}

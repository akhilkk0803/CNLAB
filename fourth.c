// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
int main() {
    // Write C code here
    int n,e;
    printf("Enter number of nodes and edges");
    scanf("%d %d",&n,&e);
    int edges[e][3]
    int source=0;
    for(int i=0;i<e;i++){
        int u,v,cost;
        printf("Enter u v and cost between u and v");
        scanf("%d%d%d",&u,&v,&cost);
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=cost;
    }
    printf("Enter Source");
    scanf("%d",&source);
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=1e9;
    }
    ans[source]=0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<e;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int c=edges[j][2];
            if(ans[u]+c<ans[v]){
                ans[v]=ans[u]+c;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    
    
    return 0;
}

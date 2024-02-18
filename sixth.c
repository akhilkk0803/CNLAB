// Online C compiler to run C program online
#include <stdio.h>
void print(int arr[]){
    for(int i=1;i<8;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    // Write C code here
    int h[8]={0},r[8]={0};
    printf("Enter 4bits of data");
    scanf("%d %d %d %d",&h[3],&h[5],&h[6],&h[7]);
    h[1]=h[3]^h[5]^h[7];
    h[2]=h[3]^h[6]^h[7];
    h[4]=h[5]^h[6]^h[7];
    printf("Enter bits at receving end");
    for(int i=1;i<8;i++){
        scanf("%d",&r[i]);
    }
    int p1=r[1]^r[3]^r[5]^r[7];
    int p2=r[2]^r[3]^r[6]^r[7];
    int p4=r[4]^r[5]^r[6]^r[7];
    int error=p1*1+p2*2+p4*4;
    if(error==0)printf("NO ERROR");
    else {
        printf("ERROR AT %d BIT",error);
        printf("RECEIVED DATA");
        print(r);
        printf("\n");
        r[error]=!r[error];
        print(r);
    }
    return 0;
}

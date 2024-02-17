#include <stdio.h>
void goBackNArq(int frames,int wz){
    int i=1;
    while(i<=frames){
        for(int temp=i;temp<i+wz && temp<=frames ;temp++){
            printf("SENDING FRAME %d\n",temp);
        }
        for(int j=0;j<wz && i<=frames;j++){
            int r=rand();
            if(r%2){
                printf("ACK Recived for frame %d\n",i);
                i++;
            }
            else {
                printf("ACK NOT RECEIVED for frame %d \n",i);
                break;
            }
        }
        printf("RETRANSMITTING WINDOW\n");
    }
}
void selective(int frames,int wz){
     int i=1;
    while(i<=frames){
        for(int temp=i;temp<i+wz && temp<=frames ;temp++){
            printf("SENDING FRAME %d\n",temp);
        }
        for(int j=0;j<wz && i<=frames;j++){
            int r=rand();
            if(r%2){
                printf("ACK Recived for frame %d\n",i);
                i++;
            }
            else {
                printf("ACK NOT RECEIVED for frame %d \n",i);
                printf("Sending Back frame %d\n",i);
                printf("ACK  RECEIVED for frame %d\n",i);
                i++;
            }
        }
        printf("RETRANSMITTING WINDOW\n");
    }
}
int main() {
    // Write C code here
    int frames,wz;
    printf("Enter frames and window size");
    scanf("%d %d",&frames,&wz);
    goBackNArq(frames,wz);
    selective(frames,wz);
    return 0;
}

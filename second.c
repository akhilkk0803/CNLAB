#include <stdio.h>
#include<string.h>

int firstBlockAdd(char s[]){
    int curr=0;
    for(int i=0;s[i]!='.';i++){
        curr*=10;
        curr+=s[i]-'0';
    }
    return curr;
}
char getClass(int i){
    if(i<128)return 'A';
    else if(i<192)return 'B';
    else if(i<224)return 'C';
    else if(i<240)return 'D';
    else return 'E';
}
int  getNetworkAddress(char s[]){
    int count=getClass(firstBlockAdd(s))-'A'+1;
    char ans[20]="";
    int i=0;
    while(count>0 && i<strlen(s)){
        if(s[i]=='.')count--;
        char temp[2]={s[i],'\0'};
        strcat(ans,temp);
        i++;
    }
    printf("Network address %s\n",ans);
    return i;
}
void getHostAddress(char s[],int start){
    char ans[20]="";
    for(int i=start;i<strlen(s);i++){
        char temp[2]={s[i],'\0'};
        strcat(ans,temp);
    }
    printf(" Host Address %s",ans);
}
int main() {
    char s[20];
    printf("Enter the  IPv4 address");
    scanf("%s",s);
    int start=getNetworkAddress(s);
    getHostAddress(s,start);
    return 0;
}

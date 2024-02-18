/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void getAddr(int a,int b,int c,int d){
    if(a<128){
        printf("Class A\n");
        printf("NetWork %d.0.0.0",a);
        printf("Host %d.%d.%d.0",b,c,d);
    }
    else if(a<192){
        printf("Class B");
        printf("NetWork %d.%d.0.0\n",a,b);
        printf("Host %d.%d.0.0\n",c,d);
    }
    else if(a<224){
        printf("Class C\n");
        printf("NetWork %d.%d.%d.0\n",a,b,c);
        printf("Host %d.0.0.0\n",d);
    }
    else if(a<240){
        printf("CLASS D\n");
    }
    else if(a<256){
        printf("CLASS E\n");
    }
    else {
        printf("INVALID");
    }
}
int main()
{   char s[16];
    scanf("%s",s);
    int a,b,c,d;
    sscanf(s,"%d.%d.%d.%d",&a,&b,&c,&d);
    getAddr(a,b,c,d);
    return 0;
}

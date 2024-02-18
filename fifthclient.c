#include <stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#define PORT 8080
#define BUFFER_SIZE 1000
int main()
{
    char buffer[BUFFER_SIZE];
    int client_socket;
    struct sockaddr_in serverAddress;
    client_socket=socket(AF_INET,SOCK_STREAM,0);
    if(client_socket==-1){
        printf("ERROR IN SOCKET");
        exit(0);
    }
    
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    serverAddress.sin_port=htons(PORT);
    
    if(connect(client_socket,(struct sockaddr *)&serverAddress,sizeof(serverAddress))==-1){
        printf("ERROR IN CONNECTION");
        exit(0);
    }
    printf("Enter a string");
    scanf("%s",buffer);

    if(send(client_socket,buffer,strlen(buffer),0)==-1){
        printf("ERROR WHILE SENDING");
        exit(0);
    }
    if(recv(client_socket,buffer,BUFFER_SIZE,0)==-1){
        printf("ERROR WHILE RECEVING");
        exit(0);
    }
    
    printf("Received from server %s",buffer);
    return 0;
}

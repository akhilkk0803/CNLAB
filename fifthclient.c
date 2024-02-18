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
 
    
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    serverAddress.sin_port=htons(PORT);
    
    printf("Enter a string");
    scanf("%s",buffer);
    
    connect(client_socket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));

    send(client_socket,buffer,strlen(buffer),0);
    
    recv(client_socket,buffer,BUFFER_SIZE,0);
    
    printf("Received from server %s",buffer);
    return 0;
}

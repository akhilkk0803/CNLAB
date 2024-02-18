/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<arpa/inet.h>
#include<unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define PORT 8080
#define BUFFER_SIZE 1024
int main()
{
   int server_socket ,client_socket;
   struct sockaddr_in server_address,client_address;
   socklen_t client_address_len=sizeof(client_address);
   char buffer[BUFFER_SIZE];
   client_socket=socket(AF_INET,SOCK_STREAM,0);
   if(client_socket==-1){
       perror("ERROR CREATING SOCKET");
       exit(EXIT_FAILURE);
   }
   
   server_address.sin_family=AF_INET;
   server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
   server_address.sin_port=htons(PORT);
   if(connect(client_socket,(struct sockaddr*)&server_address,
   sizeof(server_address))==-1){
       perror("ERROR connecting to server");
       exit(0);
   }
   printf("ENTER A STRING");
   fgets(buffer,BUFFER_SIZE,stdin);
   if(send(client_socket,buffer,strlen(buffer),0)==-1){
       perror("ERROR sending data");
       exit(0);
   }
    if(recv(client_socket,buffer,BUFFER_SIZE,0)==-1){
       perror("Error Recving data");
       exit(0);
   }
   printf("Recived from server %s",buffer);
   close(client_socket);

    return 0;
}

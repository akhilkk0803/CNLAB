/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define PORT 12345
#define BUFFER_SIZE 1024
int main()
{
   int server_socket ,client_socket;
   struct sockaddr_in server_address,client_address;
   socklen_t client_address_len=sizeof(client_address);
   server_socket=socket(AF_INET,SOCK_STREAM,0);
   char buffer[BUFFER_SIZE];
   if(server_socket==-1){
       perror("ERROR CREATING SOCKET");
       exit(EXIT_FAILURE);
   }
   
   server_address.sin_family=AF_INET;
   server_address.sin_addr.s_addr=INADDR_ANY;
   server_address.sin_port=htons(PORT);
   
   if(bind(server_socket,(struct sockaddr*)&server_address
   , sizeof(server_address))==-1){
       perror("ERROR BINDING SOCKET");
       exit(0);
   }
   
   
   if(listen(server_socket,5)==-1){
       perror("ERROR LISTENING");
       exit(0);
   }
   
   printf("Server listening on port %d\n",PORT);
   client_socket=accept(server_socket,(struct sockadd*)&
   client_address,&client_address_len);
   if(client_socket==-1){
       perror("Error accepting connection");
       exit(0);
   }
   printf("Recived connection");
   if(recv(client_socket,buffer,BUFFER_SIZE,0)==-1){
       perror("Error Recving data");
       exit(0);
   }
   printf("Recived from client");
   for(int i=0;buffer[i];i++){
       buffer[i]=toupper(buffer[i]);
   }
   if(send(client_socket,buffer,strlen(buffer),0)==-1){
       perror("ERROR SENDING DATA");
       exit(0);
   }
   close(client_socket);
   close(server_socket);
   
    return 0;
}

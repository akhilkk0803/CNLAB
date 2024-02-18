#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<ctype.h>
#define PORT 8080
#define BUFFER_SIZE 1024
int main(){
    int server_socket,client_socket;
    
    //sockaddr_in:  it's a structure specifically designed for handling Internet addresses.
    struct sockaddr_in serverAddress,clientAddress;
    
    //socklen_t  used to represent the length of socket-related structures
   int clientAdressLen=sizeof(clientAddress);
    
    //AF_INET:  indicates that the socket will be used for IPv4 addresses.
    // SOCK_STREAM: This parameter specifies the type of socket,  provides sequenced, reliable, two-way, connection-based byte streams. 
    // 0: This parameter (also known as the protocol parameter) allowing the system to choose the most appropriate protocol automatically.
    server_socket=socket(AF_INET,SOCK_STREAM,0);
    
    char buffer[BUFFER_SIZE];


// Sets the address family of the server's socket structure to IPv4.
serverAddress.sin_family=AF_INET;

// Sets the IP address of the server's socket structure to any available IP address on the local machine.
serverAddress.sin_addr.s_addr=INADDR_ANY;

//Sets the port number of the server's socket structure to the specified PORT, converting it to network byte order.
serverAddress.sin_port=htons(PORT);


// bind(socket: The file descriptor of the socket that you want to bind,
// address:that contains the network address and port number you want to bind to,
// size:of address in bytes
//)
bind(server_socket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));



//socket: This parameter is the file descriptor of the server socket that you want to listen on.
//backlog: This parameter is an integer value that specifies the maximum length of the queue of pending connections.
//It indicates how many incoming connections the server is willing to queue up while waiting for the application to accept them.
listen(server_socket,5);

printf("Server listening on port %d\n",PORT);


// accept(server_socket: The file descriptor of the server socket that is listening for incoming connections,
//clientAdress:to store the address information of the client that is connecting to the server,
//len of clientAddress
//)
    
 client_socket=accept(server_socket,(struct sockaddr *)&clientAddress,  &clientAdressLen);
 printf("Recived connection");
// recv(the socket from which data is to be received,
// buffer:pointer to which the data is to be stored,
// BUFFER_SIZE:max len of data ,
//flag:It's usually set to 0 for normal operation.
//)
   recv(client_socket,buffer,BUFFER_SIZE,0);
    
   printf("Recived from client");
   for(int i=0;buffer[i];i++){
       buffer[i]=toupper(buffer[i]);
   }
   
   
  send(client_socket,buffer,strlen(buffer),0);
   
   close(client_socket);
   close(server_socket);
}

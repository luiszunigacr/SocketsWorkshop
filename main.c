#include <stdio.h>
#include <winsock2.h>

//#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main() {

    WSADATA wsa;

    printf("\nInitialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d\n",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");



    SOCKET s;
    int family = AF_INET;
    int type = SOCK_STREAM;
    int protocol = 0; //Default: IPPROTO_TCP
    if((s = socket(family, type, protocol)) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d\n" , WSAGetLastError());
    }

    printf("Socket created.\n");



    //Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d\n" , WSAGetLastError());
    }

    puts("Bind done");



    //Listen to incoming connections
    listen(s , 3);



    //Accept and incoming connection
    puts("Waiting for incoming connections...");

    int c;
    SOCKET new_socket;
    struct sockaddr_in client;
    c = sizeof(struct sockaddr_in);
    new_socket = accept(s , (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d\n" , WSAGetLastError());
    }

    puts("Connection accepted");

    //Reply to client
    char *message;
    message = "Hola cliente. Recibí su conexión. Chao!\n";
    send(new_socket , message , strlen(message) , 0);

    getchar();

    closesocket(s);
    WSACleanup();

    puts("Socket closed");

    return 0;
}
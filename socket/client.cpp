
#include <iostream>
#include <unistd.h>    // For read(), close()
#include <sys/socket.h>
#include <arpa/inet.h> // For inet_pton
#include <cstring>

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    const char *hello = "Hello from client";
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Read server's response
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}

/*



#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
int main() {
   int sock = 0, valread;
   struct sockaddr_in serv_addr;
   char *hello = "Hello from client";
   char buffer[1024] = {0};
   if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
       printf("\n Socket creation error \n");
       return -1;
   }
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(8080);
   // Convert IPv4 and IPv6 addresses from text to binary form
   if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
       printf("\nInvalid address/ Address not supported \n");
       return -1;
   }
   if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
       printf("\nConnection Failed \n");
       return -1;
   }
   send(sock, hello, strlen(hello), 0);
   printf("Hello message sent\n");
   valread = read(sock, buffer, 1024);
   printf("%s\n",buffer );
   return 0;
}


*/





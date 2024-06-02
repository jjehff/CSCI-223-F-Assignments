#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#define LEN 256
#define SOCKET_PATH "server_socket"
#include <netinet/in.h>
#define PORT 12345

int main() {
	auto int clientSocket;
	struct in_addr {
		unsigned long s_addr;
	};
	
	struct sockaddr_in {
		short int sin_family; 				// AF_INET
	    unsigned short int sin_port; 		// port number
	    struct in_addr sin_addr;			// internet address
	    char sin_zero[8];					// padding
	} socketAddr;
	
	auto char message[LEN];

	// Creating the socket
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == -1) {
		perror("client socket -- failed");
		exit(0);
	}
	
	memset(&socketAddr, 0, sizeof(socketAddr));
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	socketAddr.sin_port = htons(PORT);
	
	// Connecting to the server
		if (connect(clientSocket, (struct sockaddr*)&socketAddr, sizeof(socketAddr)) == -1) {
		perror("client -- connection failed");
		exit(0);
	}
	printf("Connected to server\n");
	
	// Sending the message to the server
	while (1) {
		printf("Enter a message or 'quit' to exit the program: ");
		fgets(message, sizeof(message), stdin);
        
		// Send message to server
		if (send(clientSocket, message, strlen(message), 0) == -1) {
			perror("Message failed to send");
			exit(0);
		}
		if (strncmp(message, "quit", 4) == 0) {
			puts("Quitting the program...\n");
			break;
		}
	}
	close(clientSocket);
	return 0;
}

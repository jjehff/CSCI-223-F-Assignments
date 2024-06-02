#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#define LEN 256
#define SOCKET_PATH "server_socket"

int main() {
	auto int clientSocket;
	struct sockaddr_un {
		sa_family_t sun_family;
    	char sun_path[108];
	} socketAddr;
	auto char message[LEN];

	// Creating the socket
	clientSocket = socket(AF_UNIX, SOCK_STREAM, 0);
	if (clientSocket == -1) {
		perror("client socket -- failed");
		exit(0);
	}

	socketAddr.sun_family = AF_UNIX;
	strcpy(socketAddr.sun_path, SOCKET_PATH);

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

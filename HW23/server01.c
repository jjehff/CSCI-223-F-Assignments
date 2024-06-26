// ============================================================================
// File: server01.c
// ============================================================================
// The server does the following:
// -- delete the local socket file, if it exists
// -- create a socket
// -- bind the socket to the local socket file
// -- put the socket in a listening state
// -- wait for a client connection
//
// Once a client connects, the server receives a string message from the client
// and writes it to stdout. Then the server closes the connection and shuts
// down.
// ============================================================================
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>
#define LEN 256
#define SOCKET_NAME "server_socket"
// ==== main ==================================================================
//
// ============================================================================
int main(void) {
	auto char buf[LEN];
	auto int server_sockfd;
	auto int client_sockfd;
	auto socklen_t client_len;
	auto ssize_t num_client_bytes;
	auto struct sockaddr_un server_address;
	auto struct sockaddr_un client_address;

	// remove any existing socket, create a new unnamed socket for the server
	unlink(SOCKET_NAME);
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	// bind the socket to a name
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, SOCKET_NAME);
	if (bind(server_sockfd, (struct sockaddr*)&server_address, sizeof(server_address))) {
		perror("server -- bind failed");
	}

	// create a connection queue and wait for a client
	if (listen(server_sockfd, 5)) {
		perror("server -- listen failed");
	}

	// announce server is waiting for client connections
	puts("server waiting...");

	// accept a connection
	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);


	// fetch a message from the client and write it to stdout
	do {
		for (int i = 0; i < LEN; i++) { 
			buf[i] = '\0';
		}
		num_client_bytes = recv(client_sockfd, buf, LEN, 0);
		if (-1 == num_client_bytes) {
			perror("server -- recv failed");
		}
		else {
			printf("client message: %s\n", buf);
		}
	} while(strncmp(buf, "quit", 4) != 0);
	puts("Client wants to quit the program: Exiting...\n");
	// remove the local socket file and close the sockets
	unlink(SOCKET_NAME);
	close(client_sockfd);
	close(server_sockfd);
	return 0;
} // end of "main"

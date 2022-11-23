#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdbool.h>

#include "main.h"
#include "method.h"

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error init socket\n");
        exit(INIT_ERROR);
    }

    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(struct sockaddr_in));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(80);
    // my_addr.sin_zero = 0;

    if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error binding socket\n");
        exit(INIT_ERROR);
    }

    if (listen(sockfd, 1024) == -1) {
        perror("Erorr listening to port");
        exit(INIT_ERROR);
    }

    while (true) {
        struct sockaddr_in client_addr;
        int client_socklen;
        int client_fd = accept(sockfd, &client_addr, &client_socklen);
        if (client_fd == -1) {
            perror("Error accepting new client");
            exit(CONN_ERROR);
        }

        uint8_t payload_buffer[PAYLOAD_BUFFER_SIZE];
        memset(payload_buffer, 0, PAYLOAD_BUFFER_SIZE);

        int bytes_read = read(client_fd, payload_buffer, PAYLOAD_BUFFER_SIZE);
        int method_code = get_method(payload_buffer, bytes_read);
        // TODO unknown method 
        uint8_t url[PAYLOAD_BUFFER_SIZE];
        
    }


    // TODO on enter child process, close sockfd which listens for new connections
}

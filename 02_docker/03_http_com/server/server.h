#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Server{
    private:
        struct sockaddr_in server_addr;
        std::string ip_addr = "127.0.0.1";
        int port = 5000;
        int sock;

    public:

    int setSocket() {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (!sock) {
            std::cout << "Failed to initialize a socket." << std::endl;
            return 1;
        }
        
        memset(&server_addr, 0, sizeof(server_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
        server_addr.sin_port = htons(port);

        int optval = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
            std::cout << "Failed to setsocket" << std::endl;
            close(sock);
            return 1;
        }
        return sock;
    }

    int wait() {
        if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
            std::cout << "Failed to bind. error:" << strerror(errno) << std::endl;
            close(sock);
            return 1;
        }

        if (listen(sock, 5) != 0) {
            std::cout << "Failed to listen. error:" << errno << std::endl;
            close(sock);
            return 1;
        }
        return 0;
    }
};

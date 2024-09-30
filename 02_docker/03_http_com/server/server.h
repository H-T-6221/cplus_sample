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
        //std::string ip_addr = "127.0.0.1";
        std::string ip_addr = "192.168.20.20";
        int port = 5000;
        int sock;

    public:
        int setSocket();
        int setBind();
        std::string setMessage();
        void wait(std::string response);
};

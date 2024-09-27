#include "client.h"

int main(int argc, char *argv[]) {
    Client client;
    struct sockaddr_in server;
    int sock;
    
    std::string ip_addr;

    if (argc != 2) {
        ip_addr = "127.0.0.1";
    } else {
        ip_addr = argv[1];
    }

    sock = client.setSocket(ip_addr);

    if(client.getConnect()) {
        return 1;
    }
/*
    } else {
        std::cout << "check connect return 0" << std::endl;
        client.getHostName();
        if(!client.checkHost()) {
            return 1;
        }

        if(!client.getConnect()) {
            return 1;
        }
    }
*/

    if(client.sendRequest()){
        return 1;
    }

    if(client.receiveMessage()){
        return 1;
    }

    return 0;
}

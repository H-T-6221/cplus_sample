#include "server.h"

int main() {
    Server server;
    int sock;

    sock = server.setSocket();
    
    if(!server.wait()) {
        return 1;
    }

    auto body = std::string("Hello World!");
    auto response = std::string("");
    std::ostringstream oss;

    oss << "Content-Length: " << 20 << "\r\n";

    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/html; charset=UTF-8\r\n");
    response.append(oss.str());
    response.append("Connection: Keep-Alive\r\n");
    response.append("\r\n");
    response.append(body);

    std::cout << "response:" << response << std::endl;

    char inbuf[2048];

    while (true) {
        auto connfd = accept(sock, nullptr, nullptr);
        if (connfd < 0) {
            std::cout << "Failed to accept." << std::endl;
            break;
        }

        memset(inbuf, 0, sizeof(inbuf));
        recv(connfd, inbuf, sizeof(inbuf), 0);

        if (send(connfd, response.c_str(), response.length(), 0) == -1) {
            std::cout << "Failed to send." << std::endl;
        }
    }

    close(sock);

    return 0;
}

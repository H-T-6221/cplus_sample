#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include "log.h"

class Client {
    private:
        struct sockaddr_in server;
        int sock;
        std::string ip_addr;
        struct hostent *host;
        char buf[1024];
        int num;

    public:
        Log log;
        
        int setSocket(std::string ip) {
            ip_addr = ip;
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                perror("socket");
                return 1;
            }

            server.sin_family = AF_INET;
            server.sin_port = htons(5000);    // HTTPのポート
            server.sin_addr.s_addr = inet_addr(ip_addr.c_str());
            return sock;
        }

        int getConnect() {
            if (server.sin_addr.s_addr != 0xffffffff) {
                if (connect(sock, (struct sockaddr *)&server, sizeof(server)) != 0) {
                    perror("get connect error");
                    return 1;
                }
            }
            return 0;
        }

        int sendRequest() {
            memset(buf, 0, sizeof(buf));
            snprintf(buf, sizeof(buf), "GET / HTTP/1.0\r\n\r\n");

            num = write(sock, buf, (int)strlen(buf));
            std::cout << "write行:" << num << std::endl;
            if (num < 0) {
                perror("write");
                return 1;
            }
            return 0;
        }

        int receiveMessage() {
            memset(buf, 0, sizeof(buf));
            num = read(sock, buf, sizeof(buf));
            std::cout << "read行:" << num << std::endl;
            if (num < 0) {
                perror("read");
                return 1;
            }
            write(1, buf, num);
            log.print(buf);
            log.print("Receive::Success send message");
            close(sock);
            return 0;
        }
};

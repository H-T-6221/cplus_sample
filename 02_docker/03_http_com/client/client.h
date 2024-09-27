#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

class Client {
    private:
        struct sockaddr_in server;
        int sock;
        std::string ip_addr;
        struct hostent *host;
        char buf[32];
        int num;

    public:
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

        /* 使わないので必要ない */
        void getHostName() {
            host = gethostbyname(ip_addr.c_str());
        }

        /* gethostbynameでホストが取れないことがないので必要ない */
        int checkHost() {
            if (host == NULL) {
                if (h_errno == HOST_NOT_FOUND) {
                    printf("host not found : %s\n", ip_addr.c_str());
                } else {
                    printf("%s : %s\n", hstrerror(h_errno), ip_addr.c_str());
                }
                return 1;
            }
            return 0;
        }

        /* host->h_addr_listはNULLを返すのでaddrptrは常にNULL */
        int getConnect_old() {         
            unsigned int **addrptr;
            addrptr = (unsigned int **)host->h_addr_list;

            while (*addrptr != NULL) {
                server.sin_addr.s_addr = *(*addrptr);
                if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
                    break;
                }
                addrptr++;
            }

            if (*addrptr == NULL) {
                std::cout << "get connect" << std::endl;
                perror("connect");
                return 1;
            }
            return 0;
        }

        int sendRequest() {
            memset(buf, 0, sizeof(buf));
            snprintf(buf, sizeof(buf), "GET / HTTP/1.0\r\n\r\n");

            num = write(sock, buf, (int)strlen(buf));
            if (num < 0) {
                perror("write");
                return 1;
            }
            return 0;
        }

        int receiveMessage() {
            while (num > 0) {
                memset(buf, 0, sizeof(buf));
                num = read(sock, buf, sizeof(buf));
                if (num < 0) {
                    perror("read");
                    return 1;
                }
                write(1, buf, num);
            }
            close(sock);
            return 0;
        }
};

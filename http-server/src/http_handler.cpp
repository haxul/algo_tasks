#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include "ctx.cpp"

#define BUF_SIZE 1024 * 8

class HttpHandler {
   private:
    int socket_;

   public:
    HttpHandler() {}
    HttpHandler(int socket) : socket_(socket) {
        std::cout << "create handler" << "\n";
    }

    void run() {
        char buf[BUF_SIZE]; 

        while (true) {
            memset(&buf, 0, sizeof(buf));
            int read = recv(socket_, (char *)&buf, sizeof(buf), 0);
            if (read == 0) {
                break;
            }
            if (buf[0] == 'q') {
                return;
            }
            std::cout << "socket got: " << buf << '\n';
        }
    }

    ~HttpHandler() {
        std::cout << "destruct" << '\n';
        close(socket_);
    }
};
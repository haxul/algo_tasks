#ifndef SERVER_SOCKET 
#define SERVER_SOCKET 


#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

class ServerSocket {
   private:
    sockaddr_in addr_;
    int fd_ = -1;
    int port_;

   public:
    ServerSocket(int port) : port_(port) {
        memset(&addr_, 0, sizeof(addr_));
        addr_.sin_family = AF_INET;
        addr_.sin_addr.s_addr = htonl(INADDR_ANY);
        addr_.sin_port = htons(port_);

        // open stream oriented socket with internet address
        // also keep track of the socket descriptor
        fd_ = socket(AF_INET, SOCK_STREAM, 0);
        if (fd_ < 0) {
            throw "cannot create socket";
        }
        const int enable = 1;
        if (setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
            throw "setsockopt(SO_REUSEADDR) failed";
        }

        int bindStatus = bind(fd_, (struct sockaddr*)&addr_, sizeof(addr_));
        if (bindStatus < 0) {
            throw "Error binding socket to local address";
        }
        listen(fd_, 5);
    }

    ~ServerSocket() { close(fd_); }

    int Accept(sockaddr_in& sock_addr) {
        socklen_t size = sizeof(sock_addr);
        return accept(fd_, (sockaddr*)&sock_addr, &size);
    }

    int GetPort() { return port_; }
};


#endif

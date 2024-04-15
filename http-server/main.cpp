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

#include "src/server_socket.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    ServerSocket ss(3000);

    char buf[1024] = {0};

    while (true) {
        sockaddr_in new_sock_addr;
        int socket = ss.Accept(new_sock_addr);
        if (socket < 0) {
            std::cerr << "cannot get conn"
                      << "\n";
            continue;
        }
        while (true) {
            memset(&buf, 0, sizeof(buf));
            int read = recv(socket, (char *)&buf, sizeof(buf), 0);
            if (read == 0) {
                break;
            }
            std::cout << "socket got: " << buf << '\n';
        }
    }

    return 0;
}
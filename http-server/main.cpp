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
#include "src/thread_pool.cpp"


int main() {
    ThreadPool pool(10);

    ServerSocket ss(3000);


    while (true) {
        sockaddr_in new_sock_addr;
        int socket = ss.Accept(new_sock_addr);
        if (socket < 0) {
            std::cerr << "cannot get conn"
                      << "\n";
            continue;
        }
        auto handler = new HttpHandler(socket);
        pool.Enqueue(handler);
    }

    return 0;
}
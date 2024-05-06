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
#include "./src/http_method_processor.cpp"
#include "./src/http_req.cpp"
#include "./src/http_resp.cpp"

static MethodContainer container = MethodContainer();

class GetProcessor : public HttpMethodProcessor {

    HttpResponse process(const HttpRequest& req) override {

        int a = 1 + 1;
        return HttpResponse();
    }
};

HttpMethodProcessor* getProc = new GetProcessor();
HttpMethodInfo info;


int main() {
    ThreadPool pool(2);

    ServerSocket ss(3000);


    while (true) {
        sockaddr_in new_sock_addr;
        int socket = ss.Accept(new_sock_addr);
        if (socket < 0) {
            std::cerr << "cannot get conn"
                      << "\n";
            continue;
        }
        info.method = "GET";
        info.path = "/world";

        container.Reg(info, getProc);
        auto handler = new HttpHandler(socket, &container);
        pool.Enqueue(handler);
    }

    return 0;
}
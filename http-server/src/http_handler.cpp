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
#include <unordered_map>

#include "./http_method_processor.cpp"
#include "./http_req.cpp"
#include "./http_resp.cpp"

#define NEW_LINE_SIZE 2;
#define BUF_SIZE 1024 * 8

class HttpHandler {
   private:
    int socket_;
    MethodContainer* method_container;

   public:
    HttpHandler() {}
    HttpHandler(int socket, MethodContainer* container)
        : socket_(socket), method_container(container) {}

    HttpRequest Parse(const char* buf, const int size) {
        HttpRequest req;
        int p = 0;
        while (p < size && buf[p] != ' ') {
            req.method += buf[p++];
        }

        p++;
        while (p < size && buf[p] != ' ') {
            req.path += buf[p++];
        }

        p++;
        while (p < size && buf[p] != '\r') {
            req.protocol_version += buf[p++];
        }

        p += NEW_LINE_SIZE;
        // hedears
        while (p < size) {
            std::string header_name;
            if (buf[p] == '\r') {
                break;
            }
            while (p < size && buf[p] != ':') {
                header_name += buf[p++];
            }
            if (header_name == "\r\n") {
                break;
            }
            p += NEW_LINE_SIZE;
            std::string header_val;
            while (p < size && buf[p] != '\r') {
                header_val += buf[p++];
            }

            req.headers[std::move(header_name)] = std::move(header_val);
            p += NEW_LINE_SIZE;
        }
        // body
        p += NEW_LINE_SIZE;
        while (p < size) {
            req.body += buf[p++];
        }

        return req;
    }

    void Run() {
        char buf[BUF_SIZE];
        int sent_bytes;
        while (true) {
            memset(buf, 0, sizeof(buf));
            const int read = recv(socket_, (char*)&buf, sizeof(buf), 0);
            if (read == 0) {
                break;
            }

            HttpRequest req = this->Parse(buf, read);
            HttpMethodProcessor* processor =
                method_container->Get(req.method, req.path);

            if (processor == nullptr) {
                char* resp = "HTTP/1.1 404 NOT_FOUND\r\nConnection: close";
                send(this->socket_, resp, strlen(resp), 0);
                close(socket_);
                return;
            }

            auto response = processor->process(req);

            char buf[] =
                "HTTP/1.1 200 OK\r\nContent-type: plain/text\r\nConnection: "
                "close\r\n\r\nhello world";

            sent_bytes = send(this->socket_, buf, strlen(buf), 0);
            std::cout << "socket got: " << buf << '\n';
            close(socket_);
            break;
        }
    }

    ~HttpHandler() { close(socket_); }
};
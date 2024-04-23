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
#define NEW_LINE_SIZE 2;
#define BUF_SIZE 1024 * 8

class HttpRequest {
   public:
    std::string path;
    std::string method;
    std::string protocol_version;
    std::unordered_map<std::string, std::string> headers;
    std::string body;

    HttpRequest(HttpRequest& req) { std::cout << "copy" << '\n'; }

    HttpRequest() { std::cout << "created" << '\n'; }

    ~HttpRequest() { std::cout << "deleted" << '\n'; }
};

class HttpHandler {
   private:
    int socket_;

   public:
    HttpHandler() {}
    HttpHandler(int socket) : socket_(socket) {
        std::cout << "create handler"
                  << "\n";
    }

    HttpRequest parse(const char* buf, const int size) {
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
        //body
        p += NEW_LINE_SIZE;
        while (p < size) {
            req.body += buf[p++];
        }

        return req;
    }

    void run() {
        char buf[BUF_SIZE];

        while (true) {
            memset(buf, 0, sizeof(buf));
            const int read = recv(socket_, (char*)&buf, sizeof(buf), 0);
            if (read == 0) {
                break;
            }

            const HttpRequest req = this->parse(buf, read);

            std::cout << "socket got: " << buf << '\n';
        }
    }

    ~HttpHandler() { close(socket_); }
};
#ifndef HTTP_REQ
#define HTTP_REQ


#include <string.h>
#include <iostream>
#include <string>
#include <unordered_map>

struct HttpRequest {
    std::string path;
    std::string method;
    std::string protocol_version;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};

#endif;
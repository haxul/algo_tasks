#ifndef HTTP_RESPONSE 
#define HTTP_RESPONSE 

#include <string.h>
#include <string>
#include <unordered_map>


class HttpResponse {
    public:
    std::string path;
    std::string method;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};


#endif
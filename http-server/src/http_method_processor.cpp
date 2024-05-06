#ifndef HTTP_METHOD_PROCESSOR 
#define HTTP_METHOD_PROCESSOR 


#include <string>
#include <unordered_map>

#include "./http_req.cpp"
#include "./http_resp.cpp"

class HttpMethodProcessor {
   public:
    virtual HttpResponse process(const HttpRequest& req) {}
};

struct HttpMethodInfo {
    std::string path;
    std::string method;
};

class MethodContainer {
   private:
    std::unordered_map<std::string,
                       std::unordered_map<std::string, HttpMethodProcessor*>>
        container_;

   public:
    void Reg(HttpMethodInfo& http_method, HttpMethodProcessor* proc) {
        container_[http_method.path][http_method.method] = proc;
    }

    HttpMethodProcessor* Get(const std::string method, const std::string path) {
        return container_[path][method];
    }

};

#endif
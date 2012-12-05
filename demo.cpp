//
//  demo.cpp
//  Web++
//
//  Created by Alex Movsisyan
//

#include <iostream>
#include <map>

#include "web++.hpp"

using namespace WPP;

void web(Request* req, Response* res) {
    std::cout << req->method << " " << req->path << std::endl;

    std::cout << "Headers:" << std::endl;

    std::map<std::string, std::string>::iterator iter;
    for (iter = req->headers.begin(); iter != req->headers.end(); ++iter) {
        std::cout << iter->first << " = " << iter->second << std::endl;
    }

    std::cout << "Query:" << std::endl;
    
    for (iter = req->query.begin(); iter != req->query.end(); ++iter) {
        std::cout << iter->first << " = " << iter->second << std::endl;
    }

    std::cout << "Cookies: " << req->cookies.size() << std::endl;
    
    for (iter = req->cookies.begin(); iter != req->cookies.end(); ++iter) {
        std::cout << iter->first << " = " << iter->second << std::endl;
    }
    
    res->body << "HELLO";
}

int main(int argc, const char* argv[]) {
    try {
        std::cout << "Listening on port 5000" << std::endl;
        
        WPP::Server server;
        server.get("/", &web);
        server.all("/dir", "./");
        server.start(5000);
    } catch(WPP::Exception e) {
        std::cerr << "WebServer: " << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}
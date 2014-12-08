![Web++](https://raw.github.com/konteck/wpp/master/logo.png)
[![Build Status](https://secure.travis-ci.org/konteck/wpp.png)](http://travis-ci.org/konteck/wpp)

*Single file embedded C++ web server* 

===

## How to use in own project

```c++
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
```

## How to compile

    g++ demo.cpp -o demo

## Special requirements

Nop

## Tested on

* Mac OS X
* Linux

## The MIT License

Copyright (c) Alex Movsisyan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the 'Software'), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/konteck/wpp/trend.png)](https://bitdeli.com/free "Bitdeli Badge")


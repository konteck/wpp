#include "src/web++.hpp"

int main(int argc, const char* argv[]) {
    Magick::InitializeMagick(*argv);

    try {
        WPP::Server server;
//        server.get("/", &web_interface);
        server.all("/dir", "./");
        server.start(5000);
    } catch(WPP::Exception e) {
        cerr << "WebServer: " << e.what() << endl;
    }

    return EXIT_SUCCESS;
}
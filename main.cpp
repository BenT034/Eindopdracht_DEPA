#include "Application.h"
#include <iostream>
#include <exception>

int main(int argc, char* argv[]) {
    std::cout << "Application starting..." << std::endl; // DEBUG

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <circuit_file>" << std::endl;
        return 1;
    }

    Application app;
    try {
        app.run(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#include "Application.h"
#include <iostream>
#include <stdexcept>

Application::Application() = default;

void Application::run(const std::string& filename) {
    try {
        circuit = reader.parse(filename);
        simulator = std::make_unique<Simulator>(circuit.get());
        simulator->run();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

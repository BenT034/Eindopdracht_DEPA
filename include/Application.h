#ifndef APPLICATION_H
#define APPLICATION_H

#include "FileReader.h"
#include "Simulator.h"
#include <memory>
#include <string>

class Application {
private:
    FileReader reader;
    std::unique_ptr<Circuit> circuit;
    std::unique_ptr<Simulator> simulator;

public:
    Application();
    void run(const std::string& filename);
};

#endif // APPLICATION_H

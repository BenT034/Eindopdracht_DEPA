#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Circuit.h"

class Simulator {
private:
    Circuit* circuit;

public:
    Simulator(Circuit* c);
    void run();
};

#endif // SIMULATOR_H

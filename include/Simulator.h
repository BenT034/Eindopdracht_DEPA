#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Circuit.h"
#include <map>
#include <queue>
#include <vector>
#include <string>

class Simulator {
private:
    Circuit* circuit;
    
    std::map<std::string, int> calculateInDegrees();
    std::queue<Component*> findInitialNodes(const std::map<std::string, int>& inDegrees);
    std::vector<Component*> performTopologicalSort(std::map<std::string, int> inDegrees, std::queue<Component*> q);
    void validateCircuit(const std::vector<Component*>& topologicalOrder);
    void evaluateAndPrintComponents(const std::vector<Component*>& topologicalOrder);

public:
    Simulator(Circuit* c);
    void run();
};

#endif // SIMULATOR_H

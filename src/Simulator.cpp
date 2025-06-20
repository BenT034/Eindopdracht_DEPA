#include "Simulator.h"
#include <iostream>
#include <queue>
#include <stdexcept>

Simulator::Simulator(Circuit* c) : circuit(c) {}

void Simulator::run() {
    std::map<std::string, int> inDegrees;
    for (const auto& pair : circuit->getAllComponents()) {
        inDegrees[pair.first] = 0;
    }

    for (const auto& pair : circuit->getAllComponents()) {
        for (Component* output : pair.second->getOutputs()) {
            inDegrees[output->getId()]++;
        }
    }

    std::queue<Component*> q;
    for (const auto& pair : circuit->getAllComponents()) {
        if (inDegrees[pair.first] == 0) {
            q.push(pair.second.get());
        }
    }

    std::vector<Component*> topologicalOrder;
    while (!q.empty()) {
        Component* current = q.front();
        q.pop();
        topologicalOrder.push_back(current);

        for (Component* nextComp : current->getOutputs()) {
            inDegrees[nextComp->getId()]--;
            if (inDegrees[nextComp->getId()] == 0) {
                q.push(nextComp);
            }
        }
    }

    if (topologicalOrder.size() != circuit->getAllComponents().size()) {
        throw std::runtime_error("Circuit contains a cycle.");
    }

    for (Component* comp : topologicalOrder) {
        comp->eval();
        comp->printOutput();
    }
}

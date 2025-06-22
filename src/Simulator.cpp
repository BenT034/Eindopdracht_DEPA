#include "Simulator.h"
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stdexcept>

Simulator::Simulator(Circuit* c) : circuit(c) {}

std::map<std::string, int> Simulator::calculateInDegrees() {
    std::map<std::string, int> inDegrees;
    
    // Initialize all components with in-degree 0
    for (const auto& pair : circuit->getAllComponents()) {
        inDegrees[pair.first] = 0;
    }
    
    // Calculate actual in-degrees
    for (const auto& pair : circuit->getAllComponents()) {
        for (Component* output : pair.second->getOutputs()) {
            inDegrees[output->getId()]++;
        }
    }
    
    return inDegrees;
}

std::queue<Component*> Simulator::findInitialNodes(const std::map<std::string, int>& inDegrees) {
    std::queue<Component*> q;
    
    // Find nodes with no incoming edges
    for (const auto& pair : circuit->getAllComponents()) {
        if (inDegrees.at(pair.first) == 0) {
            q.push(pair.second.get());
        }
    }
    
    return q;
}

std::vector<Component*> Simulator::performTopologicalSort(std::map<std::string, int> inDegrees, std::queue<Component*> q) {
    std::vector<Component*> topologicalOrder;
    
    while (!q.empty()) {
        Component* current = q.front();
        q.pop();
        topologicalOrder.push_back(current);

        // Update in-degrees of connected components
        for (Component* nextComp : current->getOutputs()) {
            inDegrees[nextComp->getId()]--;
            if (inDegrees[nextComp->getId()] == 0) {
                q.push(nextComp);
            }
        }
    }
    
    return topologicalOrder;
}

void Simulator::validateCircuit(const std::vector<Component*>& topologicalOrder) {
    if (topologicalOrder.size() != circuit->getAllComponents().size()) {
        throw std::runtime_error("Circuit contains a cycle.");
    }
}

void Simulator::evaluateAndPrintComponents(const std::vector<Component*>& topologicalOrder) {
    for (Component* comp : topologicalOrder) {
        comp->eval();
        comp->printOutput();
    }
}

void Simulator::run() {
    // Calculate in-degrees for all components
    std::map<std::string, int> inDegrees = calculateInDegrees();
    
    // Find initial nodes (nodes with no incoming edges)
    std::queue<Component*> initialNodes = findInitialNodes(inDegrees);
    
    // Perform topological sort
    std::vector<Component*> topologicalOrder = performTopologicalSort(inDegrees, initialNodes);
    
    // Validate that the circuit has no cycles
    validateCircuit(topologicalOrder);
    
    // Evaluate and print all components in topological order
    evaluateAndPrintComponents(topologicalOrder);
}

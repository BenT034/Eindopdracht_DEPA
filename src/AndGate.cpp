#include "AndGate.h"
#include "Component.h"
#include <stdexcept>
#include <thread>
#include <chrono>

// Static member initialization
AndGate AndGate::prototype("AND");

AndGate::AndGate(const std::string& gateId)
    : GateNode(gateId) {
}

bool AndGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("AND gate must have at least one input.");
    }
    
    // Simulate propagation delay by pausing for the gate's delay time
    // In a real simulator, this would use a proper event-based timing system
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(get_propagation_delay())));
    
    _currentOutputValue = true;
    for (Component* input : inputs) {
        if (!input->getOutputValue()) {
            _currentOutputValue = false;
            break;
        }
    }
    return _currentOutputValue;
}

Component* AndGate::clone() const {
    return new AndGate(*this);
}

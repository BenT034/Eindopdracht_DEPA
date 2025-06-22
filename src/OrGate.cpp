#include "OrGate.h"
#include <stdexcept>
#include <thread>
#include <chrono>

// Static member initialization
OrGate OrGate::prototype("OR");

OrGate::OrGate(const std::string& gateId)
    : GateNode(gateId) {
}

bool OrGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("OR gate must have at least one input.");
    }
    
    // Simulate propagation delay by pausing for the gate's delay time
    std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(get_propagation_delay())));
    
    _currentOutputValue = false;
    for (Component* input : inputs) {
        if (input->getOutputValue()) {
            _currentOutputValue = true;
            break;
        }
    }
    return _currentOutputValue;
}

Component* OrGate::clone() const {
    return new OrGate(*this);
}

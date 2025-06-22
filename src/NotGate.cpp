#include "NotGate.h"
#include <stdexcept>
#include <thread>
#include <chrono>

// Static member initialization
NotGate NotGate::prototype("NOT");

NotGate::NotGate(const std::string& gateId)
    : GateNode(gateId) {
}

bool NotGate::eval() {
    if (inputs.size() != 1) {
        throw std::runtime_error("NOT gate must have exactly one input.");
    }
    
    // Simulate propagation delay by pausing for the gate's delay time
    std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(get_propagation_delay())));
    
    _currentOutputValue = !inputs[0]->getOutputValue();
    return _currentOutputValue;
}

Component* NotGate::clone() const {
    return new NotGate(*this);
}

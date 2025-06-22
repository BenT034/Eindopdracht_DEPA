#include "OrGate.h"
#include <stdexcept>

// Static member initialization
OrGate OrGate::prototype("OR");

OrGate::OrGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {
}

bool OrGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("OR gate must have at least one input.");
    }
    _currentOutputValue = false;
    for (Component* input : inputs) {
        if (input->getOutputValue()) {
            _currentOutputValue = true;
            break;
        }    }
    return _currentOutputValue;
}

Component* OrGate::clone() const {
    return new OrGate(*this);
}

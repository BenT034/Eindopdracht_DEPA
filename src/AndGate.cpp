#include "AndGate.h"
#include "Component.h"
#include <stdexcept>

// Static member initialization
AndGate AndGate::prototype("AND");

AndGate::AndGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {
}

bool AndGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("AND gate must have at least one input.");
    }
    _currentOutputValue = true;
    for (Component* input : inputs) {
        if (!input->getOutputValue()) {
            _currentOutputValue = false;
            break;
        }    }
    return _currentOutputValue;
}

Component* AndGate::clone() const {
    return new AndGate(*this);
}

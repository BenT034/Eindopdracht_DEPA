#include "AndGate.h"
#include <stdexcept>

AndGate::AndGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {}

bool AndGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("AND gate must have at least one input.");
    }
    _currentOutputValue = true;
    for (Component* input : inputs) {
        if (!input->getOutputValue()) {
            _currentOutputValue = false;
            break;
        }
    }
    return _currentOutputValue;
}

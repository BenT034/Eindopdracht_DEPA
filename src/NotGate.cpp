#include "NotGate.h"
#include <stdexcept>

// Static member initialization
NotGate NotGate::prototype("NOT");

NotGate::NotGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {
}

bool NotGate::eval() {
    if (inputs.size() != 1) {
        throw std::runtime_error("NOT gate must have exactly one input.");
    }    _currentOutputValue = !inputs[0]->getOutputValue();
    return _currentOutputValue;
}

Component* NotGate::clone() const {
    return new NotGate(*this);
}

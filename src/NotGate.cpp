#include "NotGate.h"
#include <stdexcept>

NotGate::NotGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {}

bool NotGate::eval() {
    if (inputs.size() != 1) {
        throw std::runtime_error("NOT gate must have exactly one input.");
    }
    _currentOutputValue = !inputs[0]->getOutputValue();
    return _currentOutputValue;
}

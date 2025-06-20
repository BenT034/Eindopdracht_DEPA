#include "XorGate.h"
#include <stdexcept>

XorGate::XorGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {}

bool XorGate::eval() {
    if (inputs.size() != 2) {
        throw std::runtime_error("XOR gate must have exactly two inputs.");
    }
    _currentOutputValue = inputs[0]->getOutputValue() ^ inputs[1]->getOutputValue();
    return _currentOutputValue;
}

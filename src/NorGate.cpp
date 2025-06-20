#include "NorGate.h"
#include <stdexcept>

NorGate::NorGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {}

bool NorGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("NOR gate must have at least one input.");
    }
    bool or_result = false;
    for (Component* input : inputs) {
        if (input->getOutputValue()) {
            or_result = true;
            break;
        }
    }
    _currentOutputValue = !or_result;
    return _currentOutputValue;
}

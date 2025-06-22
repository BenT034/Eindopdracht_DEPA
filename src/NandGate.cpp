#include "NandGate.h"
#include <stdexcept>

// Static member initialization
NandGate NandGate::prototype("NAND");

NandGate::NandGate(const std::string& gateId)
    : GateNode(gateId, 10.0) {
}

bool NandGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("NAND gate must have at least one input.");
    }
    bool and_result = true;
    for (Component* input : inputs) {
        if (!input->getOutputValue()) {
            and_result = false;
            break;
        }
    }    _currentOutputValue = !and_result;
    return _currentOutputValue;
}

Component* NandGate::clone() const {
    return new NandGate(*this);
}

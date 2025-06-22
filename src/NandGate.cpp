#include "NandGate.h"
#include <stdexcept>
#include <thread>
#include <chrono>

// Static member initialization
NandGate NandGate::prototype("NAND");

NandGate::NandGate(const std::string& gateId)
    : GateNode(gateId) {
}

bool NandGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("NAND gate must have at least one input.");
    }
    
    // Simulate propagation delay by pausing for the gate's delay time
    std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(get_propagation_delay())));
    
    bool and_result = true;
    for (Component* input : inputs) {
        if (!input->getOutputValue()) {
            and_result = false;
            break;
        }
    }
    _currentOutputValue = !and_result;
    return _currentOutputValue;
}

Component* NandGate::clone() const {
    return new NandGate(*this);
}

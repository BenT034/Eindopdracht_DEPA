#include "NorGate.h"
#include <stdexcept>
#include <thread>
#include <chrono>
// Static member initialization
NorGate NorGate::prototype("NOR");

NorGate::NorGate(const std::string& gateId)
    : GateNode(gateId) {
}

bool NorGate::eval() {
    if (inputs.empty()) {
        throw std::runtime_error("NOR gate must have at least one input.");
    }
    bool or_result = false;
    std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(get_propagation_delay())));

    for (Component* input : inputs) {
        if (input->getOutputValue()) {
            or_result = true;
            break;
        }
    }    _currentOutputValue = !or_result;
    return _currentOutputValue;
}

Component* NorGate::clone() const {
    return new NorGate(*this);
}

#include "ProbeNode.h"
#include <iostream>

// Static member initialization
ProbeNode ProbeNode::prototype("PROBE");

ProbeNode::ProbeNode(const std::string& probeId)
    : Component(probeId), inputSource(nullptr) {
}

bool ProbeNode::eval() {
    if (inputSource) {
        _currentOutputValue = inputSource->getOutputValue();
    } else {
        std::cerr << "Warning: ProbeNode '" << id << "' has no input source.\n";
        _currentOutputValue = false;
    }
    return _currentOutputValue;
}


void ProbeNode::setInput(Component* source) {
    if (inputSource != nullptr) {
        throw std::runtime_error("Input source for probe '" + id + "' is already set.");
    }
    inputSource = source;
}

void ProbeNode::printOutput() const {
    std::cout << "Probe '" << id << "': " << (getOutputValue() ? "HIGH" : "LOW") << std::endl;
}

Component* ProbeNode::clone() const {
    return new ProbeNode(*this);
}

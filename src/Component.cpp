#include "Component.h"
#include <stdexcept>

Component::Component(const std::string& componentId, double delay) 
    : id(componentId), propagationDelay(delay), _currentOutputValue(false) {}

const std::string& Component::getId() const {
    return id;
}

bool Component::getOutputValue() const {
    return _currentOutputValue;
}

void Component::addOutput(Component* out) {
    outputs.push_back(out);
}

const std::vector<Component*>& Component::getOutputs() const {
    return outputs;
}

double Component::getPropagationDelay() const {
    return propagationDelay;
}

void Component::printOutput() const {
    // Default implementation does nothing
}

void Component::setInput(Component* source) {
    // Default implementation: many components do not take inputs this way
    // Or throw an exception if it's an invalid operation for a generic component.
    throw std::runtime_error("SetInput is not a valid operation for this component type");
}

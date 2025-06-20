#include "Circuit.h"
#include "GateNode.h"
#include "ProbeNode.h"
#include "InputNode.h"
#include <stdexcept>

void Circuit::addComponent(std::unique_ptr<Component> comp) {
    if (components.find(comp->getId()) != components.end()) {
        throw std::runtime_error("Component with ID '" + comp->getId() + "' already exists.");
    }
    components[comp->getId()] = std::move(comp);
}

Component* Circuit::getComponent(const std::string& id) const {
    auto it = components.find(id);
    if (it != components.end()) {
        return it->second.get();
    }
    return nullptr;
}

void Circuit::connect(const std::string& fromId, const std::string& toId) {
    Component* fromComponent = getComponent(fromId);
    Component* toComponent = getComponent(toId);

    if (!fromComponent) {
        throw std::runtime_error("Source component '" + fromId + "' not found.");
    }
    if (!toComponent) {
        throw std::runtime_error("Target component '" + toId + "' not found.");
    }

    fromComponent->addOutput(toComponent);
    toComponent->setInput(fromComponent);
}

const std::map<std::string, std::unique_ptr<Component>>& Circuit::getAllComponents() const {
    return components;
}

#include "ComponentFactory.h"
#include "Component.h"

void ComponentFactory::assign(const std::string& id, Component* p) {
    prototypes[id] = p;
}

Component* ComponentFactory::create(const std::string& id) {
    auto it = prototypes.find(id);
    if (it != prototypes.end()) {
        return it->second->clone();
    }
    return nullptr;
}

ComponentFactory& ComponentFactory::getInstance() {
    static ComponentFactory theInstance;
    return theInstance;
}

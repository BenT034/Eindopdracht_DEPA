#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Component.h"
#include <map>
#include <memory>
#include <string>

class Circuit {
private:
    std::map<std::string, std::unique_ptr<Component>> components;

public:
    Circuit() = default;
    ~Circuit() = default;

    void addComponent(std::unique_ptr<Component> comp);
    Component* getComponent(const std::string& id) const;
    void connect(const std::string& fromId, const std::string& toId);
    const std::map<std::string, std::unique_ptr<Component>>& getAllComponents() const;
};

#endif // CIRCUIT_H

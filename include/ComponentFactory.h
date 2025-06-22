#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <map>
#include <string>

// Forward declaration
class Component;

class ComponentFactory {
public:
    void assign(const std::string& id, Component* p);
    Component* create(const std::string& id);
    static ComponentFactory& getInstance();

    ComponentFactory(const ComponentFactory&) = delete;
    void operator=(const ComponentFactory&) = delete;

private:
    ComponentFactory() = default;
    std::map<std::string, Component*> prototypes;
};

#endif // COMPONENTFACTORY_H

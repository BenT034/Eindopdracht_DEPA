#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Component {
protected:
    std::string id;
    std::vector<Component*> outputs;
    bool _currentOutputValue;

public:
    Component(const std::string& componentId);
    virtual ~Component() = default;

    virtual bool eval() = 0;
    virtual void printOutput() const;
    virtual void setInput(Component* source);
    virtual Component* clone() const = 0;    const std::string& getId() const;
    void setId(const std::string& newId);
    bool getOutputValue() const;
    void addOutput(Component* out);
    const std::vector<Component*>& getOutputs() const;
    double getPropagationDelay() const;
};

#endif // COMPONENT_H

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Component {
protected:
    std::string id;
    std::vector<Component*> outputs;
    double propagationDelay;
    bool _currentOutputValue;

public:
    Component(const std::string& componentId, double delay = 0.0);
    virtual ~Component() = default;

    virtual bool eval() = 0;
    virtual void printOutput() const;
    virtual void setInput(Component* source);

    const std::string& getId() const;
    bool getOutputValue() const;
    void addOutput(Component* out);
    const std::vector<Component*>& getOutputs() const;
    double getPropagationDelay() const;
};

#endif // COMPONENT_H

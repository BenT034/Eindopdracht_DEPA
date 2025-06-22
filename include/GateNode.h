#ifndef GATENODE_H
#define GATENODE_H

#include "Component.h"

class GateNode : public Component {
protected:
    std::vector<Component*> inputs;

public:
    GateNode(const std::string& gateId);
    void setInput(Component* in) override;
public:
    double get_propagation_delay() const; // Method to get propagation delay

private:
    double propagation_delay = 10.0;
};

#endif // GATENODE_H

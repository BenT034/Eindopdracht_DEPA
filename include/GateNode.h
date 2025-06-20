#ifndef GATENODE_H
#define GATENODE_H

#include "Component.h"

class GateNode : public Component {
protected:
    std::vector<Component*> inputs;

public:
    GateNode(const std::string& gateId, double delay);
    void setInput(Component* in) override;
};

#endif // GATENODE_H

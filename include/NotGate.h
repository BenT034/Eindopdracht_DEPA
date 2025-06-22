#ifndef NOTGATE_H
#define NOTGATE_H

#include "GateNode.h"

class NotGate : public GateNode {
private:
    static NotGate prototype;

public:
    NotGate(const std::string& gateId);
    bool eval() override;
    Component* clone() const override;
};

#endif // NOTGATE_H

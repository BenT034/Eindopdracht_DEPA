#ifndef ANDGATE_H
#define ANDGATE_H

#include "GateNode.h"

class AndGate : public GateNode {
private:
    static AndGate prototype;

public:
    AndGate(const std::string& gateId);
    bool eval() override;
    Component* clone() const override;
};

#endif // ANDGATE_H

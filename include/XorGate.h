#ifndef XORGATE_H
#define XORGATE_H

#include "GateNode.h"

class XorGate : public GateNode {
private:
    static XorGate prototype;

public:
    XorGate(const std::string& gateId);
    bool eval() override;
    Component* clone() const override;
};

#endif // XORGATE_H

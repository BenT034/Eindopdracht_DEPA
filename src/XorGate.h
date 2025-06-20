#ifndef XORGATE_H
#define XORGATE_H

#include "GateNode.h"

class XorGate : public GateNode {
public:
    XorGate(const std::string& gateId);
    bool eval() override;
};

#endif // XORGATE_H

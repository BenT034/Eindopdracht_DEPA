#ifndef ANDGATE_H
#define ANDGATE_H

#include "GateNode.h"

class AndGate : public GateNode {
public:
    AndGate(const std::string& gateId);
    bool eval() override;
};

#endif // ANDGATE_H

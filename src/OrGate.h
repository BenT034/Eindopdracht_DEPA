#ifndef ORGATE_H
#define ORGATE_H

#include "GateNode.h"

class OrGate : public GateNode {
public:
    OrGate(const std::string& gateId);
    bool eval() override;
};

#endif // ORGATE_H

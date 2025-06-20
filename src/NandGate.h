#ifndef NANDGATE_H
#define NANDGATE_H

#include "GateNode.h"

class NandGate : public GateNode {
public:
    NandGate(const std::string& gateId);
    bool eval() override;
};

#endif // NANDGATE_H

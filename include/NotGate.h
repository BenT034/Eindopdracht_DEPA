#ifndef NOTGATE_H
#define NOTGATE_H

#include "GateNode.h"

class NotGate : public GateNode {
public:
    NotGate(const std::string& gateId);
    bool eval() override;
};

#endif // NOTGATE_H

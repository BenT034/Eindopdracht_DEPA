#ifndef NORGATE_H
#define NORGATE_H

#include "GateNode.h"

class NorGate : public GateNode {
public:
    NorGate(const std::string& gateId);
    bool eval() override;
};

#endif // NORGATE_H

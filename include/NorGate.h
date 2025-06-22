#ifndef NORGATE_H
#define NORGATE_H

#include "GateNode.h"

class NorGate : public GateNode {
private:
    static NorGate prototype;

public:
    NorGate(const std::string& gateId);
    bool eval() override;
    Component* clone() const override;
};

#endif // NORGATE_H

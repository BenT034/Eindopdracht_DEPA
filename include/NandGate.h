#ifndef NANDGATE_H
#define NANDGATE_H

#include "GateNode.h"

class NandGate : public GateNode {
private:
    static NandGate prototype;

public:
    NandGate(const std::string& gateId);
    bool eval() override;
    Component* clone() const override;
};

#endif // NANDGATE_H

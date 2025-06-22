#ifndef ORGATE_H
#define ORGATE_H

#include "GateNode.h"

class OrGate : public GateNode {
private:
    static OrGate prototype;

public:
    OrGate(const std::string& gateId);
    bool eval() override;
    Component* clone() const override;
};

#endif // ORGATE_H

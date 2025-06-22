#ifndef PROBENODE_H
#define PROBENODE_H

#include "Component.h"
#include <stdexcept>

class ProbeNode : public Component {
private:
    Component* inputSource;
    static ProbeNode prototype;

public:
    ProbeNode(const std::string& probeId);    bool eval() override;
    void printOutput() const override;
    void setInput(Component* source) override;
    Component* clone() const override;
};

#endif // PROBENODE_H

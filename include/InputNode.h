#ifndef INPUTNODE_H
#define INPUTNODE_H

#include "Component.h"

class InputNode : public Component {
private:
    static InputNode prototypeHigh;
    static InputNode prototypeLow;

public:
    InputNode(const std::string& nodeId, bool initialValue = false);

    bool eval() override;
    void setValue(bool v);
    Component* clone() const override;
};

#endif // INPUTNODE_H

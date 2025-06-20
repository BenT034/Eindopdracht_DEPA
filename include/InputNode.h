#ifndef INPUTNODE_H
#define INPUTNODE_H

#include "Component.h"

class InputNode : public Component {
public:
    InputNode(const std::string& nodeId, bool initialValue = false);

    bool eval() override;
    void setValue(bool v);
};

#endif // INPUTNODE_H

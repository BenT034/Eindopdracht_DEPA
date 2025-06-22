#include "InputNode.h"

// Static member initialization
InputNode InputNode::prototypeHigh("INPUT_HIGH", true);
InputNode InputNode::prototypeLow("INPUT_LOW", false);

InputNode::InputNode(const std::string& nodeId, bool initialValue)
    : Component(nodeId) {
    _currentOutputValue = initialValue;
}

bool InputNode::eval() {
    return _currentOutputValue;
}

void InputNode::setValue(bool v) {
    _currentOutputValue = v;
}

Component* InputNode::clone() const {
    return new InputNode(*this);
}

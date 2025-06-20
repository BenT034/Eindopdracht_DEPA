#include "InputNode.h"

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

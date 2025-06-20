#include "GateNode.h"

GateNode::GateNode(const std::string& gateId, double delay)
    : Component(gateId, delay) {}

void GateNode::setInput(Component* in) {
    inputs.push_back(in);
}

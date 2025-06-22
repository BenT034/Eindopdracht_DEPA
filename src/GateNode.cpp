#include "GateNode.h"

GateNode::GateNode(const std::string& gateId)
    : Component(gateId) {}

void GateNode::setInput(Component* in) {
    inputs.push_back(in);
}

double GateNode::get_propagation_delay() const
{
    return propagation_delay;
}


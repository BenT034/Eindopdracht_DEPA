#include "ComponentFactory.h"
#include <unordered_map>
#include <functional>
#include "InputNode.h"
#include "ProbeNode.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "XorGate.h"
#include <stdexcept>

namespace {
    using Creator = std::function<std::unique_ptr<Component>(const std::string&)>;
    const std::unordered_map<std::string, Creator> creators = {
        {"INPUT_HIGH", [](const std::string& id){ return std::make_unique<InputNode>(id, true); }},
        {"INPUT_LOW",  [](const std::string& id){ return std::make_unique<InputNode>(id, false); }},
        {"AND",        [](const std::string& id){ return std::make_unique<AndGate>(id); }},
        {"OR",         [](const std::string& id){ return std::make_unique<OrGate>(id); }},
        {"NOT",        [](const std::string& id){ return std::make_unique<NotGate>(id); }},
        {"NAND",       [](const std::string& id){ return std::make_unique<NandGate>(id); }},
        {"NOR",        [](const std::string& id){ return std::make_unique<NorGate>(id); }},
        {"XOR",        [](const std::string& id){ return std::make_unique<XorGate>(id); }},
        {"PROBE",      [](const std::string& id){ return std::make_unique<ProbeNode>(id); }}
    };
}

std::unique_ptr<Component> ComponentFactory::create(const std::string& id, const std::string& type) {
    auto it = creators.find(type);
    if (it != creators.end()) {
        return it->second(id);
    }
    throw std::runtime_error("Unknown component type '" + type + "' for id '" + id + "'");
}

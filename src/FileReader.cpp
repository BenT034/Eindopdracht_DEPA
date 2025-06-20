#include "FileReader.h"
#include "InputNode.h"
#include "ProbeNode.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "XorGate.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Helper to trim from start
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// Helper to trim from end
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// Helper to trim from both ends
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

std::unique_ptr<Circuit> FileReader::parse(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    auto circuit = std::make_unique<Circuit>();
    std::string line;

    while (std::getline(file, line)) {
        line = cleanLine(line);
        if (line.empty()) continue;

        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) {
            throw std::runtime_error("Invalid line format (missing ':'): " + line);
        }

        std::string id = line.substr(0, colonPos);
        trim(id);

        std::string definition = line.substr(colonPos + 1);
        if (definition.back() == ';') {
            definition.pop_back();
        }
        trim(definition);

        if (circuit->getComponent(id) == nullptr) {
            // Node does not exist, so this is a declaration
            std::unique_ptr<Component> comp;
            if (definition == "INPUT_HIGH") {
                comp = std::make_unique<InputNode>(id, true);
            } else if (definition == "INPUT_LOW") {
                comp = std::make_unique<InputNode>(id, false);
            } else if (definition == "AND") {
                comp = std::make_unique<AndGate>(id);
            } else if (definition == "OR") {
                comp = std::make_unique<OrGate>(id);
            } else if (definition == "NOT") {
                comp = std::make_unique<NotGate>(id);
            } else if (definition == "NAND") {
                comp = std::make_unique<NandGate>(id);
            } else if (definition == "NOR") {
                comp = std::make_unique<NorGate>(id);
            } else if (definition == "XOR") {
                comp = std::make_unique<XorGate>(id);
            } else if (definition == "PROBE") {
                comp = std::make_unique<ProbeNode>(id);
            } else {
                throw std::runtime_error("Unknown component type '" + definition + "' for new component '" + id + "'");
            }
            circuit->addComponent(std::move(comp));
        } else {
            // Node exists, so this is a connection definition
            std::stringstream ss(definition);
            std::string toId;
            while (std::getline(ss, toId, ',')) {
                trim(toId);
                if (!toId.empty()) {
                    circuit->connect(id, toId);
                }
            }
        }
    }

    return circuit;
}

std::string FileReader::cleanLine(const std::string& line) const {
    std::string cleanedLine = line;
    size_t commentPos = cleanedLine.find('#');
    if (commentPos != std::string::npos) {
        cleanedLine = cleanedLine.substr(0, commentPos);
    }
    trim(cleanedLine);
    return cleanedLine;
}

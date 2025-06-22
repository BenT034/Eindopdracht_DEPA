#include "FileReader.h"
#include "ComponentFactory.h"
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
            // Node does not exist; create via factory
            Component* component = ComponentFactory::getInstance().create(definition);
            if (component) {
                component->setId(id);
                circuit->addComponent(std::unique_ptr<Component>(component));
            }
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

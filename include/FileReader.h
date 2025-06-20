#ifndef FILEREADER_H
#define FILEREADER_H

#include "Circuit.h"
#include <memory>
#include <string>

class FileReader {
public:
    std::unique_ptr<Circuit> parse(const std::string& filename);

private:
    std::string cleanLine(const std::string& line) const;
};

#endif // FILEREADER_H

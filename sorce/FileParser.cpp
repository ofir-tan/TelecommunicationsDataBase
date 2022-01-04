#include "FileParser.h"

Record FileParser::getParsedLine(const char delimiter) {

    vector<string> parsedStringVector;
    string segment; // auxiliary variable
    getline(file, segment);
    stringstream line(segment);

    while (std::getline(line, segment, delimiter))
        parsedStringVector.push_back(segment);

    return Record({parsedStringVector});
}
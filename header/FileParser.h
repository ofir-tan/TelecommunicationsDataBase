#pragma once
#include <fstream>
#include <sstream>
#include "Record.h"

using namespace std;

class FileParser {
    ifstream file;
public:
    explicit FileParser(const string &path) { file.open(path); };
    Record getParsedLine(char delimiter = '|');
    bool done() { return file.eof(); }
    ~FileParser() { file.close(); }
};
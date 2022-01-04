#pragma once
#include <utility>

#include "Data.h"
#include "Record.h"
#include "Services.h"
#include "istream"

using namespace std;

class BasicDataBase {
    // pure virtual class (base class for databases)
protected:
    Data dataUsed;
    string operatorID;
protected:
    static string operatorBrandName(const string &id);
public:
    BasicDataBase() : operatorID("NULL") {};
    explicit BasicDataBase(string operatorID) :
            operatorID(std::move(operatorID)) {};
    virtual void update(const Record &data) = 0;
};
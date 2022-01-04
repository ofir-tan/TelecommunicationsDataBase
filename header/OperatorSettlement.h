#pragma once

#include "BasicDataBase.h"

class OperatorSettlement : public BasicDataBase {
private:
    Services services;
public:
    // constructor:
    explicit OperatorSettlement(const string &operatorID = "NULL") : BasicDataBase(operatorID) {};
    // methods:
    void update(const Record &data) override;
    friend ostream &operator<<(ostream &os, const OperatorSettlement &settlement);
};
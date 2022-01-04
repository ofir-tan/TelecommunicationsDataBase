#pragma once
#include <ostream>
#include <utility>
#include "Services.h"
#include "BasicDataBase.h"

using namespace std;

class CustomerBilling : public BasicDataBase {
private:
    string customerID;
    Services withinMobileOperator;
    Services outsideMobileOperator;
public:
    CustomerBilling() : BasicDataBase("NULL"), customerID("NULL") {};
    explicit CustomerBilling(string customerID, const string &operatorID) :
            BasicDataBase(operatorID), customerID(std::move(customerID)) {};
    void update(const Record &data) override;
    friend ostream &operator<<(ostream &os, const CustomerBilling &billing);
};
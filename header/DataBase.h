#pragma once
#include <ostream>
#include <iostream>
#include <fstream>
#include "CustomerBilling.h"
#include "OperatorSettlement.h"

using namespace std;
typedef unordered_map<string, CustomerBilling> CustomerHashTable;
typedef unordered_map<string, OperatorSettlement> OperatorHashTable;

class DataBase {
private:
    CustomerHashTable customerDataBase;
    OperatorHashTable operatorDataBase;
private:
    void updateCustomerDataBase(const Record &record);
    void updateOperatorDataBase(const Record &record);
public:
    DataBase() = default;
    // methods:
    void printCustomerDataBase();
    void printOperatorDataBase();
    void update(const Record &record);
    // find methods:
    CustomerBilling findCustomer(const string &id);
    OperatorSettlement findOperator(const string &id);
    // save database:
    void saveCustomerDataBase(const string &path="customer.out.txt");
    void saveOperatorDataBase(const string &path="operator.out.txt");
};
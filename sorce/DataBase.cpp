#include "DataBase.h"
#include "thread"

void DataBase::update(const Record &record) {
    if (record.empty()) return;
    updateOperatorDataBase(record);
    updateCustomerDataBase(record);

//    thread t1(&DataBase::updateOperatorDataBase, this, record);
//    thread t2(&DataBase::updateCustomerDataBase, this, record);
//    t1.join();
//    t2.join();
}

void DataBase::updateOperatorDataBase(const Record &record) {
    operatorDataBase.try_emplace(record.operatorID, record.operatorID);
    operatorDataBase[record.operatorID].update(record);
}

void DataBase::updateCustomerDataBase(const Record &record) {
    customerDataBase.try_emplace(record.id, record.id, record.operatorID);
    customerDataBase[record.id].update(record);
}

void DataBase::printCustomerDataBase() {
    cout << "# Customers Data Base:" << endl;
    for (auto const&[name, data]: customerDataBase)
        cout << data << endl;
}

void DataBase::printOperatorDataBase() {
    cout << "# Operator Data Base:" << endl;
    for (auto const&[name, data]: operatorDataBase)
        cout << data << endl;
}

void DataBase::saveCustomerDataBase(const string &path) {
    ofstream file(path);
    file << "# Customers Data Base:" << endl;
    for (auto const&[name, data]: customerDataBase)
        file << data << endl;
    file.close();
    cout << "Customer DataBase Successfully Saved At: /" << path << endl;
}

void DataBase::saveOperatorDataBase(const string &path) {
    ofstream file(path);
    file << "# Operator Data Base:" << endl;
    for (auto const&[name, data]: operatorDataBase)
        file << data << endl;
    file.close();
    cout << "Operator DataBase Successfully Saved At: /" << path << endl;
}

CustomerBilling DataBase::findCustomer(const string &id) {
    return customerDataBase.count(id) ? customerDataBase[id] : CustomerBilling();
}

OperatorSettlement DataBase::findOperator(const string &id) {
    return operatorDataBase.count(id) ? operatorDataBase[id] : OperatorSettlement();
}

#include <iostream>
#include "DataBase.h"
#include "ThreadPool.h"
#include "Timer.h"

#define THREAD_NUM 5
#define PATH R"(C:\Users\AppTa\Documents\Programming\C++\TelecDatabase\data\file.cdr)"

int main() {

    DataBase dataBase;
    Timer timer("TelecDatabase");

//    cout << "Execution with single thread:" << endl;
//    FileParser parser(PATH);
//    while (!parser.done())
//        dataBase.update(parser.getParsedLine());


    cout << "Execution with " << THREAD_NUM << " threads:" << endl;
    ThreadPool threadPool(dataBase, PATH, THREAD_NUM);
    threadPool.start();
    cout << dataBase.findCustomer("1399753") << endl;

    dataBase.printOperatorDataBase();
//    dataBase.printCustomerDataBase();
    dataBase.saveOperatorDataBase();
    dataBase.saveCustomerDataBase();

    return 0;
}

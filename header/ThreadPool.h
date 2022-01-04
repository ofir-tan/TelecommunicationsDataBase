#pragma once

#include "queue"
#include <mutex>
#include "thread"
#include "Record.h"
#include "functional"
#include "DataBase.h"
#include "atomic"
#include "FileParser.h"

using namespace std;

class ThreadPool {
private:
    bool done;
    mutex mx;
    FileParser parser;
    size_t threadsNum;
    DataBase &dataBase;
    vector<thread> threads;
    queue<Record> pendingTasks{};
private:
    void job();
    void join();
    void importJobs();
public:
    explicit ThreadPool(DataBase &dataBase, const string &path, size_t threadsNum = 5) :
            dataBase(dataBase), parser(path), threadsNum(threadsNum), done(false) {};
    ~ThreadPool() { join(); };
    void start();
    DataBase getDataBase() { return dataBase; }
};
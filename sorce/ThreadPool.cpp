#include "ThreadPool.h"

void ThreadPool::job() {
    while (!done || !pendingTasks.empty()) {
        lock_guard<mutex> lock(mx);
        if (!pendingTasks.empty()) {
            dataBase.update(pendingTasks.front());
            pendingTasks.pop();
        }
    }
}

void ThreadPool::start() {
    thread importer(&ThreadPool::importJobs, this);
    for (int i = 0; i < threadsNum; i++)
        threads.emplace_back(&ThreadPool::job, this);
    importer.join();
    join();
}

void ThreadPool::importJobs() {
    // push 'jobs' to queue
    while (true) {
        Record record = parser.getParsedLine();
        if (record.empty()) break;
        lock_guard<mutex> lock(mx);
        pendingTasks.push(record);
    }
    done = true;
}

void ThreadPool::join() {
    for (auto &thread: threads)
        if (thread.joinable())
            thread.join();
}

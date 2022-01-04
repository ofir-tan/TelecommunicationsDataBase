#pragma once
#include <iostream>
#include <chrono>
#include <utility>

using namespace std;

struct Timer {
    std::chrono::time_point<chrono::system_clock> start, end;
    std::chrono::duration<double> duration{};
    const string title;
    explicit Timer(string title = "NULL") : title(std::move(title)) {
        start = chrono::high_resolution_clock::now();
        cout << "# " << this->title << " :: " << "timer starts here...\n" << endl;
    }

    ~Timer() {
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "\n# " << title << " | elapsed time: " << duration.count() << " [seconds]\n";
    }
};
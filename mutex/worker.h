#pragma once

#include <thread>
#include <mutex>

using namespace std;

class Worker {
public:
    Worker(int*, mutex*) ;
    ~Worker();
    
    void work();
    
private:
    int* counter_;
    mutex *mutex_;
};


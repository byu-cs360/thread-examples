#pragma once

#include <thread>

using namespace std;

class Worker {
public:
    Worker(int*) ;
    ~Worker();
    
    void work();
    
private:
    int* counter_;
};


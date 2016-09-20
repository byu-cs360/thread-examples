#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Second {
public:
    Second(bool*, mutex*, condition_variable*) ;
    ~Second();
    
    void work();
    
private:
    bool* ready_;
    mutex *mutex_;
    condition_variable* cv_;
};


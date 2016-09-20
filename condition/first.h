#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class First {
public:
    First(bool*, mutex*, condition_variable*) ;
    ~First();
    
    void work();
    
private:
    bool* ready_;
    mutex *mutex_;
    condition_variable* cv_;
};


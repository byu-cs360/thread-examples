#include <unistd.h>
#include <iostream>

#include "first.h"

First::First(bool* ready, mutex* mutex, condition_variable* cv) {
    ready_ = ready;
    mutex_ = mutex;
    cv_ = cv;
}

First::~First() {
}


void First::work() {
    sleep(5);
    unique_lock<mutex> lock(*mutex_);
    *ready_ = true;
    cout << "First thread is awake and setting condition variable." << endl;
    cv_->notify_one();
}

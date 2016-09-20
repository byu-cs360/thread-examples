#include <iostream>

#include "second.h"

Second::Second(bool* ready, mutex* mutex, condition_variable* cv) {
    ready_ = ready;
    mutex_ = mutex;
    cv_ = cv;
}

Second::~Second() {
}


void Second::work() {
    unique_lock<mutex> lock(*mutex_);
    while (not *ready_) {
        cout << "Second thread is waiting for the condition variable." << endl;
        cv_->wait(lock);
    }
    cout << "Second thread is awake and finished." << endl;
}

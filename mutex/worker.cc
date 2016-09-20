#include <unistd.h>
#include <iostream>

#include "worker.h"

Worker::Worker(int* counter, mutex* mutex) {
    counter_ = counter;
    mutex_ = mutex;
}

Worker::~Worker() {
}


void Worker::work() {
    int val;
    long r;

    // Each thread fetches, prints, and increments the counter 100 times.
    // We use sleep to represent work being done in the meantime.
    for (int i = 0; i < 100; i++) {
        mutex_->lock();
        val = *counter_;
        r = random() % 10;
        usleep(r);
        cout << "Thread " << this_thread::get_id() << " has counter " << val + 1 << endl;
        *counter_ += 1;
        mutex_->unlock();
        r = random() % 10;
        usleep(r);
    }
}

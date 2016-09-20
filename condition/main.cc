// Taken from Unix Network Programming: The Sockets Networking API, Volume 1,
// Third Edition, by W. Richard Stevens, Bill Fenner, and Andrew M. Rudoff

// Page 700

// This program demonstrates how to use a mutex to solve the
// synchronization problem.

#include <thread>
#include <mutex>
#include <condition_variable>

#include "first.h"
#include "second.h"

using namespace std;

void create_first(bool* ready, mutex* mutex, condition_variable* cv) {
    First f(ready,mutex,cv);
    f.work();
}

void create_second(bool* ready, mutex* mutex, condition_variable* cv) {
    Second s(ready,mutex,cv);
    s.work();
}


int
main(int argc, char **argv)
{
    bool ready = false;
    mutex mutex;
    condition_variable cv;

    srandom(1000);

    // create two threads
    thread t1(create_first,&ready,&mutex,&cv);
    thread t2(create_second,&ready,&mutex,&cv);

    // wait for both threads to terminate
    t1.join();
    t2.join();
}


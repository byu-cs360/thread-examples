// Taken from Unix Network Programming: The Sockets Networking API, Volume 1,
// Third Edition, by W. Richard Stevens, Bill Fenner, and Andrew M. Rudoff

// Page 700

// This program demonstrates how to use a mutex to solve the
// synchronization problem.

#include <thread>
#include <mutex>

#include "worker.h"

using namespace std;

void create(int* counter, mutex* mutex) {
    Worker*  w = new Worker(counter,mutex);
    w->work();
}

int
main(int argc, char **argv)
{
    int counter = 0;
    mutex mutex;

    srandom(1000);

    // create two threads
    thread t1(create,&counter,&mutex);
    thread t2(create,&counter,&mutex);

    // wait for both threads to terminate
    t1.join();
    t2.join();
}


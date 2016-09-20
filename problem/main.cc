// Taken from Unix Network Programming: The Sockets Networking API, Volume 1,
// Third Edition, by W. Richard Stevens, Bill Fenner, and Andrew M. Rudoff

// Page 699

// This program demonstrates a synchronization problem.  Two threads
// share a counter variable that is initialized to zero.  They each
// try to increment the counter 100 times each. The result of the
// program should be that each thread has a unique value for the counter, and
// the counter ends up at 200.  However, if a synchronization problem exists, neither
// of these may occur.

#include <thread>

#include "worker.h"

using namespace std;

void create(int* counter) {
    Worker*  w = new Worker(counter);
    w->work();
}

int
main(int argc, char **argv)
{
    int counter = 0;

    srandom(1000);

    // create two threads
    thread t1(create,&counter);
    thread t2(create,&counter);

    // wait for both threads to terminate
    t1.join();
    t2.join();
}


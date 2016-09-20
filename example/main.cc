// C includes
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// C++ includes
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// thread routine
void print(int number) {

    // generate random number
    float r = (float)rand()/((float)RAND_MAX);
    
    // sleep
    sleep(r);
    
    cout << "Thread " << number << " says hello." << endl;

}

int
main(int argc, char **argv) {
    int option;

    // setup default arguments
    int num_threads = 10;

    // process command line options using getopt()
    // see "man 3 getopt"
    while ((option = getopt(argc,argv,"n:")) != -1) {
        switch (option) {
            case 'n':
                num_threads = atoi(optarg);
                break;
            default:
                cout << "server [-p port]" << endl;
                exit(EXIT_FAILURE);
        }
    }

    // initialize random seed:
    srand(time(NULL));

    // keep track of vectors
    vector<thread> threads;
    
    for (int i=0; i<num_threads; i++) {
        // create thread
        threads.push_back(thread(print,i+1));
    }

    // wait for threads to terminate.
    for (int i=0; i<num_threads; i++) {
        threads[i].join();
    }
}


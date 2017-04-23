#include "../include/SyncDaemon.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {
    SyncDaemon sd;
    typedef chrono::high_resolution_clock Time;
    typedef chrono::milliseconds ms;
    typedef chrono::duration<float> fsec;

    const char *from = argv[1];
    const char *to = argv[2];

    if(to == nullptr || from == nullptr) {
        cout << "SyncFilesDaemon: \n\t" << "Paths not provided!\n";
        return 0;
    }

    while(true) {
        auto t0 = Time::now();
        sd.sync(from, to);
        auto t1 = Time::now();
        fsec fs = t1 - t0;
        ms d = chrono::duration_cast<ms>(fs);
        cout << "SyncFilesDaemon: \n\t" << "from: " << from << ", to: " << to << "\n\t" << "Elapsed time: " << d.count() << "ms\n";
        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}
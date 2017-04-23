#include "../include/SyncJobs.h"

void SyncJobs::Workers::add(std::thread& t) {
    workers.push_back(t);
}

void SyncJobs::Workers::join() {
    for(auto& thread : workers) {
        thread.join();
    }
}
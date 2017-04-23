#ifndef SYNCFILESDAEMON_WORKERS_H
#define SYNCFILESDAEMON_WORKERS_H

#include <vector>
#include <thread>

namespace SyncJobs {
    class Workers {

    public:
        void add(std::thread& t);
        void join();
    private:
        std::vector<std::thread> workers;
    };
}

#endif //SYNCFILESDAEMON_WORKERS_H

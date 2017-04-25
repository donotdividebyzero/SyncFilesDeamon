#ifndef SYNCFILESDAEMON_TASKQUEUE_H
#define SYNCFILESDAEMON_TASKQUEUE_H

#include <queue>
#include <string>
#include <tuple>

namespace SyncJobs {
    class TaskQueue {
        public:
            std::tuple<std::string, std::string> pop();
            void push(std::tuple<std::string, std::string> task);
        private:
            std::queue<std::tuple<std::string, std::string>> queue;
    };
}



#endif //SYNCFILESDAEMON_TASKQUEUE_H

#ifndef SYNCFILESDAEMON_SYNC_DAEMON_H
#define SYNCFILESDAEMON_SYNC_DAEMON_H

#include <memory>

using namespace std;

class SyncDaemon {
public:
    void sync(const string from, const string to);
};

#endif //SYNCFILESDAEMON_SYNC_DAEMON_H

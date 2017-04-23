#ifndef SYNCFILESDAEMON_SYNC_DAEMON_H
#define SYNCFILESDAEMON_SYNC_DAEMON_H

#include <memory>
#include <vector>
#include <dirent.h>
#include <unordered_map>
#include <stdio.h>

using namespace std;

class SyncDaemon {
public:
    void sync(const string source, const string destination);
    void removeNotExisting(unordered_map<string, bool> &source_files, const string &destination);
};

#endif //SYNCFILESDAEMON_SYNC_DAEMON_H

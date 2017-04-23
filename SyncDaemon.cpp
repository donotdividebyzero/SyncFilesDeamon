#define DIRECTORY_SEPARATOR "/"
#include "SyncDaemon.h"
#include "FileStatus.h"
#include <dirent.h>

using namespace std;

void SyncDaemon::sync(const string from, const string to) {
    unique_ptr<DIR, function<int(DIR*)>> dir_from(opendir(from.c_str()), &closedir);
    if(dir_from.get() == nullptr) return;

    unique_ptr<DIR, function<int(DIR*)>> dir_to(opendir(to.c_str()), &closedir);

    if(dir_to.get() == nullptr) {
        mkdir(to.c_str(), 0755);
    }

    struct dirent* file;
    while( (file = readdir(dir_from.get())) not_eq nullptr ) {
        if ( file->d_name[0] == '.') continue; // not copying hidden files or hidden directories
        FileStatus fileStatus{ from + DIRECTORY_SEPARATOR + file->d_name };
        if (fileStatus.is_directory()) {
                SyncDaemon sd;
                sd.sync(from + DIRECTORY_SEPARATOR + file->d_name, to + DIRECTORY_SEPARATOR + file->d_name);
        }
        fileStatus.updateFileTo(to + DIRECTORY_SEPARATOR + file->d_name);
    }

    delete file;
}

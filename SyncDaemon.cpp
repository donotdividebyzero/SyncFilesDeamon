#define DIRECTORY_SEPARATOR "/"

#include "SyncDaemon.h"
#include "FileStatus.h"

using namespace std;

void SyncDaemon::sync(const string source, const string destination) {
    unique_ptr<DIR, function<int(DIR*)>> dir_from(opendir(source.c_str()), &closedir);
    if(dir_from.get() == nullptr) return;

    unique_ptr<DIR, function<int(DIR*)>> dir_to(opendir(destination.c_str()), &closedir);

    if(dir_to.get() == nullptr) {
        mkdir(destination.c_str(), 0755);
    }

    unordered_map<std::string, bool> files;

    struct dirent* file;
    while( (file = readdir(dir_from.get())) not_eq nullptr ) {
        if ( file->d_name[0] == '.') continue; // not copying hidden files or hidden directories
        const string &destination_file_name = destination + DIRECTORY_SEPARATOR + file->d_name;
        const string &source_file_name = source + DIRECTORY_SEPARATOR + file->d_name;

        files.insert({destination_file_name, true });
        FileStatus fileStatus{source_file_name};
        if (fileStatus.is_directory()) {
                SyncDaemon sd;
                sd.sync(source_file_name, destination_file_name);
        }
        fileStatus.updateFileTo(destination_file_name);
    }

    removeNotExisting(files, destination);

    delete file;
}

void SyncDaemon::removeNotExisting(unordered_map<string, bool> &source_files, const string &destination) {
    struct dirent* file;
    unique_ptr<DIR, function<int(DIR*)>> dir_to(opendir(destination.c_str()), &closedir);

    unordered_map<std::string, bool> files_to;
    while( (file = readdir(dir_to.get()))) {
        files_to.insert( {destination + DIRECTORY_SEPARATOR + file->d_name, true});
    }

    delete file;

    for(auto source_to : source_files) {
        files_to.erase(source_to.first.c_str());
    }

    for(auto file_to_erase : files_to) {
        remove(file_to_erase.first.c_str());
    }
}

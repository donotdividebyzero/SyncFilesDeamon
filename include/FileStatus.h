#ifndef SYNCFILESDAEMON_FILESTATUS_H
#define SYNCFILESDAEMON_FILESTATUS_H

#include <string>
#include <sys/stat.h>

class FileStatus {

public:
    FileStatus() = default;
    explicit FileStatus(const std::string file_name);
    bool is_directory();
    void updateFileTo(const std::string to);

private:
    const std::string file_name;
    struct stat stat_buf;
    void copyFile(const std::string &destination, std::ifstream &from_file);
};

#endif //SYNCFILESDAEMON_FILESTATUS_H

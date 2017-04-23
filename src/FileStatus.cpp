#include "../include/FileStatus.h"
#include <sstream>
#include <fstream>

using namespace std;

FileStatus::FileStatus(string file_name) : file_name{ file_name } {
    lstat(file_name.c_str(), &stat_buf);
}

bool FileStatus::is_directory() {
    return (stat_buf.st_mode & S_IFMT) == S_IFDIR;
}

void FileStatus::updateFileTo(const string to) {
    ifstream to_file{to.c_str()}, from_file{file_name};

    if(from_file.tellg() != to_file.tellg()) {
        string line_from;
        ofstream to_file_(to.c_str());
        while (getline(from_file, line_from))
        {
            to_file_ << line_from << '\n';
        }
    }

}
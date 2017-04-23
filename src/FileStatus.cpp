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
    ofstream to_file(to.c_str());
    ifstream from_file(file_name);
    string line_from;

    while (getline(from_file, line_from))
    {
        to_file << line_from << '\n';
    }
}
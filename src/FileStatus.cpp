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

    if(to_file == NULL) {
        copyFile(to, from_file);
        return;
    }

    if(from_file.tellg() != to_file.tellg()) {
        copyFile(to, from_file);
        return;
    }

}

void FileStatus::copyFile(const string &destination, ifstream &from_file) {
    string line_from;
    ofstream destination_file(destination.c_str());
    while (getline(from_file, line_from))
    {
        destination_file << line_from << '\n';
    }
}
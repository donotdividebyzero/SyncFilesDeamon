Complie file using:

g++ -o3 -std=c++11 -o yourNameHere src/main.cpp include/SyncDaemon.h src/SyncDaemon.cpp src/FileStatus.cpp include/FileStatus.h

Then you can run it ./yourNameHere "absolute path to directory you want to sync" "absolute path to result directory"
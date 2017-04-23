Complie file using:

If you are using Linux use make.

If not complie using this:
g++ -o3 -std=c++11 -o Daemon src/main.cpp include/SyncDaemon.h src/SyncDaemon.cpp src/FileStatus.cpp include/FileStatus.h

Then you can run it ./Daemon "absolute path to directory you want to sync" "absolute path to result directory"

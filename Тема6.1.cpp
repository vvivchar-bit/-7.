#include <iostream>
using namespace std;

class IExecutable {
public:
    virtual int start() = 0;
    virtual void run() = 0;
    virtual void end() = 0;

    virtual ~IExecutable() {}
};

class DownloadTask : public IExecutable {
public:
    int start() override {
        cout << "DownloadTask started" << endl;
        return 1;
    }

    void run() override {
        cout << "Downloading data..." << endl;
    }

    void end() override {
        cout << "DownloadTask finished" << endl;
    }
};

class BackupTask : public IExecutable {
public:
    int start() override {
        cout << "BackupTask started" << endl;
        return 1;
    }

    void run() override {
        cout << "Creating backup..." << endl;
    }

    void end() override {
        cout << "BackupTask finished" << endl;
    }
};

void executeCallback(IExecutable* task) {
    if (task->start()) {
        task->run();
        task->end();
    }
}

int main() {
    DownloadTask d;
    BackupTask b;

    executeCallback(&d);
    cout << endl;
    executeCallback(&b);

    return 0;
}

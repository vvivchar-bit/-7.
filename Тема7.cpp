#include <iostream>
using namespace std;

class IExecutable {
public:
    virtual int start() = 0;
    virtual void run() = 0;
    virtual void end() = 0;

    virtual ~IExecutable() {
        cout << "IExecutable destructor" << endl;
    }
};

class Work : public IExecutable {
public:
    int start() override {
        cout << "Work started" << endl;
        return 1;
    }

    void run() override {
        cout << "Work is running" << endl;
    }

    void end() override {
        cout << "Work ended" << endl;
    }

    ~Work() {
        cout << "Work destructor" << endl;
    }
};

class Game : public IExecutable {
public:
    int start() override {
        cout << "Game started" << endl;
        return 1;
    }

    void run() override {
        cout << "Game is running" << endl;
    }

    void end() override {
        cout << "Game ended" << endl;
    }

    ~Game() {
        cout << "Game destructor" << endl;
    }
};

int main() {
    IExecutable* obj1 = new Work();
    IExecutable* obj2 = new Game();

    obj1->start();
    obj1->run();
    obj1->end();

    cout << endl;

    obj2->start();
    obj2->run();
    obj2->end();

    delete obj1;
    delete obj2;

    return 0;
}

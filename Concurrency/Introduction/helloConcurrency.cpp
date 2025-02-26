#include <iostream>
#include <thread>
using namespace std;

void hello() {
    cout << "Hello World\n";
}

int main() {
    thread t(hello);
    t.join();
    return 0;
}
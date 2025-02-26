#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello World\n";
}

int main() {
    std::thread t(hello);
    t.join();
    return 0;
}
#include <iostream>
int main() {
    std::freopen("in.txt", "w", stdout);
    for(int i = 10000; i <= 5000000; i += 10000) std::cout << i << "\n";
    return 0;
}
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;
using namespace chrono;

const int MIN = -5000000;
const int MAX = 5000000;

atomic<int> result(-1);

void linearSearchThread(const vector<int>& v, int target, int start, int end) {
    for (int i = start; i < end; i++) {
        if (v[i] == target) {
            result.store(i);  
            return;  
        }
    }
}

int main() {
    mt19937 generator;
    uniform_int_distribution<> distribution(MIN, MAX);
    freopen("in.txt", "r", stdin);
    ofstream file("threaded_ls.csv");
    file << "ip_size,time,found\n";
    for (int i = 0; i < 500; i++) {
        int n;
        cin >> n;
        file << n << ",";
        vector<int> v(n);
        for (int &i : v) i = distribution(generator);
        sort(v.begin(), v.end());
        int target = distribution(generator);
        auto start = high_resolution_clock::now();
        int num_threads = 4; 
        int chunk_size = n / num_threads;
        vector<thread> threads;
        for (int t = 0; t < num_threads; t++) {
            int start_idx = t * chunk_size;
            int end_idx = (t == num_threads - 1) ? n : (t + 1) * chunk_size;
            threads.push_back(thread(linearSearchThread, cref(v), target, start_idx, end_idx));
        }
        for (auto& t : threads) t.join();
        auto end = high_resolution_clock::now();
        duration<double> d = end - start;
        file << d.count() << ",";

        if (result.load() != -1) file << "1\n";
        else file << "0\n";
        result.store(-1);
    }
    return 0;
}

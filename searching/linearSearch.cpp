#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

const int MIN = -5000000;
const int MAX = 5000000;

int linearSearch(vector<int> &v, int target) {
    int n = v.size();
    for(int i = 0; i < n; i++) {
        if(v[i] == target) return i;
    }
    return -1;
}

int main() {
    mt19937 generator;
    uniform_int_distribution<> distribution(MIN, MAX);
    freopen("in.txt", "r", stdin);
    ofstream file("ls.csv");
    file << "ip_size,time,found\n";
    for(int i = 0; i < 500; i++) {
        int n;
        cin >> n;
        file << n << ",";
        vector<int> v(n);
        for(int &i : v) i = distribution(generator);
        sort(v.begin(), v.end());
        int target = distribution(generator);
        auto start = high_resolution_clock::now();
        int ans = linearSearch(v, target);
        auto end = high_resolution_clock::now();
        duration<double> d = end - start;
        file << d.count() << ",";
        if (v[ans] == target) file << "1\n";
        else file << "0\n";
    }
    return 0;
}

// Total Time: 6m:17s
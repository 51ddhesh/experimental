#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

const int MIN = -5000000;
const int MAX = 5000000;

int binarySearch(vector<int> &v, int target) {
    int i = 0, j = v.size() - 1;
    while(i <= j) {
        int m = i + (j - i) / 2;
        if (v[m] == target) return m;
        if (v[m] < target) i = m + 1;
        if (v[m] > target) j = m - 1;
    }
    return -1;
}

int main() {
    freopen("in.txt", "r", stdin);
    mt19937 generator;
    uniform_int_distribution<> distribution(MIN, MAX);
    ofstream file("bs.csv");
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
        int ans = binarySearch(v, target);
        auto end = high_resolution_clock::now();
        duration<double> d = end - start;
        file << d.count() << ",";
        if (v[ans] == target) file << "1\n";
        else file << "0\n";
    }

    return 0;
}

// Total Time: 6m:12s
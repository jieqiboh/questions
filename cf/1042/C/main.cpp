#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <numeric>
#include <random>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    std::random_device rd;                // non-deterministic seed
    std::mt19937 gen(rd());               // Mersenne Twister RNG
    std::uniform_int_distribution<int> dist(0, (1u << 31) - 1);

    int RD = dist(gen);
    int n, k; cin >> n >> k;

    unordered_map<int,int> freqMap;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        int r = tmp % k;
        freqMap[min(r, k - r) ^ RD]++;
    }

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        int r = tmp % k;
        freqMap[min(r, k - r) ^ RD]--;
    }

    for (auto& x : freqMap) {
        if (freqMap[x.first] != 0) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main() {
    fast();
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}


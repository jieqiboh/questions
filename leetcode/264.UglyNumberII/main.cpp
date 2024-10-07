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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq; // maxheap
        vector<long> primes = {2,3,5};

        set<long> visited;
        pq.push(1);
        visited.insert(1);

        long cur;
        for (int i = 0; i < n; i++) {
            long x = pq.top();
            cur = x;
            pq.pop();

            for (long prime : primes) {
                long newX = prime * x;
                if (visited.find(newX) == visited.end()) {
                    visited.insert(newX);
                    pq.push(newX);
                }
            }
        }
        return cur;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.nthUglyNumber(10) << "\n"; // 12
    cout << sol.nthUglyNumber(1) << "\n"; // 1
    return 0;
}


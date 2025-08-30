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

class Solution {
public:
    map<int,int> m;
    int prefSum;
    Solution(vector<int>& w) {
        // instantiate arr
        prefSum = 0;
        for (int i = 0; i < w.size(); i++) {
            int x = w[i];
            prefSum += x;
            m[prefSum] = i;
        }
    }

    int pickIndex() {
        std::random_device rd;  // Seed generator
        std::mt19937 gen(rd()); // Mersenne Twister PRNG
        std::uniform_real_distribution<double> dist(0.0, 1.0); // Range [0,1)

        double random_value = dist(gen); // Generate a random number
        random_value *= prefSum;

        for (pair<int,int> p : m) {
            int idx = p.second;
            int val = p.first;
            if (val >= random_value) {
                return idx;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {
    fast();
    vector<int> w = {1,3};
    Solution* sol = new Solution(w);
    for (int i = 0; i < 10; i++) {
        cout << sol->pickIndex() << "\n";
    }


    return 0;
}


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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class RecentCounter {
    vector<int> calls;
    int l;
public:
    RecentCounter() {
        this->l = 0;
    }

    int ping(int t) {
        calls.push_back(t);
        while (calls[l] < t - 3000) {
            l++;
        }
        return calls.size() - l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    fast();

    return 0;
}


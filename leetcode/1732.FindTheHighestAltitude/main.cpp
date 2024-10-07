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
    int largestAltitude(vector<int>& gain) {
        gain.insert(gain.begin(), 0);
        int alt = 0;
        int maxAlt = INT32_MIN;
        for (int x : gain) {
            alt += x;
            maxAlt = max(maxAlt, alt);
        }
        return maxAlt;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> gain = {-5,1,5,0,-7};
    cout << sol.largestAltitude(gain) << "\n";

    return 0;
}


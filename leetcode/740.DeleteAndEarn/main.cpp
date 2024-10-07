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

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m; // maps int to result sum
        int cur = nums[0];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur == nums[i]) {
                cnt++;
            } else {
                m[cur] = cur * cnt;
                cur = nums[i];
                cnt = 1;
            }
        }
        m[cur] = cur * cnt; // add last element
//        for (auto& p : m) {
//            cout << p.first << " " << p.second << "\n";
//        }
        unordered_map<int,int> cache;
        return maxPoints(cur, m, cache);
    }
    int maxPoints(int x, unordered_map<int,int>& m, unordered_map<int,int>& cache) {
        if (x < 1) return 0;
        if (cache.find(x) != cache.end()) return cache[x];
        int gain = 0;
        if (m.find(x) != m.end()) {
            gain = m[x];
        }
        int res = max(gain + maxPoints(x - 2, m, cache), maxPoints(x - 1, m, cache));
        cache[x] = res;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,3,3,3,2,4};
    cout << sol.deleteAndEarn(nums) << "\n"; // 9

    nums = {3,4,2};
    cout << sol.deleteAndEarn(nums) << "\n"; // 6

    return 0;
}


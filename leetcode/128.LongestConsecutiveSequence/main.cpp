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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> unique(nums.begin(), nums.end());
        unordered_map<int,int> consec;

        int max_val = 1;
        int cnt = 0;
        for (int x : unique) {
            if ((unique.find(x-1) != unique.end()) && (consec.find(x-1) == consec.end())) { // x-1 exists, and is not seen before
                int cur_val = 1;
                int cur_x = x;
                while (unique.find(cur_x-1) != unique.end()) {
//                    cnt++;
                    cur_val++;
                    consec[cur_x] = 0; // set to seen before
                    cur_x = cur_x - 1;
                }
                max_val = max(cur_val, max_val);
                consec[x] = cur_val;
            } else {
//                cnt++;
                max_val = max(consec[x-1] + 1, max_val);
                consec[x] = consec[x-1] + 1;
            }
        }
//        cout << "cnt is: " << cnt << "\n";V
        return max_val;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {1, 100, 200, 4, 3, 2}; // 4
    cout << sol.longestConsecutive(nums) << "\n";

    nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // 6
    cout << sol.longestConsecutive(nums) << "\n";

    return 0;
}


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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;

        int res = INT32_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (dp.find(arr[i] - difference) != dp.end()) {
                dp[arr[i]] = dp[arr[i] - difference] + 1;
            } else {
                dp[arr[i]] = 1;
            }
            res = max(res, dp[arr[i]]);
        }

        return res;
    }
};

//class Solution {
//public:
//    int longestSubsequence(vector<int>& arr, int difference) {
//        unordered_map<int,int> dp;
//
//        int res = INT32_MIN;
//        for (int i = 0; i < arr.size(); i++) {
//            int before = 0;
//            if (dp.find(arr[i] - difference) != dp.end()) {
//                before = dp[arr[i] - difference];
//            }
//            dp[arr[i]] = before + 1;
//            res = max(res, dp[arr[i]]);
//        }
//
//        return res;
//    }
//};

int main() {
    fast();
    Solution sol;
    vector<int> arr = {1,2,3,4};
    int difference = 1;
    cout << sol.longestSubsequence(arr, difference) << "\n"; // 4

    arr = {1,3,5,7};
    difference = 1;
    cout << sol.longestSubsequence(arr, difference) << "\n"; // 1

    arr = {1,5,7,8,5,3,4,2,1};
    difference = -2;
    cout << sol.longestSubsequence(arr, difference) << "\n"; // 4
    return 0;
}


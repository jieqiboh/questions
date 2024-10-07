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
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int i : nums) {
            str_nums.push_back(to_string(i));
        }
        sort(str_nums.begin(), str_nums.end(), [](const string& a, const string& b) {
            long ab = stol(a + b);
            long ba = stol(b + a);
            return ab > ba;
        });
        string res = "";
        int i = 0;
        while (i < str_nums.size() && str_nums[i] == "0") i++; // remove starting 0s
        for (; i < str_nums.size(); i++) {
            res += str_nums[i];
        }
        return (res == "") ? "0" : res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {3,30,34,5,9};
//    cout << sol.largestNumber(nums) << "\n";
//
//    nums = {10,2};
//    cout << sol.largestNumber(nums) << "\n";
//
//    nums = {432, 43243};
//    cout << sol.largestNumber(nums) << "\n"; // 43243432
//
//    nums = {999999991,9};
//    cout << sol.largestNumber(nums) << "\n"; // 43243432
//
//    nums = {0,0,0};
//    cout << sol.largestNumber(nums) << "\n"; // 0

    nums = {0};
    cout << sol.largestNumber(nums) << "\n"; // 0

    return 0;
}


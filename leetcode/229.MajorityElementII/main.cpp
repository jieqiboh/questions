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
    vector<int> majorityElement(vector<int>& nums) {
        int n = floor(nums.size() / 3);
        set<int> res;

        unordered_map<int,int> m;
        for (int elem : nums) {
            m[elem] += 1;
            if (m[elem] > n) {
                res.insert(elem);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> res = sol.majorityElement(nums);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}


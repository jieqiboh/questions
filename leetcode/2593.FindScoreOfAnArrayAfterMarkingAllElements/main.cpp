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
    long long findScore(vector<int>& nums) {
        stack<int> st;

        long long score = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || st.top() > nums[i]) {
                st.push(nums[i]);
            } else {
                while (!st.empty()) {
                    score += st.top();
                    st.pop();
                    if (!st.empty()) st.pop(); // alternate elements
                }
            }
        }

        while (!st.empty()) {
            score += st.top();
            st.pop();
            if (!st.empty()) st.pop(); // alternate elements
        }
        return score;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,1,3,4,5,2};
    cout << sol.findScore(nums) << "\n"; // 7


    return 0;
}


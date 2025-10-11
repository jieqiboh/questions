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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stPushed;
        int j = 0;

        for (int x : pushed) {
            if (stPushed.empty() || popped[j] != stPushed.top()) {
                stPushed.push(x);
            }
            while (!stPushed.empty() && popped[j] == stPushed.top()) {
                stPushed.pop();
                j++;
            }
        }
        return stPushed.empty();
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    cout << sol.validateStackSequences(pushed, popped) << "\n"; // 1

    return 0;
}


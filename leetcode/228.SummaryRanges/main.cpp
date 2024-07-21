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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int> interval = {nums[0], nums[0]}; // interval is the current considered interval
        vector<string> res = {};

        if (nums.empty()) return res;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (interval[1] + 1)) { // in range
                interval[1] = nums[i];
            } else { // not in range
                if (interval[0] == interval[1]) { // only 1 element
                    res.push_back(to_string(interval[0]));
                } else {
                    res.push_back(to_string(interval[0]) + "->" + to_string(interval[1]));
                }
                interval = {nums[i], nums[i]}; // reset interval
            }
        }
        if (interval[0] == interval[1]) { // only 1 element
            res.push_back(to_string(interval[0]));
        } else {
            res.push_back(to_string(interval[0]) + "->" + to_string(interval[1]));
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}


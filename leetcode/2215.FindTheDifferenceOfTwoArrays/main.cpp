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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res1, res2;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        for (int i : set1) {
            if (set2.find(i) == set2.end()) res1.push_back(i);
        }
        for (int i : set2) {
            if (set1.find(i) == set1.end()) res2.push_back(i);
        }
        vector<vector<int>> ans;
        ans.push_back(res1);
        ans.push_back(res2);
        return ans;
    }
};

int main() {
    fast();

    return 0;
}


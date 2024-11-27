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
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort by first element, then by second element
        sort(items.begin(), items.end());
        for(int i = 1; i < items.size(); i++) {
            items[i].back() = std::max(items[i - 1].back(), items[i].back());
        }

        vector<int> res;
        for (int q : queries) {
            auto it = upper_bound(items.begin(), items.end(), q, [](const int a, const std::vector<int>& b){
                return a < b.front();
            });
            int idx = it - items.begin();
            --idx;
            if (idx != -1) {
                res.push_back(items[idx][1]);
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};


int main() {
    fast();
    Solution sol;
    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1,2,3,4,5,6};
    vector<int> res = sol.maximumBeauty(items, queries);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    items = {{10,1000}};
    queries = {5};
    res = sol.maximumBeauty(items, queries);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}


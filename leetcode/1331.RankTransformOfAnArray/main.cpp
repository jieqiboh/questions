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
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) return {};
        vector<int> org(arr.begin(), arr.end());
        set<int> sorted(arr.begin(), arr.end());

        unordered_map<int,int> r; // maps nums to their rank
        int rnk = 1;
        for (int x : sorted) {
            r[x] = rnk++;
        }

        vector<int> res = {};
        for (int x : org) {
            res.push_back(r[x]);
        }
        return res;
    }
};


int main() {
    fast();
    Solution sol;
    vector<int> arr = {37,12,28,9,100,56,80,5,12};
    vector<int> res = sol.arrayRankTransform(arr);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}


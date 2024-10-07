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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorArr;
        xorArr.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            xorArr.push_back(xorArr[i - 1] ^ arr[i]);
        }
        vector<int> res;
        for (vector<int> q : queries) {
            // e.g. [1,2]
            if (q[0] == q[1]) {
                res.push_back(arr[q[0]]);
            } else {
                int curXor = xorArr[q[1]];
                int prevXor = q[0] - 1 >= 0 ? xorArr[q[0] - 1] : 0;
                res.push_back(curXor ^ prevXor);
            }
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int> res = sol.xorQueries(arr, queries);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}


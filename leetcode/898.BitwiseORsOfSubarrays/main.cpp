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
    int subarrayBitwiseORs(vector<int>& arr) {

        // res_ors:
        // cur_ors: contains distinct or values ending at i - 1
        // nxt_ors: contains prev or values


    }
};

int main() {
    fast();
    Solution sol;

    vector<int> arr = {0};
    cout << sol.subarrayBitwiseORs(arr) << "\n"; // 1

    arr = {1,1,2};
    cout << sol.subarrayBitwiseORs(arr) << "\n"; // 3

    arr = {1,2,4};
    cout << sol.subarrayBitwiseORs(arr) << "\n"; // 6

    return 0;
}


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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find pos of int x after binsearch
        // then instantiate ptrs to its left and right
        auto iter = lower_bound(arr.begin(), arr.end(), x);
        cout << *iter;
        vector<int>::iterator i, j;
        if (*iter != x) {
            i = iter--;
            j = iter++;
        }
        while (i)
        return {};
    }

};

int main() {
    fast();
    Solution sol;
    vector<int> arr = {2,4,5,8};
    int k = 2;
    int x = 6;
    vector<int> res = sol.findClosestElements(arr, k, x); // 4,5
    for (int i : res) cout << i << " ";
    cout << "\n";

    arr = {2,4,5,6,100};
    k = 4;
    x = 6;
    res = sol.findClosestElements(arr, k, x); // 2,4,5,6
    for (int i : res) cout << i << " ";
    cout << "\n";
    return 0;
}


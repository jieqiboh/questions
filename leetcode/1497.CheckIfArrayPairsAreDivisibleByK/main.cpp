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
    bool canArrange(vector<int>& arr, int k) {
        vector<int> modArr;
        for (int x : arr) modArr.push_back(x % k);
        sort(modArr.begin(), modArr.end());
        int l = 0; int r = arr.size() - 1;
        while (l < r && modArr[l] == 0) l++;
        while (l < r) {
            if (modArr[l] + modArr[r] == k) {
                l++; r--;
                continue;
            }
            return false;
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 5;
    cout << sol.canArrange(arr, k) << "\n"; // 1

    arr = {1,2,3,4,5,6,};
    k = 10;
    cout << sol.canArrange(arr, k); // 0
    return 0;
}


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
    int waysToSplitArray(vector<int>& nums) {
        vector<ll> r2l(nums.size());
        vector<ll> l2r(nums.size());
        ll cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            l2r[i] = cnt;
        }
        cnt = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            cnt += nums[i];
            r2l[i] = cnt;
        }
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (l2r[i] >= r2l[i + 1]) res++;
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}


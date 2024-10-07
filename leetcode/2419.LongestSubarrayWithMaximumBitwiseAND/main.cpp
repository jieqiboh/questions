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
    int longestSubarray(vector<int>& nums) {
        int maxVal = INT32_MIN;
        int cnt = 0;
        for (int x : nums) {
            if (x > maxVal) {
                maxVal = x;
                cnt = 1;
            } else if (x == maxVal) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    fast();

    return 0;
}


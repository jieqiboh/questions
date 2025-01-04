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
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) return;
        int i = 0; // rightmost boundary of 0s
        int j = nums.size() - 1; // leftmost boundary of 2s

        int cur = 0;
        while (cur < nums.size()) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[i]);
                i++;
                cur++;
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[j]);
                j--;
            } else {
                cur++;
            }
        }
    }
};

int main() {
    fast();

    return 0;
}


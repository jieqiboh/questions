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
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1) return;

        for (int i = 0; i < nums.size() - 1; i++) {
            int j = i + 1;
            if (i % 2 == 0) {
                if (nums[j] < nums[i]) swap(nums[i], nums[j]);
            } else {
                if (nums[j] > nums[i]) swap(nums[i], nums[j]);
            }
        }
    }
};

int main() {
    fast();

    return 0;
}


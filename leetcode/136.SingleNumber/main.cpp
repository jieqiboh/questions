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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            num = num ^ nums[i];
        }

        return num;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {2,2,4,1,1,4,-3};
    cout << sol.singleNumber(nums) << "\n";

    return 0;
}


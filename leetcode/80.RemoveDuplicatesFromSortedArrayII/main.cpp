#include <iostream>
#include <sys/resource.h>
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
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;

        int cur = nums[0];
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == cur && count < 2) {
                nums[idx] = nums[i];
                count++;
                idx++;
            } else if (nums[i] != cur) {
                cur = nums[i];
                nums[idx] = nums[i];
                count = 1;
                idx++;
            } else { // count >= 2
                // don't increment idx
                continue;
            }
        }
        return idx;
        
    }
};

int main() {
    fast();

    vector<int> nums = {0,0,0,0,1,2,2,2}; // 0,0,1,2,2
    
    Solution sol;
    cout << sol.removeDuplicates(nums) << "\n";

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}


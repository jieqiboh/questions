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
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                freq[nums[i] * nums[j]]++;
            }
        }

        int res = 0;
        for (pair<int,int> p : freq) {
//            cout << p.first << " " << p.second << "\n";
            int f = p.second;
            int num = p.first;

            if (f > 1) {
                if (f > 2) {
                    res += (f * (f - 1)) / 2;
                } else {
                    res++;
                }
            }
        }
        return res * 8;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,2,4,5,10};
    cout << sol.tupleSameProduct(nums) << "\n"; // 16
    
    nums = {2,3,4,6,8,12};
    cout << sol.tupleSameProduct(nums) << "\n"; // 40

    return 0;
}


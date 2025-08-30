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
    bool isArraySpecial(vector<int>& nums) {
        int parity = nums[0] % 2 == 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == parity) {
                return false;
            }
            parity = nums[i] % 2;
        }
        return true;
    }
};

int main() {
    fast();

    return 0;
}


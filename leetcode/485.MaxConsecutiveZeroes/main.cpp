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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsec = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            }
            maxConsec = max(maxConsec, count);
            if (nums[i] == 0) {
                count = 0;
            }
        }
    }
};

int main() {
    fast();

    return 0;
}


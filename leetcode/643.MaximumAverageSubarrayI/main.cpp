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
    double findMaxAverage(vector<int>& nums, int k) {
        double curSum = 0;
        double maxAvg = INT32_MIN;
        for (int i = 0; i < k; i++) {
            curSum += nums[i];
        }
        maxAvg = max(maxAvg, curSum / k);

        int i = 1; // [i, j] are the current range to be considered
        int j = k;
        while (j < nums.size()) {
            curSum += nums[j];
            curSum -= nums[i-1];
            maxAvg = max(maxAvg, curSum / k);
            j++;
            i++;
        }
        return maxAvg;
    }
};

int main() {
    fast();

    return 0;
}


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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int a = 0;
        int b = k;
        int c = 2 * k;

        int singleWindowSum = 0;
        int doubleWindowSum = 0;
        int tripleWindowSum = 0;

        for (int i = 0; i < k; i++) {
            singleWindowSum += nums[i + a];
            doubleWindowSum += nums[i + b];
            tripleWindowSum += nums[i + c];
        }

        int bestSingleSum = singleWindowSum;
        int bestDoubleSum = bestSingleSum + doubleWindowSum;
        int bestTripleSum = bestDoubleSum + tripleWindowSum;

        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, k * 2};

        while (c < nums.size() - k) {
            singleWindowSum -= nums[a];
            doubleWindowSum -= nums[b];
            tripleWindowSum -= nums[c];

            a++; // move start points
            b++;
            c++;

            singleWindowSum += nums[a + k - 1];
            doubleWindowSum += nums[b + k - 1];
            tripleWindowSum += nums[c + k - 1];

            if (singleWindowSum > bestSingleSum) {
                bestSingleSum = singleWindowSum;
                bestSingleStart = a;
            }
            if (bestSingleSum + doubleWindowSum > bestDoubleSum) {
                bestDoubleSum = bestSingleSum + doubleWindowSum;
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = b;
            }
            if (bestDoubleSum + tripleWindowSum > bestTripleSum) {
                bestTripleSum = bestDoubleSum + tripleWindowSum;
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = c;
            }
        }

        return bestTripleStart;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,2,1,2,6,7,5,1};
    int k = 2;
    vector<int> res = sol.maxSumOfThreeSubarrays(nums, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    nums = {1,2,1,2,1,2,1,2,1};
    k = 2;
    res = sol.maxSumOfThreeSubarrays(nums, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    nums = {4,5,10,6,11,17,4,11,1,3};
    k = 1;
    res = sol.maxSumOfThreeSubarrays(nums, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}


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
    int lenLongestFibSubseq(vector<int>& arr) {
        // 3 <= arr.length <= 1000
        // 1 <= arr[i] < arr[i + 1] <= 10^9
        // Observation: Fibonacci seq increases exponentially
        // max fib seq length is around 60 - max operations around 6000

        unordered_set<int> nums;
        for (int i = 0; i < arr.size(); i++) {
            nums.insert(arr[i]);
        }

        int maxLen = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int curLen = 0;
                int a = arr[i];
                int b = arr[j];
                int c = a + b;
                while (nums.find(c) != nums.end()) {
                    curLen++;
                    int tmp = b;
                    b = c;
                    a = tmp;
                    c = a + b;
                }
                if (curLen > 0) {
                    maxLen = max(maxLen, curLen + 2);
                }
            }
        }
        return maxLen;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout << sol.lenLongestFibSubseq(arr) << "\n"; // 5

    arr = {1,3,7,11,12,14,18};
    cout << sol.lenLongestFibSubseq(arr) << "\n"; // 3

    return 0;
}


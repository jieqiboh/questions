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
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, maxElement = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update maxElement
            maxElement = max(maxElement, arr[i]);

            if (maxElement == i) {
                // All values in range [0, i] belong to the prefix arr[0:i];
                // a new chunk can be formed
                chunks++;
            }
        }

        return chunks;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> arr = {4,3,2,1,0};
    cout << sol.maxChunksToSorted(arr) << "\n"; // 1

    arr = {1,0,2,3,4};
    cout << sol.maxChunksToSorted(arr) << "\n"; // 4

    arr = {1,2,0,3};
    cout << sol.maxChunksToSorted(arr) << "\n"; // 2
    return 0;
}


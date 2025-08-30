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
    int minimizeXor(int num1, int num2) {
        int result = 0;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = 0;
        int currentBit = 31;  // Start from the most significant bit.

        // While x has fewer set bits than num2
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit of num1 is set or we must set all remaining
            // bits in result
            if (isSet(num1, currentBit) ||
                (targetSetBitsCount - setBitsCount > currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--;  // Move to the next bit.
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }
};

int main() {
    fast();
    Solution sol;
    int num1 = 8;
    int num2 = 5;
    cout << sol.minimizeXor(num1, num2) << "\n"; // 12

    num1 = 3;
    num2 = 5;
    cout << sol.minimizeXor(num1, num2) << "\n"; // 3

    num1 = 1;
    num2 = 12;
    cout << sol.minimizeXor(num1, num2) << "\n"; // 3

    num1 = 25;
    num2 = 72;
    cout << sol.minimizeXor(num1, num2) << "\n"; // 24
    return 0;
}


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
    int maximumSwap(int num) {
        // greedily swap the earliest digit with a later digit that is larger
        vector<int> d;
        int tmp = num;
        // extract digits into array
        while (num) {
            int digit = num % 10;
            d.push_back(digit);
            num /= 10;
        }
        reverse(d.begin(), d.end());
        vector<int> maxIdxVec(d.size());
        vector<int> minIdxVec(d.size());
        int minDigit = INT32_MAX;
        int minDigitIdx = -1;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] < minDigit) {
                minDigit = d[i];
                minDigitIdx = i;
            }
            minIdxVec[i] = minDigitIdx;
        }
        int maxDigit = INT32_MIN;
        int maxDigitIdx = -1;
        for (int i = d.size() - 1; i >= 0; i--) {
            if (d[i] > maxDigit) {
                maxDigit = d[i];
                maxDigitIdx = i;
            }
            maxIdxVec[i] = maxDigitIdx;
        }

//        for (int i : d) {
//            cout << i << " ";
//        }
//        cout << "\n";
        for (int i = 0; i < d.size(); i++) {
            if (d[maxIdxVec[i]] > d[minIdxVec[i]]) {
                swap(d[maxIdxVec[i]], d[minIdxVec[i]]);
                break;
            }
        }
        // reconstruct number
        int newNum = 0;
        for (int i = 0; i < d.size(); i++) {
            newNum *= 10;
            newNum += d[i];
        }

        return newNum;

    }
};

int main() {
    fast();
    Solution sol;
    int num = 2736;
    cout << sol.maximumSwap(num) << "\n"; // 7236

    num = 9973;
    cout << sol.maximumSwap(num) << "\n"; // 9973

    num = 98368;
    cout << sol.maximumSwap(num) << "\n"; // 98863

    return 0;
}


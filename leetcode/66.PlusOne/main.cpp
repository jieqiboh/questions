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
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit and add one
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // If all the digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> digits = {1,2,3};
    vector<int> res = sol.plusOne(digits); // 124

    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    digits = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};
    res = sol.plusOne(digits); //
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}


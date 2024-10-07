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
#include <numeric>
#include <utility>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int curSum = accumulate(rolls.begin(), rolls.end(), 0);
        int totalSum = mean * (rolls.size() + n);
        int remSum = totalSum - curSum;

        vector<int> res(n, 1);

        remSum -= n;
        int i = 0;
        while (remSum > 0) {
            int toAdd = min(remSum, 5);
            res[i] += toAdd;
            remSum -= toAdd;
            i++;
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> rolls = {3,2,4,3};
    int mean = 4;
    int n = 2;
    vector<int> res = sol.missingRolls(rolls, mean, n);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}


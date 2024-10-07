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
#include "numeric"

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int chalkSum = accumulate(chalk.begin(), chalk.end(), 0);
        k = k % chalkSum;
        int idx = 0;
        int actIdx = idx % chalk.size(); // actual idx of student
        while (k >= chalk[actIdx]) {
            k -= chalk[actIdx];
            idx++;
            actIdx = idx % chalk.size();
        }
        return actIdx;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> chalk = {5,1,5};
    cout << sol.chalkReplacer(chalk, 22) << "\n"; // 0

    return 0;
}


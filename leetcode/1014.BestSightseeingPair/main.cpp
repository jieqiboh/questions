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
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> maxLeftScore;
        int maxLeftScoreVal = values[0];
        maxLeftScore.push_back(values[0]);

        for (int i = 1; i < values.size(); i++) {
            int leftScore = values[i] + i;

            maxLeftScore.push_back(maxLeftScoreVal);
            maxLeftScoreVal = max(maxLeftScoreVal, leftScore);
        }

        int res = INT32_MIN;
        for (int i = 1; i < values.size(); i++) {
            int rightScore = values[i] - i;
            res = max(res, rightScore + maxLeftScore[i]);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> values = {8,1,5,2,6};
    cout << sol.maxScoreSightseeingPair(values) << "\n"; // 11

    values = {1,2};
    cout << sol.maxScoreSightseeingPair(values) << "\n"; // 2
    return 0;
}


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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> m; // reved num and idx
        for (int x : nums) {
            
        }


    }

    int reverse(int x) {
        bool negative = x < 0;
        x = abs(x);

        string tmp = "";
        while (x) {
            tmp += ('0' + x % 10);
            x /= 10;
        }
        // tmp is already reversed, no need to flip
        // but handle leading zeros: "021" -> 21
        int result = stoi(tmp);
        return negative ? -result : result;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.reverse(12);

    return 0;
}


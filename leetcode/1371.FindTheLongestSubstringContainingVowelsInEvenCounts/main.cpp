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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> xorMap;
        xorMap.insert({'a',1});
        xorMap.insert({'e',2});
        xorMap.insert({'i',4});
        xorMap.insert({'o',8});
        xorMap.insert({'u',16});

        unordered_map<int,int> pos; // maps xorVals to their first idx sighting

        int xorVal = 0;
        int maxSize = 0;
        for (int i = 0; i < s.size(); i++) {
            int charVal = (xorMap.find(s[i]) == xorMap.end()) ? 0 : xorMap[s[i]];
            xorVal = xorVal ^ charVal;
            if (xorVal == 0) {
                maxSize = i + 1;
                continue;
            }
            if (pos.find(xorVal) == pos.end()) {
                pos[xorVal] = i;
            } else { // seen before
                maxSize = max(maxSize, i - pos[xorVal]);
            }
        }
        return maxSize;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "leetcodegreat";
    cout << sol.findTheLongestSubstring(s) << "\n"; // 5



    return 0;
}


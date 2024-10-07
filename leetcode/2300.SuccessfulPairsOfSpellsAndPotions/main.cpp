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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> res;
        for (int i = 0; i < spells.size(); i++) {
            long long spellVal = spells[i];
            long long potionVal = ceil((long long)success / (double)spellVal);
            auto it = lower_bound(potions.begin(), potions.end(), potionVal);
            if (it != potions.end()) {
                res.push_back(potions.size() - (it - potions.begin()));
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> spells = {5,1,3};
    vector<int> potion = {1,2,3,4,5};
    vector<int> res = sol.successfulPairs(spells, potion, 7);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    spells = {3,1,2};
    potion = {8,5,8};
    res = sol.successfulPairs(spells, potion, 16);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}


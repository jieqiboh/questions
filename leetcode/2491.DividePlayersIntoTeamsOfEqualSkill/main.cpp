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
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        sort(skill.begin(), skill.end());

        int l = 0;
        int r = skill.size() - 1;
        int sum = skill[l] + skill[r];
        while (l < r) {
            if (skill[l] + skill[r] != sum) return -1;
            res += (skill[l] * skill[r]);
            l++;r--;
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> skill = {3,2,5,1,3,4};
    cout << sol.dividePlayers(skill) << "\n"; // 22

    skill = {1,1,2,3};
    cout << sol.dividePlayers(skill) << "\n"; // -1
    return 0;
}


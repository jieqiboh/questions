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
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n);
        for (vector<int> edge : edges) {
            int to = edge[1];
            cnt[to]++;
        }
        int numChampions = 0;
        int champ = -1;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) {
                numChampions++;
                champ = i;
            }
        }
        if (numChampions != 1) {
            return -1;
        } else {
            return champ;
        }
    }
};

int main() {
    fast();
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0,2},{1,3},{1,2}};
    cout << sol.findChampion(n, edges) << "\n"; // -1

    n = 3;
    edges = {{0,1},{1,2}};
    cout << sol.findChampion(n, edges) << "\n"; // 0
    return 0;
}


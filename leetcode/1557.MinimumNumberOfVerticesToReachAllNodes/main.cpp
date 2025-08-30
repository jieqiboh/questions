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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);

        for (vector<int> vi : edges) {
            int v = vi[1];
            indeg[v]++;
        }

        vector<int> res;
        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0) res.push_back(i);
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}


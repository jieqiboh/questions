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
    int trap(vector<int>& height) {
        vector<int> r_max(height.size());
        vector<int> l_max(height.size());

        // right pass
        int max_val = 0;
        for (int i = 0; i < height.size(); i++) {
            r_max[i] = max_val;
            max_val = max(max_val, height[i]);
        }

        // left pass
        max_val = 0;
        for (int j = height.size() - 1; j >= 0; j--) {
            l_max[j] = max_val;
            max_val = max(max_val, height[j]);
        }

        vector<int> lr_minmax(height.size());
        for (int i = 0; i < height.size(); i++) {
            lr_minmax[i] = min(l_max[i], r_max[i]);
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += max(lr_minmax[i] - height[i], 0);
        }

        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << "\n";

    height = {4,2,0,3,2,5};
    cout << sol.trap(height) << "\n";
    return 0;
}


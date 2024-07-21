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
    int calcVol(vector<int>& height, int l, int r) {
        return min(height[l], height[r]) * (r - l);
    }
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_vol = calcVol(height, l, r);

        while (l < r) {
            int vol = calcVol(height, l, r);
            int r_vol = calcVol(height, l, r - 1);
            int l_vol = calcVol(height, l + 1, r);

            if (r_vol > vol && l_vol > vol) {
                if (l_vol >= r_vol) {
                    l++;
                    max_vol = max(l_vol, max_vol);
                } else {
                    r--;
                    max_vol = max(r_vol, max_vol);
                }
            } else if (r_vol > vol) { // only r_vol greater
                r--;
                max_vol = max(r_vol, max_vol);
            } else if (l_vol > vol) { // only l_vol greater
                l++;
                max_vol = max(l_vol, max_vol);
            } else { // explore in the dirn whr the height is greater
                if (height[l] < height[r]) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return max_vol;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
//    cout << sol.maxArea(height) << "\n"; // 49

    height = {1,3,2,5,25,24,5};
    cout << sol.maxArea(height) << "\n"; // 24

    return 0;
}


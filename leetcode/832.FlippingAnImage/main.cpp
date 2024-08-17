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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& v : image) {
            reverseHorVec(v);
            invertVec(v);
        }
        return image;
    }
    void reverseHorVec(vector<int>& v) {
        int l = 0;
        int r = v.size() - 1;
        while (l <= r) {
            swap(v[r], v[l]);
            l++;
            r--;
        }
    }
    void invertVec(vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            v[i] = !v[i];
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> res = sol.flipAndInvertImage(image);
    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}


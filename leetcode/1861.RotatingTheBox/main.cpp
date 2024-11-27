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
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // rotate box
        vector<vector<char>> res(box[0].size(), vector<char>(box.size()));

        for (int j = 0; j < box[0].size(); j++) {
            for (int i = 0; i < box.size(); i++) {
                res[j][res[0].size() - 1 - i] = box[i][j];
            }
        }

        // move stones
        for (int j = 0; j < res[0].size(); j++) {
            int pos = -1; // y pos of space
            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i][j] == '#' && pos != -1) {
                    res[pos][j] = '#';
                    res[i][j] = '.';
                    pos--;
                } else if (res[i][j] == '.' && pos == -1) {
                    pos = i;
                } else if (res[i][j] == '*') {
                    pos = -1;
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<char>> box = {{'#','.','*','.'},{'#','#','*','.'}};
    vector<vector<char>> res = sol.rotateTheBox(box);
    for (vector<char> v : res) {
        for (char c : v) {
            cout << c << " ";
        }
        cout << "\n";
    }
    
    box = {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};

    return 0;
}


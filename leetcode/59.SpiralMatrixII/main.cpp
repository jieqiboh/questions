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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));

        int i = 0;
        int j = n - 1;
        int k = n - 1;
        int l = 0;

        int dir = 0; // left-right, top-down, right-left, down-up
        int count = 1;

        while (i <= k && l <= j) {
            if (dir == 0) { // left-right
                for (int x = l; x <= j; x++) {
                    res[i][x] = count;
                    count++;
                }
                i++;
            } else if (dir == 1) { // top-down
                for (int x = i; x <= k; x++) {
                    res[x][j] = count;
                    count++;
                }
                j--;
            } else if (dir == 2) { // right-left
                for (int x = j; x >= l; x--) {
                    res[k][x] = count;
                    count++;
                }
                k--;
            } else { // down-up
                for (int x = k; x >= i; x--) {
                    res[x][l] = count;
                    count++;
                }
                l++;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> res = sol.generateMatrix(4);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    res = sol.generateMatrix(5);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    res = sol.generateMatrix(1);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}


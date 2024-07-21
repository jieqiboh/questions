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
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows(0);
        unordered_set<int> cols(0);

        for (int i = 0; i < matrix.size(); i++) {
           for (int j = 0; j < matrix[0].size(); j++) {
              if (matrix[i][j] == 0) {
                  rows.insert(i);
                  cols.insert(j);
              }
           }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    fast();
    Solution sol;


    return 0;
}


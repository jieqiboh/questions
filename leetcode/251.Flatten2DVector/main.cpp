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

class Vector2D {
public:
    vector<vector<int>> myvec;
    int i, j;

    // Helper to move to next available position
    void advanceToNext() {
        while (i < myvec.size() && j == myvec[i].size()) {
            i++;
            j = 0;
        }
    }
    Vector2D(vector<vector<int>>& vec) : myvec(vec), i(0), j(0) {
        advanceToNext();
    }

    int next() {
        int ret = myvec[i][j];
        j++;
        advanceToNext();
        return ret;
    }

    bool hasNext() {
        return i < myvec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    fast();
    vector<vector<int>> vec = {{1,2}, {3}, {4}};
    Vector2D* obj = new Vector2D(vec);
    cout << obj->next() << "\n"; // 1
    cout << obj->next() << "\n"; // 2
    cout << obj->next() << "\n"; // 3
    cout << obj->hasNext() << "\n"; // 1
    cout << obj->hasNext() << "\n"; // 1
    cout << obj->next() << "\n"; // 4
    cout << obj->hasNext() << "\n"; // 0

    return 0;
}


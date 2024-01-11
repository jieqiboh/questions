#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

// valid if there is row and col is unique
// valid if there is no queen along both diagonals 40K ops

int main() {
    fast();
    bool valid = true;
    int colmask = 0; // use a bitmask
    int rowmask = 0;
    vector<pair<int, int>> pos;

    for (int i = 0; i < 8; i++) { // for each row
        for (int j = 0; j < 8; j++) {
            char c;
            scanf(" %c", &c);
            if (c == '*') {
                rowmask |= (1<<i); // set the ith bit to be 1
                colmask |= (1<<j); // set the jth bit to be 1
                pos.emplace_back(j, i);
            }
        }
    }


    // check cols and rows
    // 255 means all the 1s bits are set
    if (colmask != 255 || rowmask != 255) valid = false;

    // check diagonals
    for (int i = 0; i < pos.size(); i++) {
        if (!valid) break;
        for (int j = i+1; j < pos.size(); j++) {
            if (abs(pos[i].first - pos[j].first) == abs(pos[i].second - pos[j].second)) {
                valid = false;
            }
        }
    }

    if (valid) {
        printf("valid");
    } else {
        printf("invalid");
    }
    // scan each row and add the coords of the * to a vector, also marking the col
    // if there is not exactly 1 * in a row, return invalid
    //

    return 0;
}


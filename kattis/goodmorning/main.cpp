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
set<int> possible; // set of possible numbers which are <= 200
void backtrack(int cur, int i, int j, vector<vector<int> >& keys) {
    // takes i and j and cur
    // check if cur is possible, and if not, stop

    if (cur > 200 || cur < 1) {
        return;
    } else {
        // add number to set of possible integers
        possible.insert(cur);

        // try pressing again
        int num = keys[i][j];
        int combined = cur * 10 + num;
        backtrack(combined, i, j, keys);


        // try going right
        if (j+1 < 3) {
            num = keys[i][j+1];
            if (num != -1) {
                combined = cur * 10 + num;
                backtrack(combined, i, j+1, keys); // go right and press
                backtrack(cur, i, j+1, keys); // go right and no press
            }
        }

        // try going down
        if (i+1 <= 3) {
            num = keys[i+1][j];
            if (num != -1) {
                combined = cur * 10 + num;
                backtrack(combined, i+1, j, keys); // go down and press
                backtrack(cur, i+1, j, keys); // go down and no press
            }
        }

    }
}

int main() {
    fast(); // test

    int n; cin >> n;

    vector<vector<int> > keys = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            // start from the various keys
            backtrack(keys[i][j], i, j, keys);
        }
    }

//    for (int x : possible) {
//        cout << x << " ";
//    }
//    cout << endl;

    while (n--) {
        int num; cin >> num;
        // lower bound returns an iterator pointing to the first elem that is >= x
        int n1 = *possible.lower_bound(num) == num ? *possible.lower_bound(num) : *prev(possible.lower_bound(num));
        // upper bound returns an iterator pointing to the first element that is > x
        int n2 = *possible.upper_bound(num);

//        cout << num << ": ";
        if (abs(num-n1) < abs(num-n2)) {
            cout << n1;
        } else {
            cout << n2;
        }
        cout << endl;
        
//        cout << num << " ";
//        cout << "n1: " << n1 << " n2: " << n2;
//        cout << endl;

    }

    return 0;
}


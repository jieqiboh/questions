#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
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

vector<string> best;
umap<string, bool> used; // maps colour names to whether they are currently used
int c = 0; // counts the number of nonhideous paintings
void backtrack(vector<string>& cur, vector<string>& colours, vector<vector<bool>>& good_pairs, map<string, int>& col_idxs) {
    if (cur.size() == colours.size()) {
        // compare with best based on similarity to colours vector
        for (int i=0;i<colours.size();i++) {
            if (best.empty()) {
                best = cur; break;
            }
            if (best[i] == colours[i] && cur[i] == colours[i]) {
                continue;
            } else if (best[i] != colours[i] && cur[i] == colours[i]) {
                best = cur; break;
            } else { // best match but cur no match
                break;
            }
        }
//        for (string x : best){
//            cout << x << " ";
//        }
//        cout << endl;
        c++;
    } else {
        // tries the next best colour
        for (string c : colours) {
//            for (string x : cur){
//                cout << x << " ";
//            }
//            cout << endl;
//            if (find(cur.begin(), cur.end(), c) == cur.end()) { // creates a new_cur so every colour is tried
            if (!used[c]) { // creates a new_cur so every colour is tried
                vector<string> new_cur = cur;
                if (good_pairs[col_idxs[cur.back()]][col_idxs[c]]) {
                    // pair not found, so can backtrack with this
                    new_cur.push_back(c);
                    used[c] = true;
                    backtrack(new_cur, colours, good_pairs, col_idxs);
                    used[c] = false;
                }
            }
        }
    }
}

int main() {
    fast();
    
    int no_cases; cin >> no_cases;

    while (no_cases--) {
        int no_colours; cin >> no_colours;
        vector<string> colours(no_colours); // colours arrange in increasing preference
        map<string, int> col_idxs; // maps colours to idxes for pair search

        for (int i = 0; i < no_colours; i++ ) { // initialise colours and col_idxes and used
            string colour; cin >> colour;
            colours[i] = colour;
            col_idxs[colour] = i;
            used[colour] = false;
        }
//        for (auto& x : colours) {
//            cout << x;
//        }

        // initialise a 2d array representing good and bad pairs
        int no_pairs; cin >> no_pairs;
        vector<vector<bool>> good_pairs(no_colours, vector<bool>(no_colours, true));

        for (int i = 0; i < no_pairs; i++) {
            string c1, c2; cin >> c1 >> c2;
            int idx1 = col_idxs[c1];
            int idx2 = col_idxs[c2];
            good_pairs[idx1][idx2] = false;
            good_pairs[idx2][idx1] = false;
        }

//        for (auto& x : good_pairs) {
//            for (bool b : x) {
//                cout << b << " ";
//            }
//            cout << endl;
//        }

        // find no of non-hideous paintings
        // find the optimal paintings

        for (int i = 0; i < colours.size(); i++ ) {
            vector<string> cur; cur.push_back(colours[i]);
            used[colours[i]] = true;
            backtrack(cur, colours, good_pairs, col_idxs);
            used[colours[i]] = false;
        }

        cout << c << endl;
        for (string x : best){
            cout << x << " ";
        }
        cout << endl;
        c = 0;
    }

    return 0;
}


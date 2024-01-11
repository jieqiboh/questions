#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <sstream>

using namespace std;

#include <bits/extc++.h>                         // pbds
using namespace __gnu_pbds;

template<class x>
using ost = tree<x, null_type, less<x>, rb_tree_tag,
          tree_order_statistics_node_update>;

#define uset unordered_set
#define umap unordered_map

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct score {
        int id = 0;
        int solved = 0;
        int penalty = 0;
};

bool operator< (const score& s1, const score& s2) {
    if (s1.solved == s2.solved) {
        if (s1.penalty == s2.penalty) {
            return s1.id < s2.id;
        }
        return s1.penalty < s2.penalty;
    }
    return s1.solved > s2.solved;
}

int main() {
    // Your code goes here

    ost<score> scores;
    umap<int, score> m; // maps team id to their score structs
    int numteams, numlines; cin >> numteams >> numlines;
    int teamnum, penalty;

    // initialise scores
    for (int i = 1; i <=numteams; i++) {
        score tmp;
        tmp.id = i;
        scores.insert(tmp);
        m.insert({i, tmp});
    }

    while (numlines--) {
        cin >> teamnum >> penalty;

        // update m
        score curScore = m[teamnum];
        m[teamnum].solved++; // add 1 to solved
        m[teamnum].penalty += penalty; // add penalty
        score newScore = m[teamnum];

        // update scores
        scores.erase(curScore);
        scores.insert(newScore);

        // get score of team with id 1
        score t1 = m[1];
        cout << scores.order_of_key(t1) + 1 << endl;
    }


    return 0;
}


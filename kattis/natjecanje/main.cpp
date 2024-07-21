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
umap<int, int> teams;
int no_teams;
int no_reserve;
int no_cannotstart;
int minimum;
void backtrack() {
    if (no_cannotstart == 0) {
        minimum = 0; return;
    }
    if (no_reserve == 0) {
        if (no_cannotstart < minimum) {
            minimum = no_cannotstart;
            return;
        }
    }
    for (auto& t : teams) {
        if (t.second == 2) { // only lend if t has an extra boat
            // if boat to the left has 0 boats
            if (teams[t.first - 1] == 0 && t.first-1 >= 0) {
                no_cannotstart--;
                no_reserve--;
                teams[t.first]--; // lender loses their reserve boat
                teams[t.first - 1]++; // borrower gets 1 boat
                backtrack();
                teams[t.first]++; // lender gets back their reserve boat
                teams[t.first - 1]--; // borrower gets 1 boat
                no_cannotstart++;
                no_reserve++;
            }
            // if boat to the right has 0 boats
            if (teams[t.first + 1] == 0 && t.first + 1 < 10) {
                no_cannotstart--;
                no_reserve--;
                teams[t.first]--; // lender loses their reserve boat
                teams[t.first + 1]++; // borrower gets 1 boat
                backtrack();
                teams[t.first]++; // lender gets back their reserve boat
                teams[t.first + 1]--; // borrower gets 1 boat
                no_cannotstart++;
                no_reserve++;
            }
        }
    }
}

int main() {
    fast();

    // teams are 0 indexed
    cin >> no_teams >> no_cannotstart >> no_reserve;
    for (int i = 0; i < no_teams; i ++ ) { // 0-indexed
        teams[i] = 1;
    }
//    for (int i = 1; i <= no_teams; i ++ ) {
//        teams[i] = 1;
//    }
    set<int> set_cannotstart;
    for (int i = 0; i < no_cannotstart; i ++){
        int t; cin >> t;
        teams[t]--;
        set_cannotstart.insert(t);
    }
    for (int i = 0; i < no_reserve; i++ ) {
        int t; cin >> t;
        teams[t]++;
        if (set_cannotstart.find(t) != set_cannotstart.end()) { // decrement from cannot_start and reserve
            no_cannotstart--;
            no_reserve--;
        }
    }

    minimum = no_cannotstart; // initial minimum no. of teams that cannot start

//    for (auto& x : teams) {
//        cout << x.first << " " << x.second << endl;
//    }

    backtrack();
    cout << minimum;
    return 0;
}


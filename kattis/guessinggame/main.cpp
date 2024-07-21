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

int main() {
    fast();
    
    int val; cin >> val;
    int hi = 10; // highest possible val
    int lo = 1; // lowest possible val
    while (val != 0) {
        cin.ignore();
        string res; getline(cin, res);

        if (res == "too high") {
            if (val <= hi) hi = val-1;
        } else if (res == "too low") {
            if (val >= lo) lo = val + 1;
        } else {
            if (val < lo || val > hi) {
                cout << "Stan is dishonest" << endl;
            } else {
                cout << "Stan may be honest" << endl;
            }
            hi = 10;
            lo = 1;
        }
        cin >> val;
    }
    return 0;
}


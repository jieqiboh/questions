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

struct event {
    ll s, e;
};

// higher s time is greater, higher e time is greater
// ensure that encountered timings end earliest, and otherwise start earliest
bool cmp(event& e1, event& e2) {
    if(e1.e == e2.e) {
        return e1.s < e2.s;
    }
    return e1.e < e2.e;
}

int main() {
    fast();
    ll n_activities, n_rooms;
    cin >> n_activities >> n_rooms;

    vector<event> v;

    while (n_activities--) {
        event event;
        cin >> event.s >> event.e;

        v.push_back(event);
    }
    sort(v.begin(), v.end(), cmp);

    for (event x : v) {
        cout << x.s << " " << x.e << endl;
    }
    // add to queue
    return 0;
}


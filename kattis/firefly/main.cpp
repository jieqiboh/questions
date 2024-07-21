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
int n, h;
int num_hit(vector<int>& v, bool isStalac, int height) {
//    if (isStalac) height = h - height;
    int hit;
    auto idx = lower_bound(v.begin(), v.end(), height);

    if (idx == v.end()) {
        hit = 0;
    } else {
        if (isStalac) {
            hit = v.size() - (v.size() - (idx - v.begin()));
        } else {
            hit = v.size() - (idx - v.begin());
        }
    }
    return hit;
}

int main() {
    fast();
    
    vector<int> stalactites, stalagmites;

    cin >> n >> h;
    cout << "height is: " << h << endl;
    
    int ob;
    while (n--) {
        cin >> ob;
//        cout << n << " " << ob << endl;
        if (n%2!=0) {
            stalagmites.push_back(ob);
        } else {
            stalactites.push_back(h - ob);
        }
    }

    sort(stalactites.begin(), stalactites.end());
    sort(stalagmites.begin(), stalagmites.end());

    cout << "stalagmites ";
    for (auto& x : stalagmites) {
        cout << x << " ";
    }
    cout << endl;
    cout << "stalactites ";
    for (auto& x : stalactites) {
        cout << x << " ";
    }
    cout << endl;

    cout << num_hit(stalactites, true, 1) << endl;
    cout << num_hit(stalactites, true, 2) << endl;
    cout << num_hit(stalactites, true, 3) << endl;
    cout << num_hit(stalactites, true, 4) << endl;
//    cout << num_hit(stalagmites, false, 1) << endl;
//    cout << num_hit(stalagmites, false, 2) << endl;
//    cout << num_hit(stalagmites, false, 3) << endl;
//    cout << num_hit(stalagmites, false, 4) << endl;
    return 0;
}


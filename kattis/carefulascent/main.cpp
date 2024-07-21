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
#include <iomanip>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ld simulate(vector<vector<ld>>& shields, ld fy, ld speed) {
    // simulates and returns the x coord of Mal at the fy coord
    // initial coords is 0, 0
    ld x = 0; ld y = 0;
    ld factor;
    for (auto& v : shields) {
        ld starty = v[0];
        ld endy = v[1];
        factor = v[2];

        if (y < starty) { // there is a segment without a shield and factor is 1
            x += speed * (starty - y);
            x += factor * speed * (endy - starty);
        } else { // y equals starty
            x += factor * speed * (endy - y);
        }
        y = endy;
    }
    if (y < fy) { // last stretch before firefly with no shields
        x += speed * (fy - y);
    }
    return x;
}

ld my_bin_search(vector<vector<ld>>& shields, ld fx, ld fy) { // returns the optimal speed
    ld hi = fx;
    ld lo = 0;
    ld xcoords;
    ld mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        xcoords = simulate(shields, fy, mid);

        if (fabs(xcoords - fx) < 10e-8) {
            return mid;
        } else if (xcoords < fx) {
            lo = mid;
        } else if (xcoords > fx) { // cur speed is too high
            hi = mid;
        }
    }
    return mid;
}

int main() {
    fast();
    
    // binary search the answer with physics simulation
    // normally if answer demands accuracy to a relative precision, this means bsta
    ld fx, fy; cin >> fx >> fy; 

    int num_cases; cin >> num_cases;
    
    vector<vector<ld>> shields;
    while (num_cases--) {
        ld starty, endy, factor; cin >> starty >> endy >> factor;
        vector<ld> v(3);
        v[0] = starty;
        v[1] = endy;
        v[2] = factor;

        shields.push_back(v);
    }
    // sort the shields by starty coord
    sort(shields.begin(), shields.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0]; // Compare based on y-coordinate
    });

//    for (auto& x : shields) {
//        cout << x[0] << " " << x[1] << " " << x[2] << endl;
//    }

    // binary search the appropriate value
    ld speed = my_bin_search(shields, fx, fy);

//    ld x = simulate(shields, fx, fy, 1.96078431373);
    cout << fixed << setprecision(11);
    cout << speed;
    return 0;
}


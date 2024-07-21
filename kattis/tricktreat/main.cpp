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
#include <iostream>
#include <iomanip>
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

double compute(double m, vector<pair<double,double>>& coords) { // given m, computes the max dist
    double max = 0;

    for (auto& c : coords) {
        double dist = sqrt(pow(fabs(c.first - m), 2) + pow(c.second, 2));
        max = (dist > max) ? dist : max;
    }
    
    return max;
}

// DIVIDE AND CONQUER - TERNARY BINARY SEARCH ON A UNIMODAL FTN

int main() {
    fast();


    int n; cin >> n;

    vector<pair<double, double>> coords;
    while (n != 0) {
        coords.clear(); // reset

        double hi = -200000;
        double lo = 200000;
        for (int i = 0; i < n; i++ ) {
            double x, y; cin >> x >> y;
            coords.push_back({x, y});
            hi = (x > hi) ? x : hi;
            lo = (x < lo) ? x : lo;
        }

//        for (auto& x : coords) {
//            cout << x.first << " " << x.second << endl;
//        }

        int num_loops = 50;
        for (int i = 0; i < num_loops; i++) {
            double delta = (hi - lo)/3.0;
            double m1 = lo + delta;
            double m2 = hi - delta;
            double fm1 = compute(m1, coords);
            double fm2 = compute(m2, coords);

            if (fm1 > fm2) {
                lo = m1;
            } else if (fm1 <= fm2) {
                hi = m2;
            }
        }

        double max_dist = compute((hi+lo)/2.00f, coords);

        printf("%.6lf %.6lf\n", lo, max_dist);

        cin >> n; // take input again
    }
    return 0;
}


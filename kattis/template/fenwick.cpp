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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

#define LSOne(S) ((S) & -(S))

typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;
public:

    FenwickTree(int m) {
        ft.assign(m + 1, 0);
    }

    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
        // the key operation
        // index 0 is not used
        // create empty FT
        // returns RSQ(1, j)
    }

    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, int v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }
};

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

int main() {
    fast();
    return 0;
}


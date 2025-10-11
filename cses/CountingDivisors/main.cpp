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
#include <numeric>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int SIZE = 1e6;
int main() {
    fast();

    vector<int> divs(SIZE, 2); // everything starts out with 2
    divs[0] = 1;

    for (int i = 2; i <= SIZE / 2; i++) {
        int j = 2 * i - 1; // idx
        while (j <= SIZE - 1) {
            divs[j]++;
            j += i;
        }
    }

//    for (int i = 0; i < 20; i++) {
//        cout << divs[i] << " ";
//    }

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        cout << divs[x-1] << "\n";
    }



    return 0;
}


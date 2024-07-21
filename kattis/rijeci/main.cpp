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

    // 1 - 0 1
    // 4 - 2 3
    int a = 0;
    int b = 1;

    int count; cin >> count;
    count--;

    while (count--) {
        int tmp = a;
        a = b;
        b = b + tmp;
    }
    cout << a << " " << b;

    return 0;
}


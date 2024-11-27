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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();
    long long num; cin >> num;

    while (num != 1) {
        cout << num << " ";
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num *= 3;
            num += 1;
        }
    }
    cout << "1";
    return 0;
}


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

class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;

        int sum = 0;
        while (true) {
            while (n > 0) { // extract the integers from the number and sum up the squares
                int x = n % 10;
                sum += pow(x, 2);
                n /= 10;
//                cout << n << " ";
            }
//            cout << "\n";
//            cout << sum;
            if (sum == 1) return true;
            if (seen.find(sum) != seen.end()) {
                return false;
            } else {
                seen.insert(sum);
                n = sum;
                sum = 0;
            }
        }
    }
};

int main() {
    fast();

    Solution sol;

    int n = 19;
    cout << sol.isHappy(n) << "\n"; // 1

    n = 2;
    cout << sol.isHappy(n) << "\n"; // 0
    return 0;
}


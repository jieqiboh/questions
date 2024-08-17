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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        } else if (x == 1) {
            return 1;
        }
        int l = 1;
        int r = x;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long square = static_cast<long long>(mid) * mid;
            if (square == x) {
                return mid;
            } else if (square > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }
};

int main() {
    fast();

    return 0;
}


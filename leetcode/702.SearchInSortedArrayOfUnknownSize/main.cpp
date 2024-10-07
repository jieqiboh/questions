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
    cin.tie(NULL);
    cout.tie(NULL);
}

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
class ArrayReader {
public:
    int get(int index);
};

class Solution {
public:
    int search(ArrayReader &reader, int target) {
        int l = 0;
        int r = pow(10,4);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (reader.get(mid) == target) {
                return mid;
            } else if (reader.get(mid) > target || reader.get(mid) == INT32_MAX) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    fast();

    return 0;
}


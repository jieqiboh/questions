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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a, b;
        int m, n;
        if (nums1.size() <= nums2.size()) {
            a = nums1; b = nums2;
            m = nums1.size(); n = nums2.size();
        } else {
            a = nums2; b = nums1;
            m = nums2.size(); n = nums1.size();
        }

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n) / 2 - i;

            int maxLeft1  = (i == 0) ? INT_MIN : a[i-1];
            int minRight1 = (i == m) ? INT_MAX : a[i];
            int maxLeft2  = (j == 0) ? INT_MIN : b[j-1];
            int minRight2 = (j == n) ? INT_MAX : b[j];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 1)
                    return max(maxLeft1, maxLeft2);
                else
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else if (maxLeft1 > minRight2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return -1; // unreachable
    }
};

int main() {
    fast();

    return 0;
}


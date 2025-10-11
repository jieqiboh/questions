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
        // Find the array with the smaller length first
        // The other array is guaranteed to have elements in the right, since it is larger
        // arr b is the smaller one
        vector<int> a, b;

        if (nums1.size() >= nums2.size()) {
            a = nums1;
            b = nums2;
        } else {
            a = nums1;
            b = nums2;
        }
        int la, lb = 0;
        int ra = a.size();
        int rb = b.size();

        int mida = (ra + la) / 2;
        int midb = (rb + lb) / 2;

        // account for the case where either array is empty
        // if a[mid

    }
};

int main() {
    fast();

    return 0;
}


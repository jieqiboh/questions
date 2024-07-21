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
        int la = 0; int ra = nums1.size() - 1;
        int lb = 0; int rb = nums2.size() - 1;
        // we want to do binsearches until all

    }
};

int main() {
    fast();

    return 0;
}


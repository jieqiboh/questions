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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // naive method: construct another array, and just assign into nums1
        int i = 0;
        int j = 0;

        vector<int> nums3;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            } else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        if (i == m) { // remaining elements in nums2
            while (j < n) {
                nums3.push_back(nums2[j]);
                j++;
            }
        } else {
            while (i < m) {
                nums3.push_back(nums1[i]);
                i++;
            }
        }

        // copy elements into nums1
        for (int i = 0; i < nums3.size(); i++) {
            if (nums3[i] != nums1[i]) {
                nums1[i] = nums3[i];
            }
        }
    }
};

int main() {
    fast();

    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;


    Solution sol;
    sol.merge(nums1, m, nums2, n);

    // Print the merged array
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


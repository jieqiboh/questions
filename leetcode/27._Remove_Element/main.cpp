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
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    fast();

    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    vector<int> nums2 = {3,2,2,3};
    int val2 = 3;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << k << "\n";

//    k = sol.removeElement(nums2, val2);
//    cout << k << "\n";

//    for (int x : nums) {
//        cout << x << " ";
//    }
    
    return 0;
}


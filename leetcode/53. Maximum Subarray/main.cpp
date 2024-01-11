#include <vector>
#include <iostream>
using namespace std;

// O(n**3) solution
// int maxSubArray(vector<int>& nums) {
//     int max = nums[0];
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i; j < nums.size(); j++) {
//             int subarraysum = 0;
//             for (int k = i; k <= j; k++) {
//                 subarraysum += nums.at(k);
//             }
//             if (subarraysum > max) max = subarraysum;
//         }
//     }
//     return max;
// }

// linear solution
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    
    int prefix = nums[0];
    int max = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (prefix < 0) {
            prefix = nums[i];
        } else {
            prefix += nums[i];
        }
        if (prefix > max) max = prefix;
    }

    return max;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}
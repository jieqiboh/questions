#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int cur = 0;
            if (nums.size() == 0) return 0;

            for (int i = 1; i < nums.size(); i++) {
                if(nums[i] != nums[cur]) {
                    cur++;
                    nums[cur] = nums[i];
                }
            }
            return cur+1;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {1,1,2};

    int result = solution.removeDuplicates(nums);

    cout << "Updated array: ";
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << result << endl;

    return 0;
}

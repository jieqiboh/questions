#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size()-1;
        int cur;
        int res = 0;

        while (low < high) {
            cur = nums[low] + nums[high];
            if (cur == k) {
                res++;
                low++;
                high--;
            } else if (cur < k) {
                low++;
            } else if (cur > k) {
                high--;
            }
        }
        return res;
    }
};

int main() {
    auto sol = Solution();
    vector<int> v = {3,1,3,4,3};
    cout << sol.maxOperations(v, 6) << endl;
    return 0;
}
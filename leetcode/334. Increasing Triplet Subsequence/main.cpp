#include <vector>
#include "iostream"
using namespace std;

class Solution {
public:
    bool increasingTripletNaive(vector<int>& nums) {
        for (int i = 0; i < nums.size()-2;i++)
            for (int j = i + 1; j < nums.size()-1; j++)
                for (int k = j + 1; k < nums.size(); k++) {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << "\n";
                    if (nums[i] < nums[j] && nums[j] < nums[k]) return true;
                }
        return false;
    }

    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX;
        for(auto x: nums){
            if(x<=a)    a=x;
            else if(x<=b)   b=x;
            else        return true;
        }
        return false;
    }
};

int main() {
    auto sol = new Solution();
    vector<int> nums1 = {20,100,10,12,5,13};
    vector<int> nums2 = {2,1,5,0,4,6};
    vector<int> nums3 = {5,4,3,2,1};
//    cout << sol->increasingTripletNaive(nums1);
//    cout << sol->increasingTripletNaive(nums2);
    cout << sol->increasingTriplet(nums1);

    return 0;
}


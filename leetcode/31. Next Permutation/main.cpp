#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // iterate from right to left to find an index i, where the entire right side is non-increasing
        // swap i with value slightly larger from [i+2,end]
        // reverse i+2 onwards

        int breakpt = 0;

        if (nums.size() == 1) return; //case where only 1 elem

        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                breakpt = i+1;

                for (int j = nums.size()-1; j >= i+1; j--) {
                    if (nums[j] > nums[i]) {
                        int t = nums[j];
                        nums[j] = nums[i];
                        nums[i] = t;
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin() + breakpt, nums.end());
    }

    void printVec(vector<int>& vec) {
        // Print the modified vector
        for (const int& element : vec) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    vector<int> v1 = {2,3,1};
    vector<int> v2 = {5,8,9,3,3};
    vector<int> v3 = {1,3,2};
    vector<int> v4 = {3,5,7,5,5};

    auto sol = Solution();
    sol.nextPermutation(v1);
    sol.nextPermutation(v2);
    sol.nextPermutation(v3);
    sol.nextPermutation(v4);

    sol.printVec(v1);
    sol.printVec(v2);
    sol.printVec(v3);
    sol.printVec(v4);
}

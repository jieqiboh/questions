#include <vector>
#include <iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> right(nums.size());
    vector<int> left(nums.size());
    vector<int> res(nums.size());
    right[0] = nums[0];
    left[nums.size()-1] = nums[nums.size()-1];

    for (int i = 1; i < nums.size(); i++) {
        right[i] = right[i-1] * nums[i];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
        left[i] = left[i+1] * nums[i];
    }

    for (int i = 0; i < nums.size();i++) {
        int leftval = (i-1 < 0) ? 1 : right[i-1];
        int rightval = (i+1 > nums.size()-1) ? 1 : left[i+1];
        res[i] = leftval * rightval;
    }
    return res;

}

void printVec(vector<int> &vec) {
    for (int x : vec) {
        cout << x << "\n";
    }
}

int main() {
    vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    vector<int> res = productExceptSelf(myVector);
    printVec(res);
}
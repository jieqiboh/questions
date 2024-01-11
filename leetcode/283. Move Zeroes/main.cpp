#include <vector>
#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int left = 0; // tracks idx of first zero elem
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[left] = nums[i];
            nums[i] = 0;
            left++;
        }
    }
}

void printVec(vector<int> &vec) {
    for (int x : vec) {
        cout << x << "\n";
    }
}

int main() {
    vector<int> vec = {0, 1, 0, 3, 12};
    moveZeroes(vec);
    printVec(vec);
    return 0;
}

#include <vector>
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

// soln 1: 2 passes through list, generating a hashmap of (sum, idx) to idx
// time: O(n)
// space: O(n)
//int pivotIndex(vector<int>& nums) {
//    map<tuple<int, int>, int> map;
//
//    int sum = 0;
//    int curPivot = -1;
//
//    for (int i = 0; i < nums.size(); i++) {
//        sum+=nums[i];
//        map[make_tuple(sum, i)] = i;
//    }
//
//    sum = 0;
//    for (int j = nums.size()-1; j >= 0; j--) {
//        sum+=nums[j];
//        if (auto search = map.find(make_tuple(sum, j)); search != map.end()) {
//            if (search->second == j) curPivot = j;
//        }
//    }
//    return curPivot;
//}

int pivotIndex(vector<int>& nums) {
    int rightSum = 0;
    int leftSum = 0;

    for (int x : nums) rightSum+=x;
    for (int i = 0; i < nums.size(); i++) {
        rightSum -= nums[i];
        if (rightSum == leftSum) return i;
        leftSum += nums[i];
    }
}

void printArr(vector<int> arr) {
    for (int x : arr) cout << x << "\n";
}

int main() {
    vector<int> arr = {1,7,3,6,5,6};
//    vector<int> arr = {0};
    cout << pivotIndex(arr);
    return 0;
}

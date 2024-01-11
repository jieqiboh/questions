#include "map"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        map<int, int> myMap;
        for (int x : nums) {
            auto it = myMap.find(x);
            if (it != myMap.end()) {
                myMap[x] += 1;
            } else {
                myMap[x] = 1;
            }

            if (myMap[x] > nums.size()/2) return x;
        }
    }
};

int main() {
    vector<int> vec1 = {2,2,1,1,1,2,2};
    vector<int> vec2 = {3,2,3};

    cout << Solution::majorityElement(vec1) << endl;
    cout << Solution::majorityElement(vec2) << endl;
    return 0;
}

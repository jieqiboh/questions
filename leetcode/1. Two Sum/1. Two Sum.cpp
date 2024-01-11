/**
Approach 3: One-pass Hash Table
build and check for complement at the same time
**/
/**
Complexity Analysis:
Time complexity : O(n).
We traverse the list containing n elements only once. 
Each look up in the table costs only O(1) time.
Space complexity : O(n). 
The extra space required depends on the number of items stored in the hash table, which stores at most nn elements.
**/

#include <map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> intmap;
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                if (intmap.find(complement) != intmap.end()) {
                    return vector<int> {i, intmap[complement]};
                }
                intmap[nums[i]] = i;
            }
            return vector<int> {};
        }

};
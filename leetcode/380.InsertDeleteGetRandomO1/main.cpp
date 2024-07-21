#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> nums_map;

    RandomizedSet() {
    }

    bool insert(int val) {
        // element already exists
        if (nums_map.find(val) != nums_map.end()) return false;

        // element doesn't exist
        nums.push_back(val);
        int idx = nums.size() - 1;

        nums_map[val] = idx;

        return true;
    }

    bool remove(int val) {
        if (nums_map.find(val) == nums_map.end()) return false; // val doesn't exist

        int idx = nums_map[val];
        int last_val = nums[nums.size() - 1];

        // Assign idx of val to last_val
        nums_map[last_val] = idx;
        nums_map.erase(val);

        // replace val at idx of val with the last_val, then pop_back the vector
        nums[idx] = last_val;
        nums.pop_back();

        return true;
    }

    int getRandom() {

        // 0 to n-1
        int n = nums.size();
        int random_idx = rand() % n;
        int random_val = nums[random_idx];

        return random_val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    fast();

    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << "\n"; // 1
    cout << obj->insert(1) << "\n"; // 0
    cout << obj->insert(6) << "\n"; // 1
    cout << obj->insert(9) << "\n"; // 1
    cout << obj->remove(5) << "\n"; // 0
    cout << obj->remove(6) << "\n"; // 1
    cout << obj->insert(7) << "\n"; // 1

    cout << obj->remove(1) << "\n"; // 1
    cout << obj->insert(1) << "\n"; // 1
    int param_3 = obj->getRandom();

    return 0;
}


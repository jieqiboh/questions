#include <iostream>
#include <sys/wait.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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



void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();
    
    int n; cin >> n;
    vector<int> nums(n);

    for (auto& x : nums) {
        cin >> x;
    }

    // for (auto& x : nums) {
    //     cout << x << " ";
    // }

    if (nums[nums.size()-1] < nums.size()-1) {
        cout << 1;
        return 0;
    } else {
        int count = 0;
        for (int i = nums.size()-1; i > 0; i--) {
            if (nums[i-1] > nums[i] - 1) {
                int tmp = nums[i-1] - nums[i] + 1;
                nums[i-1] = nums[i] - 1; // deduct
                count += tmp;                              
            }
        }
        cout << count;
    }

    

    return 0;
}


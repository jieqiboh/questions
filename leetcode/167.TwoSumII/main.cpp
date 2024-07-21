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

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return {i+1, j+1};
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }

    vector<int> twoSumNaive(vector<int>& numbers, int target) {
        int k = numbers.size() - 1; // limit that j can go to
        
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < k; j++) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                } else if (numbers[i] + numbers[j] > target) {
                    k = j - 1; // set new limit
                }
            }
        }
        return {-1,-1};
    }
};

int main() {
    fast();
    vector<int> numbers = {2,7,11,15};
    int target = 9;

    Solution sol;

    vector<int> res = sol.twoSum(numbers, target);

    cout << res[0] << " " << res[1] << "\n";

    return 0;
}
    


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
    int candy(vector<int>& ratings) {
        int cur = 0;
        int count = 0;
        // right pass
        vector<int> r(ratings.size());
        for (int i = 0; i < ratings.size() - 1; i++) {
            r[i] = cur;
            if (ratings[i + 1] > ratings[i]) {
                cur++;
            } else {
                cur = 0;
            }
        }
        r[ratings.size() - 1] = cur;

        cur = 0;
        // left pass
        vector<int> l(ratings.size());
        for (int i = ratings.size() - 1; i > 0; i--) {
            l[i] = cur;
            if (ratings[i - 1] > ratings[i]) {
                cur++;
            } else {
                cur = 0;
            }
        }
        l[0] = cur;

        for (int i = 0; i < ratings.size(); i++) {
            count += max(r[i], l[i]);
        }
        count += ratings.size();
        return count;
    }
};

int main() {
    fast();

    Solution sol;

    vector<int> ratings1 = {1,0,2}; // 2, 1, 2
    cout << sol.candy(ratings1) << "\n"; // 5

    vector<int> ratings2 = {1,2,2};
    cout << sol.candy(ratings2) << "\n"; // 4

    return 0;
}


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
    int hIndex(vector<int>& citations) {
        // sort citations in ascending
        sort(citations.begin(), citations.end());

        if (citations[citations.size()-1] == 0) return 0;

        // then count
        int h_index = 1;
        for (int i = 0; i < citations.size(); i++) {
            int cur = citations[i];
            int remaining_size = citations.size() - i;
            if (remaining_size >= cur) {
                h_index = cur;
            } else { // remaining_size < cur
                h_index = max(h_index, remaining_size);
            }
        }
        return h_index;
    }
};
int main() {
    fast();

    Solution sol;
    vector<int> citations = {3,0,6,1,5}; // 3
    vector<int> citations2 = {1,3,1}; // 1
    vector<int> citations3 = {0}; // 0
    vector<int> citations4 = {10}; // 1
    vector<int> citations5 = {0,2}; // 1
    int h_index_sol = sol.hIndex(citations);

    cout << h_index_sol << "\n";

    h_index_sol = sol.hIndex(citations2);

    cout << h_index_sol << "\n";

    h_index_sol = sol.hIndex(citations3);

    cout << h_index_sol << "\n";

    h_index_sol = sol.hIndex(citations4);

    cout << h_index_sol << "\n";

    h_index_sol = sol.hIndex(citations5);

    cout << h_index_sol << "\n";
    return 0;
}


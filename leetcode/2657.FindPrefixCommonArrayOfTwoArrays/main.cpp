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
#include <numeric>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size() + 1);

        vector<int> res(A.size(), 0);
        int cur = 0;
        for (int i = 0; i < A.size(); i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                cur++;
            }

            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                cur++;
            }
            res[i] = cur;
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> A = {1,3,2,4};
    vector<int> B = {3,1,2,4};
    vector<int> res = sol.findThePrefixCommonArray(A, B);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";


    return 0;
}


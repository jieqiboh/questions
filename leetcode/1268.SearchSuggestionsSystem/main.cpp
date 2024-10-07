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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix = "";
        for (int i = 0; i < searchWord.size(); i++) {
            vector<string> subRes;
            prefix += searchWord[i];
            auto it = lower_bound(products.begin(), products.end(), prefix);
            for (int j = 0; j < 3 && it + j != products.end(); j++) {
                string &s = *(it + j);
                if (s.find(prefix) == string::npos) break;
                subRes.push_back(s);
            }
            res.push_back(subRes);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> res = sol.suggestedProducts(products, searchWord);
    for (vector<string> vs : res) {
        for (string s : vs) {
            cout << s << " ";
        }
        cout << "\n";
    }

    return 0;
}


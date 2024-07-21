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
    string intToRoman(int num) {
        // 1 <= num <= 3999
        vector<string> letters = {"M","D","C","L","X","V","I"};
        vector<int> vals = {1000,500,100,50,10,5,1};
        vector<string> other_letters = {"CM","CD","XC","XL","IX","IV"};
        vector<int> other_vals = {900, 400, 90, 40, 9, 4};

        int i = 0;
        int j = 0;
        string res = "";
        while (num > 0) {
            string num_s = to_string(num);
            // select the first digit
            if (num_s[0] == '4' || num_s[0] == '9') {
                while (num < other_vals[j]) {
                    j++;
                }
                num -= other_vals[j];
                res += other_letters[j];
            } else {
                while (num < vals[i]) {
                    i++;
                }
                num -= vals[i];
                res += letters[i];
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int num = 3749;
    cout << sol.intToRoman(num) << "\n";

    return 0;
}


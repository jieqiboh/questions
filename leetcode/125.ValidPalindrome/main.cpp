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
    bool isPalindrome(string s) {

        string parsed_s = "";
        for (char c: s) {
            if ((tolower(c) >= 97 && tolower(c) <= 122) || (c >= 48 && c <= 57)) {
                parsed_s += tolower(c);
            }
        }

        cout << parsed_s.size() << "\n";

        for (int i = 0; i < (parsed_s.size() / 2); i++) { // do + 1 because of rounding down during division
            if (parsed_s[i] != parsed_s[parsed_s.size() - 1 - i]) {
                return false;
            }
//            cout << i << " " << parsed_s[i] << " : " << parsed_s[parsed_s.size() - 1 - i] << "\n";
        }
        return true;
        
    }
};

int main() {
    fast();

    Solution sol;

    string s = "A man, a plan, a canal: Panama";

    cout << sol.isPalindrome(s) << "\n";

    s = " ";
    cout << sol.isPalindrome(s) << "\n";

    s = " aba";
    cout << sol.isPalindrome(s) << "\n";

    s = " 0P";
    cout << sol.isPalindrome(s) << "\n";

    s = " 0P0";
    cout << sol.isPalindrome(s) << "\n";

    return 0;
}


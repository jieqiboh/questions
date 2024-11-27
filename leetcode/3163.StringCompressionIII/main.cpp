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
    string compressedString(string word) {
        string comp = "";
        char cur = word[0];
        int cnt = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == cur && cnt < 9) {
                cnt++;
            } else {
                comp += cnt + '0';
                comp += cur;
                cur = word[i];
                cnt = 1;
            }
        }
        comp += cnt + '0';
        comp += cur;
        return comp;
    }
};

int main() {
    fast();
    Solution sol;
    string word = "aaaaaaaaaaaaaabb";
    cout << sol.compressedString(word) << "\n";

    word = "abcde";
    cout << sol.compressedString(word) << "\n";
    return 0;
}


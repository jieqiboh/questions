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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> freq;
        int B = 0;
        int C = 0;

        for (char c: secret) {
            freq[c]++;
        }
        // pass 1
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] == guess[i]) {
                freq[secret[i]]--;
                B++;
            }
        }
        // pass 2
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && freq.find(guess[i]) != freq.end()) {
                if (freq[guess[i]] > 0) {
                    freq[guess[i]]--;
                    C++;
                }
            }
        }
        return to_string(B) + "A" + to_string(C) + "B";
    }
};

int main() {
    fast();
    Solution sol;
    string secret = "1807";
    string guess = "7810";
    cout << sol.getHint(secret, guess) << "\n"; // 1A3B

    return 0;
}


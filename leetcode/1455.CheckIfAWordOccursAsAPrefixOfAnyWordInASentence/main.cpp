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
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> v = split(sentence, ' ');
        for (int i = 0; i < v.size(); i++) {
            string s = v[i];
            if (s.size() < searchWord.size()) continue;
            if (s.substr(0, searchWord.size()) == searchWord) return i + 1;
        }
        return -1;
    }
    vector<string> split(const string &str, char delim) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) {
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    fast();
    Solution sol;
    string sentence = "i love eating burger";
    string searchWord = "burg";
    cout << sol.isPrefixOfWord(sentence, searchWord) << "\n"; // 4

    sentence = "this problem is an easy problem";
    searchWord = "pro";
    cout << sol.isPrefixOfWord(sentence, searchWord) << "\n"; // 2

    sentence = "i am tired";
    searchWord = "you";
    cout << sol.isPrefixOfWord(sentence, searchWord) << "\n"; // -1
    return 0;
}


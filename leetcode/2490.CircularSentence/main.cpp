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

    bool isCircularSentence(string sentence) {
        vector<string> v = split(sentence, ' ');
        for (int i = 0; i < v.size() - 1; i++) {
            string word = v[i];
            string nxtWord = v[i + 1];
            if (word[word.size() - 1] != nxtWord[0]) return false;
        }
        string lastWord = v[v.size() - 1];
        string firstWord = v[0];
        return lastWord[lastWord.size() - 1] == firstWord[0];
    }
};

int main() {
    fast();
    Solution sol;
    string sentence = "leetcode exercises sound delightful";
    cout << sol.isCircularSentence(sentence) << "\n"; // 1

    return 0;
}


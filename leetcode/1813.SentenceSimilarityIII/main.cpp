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

    bool areSentencesSimilar(string sentence1, string sentence2) {
        // remove words from longer sentence s.t. it equals shorter sentence
        string string2 = (sentence1.length() <= sentence2.length()) ? sentence2 : sentence1; // longer sentence becomes s2
        string string1 = (sentence1.length() <= sentence2.length()) ? sentence1 : sentence2; // shorter becomes s1
        vector<string> s1 = split(string1, ' ');
        vector<string> s2 = split(string2, ' ');

        int i = 0; int j = s2.size() - 1;
        int l = s1.size() - 1;
        while (i < s1.size() && s1[i] == s2[i]) i++;

        if (i >= s1.size()) { // terminated because out of bounds
            return true;
        }

        while (l >= i && j >= 0 && s1[l] == s2[j]) {
            j--;
            l--;
        }
        // [i, j] shld denote range to remove from s2
        // false if size of s2 after removing, does not equal size of s1
        if (i > j) return true;
        if (s2.size() - (j - i + 1) != s1.size()) return false;
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    string sentence1 = "Eating right now";
    string sentence2 = "Eating";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << "\n"; // 1

    sentence1 = "Hello my name is Jane";
    sentence2 = "Hello Jane";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << "\n"; // 1

    sentence1 = "A lot of words";
    sentence2 = "of";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << "\n"; // 0

    sentence1 = "xD iP tqchblXgqvNVdi";
    sentence2 = "FmtdCzv Gp YZf UYJ xD iP tqchblXgqvNVdi";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << "\n"; // 1

    sentence1 = "a";
    sentence2 = "a aa a";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << "\n"; // 1

    sentence1 = "A B C D B B";
    sentence2 = "A B B";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << "\n"; // 1

    return 0;
}


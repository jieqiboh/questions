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
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> setWords;
        for (string w : words) {
            setWords.insert(w);
        }

        unordered_map<string, int> cache; // maps words to their longest str chain val
        int res = 0;
        for (string w : words) {
            res = max(res, helper(cache, setWords, w, words));
        }
        return res;
    }
    int helper(unordered_map<string, int>& cache, set<string>& setWords, string& word, vector<string>& words) {
        // returns longest str chain, starting w this word
        if (word.size() == 1) return 1;
        if (cache.find(word) != cache.end()) return cache[word];

        int res = 1;
        for (int i = 0; i < word.size(); i++) {
            string newWord = word.substr(0, i) + word.substr(i + 1);
            if (setWords.find(newWord) != setWords.end()) { // newWord exists
                res = max(helper(cache,setWords, newWord, words) + 1, res);
            }
        }
        cache[word] = res;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    cout << sol.longestStrChain(words) << "\n"; // 4

    words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout << sol.longestStrChain(words) << "\n"; // 5

    words = {"abcd","dbqca"};
    cout << sol.longestStrChain(words) << "\n"; // 1

    return 0;
}


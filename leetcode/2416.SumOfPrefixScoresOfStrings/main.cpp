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

struct vertex {
    int cnt; // number of words starting w this prefix
    vector<vertex *> child;

    vertex() : cnt(0) { child.assign(26, NULL); }
};

struct TrieNode {
    TrieNode* next[26] = {};
    int cnt = 0;
};

class Solution {
    // Initialize the root node of the trie.
    TrieNode root;

public:
    // Insert function for the word.
    void insert(string word) {
        auto node = &root;
        for (char c : word) {
            // If new prefix, create a new trie node.
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new TrieNode();
            }
            // Increment the count of the current prefix.
            node->next[c - 'a']->cnt++;
            node = node->next[c - 'a'];
        }
    }
    // Calculate the prefix count using this function.
    int count(string s) {
        auto node = &root;
        int ans = 0;
        // The ans would store the total sum of counts.
        for (char c : s) {
            ans += node->next[c - 'a']->cnt;
            node = node->next[c - 'a'];
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        // Insert words in trie.
        for (int i = 0; i < N; i++) {
            insert(words[i]);
        }
        vector<int> scores(N, 0);
        for (int i = 0; i < N; i++) {
            // Get the count of all prefixes of given string.
            scores[i] = count(words[i]);
        }
        return scores;
    }
};

int main() {
    Trie T;
    Solution sol;
    vector<string> words = {"abc","ab","bc","b"};
    vector<int> res = sol.sumPrefixScores(words);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

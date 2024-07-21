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

class TrieNode {
public:
    TrieNode *children[26]; // each TrieNode can have up to 26 children
    bool terminal;
public:
    TrieNode() {
        for (auto & i : children) {
            i = nullptr;
        }
        terminal = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->children[word[i] - 'a'] == nullptr) { // cur doesn't have the char as a child
                TrieNode* newNode = new TrieNode();
                cur->children[word[i] - 'a'] = newNode;
                cur = newNode;
            } else { // cur has char as a child
                cur = cur->children[word[i] - 'a'];
            }
        }
        cur->terminal = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->children[word[i] - 'a'] != nullptr) { // cur has the char as a child
                cur = cur->children[word[i] - 'a'];
            } else {
                return false;
            }
        }
        return cur->terminal;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (cur->children[prefix[i] - 'a'] != nullptr) { // cur has the char as a child
                cur = cur->children[prefix[i] - 'a'];
            } else {
                return false;
            }
        }
        return true; // doesn't matter if it is a terminal char
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    fast();

    string word = "cattle";
    string prefix = "app";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    cout << param_2 << "\n"; // 1
    bool param_3 = obj->startsWith(prefix);
    cout << param_3 << "\n"; // 0
    cout << obj->startsWith("cat") << "\n"; // 1
    cout << obj->search("catt") << "\n"; // 0

    return 0;
}


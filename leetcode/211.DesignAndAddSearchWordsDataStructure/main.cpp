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

class WordDictionary {
public:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
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
        return dfsSearch(word, cur);
    }

    bool dfsSearch(string word, TrieNode* root) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* child : cur->children) {
                    if (child != nullptr) {
                        if (dfsSearch(word.substr(i + 1), child)) return true;
                    }
                }
            } else {
                if (cur->children[word[i] - 'a'] != nullptr) { // cur has the char as a child
                    cur = cur->children[word[i] - 'a'];
                } else {
                    return false;
                }
            }
        }
        return cur->terminal;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    fast();

    WordDictionary* obj = new WordDictionary();
    obj->addWord("cat");
    obj->addWord("cot");
    obj->addWord("con");
    cout << obj->search("cat") << "\n"; // 1
    cout << obj->search("c.t") << "\n"; // 1
    cout << obj->search("c..") << "\n"; // 1
    cout << obj->search("..n") << "\n"; // 1
    cout << obj->search("dog") << "\n"; // 0
    cout << obj->search(".og") << "\n"; // 0
    cout << obj->search(".o.") << "\n"; // 1

    return 0;
}


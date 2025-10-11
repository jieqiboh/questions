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
    char alphabet;
    bool exist;
    vector<vertex*> child;
    vertex(char a) : alphabet(a), exist(false) { child.assign(26, nullptr); }
};

class Trie {
private:
    vertex* root;
public:
    Trie() { root = new vertex('!'); }

    void insert(const string& word) {
        vertex* cur = root;
        for (char ch : word) {
            int k = ch - 'a';               // assume 'a'..'z'
            if (k < 0 || k >= 26) return;   // or handle as needed
            if (!cur->child[k]) cur->child[k] = new vertex(ch);
            cur = cur->child[k];
        }
        cur->exist = true;
    }

    // Walk the sequence; return true if ANY prefix of it forms a word.
    bool anyPrefixIsWord(const string& s) const {
        const vertex* cur = root;
        for (char ch : s) {
            int k = ch - 'a';
            if (k < 0 || k >= 26 || !cur->child[k]) return false; // early stop
            cur = cur->child[k];
            if (cur->exist) return true; // check AFTER stepping
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie trie;
    string cur;          // newest char at front
    size_t maxLen = 0;

    StreamChecker(vector<string>& words) {
        for (auto s : words) {
            maxLen = max(maxLen, s.size());
            reverse(s.begin(), s.end()); // build reversed trie
            trie.insert(s);
        }
    }

    bool query(char letter) {
        // Prepend newest char, cap to maxLen
        cur.insert(cur.begin(), letter);   // or: cur = letter + cur;
        if (cur.size() > maxLen) cur.pop_back();
        return trie.anyPrefixIsWord(cur);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    Trie T;

    vector<string> v = {"cd", "f", "kl"};
    StreamChecker sc(v);
    cout << sc.query('a'); // 0
    cout << sc.query('b'); // 0
    cout << sc.query('c'); // 0
    cout << sc.query('d'); // 1
    cout << sc.query('e'); // 0
    cout << sc.query('f'); // 1
    cout << sc.query('g'); // 0
    cout << sc.query('h'); // 0
    cout << sc.query('i'); // 0
    cout << sc.query('j'); // 0
    cout << sc.query('k'); // 0
    cout << sc.query('l'); // 1
    return 0;
}

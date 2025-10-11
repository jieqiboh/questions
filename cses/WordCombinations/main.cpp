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
  vertex(char a): alphabet(a), exist(false) { child.assign(26, NULL); }
};

const long long MOD = 1e9 + 7;

class Trie {                                     // this is TRIE
private:                                         // NOT Suffix Trie
  vertex* root;
public:
  Trie() { root = new vertex('!'); }

  void insert(string word) {                     // insert a word into trie
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) { // O(n)
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == NULL)          // add new branch if NULL
        cur->child[alphaNum] = new vertex(word[i]);
      cur = cur->child[alphaNum];
    }
    cur->exist = true;
  }

  int countWays(string& s, int idx, vector<int>& dp) {
      vertex* cur = root;
      int ways = 0;
      for (int i = idx; i < s.size(); i++) {
          int alphaNum = s[i]-'a';
          if (cur->child[alphaNum] == NULL)
              return ways;
          cur = cur->child[alphaNum];
          if (cur->exist)
              ways  = (ways + dp[i+1]) % MOD;
      }
      return ways;

  }
};

int main() {
  string s; cin >> s;
  int n; cin >> n;
  vector<string> v(n);
  for (auto& x : v) {
      cin >> x;
  }

  Trie trie;
  for (string x : v) {
      trie.insert(x);
  }

  vector<int> dp(s.size() + 1);
  dp[s.size()] = 1; // 1 way to form an empty string
  for (int i = s.size() - 1; i >= 0; i--) {
      dp[i] = trie.countWays(s, i, dp);
  }

  cout << dp[0];
  return 0;
}

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

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adjList;
        wordList.push_back(beginWord);

        // initialise the adjList
        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            for (int j = i + 1; j < wordList.size(); j++) {
                if (oneCharDiff(word, wordList[j])) {
                    adjList[word].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(word);
                }
            }
        }
        // do bfs
        unordered_set<string> visited;
        queue<pair<string, int>> q;

        q.push(make_pair(beginWord, 1));
        visited.insert(beginWord);
        while (!q.empty()) {
            pair<string, int> cur = q.front();
            q.pop();

            vector<string> neighbours = adjList[cur.first];
            for (string neighbour : neighbours) {
                if (visited.find(neighbour) == visited.end()) {
                    if (neighbour == endWord) return cur.second + 1;
                    q.push(make_pair(neighbour, cur.second + 1));
                    visited.insert(neighbour);
                }
            }
        }
        return 0;
    }

    bool oneCharDiff(string a, string b) {
        // returns true if a and b differ by only 1 char
        int numDiff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) numDiff++;
        }
        return numDiff == 1;
    }
};

int main() {
    fast();

    Solution sol;
    string beginWord = "hit"; 
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int res = sol.ladderLength(beginWord, endWord, wordList);
    cout << res << "\n"; // 5

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log"};

    res = sol.ladderLength(beginWord, endWord, wordList);
    cout << res << "\n"; // 5

    return 0;
}


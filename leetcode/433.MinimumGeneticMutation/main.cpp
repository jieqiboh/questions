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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> geneChars = {'A', 'C', 'G', 'T'};
        unordered_set<string> set_bank;
        for (string x : bank) {
            set_bank.insert(x);
        }

        queue<pair<string,int>> q; // gene and number of steps to reach it
        unordered_set<string> visited; // visited genes

        q.push(make_pair(startGene, 0));
        visited.insert(startGene);
        while (!q.empty()) {
            pair<string, int> cur = q.front();
            q.pop();
            string curGene = cur.first;

            for (int i = 0; i < 8; i++) {
                for (char c : geneChars) {
                    string newGene = curGene;
                    newGene[i] = c;
                    if (set_bank.find(newGene) != set_bank.end() && newGene != curGene && visited.find(newGene) == visited.end()) {
                        if (newGene == endGene) return cur.second + 1;
                        q.push(make_pair(newGene, cur.second + 1));
                        visited.insert(newGene);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();

    Solution sol;
    vector<string> bank = {"AACCGGTA"};
    string startGene = "AACCGGTT";
    string endGene = "AACCGGTA";
    int res = sol.minMutation(startGene, endGene, bank);
    cout << res << "\n"; // 1

    bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    startGene = "AACCGGTT";
    endGene = "AAACGGTA";
    res = sol.minMutation(startGene, endGene, bank);
    cout << res << "\n"; // 2

    return 0;
}


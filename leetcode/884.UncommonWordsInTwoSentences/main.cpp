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
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordMap;
        istringstream iss1(s1);
        while (iss1) {
            string s;
            iss1 >> s;
            wordMap[s]++;
        }
        istringstream iss2(s2);
        while (iss2) {
            string s;
            iss2 >> s;
            wordMap[s]++;
        }
        vector<string> res;
        for (pair<string,int> p : wordMap) {
            if (p.second == 1) res.push_back(p.first);
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}


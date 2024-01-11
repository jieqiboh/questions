#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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

int main() {
    // Your code goes here
    vector<string> words;
    string word;
    while (cin >> word) {
        words.push_back(word);
        continue;
    }
    
    set<string> combinations;
    for (int i=0;i<words.size();i++) {
        for (int j=0;j<words.size();j++) {
            if (i==j) continue;
            string newword = words[i]+words[j];
            combinations.insert(newword);
        }
    }

    for (string w : combinations) {
        cout << w << endl;
    }
    return 0;
}


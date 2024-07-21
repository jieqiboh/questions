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

int main() {
    fast();
    int num; cin >> num;
    bool isP1 = true;
    umap<string,bool> words;
    string prevWord = "";
    bool fair = true;
    while (num--) {
        string word; cin >> word;
        
        // word used before
        if (words.find(word) != words.end()) {
            string res = isP1 ? "Player 1 lost" : "Player 2 lost";
            fair = false;
            cout << res;
            break;
        }
        
        // first char of cur word matches last char of prevWord
        char prevWordLastLetter = prevWord.back();
        char wordFirstLetter = word.at(0);
        if (prevWordLastLetter != wordFirstLetter && prevWord != "") {
            string res = isP1 ? "Player 1 lost" : "Player 2 lost";
            fair = false;
            cout << res;
            break;
        }

        // all good
        prevWord = word;
        isP1 = !isP1;
        words.insert(make_pair(word, true));
    }
    if (fair) cout << "Fair Game";
    return 0;
}


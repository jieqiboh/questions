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
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> char_count; // maps chars to their counts
        for (char c : magazine) {
            char_count[c]++;
        }

        for (char c : ransomNote) {
            if (char_count.find(c) == char_count.end() || char_count[c] == 0) {
                return false;
            } else {
                char_count[c]--;
            }
        }

        return true;
        
    }
};

int main() {
    fast();


    Solution sol;

    string ransomNote = "a";
    string magazine = "b";
    cout << sol.canConstruct(ransomNote, magazine);

    return 0;
}


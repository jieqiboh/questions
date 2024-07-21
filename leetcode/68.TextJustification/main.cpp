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

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // assume all words are <= maxWidth
        vector<string> res(0);
        int i = 0; // index of first word in words to be added
        int j = 1; // index of word to be considered
        while (j <= words.size()) {
            int lenWords = words[i].length(); // length of words in string w/o spaces
            while (lenWords + words[j].length() + (j - i + 1) - 1 <= maxWidth) { // next word can be added
                lenWords += words[j].length();
                j++;
            }
            string line = words[i];
            if (j >= words.size()) { // last line
                for (int k = i + 1; k < j; k++) {
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                // [i, j) range of words
                int spaceAvail = maxWidth - lenWords;
                int spaceSlots = j - i - 1;
                int spaceSize = spaceSlots > 0 ? spaceAvail / spaceSlots : 0;
                int extraSpaces = spaceSlots > 0 ? spaceAvail % spaceSlots : 0;
                for (int k = i + 1; k < j; k++) {
                    int spacesToAdd = spaceSize + (k - i <= extraSpaces ? 1 : 0);
                    line += string(spacesToAdd, ' ') + words[k];
                }
                line += string(maxWidth - line.length(), ' ');
            }
            res.push_back(line);
            i = j;
            j++;
        }
        return res;
    }
};

int main() {
    fast();
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    Solution sol;
    sol.fullJustify(words, maxWidth);
    vector<string> res = sol.fullJustify(words, maxWidth);
    for (string s : res) {
        cout << s << "\n";
    }
    cout << "\n";

    words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    maxWidth = 20;
    res = sol.fullJustify(words, maxWidth);
    for (string s : res) {
        cout << s << "\n";
    }


    return 0;
}

